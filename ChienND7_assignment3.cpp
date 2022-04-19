#include <iostream>
using namespace std;

// Hàm kiểm tra năm nhuận
bool laNamNhuan(int nYear);

// Hàm trả về số ngày trong tháng thuộc năm cho trước
int tinhSoNgayTrongThang(int nMonth, int nYear);

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool laNgayHopLe(int nDay, int nMonth, int nYear);

// Hàm tìm ngày hôm trước của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void timNgayHomTruoc(int& nDay, int& nMonth, int& nYear);

// Hàm tìm ngày hôm sau của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void timNgayHomSau(int& nDay, int& nMonth, int& nYear);

int main()
{
	int nDay, nMonth, nYear;
	cout << "Day: ";
	cin >> nDay;

	cout << "Month: ";
	cin >> nMonth;

	cout << "Year: ";
	cin >> nYear;

	if (laNgayHopLe(nDay, nMonth, nYear))
	{
		int tmpDay = nDay;
		int tmpMonth = nMonth;
		int tmpYear = nYear;

		// Tìm ngày hôm trước
		timNgayHomTruoc(tmpDay, tmpMonth, tmpYear);
		cout << "Yesterday: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;


		tmpDay = nDay;
		tmpMonth = nMonth;
		tmpYear = nYear;

		// Tìm ngày hôm sau
		timNgayHomSau(tmpDay, tmpMonth, tmpYear);
		cout << "Tomorrow: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;
	}
	else
	{
		cout << "Ngay khong hop le." << endl;
	}

	return 0;
}

// Hàm kiểm tra năm nhuận
bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;

	// <=> return ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0);
}

// Hàm trả về số ngày trong tháng thuộc năm cho trước
int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool laNgayHopLe(int nDay, int nMonth, int nYear)
{
	bool bResult = true; // Giả sử ngày hợp lệ

	// Kiểm tra năm
	if (!(nYear > 0 && nMonth))
	{
		bResult = false; // Ngày không còn hợp lệ nữa!
	}

	// Kiểm tra tháng
	if (!(nMonth >= 1 && nMonth <= 12))
	{
		bResult = false; // Ngày không còn hợp lệ nữa!
	}

	// Kiểm tra ngày
	if (!(nDay >= 1 && nDay <= tinhSoNgayTrongThang(nMonth, nYear)))
	{
		bResult = false; // Ngày không còn hợp lệ nữa!
	}

	return bResult; // Trả về trạng thái cuối cùng...
}
// Hàm tìm ngày hôm trước của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void timNgayHomTruoc(int& nDay, int& nMonth, int& nYear)
{
	nDay--;
	if (nDay == 0)
	{
		nMonth--;
		if (nMonth == 0)
		{
			nMonth = 12;
			nYear--;
		}

		nDay = tinhSoNgayTrongThang(nMonth, nYear);
	}
}

// Hàm tìm ngày hôm sau của một ngày dd/mm/yyyy cho trước (đã hợp lệ)
void timNgayHomSau(int& nDay, int& nMonth, int& nYear)
{
	nDay++;
	if (nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		nDay = 1;
		nMonth++;
		if (nMonth > 12)
		{
			nMonth = 1;
			nYear++;
		}
	}
}
