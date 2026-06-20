_QWORD *__fastcall os_if_qmi_register_callbacks(__int64 a1, _QWORD *a2)
{
  os_if_qmi_wfds_register_callbacks(a2);
  return ucfg_qmi_register_os_if_callbacks(a1, a2);
}
