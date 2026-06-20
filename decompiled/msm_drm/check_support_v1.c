__int64 __fastcall check_support_v1(unsigned int a1, int a2, bool *a3)
{
  bool v3; // w8

  if ( !a3 )
    return 4294967274LL;
  v3 = a1 <= 0x18 && (v1_supported[a1] & a2) != 0;
  *a3 = v3;
  return 0;
}
