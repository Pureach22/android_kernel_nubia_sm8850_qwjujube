__int64 __fastcall icnss_remove(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x21
  unsigned int *v5; // x21
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  unsigned int *v8; // x21
  unsigned int *v9; // x21
  unsigned int *v10; // x21
  unsigned int *v11; // x21
  unsigned int *v12; // x21
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 result; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v32; // x8

  v1 = *(_QWORD *)(a1 + 168);
  printk("%sicnss2: Removing driver: state: 0x%lx\n", byte_13289B, *(_QWORD *)(v1 + 1832));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Removing driver: state: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(v1 + 1832));
  timer_delete((timer_t)(v1 + 6016));
  if ( *(_BYTE *)(v1 + 6096) == 1 )
    timer_delete((timer_t)(v1 + 6056));
  v3 = *(_QWORD *)(v1 + 8);
  device_wakeup_disable(v3 + 16);
  device_set_wakeup_capable(v3 + 16, 0);
  icnss_unregister_ims_service(v1);
  icnss_debugfs_destroy(v1);
  v4 = penv;
  if ( *(_QWORD *)(penv + 5872) )
    power_supply_put();
  if ( *(_BYTE *)(v4 + 5846) == 1 )
  {
    _flush_workqueue(*(_QWORD *)(v4 + 5920));
    destroy_workqueue(*(_QWORD *)(v4 + 5920));
    power_supply_unreg_notifier(v4 + 5848);
  }
  if ( *(_QWORD *)(v1 + 3256) )
    kobject_put();
  sysfs_remove_link(kernel_kobj, "icnss");
  if ( (unsigned int)devres_release(
                       *(_QWORD *)(v1 + 8) + 16LL,
                       devm_icnss_group_remove,
                       devm_icnss_group_match,
                       &icnss_attr_group) )
    __break(0x800u);
  complete_all(v1 + 3088);
  if ( *(_BYTE *)(v1 + 5976) )
    complete(v1 + 5984);
  v5 = *(unsigned int **)(v1 + 2928);
  if ( v5 && (unsigned __int64)v5 <= 0xFFFFFFFFFFFFF000LL )
  {
    device_unregister(*((_QWORD *)v5 + 5));
    ida_free(&rd_minor_id, *v5);
    kfree(v5);
  }
  if ( *(_BYTE *)(v1 + 5968) == 1 )
  {
    icnss_dms_deinit(v1);
    v6 = *(_QWORD *)(v1 + 2752);
    if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL )
    {
      qcom_unregister_early_ssr_notifier();
      *(_QWORD *)(v1 + 2752) = 0;
    }
    _X9 = (unsigned __int64 *)(v1 + 1832);
    __asm { PRFM            #0x11, [X9] }
    do
      v23 = __ldxr(_X9);
    while ( __stlxr(v23 & 0xFFFFFFFFFFFFFF7FLL, _X9) );
    __dmb(0xBu);
    if ( (v23 & 0x80) != 0 )
    {
      qcom_unregister_ssr_notifier(*(_QWORD *)(v1 + 2744), v1 + 2792);
      *(_QWORD *)(v1 + 2744) = 0;
    }
  }
  else
  {
    _X9 = (unsigned __int64 *)(v1 + 1832);
    __asm { PRFM            #0x11, [X9] }
    do
      v26 = __ldxr(_X9);
    while ( __stlxr(v26 & 0xFFFFFFFFFFFFFF7FLL, _X9) );
    __dmb(0xBu);
    if ( (v26 & 0x80) != 0 )
    {
      qcom_unregister_ssr_notifier(*(_QWORD *)(v1 + 2736), v1 + 2768);
      *(_QWORD *)(v1 + 2736) = 0;
    }
    _X9 = (unsigned __int64 *)(v1 + 1832);
    __asm { PRFM            #0x11, [X9] }
    do
      v29 = __ldxr(_X9);
    while ( __stlxr(v29 & 0xFFFFFFFFFFFFFEFFLL, _X9) );
    __dmb(0xBu);
    if ( (v29 & 0x100) != 0 )
      pdr_handle_release(*(_QWORD *)(v1 + 5664));
  }
  v7 = *(_QWORD *)(v1 + 304);
  if ( v7 == 30544 )
  {
    _X9 = (unsigned __int64 *)(v1 + 1832);
    __asm { PRFM            #0x11, [X9] }
    do
      v32 = __ldxr(_X9);
    while ( __stlxr(v32 & 0xFFFFFFFFEFFFFFFFLL, _X9) );
    __dmb(0xBu);
    if ( (v32 & 0x10000000) != 0 )
      unregister_reboot_notifier(v1 + 2872);
    v7 = *(_QWORD *)(v1 + 304);
  }
  if ( v7 == 25680 || v7 == 30544 || v7 == 26448 )
  {
    icnss_genl_exit();
    _pm_runtime_disable(*(_QWORD *)(v1 + 8) + 16LL, 1);
    pm_runtime_allow(*(_QWORD *)(v1 + 8) + 16LL);
    _pm_runtime_idle(*(_QWORD *)(v1 + 8) + 16LL, 4);
    tracepoint_probe_unregister(&_tracepoint_android_vh_rproc_recovery_set, rproc_restart_level_notifier, 0);
    complete_all(v1 + 5808);
    v8 = *(unsigned int **)(v1 + 2936);
    if ( v8 && (unsigned __int64)v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      device_unregister(*((_QWORD *)v8 + 5));
      ida_free(&rd_minor_id, *v8);
      kfree(v8);
    }
    v9 = *(unsigned int **)(v1 + 2944);
    if ( v9 && (unsigned __int64)v9 <= 0xFFFFFFFFFFFFF000LL )
    {
      device_unregister(*((_QWORD *)v9 + 5));
      ida_free(&rd_minor_id, *v9);
      kfree(v9);
    }
    v10 = *(unsigned int **)(v1 + 2952);
    if ( v10 && (unsigned __int64)v10 <= 0xFFFFFFFFFFFFF000LL )
    {
      device_unregister(*((_QWORD *)v10 + 5));
      ida_free(&rd_minor_id, *v10);
      kfree(v10);
    }
    v11 = *(unsigned int **)(v1 + 2960);
    if ( v11 && (unsigned __int64)v11 <= 0xFFFFFFFFFFFFF000LL )
    {
      device_unregister(*((_QWORD *)v11 + 5));
      ida_free(&rd_minor_id, *v11);
      kfree(v11);
    }
    v12 = *(unsigned int **)(v1 + 2968);
    if ( v12 && (unsigned __int64)v12 <= 0xFFFFFFFFFFFFF000LL )
    {
      device_unregister(*((_QWORD *)v12 + 5));
      ida_free(&rd_minor_id, *v12);
      kfree(v12);
    }
    v13 = *(_QWORD *)(v1 + 1784);
    if ( v13 )
      destroy_workqueue(v13);
    icnss_aop_interface_deinit(v1);
  }
  class_destroy(*(_QWORD *)(v1 + 5792));
  unregister_chrdev_region(*(unsigned int *)(v1 + 5800), 256);
  icnss_unregister_fw_service(v1);
  v14 = *(_QWORD *)(v1 + 1776);
  if ( v14 )
    destroy_workqueue(v14);
  *(_QWORD *)(v1 + 576) = 0;
  icnss_hw_power_off(v1);
  v15 = icnss_put_resources(v1);
  result = cnss_deinitialize_prealloc_pool(v15);
  *(_QWORD *)(a1 + 168) = 0;
  return result;
}
