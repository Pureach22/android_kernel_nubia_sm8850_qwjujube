__int64 __fastcall mlo_mgr_osif_update_connect_info(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  _QWORD *v14; // x9
  unsigned __int8 *v15; // x20
  __int64 v16; // x22
  _DWORD *v17; // x8

  result = wlan_objmgr_get_mlo_ctx();
  if ( !result )
    return result;
  v13 = *(_QWORD *)(a1 + 1360);
  if ( !v13 )
    return result;
  v14 = *(_QWORD **)(result + 360);
  if ( !v14 || a2 > 0xE || !*v14 )
    return result;
  v15 = *(unsigned __int8 **)(v13 + 3880);
  if ( v15[6] != a2 )
  {
    if ( v15[54] != a2 )
    {
      if ( v15[102] != a2 )
        return result;
      v15 += 96;
      if ( !v15 )
        return result;
      goto LABEL_10;
    }
    v15 += 48;
  }
  if ( !v15 )
    return result;
LABEL_10:
  v16 = result;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Vdev %d: link id %d freq %d self MAC %02x:%02x:%02x:**:**:%02x BSSID %02x:%02x:%02x:**:**:%02x",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "mlo_mgr_osif_update_connect_info",
    v15[12],
    a2,
    *((unsigned __int16 *)v15 + 5),
    *v15,
    v15[1],
    v15[2],
    v15[5],
    v15[24],
    v15[25],
    v15[26],
    v15[29]);
  v17 = **(_DWORD ***)(v16 + 360);
  if ( *(v17 - 1) != 363531959 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(unsigned __int8 *, unsigned __int8 *, _QWORD))v17)(v15, v15 + 24, a2);
}
