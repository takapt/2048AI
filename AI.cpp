#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

#define debug(v) (cout << #v << ": " << v << endl)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
template <typename T> void print_container(ostream& os, const T& c) { const char* _s = " "; if (!c.empty()) { __typeof__(c.begin()) last = --c.end(); foreach (it, c) { os << *it; if (it != last) cerr << _s; } } }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }

template <typename T> void print(T a, int n, const string& split = " ") { for (int i = 0; i < n; i++) { cerr << a[i]; if (i + 1 != n) cerr << split; } cerr << endl; }
template <typename T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) { if (width != -1) cerr.width(width); cerr << a[i][j] << ' '; } cerr << endl; } while (br--) cerr << endl; }


#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)
#define ten(n) ((long long)(1e##n))

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;


const int dir_dx[] = { 0, 1, 0, -1 };
const int dir_dy[] = { 1, 0, -1, 0 };
enum Dir
{
    DOWN,
    RIGHT,
    UP,
    LEFT,

    NA,
};
const string dir_s[] = { "down", "right", "up", "left", "NA" };
Dir to_dir(const string& s)
{
    int i = find(dir_s, dir_s + 4, s) - dir_s;
    assert(0 <= i && i < 4);
    return Dir(i);
}
Dir rev_dir(Dir dir)
{
    return Dir((dir + 2) % 4);
}

struct Cell
{
    int x, y;
    Cell(int x, int y)
        : x(x), y(y)
    {
    }
    Cell()
        : x(0), y(0)
    {
    }

    bool operator==(const Cell& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator !=(const Cell& other) const
    {
        return x != other.x || y != other.y;
    }

    void operator+=(const Cell& other)
    {
        x += other.x;
        y += other.y;
    }
    void operator-=(const Cell& other)
    {
        x -= other.x;
        y -= other.y;
    }

    Cell operator+(const Cell& other) const
    {
        Cell res = *this;
        res += other;
        return res;
    }
    Cell operator-(const Cell& other) const
    {
        Cell res = *this;
        res -= other;
        return res;
    }
    Cell operator*(int a) const
    {
        return Cell(x * a, y * a);
    }

    bool operator<(const Cell& other) const
    {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }
};

Cell operator*(int a, const Cell& cell)
{
    return cell * a;
}
Cell to_cell(Dir dir)
{
    assert(0 <= dir && dir < 4);
    return Cell(dir_dx[dir], dir_dy[dir]);
}

namespace std
{
    ostream& operator<<(ostream& os, Dir dir)
    {
        os << dir_s[dir];
        return os;
    }

    ostream& operator<<(ostream& os, const Cell& c)
    {
        char buf[256];
        sprintf(buf, "(%d, %d)", c.x, c.y);
        os << buf;
        return os;
    }
}


const int BOARD_SIZE = 4;


class Board
{
public:
    Board()
    {
        rep(y, BOARD_SIZE) rep(x, BOARD_SIZE)
            board[y][x] = 0;
    }

    int at(int x, int y) const
    {
        assert(0 <= x && x < BOARD_SIZE);
        assert(0 <= y && y < BOARD_SIZE);
        return board[y][x];
    }
    int at(const Cell& cell) const
    {
        return at(cell.x, cell.y);
    }
    int& at(int x, int y)
    {
        assert(0 <= x && x < BOARD_SIZE);
        assert(0 <= y && y < BOARD_SIZE);
        return board[y][x];
    }
    int& at(const Cell& cell)
    {
        return at(cell.x, cell.y);
    }

    int move(Dir dir)
    {
        int added_score = 0;
        const Cell diff = to_cell(rev_dir(dir));
        const vector<Cell>& gl = gravity_line(dir);
        for (const Cell& start : gl)
        {
            int nums[BOARD_SIZE];
            int n = 0;
            {
                Cell c = start;
                rep(i, BOARD_SIZE)
                {
                    if (at(c) != 0)
                        nums[n++] = at(c);
                    at(c) = 0;
                    c += diff;
                }
            }

            {
                rep(i, n - 1)
                {
                    if (nums[i] == nums[i + 1])
                    {
                        nums[i] *= 2;
                        nums[i + 1] = -1;
                        added_score += nums[i];
                        ++i;
                    }
                }

                Cell c = start;
                rep(i, n)
                {
                    if (nums[i] != -1)
                    {
                        at(c) = nums[i];
                        c += diff;
                    }
                }
            }
        }

        return added_score;
    }

    bool can_move(Dir dir) const
    {
        const Cell diff = to_cell(rev_dir(dir));
        const vector<Cell>& gl = gravity_line(dir);
        for (const Cell& start : gl)
        {
            Cell cells[BOARD_SIZE];
            int n = 0;
            {
                Cell c = start;
                rep(i, BOARD_SIZE)
                {
                    if (at(c) != 0)
                        cells[n++] = c;
                    c += diff;
                }
            }

            if (n > 0)
            {
                if (cells[0] != start)
                    return true;
                rep(i, n - 1)
                {
                    Cell d = cells[i] - cells[i + 1];
                    if (abs(d.x) > 1 || abs(d.y) > 1 || at(cells[i]) == at(cells[i + 1]))
                        return true;
                }
            }
        }
        return false;
    }

    void put(int x, int y, int num)
    {
        at(x, y) = num;
    }
    void put(const Cell& cell, int num)
    {
        at(cell) = num;
    }

    vector<Dir> available_moves() const
    {
        vector<Dir> dirs;
        rep(dir, 4)
            if (can_move(Dir(dir)))
                dirs.push_back(Dir(dir));
        return dirs;
    }

    vector<Cell> empty_cells() const
    {
        vector<Cell> cells;
        rep(y, BOARD_SIZE) rep(x, BOARD_SIZE)
            if (at(x, y) == 0)
                cells.push_back(Cell(x, y));
        return cells;
    }

    string to_s() const
    {
        string s;
        rep(y, BOARD_SIZE)
        {
            rep(x, BOARD_SIZE)
            {
                char buf[256];
                sprintf(buf, "%4d ", at(x, y));
                s += buf;
            }
            s += "\n";
        }
        return s;
    }

private:
    int board[BOARD_SIZE][BOARD_SIZE];


    bool in_range(const Cell& cell) const
    {
        return 0 <= cell.x && cell.x < BOARD_SIZE && 0 <= cell.y && cell.y < BOARD_SIZE;
    }

    const vector<Cell>& gravity_line(Dir dir) const
    {
#if 1
        static const vector<Cell> down_line = {
            Cell(0, BOARD_SIZE - 1), 
            Cell(1, BOARD_SIZE - 1), 
            Cell(2, BOARD_SIZE - 1), 
            Cell(3, BOARD_SIZE - 1), 
        };
        static const vector<Cell> left_line = {
            Cell(0, 0),
            Cell(0, 1),
            Cell(0, 2),
            Cell(0, 3),
        };
        static const vector<Cell> up_line = {
            Cell(0, 0),
            Cell(1, 0),
            Cell(2, 0),
            Cell(3, 0),
        };
        static const vector<Cell> right_line = {
            Cell(BOARD_SIZE - 1, 0),
            Cell(BOARD_SIZE - 1, 1),
            Cell(BOARD_SIZE - 1, 2),
            Cell(BOARD_SIZE - 1, 3),
        };
        static const vector<Cell> table[] = { down_line, right_line, up_line, left_line };
        return table[dir];
#else
        static vector<Cell> down_line, left_line, up_line, right_line;
        switch (dir)
        {
            case DOWN:
                if (down_line.empty())
                    rep(x, BOARD_SIZE)
                        down_line.push_back(Cell(x, BOARD_SIZE - 1));
                return down_line;

            case LEFT:
                if (left_line.empty())
                    rep(y, BOARD_SIZE)
                        left_line.push_back(Cell(0, y));
                return left_line;

            case UP:
                if (up_line.empty())
                    rep(x, BOARD_SIZE)
                        up_line.push_back(Cell(x, 0));
                return up_line;

            case RIGHT:
                if (right_line.empty())
                    rep(y, BOARD_SIZE)
                        right_line.push_back(Cell(BOARD_SIZE - 1, y));
                return right_line;

            default:
                abort();
        }
#endif
    }
};



double _eval_board(const Board& board, const Cell& start, Dir line_dir, Dir next_line_dir)
{
    Cell line_diff = to_cell(line_dir);
    Cell next_line_diff = to_cell(next_line_dir);
    double score = 0;
    double weight = 1;
    Cell cur = start;
    rep(i, BOARD_SIZE)
    {
        rep(j, BOARD_SIZE)
        {
            int num = board.at(cur);
            score += weight * num;

            if (j < BOARD_SIZE - 1)
                cur += line_diff;

            weight /= 32;
        }
        cur += next_line_diff;
        line_diff = -1 * line_diff;
    }
    return score;
}
double eval_board(const Board& board)
{
    double score = -1e60;
    rep(y, 2) rep(x, 2)
    {
        int sx = x == 0 ? 0 : BOARD_SIZE - 1;
        int sy = y == 0 ? 0 : BOARD_SIZE - 1;
        Cell start(sx, sy);

        {
            Dir line_dir = x == 0 ? RIGHT : LEFT;
            Dir next_line_dir = y == 0 ? DOWN : UP;
            upmax(score, _eval_board(board, start, line_dir, next_line_dir));
        }
        {
            Dir line_dir = y == 0 ? DOWN : UP;
            Dir next_line_dir = x == 0 ? RIGHT : LEFT;
            upmax(score, _eval_board(board, start, line_dir, next_line_dir));
        }
    }
    return score;
}

class Solver
{
public:
    Dir best_move(const Board& init_board)
    {
        vector<int> nums;
        rep(y, BOARD_SIZE) rep(x, BOARD_SIZE)
            nums.push_back(init_board.at(x, y));
        sort(all(nums), greater<int>());

        const int num_empty = init_board.empty_cells().size();
        int max_depth;
        if (num_empty >= 6)
            max_depth = 3;
        else
            max_depth = 4;

        auto res = move_node(init_board, max_depth);
        double score = res.first;
        Dir move = res.second;

        return move;
    }

private:
    pair<double, Dir> move_node(const Board& board, int rem_depth)
    {
        assert(rem_depth > 0);

        auto moves = board.available_moves();
        if (moves.empty())
            return make_pair(0, NA);

        double best_score = -1;
        Dir best_move = moves[0];
        for (Dir move : moves)
        {
            Board next = board;
            next.move(move);
            double score = random_put_node(next, rem_depth - 1);
            if (score > best_score)
            {
                best_score = score;
                best_move = move;
            }
        }
        return make_pair(best_score, best_move);
    }
    double random_put_node(const Board& board, int rem_depth)
    {
        auto cand = board.empty_cells();

        if (rem_depth == 0)
            return eval_board(board);

        double exp = 0;
        for (Cell c : cand)
        {
            static const int nums[] = { 2, 4 };
            static const double probs[] = { 0.9, 0.1 };
            rep(i, 2)
            {
                int num = nums[i];
                double prob = probs[i];
                Board next = board;
                next.put(c, num);
                exp += prob * move_node(next, rem_depth).first;
            }
        }
        exp /= cand.size();
        return exp;
    }
};



struct PlayResult
{
    int score;
    int turns;
    Board board;

    string info()
    {
        string res;
        res += "score: " + to_s(score) + "\n";
        res += "turns: " + to_s(turns) + "\n";
        res += board.to_s();
        return res;
    }
};
void rand_put(Board& board)
{
    vector<Cell> cells = board.empty_cells();
    if (!cells.empty())
    {
        Cell c = cells[rand() % cells.size()];
        int num = rand() % 100 < 90 ? 2 : 4;
        board.put(c, num);
    }
}
PlayResult play_in_console(bool log = true)
{
    Board board;
    rand_put(board);
    rand_put(board);

    int score = 0;
    int turns = 0;
    while (!board.available_moves().empty())
    {
        if (log)
        {
            debug(turns);
            debug(score);
            debug(eval_board(board));
            cout << board.to_s() << endl;
        }

        auto am = board.available_moves();
        if (am.empty())
            break;

        Dir move = Solver().best_move(board);
        assert(move != NA);

        score += board.move(Dir(move));
        rand_put(board);
        ++turns;
    }

    PlayResult res;
    res.score = score;
    res.board = board;
    res.turns = turns;

    return res;
}
void play_loop()
{
    int best_score = -1;
    vector<PlayResult> res;
    rep(i, 1000)
    {
        auto r = play_in_console(false);
        res.push_back(r);

        upmax(best_score, r.score);
        debug(best_score);
        cout << r.info() << endl;
    }

    vector<int> scores;
    for (auto& r : res)
        scores.push_back(r.score);
    sort(all(scores));
    rep(i, 10)
        cout << scores[sz(scores) - 1 - i] << endl;
    int med_score = scores[scores.size() / 2];
    debug(med_score);
}
void play_in_browser()
{
    int ai_score = 0;
    while(true) {
        int continued;
        int score, best;
        std::cin >> continued;
        std::cin >> score >> best;
        assert(ai_score == score);

        Board board;
        rep(y, 4) rep(x, 4)
        {
            int a;
            cin >> a;
            board.put(x, y, a);
        }
        auto moves = board.available_moves();

        if (!continued) {
            assert(moves.empty());
            std::cout << "exit" << std::endl;
            std::cout.flush();

            ofstream fs("hoge.txt");
            fs << ai_score << endl;
            fs << board.to_s() << endl;
            break;
        }

        Dir move = Solver().best_move(board);

        int added = board.move(move);
        ai_score += added;

        cout << to_s(move) << endl;
        cout.flush();
    }
}
void play_in_hackerrank()
{
    Board board;
    rep(y, 4) rep(x, 4)
    {
        int a;
        cin >> a;
        board.put(x, y, a);
    }

    Dir move = Solver().best_move(board);
    string res = to_s(move);
    for (char& c : res)
        c = toupper(c);
    cout << res << endl;
}
int main()
{
    srand(time(NULL));

//     play_in_browser();
    play_in_console();
//     play_in_console(false);
//     play_loop();
//     play_in_hackerrank();
}
