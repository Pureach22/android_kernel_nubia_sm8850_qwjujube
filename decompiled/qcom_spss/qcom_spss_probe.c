__int64 __fastcall qcom_spss_probe(_QWORD *a1)
{
  _QWORD *v1; // x21
  __int64 match_data; // x0
  __int64 v4; // x23
  __int64 v5; // x0
  _QWORD *v6; // x20
  __int64 v7; // x19
  int v8; // w8
  __int64 v9; // x24
  unsigned int inited; // w24
  __int64 resource_byname; // x0
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  bool v19; // zf
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  unsigned __int64 v26; // x0
  int variable_u32_array; // w0
  unsigned __int64 v28; // x0
  unsigned int irq; // w0
  unsigned int v30; // w0
  __int64 v31; // x20
  __int64 v33; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v34; // [xsp+10h] [xbp-B0h]
  __int64 v35; // [xsp+18h] [xbp-A8h]
  __int64 v36; // [xsp+20h] [xbp-A0h]
  __int64 v37; // [xsp+28h] [xbp-98h]
  __int64 v38; // [xsp+30h] [xbp-90h]
  __int64 v39; // [xsp+38h] [xbp-88h]
  __int64 v40; // [xsp+40h] [xbp-80h]
  __int64 v41; // [xsp+48h] [xbp-78h]
  __int64 v42; // [xsp+50h] [xbp-70h]
  __int64 v43; // [xsp+58h] [xbp-68h]
  __int64 v44; // [xsp+60h] [xbp-60h]
  _QWORD v45[11]; // [xsp+68h] [xbp-58h] BYREF

  v1 = a1 + 2;
  v45[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  match_data = of_device_get_match_data(a1 + 2);
  if ( match_data )
  {
    v4 = match_data;
    if ( (qcom_scm_is_available() & 1) != 0 )
    {
      v5 = rproc_alloc(v1, *a1, &spss_ops, *(_QWORD *)v4, 432);
      if ( !v5 )
      {
        dev_err(v1, "unable to allocate remoteproc\n");
        inited = -12;
        goto LABEL_41;
      }
      v6 = *(_QWORD **)(v5 + 40);
      v7 = v5;
      *v6 = v1;
      v6[1] = v5;
      v8 = *(_DWORD *)(v4 + 8);
      *((_DWORD *)v6 + 16) = 0;
      *((_DWORD *)v6 + 14) = v8;
      _init_swait_queue_head(v6 + 9, "&x->wait", &init_completion___key);
      a1[21] = v6;
      *(_BYTE *)(v7 + 1249) = *(_BYTE *)(v4 + 24);
      v6[17] = *(_QWORD *)(v4 + 32);
      *(_BYTE *)(v7 + 1204) = 1;
      rproc_coredump_set_elf_info(v7, 1, 0);
      v9 = *v6;
      device_set_wakeup_capable(*v6, 1);
      inited = device_wakeup_enable(v9);
      if ( inited )
      {
LABEL_40:
        rproc_free(v7);
        goto LABEL_41;
      }
      resource_byname = platform_get_resource_byname(a1, 512, "rmb_general_purpose");
      v12 = devm_ioremap_resource(v1, resource_byname);
      v6[52] = v12;
      if ( v12 >= 0xFFFFFFFFFFFFF001LL )
      {
        inited = v12;
        goto LABEL_39;
      }
      v13 = platform_get_resource_byname(a1, 512, "sp2soc_irq_status");
      v14 = devm_ioremap_resource(v1, v13);
      v6[47] = v14;
      if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_14;
      v15 = platform_get_resource_byname(a1, 512, "sp2soc_irq_clr");
      v14 = devm_ioremap_resource(v1, v15);
      v6[48] = v14;
      if ( v14 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_14;
      v16 = platform_get_resource_byname(a1, 512, "sp2soc_irq_mask");
      v14 = devm_ioremap_resource(v1, v16);
      v6[49] = v14;
      if ( v14 >= 0xFFFFFFFFFFFFF001LL
        || (v17 = platform_get_resource_byname(a1, 512, "rmb_err"),
            v14 = devm_ioremap_resource(v1, v17),
            v6[50] = v14,
            v14 >= 0xFFFFFFFFFFFFF001LL)
        || (v18 = platform_get_resource_byname(a1, 512, "rmb_err_spare2"),
            v14 = devm_ioremap_resource(v1, v18),
            v6[51] = v14,
            v14 >= 0xFFFFFFFFFFFFF001LL) )
      {
LABEL_14:
        inited = v14;
        goto LABEL_39;
      }
      variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,spss-scsr-bits", v6 + 53, 2, 0);
      inited = variable_u32_array & (variable_u32_array >> 31);
      if ( inited )
        goto LABEL_39;
      v19 = (*(_DWORD *)v6[52] & 1) == 0;
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      if ( v19 )
        v20 = 6;
      else
        v20 = 0;
      v39 = 0;
      v40 = 0;
      *(_DWORD *)(v7 + 972) = v20;
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      v33 = 0;
      v34 = 0;
      v21 = *(_QWORD *)(*v6 + 744LL);
      memset(v45, 0, 80);
      if ( (unsigned int)_of_parse_phandle_with_args(v21, "memory-region", 0, 0, 0, v45) || !v45[0] )
      {
        dev_err(*v6, "no memory-region specified\n");
        inited = -22;
        goto LABEL_39;
      }
      inited = of_address_to_resource(v45[0], 0, &v33);
      if ( inited )
      {
LABEL_39:
        v31 = *v6;
        device_wakeup_disable(v31);
        device_set_wakeup_capable(v31, 0);
        goto LABEL_40;
      }
      v22 = v33;
      v23 = *v6;
      v24 = v34 - v33;
      v6[12] = v33;
      v6[13] = v22;
      v6[15] = v24 + 1;
      v25 = devm_ioremap_wc(v23);
      v6[14] = v25;
      if ( !v25 )
      {
        dev_err(*v6, "unable to map memory region: %pa+%zx\n", &v33, v6[15]);
        inited = -16;
        goto LABEL_39;
      }
      inited = spss_init_clock(v6);
      if ( inited )
        goto LABEL_39;
      inited = init_regulator(*v6, v6 + 3, "cx");
      if ( inited )
        goto LABEL_39;
      if ( of_find_property(a1[95], "sensors-supply", 0) )
      {
        inited = init_regulator(*v6, v6 + 5, "sensors");
        if ( inited )
          goto LABEL_39;
      }
      v26 = qmp_get(*v6);
      v6[18] = v26;
      if ( v26 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( v26 != -19 )
        {
          inited = dev_err_probe(v1, v26, "failed to acquire load state\n");
          goto LABEL_41;
        }
        v6[18] = 0;
      }
      qcom_add_glink_spss_subdev(v7, v6 + 19);
      qcom_add_ssr_subdev(v7, v6 + 33, *(_QWORD *)(v4 + 16));
      v28 = qcom_add_sysmon_subdev(v7, *(_QWORD *)(v4 + 16), 4294967274LL);
      v6[46] = v28;
      if ( v28 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(*v6, "failed to add sysmon subdevice\n");
        inited = 0;
        goto LABEL_39;
      }
      *(_DWORD *)v6[49] = -1;
      irq = platform_get_irq(a1, 0);
      *((_DWORD *)v6 + 32) = irq;
      v30 = devm_request_threaded_irq(v1, irq, 0, spss_generic_handler, 8193, "generic-irq", v6);
      if ( v30 )
      {
        inited = v30;
        dev_err(v1, "failed to acquire generic IRQ\n");
      }
      else
      {
        inited = rproc_add(v7);
        if ( !inited )
          goto LABEL_41;
      }
      qcom_remove_sysmon_subdev(v6[46]);
      goto LABEL_39;
    }
    inited = -517;
  }
  else
  {
    inited = -22;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return inited;
}
