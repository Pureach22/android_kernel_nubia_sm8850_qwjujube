__int64 __fastcall service_coresight_qmi_del_server(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w2

  v1 = *(_QWORD *)(a1 - 64);
  v2 = *(_DWORD *)(a1 + 304);
  *(_BYTE *)(a1 + 308) = 0;
  return dev_info(v1, "Connection disconnected between QMI handle and %d service\n", v2);
}
