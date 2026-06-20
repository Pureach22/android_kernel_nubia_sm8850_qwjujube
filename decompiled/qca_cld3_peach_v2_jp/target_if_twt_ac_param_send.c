__int64 __fastcall target_if_twt_ac_param_send(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    if ( a2 >= 5 )
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: invalid enum: %u",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_twt_convert_ac_value",
        a2);
    result = wmi_unified_pdev_param_send(v11);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: wmi_handle is null", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_twt_ac_param_send");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
