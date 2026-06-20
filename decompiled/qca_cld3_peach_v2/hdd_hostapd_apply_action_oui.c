__int64 __fastcall hdd_hostapd_apply_action_oui(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  unsigned int v4; // w22
  __int64 *v5; // x21
  int v8; // w8
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD v18[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a3 + 80);
  v19 = 0;
  v20 = 0;
  v18[0] = 0;
  v18[1] = 0;
  if ( !v3 )
  {
    v4 = *(_DWORD *)(a3 + 36);
    v5 = (__int64 *)result;
    if ( wlan_reg_is_24ghz_ch_freq(v4) )
    {
      BYTE6(v20) = 1;
    }
    else
    {
      result = wlan_reg_is_5ghz_ch_freq(v4);
      if ( (result & 1) == 0 )
        goto LABEL_2;
      HIBYTE(v20) = 1;
    }
    v8 = *(_DWORD *)(a3 + 84);
    if ( *(_BYTE *)(a3 + 164) && v8 == 2 )
    {
      BYTE5(v20) = 1;
    }
    else if ( *(_BYTE *)(a3 + 104) && v8 == 1 )
    {
      BYTE4(v20) = 1;
    }
    v9 = *v5;
    v19 = a3;
    result = ucfg_action_oui_search(v9, v18, 6);
    if ( (result & 1) != 0 )
    {
      result = sme_set_peer_param(v19, 29, 1, *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL));
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Failed to disable aggregation for peer",
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   "hdd_hostapd_apply_action_oui");
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
