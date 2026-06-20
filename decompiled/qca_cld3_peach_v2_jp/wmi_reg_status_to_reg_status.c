__int64 __fastcall wmi_reg_status_to_reg_status(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 > 2 )
  {
    if ( a1 == 3 )
    {
      qdf_trace_msg(0x31u, 8u, "WMI_REG_SET_CC_CHANGE_NOT_ALLOWED", a2, a3, a4, a5, a6, a7, a8, a9);
      return 3;
    }
    if ( a1 != 4 )
    {
      if ( a1 == 5 )
      {
        qdf_trace_msg(0x31u, 8u, "WMI_REG_SET_CC_STATUS_FAIL", a2, a3, a4, a5, a6, a7, a8, a9);
        return 5;
      }
LABEL_12:
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Unknown reg status code from WMI",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wmi_reg_status_to_reg_status");
      return 5;
    }
    qdf_trace_msg(0x31u, 8u, "WMI_REG_SET_CC_STATUS_NO_MEMORY", a2, a3, a4, a5, a6, a7, a8, a9);
    return 4;
  }
  else
  {
    if ( !a1 )
    {
      qdf_trace_msg(0x31u, 8u, "REG_SET_CC_STATUS_PASS", a2, a3, a4, a5, a6, a7, a8, a9);
      return 0;
    }
    if ( a1 != 1 )
    {
      if ( a1 == 2 )
      {
        qdf_trace_msg(0x31u, 8u, "WMI_REG_INIT_ALPHA2_NOT_FOUND", a2, a3, a4, a5, a6, a7, a8, a9);
        return 2;
      }
      goto LABEL_12;
    }
    qdf_trace_msg(0x31u, 8u, "WMI_REG_CURRENT_ALPHA2_NOT_FOUND", a2, a3, a4, a5, a6, a7, a8, a9);
    return 1;
  }
}
