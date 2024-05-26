#include <Account.h>
#include <Transaction.h>
#include <gtest/gtest.h>

TEST(Transaction, Banking) {
    const int initial_balance_Alice = 10000;
    const int initial_balance_Bob = 2000;
    const int transaction_fee = 50;

    Account Alice(0, initial_balance_Alice), Bob(1, initial_balance_Bob);
    Transaction test_tran;

    ASSERT_EQ(test_tran.fee(), 1);
    test_tran.set_fee(transaction_fee);
    ASSERT_EQ(test_tran.fee(), transaction_fee);

    ASSERT_THROW(test_tran.Make(Alice, Alice, 2000), std::logic_error);
    ASSERT_THROW(test_tran.Make(Alice, Bob, -100), std::invalid_argument);
    ASSERT_THROW(test_tran.Make(Alice, Bob, 50), std::logic_error);

    if (test_tran.fee() * 2 - 1 >= 200) {
        ASSERT_FALSE(test_tran.Make(Alice, Bob, test_tran.fee() * 2 - 1));
    }

    Alice.Lock();
    ASSERT_THROW(test_tran.Make(Alice, Bob, 2000), std::runtime_error);
    Alice.Unlock();

    ASSERT_TRUE(test_tran.Make(Alice, Bob, 2000));
    ASSERT_EQ(Bob.GetBalance(), initial_balance_Bob + 2000);	
    ASSERT_EQ(Alice.GetBalance(), initial_balance_Alice - 2000 - transaction_fee);

    ASSERT_FALSE(test_tran.Make(Alice, Bob, 8000));
    ASSERT_EQ(Bob.GetBalance(), initial_balance_Bob + 2000);	
    ASSERT_EQ(Alice.GetBalance(), initial_balance_Alice - 2000 - transaction_fee);
}
