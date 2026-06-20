__int64 __fastcall qmi_psoc_obj_create_notification(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  v2 = (_QWORD *)_qdf_mem_malloc(0x38u, "qmi_psoc_obj_create_notification", 33);
  if ( !v2 )
    return 2;
  v3 = (__int64)v2;
  *v2 = a1;
  result = wlan_objmgr_psoc_component_obj_attach(a1, 0x31u, (__int64)v2, 0);
  if ( (_DWORD)result )
  {
    v13 = result;
    qdf_trace_msg(
      0x9Du,
      2u,
      "%s: Failed to attach psoc QMI component obj",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "qmi_psoc_obj_create_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  return result;
}
