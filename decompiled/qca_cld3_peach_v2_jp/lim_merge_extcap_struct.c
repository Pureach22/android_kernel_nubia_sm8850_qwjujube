__int64 __fastcall lim_merge_extcap_struct(
        __int64 result,
        _BYTE *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _BYTE *v13; // x19
  _BYTE *v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _BYTE *v23; // x11
  _BYTE *v24; // x8
  char v25; // w9
  _BYTE *v26; // x10
  char v27; // w11
  char v28; // w12
  char v29; // w13
  char v30; // w11
  int v31; // w8

  if ( *a2 )
  {
    v13 = (_BYTE *)result;
    v14 = a2 + 2;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: source extended capabilities length:%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_merge_extcap_struct",
      (unsigned __int8)a2[1]);
    result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(
               53,
               8,
               v14,
               (unsigned __int8)a2[1]);
    if ( *v13 || (a3 & 1) != 0 )
    {
      if ( v13 != (_BYTE *)-2LL && v14 )
      {
        v23 = a2 + 3;
        v24 = v13 + 3;
        v25 = 15;
        do
        {
          if ( !v25 )
            break;
          v26 = v23;
          v27 = *(v23 - 1);
          v28 = *(v24 - 1);
          v29 = v28 & v27;
          v30 = v28 | v27;
          if ( (a3 & 1) == 0 )
            v30 = v29;
          *(v24 - 1) = v30;
          if ( !v24 )
            break;
          --v25;
          v23 = v26 + 1;
          ++v24;
        }
        while ( v26 );
      }
      if ( v13[16] )
      {
        v13[1] = 15;
      }
      else if ( v13[15] )
      {
        v13[1] = 14;
      }
      else if ( v13[14] )
      {
        v13[1] = 13;
      }
      else if ( v13[13] )
      {
        v13[1] = 12;
      }
      else if ( v13[12] )
      {
        v13[1] = 11;
      }
      else if ( v13[11] )
      {
        v13[1] = 10;
      }
      else if ( v13[10] )
      {
        v13[1] = 9;
      }
      else if ( v13[9] )
      {
        v13[1] = 8;
      }
      else if ( v13[8] )
      {
        v13[1] = 7;
      }
      else if ( v13[7] )
      {
        v13[1] = 6;
      }
      else if ( v13[6] )
      {
        v13[1] = 5;
      }
      else if ( v13[5] )
      {
        v13[1] = 4;
      }
      else if ( v13[4] )
      {
        v13[1] = 3;
      }
      else if ( v13[3] )
      {
        v13[1] = 2;
      }
      else
      {
        v31 = (unsigned __int8)v13[2];
        v13[1] = v13[2] != 0;
        if ( !v31 )
        {
          *v13 = 0;
          return result;
        }
      }
      *v13 = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: destination extended capabilities length: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_merge_extcap_struct");
      return ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(
               53,
               8,
               v13 + 2,
               (unsigned __int8)v13[1]);
    }
  }
  return result;
}
