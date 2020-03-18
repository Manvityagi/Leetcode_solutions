//NAIVE STRINGSTREAM
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode *deserialize(string data)
    {
        if (data == "#")
            return NULL;
        stringstream s(data);
        return makeDeserialize(s);
    }

    TreeNode *makeDeserialize(stringstream &s)
    {
        string str;
        getline(s, str, ',');
        if (str == "#")
        {
            return NULL;
        }
        else
        {
            TreeNode *root = new TreeNode(stoi(str));
            root->left = makeDeserialize(s);
            root->right = makeDeserialize(s);
            return root;
        }
    }
};