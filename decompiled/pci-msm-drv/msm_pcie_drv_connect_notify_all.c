unsigned __int64 __fastcall msm_pcie_drv_connect_notify_all(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  __int64 v2; // x20
  _BYTE *v3; // x21
  __int64 v4; // x21
  _BYTE *v5; // x22
  __int64 v6; // x21
  _BYTE *v7; // x22
  __int64 v8; // x21
  _BYTE *v9; // x22
  __int64 v10; // x21
  _BYTE *v11; // x22

  if ( *(_QWORD *)(result - 8) )
  {
    v1 = result;
    v2 = **(_QWORD **)(result - 16);
    if ( v2 )
    {
      v3 = *(_BYTE **)(v2 + 1792);
      if ( v3 && (*v3 & 1) == 0 )
      {
        result = msm_pcie_notify_client(**(_QWORD **)(result - 16), 16);
        if ( (result & 1) != 0 )
        {
          mutex_lock(v2 + 1904);
          *v3 = 1;
          if ( *(_DWORD *)(v2 + 1896) )
            queue_work_on(32, mpcie_wq, v2 + 1832);
          result = mutex_unlock(v2 + 1904);
        }
      }
      else
      {
        v2 = 0;
      }
    }
    v4 = *(_QWORD *)(*(_QWORD *)(v1 - 16) + 8LL);
    if ( v4 )
    {
      v5 = *(_BYTE **)(v4 + 1792);
      if ( v5 )
      {
        if ( (*v5 & 1) == 0 )
        {
          result = msm_pcie_notify_client(v4, 16);
          if ( (result & 1) != 0 )
          {
            mutex_lock(v4 + 1904);
            *v5 = 1;
            if ( *(_DWORD *)(v4 + 1896) )
              queue_work_on(32, mpcie_wq, v4 + 1832);
            result = mutex_unlock(v4 + 1904);
          }
          v2 = v4;
        }
      }
    }
    v6 = *(_QWORD *)(*(_QWORD *)(v1 - 16) + 16LL);
    if ( v6 )
    {
      v7 = *(_BYTE **)(v6 + 1792);
      if ( v7 )
      {
        if ( (*v7 & 1) == 0 )
        {
          result = msm_pcie_notify_client(v6, 16);
          if ( (result & 1) != 0 )
          {
            mutex_lock(v6 + 1904);
            *v7 = 1;
            if ( *(_DWORD *)(v6 + 1896) )
              queue_work_on(32, mpcie_wq, v6 + 1832);
            result = mutex_unlock(v6 + 1904);
          }
          v2 = v6;
        }
      }
    }
    v8 = *(_QWORD *)(*(_QWORD *)(v1 - 16) + 24LL);
    if ( v8 )
    {
      v9 = *(_BYTE **)(v8 + 1792);
      if ( v9 )
      {
        if ( (*v9 & 1) == 0 )
        {
          result = msm_pcie_notify_client(v8, 16);
          if ( (result & 1) != 0 )
          {
            mutex_lock(v8 + 1904);
            *v9 = 1;
            if ( *(_DWORD *)(v8 + 1896) )
              queue_work_on(32, mpcie_wq, v8 + 1832);
            result = mutex_unlock(v8 + 1904);
          }
          v2 = v8;
        }
      }
    }
    v10 = *(_QWORD *)(*(_QWORD *)(v1 - 16) + 32LL);
    if ( !v10 || (v11 = *(_BYTE **)(v10 + 1792)) == nullptr || (*v11 & 1) != 0 )
    {
      if ( !v2 )
        return printk(&unk_2CA3E);
      if ( *(_QWORD *)(v1 + 152) )
        return result;
      goto LABEL_35;
    }
    result = msm_pcie_notify_client(v10, 16);
    if ( (result & 1) != 0 )
    {
      mutex_lock(v10 + 1904);
      *v11 = 1;
      if ( *(_DWORD *)(v10 + 1896) )
        queue_work_on(32, mpcie_wq, v10 + 1832);
      result = mutex_unlock(v10 + 1904);
    }
    v2 = v10;
    if ( !*(_QWORD *)(v1 + 152) )
    {
LABEL_35:
      result = qcom_register_early_ssr_notifier(*(_QWORD *)(v2 + 1984), v1 + 128);
      *(_QWORD *)(v1 + 152) = result;
      if ( result >= 0xFFFFFFFFFFFFF001LL )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: failed to register ssr notifier\n",
          "msm_pcie_drv_connect_notify_all",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: DRV: failed to register ssr notifier\n",
          "msm_pcie_drv_connect_notify_all",
          *(_DWORD *)(v2 + 1348));
        result = printk(&unk_22F97);
        *(_QWORD *)(v1 + 152) = 0;
      }
    }
  }
  return result;
}
