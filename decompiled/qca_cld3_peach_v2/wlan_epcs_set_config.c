__int64 __fastcall wlan_epcs_set_config(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  __int64 v13; // x8
  bool v14; // zf
  __int64 v15; // x20
  __int64 v16; // x0
  char v17; // w1

  context = _cds_get_context(53, (__int64)"wlan_epcs_set_config", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 4;
  if ( !a1 )
    return 16;
  v13 = *(_QWORD *)(a1 + 216);
  v14 = a2 == 0;
  v15 = (__int64)context;
  if ( v14 )
  {
    if ( v13 )
      v16 = *(_QWORD *)(v13 + 80);
    else
      v16 = 0;
    v17 = 0;
  }
  else
  {
    if ( v13 )
      v16 = *(_QWORD *)(v13 + 80);
    else
      v16 = 0;
    v17 = 1;
  }
  wlan_mlme_set_epcs_capability(v16, v17);
  return lim_send_eht_caps_ie(v15, 0, *(unsigned __int8 *)(a1 + 168));
}
