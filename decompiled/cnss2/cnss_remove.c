__int64 __fastcall cnss_remove(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x19
  __int64 matched; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x0
  const char *v14; // x1
  unsigned __int64 v15; // x8
  unsigned __int64 StatusReg; // x8
  __int16 v17; // w9
  const char *v18; // x8
  const char *v19; // x5
  __int16 v20; // w9
  const char *v21; // x8
  unsigned int v22; // w3
  unsigned int v23; // w4
  __int64 result; // x0
  _QWORD *v25; // x9
  _QWORD *v26; // x21
  _QWORD *v27; // x8
  _QWORD *v28; // x23
  __int64 v29; // x0
  _QWORD *v30; // x0
  __int16 v31; // w9
  const char *v32; // x8
  char v33; // [xsp+0h] [xbp-40h]
  _QWORD v34[4]; // [xsp+8h] [xbp-38h] BYREF
  char v35[5]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v36; // [xsp+2Dh] [xbp-13h]
  __int16 v37; // [xsp+35h] [xbp-Bh]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD **)(a1 + 168);
  if ( !v8 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(StatusReg + 16);
      v21 = (const char *)(StatusReg + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v21;
    }
    v19 = "plat priv is null\n";
    goto LABEL_19;
  }
  matched = of_match_device(&_mod_of__cnss_of_match_table_device_table, a1 + 16);
  if ( !matched || (v11 = *(_QWORD *)(matched + 192)) == 0 )
  {
    v15 = _ReadStatusReg(SP_EL0);
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v15 + 16);
      v18 = (const char *)(v15 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v18;
    }
    v19 = "cnss remove failed to find of match device!\n";
LABEL_19:
    v22 = 3;
    v23 = 3;
LABEL_20:
    result = cnss_debug_ipc_log_print(v13, v14, "cnss_remove", v22, v23, v19, a7, a8, v33);
    goto LABEL_21;
  }
  if ( *(_QWORD *)(v11 + 24) == 0xFFFF )
  {
    v12 = _ReadStatusReg(SP_EL0);
    v13 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v31 = *(_DWORD *)(v12 + 16);
      v32 = (const char *)(v12 + 2320);
      if ( (v31 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v32;
    }
    v19 = "cnss direct link device removed!\n";
    v22 = 6;
    v23 = 6;
    goto LABEL_20;
  }
  v8[943] = 0;
  cnss_genl_exit();
  cnss_pm_notifier_deinit(v8);
  cnss_unregister_ims_service(v8);
  cnss_unregister_coex_service(v8);
  cnss_bus_deinit((__int64)v8);
  cnss_misc_deinit(v8);
  cnss_debugfs_destroy((__int64)v8);
  cnss_cancel_dms_work(v8);
  cnss_dms_deinit(v8);
  cnss_qmi_deinit(v8);
  destroy_workqueue(v8[85]);
  v36 = 0;
  strcpy(v35, "cnss");
  v37 = 0;
  memset((char *)&v34[1] + 6, 0, 18);
  strcpy((char *)v34, "shutdown_wlan");
  sysfs_remove_link(kernel_kobj, v34);
  sysfs_remove_link(kernel_kobj, v35);
  if ( (unsigned int)devres_release(*v8 + 16LL, devm_cnss_group_remove, devm_cnss_group_match, &cnss_attr_group) )
    __break(0x800u);
  v25 = (_QWORD *)v8[43];
  v26 = v8 + 43;
  if ( v25 != v8 + 43 )
  {
    do
    {
      v28 = (_QWORD *)*v25;
      v27 = (_QWORD *)v25[1];
      if ( (_QWORD *)*v27 == v25 && (_QWORD *)v28[1] == v25 )
      {
        v28[1] = v27;
        *v27 = v28;
      }
      else
      {
        _list_del_entry_valid_or_report(v25);
      }
      v29 = v25[3];
      *v25 = 0xDEAD000000000100LL;
      v25[1] = 0xDEAD000000000122LL;
      if ( v29 )
        icc_put();
      v25 = v28;
    }
    while ( v28 != v26 );
  }
  v8[45] = 0;
  v8[46] = 0;
  *v26 = 0;
  v8[44] = 0;
  cnss_put_resources(v8);
  cnss_aop_interface_deinit(v8);
  v30 = (_QWORD *)v8[1000];
  if ( v30 )
  {
    if ( *v30 )
    {
      kfree(*v30);
      v30 = (_QWORD *)v8[1000];
    }
    v30 = (_QWORD *)kfree(v30);
  }
  result = cnss_deinitialize_prealloc_pool(v30);
  *(_QWORD *)(a1 + 168) = 0;
  plat_env = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
