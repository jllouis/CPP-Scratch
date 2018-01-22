bool circular(string command) {
    map<char, unsigned> record {{'G', 0}, {'R', 0}, {'L', 0}};

    for (char c : command)
        record[toupper(c)]++;

    if (record['G'] == 0)
        return true;
    else if (record['G'] != record['R'] + record['L'])
        return false;
    else if (record['R'] == record['L'])
        return false;

    return true;
}