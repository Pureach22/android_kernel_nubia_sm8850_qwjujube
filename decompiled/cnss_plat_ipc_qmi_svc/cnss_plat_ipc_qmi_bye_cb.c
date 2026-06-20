__int64 __fastcall cnss_plat_ipc_qmi_bye_cb(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19

  v2 = a2;
  cnss_plat_ipc_qmi_disconnect_cb(a1, a2, HIDWORD(qword_7DAC));
  return cnss_plat_ipc_qmi_disconnect_cb(a1, v2, HIDWORD(qword_7DD4));
}
