__int64 __fastcall dp_parser_mst(__int64 *a1)
{
  __int64 v1; // x21
  __int64 property; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0

  v1 = *a1;
  property = of_find_property(*(_QWORD *)(*a1 + 760), "qcom,mst-enable", 0);
  *((_BYTE *)a1 + 724) = property != 0;
  *((_BYTE *)a1 + 725) = property != 0;
  ipc_log_context = get_ipc_log_context(property);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]mst parsing successful. mst:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    *((unsigned __int8 *)a1 + 724));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst parsing successful. mst:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *((unsigned __int8 *)a1 + 724));
  of_property_read_u32_index(*(_QWORD *)(v1 + 760), "qcom,mst-fixed-topology-ports", 0, a1 + 93);
  of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,mst-fixed-topology-display-types", a1 + 97, 1, 0);
  if ( !a1[97] )
    a1[97] = (__int64)"unknown";
  of_property_read_u32_index(*(_QWORD *)(v1 + 760), "qcom,mst-fixed-topology-ports", 1, (char *)a1 + 748);
  result = of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,mst-fixed-topology-display-types", a1 + 98, 1, 1);
  if ( !a1[98] )
    a1[98] = (__int64)"unknown";
  return result;
}
