
//Declaration (index == player number from search function, list[] == array of structures, update == number to be added to catches, length == number of array elements)
void updateCatches(int index, footBallPlayerType list[], int update, int length);



//function call
//updateCatches(playerNum, bigGiants, numOfcatches, num);


//Definition
//If index number is valid, update number of catches and output success message
void updateCatches(int index, footBallPlayerType list[], int update, int length)
{
    if (0 <= index && index < length)
    {
        list[index].catches = list[index].catches + update;
    }

    cout << "Catches updated for " << list[index].name << endl << endl;
}

