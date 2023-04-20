


class product {
private:
	string name;
	string barcode;
	uint16_t price;
public:
	product(); //по умолчанию
	product(string name, string barcode, uint16_t price);

	void setName(string name);
	void setBarcode(string barcode);
	void setPrice(uint16_t price);
	
	string getName();
	string getBarcode();
	uint16_t getPrice();
};