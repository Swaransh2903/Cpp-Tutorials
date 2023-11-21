// So basically we'll be given a set of words sorted in an alien language comprising of only the first k characters
// of english alphabet. Based on the words , we need to figure out the sorted order of the alphabets in alien order.

// Eg: baa, abcd, abca, cab, cad-> Suppose using this we need to figure out the sorted order of a,b,c,d in alien
// dictionary. 

// How to solve? since baa < abcd -> we can say b appears before a . Similary comparing second and third string , we
// can say that d appears before a and by comparing third and fourth c appears after a. Therefore order: b,d,a,c

// So basically , we look for the first conflicting character(non matching) and then figure out which one is smallest
// Look's like 