__int64 __fastcall hal_rx_fst_detach(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0

  if ( a10 && a11 )
  {
    qdf_ssr_driver_dump_unregister_region("hal_rx_fst", a1, a2, a3, a4, a5, a6, a7, a8);
    if ( !a12 )
    {
      if ( *(_QWORD *)a10 )
      {
        qdf_ssr_driver_dump_unregister_region("dp_fisa_hw_fse_table", v15, v16, v17, v18, v19, v20, v21, v22);
        _qdf_mem_free_consistent(a11, *(_QWORD *)(a11 + 40), *(_DWORD *)(a10 + 40) * *(unsigned __int16 *)(a10 + 24));
      }
    }
    return _qdf_mem_free(a10);
  }
  return result;
}
