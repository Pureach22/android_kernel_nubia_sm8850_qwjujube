__int64 __fastcall sme_store_pdev(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  result = wlan_objmgr_pdev_try_get_ref(a2, 7u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
  {
    *(_QWORD *)(a1 + 21632) = 0;
  }
  else
  {
    *(_QWORD *)(a1 + 21632) = a2;
    result = (__int64)_cds_get_context(54, (__int64)"sme_store_pdev", v13, v14, v15, v16, v17, v18, v19, v20);
    if ( result )
    {
      result = wma_store_pdev(result, a2);
      *(_DWORD *)(a2 + 8) |= 0x3FFFFu;
    }
  }
  return result;
}
