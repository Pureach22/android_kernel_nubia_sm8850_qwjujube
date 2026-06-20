__int64 __fastcall is_dp_intf_valid(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x30
  __int64 v10; // x8
  __int64 v11; // x20
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: Interface is NULL";
LABEL_9:
    qdf_trace_msg(0x45u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "is_dp_intf_valid");
    return 4294967274LL;
  }
  v10 = *(_QWORD *)(a1 + 56);
  if ( !v10 )
  {
    v13 = "%s: DP interface net_device is null";
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(v10 + 176) & 1) != 0 )
    return 0;
  v11 = jiffies;
  if ( is_dp_intf_valid___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: DP interface '%s' is not up %ps",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "is_dp_intf_valid",
      v10 + 296,
      v9);
    is_dp_intf_valid___last_ticks = v11;
  }
  return 4294967285LL;
}
