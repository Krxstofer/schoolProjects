// Kristofer Norman
// 11/19/2021

#include <iostream>

#include <string>

using namespace std;

enum movieRatings

{
	G = 1,

	PG,

	PG_13,

	R,

	NC_17
};


struct Movie

{
	string name;

	enum movieRatings rating;

	string year_produced;

	string mainStar;

	char saw;

	char liked;
};

//function to read rating from user

void read_rating(Movie& first)

{

	char temp1;

	int temp;

	cin >> temp1;

	temp = temp1 - '0';

	switch (temp)

	{

	case 1:

		first.rating = G;

		break;

	case 2:

		first.rating = PG;

		break;

	case 3:

		first.rating = PG_13;

		break;

	case 4:

		first.rating = R;

		break;

	case 5:

		first.rating = NC_17;

		break;

	default:

		cout << "\nPlease enter a valid rating ";

		read_rating(first);

	}

}

//function to display rating of enum type

void display_rating(enum movieRatings temp)

{

	switch (temp)

	{

	case 1:

		cout << "\nThis movie is rated G: General Audiences\n";

		break;

	case 2:

		cout << "\nThis movie is rated PG : Parental Guidance Suggested\n";

		break;

	case 3:

		cout << "\nThis movie is rated PG-13: Parent's Strongly Cautioned\n";

		break;

	case 4:

		cout << "\nThis movie is rated R: Under 17 requires accompanying adult or adult guardian\n";

		break;

	case 5:

		cout << "\nThis movie is rated NC-17: No one under 17 and under admitted\n";

		break;

	}

}

int main()

{

	Movie first; // object of movie

	cout << "\nEnter name of Movie ";

	cin >> first.name; // read name of the movie

	cout << "\nEnter a number seen below associated with the movie rating\n";

	cout << "\n1 - G\n2 - PG\n3 - PG-13\n4 - R\n5 - NC-17\n\n";

	read_rating(first); // reading the ratings 

	cout << "\nEnter year produced ";

	cin >> first.year_produced; // read year produced

	cout << "\nEnter main star of movie ";

	cin >> first.mainStar; // read main star

	cout << "\nPress Y if you saw the movie else Press N if you didn't saw the movie ";

	cin >> first.saw; // read seen 

	cout << "\nPress Y if you liked the movie else Press N if you didn't liked the movie ";

	cin >> first.liked; // read liked

	cout << "\n\nName of movie is " << first.name << endl;

	cout << "\nThe movie is produced in year: " << first.year_produced << endl;

	cout << "\nMain star of Movie is " << first.mainStar << endl;

	display_rating(first.rating); // displaying the ratings

	if (first.saw == 'Y' || first.saw == 'y')

		cout << "\nYou saw the movie\n";

	else

		cout << "\nYou did not see the movie\n";

	if (first.liked == 'Y' || first.liked == 'y')

		cout << "\nYou liked the movie\n";

	else

		cout << "\nYou did not liked the movie\n";

	cout << endl;

}