__int64 __fastcall dp_parser_dsc(_BYTE *a1)
{
  __int64 v1; // x20
  __int64 property; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)a1;
  a1[726] = of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,dsc-feature-enable", 0) != 0;
  property = of_find_property(*(_QWORD *)(v1 + 760), "qcom,dsc-continuous-pps", 0);
  a1[728] = property != 0;
  ipc_log_context = get_ipc_log_context(property);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = ipc_log_string(
         ipc_log_context,
         "[d][%-4d]dsc parsing successful. dsc:%d\n",
         *(_DWORD *)(StatusReg + 1800),
         (unsigned __int8)a1[726]);
  if ( (_drm_debug & 4) != 0 )
    v6 = _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dp-debug][%-4d]dsc parsing successful. dsc:%d\n",
           *(_DWORD *)(StatusReg + 1800),
           (unsigned __int8)a1[726]);
  v7 = get_ipc_log_context(v6);
  result = ipc_log_string(v7, "[d][%-4d]cont_pps:%d\n", *(_DWORD *)(StatusReg + 1800), (unsigned __int8)a1[728]);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]cont_pps:%d\n",
             *(_DWORD *)(StatusReg + 1800),
             (unsigned __int8)a1[728]);
  return result;
}
