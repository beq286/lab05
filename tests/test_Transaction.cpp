#include "Account.h"
#include "Transaction.h"

#include <gtest/gtest.h>

TEST(Account, check1) {
    Account account(1000, 2000);
    EXPECT_EQ(account.id(), 1000);
    EXPECT_EQ(account.GetBalance(), 2000);
    EXPECT_EQ(account.GetBalance(), 2000);
    Account Count1(110, 1000);
    Account Count2(110, 1000);
    Transaction transaction;
    try {
        transaction.Make(Count1, Count2, 1000);
        FAIL() << "expected error" << std::endl;
    } catch(std::logic_error& err) {
        EXPECT_EQ(err.what(), std::string("invalid action"));
    } catch(...) {
        FAIL() << "expected logic error" << std::endl;
    }
}

TEST(Account, check2) {
    Account test(1,2);
    
    ASSERT_EQ(test.GetBalance(), 2);
    
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);
    
    test.Lock();
    
    ASSERT_NO_THROW(test.ChangeBalance(100));
    
    ASSERT_EQ(test.GetBalance(), 102);
    
    ASSERT_THROW(test.Lock(), std::runtime_error);
    
    test.Unlock();
    ASSERT_THROW(test.ChangeBalance(102), std::runtime_error);
}

TEST(Transaction, id_check) {
    Account Check1(11, 100);
    Account Check2(11, 100);
    Transaction transaction;
    
    try {
        transaction.Make(Check1, Check2, 100);
        FAIL() << "expected error" << std::endl;
    } catch(std::logic_error& err) {
        EXPECT_EQ(err.what(), std::string("invalid action"));
    } catch(...) {
        FAIL() << "expected logic error" << std::endl;
    }
}

TEST(Transaction, sum_check) {
    Account Check1(1, 1000);
    Account Check2(12, 100);
    Transaction transaction;
    
    try {
        transaction.Make(Check1, Check2, -100);
        FAIL() << "expected error" << std::endl;
    } catch(std::invalid_argument& arg) {
        
        EXPECT_EQ(arg.what(), std::string("sum can't be negative"));
    } catch(...) {
        FAIL() << "expected argument error" << std::endl;
    }
}



TEST(Transaction, change_balance) {
    Account Check1(173, 1000);
    Account Check2(12, 100);
    try {
        Check1.ChangeBalance(30);
        FAIL() << "expected error" << std::endl;
    } catch(std::runtime_error& time) {
        EXPECT_EQ(time.what(), std::string("at first lock the account"));
    } catch(...) {
        FAIL() << "expected time error" << std::endl;
    }
}
