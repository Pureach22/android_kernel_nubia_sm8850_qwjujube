__int64 __fastcall dp_parser_qos(__int64 *a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x9
  __int64 ipc_log_context; // x0
  int v6; // w3
  int v7; // w4
  unsigned __int64 StatusReg; // x19
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v9[0] = 0;
  result = of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,qos-cpu-latency-us", v9, 1, 0);
  if ( (result & 0x80000000) == 0 )
  {
    result = of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,qos-cpu-mask", (char *)v9 + 4, 1, 0);
    if ( (result & 0x80000000) == 0 )
    {
      v4 = LODWORD(v9[0]);
      *((_DWORD *)a1 + 188) = HIDWORD(v9[0]);
      a1[95] = v4;
      ipc_log_context = get_ipc_log_context(result);
      v7 = v9[0];
      v6 = HIDWORD(v9[0]);
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(
                 ipc_log_context,
                 "[d][%-4d]qos parsing successful. mask:%x latency:%u\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v6,
                 v7);
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]qos parsing successful. mask:%x latency:%u\n",
                   *(_DWORD *)(StatusReg + 1800),
                   HIDWORD(v9[0]),
                   LODWORD(v9[0]));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
