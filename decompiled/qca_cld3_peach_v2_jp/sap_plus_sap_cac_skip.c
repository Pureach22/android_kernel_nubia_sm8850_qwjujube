__int64 __fastcall sap_plus_sap_cac_skip(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v13; // x22
  _DWORD *v14; // x24
  char v15; // w26
  const char *v16; // x2
  bool v17; // cf
  __int64 v18; // x27
  __int64 v19; // x0
  __int64 active_channel; // x0

  v13 = 0;
  v14 = (_DWORD *)(a1 + 14824);
  v15 = 1;
  while ( 1 )
  {
    v18 = *((_QWORD *)v14 - 1);
    if ( v18 )
    {
      if ( (*v14 | 2) == 3 && *(_BYTE *)(v18 + 1553) == 1 && *(_DWORD *)v18 == a3 )
        break;
    }
LABEL_4:
    v17 = v13++ >= 5;
    v14 += 4;
    v15 = !v17;
    if ( v13 == 6 )
      return v15 & 1;
  }
  v19 = *(_QWORD *)(v18 + 16);
  if ( !v19 )
  {
    v16 = "%s: vdev invalid";
LABEL_3:
    qdf_trace_msg(0x39u, 8u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "sap_operating_on_dfs");
    goto LABEL_4;
  }
  active_channel = wlan_vdev_get_active_channel(v19);
  if ( !active_channel )
  {
    v16 = "%s: Couldn't get vdev active channel";
    goto LABEL_3;
  }
  if ( (*(_WORD *)(active_channel + 6) & 6) == 0 )
    goto LABEL_4;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: SAP vid %d CAC can skip due to CAC completed on SAP vid %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sap_plus_sap_cac_skip",
    *(unsigned __int8 *)(a2 + 12),
    *(unsigned __int8 *)(v18 + 12));
  return v15 & 1;
}
