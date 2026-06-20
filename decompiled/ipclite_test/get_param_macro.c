unsigned __int64 get_param_macro()
{
  return ((unsigned __int64)(unsigned int)test_params << 56)
       | ((unsigned __int64)(HIDWORD(test_params) & 0xFFFFF) << 28)
       | ((unsigned __int64)(qword_B680 & 0xFFF) << 16)
       | (16 * (qword_B688 & 0xFFF))
       | qword_B694 & 0xF
       | 0x2000000000000LL;
}
