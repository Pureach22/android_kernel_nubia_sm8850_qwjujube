__int64 __fastcall msm_pcie_drv_notify_client(__int64 result, unsigned int a2)
{
  __int64 v3; // x20
  __int64 i; // x25
  __int64 v5; // x24
  _BYTE *v6; // x26

  v3 = result;
  for ( i = 0; i != 40; i += 8 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + i);
    if ( v5 )
    {
      v6 = *(_BYTE **)(v5 + 1792);
      if ( v6 )
      {
        ipc_log_string(
          *(_QWORD *)(v5 + 1704),
          "DBG1:%s: PCIe: RC%d: event %d received\n",
          "msm_pcie_drv_notify_client",
          *(_DWORD *)(v5 + 1348),
          a2);
        result = ipc_log_string(
                   *(_QWORD *)(v5 + 1696),
                   "%s: PCIe: RC%d: event %d received\n",
                   "msm_pcie_drv_notify_client",
                   *(_DWORD *)(v5 + 1348),
                   a2);
        if ( *v6 == 1 )
        {
          result = msm_pcie_notify_client(v5, a2);
          if ( (a2 & 0x20) != 0 )
          {
            mutex_lock(v5 + 1904);
            *v6 = 0;
            cancel_work_sync(v5 + 1832);
            cancel_work_sync(v5 + 1800);
            result = mutex_unlock(v5 + 1904);
          }
        }
      }
    }
  }
  return result;
}
