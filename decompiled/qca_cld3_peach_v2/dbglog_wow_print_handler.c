__int64 __fastcall dbglog_wow_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        __int16 a5,
        unsigned __int8 *a6)
{
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x4
  unsigned int v9; // w9
  __int64 v10; // x6
  __int64 v11; // x7
  int v12; // w10
  int v13; // w11
  int v14; // w12
  int v15; // w13
  int v16; // w14
  int v17; // w15
  int v18; // w16
  int v19; // w17
  int v20; // w0
  int v21; // w2
  int v22; // w5
  const char *v23; // x2
  int v24; // w16
  int v25; // w2
  int v26; // [xsp+30h] [xbp-30h]
  int v27; // [xsp+38h] [xbp-28h]
  int v28; // [xsp+40h] [xbp-20h]
  int v29; // [xsp+48h] [xbp-18h]
  int v30; // [xsp+50h] [xbp-10h]

  result = 0;
  if ( a3 <= 16 )
  {
    if ( a3 == 14 )
    {
      if ( a5 == 4 )
      {
        v7 = *a6;
        v8 = a6[1];
        v9 = a6[2];
        v10 = a6[3];
        v11 = a6[4];
        v12 = a6[5];
        v13 = a6[6];
        v14 = a6[7];
        v15 = a6[8];
        v16 = a6[9];
        v17 = a6[10];
        v29 = a6[14];
        v23 = "Enable NS offload, for sender %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x";
        v28 = a6[13];
        v30 = a6[15];
        v27 = a6[12];
        v26 = a6[11];
LABEL_20:
        dbglog_printf(a4, a2, v23, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v26, v27, v28, v29, v30);
        return 1;
      }
      return 0;
    }
    if ( a3 == 15 )
    {
      if ( a5 == 1 )
      {
        dbglog_printf(a4, a2, "Enable ARP offload, for sender %d.%d.%d.%d", *a6, a6[1], a6[2], a6[3]);
        return 1;
      }
      return 0;
    }
    if ( a3 != 16 )
      return result;
    if ( a5 )
      return 0;
    dbglog_printf(a4, a2, "disable NS/ARP offload");
    return 1;
  }
  if ( a3 > 18 )
  {
    if ( a3 == 19 )
    {
      if ( a5 == 1 )
      {
        dbglog_printf(a4, a2, "ARP requested from %d.%d.%d.%d", *a6, a6[1], a6[2], a6[3]);
        return 1;
      }
      return 0;
    }
    if ( a3 != 20 )
      return result;
    if ( a5 != 1 )
      return 0;
    dbglog_printf(a4, a2, "ARP replied to %d.%d.%d.%d", *a6, a6[1], a6[2], a6[3]);
    return 1;
  }
  if ( a3 == 17 )
  {
    if ( a5 == 4 )
    {
      v7 = *a6;
      v8 = a6[1];
      v9 = a6[2];
      v10 = a6[3];
      v11 = a6[4];
      v12 = a6[5];
      v13 = a6[6];
      v14 = a6[7];
      v15 = a6[8];
      v16 = a6[9];
      v17 = a6[10];
      v24 = a6[11];
      v19 = a6[12];
      v20 = a6[13];
      v25 = a6[14];
      v22 = a6[15];
      v26 = v24;
      v29 = v25;
      v23 = "NS requested from %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x";
      goto LABEL_19;
    }
  }
  else if ( a5 == 4 )
  {
    v7 = *a6;
    v8 = a6[1];
    v9 = a6[2];
    v10 = a6[3];
    v11 = a6[4];
    v12 = a6[5];
    v13 = a6[6];
    v14 = a6[7];
    v15 = a6[8];
    v16 = a6[9];
    v17 = a6[10];
    v18 = a6[11];
    v19 = a6[12];
    v20 = a6[13];
    v21 = a6[14];
    v22 = a6[15];
    v26 = v18;
    v29 = v21;
    v23 = "NS replied to %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x";
LABEL_19:
    v30 = v22;
    v28 = v20;
    v27 = v19;
    goto LABEL_20;
  }
  return 0;
}
