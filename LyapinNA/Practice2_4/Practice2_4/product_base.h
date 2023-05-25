#pragma once

class product_base
{
private:
	ListContainer<string> productBase;

public:

	product_base(const string path)
	{
		ifstream read(path);
		if (!read) cout << "файл не открыт!";
		string text;
		while (getline(read, text))
		{
			cout << text << endl;
			//productBase.push_back(text);
		}
		read.close();
	}
	

};

