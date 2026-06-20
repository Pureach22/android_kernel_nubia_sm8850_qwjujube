__int64 __fastcall dss_reg_dump(__int64 result, unsigned int a2, __int64 a3, int a4)
{
  if ( a4 )
    return print_hex_dump(&unk_2597DF, a3, 2, 32, 4, result, a2, 0);
  return result;
}
