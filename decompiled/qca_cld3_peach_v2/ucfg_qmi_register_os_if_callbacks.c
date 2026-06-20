_QWORD *__fastcall ucfg_qmi_register_os_if_callbacks(__int64 a1, _QWORD *a2)
{
  _QWORD *result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x31u);
  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x9Du,
                       2u,
                       "%s: QMI context is NULL",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       "ucfg_qmi_register_os_if_callbacks");
  result[1] = *a2;
  result[2] = a2[1];
  result[3] = a2[2];
  result[4] = a2[3];
  result[5] = a2[4];
  result[6] = a2[5];
  return result;
}
