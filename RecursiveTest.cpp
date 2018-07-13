// test scaffold

#include "Timer.h"
#include <vector>
#include <bitset>
#include <tuple>

using namespace std;

namespace FindPath
{
    typedef std::tuple<int, int> Cell;
    typedef std::vector<Cell> CellPath;

    template<int nRow, int nCol>
    class Grid
    {
        std::bitset<nRow*nCol> _offLimit; // row major
        CellPath _computedPath[nRow][nCol]; // row major
    public:
        void setOffLimit(int r, int c) { _offLimit.set(r*nCol + c); }
        void resetOffLimit() { _offLimit.reset(); }
        void setComputedPath(int r, int c, const CellPath& path) { _computedPath[r][c] = path; }
        void acquireComputedPath(int r, int c, CellPath& path) { _computedPath[r][c] = std::move(path); }

        bool offLimit(int r, int c) const { return _offLimit[r*nCol + c]; }
        int numRow() const { return nRow; }
        int numCol() const { return nCol; }
        bool pathComputed(int r, int c) const { return !_computedPath[r][c].empty(); } // use extra bitset to track this?
        const CellPath& computedPath(int r, int c) const { return _computedPath[r][c]; }
    };

    inline Cell makeCell(int r, int c) { return std::make_tuple(r, c); }
    
    template<int nRow, int nCol, int nOffLimits> Grid<nRow, nCol> makeGrid()
    {
        Grid<nRow, nCol> g;
        g.resetOffLimit();
        // to do: to precisely respect the input offlimit number
        for (int i = 0; i < nOffLimits; ++i) {
            int r = rand() % nRow, c = rand() % nCol;
            g.setOffLimit(r, c);
        }
        return g;
    }
    
    /// find path vector starting from cell located at (r,c), with consideration /// towards offLimit (avoids cells with offLimit to be on)
    /// r and c are 0 based index into the grid cells
    /// return false if terminated before a complete path is found, true otherwise
    template<int nRow, int nCol>
    bool findPath(const Grid<nRow, nCol>& g, int r, int c, CellPath& path)
    {
        if (r >= nRow || c >= nCol)
            return (r == nRow - 1) || (c == nCol - 1);
        // Invariant: (r,c) is a cell in the grid
        if (g.pathComputed(r, c)) {
            path.insert(std::end(path), std::begin(g.computedPath(r, c)),
                std::end(g.computedPath(r, c)));
            return false;
        }
        if (!g.offLimit(r, c)) {
            path.push_back(makeCell(r, c));
            if (findPath(g, r + 1, c, path)) return true;
            else	return findPath(g, r, c + 1, path);
        }
        else
            return false; // path not complete
    }

    template<int nRow, int nCol, int nOffLimits>
    bool test(CellPath& path)
    {
        Grid<nRow, nCol> g = makeGrid<nRow, nCol, nOffLimits>();
        return findPath<nRow, nCol>(g, 0, 0, path);
    }
}

void testRecursive()
{
    Timer t;

    t.start();
    FindPath::CellPath path;
    FindPath::test<10, 10, 5>(path);
    cout << "FindPath:" << t.elapsedTime() << " seconds." << endl;

}


