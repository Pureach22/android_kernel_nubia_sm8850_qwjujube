__int64 __fastcall wlan_hdd_trim_acs_channel_list(
        unsigned int *a1,
        unsigned __int8 a2,
        __int64 a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v18; // w12
  unsigned __int64 v19; // x10
  unsigned __int16 v20; // w9
  __int64 v21; // x12
  int v22; // w15
  __int64 v23; // x16
  unsigned int *v24; // x17
  unsigned int v25; // t1

  if ( (unsigned __int8)*a4 >= 0x66u )
  {
    v12 = "%s: org_ch_list_count too big %d";
    return qdf_trace_msg(0x33u, 2u, v12, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_trim_acs_channel_list");
  }
  if ( a2 >= 0x66u )
  {
    v12 = "%s: pcl_count is too big %d";
    return qdf_trace_msg(0x33u, 2u, v12, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_trim_acs_channel_list");
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: Update ACS chan freq with PCL",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "wlan_hdd_trim_acs_channel_list");
  v18 = (unsigned __int8)*a4;
  if ( *a4 )
  {
    v19 = 0;
    v20 = 0;
    do
    {
      if ( a2 )
      {
        v22 = *(_DWORD *)(a3 + 4 * v19);
        v23 = a2;
        v24 = a1;
        while ( 1 )
        {
          v25 = *v24++;
          result = v25;
          if ( v25 == v22 )
            break;
          if ( !--v23 )
            goto LABEL_9;
        }
        v21 = v20++;
        *(_DWORD *)(a3 + 4 * v21) = v22;
        v18 = (unsigned __int8)*a4;
      }
LABEL_9:
      ++v19;
    }
    while ( v19 < v18 );
  }
  else
  {
    LOBYTE(v20) = 0;
  }
  *a4 = v20;
  return result;
}
