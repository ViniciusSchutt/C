// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0; // The votes need to start at 0 and increment only if the candidate get any votes
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO, declare a iterabe variable starting at 0, while it's less than candidate count, add 1 to it
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // if the candidate 'i' name matches the new voted name
        {
            candidates[i].votes++; //Add 1 to this candidate 'i' total votes, which started in 0 at line 45
            return true; //Returns true when given valid candidates
        }
    }
    return false; //And false to invalid candidates
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO, start a variable mostvotes in 0, so we can compare candidates votes to this and, if the candidate is higher, mostvotes become the cited candidate votes
    int mostvotes = 0;
    // Same as the vote function for loop
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > mostvotes) //Test if the candidate 'i' has more votes than mostvotes
        {
            mostvotes = candidates[i].votes; //If yes, mostvotes receives the value of candidate 'i' votes
        }
    }
    // Same for loop again
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == mostvotes)//Now the program test's if candidate 'i' votes is equal to mostvotes, which was created in the previous for loop
        {
            printf("%s\n", candidates[i].name); //When the program find's exactly which candidate has the same amount as the mostvotes value, this one is the winner and his/her name is printed
        }
    }
    return;
}