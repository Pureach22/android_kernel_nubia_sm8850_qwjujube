__int64 __fastcall lmac_get_pdev_target_type(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w8
  _DWORD *v14; // x19

  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 2800);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 496);
    }
    else
    {
      v14 = a2;
      qdf_trace_msg(0x49u, 2u, "%s: target_psoc_info is null", a3, a4, a5, a6, a7, a8, a9, a10, "lmac_get_tgt_type");
      a2 = v14;
      v12 = 0;
    }
    *a2 = v12;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "lmac_get_pdev_target_type");
    return 16;
  }
}
