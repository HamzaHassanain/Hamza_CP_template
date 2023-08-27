
struct LazyPropagationSegmentTreeWithMultipleQueryingTechniques
{
    int size;
    long long DEFAULT;
    vector<long long> data, lazy;
    vector<long long> lazyAdder;
    void init(int n, long long DEFAULT)
    {
        size = 1;
        this->DEFAULT = DEFAULT;
        while (size < n)
            size *= 2;
        data.assign(2 * size, DEFAULT);
        lazy.assign(2 * size, DEFAULT);
        lazyAdder.assign(2 * size, 0);
    }

    void addLazy(int &node, int &beginSeg, int &endSeg)
    {
        if (lazyAdder[node] != 0)
        {
            long long dx = lazyAdder[node];
            lazyAdder[node] = 0;
            data[node] += dx;
            if (beginSeg != endSeg)
            {
                lazyAdder[2 * node] += dx;
                lazyAdder[2 * node + 1] += dx;
            }
        }
    }
    void workLazy(int &node, int &beginSeg, int &endSeg)
    {
        if (lazy[node] != DEFAULT)
        {
            long long dx = lazy[node];
            lazy[node] = DEFAULT;
            data[node] = dx;
            if (beginSeg != endSeg)
            {
                lazy[2 * node] = dx;
                lazy[2 * node + 1] = dx;
            }
        }

        addLazy(node, beginSeg, endSeg);
    }
    void set(int left, int right, int node, int beginSeg, int endSeg, ll value)
    {
        workLazy(node, beginSeg, endSeg);

        if (beginSeg > right || left > endSeg)
            return;

        if (beginSeg >= left && endSeg <= right)
        {
            long long dx = value;
            data[node] = dx;

            if (beginSeg != endSeg)
            {
                lazy[2 * node] = value;
                lazy[2 * node + 1] = value;
            }
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        this->set(left, right, 2 * node, beginSeg, mid, value);
        this->set(left, right, 2 * node + 1, mid + 1, endSeg, value);

        data[node] = min(data[2 * node], data[2 * node + 1]);
    }
    void add_value(int left, int right, int node, int beginSeg, int endSeg, ll value)
    {
        workLazy(node, beginSeg, endSeg);
        if (beginSeg > right || left > endSeg)
            return;

        if (beginSeg >= left && endSeg <= right)
        {
            long long dx = value;
            data[node] += dx;

            if (beginSeg != endSeg)
            {
                lazyAdder[2 * node] += value;
                lazyAdder[2 * node + 1] += value;
            }
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        this->add_value(left, right, 2 * node, beginSeg, mid, value);
        this->add_value(left, right, 2 * node + 1, mid + 1, endSeg, value);

        data[node] = min(data[2 * node], data[2 * node + 1]);
    }
    long long query(int left, int right, int node, int beginSeg, int endSeg)
    {
        workLazy(node, beginSeg, endSeg);

        if (beginSeg > right || left > endSeg)
            return DEFAULT;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        long long a = this->query(left, right, 2 * node, beginSeg, mid);
        long long b = this->query(left, right, 2 * node + 1, mid + 1, endSeg);

        return min(a, b);
    }
    long long query(int left, int right)
    {

        return query(left, right, 1, 1, size);
    }
    void set(int left, int right, long long value)
    {
        set(left, right, 1, 1, size, value);
    }
    void add_value(int left, int right, long long value)
    {
        add_value(left, right, 1, 1, size, value);
    }
};