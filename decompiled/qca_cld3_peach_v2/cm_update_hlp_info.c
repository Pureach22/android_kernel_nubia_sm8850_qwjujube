__int64 __fastcall cm_update_hlp_info(
        __int64 a1,
        const void *a2,
        unsigned __int16 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  unsigned int v25; // w4
  const char *v26; // x2
  unsigned int v27; // w1

  result = wlan_vdev_mlme_get_ext_hdl(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v24 = result;
    if ( (a4 & 1) != 0 )
    {
      result = *(_QWORD *)(result + 24064);
      *(_DWORD *)(v24 + 24072) = 0;
      if ( result )
      {
        result = _qdf_mem_free(result);
        *(_QWORD *)(v24 + 24064) = 0;
      }
    }
    if ( a2 && a3 )
    {
      v25 = *(_DWORD *)(v24 + 24072);
      if ( v25 + a3 < 0x801 )
      {
        result = *(_QWORD *)(v24 + 24064);
        if ( !result )
        {
          result = _qdf_mem_malloc(0x800u, "cm_update_hlp_info", 82);
          *(_QWORD *)(v24 + 24064) = result;
          if ( !result )
            return result;
          v25 = *(_DWORD *)(v24 + 24072);
        }
        qdf_mem_copy((void *)(result + v25), a2, a3);
        v26 = "%s: hlp_ie_len %d len %d";
        v27 = 8;
        *(_DWORD *)(v24 + 24072) += a3;
      }
      else
      {
        v26 = "%s: HLP len exceeds: hlp_ie_len %d len %d";
        v27 = 2;
      }
      return qdf_trace_msg(0x68u, v27, v26, v16, v17, v18, v19, v20, v21, v22, v23, "cm_update_hlp_info");
    }
  }
  return result;
}
