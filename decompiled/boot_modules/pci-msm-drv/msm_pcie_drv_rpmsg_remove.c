__int64 __fastcall msm_pcie_drv_rpmsg_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x23
  __int64 result; // x0
  int v4; // w20

  v1 = *(_QWORD *)(a1 + 152);
  v2 = **(_QWORD **)(v1 + 16);
  mutex_lock(v1 + 112);
  *(_QWORD *)(v1 + 8) = 0;
  *(_QWORD *)(v1 + 24) = 0;
  mutex_unlock(v1 + 112);
  _flush_workqueue(mpcie_wq);
  flush_work(v1 + 32);
  msm_pcie_drv_notify_client(v1, 0x20u);
  result = *(_QWORD *)(v1 + 184);
  if ( result )
  {
    result = qcom_unregister_ssr_notifier(result, v1 + 160);
    if ( (_DWORD)result )
    {
      v4 = result;
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: error %d unregistering notifier\n",
          "msm_pcie_drv_rpmsg_remove",
          *(_DWORD *)(v2 + 1348),
          result);
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: DRV: error %d unregistering notifier\n",
          "msm_pcie_drv_rpmsg_remove",
          *(_DWORD *)(v2 + 1348),
          v4);
      }
      result = printk(&unk_2F211);
    }
    *(_QWORD *)(v1 + 184) = 0;
  }
  return result;
}
