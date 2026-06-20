__int64 __fastcall qcom_smd_register_edge(const char **a1, _QWORD *a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  const char *v6; // x2
  int v7; // w0
  int variable_u32_array; // w0
  unsigned __int64 v9; // x0
  int v10; // w20
  int u32_index; // w0
  int v12; // w0
  unsigned int v13; // w0
  unsigned int v14; // w21
  int v15; // w0
  _QWORD *v16; // x0
  int v17; // w0
  int v18; // w21
  const char *v19; // x1
  const char *v20; // x1
  unsigned __int64 v21; // x0
  _QWORD v23[11]; // [xsp+8h] [xbp-58h] BYREF

  v23[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (qcom_smem_is_available() & 1) == 0 )
  {
    v5 = -517;
    goto LABEL_41;
  }
  v4 = _kmalloc_cache_noprof(irq_of_parse_and_map, 3520, 1160);
  v5 = v4;
  if ( !v4 )
  {
    v5 = -12;
    goto LABEL_41;
  }
  _init_waitqueue_head(v4 + 1072, "&edge->new_channel_event", &qcom_smd_register_edge___key);
  v6 = a1[14];
  *(_QWORD *)(v5 + 808) = qcom_smd_edge_release;
  *(_QWORD *)(v5 + 96) = a1;
  *(_QWORD *)(v5 + 744) = a2;
  *(_QWORD *)(v5 + 800) = &qcom_smd_edge_groups;
  if ( !v6 )
    v6 = *a1;
  dev_set_name(v5, "%s:%pOFn", v6, a2);
  v7 = device_register(v5);
  if ( v7 )
  {
    v18 = v7;
    printk(&unk_879C);
    put_device(v5);
    v5 = v18;
    goto LABEL_41;
  }
  *(_QWORD *)(v5 + 1024) = v5 + 1024;
  *(_QWORD *)(v5 + 1032) = v5 + 1024;
  *(_DWORD *)(v5 + 1040) = 0;
  *(_QWORD *)(v5 + 1096) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v5 + 1104) = v5 + 1104;
  *(_QWORD *)(v5 + 1112) = v5 + 1104;
  *(_QWORD *)(v5 + 1128) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v5 + 1120) = qcom_channel_scan_worker;
  *(_QWORD *)(v5 + 1136) = v5 + 1136;
  *(_QWORD *)(v5 + 1144) = v5 + 1136;
  *(_QWORD *)(v5 + 1152) = qcom_channel_state_worker;
  *(_QWORD *)(v5 + 920) = a2;
  variable_u32_array = of_property_read_variable_u32_array(a2, "qcom,smd-edge", v5 + 928, 1, 0);
  if ( variable_u32_array < 0 )
  {
    v10 = variable_u32_array;
    v19 = "edge missing %s property\n";
    goto LABEL_25;
  }
  *(_DWORD *)(v5 + 932) = -1;
  of_property_read_variable_u32_array(a2, "qcom,remote-pid", v5 + 932, 1, 0);
  *(_QWORD *)(v5 + 960) = v5;
  *(_BYTE *)(v5 + 984) = 1;
  v9 = mbox_request_channel(v5 + 960, 0);
  *(_QWORD *)(v5 + 1016) = v9;
  if ( v9 < 0xFFFFFFFFFFFFF001LL )
    goto LABEL_16;
  if ( v9 == -19 )
  {
    *(_QWORD *)(v5 + 1016) = 0;
    memset(v23, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(a2, "qcom,ipc", 0, 0, 0, v23) || !v23[0] )
    {
      dev_err(v5, "no qcom,ipc node\n");
      v10 = -19;
      goto LABEL_30;
    }
    v9 = syscon_node_to_regmap();
    *(_QWORD *)(v5 + 944) = v9;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_12;
    u32_index = of_property_read_u32_index(a2, "qcom,ipc", 1, v5 + 952);
    if ( u32_index < 0 )
    {
      v10 = u32_index;
      v19 = "no offset in %s\n";
    }
    else
    {
      v12 = of_property_read_u32_index(a2, "qcom,ipc", 2, v5 + 956);
      if ( (v12 & 0x80000000) == 0 )
      {
LABEL_16:
        if ( (of_property_read_string(a2, "label", v5 + 912) & 0x80000000) != 0 )
          *(_QWORD *)(v5 + 912) = *a2;
        v13 = irq_of_parse_and_map(a2, 0);
        if ( v13 )
        {
          v14 = v13;
          v15 = devm_request_threaded_irq(v5, v13, qcom_smd_edge_intr, 0, 1, *a2, v5);
          if ( !v15 )
          {
            *(_DWORD *)(v5 + 936) = v14;
            v16 = (_QWORD *)_kmalloc_cache_noprof(of_property_read_string, 3520, 1000);
            if ( v16 )
            {
              v16[123] = &qcom_smd_device_ops;
              v16[124] = v5;
              v16[12] = v5;
              v16[101] = qcom_smd_release_device;
              v17 = rpmsg_register_device_override();
              if ( !v17 )
              {
                queue_work_on(32, system_wq, v5 + 1096);
                goto LABEL_41;
              }
              v10 = v17;
            }
            else
            {
              v10 = -12;
            }
            v20 = "failed to register chrdev for edge\n";
            goto LABEL_37;
          }
          v10 = v15;
          dev_err(v5, "failed to request smd irq\n");
        }
        else
        {
          dev_err(v5, "required smd interrupt missing\n");
          v10 = -22;
        }
        goto LABEL_30;
      }
      v10 = v12;
      v19 = "no bit in %s\n";
    }
LABEL_25:
    dev_err(v5, v19);
LABEL_30:
    *(_QWORD *)(v5 + 920) = 0;
    goto LABEL_31;
  }
LABEL_12:
  *(_QWORD *)(v5 + 920) = 0;
  v10 = v9;
LABEL_31:
  v20 = "failed to parse smd edge\n";
LABEL_37:
  dev_err(v5, v20);
  v21 = *(_QWORD *)(v5 + 1016);
  if ( v21 && v21 <= 0xFFFFFFFFFFFFF000LL )
    mbox_free_channel();
  device_unregister(v5);
  v5 = v10;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v5;
}
