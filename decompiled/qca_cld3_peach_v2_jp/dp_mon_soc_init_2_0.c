__int64 __fastcall dp_mon_soc_init_2_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  unsigned int v21; // w8

  if ( *(_QWORD *)(a1 + 480) )
  {
    qdf_trace_msg(0x92u, 5u, "%s: %pK: mon soc init is done", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_soc_init_2_0", a1);
    return 0;
  }
  else
  {
    v11 = *(_QWORD *)(a1 + 20056);
    result = dp_tx_mon_soc_init_2_0(a1);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: SRNG setup failed fortx_mon_buf_ring",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_mon_soc_init_2_0",
        a1);
      v20 = *(_QWORD *)(a1 + 20056);
      if ( *(_BYTE *)(v20 + 852) == 1 )
      {
        dp_tx_mon_soc_deinit_2_0(a1, 0);
        *(_BYTE *)(v20 + 852) = 0;
      }
      return 16;
    }
    else
    {
      *(_WORD *)(v11 + 842) = 0;
      v21 = *(_DWORD *)(a1 + 532);
      if ( v21 >= 0x800 )
        LOWORD(v21) = 2048;
      *(_WORD *)(v11 + 840) = v21;
      *(_BYTE *)(v11 + 852) = 1;
    }
  }
  return result;
}
