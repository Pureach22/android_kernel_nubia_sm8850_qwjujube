__int64 __fastcall cam_bps_cpas_cb(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int *v3; // x19
  int v4; // w0
  __int64 v5; // x6
  __int64 v6; // x7
  const char *v7; // x5
  __int64 v8; // x0
  __int64 v9; // x4
  int v10; // w0
  int v12; // [xsp+0h] [xbp-20h]
  unsigned int v13; // [xsp+8h] [xbp-18h]
  unsigned int v14; // [xsp+10h] [xbp-10h]
  unsigned int v15; // [xsp+18h] [xbp-8h]

  v3 = a3;
  if ( a3 )
  {
    if ( *a3 == 14 )
    {
      v10 = __ratelimit(&cam_bps_cpas_cb__rs_8, "cam_bps_cpas_cb");
      v5 = *v3;
      v6 = v3[1];
      v7 = "IPE/BPS UBWC Encode error type=%d status=%x";
      if ( v10 )
        v8 = 3;
      else
        v8 = 2;
      v9 = 69;
    }
    else
    {
      if ( *a3 != 13 )
      {
        LODWORD(v3) = 0;
        return (unsigned int)v3;
      }
      v4 = __ratelimit(&cam_bps_cpas_cb__rs, "cam_bps_cpas_cb");
      v5 = *v3;
      v6 = v3[1];
      v7 = "IPE/BPS UBWC Decode error type=%d status=%x thr_err=%d, fcl_err=%d, len_md_err=%d, format_err=%d";
      if ( v4 )
        v8 = 3;
      else
        v8 = 2;
      v15 = ((unsigned int)v6 >> 3) & 1;
      v9 = 62;
      v14 = ((unsigned int)v6 >> 2) & 1;
      v13 = ((unsigned int)v6 >> 1) & 1;
      v12 = v3[1] & 1;
    }
    LODWORD(v3) = 1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int, unsigned int, unsigned int))cam_print_log)(
      v8,
      256,
      1,
      "cam_bps_cpas_cb",
      v9,
      v7,
      v5,
      v6,
      v12,
      v13,
      v14,
      v15);
  }
  return (unsigned int)v3;
}
