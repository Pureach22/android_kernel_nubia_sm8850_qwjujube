__int64 __fastcall lim_cm_roam_create_session(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w19
  __int64 v6; // x0
  char is_mlo_link; // w21
  int sta_link_mac_addr; // w8
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _BYTE v18[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v19; // [xsp+10h] [xbp-10h] BYREF
  __int16 v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v5 = a2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 21624);
  v20 = 0;
  v19 = 0;
  v18[0] = 0;
  is_mlo_link = wlan_vdev_mlme_get_is_mlo_link(v6, a2);
  sta_link_mac_addr = mlo_get_sta_link_mac_addr(v5, a3, &v19);
  result = 0;
  if ( !sta_link_mac_addr && (is_mlo_link & 1) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, int *, _BYTE *, _QWORD, _QWORD, _QWORD))pe_create_session)(
               a1,
               &v19,
               v18,
               *(unsigned __int8 *)(a1 + 12272),
               0,
               v5);
    if ( !result )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev_id %d : pe session create failed BSSID%02x:%02x:%02x:**:**:%02x",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "lim_cm_roam_create_session",
        (unsigned __int8)v5,
        (unsigned __int8)v19,
        BYTE1(v19),
        BYTE2(v19),
        HIBYTE(v20));
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
