bool __fastcall cm_is_bssid_present_on_any_assoc_link(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  bool v22; // zf
  bool v23; // zf
  int v24; // w10
  int v25; // w8
  _BOOL8 result; // x0
  int v29; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v30; // [xsp+4h] [xbp-Ch]
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 1360);
  v30 = 0;
  v29 = 0;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0
    && v12
    && (v21 = *(_QWORD *)(v12 + 3880)) != 0 )
  {
    if ( *(unsigned __int8 *)(v21 + 6) == 255
      || (*(_DWORD *)a2 == *(_DWORD *)(v21 + 24)
        ? (v22 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v21 + 28))
        : (v22 = 0),
          !v22) )
    {
      if ( *(unsigned __int8 *)(v21 + 54) == 255
        || (*(_DWORD *)a2 == *(_DWORD *)(v21 + 72)
          ? (v23 = *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v21 + 76))
          : (v23 = 0),
            !v23) )
      {
        if ( *(unsigned __int8 *)(v21 + 102) == 255 )
          goto LABEL_22;
        v24 = *(_DWORD *)(v21 + 120);
        v25 = *(unsigned __int16 *)(v21 + 124);
        if ( *(_DWORD *)a2 != v24 || *(unsigned __int16 *)(a2 + 4) != v25 )
          goto LABEL_22;
      }
    }
    result = 1;
  }
  else
  {
    if ( (unsigned int)wlan_vdev_get_bss_peer_mac(a1, &v29, v13, v14, v15, v16, v17, v18, v19, v20) )
    {
LABEL_22:
      result = 0;
      goto LABEL_29;
    }
    result = *(_DWORD *)a2 == v29 && *(unsigned __int16 *)(a2 + 4) == v30;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
