__int64 __fastcall is_dp_link_valid(
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
  __int64 v11; // x8
  __int64 v12; // x20
  const char *v14; // x2
  const char *v15; // x3
  unsigned int v16; // w4

  if ( !a1 )
  {
    v14 = "%s: link is NULL";
    v15 = "is_dp_link_valid";
LABEL_13:
    qdf_trace_msg(0x45u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, v15);
    return 0;
  }
  if ( *(_QWORD *)(a1 + 16) != 0x5F44505F4C494E4BLL )
  {
    qdf_trace_msg(0x45u, 2u, "%s: dp_link %pK bad magic %llx", a2, a3, a4, a5, a6, a7, a8, a9, "is_dp_link_valid", a1);
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 32);
  if ( !v10 )
  {
    v14 = "%s: Interface is NULL";
LABEL_12:
    v15 = "is_dp_intf_valid";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)(v10 + 56);
  if ( !v11 )
  {
    v14 = "%s: DP interface net_device is null";
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(v11 + 176) & 1) != 0 )
  {
    v16 = *(unsigned __int8 *)(a1 + 24);
    if ( v16 == 255 )
    {
      qdf_trace_msg(0x45u, 2u, "%s: Interface is not up: %ps", a2, a3, a4, a5, a6, a7, a8, a9, "validate_link_id", v9);
    }
    else
    {
      if ( v16 < 6 )
        return 1;
      qdf_trace_msg(0x45u, 2u, "%s: Bad interface id:%u", a2, a3, a4, a5, a6, a7, a8, a9, "validate_link_id");
    }
  }
  else
  {
    v12 = jiffies;
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
        v11 + 296,
        v9);
      is_dp_intf_valid___last_ticks = v12;
      return 0;
    }
  }
  return 0;
}
