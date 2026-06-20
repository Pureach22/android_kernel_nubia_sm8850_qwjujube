__int64 __fastcall swrm_probe(_QWORD *a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x0
  __int64 *v4; // x24
  __int64 v5; // x19
  __int64 v6; // x8
  unsigned int variable_u32_array; // w0
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned int v14; // w0
  __int64 v15; // x0
  unsigned __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x23
  unsigned __int64 v19; // x8
  int v20; // w13
  unsigned int v21; // w12
  unsigned __int64 v22; // x11
  __int64 v23; // x3
  __int64 v24; // x4
  unsigned __int64 v25; // x14
  int v26; // w13
  int v27; // w14
  _BYTE *v28; // x12
  int v29; // w0
  __int64 v30; // x8
  __int64 v31; // x8
  int v32; // w26
  unsigned __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 v36; // x11
  bool *v37; // x14
  char v38; // w15
  bool v39; // zf
  char v40; // w13
  __int64 v41; // x13
  int v42; // w14
  __int64 result; // x0
  unsigned __int64 v44; // x0
  unsigned __int64 v45; // x22
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x0
  bool v48; // cc
  __int64 (__fastcall *v49)(__int64, __int64 (__fastcall *)(), __int64, __int64); // x8
  unsigned int v50; // w22
  unsigned __int64 v51; // x9
  __int64 v52; // x0
  unsigned int v53; // w0
  const char *v54; // x1
  __int64 v55; // x3
  _QWORD *v56; // x0
  unsigned int irq_byname; // w0
  unsigned int v58; // w0
  __int64 v59; // x22
  int v60; // w0
  unsigned int v61; // w0
  int v62; // w0
  int v63; // w3
  unsigned int v64; // w0
  __int64 v65; // x9
  unsigned int v66; // w0
  unsigned int v67; // w3
  unsigned int v68; // w4
  int v69; // w0
  __int64 v70; // x8
  __int64 v71; // x0
  unsigned __int64 dir; // x0
  __int64 file; // x0
  __int64 v74; // x2
  __int64 v75; // x0
  __int64 v76; // x2
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  unsigned int v80; // w19
  __int64 v81; // x8
  const char *v82; // x1
  __int64 v83; // x20
  _DWORD *v84; // x8
  __int64 v85; // x0
  __int64 irq_data; // x0
  unsigned int v87; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v88; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v89; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v90; // [xsp+18h] [xbp-8h]

  v1 = a1 + 2;
  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = 0;
  v87 = 0;
  v88 = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 2, 20888, 3520);
  if ( !v3 )
    goto LABEL_61;
  v4 = (__int64 *)a1[20];
  v5 = (__int64)v3;
  v3[1918] = a1;
  v3[1064] = v1;
  a1[21] = v3;
  v3[19] = v3;
  if ( !v4 )
  {
    dev_err(v1, "%s: pdata from parent is NULL\n", "swrm_probe");
LABEL_122:
    result = 4294967274LL;
    goto LABEL_140;
  }
  v6 = *v4;
  v3[1133] = *v4;
  if ( !v6 )
  {
    dev_err(v1, "%s: swrm->handle is NULL\n", "swrm_probe");
    goto LABEL_122;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,swr-master-ee-val", v3 + 1132, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v5 + 9056) = 1;
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,swr-master-version", v5 + 9128, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v5 + 9128) = 0x2000000;
  variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,swr_master_id", v5 + 9052, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v80 = variable_u32_array;
    dev_err(v1, "%s: failed to get master id\n", "swrm_probe");
LABEL_115:
    result = v80;
    goto LABEL_140;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,dynamic-port-map-supported", v5 + 9060, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v5 + 9060) = 1;
  if ( (of_property_read_variable_u32_array(a1[95], "swrm-io-base", v5 + 9024, 1, 0) & 0x80000000) == 0 )
    of_property_read_variable_u32_array(a1[95], "swrm-io-base", v5 + 9024, 1, 0);
  v8 = *(unsigned int *)(v5 + 9024);
  if ( (_DWORD)v8 )
  {
    *(_QWORD *)(v5 + 9032) = devm_ioremap(v1, v8, 24744);
  }
  else
  {
    v9 = v4[1];
    *(_QWORD *)(v5 + 9072) = v9;
    if ( !v9 )
    {
      dev_err(v1, "%s: swrm->read is NULL\n", "swrm_probe");
      goto LABEL_122;
    }
    v10 = v4[2];
    *(_QWORD *)(v5 + 9080) = v10;
    if ( !v10 )
    {
      dev_err(v1, "%s: swrm->write is NULL\n", "swrm_probe");
      goto LABEL_122;
    }
    v11 = v4[3];
    *(_QWORD *)(v5 + 9088) = v11;
    if ( !v11 )
    {
      dev_err(v1, "%s: swrm->bulk_write is NULL\n", "swrm_probe");
      goto LABEL_122;
    }
  }
  v12 = a1[95];
  *(_QWORD *)(v5 + 9104) = v4[5];
  if ( (of_property_read_variable_u32_array(v12, "qcom,swrm-hctl-reg", &v88, 1, 0) & 0x80000000) == 0 )
    *(_QWORD *)(v5 + 9040) = devm_ioremap(v1, v88, 4);
  v13 = v4[4];
  *(_QWORD *)(v5 + 9096) = v13;
  if ( !v13 )
  {
    dev_err(v1, "%s: swrm->clk is NULL\n", "swrm_probe");
    goto LABEL_122;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,swr-clock-stop-mode0", v5 + 15704, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v5 + 15704) = 0;
  v14 = of_property_read_variable_u32_array(a1[95], "qcom,swr-num-ports", &v89, 1, 0);
  if ( (v14 & 0x80000000) != 0 )
  {
    v81 = *(_QWORD *)(v5 + 8512);
    v82 = "%s: Failed to get num_ports\n";
LABEL_114:
    v80 = v14;
    dev_err(v81, v82, "swrm_probe");
    goto LABEL_115;
  }
  v15 = a1[95];
  *(_BYTE *)(v5 + 15472) = v89;
  if ( !of_find_property(v15, "qcom,swr-port-mapping", &v87) )
  {
    dev_err(*(_QWORD *)(v5 + 8512), "missing port mapping\n");
    result = 0;
    goto LABEL_140;
  }
  if ( v89 >= 0xE )
  {
    dev_err(v1, "%s:invalid number of swr ports\n", "swrm_probe");
    goto LABEL_122;
  }
  v16 = v87;
  v17 = devm_kmalloc(v1, v87, 3520);
  if ( !v17 )
  {
LABEL_61:
    result = 4294967284LL;
    goto LABEL_140;
  }
  v18 = v17;
  v14 = of_property_read_variable_u32_array(a1[95], "qcom,swr-port-mapping", v17, 3 * ((unsigned int)v16 / 0xC), 0);
  if ( (v14 & 0x80000000) != 0 )
  {
    v81 = *(_QWORD *)(v5 + 8512);
    v82 = "%s: Failed to read port mapping\n";
    goto LABEL_114;
  }
  if ( (unsigned int)v16 < 0xC )
  {
LABEL_45:
    devm_kfree(v1, v18);
    v29 = of_property_read_variable_u32_array(a1[95], "qcom,is-always-on", v5 + 15904, 1, 0);
    v30 = v4[6];
    *(_QWORD *)(v5 + 8432) = swrm_read;
    *(_QWORD *)(v5 + 9112) = v30;
    *(_QWORD *)(v5 + 8448) = swrm_bulk_write;
    *(_QWORD *)(v5 + 8456) = swrm_get_logical_dev_num;
    *(_QWORD *)(v5 + 8464) = &swrm_init_port_params;
    *(_QWORD *)(v5 + 8416) = swrm_connect_port;
    *(_QWORD *)(v5 + 8424) = swrm_disconnect_port;
    *(_QWORD *)(v5 + 8472) = swrm_slvdev_datapath_control;
    *(_QWORD *)(v5 + 8480) = swrm_remove_from_group;
    *(_QWORD *)(v5 + 8488) = swrm_device_wakeup_vote;
    *(_QWORD *)(v5 + 8496) = swrm_device_wakeup_unvote;
    v31 = a1[95];
    *(_QWORD *)(v5 + 8440) = swrm_write;
    *(_QWORD *)(v5 + 744) = v31;
    *(_WORD *)(v5 + 9048) = 0;
    LODWORD(v31) = *(_DWORD *)(v5 + 9052);
    *(_QWORD *)(v5 + 96) = v1;
    *(_BYTE *)(v5 + 8409) = 0;
    *(_BYTE *)(v5 + 9050) = 0;
    *(_DWORD *)(v5 + 9144) = 0;
    *(_DWORD *)(v5 + 15352) = 0;
    *(_DWORD *)(v5 + 8536) = 0;
    *(_DWORD *)(v5 + 15868) = 0;
    *(_QWORD *)(v5 + 9132) = 41231686051200000LL;
    if ( (_DWORD)v31 == 5 )
      *(_QWORD *)(v5 + 9132) = 0xBB800000BB8000LL;
    *(_WORD *)(v5 + 15748) = 1;
    *(_DWORD *)(v5 + 15336) = 2;
    *(_BYTE *)(v5 + 15900) = 0;
    *(_BYTE *)(v5 + 15908) = 0;
    v32 = v29 & (v29 >> 31);
    *(_DWORD *)(v5 + 15744) = 0;
    *(_DWORD *)(v5 + 15884) = 0;
    *(_DWORD *)(v5 + 8576) = 0;
    _init_swait_queue_head(v5 + 8584, "&x->wait", &init_completion___key);
    *(_DWORD *)(v5 + 8608) = 0;
    _init_swait_queue_head(v5 + 8616, "&x->wait", &init_completion___key);
    *(_DWORD *)(v5 + 8544) = 0;
    _init_swait_queue_head(v5 + 8552, "&x->wait", &init_completion___key);
    _mutex_init(v5 + 8928, "&swrm->irq_lock", &swrm_probe___key);
    _mutex_init(v5 + 8784, "&swrm->mlock", &swrm_probe___key_89);
    _mutex_init(v5 + 8832, "&swrm->reslock", &swrm_probe___key_91);
    _mutex_init(v5 + 15360, "&swrm->force_down_lock", &swrm_probe___key_93);
    _mutex_init(v5 + 8688, "&swrm->iolock", &swrm_probe___key_95);
    _mutex_init(v5 + 8640, "&swrm->clklock", &swrm_probe___key_97);
    _mutex_init(v5 + 8736, "&swrm->devlock", &swrm_probe___key_99);
    _mutex_init(v5 + 8880, "&swrm->pm_lock", &swrm_probe___key_101);
    _mutex_init(v5 + 8976, "&swrm->runtime_lock", &swrm_probe___key_103);
    *(_DWORD *)(v5 + 15832) = 0;
    *(_DWORD *)(v5 + 15800) = 0;
    _init_waitqueue_head(v5 + 15808, "&swrm->pm_wq", &swrm_probe___key_105);
    cpu_latency_qos_add_request(v5 + 15752, 0xFFFFFFFFLL);
    v33 = 0;
    v34 = 9152;
    v35 = 9174;
    v36 = 9183;
    do
    {
      v41 = v5 + v34;
      *(_QWORD *)v41 = v41;
      *(_QWORD *)(v41 + 8) = v41;
      v42 = *(_DWORD *)(v5 + 9052);
      if ( v42 == 5 || v42 == 3 )
      {
        v39 = v42 == 5;
        v37 = (bool *)(v5 + v36);
        *(_WORD *)(v5 + v35) = -1;
        v38 = 20 * v33;
        *(_BYTE *)(v5 + v36 - 11) = 0;
        if ( !v39 )
          v38 = 0;
        *(v37 - 12) = v38;
        *(_BYTE *)(v41 + 28) = -1;
        *(_DWORD *)(v41 + 24) = -1;
        *(v37 - 2) = 0;
        v39 = v33 > 3 && *(_DWORD *)(v5 + 9052) == 5;
        v40 = v39;
        *(v37 - 1) = v40;
        *v37 = *(_DWORD *)(v5 + 9052) != 3;
      }
      ++v33;
      v34 += 40;
      v35 += 40;
      v36 += 40;
    }
    while ( v33 != 13 );
    if ( (of_property_read_variable_u32_array(a1[95], "qcom,disable-div2-clk-switch", v5 + 15884, 1, 0) & 0x80000000) != 0 )
      *(_DWORD *)(v5 + 15884) = 0;
    v44 = devm_clk_get(v1, "lpass_core_hw_vote");
    v45 = v44;
    if ( v44 <= 0xFFFFFFFFFFFFF000LL )
      v46 = v44;
    else
      v46 = 0;
    *(_QWORD *)(v5 + 15848) = v46;
    v47 = devm_clk_get(v1, "lpass_audio_hw_vote");
    v48 = v45 > 0xFFFFFFFFFFFFF000LL || v47 > 0xFFFFFFFFFFFFF000LL;
    v49 = *(__int64 (__fastcall **)(__int64, __int64 (__fastcall *)(), __int64, __int64))(v5 + 9112);
    if ( v48 )
      v50 = 0;
    else
      v50 = v32;
    if ( v47 <= 0xFFFFFFFFFFFFF000LL )
      v51 = v47;
    else
      v51 = 0;
    *(_QWORD *)(v5 + 15856) = v51;
    if ( v49 )
    {
      v52 = *(_QWORD *)(v5 + 9064);
      if ( *((_DWORD *)v49 - 1) != -46680235 )
        __break(0x8228u);
      v53 = v49(v52, swr_mstr_interrupt, v5, 1);
      if ( v53 )
      {
        v54 = "%s: IRQ register failed ret %d\n";
        v55 = v53;
        v56 = v1;
LABEL_138:
        v50 = v55;
        dev_err(v56, v54, "swrm_probe", v55);
        goto LABEL_139;
      }
    }
    else
    {
      irq_byname = platform_get_irq_byname(a1, "swr_master_irq");
      *(_DWORD *)(v5 + 9120) = irq_byname;
      if ( (irq_byname & 0x80000000) != 0 )
      {
        dev_err(*(_QWORD *)(v5 + 8512), "%s() error getting irq hdle: %d\n", "swrm_probe", irq_byname);
        goto LABEL_139;
      }
      v58 = request_threaded_irq(irq_byname, 0, swr_mstr_interrupt, 8193, "swr_master_irq", v5);
      if ( v58 )
      {
        v54 = "%s: Failed to request irq %d\n";
        v55 = v58;
        v56 = *(_QWORD **)(v5 + 8512);
        goto LABEL_138;
      }
    }
    of_property_read_variable_u32_array(a1[95], "qcom,swr-mstr-irq-wakeup-capable", v5 + 15868, 1, 0);
    if ( *(_DWORD *)(v5 + 15868) )
    {
      irq_set_irq_wake(*(unsigned int *)(v5 + 9120), 1);
      v59 = *(_QWORD *)(v5 + 8512);
      device_set_wakeup_capable(v59, 1);
      v60 = device_wakeup_enable(v59);
      if ( v60 )
        dev_info(*(_QWORD *)(v5 + 8512), "%s: Device wakeup init failed: %d\n", "swrm_probe", v60);
    }
    v61 = swr_register_master(v5);
    if ( v61 )
    {
      v50 = v61;
      dev_err(v1, "%s: error adding swr master\n", "swrm_probe");
    }
    else
    {
      swr_master_add_boarddevices(v5);
      if ( !*(_DWORD *)(v5 + 15904) )
        swrm_request_hw_vote(v5, 1, 1);
      mutex_lock(v5 + 8784);
      swrm_clk_request(v5, 1);
      *(_DWORD *)(v5 + 15888) = ((unsigned int)swr_master_read(v5, 0x100u) >> 15) & 0x1F;
      *(_DWORD *)(v5 + 15892) = ((unsigned int)swr_master_read(v5, 0x100u) >> 10) & 0x1F;
      v62 = swr_master_read(v5, 0);
      v63 = *(_DWORD *)(v5 + 9128);
      if ( v63 != v62 )
        dev_info(
          v1,
          "%s: version specified in dtsi: 0x%x not match with HW read version 0x%x\n",
          "swrm_probe",
          v63,
          v62);
      v64 = swr_master_read(v5, 0x100u);
      v65 = *(_QWORD *)(v5 + 8512);
      *(_DWORD *)(v5 + 15896) = (v64 >> 20) & 0xF;
      v66 = of_property_read_variable_u32_array(*(_QWORD *)(v65 + 744), "qcom,swr-num-dev", v5 + 9140, 1, 0);
      if ( (v66 & 0x80000000) != 0 )
      {
        v50 = v66;
        dev_err(v1, "%s: Looking up %s property failed\n", "swrm_probe", "qcom,swr-num-dev");
      }
      else
      {
        v67 = *(_DWORD *)(v5 + 9140);
        v68 = *(_DWORD *)(v5 + 15896);
        if ( v67 > v68 )
        {
          dev_err(v1, "%s: num_dev %d > max limit %d\n", "swrm_probe", v67, v68);
          v50 = -22;
        }
        else
        {
          v69 = swrm_master_init(v5);
          if ( (v69 & 0x80000000) == 0 )
          {
            mutex_unlock(v5 + 8784);
            *(_QWORD *)(v5 + 15712) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v5 + 15720) = v5 + 15720;
            *(_QWORD *)(v5 + 15728) = v5 + 15720;
            v70 = a1[95];
            *(_QWORD *)(v5 + 15736) = swrm_wakeup_work;
            if ( v70 )
              of_register_swr_devices(v5);
            v71 = a1[16];
            if ( !v71 )
              v71 = *v1;
            dir = debugfs_create_dir(v71, 0);
            *(_QWORD *)(v5 + 20840) = dir;
            if ( dir <= 0xFFFFFFFFFFFFF000LL )
            {
              file = debugfs_create_file("swrm_peek", 33060, dir, v5, &swrm_debug_read_ops);
              v74 = *(_QWORD *)(v5 + 20840);
              *(_QWORD *)(v5 + 20848) = file;
              v75 = debugfs_create_file("swrm_poke", 33060, v74, v5, &swrm_debug_write_ops);
              v76 = *(_QWORD *)(v5 + 20840);
              *(_QWORD *)(v5 + 20856) = v75;
              *(_QWORD *)(v5 + 20864) = debugfs_create_file("swrm_reg_dump", 33060, v76, v5, &swrm_debug_dump_ops);
            }
            v77 = a1[16];
            if ( !v77 )
              v77 = *v1;
            v78 = proc_mkdir(v77, 0);
            *(_QWORD *)(v5 + 20880) = v78;
            if ( v78 && !proc_create_data("swr_mstr_ctrl_regdump", 292, v78, &swr_mstr_ctrl_proc_ops, v5) )
            {
              dev_err(v1, "%s: error creating proc read interface\n", "swrm_probe");
              proc_remove(*(_QWORD *)(v5 + 20880));
              *(_QWORD *)(v5 + 20880) = 0;
            }
            pm_runtime_set_autosuspend_delay(v1, (unsigned int)auto_suspend_timer);
            _pm_runtime_use_autosuspend(v1, 1);
            _pm_runtime_set_status(v1, 0);
            v79 = pm_runtime_enable(v1);
            a1[67] = ktime_get_mono_fast_ns(v79);
            result = 0;
            *(_QWORD *)(v5 + 15440) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v5 + 15448) = v5 + 15448;
            *(_QWORD *)(v5 + 15456) = v5 + 15448;
            *(_QWORD *)(v5 + 15464) = swrm_notify_work_fn;
            *(_QWORD *)(v5 + 15416) = swrm_event_notify;
            goto LABEL_140;
          }
          dev_err(v1, "%s: Error in master Initialization , err %d\n", "swrm_probe", v69);
          v50 = -517;
        }
      }
      mutex_unlock(v5 + 8784);
      swr_unregister_master(v5);
      v83 = *(_QWORD *)(v5 + 8512);
      device_wakeup_disable(v83);
      device_set_wakeup_capable(v83, 0);
    }
    v84 = *(_DWORD **)(v5 + 9112);
    if ( v84 )
    {
      v85 = *(_QWORD *)(v5 + 9064);
      if ( *(v84 - 1) != -46680235 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64 (__fastcall *)(), __int64, _QWORD))v84)(v85, swr_mstr_interrupt, v5, 0);
    }
    else if ( *(_DWORD *)(v5 + 9120) )
    {
      if ( ((__int64 (*)(void))irq_get_irq_data)() )
      {
        irq_data = irq_get_irq_data(*(unsigned int *)(v5 + 9120));
        **(_DWORD **)(irq_data + 16) &= 0xFFFFFFF0;
        **(_DWORD **)(irq_data + 16) |= 0x2000000u;
      }
      if ( *(_DWORD *)(v5 + 15868) )
        irq_set_irq_wake(*(unsigned int *)(v5 + 9120), 0);
      free_irq(*(unsigned int *)(v5 + 9120), v5);
    }
LABEL_139:
    cpu_latency_qos_remove_request(v5 + 15752);
    result = v50;
    goto LABEL_140;
  }
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = v16;
  while ( 1 )
  {
    if ( v19 > v16 || v22 < 4 || v19 + 8 > v16 || v22 - 8 < 4 )
LABEL_141:
      __break(1u);
    v23 = *(unsigned int *)(v18 + v19);
    v24 = (_DWORD)v23 == v20 ? v21 : 0LL;
    if ( (unsigned int)v23 > 0xD || (unsigned int)v24 >= 8 )
      break;
    if ( v19 + 4 > v16 || v22 - 4 < 4 || ((16 * v23) | (unsigned __int64)(2 * v24)) >> 3 > 0x2A4 )
      goto LABEL_141;
    v25 = v18 + v19;
    v26 = *(_DWORD *)(v18 + v19 + 8);
    v19 += 12LL;
    v27 = *(_DWORD *)(v25 + 4);
    v28 = (_BYTE *)(v5 + 15473 + 16 * v23 + 2 * v24);
    if ( *(_DWORD *)(v5 + 9052) == 5 )
      LOBYTE(v26) = 1;
    v22 -= 12LL;
    *v28 = v27;
    v28[1] = v26;
    v21 = v24 + 1;
    v20 = v23;
    if ( 12LL * ((unsigned int)v16 / 0xC) == v19 )
      goto LABEL_45;
  }
  dev_err(v1, "%s:invalid port_num %d or ch_iter %d\n", "swrm_probe", v23, v24);
  result = 0;
LABEL_140:
  _ReadStatusReg(SP_EL0);
  return result;
}
