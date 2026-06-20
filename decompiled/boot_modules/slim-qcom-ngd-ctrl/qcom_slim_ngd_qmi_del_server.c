void __fastcall qcom_slim_ngd_qmi_del_server(__int64 a1)
{
  int v2; // w8

  _slimbus_dbg();
  v2 = *(_DWORD *)(a1 + 3868);
  if ( v2 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 3880), "Slimbus QMI del server event received\n");
    v2 = *(_DWORD *)(a1 + 3868);
  }
  if ( !v2 )
    ipc_log_string(*(_QWORD *)(a1 + 3888), "Slimbus QMI del server event received\n");
  *(_DWORD *)(a1 + 3408) = 0;
  *(_QWORD *)(a1 - 12) = 0;
}
