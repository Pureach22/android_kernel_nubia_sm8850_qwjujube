__int64 __fastcall qcom_slim_ngd_runtime_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x1
  int v4; // w8
  int v5; // w8
  int v6; // w8
  unsigned int v7; // w20
  int v8; // w8
  int v9; // w8
  int v10; // w8

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 1960);
  _slimbus_dbg();
  v4 = *(_DWORD *)(v1 + 5476);
  if ( v4 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 5488), "Slim runtime suspend\n");
    v4 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v4 )
    ipc_log_string(*(_QWORD *)(v1 + 5496), "Slim runtime suspend\n");
  mutex_lock(v1 + 5200, v3);
  if ( !*(_QWORD *)(v1 + 1920) )
  {
    _slimbus_dbg();
    v9 = *(_DWORD *)(v1 + 5476);
    if ( v9 >= 2 )
    {
      printk(&unk_CA26, "qcom_slim_ngd_runtime_suspend");
      ipc_log_string(*(_QWORD *)(v1 + 5488), "%s QMI handle is NULL\n", "qcom_slim_ngd_runtime_suspend");
      if ( *(_DWORD *)(v1 + 5476) )
        goto LABEL_23;
    }
    else if ( v9 )
    {
LABEL_23:
      mutex_unlock(v1 + 5200);
      return 0;
    }
    ipc_log_string(*(_QWORD *)(v1 + 5496), "%s QMI handle is NULL\n", "qcom_slim_ngd_runtime_suspend");
    goto LABEL_23;
  }
  qcom_slim_ngd_exit_dma(v1);
  if ( (*(_BYTE *)(v1 + 5508) & 1) == 0 )
  {
    disable_irq(*(unsigned int *)(v1 + 5504));
    *(_BYTE *)(v1 + 5508) = 1;
    _slimbus_dbg();
    v5 = *(_DWORD *)(v1 + 5476);
    if ( v5 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 5488), "Slim ngd IRQ disabled\n");
      v5 = *(_DWORD *)(v1 + 5476);
    }
    if ( !v5 )
      ipc_log_string(*(_QWORD *)(v1 + 5496), "Slim ngd IRQ disabled\n");
  }
  writel_relaxed(0, (unsigned int *)(*(_QWORD *)(v2 + 8) + 16LL));
  _slimbus_dbg();
  v6 = *(_DWORD *)(v1 + 5476);
  if ( v6 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 5488), "Sending QMI power off request\n");
    v6 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v6 )
    ipc_log_string(*(_QWORD *)(v1 + 5496), "Sending QMI power off request\n");
  v7 = qcom_slim_qmi_power_request(v1, 0);
  if ( v7 == -16 )
    goto LABEL_28;
  if ( !v7 )
    goto LABEL_27;
  _slimbus_dbg();
  v8 = *(_DWORD *)(v1 + 5476);
  if ( v8 < 3 )
  {
    if ( v8 )
      goto LABEL_26;
LABEL_25:
    ipc_log_string(*(_QWORD *)(v1 + 5496), "slim resource not idle:%d\n", v7);
    goto LABEL_26;
  }
  ipc_log_string(*(_QWORD *)(v1 + 5488), "slim resource not idle:%d\n", v7);
  if ( !*(_DWORD *)(v1 + 5476) )
    goto LABEL_25;
LABEL_26:
  if ( v7 == -110 )
LABEL_27:
    *(_DWORD *)(v1 + 5384) = 2;
LABEL_28:
  mutex_unlock(v1 + 5200);
  _slimbus_dbg();
  v10 = *(_DWORD *)(v1 + 5476);
  if ( v10 >= 3 )
  {
    ipc_log_string(
      *(_QWORD *)(v1 + 5488),
      "Slim runtime suspend: ret %d irq_disabled %d\n",
      v7,
      *(unsigned __int8 *)(v1 + 5508));
    v10 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v10 )
    ipc_log_string(
      *(_QWORD *)(v1 + 5496),
      "Slim runtime suspend: ret %d irq_disabled %d\n",
      v7,
      *(unsigned __int8 *)(v1 + 5508));
  return v7;
}
