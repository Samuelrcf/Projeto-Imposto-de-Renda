#include <iostream>
#include <string>
#include "curl/include/curl/curl.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, char *buffer_in)
{
    ((string*)buffer_in)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

float CotacaoMoedas()
{
    int x = 0;
    CURL *curl;
    CURLcode res;
    string readBuffer;
    
    curl = curl_easy_init();
    if(curl)
    {
    	string moeda;
    	string reqMoeda;
    	cout << "Digite a sigla da moeda: ";
    	cin >> moeda;
    	reqMoeda = "https://economia.awesomeapi.com.br/last/" + moeda + "-BRL";
        curl_easy_setopt(curl, CURLOPT_URL, reqMoeda.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        json j = json::parse(readBuffer);
        string moedaParaReal = moeda + "BRL";
        //double cotacao = j.at(moeda)["bid"].get<double>();
        // double usd_cotacao = j["USD"]["bid"]; ou double usd_cotacao = j.at("USD").at("bid");
        //double cotacao = j.at(moeda).at("bid");
        double cotacao = stod(j.at(moedaParaReal).at("bid").get<string>());
        cout << "A Cotacao para " << moedaParaReal << ": " << cotacao << endl;
    }
    cout << "Finalizar?";
    cin >> x;
    return 0;
}
