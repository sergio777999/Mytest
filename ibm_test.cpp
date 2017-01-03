#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


void split_and_show(const string& str, vector<vector<string>>& pairs,
													string& employee1, string& employee2)
{
 size_t start{0}, end, current;
 string word_pair, word1, word2;
 do
  {
   end = str.find(",", start);
   word_pair = str.substr(start, (end - start));
   if((current = word_pair.find("->")) != string::npos)
     {
      word1 = word_pair.substr(0, current);
      word2 = word_pair.substr(current + 2);
      vector<string> temp;
      temp.push_back(word1);
      temp.push_back(word2);
      pairs.push_back(temp);
     }
   else
     if(end != string::npos)
       employee1 = word_pair;
     else
       employee2 = word_pair;
 
   start = end + 1;
   current = 0;
 }while(end != string::npos);
 
 for(auto& i : pairs)
    cout << "Manager: " << i[0] << ", Employee: " << i[1] << " relationship." << endl;
 
 cout << endl << "Employee 1: " << employee1 << ", Employee 2: " << employee2 << endl << endl;
}


void match_and_show(const vector<vector<string>>& pairs, const string& employee1,
											const string& employee2, string& result)
{
 vector<string> match;
 for(auto& i : pairs)
 {
  if((i[1] == employee1) || (i[1] == employee2))
    {
      match.push_back(i[0]);
    }
 }
 
 for(vector<string>::iterator it_out = match.begin(); it_out < match.end(); ++it_out)
 {
  string temp = *it_out;
  for(vector<string>::iterator it_in = (match.begin() + 1); it_in < match.end(); ++it_in)
    if(*it_out == *it_in)
	     match.erase(it_in);
 }
 
 if(match.size() > 1)
 { 
  for(auto& i : pairs)
   { 
    if((i[0] == match[0]) && (i[1] == match[1]))
         result = match[0];
    else
      if((i[0] == match[1]) && (i[1] == match[0]))
         result = match[1];
   }
 }
 else
     result = match[0];
 
 cout << "The manager to resolve the dispute is: " << result << endl << endl;
}


int main()
{
 string str = "Frank->Mary,Mary->Sam,Mary->Bob,Sam->Katie,Sam->Pete,Bob->John,Bob,Katie";

 string str1 = "Sam->Pete,Pete->Nancy,Sam->Katie,Mary->Bob,Frank->Mary,Mary->Sam,Bob->John,Sam,John";

 vector< vector<string> > pairs;
 string employee1, employee2;
 split_and_show(str, pairs, employee1, employee2);

 vector< vector<string> > pairs2;
 string employee_1, employee_2;
 split_and_show(str1, pairs2, employee_1, employee_2);

unordered_map<string, string> umap;
 for(auto& i : pairs2)
    umap.emplace(i[0], i[1]);

 for(auto& i : umap)
    cout << "Key: " << i.first << ", Value: " << i.second << endl << endl;


string result1, result2;
match_and_show(pairs, employee1, employee2, result1);
match_and_show(pairs2, employee_1, employee_2, result2);

cout << endl << employee1 << "'s and " << employee2 << "'s boss is " << result1 << endl;
cout << endl << employee_1 << "'s and " << employee_2 << "'s boss is " << result2 << endl;
return 0;
}
