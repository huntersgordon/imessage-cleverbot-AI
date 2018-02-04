#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <locale>

using namespace std;

string singledigtodouble(string s){

     if(s.length() == 1){
          return "0" + s;
     }

     return s;

}



std::string exec(const char* cmd){

   std::array<char, 128> buffer;
   std::string result;
   std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
   if (!pipe) throw std::runtime_error("popen() failed!");
   while (!feof(pipe.get())) {
       if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
          result += buffer.data();
   }
   return result;
}

string bitch(string s){

     string meow = "";

     for (int i = 0; i < s.length(); i++){

          if(s[i] == ' '){
               meow += "\\ ";
          }
          else{
          meow += s[i];
          }
     }
     return meow;

}

bool invalidChar (char c)
{
   // return !(c>=0 && c <128);
   return true;
}
void stripUnicode(string & str)
{
    str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());
}

std::string get_str_between_two_str(const std::string &s,
        const std::string &start_delim,
        const std::string &stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find(stop_delim);

    return s.substr(end_pos_of_first_delim,
            last_delim_pos - end_pos_of_first_delim);
}

string getinbetween(string s){

     //int invalidplace;
     reverse(s.begin(),s.end());

     if (s[1] == 'Q' && s[3] == 'Q'){
          s = s[0];
          return s;
     }
     if (s[2] == 'R' && s[5] == 'R'){
          s = s.substr(0,2);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[3] == 'S' && s[7] == 'S'){
          s = s.substr(0,3);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[4] == 'T' && s[9] == 'T'){
          s = s.substr(0,4);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[5] == 'U' && s[11] == 'U'){
          s = s.substr(0,5);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[6] == 'V' && s[13] == 'V'){
          s = s.substr(0,6);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[7] == 'W' && s[15] == 'W'){
          s = s.substr(0,7);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[8] == 'X' && s[17] == 'X'){
          s = s.substr(0,8);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[9] == 'Y' && s[19] == 'Y'){
          s = s.substr(0,9);
          reverse(s.begin(),s.end());
          return s;
     }
     if (s[10] == 'Z' && s[21] == 'Z'){
          s = s.substr(0,10);
          reverse(s.begin(),s.end());
          return s;
     }

     if (s[11] == 91 && s[23] == 91){
          s = s.substr(0,11);
          reverse(s.begin(),s.end());
          return s;
     }





     for(int i = 11; i<100; i++){

          if (s[i] == i+80 && s[i*2+1] == i+80){
               s = s.substr(0,i);
               reverse(s.begin(),s.end());
               return s;
          }


     }








     // reverse(penis.begin(),penis.end()); //restores string
     //_bling blaogyygaaa_
     //_bling blaogyyga_
     //^bling blaogyyg^
     //]bling blaogyy]
     //]bling blaogyw]
     //\bling blaogy\
     //[bling blaog[
     //[bling bloog[


     //cout<<"invalidChar at "<<to_string(invalidplace)<<endl;
     reverse(s.begin(),s.end());

     string interest;


     s.erase(std::remove(s.begin(), s.end(), '\t'), s.end());

     if (s.length() < 30){
          s = s.substr(9);
          //char likey = s[0];
     //     cout << likey << " is the delimiter";
          return s;
     }

     if (s.find("_") != std::string::npos){

          interest = s;
          int start = s.find('_');
          reverse(s.begin(),s.end());
          int end = s.find('_');
          reverse(s.begin(),s.end());
          return s.substr(start+2,end-1);
      }

      else return s;
}


string YMD(){


          time_t t = time(0);   // get time now
         struct tm * now = localtime( & t );
         return singledigtodouble(to_string(now->tm_year + 1900)) + '-'
              + singledigtodouble(to_string(now->tm_mon + 1)) + '-'
              +  singledigtodouble(to_string(now->tm_mday));

}

std::string escape(std::string const &s)
{
    std::size_t n = s.length();
    std::string escaped;
    escaped.reserve(n * 2);        // pessimistic preallocation

    for (std::size_t i = 0; i < n; ++i) {
        if (s[i] == '\\' || s[i] == '\'')
            escaped += '\\';
        escaped += s[i];
    }
    return escaped;
}

const std::string forbiddenChars = "\\/:?\"<>|";
static char ClearForbidden(char toCheck)
{
    if(forbiddenChars.find(toCheck) != string::npos)
    {
         return ' ';
    }

    return toCheck;
}





//int cachedfilesize =0;
string lastmessage ="nully";
int main(){


     while(true){
     string command = "cd /Users/Hunter\\ 1/Library/Messages/Archive/" +YMD() + ";find . -type f -print0 | xargs -0 stat -f \"%m %N\" |sort -rn | head -1 | cut -f2- -d\" \"";
     string mostrecent = exec(command.c_str()); //get most recent modified file.
     //cout <<"most recent modified file is: " + bitch(mostrecent).substr(2)<<endl;
     string mostrecentfilesize = "cd /Users/Hunter\\ 1/Library/Messages/Archive/" +YMD() + ";ls -l \""+mostrecent.substr(2,mostrecent.length()-3)+"\" | awk '{print $5}';";
     mostrecentfilesize = exec(mostrecentfilesize.c_str());
     int filesize = stoi(mostrecentfilesize);

     if (mostrecent.find(".ichat") == std::string::npos){
         cout<<"Error: iChat file was not most recent modified";
        exit(EXIT_FAILURE);
     }



          //cout<<filesize<<endl;
          //cout << "most recent: "<<mostrecent<<" most recent filesize: "<<mostrecentfilesize<<endl;


          //string outs = "cd /Users/Hunter\\ 1/Library/Messages/Archive/" +YMD() + ";echo \"" + mostrecent + "\" /Users/Hunter\\\ 1/Desktop/files.txt; wc -c \""+ mostrecent +"\" | awk '{print $1}' ";
          //cout <<"/Users/Hunter\\ 1/Library/Messages/Archive/" +YMD() +'/'+ bitch(mostrecent.substr(2)); //the path of the most recent imessage
          string path = "/Users/Hunter\\ 1/Library/Messages/Archive/" +YMD() +'/'+ bitch(mostrecent.substr(2));
          //cout<<path;
          ifstream file;
          string line;
          //cout <<"most recent modified file is: " + bitch(mostrecent).substr(2)<<endl;
          string filetoopen = mostrecent.substr(2);
          file.open(filetoopen.substr(0,filetoopen.length()-1));
          string ballsack = "";
          if (file.is_open())
          {
            while ( getline (file,line) )
            {
              //cout << line << '\n';
              ballsack += line;
            }
            file.close();

            if (mostrecent.find(".ichat") == std::string::npos){
                cout<<"Error: iChat file was not most recent modified";
               exit(EXIT_FAILURE);
            }


           reverse(ballsack.begin(),ballsack.end());
           string penis = get_str_between_two_str(ballsack,"yarrAelbatuMSN", "_");
           //reverse(penis.begin(),penis.end());
           string blee = get_str_between_two_str(penis,"$","#");
           blee = get_str_between_two_str(blee,"_","�");
           reverse(blee.begin(),blee.end());

          // reverse(penis.begin(),penis.end()); //restores string
          //_bling blaogyygaaa_
          //_bling blaogyyga_
          //^bling blaogyyg^
          //]bling blaogyy]
          //]bling blaogyw]
          //\bling blaogy\
          //[bling blaog[
          //[bling bloog[
          //Zbling blooZ
          //Zbling bluuZ
          //Ybling bluY
          //Ybling bluY

          //if (ballsack.find("Hunter:") != std::string::npos){
          //      cout<<"this means i've sent a text";
          // }

          //string php = "php -q clever.php \" hello \"";
          //string response = exec(php.c_str());
          //cout<< "Response is: "<<response;

          if (blee.length() < 500){

          //stripUnicode(blee);
          string haha = getinbetween(blee)  ;
          cout<<"Found text: "+ haha<<endl;

          if (lastmessage.find(haha) != std::string::npos){

              cout<<"No changes."<<endl;//found last message: " +lastmessage + " in " + haha;
              cout<<"last message was" + lastmessage + " and found was: " + haha;
            //  cout<<"refreshing in 10 secs.";
            // sleep(15); //10 second sleep

          }
          else{

               //stripUnicode(haha);
               haha.erase(std::remove(haha.begin(), haha.end(), '\''), haha.end());
               //ClearForbidden(haha);
               cout<<"activating AI"<<endl;
               //string hi = "hello";
               string php = "php -q clever.php \'"+haha+"\'";
               sleep(3);
               string response = exec(php.c_str());
               response.erase(std::remove(response.begin(), response.end(), '\''), response.end());
               response.erase(std::remove(response.begin(), response.end(), '.'), response.end());
               //stripUnicode(response);
               lastmessage = response;
               std::locale loc;
               for (std::string::size_type i=0; i<response.length(); ++i)
                    std::cout << std::tolower(response[i],loc);
               cout<< "Response is: "<<response<<endl;
               //response.erase(std::remove(response.begin(), response.end(), ' '), response.end());
               string imessa = "imessage --text \'"+response+"\' --contacts '3234281170'";
               string test = exec(imessa.c_str());

          }
          sleep(23); //10 second sleep
          }



          //cout << get_str_between_two_str("hellllooo","he","o");

          }

          else {cout << "Unable to open file " + filetoopen;}
     }






}
