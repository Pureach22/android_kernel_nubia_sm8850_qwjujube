__int64 __fastcall qcom_slim_ngd_qmi_new_server(__int64 a1, __int64 a2)
{
  int v4; // w8

  _slimbus_dbg();
  v4 = *(_DWORD *)(a1 + 3868);
  if ( v4 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 3880), "Slimbus QMI new server event received\n");
    v4 = *(_DWORD *)(a1 + 3868);
  }
  if ( !v4 )
    ipc_log_string(*(_QWORD *)(a1 + 3888), "Slimbus QMI new server event received\n");
  *(_WORD *)(a1 - 16) = 42;
  *(_DWORD *)(a1 - 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(a1 - 8) = *(_DWORD *)(a2 + 16);
  complete(a1 + 3408);
  return 0;
}
