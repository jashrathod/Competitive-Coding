// Huffman Decoding

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    MinHeapNode *r = root;
    string s = "";
    for(int i=0; i<binaryString.size(); i++)
    {
        if(binaryString[i] == '0')  r = r->left;
        else if(binaryString[i] == '1')  r = r->right;
        if(r->left == NULL && r->right == NULL)
        {
            s = s + r->data;
            r->freq = r->freq - 1;
            r = root;
        }
    }
    s = s + '\0';
    return s;
}