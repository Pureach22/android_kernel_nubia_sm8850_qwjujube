__int64 __fastcall tgt_dfs_is_5ghz_supported_in_pdev(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x8
  _DWORD *v12; // x8
  const char *v13; // x2
  char v14; // w8
  int v16; // [xsp+Ch] [xbp-14h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v18[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v16 = 0;
  v17 = 0;
  wlan_reg_get_freq_range(a1, nullptr, nullptr, &v17, &v16);
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
    goto LABEL_11;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: tx_ops is null",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_psoc_get_dfs_txops");
    goto LABEL_10;
  }
  v12 = *(_DWORD **)(v11 + 1240);
  if ( !v12 )
  {
LABEL_10:
    v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_tx_ops is null";
    goto LABEL_11;
  }
  if ( *(v12 - 1) != -1393108416 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64, _BYTE *))v12)(a1, v18) )
  {
    v14 = v18[0];
    goto LABEL_12;
  }
  v13 = "WLAN_DEBUG_DFS_ALWAYS : %s: Failed to get is_5ghz value";
LABEL_11:
  qdf_trace_msg(0x27u, 2u, v13, v2, v3, v4, v5, v6, v7, v8, v9, "tgt_dfs_is_5ghz_supported_in_pdev");
  v14 = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
