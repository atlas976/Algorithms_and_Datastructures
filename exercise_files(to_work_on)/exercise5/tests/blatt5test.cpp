//
// Created by Robin on 25.03.24.
//

#include <gtest/gtest.h>
#include <cmath>
#include "../include/blatt5.h"

using DATA = std::tuple<int, int, long>;

TEST(PiApprox, First1000) {
    for(int numDigits = 1; numDigits <= 1000; numDigits++) {
        float res = pi(numDigits);
        double diff = std::abs(M_PI - res);
        ASSERT_LE(diff * numDigits, 2);
    }
}

void checkBinom(int n, int k, long sol, long(*func)(int, int)) {
    long output = func(n, k);
    ASSERT_EQ(output, sol);
}

class BinomRecursive : public testing::TestWithParam<DATA> {};

TEST_P(BinomRecursive, CheckNumbers) {
    auto [n, k, sol] = GetParam();
    checkBinom(n, k, sol, binom_rec);
}

class BinomIterative : public testing::TestWithParam<DATA> {};

TEST_P(BinomIterative, CheckNumbers) {
    auto [n, k, sol] = GetParam();
    checkBinom(n, k, sol, binom_iter);
}

const auto first10rows = testing::Values(DATA{0, 0, 1}, DATA{1, 0, 1}, DATA{1, 1, 1}, DATA{2, 0, 1}, DATA{2, 1, 2}, DATA{2, 2, 1}, DATA{3, 0, 1}, DATA{3, 1, 3}, DATA{3, 2, 3}, DATA{3, 3, 1}, DATA{4, 0, 1}, DATA{4, 1, 4}, DATA{4, 2, 6}, DATA{4, 3, 4}, DATA{4, 4, 1}, DATA{5, 0, 1}, DATA{5, 1, 5}, DATA{5, 2, 10}, DATA{5, 3, 10}, DATA{5, 4, 5}, DATA{5, 5, 1}, DATA{6, 0, 1}, DATA{6, 1, 6}, DATA{6, 2, 15}, DATA{6, 3, 20}, DATA{6, 4, 15}, DATA{6, 5, 6}, DATA{6, 6, 1}, DATA{7, 0, 1}, DATA{7, 1, 7}, DATA{7, 2, 21}, DATA{7, 3, 35}, DATA{7, 4, 35}, DATA{7, 5, 21}, DATA{7, 6, 7}, DATA{7, 7, 1}, DATA{8, 0, 1}, DATA{8, 1, 8}, DATA{8, 2, 28}, DATA{8, 3, 56}, DATA{8, 4, 70}, DATA{8, 5, 56}, DATA{8, 6, 28}, DATA{8, 7, 8}, DATA{8, 8, 1}, DATA{9, 0, 1}, DATA{9, 1, 9}, DATA{9, 2, 36}, DATA{9, 3, 84}, DATA{9, 4, 126}, DATA{9, 5, 126}, DATA{9, 6, 84}, DATA{9, 7, 36}, DATA{9, 8, 9}, DATA{9, 9, 1}, DATA{10, 0, 1}, DATA{10, 1, 10}, DATA{10, 2, 45}, DATA{10, 3, 120}, DATA{10, 4, 210}, DATA{10, 5, 252}, DATA{10, 6, 210}, DATA{10, 7, 120}, DATA{10, 8, 45}, DATA{10, 9, 10}, DATA{10, 10, 1});

INSTANTIATE_TEST_SUITE_P(
        First10Rows,
        BinomRecursive,
        first10rows
);

INSTANTIATE_TEST_SUITE_P(
        First10Rows,
        BinomIterative,
        first10rows
);

const auto tailrecData = testing::Values(DATA{7, 1, 7}, DATA{33, 4, 324}, DATA{10, 1, 1}, DATA{15, 2, 26}, DATA{32, 4, 259}, DATA{1, 4, 1}, DATA{31, 4, 244}, DATA{79, 2, 424}, DATA{72, 5, 117681}, DATA{19, 4, 6562}, DATA{31, 3, 82}, DATA{64, 1, 40}, DATA{58, 3, 1137}, DATA{42, 2, 68}, DATA{80, 4, 32768}, DATA{4, 1, 4}, DATA{65, 1, 41}, DATA{78, 2, 407}, DATA{21, 4, 33}, DATA{10, 2, 1}, DATA{54, 1, 29}, DATA{14, 5, 1025}, DATA{54, 3, 689}, DATA{64, 2, 232}, DATA{73, 2, 352}, DATA{25, 2, 33}, DATA{53, 3, 652}, DATA{50, 4, 3125}, DATA{38, 1, 17}, DATA{61, 1, 37}, DATA{67, 2, 265}, DATA{75, 2, 368}, DATA{13, 3, 28}, DATA{11, 3, 2}, DATA{44, 4, 1280}, DATA{70, 1, 49}, DATA{33, 4, 324}, DATA{30, 2, 27}, DATA{14, 4, 257}, DATA{74, 1, 53}, DATA{3, 3, 27}, DATA{5, 1, 5}, DATA{28, 4, 4128}, DATA{34, 1, 13}, DATA{47, 5, 20903}, DATA{56, 3, 841}, DATA{18, 3, 513}, DATA{65, 2, 241}, DATA{53, 2, 134}, DATA{67, 2, 265}, DATA{27, 4, 2433}, DATA{29, 2, 89}, DATA{49, 5, 63145}, DATA{39, 4, 6804}, DATA{46, 5, 11872}, DATA{31, 2, 28}, DATA{48, 4, 5120}, DATA{7, 2, 49}, DATA{56, 2, 161}, DATA{4, 4, 256}, DATA{78, 5, 150417}, DATA{74, 4, 17063}, DATA{80, 3, 4096}, DATA{20, 1, 4}, DATA{4, 1, 4}, DATA{8, 4, 4096}, DATA{4, 2, 16}, DATA{77, 2, 392}, DATA{48, 2, 128}, DATA{27, 1, 11}, DATA{26, 1, 10}, DATA{21, 5, 65}, DATA{77, 4, 19208}, DATA{9, 1, 9}, DATA{42, 1, 18}, DATA{63, 3, 1323}, DATA{72, 3, 2409}, DATA{13, 4, 82}, DATA{60, 2, 216}, DATA{73, 1, 52}, DATA{36, 5, 8505}, DATA{40, 4, 1024}, DATA{78, 1, 57}, DATA{5, 4, 625}, DATA{63, 4, 7857}, DATA{64, 4, 8032}, DATA{22, 1, 6}, DATA{22, 1, 6}, DATA{32, 4, 259}, DATA{26, 1, 10}, DATA{71, 4, 16808}, DATA{18, 2, 65}, DATA{9, 1, 9}, DATA{4, 5, 1024}, DATA{58, 2, 189}, DATA{8, 2, 64}, DATA{20, 5, 64}, DATA{71, 3, 2402}, DATA{79, 3, 3130}, DATA{55, 1, 30}, DATA{11, 3, 2}, DATA{66, 3, 1512}, DATA{60, 4, 7776}, DATA{46, 2, 100}, DATA{27, 4, 2433}, DATA{46, 3, 472}, DATA{60, 5, 46656}, DATA{62, 3, 1304}, DATA{67, 1, 43}, DATA{6, 3, 216}, DATA{12, 2, 5}, DATA{8, 1, 8}, DATA{61, 1, 37}, DATA{36, 5, 8505}, DATA{23, 5, 307}, DATA{2, 2, 4}, DATA{37, 5, 17536}, DATA{30, 1, 9}, DATA{32, 4, 259}, DATA{66, 2, 252}, DATA{29, 3, 745}, DATA{15, 5, 3126}, DATA{41, 5, 4097}, DATA{2, 3, 8}, DATA{16, 4, 1297}, DATA{36, 5, 8505}, DATA{76, 1, 55}, DATA{24, 4, 288}, DATA{76, 3, 2617}, DATA{63, 2, 225}, DATA{44, 1, 20}, DATA{27, 5, 16871}, DATA{50, 4, 3125}, DATA{54, 1, 29}, DATA{33, 5, 972}, DATA{7, 5, 16807}, DATA{5, 1, 5}, DATA{7, 2, 49}, DATA{73, 1, 52}, DATA{33, 3, 108}, DATA{44, 4, 1280}, DATA{51, 3, 626}, DATA{11, 3, 2}, DATA{26, 4, 1328}, DATA{17, 1, 8}, DATA{80, 1, 64}, DATA{19, 5, 59050}, DATA{37, 5, 17536}, DATA{54, 1, 29}, DATA{60, 2, 216}, DATA{32, 4, 259}, DATA{54, 5, 16649}, DATA{30, 4, 243}, DATA{23, 5, 307}, DATA{20, 5, 64}, DATA{27, 2, 57}, DATA{7, 4, 2401}, DATA{80, 1, 64}, DATA{39, 4, 6804}, DATA{8, 1, 8}, DATA{12, 4, 17}, DATA{24, 4, 288}, DATA{51, 3, 626}, DATA{65, 3, 1421}, DATA{58, 1, 33}, DATA{65, 4, 8401}, DATA{36, 3, 297}, DATA{9, 4, 6561}, DATA{41, 2, 65}, DATA{75, 1, 54}, DATA{17, 5, 16808}, DATA{23, 5, 307}, DATA{36, 5, 8505}, DATA{25, 2, 33}, DATA{30, 4, 243}, DATA{52, 3, 633}, DATA{39, 2, 108}, DATA{68, 2, 280}, DATA{77, 3, 2744}, DATA{49, 5, 63145}, DATA{5, 3, 125}, DATA{39, 1, 18}, DATA{32, 5, 761}, DATA{55, 3, 750}, DATA{14, 4, 257}, DATA{5, 5, 3125}, DATA{15, 5, 3126}, DATA{46, 5, 11872}, DATA{20, 3, 16}, DATA{33, 3, 108}, DATA{27, 1, 11}, DATA{40, 3, 256}, DATA{76, 1, 55}, DATA{40, 3, 256}, DATA{69, 4, 14337}, DATA{75, 5, 120774}, DATA{34, 1, 13}, DATA{49, 1, 25}, DATA{36, 5, 8505}, DATA{47, 1, 23});

class TailRecursiveG : public testing::TestWithParam<DATA> {};

TEST_P(TailRecursiveG, CheckNumbers) {
    auto [x, y, sol] = GetParam();
    int output = g_tailrec(x, y);
    ASSERT_EQ(output, sol);
}

INSTANTIATE_TEST_SUITE_P(
        TailRecursive,
        TailRecursiveG,
        tailrecData
);

class IterativeG : public testing::TestWithParam<DATA> {};

TEST_P(IterativeG, CheckNumbers) {
    auto [x, y, sol] = GetParam();
    int output = g_iter(x, y);
    ASSERT_EQ(output, sol);
}

INSTANTIATE_TEST_SUITE_P(
        Iterative,
        IterativeG,
        tailrecData
);