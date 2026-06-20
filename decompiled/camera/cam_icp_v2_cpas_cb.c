__int64 __fastcall cam_icp_v2_cpas_cb(__int64 a1, __int64 a2, _DWORD *a3)
{
  _DWORD *v3; // x19
  int v4; // w0
  __int64 v5; // x6
  __int64 v6; // x0
  const char *v7; // x5
  __int64 v8; // x4
  int v9; // w0

  v3 = a3;
  if ( a3 )
  {
    if ( *a3 == 14 )
    {
      v9 = __ratelimit(&cam_icp_v2_cpas_cb__rs_30, "cam_icp_v2_cpas_cb");
      v5 = (unsigned int)v3[1];
      if ( v9 )
        v6 = 3;
      else
        v6 = 2;
      v7 = "IPE/BPS UBWC encode error status=0x%08x";
      v8 = 140;
    }
    else
    {
      if ( *a3 != 13 )
      {
        LODWORD(v3) = 0;
        return (unsigned int)v3;
      }
      v4 = __ratelimit(&cam_icp_v2_cpas_cb__rs, "cam_icp_v2_cpas_cb");
      v5 = (unsigned int)v3[1];
      if ( v4 )
        v6 = 3;
      else
        v6 = 2;
      v7 = "IPE/BPS UBWC decode error status=0x%08x";
      v8 = 134;
    }
    LODWORD(v3) = 1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      v6,
      256,
      1,
      "cam_icp_v2_cpas_cb",
      v8,
      v7,
      v5);
  }
  return (unsigned int)v3;
}
