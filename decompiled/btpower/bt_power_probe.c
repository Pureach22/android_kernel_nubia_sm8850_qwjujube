__int64 __fastcall bt_power_probe(__int64 a1)
{
  __int64 v2; // x8
  int *v3; // x11
  _QWORD *v4; // x0
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  bool v11; // w2
  __int64 v12; // x0
  _QWORD *v13; // x8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x20
  int v20; // w0
  __int64 v21; // x19
  __int64 v22; // x20
  int string_helper; // w0
  unsigned int v24; // w0
  unsigned int v25; // w19
  int v26; // w21
  __int64 v27; // x8
  __int64 v28; // x2
  __int64 v29; // x1
  void *v30; // x0

  v2 = 0;
  do
  {
    v3 = &power_src[v2];
    v2 += 2;
    *((_QWORD *)v3 + 18) = 0xFFFFFFFEFFFFFFFELL;
    *(_QWORD *)v3 = 0xFFFFFFFEFFFFFFFELL;
    *((_QWORD *)v3 + 36) = 0xFFFFFFFEFFFFFFFELL;
  }
  while ( v2 != 36 );
  v4 = (_QWORD *)_kmalloc_cache_noprof(rfkill_init_sw_state, 3520, 808);
  pwr_data = (__int64)v4;
  if ( !v4 )
    return 4294967284LL;
  *v4 = a1;
  v4[26] = 0;
  v4[27] = 0;
  printk(&unk_114FC, "bt_power_probe");
  v6 = devm_nvmem_cell_get(a1 + 16, "fmd_set");
  *(_QWORD *)(pwr_data + 776) = v6;
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_11BFF, "bt_power_probe");
    v9 = devm_nvmem_cell_get(a1 + 16, "fmd_chg_pon");
    *(_QWORD *)(pwr_data + 784) = v9;
    if ( v9 < 0xFFFFFFFFFFFFF001LL )
      printk(&unk_110EE, "bt_power_probe");
    else
      printk(&unk_12744, "bt_power_probe");
    v10 = devm_nvmem_cell_get(a1 + 16, "fmd_cnt2_stop");
    *(_QWORD *)(pwr_data + 792) = v10;
    if ( v10 < 0xFFFFFFFFFFFFF001LL )
      printk(&unk_138E0, "bt_power_probe");
    else
      printk(&unk_11D92, "bt_power_probe");
    fmd_set_sdam_bit(0);
    fmd_reboot_on_usb_detection(0);
    fmd_write_stop_counter(0);
  }
  else
  {
    printk(&unk_122C5, "bt_power_probe");
    printk(&unk_112DC, "bt_power_probe");
    v7 = pwr_data;
    v8 = *(_QWORD *)(pwr_data + 776);
    *(_QWORD *)(pwr_data + 784) = v8;
    *(_QWORD *)(v7 + 792) = v8;
  }
  printk(&unk_12021, "bt_power_probe");
  v11 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,peach-bt", 0)
     || of_find_property(*(_QWORD *)(a1 + 760), "qcom,wcn786x", 0)
     || of_find_property(*(_QWORD *)(a1 + 760), "qcom,wcn8850-bt", 0) != 0;
  *(_BYTE *)(pwr_data + 176) = v11;
  printk(&unk_11C2C, "bt_power_probe");
  v12 = alloc_workqueue("workq", 16, 256);
  v13 = (_QWORD *)pwr_data;
  *(_QWORD *)(pwr_data + 296) = v12;
  if ( !v12 )
  {
    printk(&unk_10F99, "bt_power_probe");
    return 4294967284LL;
  }
  v13[45] = v13 + 45;
  v13[46] = v13 + 45;
  v13[40] = 0xFFFFFFFE00000LL;
  v13[47] = uwb_signal_handler;
  v13[41] = v13 + 41;
  v13[42] = v13 + 41;
  v13[43] = bt_signal_handler;
  v13[44] = 0xFFFFFFFE00000LL;
  v13[83] = 0xFFFFFFFE00000LL;
  v13[84] = v13 + 84;
  v13[85] = v13 + 84;
  v13[86] = bt_power_vote;
  _init_waitqueue_head(v13 + 48, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 408, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 432, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 456, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 480, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 504, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 528, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 552, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 576, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  _init_waitqueue_head(pwr_data + 600, "&pwr_data->rsp_wait_q[itr]", &bt_power_probe___key_193);
  v14 = pwr_data;
  v15 = pwr_data + 720;
  *(_QWORD *)(pwr_data + 712) = 0;
  *(_QWORD *)(v14 + 696) = v14 + 696;
  *(_QWORD *)(v14 + 704) = v14 + 696;
  _mutex_init(v15, "&pwr_data->pwr_mtx", &bt_power_probe___key_195);
  _mutex_init(pwr_data + 224, "&pwr_data->btpower_state.state_machine_lock", &bt_power_probe___key_197);
  v16 = pwr_data;
  *(_QWORD *)(pwr_data + 272) = 0;
  *(_QWORD *)(v16 + 280) = 0x100000000LL;
  if ( *(_QWORD *)(a1 + 760) )
  {
    v24 = bt_power_populate_dt_pinfo(a1);
    if ( (v24 & 0x80000000) != 0 )
    {
      v25 = v24;
      printk(&unk_11339, "bt_power_probe");
LABEL_38:
      kfree(pwr_data);
      return v25;
    }
    if ( *(_DWORD *)(pwr_data + 200) )
    {
      printk(&unk_11517, "bt_power_probe");
    }
    else
    {
      printk(&unk_12198, "bt_power_probe");
      *(_QWORD *)(a1 + 160) = pwr_data;
    }
  }
  else
  {
    v17 = *(_QWORD *)(a1 + 160);
    if ( !v17 )
    {
      printk(&unk_12773, "bt_power_probe");
LABEL_37:
      v25 = 0;
      goto LABEL_38;
    }
    if ( !*(_QWORD *)(v17 + 96) )
      *(_QWORD *)(v17 + 96) = &power_regulators;
    memcpy((void *)pwr_data, *(const void **)(a1 + 160), 0x328u);
  }
  v18 = rfkill_alloc("bt_power", a1 + 16, 2, &btpower_rfkill_ops, *(_QWORD *)(a1 + 160));
  if ( !v18 )
  {
    dev_err(a1 + 16, "rfkill allocate failed\n");
    goto LABEL_37;
  }
  v19 = v18;
  if ( (device_create_file(a1 + 16, &dev_attr_extldo) & 0x80000000) != 0 )
    printk(&unk_113A4, "btpower_rfkill_probe");
  rfkill_init_sw_state(v19, 1);
  previous = 1;
  v20 = rfkill_register(v19);
  if ( v20 )
  {
    v26 = v20;
    dev_err(a1 + 16, "rfkill register failed=%d\n", v20);
    rfkill_destroy(v19);
    if ( (v26 & 0x80000000) == 0 )
      goto LABEL_29;
    goto LABEL_37;
  }
  *(_QWORD *)(a1 + 168) = v19;
LABEL_29:
  v21 = pwr_data;
  v22 = *(_QWORD *)pwr_data;
  string_helper = of_property_read_string_helper(
                    *(_QWORD *)(*(_QWORD *)pwr_data + 760LL),
                    "qcom,pdc_init_table",
                    0,
                    0,
                    0);
  *(_DWORD *)(v21 + 180) = string_helper;
  if ( string_helper >= 1 )
  {
    v27 = *(unsigned int *)(v21 + 180);
    if ( (v27 & 0x80000000) != 0 )
      v28 = 0;
    else
      v28 = _kmalloc_noprof(8 * v27, 3520);
    *(_QWORD *)(v21 + 184) = v28;
    if ( (int)of_property_read_string_helper(*(_QWORD *)(v22 + 760), "qcom,pdc_init_table", v28, *(int *)(v21 + 180), 0) >= 0 )
      v30 = &unk_1351A;
    else
      v30 = &unk_129AE;
    printk(v30, v29);
  }
  btpower_aop_mbox_init(pwr_data);
  probe_finished = 1;
  return 0;
}
