//------------------------------------------------------------------------------
// @file       dictionary.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"
#include "sorted_list.h"


/**
 * @brief      Dictionary that pairs std::string 'keys' with Data 'values'.
 *
 * @tparam     Data  The typename of the value objects stored in the Dictionary. 
 */
template<class Data>
class Dictionary
{
public:
    /**
     * @brief      Default constructor. 
     *             Sets capacity value to CAP (private static constant).
     */
    Dictionary();
    

    /**
     * @brief      Parameterized constructor.
     *
     * @param[in]  cap   Initializes capacity value (number of entries).
     */
    Dictionary(int cap);
    

    /**
     * @brief      Copy constructor.
     *
     * @param[in]  other  The Dictionary being copied.
     */
    Dictionary(const Dictionary& other);
    

    /**
     * @brief      Destructor.
     */
    ~Dictionary();

    
    /**
     * @brief      Adds a key/value pair to the dictionary.
     *
     * @param[in]  k     Key.
     * @param[in]  d     Value. Reference to Data object.
     * @throws     FullContainer  If dictionary has reached maximum capacity.
     * @throws     DuplicateKey   If entry with same key as 'k' already exists 
     *                            in Dictionary.
     */         
    void insert(std::string k, const Data& d) throw(FullContainer, DuplicateKey);
    

    /**
     * @brief      Removes the entry containing the key 'k' from the dictionary.
     *
     * @param[in]  k     Key of entry to be removed.
     * @throws     EmptyContainer  If Dictionary contains no entries to remove.
     * @throws     MissingKey      If no entry with key 'k' exists in 
     *                             Dictionary.
     *
     * @return     Constant reference to Data object paired with key 'k'.
     */
    const Data& remove(std::string k) throw(EmptyContainer, MissingKey);
    

    /**
     * @brief      Retrieves the value paired with key 'k'.
     *
     * @param[in]  k     Key paired with Data to be retrieved.
     * @throws     EmptyContainer  If Dictionary contains no entries to remove.
     * @throws     MissingKey      If no entry with key 'k' exists in 
     *                             Dictionary.
     * 
     * @return     Constant reference to Data object paired with key 'k'.
     */
    const Data& lookup(std::string k) throw(EmptyContainer, MissingKey);

    
    /**
     * @brief      Gets the number of key/value pairs stored in the dictionary.
     *
     * @return     The number of std::string/Data pairs stored in Dictionary.
     */
    int get_size();
    

    /**
     * @brief      Gets a list of keys stored in the dictionary.
     *
     * @return     The list of keys stored as a single std::string. Each key is
     *             seperated by a newline character '\n'.
     */
    std::string get_key_list();
    

    /**
     * @brief      Determines if there is an entry with the key 'k' in the
     *             dictionary.
     *
     * @param[in]  k     Key to be compared.
     *
     * @return     True if has key 'k' is in Dictionary, False otherwise.
     */
    bool has_key(std::string k);

private:
    /**
     * @brief      Performs a binary search on the keys stored in entries[].
     *
     * @param[in]  k     Key to be compared.
     *
     * @return     If Entry containing key 'k' exists in entries[], returns
     *             index of that Entry. If no Entry contains key 'k', returns
     *             the index of the cell in entries[] where key 'k' would belong
     *             if stored alphabetically.
     */
    int bin_search(std::string k);
    
    struct Entry
    {
        std::string key;
        const Data* data;
    };
   
    static const int CAP = 200;
    int capacity;
    int size;
    

    /**
     * Pointer to array that contains all Entry objects stored by Dictionary,
     * sorted alphabetically by key.
     */
    Entry * entries;
    

    /**
     * Sorted list containing the names of all keys in Dictionary, as
     * std::strings.
     */
    SortedList key_list;
};

#include "dictionary.inl.h"