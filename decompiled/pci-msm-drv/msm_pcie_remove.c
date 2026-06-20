__int64 __fastcall msm_pcie_remove(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  _QWORD *v8; // x19
  __int64 v9; // x0
  __int64 v10; // x8
  _QWORD *v11; // x19
  __int64 v12; // x0
  __int64 v13; // x9
  unsigned __int64 v14; // x21
  _QWORD *v15; // x0
  _QWORD *v16; // x9
  __int64 v17; // x8
  _QWORD *v18; // x8
  _QWORD *v19; // x22
  _QWORD *v20; // x0
  _QWORD *v21; // x9
  __int64 v22; // x8
  _QWORD *v23; // x8
  _QWORD *v24; // x22
  __int64 result; // x0
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  mutex_lock(&unk_30CD8);
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "cell-index", &v26, 1, 0) & 0x80000000) != 0 )
  {
    printk(&unk_2D2CC);
    goto LABEL_46;
  }
  --pcie_drv[0];
  dev_info(a1 + 16, "PCIe: RC%d: being removed\n", v26);
  v2 = v26;
  if ( v26 >= 5 )
    goto LABEL_47;
  v3 = msm_pcie_dev[v26];
  if ( *(_QWORD *)(v3 + 1192) )
  {
    pci_load_and_free_saved_state(*(_QWORD *)(v3 + 8), v3 + 1192);
    v2 = v26;
    if ( v26 > 4 )
      goto LABEL_47;
  }
  if ( v2 > 4 )
    goto LABEL_48;
  v4 = msm_pcie_dev[v2];
  if ( *(_QWORD *)(v4 + 1184) )
  {
    pci_load_and_free_saved_state(*(_QWORD *)(v4 + 8), v4 + 1184);
    v2 = v26;
    if ( v26 > 4 )
      goto LABEL_47;
  }
  if ( v2 > 4 )
    goto LABEL_48;
  v5 = msm_pcie_dev[v2];
  if ( *(_QWORD *)(v5 + 3128) )
  {
    msm_pcie_cesta_map_apply(v5, 0);
    v2 = v26;
    if ( v26 > 4 )
      goto LABEL_47;
  }
  if ( v2 > 4 )
    goto LABEL_48;
  v6 = msm_pcie_dev[v2];
  if ( v6 )
  {
    ipc_log_string(*(_QWORD *)(v6 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_irq_deinit", *(_DWORD *)(v6 + 1348));
    ipc_log_string(*(_QWORD *)(v6 + 1696), "%s: RC%d\n", "msm_pcie_irq_deinit", *(_DWORD *)(v6 + 1348));
  }
  wakeup_source_unregister(*(_QWORD *)(v6 + 1200));
  v7 = *(unsigned int *)(v6 + 944);
  if ( (_DWORD)v7 )
    disable_irq(v7);
  if ( v26 > 4 )
    goto LABEL_47;
  msm_pcie_vreg_deinit(msm_pcie_dev[v26]);
  if ( v26 > 4 )
    goto LABEL_47;
  msm_pcie_clk_deinit(msm_pcie_dev[v26]);
  if ( v26 > 4 )
    goto LABEL_47;
  msm_pcie_gdsc_deinit((const char ***)msm_pcie_dev[v26]);
  if ( v26 > 4 )
    goto LABEL_47;
  ((void (__fastcall *)(__int64))msm_pcie_gpio_deinit)(msm_pcie_dev[v26]);
  if ( v26 > 4 )
    goto LABEL_47;
  v8 = (_QWORD *)msm_pcie_dev[v26];
  v9 = v8[387];
  v8[109] = 0;
  v8[391] = 0;
  v8[111] = 0;
  v8[112] = 0;
  v8[113] = 0;
  v8[114] = 0;
  v8[115] = 0;
  v8[116] = 0;
  kfree(v9);
  kfree(v8[389]);
  kfree(v8[385]);
  v10 = v26;
  v8[387] = 0;
  v8[389] = 0;
  v8[385] = 0;
  if ( (unsigned int)v10 > 4 )
  {
LABEL_47:
    __break(0x5512u);
LABEL_48:
    __break(1u);
  }
  v11 = (_QWORD *)msm_pcie_dev[v10];
  v12 = v11[5];
  v13 = v11[6];
  if ( v12 )
  {
    if ( v13 )
    {
      dev_pm_domain_detach(v12, 0);
      dev_pm_domain_detach(v11[6], 0);
      goto LABEL_28;
    }
  }
  else if ( !v13 )
  {
    goto LABEL_28;
  }
  _pm_runtime_disable(*v11 + 16LL, 1);
LABEL_28:
  v14 = v26;
  if ( v26 > 4 )
    goto LABEL_47;
  v15 = *(_QWORD **)(msm_pcie_dev[v26] + 1584);
  while ( 1 )
  {
    if ( v14 > 4 )
      goto LABEL_48;
    v17 = msm_pcie_dev[v14];
    if ( v15 == (_QWORD *)(v17 + 1584) )
      break;
    v19 = (_QWORD *)*v15;
    v18 = (_QWORD *)v15[1];
    if ( (_QWORD *)*v18 == v15 && (_QWORD *)v19[1] == v15 )
    {
      v19[1] = v18;
      *v18 = v19;
    }
    else
    {
      _list_del_entry_valid_or_report(v15);
      v15 = v16;
    }
    *v15 = 0xDEAD000000000100LL;
    v15[1] = 0xDEAD000000000122LL;
    kfree(v15);
    v14 = v26;
    v15 = v19;
    if ( v26 >= 5 )
      goto LABEL_47;
  }
  v20 = *(_QWORD **)(v17 + 1600);
  while ( 1 )
  {
    if ( v14 > 4 )
      goto LABEL_48;
    v22 = msm_pcie_dev[v14];
    if ( v20 == (_QWORD *)(v22 + 1600) )
      break;
    v24 = (_QWORD *)*v20;
    v23 = (_QWORD *)v20[1];
    if ( (_QWORD *)*v23 == v20 && (_QWORD *)v24[1] == v20 )
    {
      v24[1] = v23;
      *v23 = v24;
    }
    else
    {
      _list_del_entry_valid_or_report(v20);
      v20 = v21;
    }
    *v20 = 0xDEAD000000000100LL;
    v20[1] = 0xDEAD000000000122LL;
    kfree(v20);
    v14 = v26;
    v20 = v24;
    if ( v26 >= 5 )
      goto LABEL_47;
  }
  ipc_log_context_destroy(*(_QWORD *)(v22 + 1696));
  ipc_log_context_destroy(*(_QWORD *)(msm_pcie_dev[v14] + 1704));
  ipc_log_context_destroy(*(_QWORD *)(msm_pcie_dev[v14] + 1712));
LABEL_46:
  result = mutex_unlock(&unk_30CD8);
  _ReadStatusReg(SP_EL0);
  return result;
}
