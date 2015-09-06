<?hh // strict

require 'vendor/autoload.php';

class AboutAsserts extends PHPUnit_Framework_TestCase {

  // We shall contemplate truth by testing reality, via asserts.
  public function test_assert_truth() {
    $this->assertTrue(true);       // This should be true
  }

  // Enlightenment may be more easily achieved with appropriate
  // messages.
  public function test_assert_with_message() {
    $this->assertTrue(true, "This should be true -- Please fix this");
  }

  // To understand reality, we must compare our expectations against
  // reality.
  public function test_assert_equality() {
    $expected_value = 2;
    $actual_value = 1 + 1;

    $this->assertTrue($expected_value == $actual_value);
  }

  // Some ways of asserting equality are better than others.
  public function test_a_better_way_of_asserting_equality() {
    $expected_value = 2;
    $actual_value = 1 + 1;

    $this->assertEquals($expected_value, $actual_value);
  }

  // Sometimes we will ask you to fill in the values
  public function test_fill_in_values() {
    $this->assertEquals(2, 1 + 1);
  }

}
