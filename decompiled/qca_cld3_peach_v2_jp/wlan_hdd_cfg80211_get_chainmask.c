__int64 __fastcall wlan_hdd_cfg80211_get_chainmask(__int64 a1, int *a2, int *a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  unsigned int v9; // w19
  int command; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w5
  int v20; // w4
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 488);
  v21[0] = 0;
  result = _osif_psoc_sync_op_start(v6, v21, "wlan_hdd_cfg80211_get_chainmask");
  if ( (_DWORD)result )
    goto LABEL_13;
  if ( a1 )
  {
    v8 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_get_chainmask");
    if ( (_DWORD)v8 )
    {
      v9 = -22;
LABEL_12:
      _osif_psoc_sync_op_stop(v21[0], "wlan_hdd_cfg80211_get_chainmask");
      result = v9;
LABEL_13:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    *a2 = wma_cli_get_command(v8, 1, 2);
    command = wma_cli_get_command(0, 2, 2);
    *a3 = command;
    if ( *a2 )
    {
      if ( command )
      {
LABEL_11:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: tx_mask: %d rx_mask: %d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "__wlan_hdd_cfg80211_get_chainmask");
        v9 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      if ( *(_DWORD *)(a1 + 2784) == 2 )
        v20 = 3;
      else
        v20 = 1;
      *a2 = v20;
      if ( *a3 )
        goto LABEL_11;
    }
    if ( *(_DWORD *)(a1 + 2784) == 2 )
      v19 = 3;
    else
      v19 = 1;
    *a3 = v19;
    goto LABEL_11;
  }
  __break(0x800u);
  return wlan_hdd_cfg80211_set_rekey_data();
}
