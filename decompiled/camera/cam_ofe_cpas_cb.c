__int64 __fastcall cam_ofe_cpas_cb(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int *v3; // x19
  int v4; // w0
  __int64 v5; // x6
  __int64 v6; // x7
  const char *v7; // x5
  __int64 v8; // x0
  unsigned int v9; // w9
  unsigned int v10; // w10
  int v11; // w8
  __int64 v12; // x4
  int v13; // w0
  unsigned int v15; // [xsp+18h] [xbp-8h]

  v3 = a3;
  if ( a3 )
  {
    if ( *a3 == 16 )
    {
      v13 = __ratelimit(&cam_ofe_cpas_cb__rs_8, "cam_ofe_cpas_cb");
      v5 = *v3;
      v6 = v3[1];
      v7 = "OFE Read UBWC Decode error type=%d status=%x thr_err=%d, fcl_err=%d, len_md_err=%d, format_err=%d";
      if ( v13 )
        v8 = 3;
      else
        v8 = 2;
      v9 = ((unsigned int)v6 >> 1) & 1;
      v10 = ((unsigned int)v6 >> 2) & 1;
      v11 = v3[1] & 1;
      v12 = 61;
      v15 = ((unsigned int)v6 >> 3) & 1;
    }
    else
    {
      if ( *a3 != 15 )
      {
        LODWORD(v3) = 0;
        return (unsigned int)v3;
      }
      v4 = __ratelimit(&cam_ofe_cpas_cb__rs, "cam_ofe_cpas_cb");
      v5 = *v3;
      v6 = v3[1];
      v7 = "OFE Write UBWC Decode error type=%d status=%x thr_err=%d, fcl_err=%d, len_md_err=%d, format_err=%d";
      if ( v4 )
        v8 = 3;
      else
        v8 = 2;
      v9 = ((unsigned int)v6 >> 1) & 1;
      v10 = ((unsigned int)v6 >> 2) & 1;
      v11 = v3[1] & 1;
      v15 = ((unsigned int)v6 >> 3) & 1;
      v12 = 50;
    }
    LODWORD(v3) = 1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int, unsigned int, unsigned int))cam_print_log)(
      v8,
      256,
      1,
      "cam_ofe_cpas_cb",
      v12,
      v7,
      v5,
      v6,
      v11,
      v9,
      v10,
      v15);
  }
  return (unsigned int)v3;
}
