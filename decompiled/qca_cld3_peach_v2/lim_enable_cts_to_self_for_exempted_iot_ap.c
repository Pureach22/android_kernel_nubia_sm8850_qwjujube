__int64 __fastcall lim_enable_cts_to_self_for_exempted_iot_ap(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 a4)
{
  __int64 v5; // x0
  char v6; // w20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v16; // [xsp+8h] [xbp-28h] BYREF
  int v17; // [xsp+10h] [xbp-20h]
  int v18; // [xsp+14h] [xbp-1Ch]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 21624);
  v16 = a3;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v17 = a4;
  v6 = wlan_action_oui_search(v5, &v16, 23);
  if ( (v6 & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev %d: enable cts to self",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "lim_enable_cts_to_self_for_exempted_iot_ap",
      *(unsigned __int8 *)(a2 + 10));
    wma_cli_set_command(*(unsigned __int8 *)(a2 + 10), 44, 34, 1);
  }
  _ReadStatusReg(SP_EL0);
  return v6 & 1;
}
