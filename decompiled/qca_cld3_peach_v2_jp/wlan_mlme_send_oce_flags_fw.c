void __fastcall wlan_mlme_send_oce_flags_fw(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  _BYTE *dynamic_oce_flags; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 v27; // [xsp+8h] [xbp-18h]

  if ( !*(_DWORD *)(a10 + 16) )
  {
    v27 = v12;
    dynamic_oce_flags = (_BYTE *)mlme_get_dynamic_oce_flags(a10, a1, a2, a3, a4, a5, a6, a7, a8);
    if ( dynamic_oce_flags )
    {
      v24 = *a11;
      if ( v24 == (unsigned __int8)*dynamic_oce_flags )
      {
        v25 = "%s: Current FW flags matches with updated value.";
        v26 = 8;
      }
      else
      {
        *dynamic_oce_flags = v24;
        if ( !(unsigned int)wma_cli_set_command(*(unsigned __int8 *)(a10 + 104), 120, *a11, 1) )
          return;
        v25 = "%s: Failed to send OCE update to FW";
        v26 = 2;
      }
      qdf_trace_msg(0x1Fu, v26, v25, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_mlme_send_oce_flags_fw", v11, v27);
    }
  }
}
