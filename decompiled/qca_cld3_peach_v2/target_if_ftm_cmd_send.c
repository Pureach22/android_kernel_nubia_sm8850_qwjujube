__int64 __fastcall target_if_ftm_cmd_send(
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
  __int64 *v9; // x8
  __int64 result; // x0
  const char *v11; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v11 = "%s: null pdev";
    goto LABEL_7;
  }
  v9 = *(__int64 **)(a1 + 1240);
  if ( !v9 || !*v9 )
  {
    v11 = "%s: null handle";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ftm_cmd_send");
    result = 16;
    goto LABEL_8;
  }
  result = wmi_unified_pdev_utf_cmd_send(*v9);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
