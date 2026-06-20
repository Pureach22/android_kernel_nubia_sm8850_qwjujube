__int64 __fastcall hdd_update_dfs_config(__int64 *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v11[0] = 0;
  ucfg_mlme_get_dfs_filter_offload(v1, v11);
  result = ucfg_dfs_update_config(v1, v11);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed dfs psoc configuration",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_update_dfs_config");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
