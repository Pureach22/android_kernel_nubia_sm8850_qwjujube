__int64 __fastcall dp_rx_mon_filter_update_2_0(
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
  __int64 v9; // x19
  __int64 result; // x0
  _QWORD v12[9]; // [xsp+8h] [xbp-98h] BYREF
  __int128 v13; // [xsp+50h] [xbp-50h]
  __int64 v14; // [xsp+60h] [xbp-40h]
  __int64 v15; // [xsp+68h] [xbp-38h]
  __int64 v16; // [xsp+70h] [xbp-30h]
  __int64 v17; // [xsp+78h] [xbp-28h]
  __int64 v18; // [xsp+80h] [xbp-20h]
  __int64 v19; // [xsp+88h] [xbp-18h]
  __int64 v20; // [xsp+90h] [xbp-10h]
  __int64 v21; // [xsp+98h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  v13 = 0u;
  HIDWORD(v12[0]) = 0;
  memset(&v12[1], 0, 64);
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 8);
    dp_rx_mon_filter_h2t_setup();
    *(_DWORD *)((char *)&v13 + 6) &= ~0x8000u;
    dp_mon_ht2_rx_ring_cfg(v9, (unsigned __int8 *)a1, 3, (__int64)v12 + 4);
    result = 0;
  }
  else
  {
    qdf_trace_msg(0x73u, 2u, "%s: pdev Context is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_rx_mon_filter_update_2_0");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
