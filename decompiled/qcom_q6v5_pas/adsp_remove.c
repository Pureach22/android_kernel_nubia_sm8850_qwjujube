__int64 __fastcall adsp_remove(__int64 a1)
{
  __int64 *v1; // x19
  int v2; // w20
  __int64 v3; // x8
  int i; // w21
  __int64 v5; // x19

  v1 = *(__int64 **)(a1 + 168);
  rproc_del(v1[2]);
  qcom_q6v5_deinit(v1 + 3);
  if ( v1[1] )
    qcom_destroy_ramdump_device();
  device_remove_file(*v1, &dev_attr_txn_id);
  adsp_unassign_memory_region(v1);
  qcom_remove_glink_subdev(v1[2], v1 + 99);
  qcom_remove_sysmon_subdev(v1[144]);
  qcom_remove_smd_subdev(v1[2], v1 + 113);
  qcom_remove_pdm_subdev(v1[2], v1 + 122);
  qcom_remove_ssr_subdev(v1[2], v1 + 131);
  if ( *((_BYTE *)v1 + 1328) == 1 )
    atomic_notifier_chain_unregister(&panic_notifier_list, v1 + 153);
  v2 = *((_DWORD *)v1 + 110);
  if ( v2 && *(_QWORD *)(*v1 + 592) )
  {
    _pm_runtime_disable();
  }
  else if ( v2 )
  {
    v3 = 0;
    for ( i = 0; i != v2; v3 = i )
    {
      dev_pm_domain_detach(v1[v3 + 52], 0);
      ++i;
    }
  }
  v5 = *v1;
  device_wakeup_disable(v5);
  return device_set_wakeup_capable(v5, 0);
}
