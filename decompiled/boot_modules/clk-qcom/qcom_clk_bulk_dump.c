unsigned __int64 __fastcall qcom_clk_bulk_dump(
        unsigned __int64 result,
        unsigned __int64 a2,
        unsigned __int64 a3,
        char a4)
{
  __int64 v6; // x21
  unsigned __int64 *v7; // x20
  unsigned __int64 v8; // t1

  LODWORD(v6) = result;
  if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
    result = gdsc_debug_print_regs(a3);
  if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL && (int)v6 >= 1 )
  {
    v6 = (unsigned int)v6;
    v7 = (unsigned __int64 *)(a2 + 8);
    do
    {
      v8 = *v7;
      v7 += 2;
      result = qcom_clk_dump(v8, 0, a4 & 1);
      --v6;
    }
    while ( v6 );
  }
  return result;
}
