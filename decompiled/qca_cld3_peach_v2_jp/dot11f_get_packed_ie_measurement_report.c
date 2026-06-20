__int64 __fastcall dot11f_get_packed_ie_measurement_report(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  unsigned int v4; // w3
  unsigned int v5; // w9
  unsigned int v6; // w9
  int v7; // w9
  int v8; // w8
  unsigned int *v9; // x3

  if ( !*a2 )
    return 0;
  v3 = *a3;
  v4 = 0;
  *a3 += 3;
  v5 = (unsigned __int8)a2[3];
  if ( v5 <= 2 )
  {
    if ( v5 == 1 )
    {
      v8 = v3 + 15;
    }
    else
    {
      if ( v5 != 2 )
        return v4;
      v8 = v3 + 22;
    }
    v4 = 0;
    *a3 = v8;
    return v4;
  }
  switch ( v5 )
  {
    case 3u:
      v9 = (unsigned int *)&IES_reportchannel_load_report;
      *a3 = v3 + 16;
      return (unsigned int)get_packed_size_core(a1, (__int64)a2, a3, v9);
    case 5u:
      v9 = (unsigned int *)&IES_reportBeacon;
      *a3 = v3 + 29;
      return (unsigned int)get_packed_size_core(a1, (__int64)a2, a3, v9);
    case 7u:
      *a3 = v3 + 6;
      v6 = (unsigned __int8)a2[6];
      if ( v6 > 1 )
      {
        if ( v6 == 2 )
        {
          v7 = 58;
          goto LABEL_23;
        }
        if ( v6 == 10 )
        {
          v7 = 14;
          goto LABEL_23;
        }
      }
      else
      {
        if ( !a2[6] )
        {
          v7 = 34;
          goto LABEL_23;
        }
        if ( v6 == 1 )
        {
          v7 = 30;
LABEL_23:
          *a3 = v3 + v7;
        }
      }
      v9 = (unsigned int *)&IES_reportsta_stats;
      return (unsigned int)get_packed_size_core(a1, (__int64)a2, a3, v9);
  }
  return v4;
}
