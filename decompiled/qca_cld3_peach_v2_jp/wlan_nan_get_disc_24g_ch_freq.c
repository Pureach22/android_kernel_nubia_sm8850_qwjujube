__int64 __fastcall wlan_nan_get_disc_24g_ch_freq(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x0
  const char *v22; // x2
  const char *v23; // x3

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_7;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_7:
    v22 = "%s: psoc_nan_obj is null";
    v23 = "wlan_nan_get_disc_24g_ch_freq";
LABEL_8:
    qdf_trace_msg(0x53u, 2u, v22, v11, v12, v13, v14, v15, v16, v17, v18, v23);
    return 0;
  }
  v19 = comp_private_obj;
  v20 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !v20 )
  {
    v22 = "%s: nan psoc priv object is NULL";
    v23 = "nan_get_discovery_state";
    goto LABEL_8;
  }
  if ( *(_DWORD *)(v20 + 272) == 2 )
    return *(unsigned int *)(v19 + 276);
  return 0;
}
