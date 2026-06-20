__int64 __fastcall dp_parser_fec(_BYTE *a1)
{
  __int64 property; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0

  property = of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,fec-feature-enable", 0);
  a1[727] = property != 0;
  ipc_log_context = get_ipc_log_context(property);
  StatusReg = _ReadStatusReg(SP_EL0);
  result = ipc_log_string(
             ipc_log_context,
             "[d][%-4d]fec parsing successful. fec:%d\n",
             *(_DWORD *)(StatusReg + 1800),
             (unsigned __int8)a1[727]);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]fec parsing successful. fec:%d\n",
             *(_DWORD *)(StatusReg + 1800),
             (unsigned __int8)a1[727]);
  return result;
}
