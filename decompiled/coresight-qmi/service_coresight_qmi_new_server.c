__int64 __fastcall service_coresight_qmi_new_server(__int64 a1, __int64 a2)
{
  int v2; // w2
  __int64 v3; // x8
  int v4; // w9

  v2 = *(_DWORD *)(a1 + 304);
  *(_WORD *)(a1 + 312) = 42;
  *(_DWORD *)(a1 + 316) = *(_DWORD *)(a2 + 12);
  v3 = *(_QWORD *)(a1 - 64);
  v4 = *(_DWORD *)(a2 + 16);
  *(_BYTE *)(a1 + 308) = 1;
  *(_DWORD *)(a1 + 320) = v4;
  dev_info(v3, "Connection established between QMI handle and %d service\n", v2);
  return 0;
}
