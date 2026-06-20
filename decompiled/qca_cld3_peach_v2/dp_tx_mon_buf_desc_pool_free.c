__int64 __fastcall dp_tx_mon_buf_desc_pool_free(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8

  v9 = *(_QWORD *)(result + 20112);
  if ( v9 )
    return dp_mon_desc_pool_free(result, v9 + 696, 0xDu, a2, a3, a4, a5, a6, a7, a8, a9);
  return result;
}
