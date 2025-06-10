#include <bits/stdc++.h>
using namespace std;

//1.target interface expected by the client
class IReports{
    
    public:
        //now takes the raw data string and return json
        virtual string getJsonReport(const string& rawData) = 0;
        virtual ~IReports() {}
};

//2.Adaptee:provides xml data from raw input
class XmlDataProvider {
    
    public:
        //expect data in "name:id" format
        string getXmlData(const string& rawData) { //this can vary based on the use case
            size_t sep = rawData.find(':');
            string name = rawData.substr(0, sep);
            string id = rawData.substr(sep + 1);
            //build an xml representation
            return "<user>" 
            "<name>" + name + "</name>"
            "<id>" + id + "</id>"
            "</user>"
        }
};

//3. Adapter: implements IReports by converting XML to JSON
class XmlDataProviderAdapter : public IReports {
    
    private:
        XmlDataProvider* xmlDataProvider; //composition with adaptee
    
    public:
        XmlDataProviderAdapter(XmlDataProvider* provider) : xmlDataProvider(provider) {
            this->xmlDataProvider = provider; //initialize the adaptee
        }

        string getJsonReport(const string& rawData) override {
            //1. get xml data from adaptee
            string xmlData = xmlDataProvider->getXmlData(rawData);
            //2. naively parse out <name> and <id> values (convert xml to json (simple conversion for demonstration))
            size_t nameStart = xmlData.find("<name>") + 6; 
            size_t nameEnd = xmlData.find("</name>");
            string name = xmlData.substr(nameStart, nameEnd - nameStart);

            size_t idStart = xmlData.find("<id>") + 4;
            size_t idEnd = xmlData.find("</id>");
            string id = xmlData.substr(idStart, idEnd - idStart);
            
            //3. build and return json representation
            return "{ \"user\": { \"name\": \"" + name + "\", \"id\": \"" + id + "\" } }";
        }
};

//4. Client code works with IReports interface
class Client{
    public:
    void getReport(IReports* reportProvider, const string& rawData) {
        //get json report from the provider
        string jsonReport = reportProvider->getJsonReport(rawData);
        cout << "Generated JSON Report: " << jsonReport << endl;
    }
};

int main(){
    //1. create the adaptee
    XmlDataProvider* xmlProvider = new XmlDataProvider();

    //2. make our adapter
    IReports* adapter = new XmlDataProviderAdapter(xmlProvider);

    //3. give it some raw data
    string rawData = "JohnDoe:12345";

    //4. client prints the raw data as json
    Client* client = new Client();
    client->getReport(adapter, rawData);

    //5. cleanup
    delete client;
    delete adapter;
    delete xmlProvider;

    return 0;
}