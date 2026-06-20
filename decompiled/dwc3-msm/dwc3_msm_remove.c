__int64 __fastcall dwc3_msm_remove(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x22
  int v4; // w20
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w8
  unsigned int i; // w23
  __int64 v10; // x9
  __int64 v11; // x1
  __int64 v12; // x19
  __int64 v13; // x19
  __int64 v14; // x19
  __int64 v15; // x19
  __int64 v16; // x19
  unsigned __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x19
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x0
  __int64 v22; // x20
  int v23; // w0
  unsigned int v24; // w8
  unsigned int v31; // w10
  __int64 v33; // x20
  __int64 v34; // x20
  __int64 v35; // x20
  __int64 v36; // x20
  __int64 v37; // x20
  __int64 v38; // x20
  __int64 v39; // x20

  v1 = *(_QWORD **)(a1 + 168);
  v3 = *(_QWORD *)(v1[5] + 168LL);
  if ( diag_dload )
    iounmap(diag_dload);
  usb_role_switch_unregister(v1[152]);
  if ( v1[146] )
  {
    regulator_unregister_notifier(v1[149], v1 + 146);
    v1[146] = 0;
  }
  v4 = _pm_runtime_resume(*v1, 4);
  dwc3_dbg_print(v1[157], 0xFFu, "Remov gsyn", v4, (const char *)&unk_16A05);
  if ( v4 < 0 )
  {
    dev_err(*v1, "pm_runtime_get_sync failed with %d\n", v4);
    if ( *((_BYTE *)v1 + 2804) == 1 )
    {
      v22 = *(_QWORD *)v1[352];
      v23 = _pm_runtime_resume(v22, 4);
      if ( v23 < 0 )
      {
        v24 = *(_DWORD *)(v22 + 480);
        do
        {
          if ( !v24 )
            break;
          _X12 = (unsigned int *)(v22 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v31 = __ldxr(_X12);
            if ( v31 != v24 )
              break;
            if ( !__stlxr(v24 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v31 == v24;
          v24 = v31;
        }
        while ( !_ZF );
        dev_err(*v1, "power state transit failed d1 to d0 with %d\n", v23);
      }
    }
    else
    {
      v33 = v1[52];
      if ( !(unsigned int)clk_prepare(v33) && (unsigned int)clk_enable(v33) )
        clk_unprepare(v33);
      v34 = v1[48];
      if ( !(unsigned int)clk_prepare(v34) && (unsigned int)clk_enable(v34) )
        clk_unprepare(v34);
      v35 = v1[42];
      if ( !(unsigned int)clk_prepare(v35) && (unsigned int)clk_enable(v35) )
        clk_unprepare(v35);
      v36 = v1[46];
      if ( !(unsigned int)clk_prepare(v36) && (unsigned int)clk_enable(v36) )
        clk_unprepare(v36);
      v37 = v1[47];
      if ( !(unsigned int)clk_prepare(v37) && (unsigned int)clk_enable(v37) )
        clk_unprepare(v37);
      v38 = v1[51];
      if ( !(unsigned int)clk_prepare(v38) && (unsigned int)clk_enable(v38) )
        clk_unprepare(v38);
      v39 = v1[41];
      if ( !(unsigned int)clk_prepare(v39) && (unsigned int)clk_enable(v39) )
        clk_unprepare(v39);
    }
  }
  v5 = irq_to_desc(*((unsigned int *)v1 + 139));
  if ( (*((_BYTE *)v1 + 2804) & 1) == 0 && v5 )
  {
    cancel_delayed_work_sync(v1 + 116);
    if ( *((_BYTE *)v1 + 744) && *((_DWORD *)v1 + 218) )
    {
      cpu_latency_qos_update_request(v1 + 110, 0xFFFFFFFFLL);
      *((_BYTE *)v1 + 744) = 0;
    }
    cpu_latency_qos_remove_request(v1 + 110);
  }
  cancel_work_sync(v1 + 82);
  v6 = v1[56];
  if ( v6 )
    *(_DWORD *)(v6 + 16) &= ~1u;
  v7 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 368) + 96LL) + 152LL);
  if ( *(_QWORD *)(v7 + 864) )
  {
    v8 = *(_DWORD *)(v7 + 856);
    if ( v8 )
    {
      for ( i = 0; i < v8; ++i )
      {
        v10 = *(_QWORD *)(*(_QWORD *)(v7 + 864) + 8LL * (int)i);
        if ( v10 )
        {
          dma_free_attrs(*(_QWORD *)(v3 + 376), *(unsigned int *)(v10 + 16), *(_QWORD *)v10, *(_QWORD *)(v10 + 32), 0);
          v8 = *(_DWORD *)(v7 + 856);
        }
      }
    }
    v11 = *(_QWORD *)(v7 + 1208);
    if ( v11 )
    {
      dma_unmap_page_attrs(*(_QWORD *)(v3 + 376), v11, 8, 2, 0);
      *(_QWORD *)(v7 + 1208) = 0;
    }
  }
  platform_device_put(v1[5]);
  of_platform_depopulate(a1 + 16);
  usb_put_redriver(v1[58]);
  dwc3_dbg_print(v1[157], 0xFFu, "Remov put", 0, (const char *)&unk_16A05);
  _pm_runtime_disable(*v1, 1);
  pm_runtime_barrier(*v1);
  _pm_runtime_idle(*v1, 4);
  _pm_runtime_set_status(*v1, 2);
  device_wakeup_disable(*v1);
  icc_put(v1[89]);
  icc_put(v1[90]);
  icc_put(v1[91]);
  if ( *((_DWORD *)v1 + 129) )
    ((void (*)(void))disable_irq)();
  if ( *((_DWORD *)v1 + 133) )
    ((void (*)(void))disable_irq)();
  if ( *((_DWORD *)v1 + 135) )
    ((void (*)(void))disable_irq)();
  if ( *((_DWORD *)v1 + 137) )
    ((void (*)(void))disable_irq)();
  disable_irq(*((unsigned int *)v1 + 131));
  if ( (*((_BYTE *)v1 + 2804) & 1) != 0 )
  {
    _pm_runtime_idle(*(_QWORD *)v1[352], 4);
    if ( !(unsigned int)_pm_runtime_idle(*(_QWORD *)v1[352], 4) )
      _pm_runtime_idle(*(_QWORD *)(v1[352] + 8LL), 4);
  }
  else
  {
    v12 = v1[48];
    clk_disable(v12);
    clk_unprepare(v12);
    clk_set_rate(v1[42], 19200000);
    v13 = v1[42];
    clk_disable(v13);
    clk_unprepare(v13);
    v14 = v1[46];
    clk_disable(v14);
    clk_unprepare(v14);
    v15 = v1[47];
    clk_disable(v15);
    clk_unprepare(v15);
    v16 = v1[41];
    clk_disable(v16);
    clk_unprepare(v16);
    if ( (*((_BYTE *)v1 + 2804) & 1) == 0 )
    {
      v17 = v1[55];
      if ( v17 )
      {
        if ( v17 <= 0xFFFFFFFFFFFFF000LL )
        {
          qcom_clk_set_flags(v1[42], 3);
          if ( (unsigned int)regulator_disable(v1[55]) )
            dev_err(*v1, "unable to disable usb3 gdsc\n");
        }
      }
    }
  }
  destroy_workqueue(v1[81]);
  destroy_workqueue(v1[80]);
  ipc_log_context_destroy(v1[157]);
  ipc_log_context_destroy(v1[158]);
  debugfs_remove(v1[323]);
  if ( *((_BYTE *)v1 + 2804) == 1 )
  {
    v18 = *((unsigned int *)v1 + 702);
    if ( (int)v18 < 2 )
    {
      dev_err(*v1, "%s: PD count invalid\n", "dwc3_msm_modeled_domain_detach");
    }
    else
    {
      v19 = v18 - 1;
      do
      {
        v21 = *(_QWORD *)(v1[352] + 8 * v19);
        if ( v21 && v21 <= 0xFFFFFFFFFFFFF000LL )
          dev_pm_domain_detach();
        v20 = v19-- + 1;
      }
      while ( v20 > 1 );
    }
  }
  kfree(v1[106]);
  return kfree(v1[105]);
}
