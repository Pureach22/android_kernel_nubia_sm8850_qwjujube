__int64 __fastcall wlan_hdd_set_listen_interval(__int64 *a1, __int64 a2)
{
  __int64 v4; // x19
  unsigned __int8 sta_mlo_simultaneous_links; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  unsigned __int8 v15; // w19
  __int64 result; // x0
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v17 = 0;
  wlan_mlme_get_eht_mode(v4, &v17);
  sta_mlo_simultaneous_links = wlan_mlme_get_sta_mlo_simultaneous_links(v4);
  v14 = v17;
  v15 = sta_mlo_simultaneous_links;
  if ( v17 == 2 && !sta_mlo_simultaneous_links )
  {
    sme_set_listen_interval(a1[2], *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL));
    v14 = v17;
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: EHT mode: %d, max simultaneous link num: %d",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_hdd_set_listen_interval",
             v14,
             v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
