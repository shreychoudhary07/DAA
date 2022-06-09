def main():
    n = int(input())
    list_keys = []
    list_duplicates = []
    for i in range(n):
        no_of_elements = int(input())
        '''no_of_elements isn't really used here for anything
        as input().split() takes in a input string which splits
        whenever it reads a whitespace [default] and those split
        strings are converted into int before being appended in the a_list
        '''
        a_list = [int(item) for item in input().split()]

        key = int(input())
        dup_count = a_list.count(key)
        list_keys.append(key)
        list_duplicates.append(dup_count)

    for item in zip(list_keys, list_duplicates):
        if(item[1] == 0):
            print("key not found")
        else:
            print(item[0], item[1])


if __name__ == '__main__':
    main()
