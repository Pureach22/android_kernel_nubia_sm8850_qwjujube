__int64 __fastcall cm_is_roam_enabled(__int64 a1)
{
  char v2; // w0
  __int64 v3; // x21
  char v4; // w22
  char v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v2 = cm_roam_offload_enabled(a1);
  if ( (v2 & 1) == 0 )
  {
    v3 = jiffies;
    if ( cm_is_roam_enabled___last_ticks - jiffies + 125 < 0 )
    {
      v4 = v2;
      v5 = cm_roam_offload_enabled(a1);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: All roam mode (offload %d, host %d) are disabled",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "cm_is_roam_enabled",
        v5 & 1,
        0);
      v2 = v4;
      cm_is_roam_enabled___last_ticks = v3;
    }
  }
  return v2 & 1;
}
