__int64 __fastcall wma_store_pdev(
        _QWORD *a1,
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
  _QWORD *v21; // x8

  result = wlan_objmgr_pdev_try_get_ref(a2, 8u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
  {
    a1[4] = 0;
  }
  else
  {
    a1[4] = a2;
    result = target_if_store_pdev_target_if_ctx(
               (__int64)wma_get_pdev_from_scn_handle,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20);
    v21 = *(_QWORD **)(a1[4] + 1232LL);
    if ( v21 )
      *v21 = *a1;
  }
  return result;
}
