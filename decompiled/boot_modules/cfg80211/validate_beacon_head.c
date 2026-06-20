__int64 __fastcall validate_beacon_head(_WORD *a1, _QWORD *a2)
{
  unsigned __int16 *v4; // x22
  unsigned int v5; // w8
  __int64 v6; // x0
  unsigned int v7; // w23
  unsigned __int64 v8; // x21
  int v9; // w24
  char *v10; // x8
  char *v11; // x9
  __int64 v12; // x10

  v4 = a1 + 2;
  v5 = (unsigned __int16)(*a1 - 4);
  if ( v5 >= 2 )
  {
    v6 = *v4;
    v7 = (v6 & 0xFC) == 0x1C ? 15 : 36;
    v8 = v5 - v7;
    if ( v5 >= v7 )
    {
      v9 = (v6 & 0xFC) == 0x1C ? 4 : 24;
      if ( (unsigned int)ieee80211_hdrlen(v6) == v9 )
      {
        v10 = (char *)v4 + v7;
        v11 = &v10[v8];
        if ( (unsigned int)v8 >= 2 )
        {
          do
          {
            v12 = (unsigned __int8)v10[1];
            if ( v8 < v12 + 2 )
              break;
            v10 += v12 + 2;
            v8 = v11 - v10;
          }
          while ( v11 - v10 > 1 );
        }
        if ( v11 == v10 )
          return 0;
      }
    }
  }
  do_trace_netlink_extack("malformed beacon head");
  if ( !a2 )
    return 4294967274LL;
  *a2 = "malformed beacon head";
  a2[1] = a1;
  a2[2] = 0;
  return 4294967274LL;
}
