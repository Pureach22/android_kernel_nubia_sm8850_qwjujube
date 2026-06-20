void __fastcall dp_mon_filter_reset_mon_srng(__int64 a1, unsigned __int8 *a2, int a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w0
  _QWORD v13[12]; // [xsp+0h] [xbp-60h] BYREF

  v13[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 88);
  dp_mon_ht2_rx_ring_cfg(a1, a2, a3, (int *)v13);
  if ( v12 )
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: %pK: Monitor destination ring filter setting failed",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_mon_filter_reset_mon_srng",
      a1);
  _ReadStatusReg(SP_EL0);
}
