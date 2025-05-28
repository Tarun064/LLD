#include <bits/stdc++.h>
using namespace std;

//abstract observer interface: subscriber must implement this update method
class ISubscriber{
    public:
        virtual void update()=0; // pure virtual function
        virtual ~ISubscriber(){} // virtual destructor
};

//abstract observable interface: a youtube channel interface
class IChannel{
    public:
        virtual void subscribe(ISubscriber* subscriber)=0; // pure virtual function
        virtual void unsubscribe(ISubscriber* subscriber)=0; // pure virtual function
        virtual void notifySubscribers()=0; // pure virtual function
        virtual ~IChannel(){} // virtual destructor
};

//concrete observable class: a youtube channel that observers subscribe to
class Channel: public IChannel{
    private:
        vector<ISubscriber*> subscribers; // list of subscribers
        string name; // channel name
        string latestVideo; // latest video uploaded
    public:
        Channel(string name):channelName(name){
            this->name = name; // initialize channel name
        } // constructor to initialize channel name

        //add subscriber (avoiding duplicate subscriptions)
        void subscribe(ISubscriber* subscriber) override {
            if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
                subscribers.push_back(subscriber); // add subscriber to the list if not already present
            }
        }

        //remove a subscriber if present
        void unsubscribe(ISubscriber* subscriber) override {
            auto it = find(subscribers.begin(), subscribers.end(), subscriber);
            if(it != subscribers.end()) {
                subscribers.erase(it); // remove subscriber from the list if found
            }
        }

        //notify all the subscriber of the latest video uploads
        void notifySubscribers() override {
            for(ISubscriber* subscriber : subscribers) {
                subscriber->update(); // notify each subscriber
            }
        }

        //upload a new video and notify subscribers
        void uploadVideo(const string& videoTitle) {
            latestVideo = videoTitle; // set the latest video title
            cout << "Channel: " << name << " uploaded a new video: " << latestVideo << endl;
            notifySubscribers(); // notify all subscribers about the new video
        }

        //read video data
        void getVideoData() const {
            cout << "Latest video on channel " << name << ": " << latestVideo << endl;
            return latestVideo; // obswerver ka update method yha se uss nyi video ka data le lega
        }
};

class Subscriber: public ISubscriber{
    private:
        string name; // subscriber name
        Channel* channel; // subscribed channel
    public:
        Subscriber(string name, Channel* channel):name(name), channel(channel) {
            this->channel = channel; // initialize channel
            this->name = name; // initialize subscriber name
        }

        //update method to be called when a new video is uploaded
        //called by channel: prints notification message
        void update() override {
            cout << "Subscriber: " << name << " has been notified of a new video upload on channel: " << channel->getVideoData() << endl;
        }
};
int main(){
    //create a channel and subscribers
    Channel* channel = new Channel("TechTalks");
    Subscriber* sub1 = new Subscriber("Alice", channel);
    Subscriber* sub2 = new Subscriber("Bob", channel);

    //both subscribe to techtalks channel
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    //upload a video both will get notified
    channel->uploadVideo("Understanding Design Patterns in C++ : Observer Design Pattern");

    //bob unsubscribes from the channel
    channel->unsubscribe(sub2);

    //upload another video only alice will get notified
    channel->uploadVideo("Decorator Design Pattern in C++");
    
    //clean up
    delete sub1;
    delete sub2;
    delete channel; // delete channel object
    return 0; // return success
}