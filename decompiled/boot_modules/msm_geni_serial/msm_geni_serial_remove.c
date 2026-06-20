__int64 __fastcall msm_geni_serial_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  v1 = *(_QWORD *)(result + 168);
  if ( (*(_BYTE *)(v1 + 1036) & 1) == 0 )
  {
    v2 = *(_QWORD *)(v1 + 520);
    v3 = result;
    if ( *(int *)(v1 + 920) >= 1 )
      destroy_workqueue(*(_QWORD *)(v1 + 1352));
    v4 = *(_QWORD *)(v1 + 264);
    if ( !v4 || *(_DWORD *)(v1 + 316) != *(__int16 *)(v4 + 74) )
    {
      wakeup_source_unregister(*(_QWORD *)(v1 + 928));
      *(_QWORD *)(v1 + 928) = 0;
    }
    if ( *(_BYTE *)(v1 + 1336) == 1 )
      pm_runtime_allow(v3 + 16);
    uart_remove_one_port(v2, v1);
    if ( *(_BYTE *)(v1 + 1136) == 1 )
    {
      destroy_workqueue(*(_QWORD *)(v1 + 1248));
      destroy_workqueue(*(_QWORD *)(v1 + 1256));
    }
    if ( *(_QWORD *)(v1 + 872) )
    {
      if ( v1 != -872 )
      {
        v5 = *(_QWORD *)(v1 + 624);
        if ( v5 )
        {
          if ( *(_QWORD *)(v1 + 824) )
            dma_free_attrs(v5, 2048);
        }
      }
      *(_QWORD *)(v1 + 872) = 0;
    }
    if ( *(_BYTE *)(v1 + 2000) == 1 && *(_QWORD *)(v1 + 2016) )
    {
      v6 = *(_QWORD *)(v1 + 624);
      if ( v6 )
        dma_free_attrs(v6, 4112);
      *(_QWORD *)(v1 + 2016) = 0;
      *(_QWORD *)(v1 + 2008) = 0;
    }
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_hs_uart_version);
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_hs_uart_operation);
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_loopback);
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_xfer_mode);
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_ver_info);
    device_remove_file(*(_QWORD *)(v1 + 344), &dev_attr_capture_kpi);
    debugfs_remove(*(_QWORD *)(v1 + 592));
    return dev_info(v3 + 16, "%s driver removed %d\n", "msm_geni_serial_remove", 1);
  }
  return result;
}
