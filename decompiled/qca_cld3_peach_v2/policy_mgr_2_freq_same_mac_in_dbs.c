__int64 __fastcall policy_mgr_2_freq_same_mac_in_dbs(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x20
  unsigned int v16; // w8
  unsigned int v17; // w8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = (_DWORD *)context;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
      return 1;
    if ( (v16 = v15[309], v16 <= a2) && v15[310] >= a2 || v15[311] <= a2 && v15[312] >= a2 )
    {
      if ( v16 <= a3 && v15[310] >= a3 || v15[311] <= a3 && v15[312] >= a3 )
        return 1;
    }
    if ( (v17 = v15[313], v17 <= a2) && v15[314] >= a2 || v15[315] <= a2 && v15[316] >= a2 )
    {
      if ( v17 <= a3 && v15[314] >= a3 || v15[315] <= a3 && v15[316] >= a3 )
        return 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_2_freq_same_mac_in_dbs");
  }
  return 0;
}
