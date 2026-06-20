__int64 __fastcall qmp_mbox_probe(__int64 a1)
{
  __int64 v1; // x22
  _QWORD *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned __int64 v6; // x0
  unsigned int v7; // w24
  __int64 v8; // x23
  __int64 v9; // x26
  __int64 property; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 v16; // x0
  unsigned int v17; // w20
  unsigned __int64 v18; // x24
  unsigned __int64 v19; // x22
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned __int64 v22; // x9
  unsigned int v23; // w8
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x9
  signed int v26; // w8
  unsigned int variable_u32_array; // w0
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x0
  __int64 v30; // x27
  __int64 v31; // x25
  __int64 v32; // x0
  int v33; // w0
  __int64 v34; // x0
  __int64 v35; // x23
  int v36; // w8
  __int64 v37; // x10
  __int64 v38; // x9
  unsigned int mbox_num_chans; // w24
  unsigned __int64 v40; // x26
  unsigned __int64 v41; // x25
  __int64 v42; // x0
  __int64 v43; // x0
  unsigned __int64 v44; // x9
  unsigned int v45; // w8
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x9
  signed int v48; // w8
  void *v50; // x0
  unsigned int v51; // w8
  int v52; // w10
  int v53; // w11
  __int64 v54; // x12
  __int64 v55; // x10
  unsigned int v56; // w0
  __int64 v57; // x8
  __int64 v58; // x2
  __int64 v59; // x8
  __int64 *v60; // x1
  const char *v61; // x1
  unsigned int v62; // w8
  int v63; // w10
  int v64; // w11
  __int64 v65; // x12
  __int64 v66; // x10
  unsigned int v67; // w0
  __int64 v68; // x2
  __int64 *v69; // x1
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x1
  unsigned int v73; // w0
  int v74; // w0
  int v75; // w20
  _QWORD *i; // x20
  void *v77; // x0
  const char *v78; // x1
  void *v79; // x0
  int v80; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v81; // [xsp+10h] [xbp-60h] BYREF
  _QWORD v82[11]; // [xsp+18h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v82[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(a1 + 760);
  v4 = devm_kmalloc(a1 + 16, 160, 3520);
  if ( !v4 )
    goto LABEL_52;
  v5 = v4;
  *(_QWORD *)(a1 + 168) = v4;
  memset(v82, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v3, "qcom,qmp", 0, 0, 0, v82) || !v82[0] )
  {
    v8 = *(_QWORD *)(a1 + 760);
    v9 = *(_QWORD *)(a1 + 168);
    property = of_get_property(v8, "label", 0);
    *(_QWORD *)(v9 + 8) = property;
    if ( !property )
    {
      v50 = &unk_82F8;
LABEL_110:
      v61 = "qmp_edge_init";
      goto LABEL_111;
    }
    *(_QWORD *)(v9 + 16) = v9 + 16;
    *(_QWORD *)(v9 + 24) = v9 + 16;
    *(_QWORD *)v9 = v1;
    if ( platform_get_resource_byname(a1, 512, "msgram") )
    {
      v11 = devm_ioremap(v1);
      *(_QWORD *)(v9 + 32) = v11;
      if ( !v11 )
      {
        v7 = -5;
        goto LABEL_53;
      }
    }
    else
    {
      HIDWORD(v81) = 0;
      v82[0] = 0;
      variable_u32_array = of_property_read_variable_u32_array(v8, "qcom,remote-pid", (char *)&v81 + 4, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v7 = variable_u32_array;
        printk(&unk_860E, variable_u32_array);
        goto LABEL_53;
      }
      v28 = qcom_smem_get(HIDWORD(v81), 629, v82);
      v7 = v28;
      if ( v28 && v28 <= 0xFFFFFFFFFFFFF000LL )
      {
        *(_QWORD *)(v9 + 32) = v28;
      }
      else if ( (_DWORD)v28 )
      {
        goto LABEL_53;
      }
    }
    *(_QWORD *)(v9 + 72) = v1;
    *(_BYTE *)(v9 + 96) = 1;
    v29 = mbox_request_channel(v9 + 72, 0);
    *(_QWORD *)(v9 + 128) = v29;
    if ( v29 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( v29 != -19 )
      {
        v7 = v29;
        goto LABEL_53;
      }
      *(_QWORD *)(v9 + 128) = 0;
      v30 = *(_QWORD *)(a1 + 168);
      v31 = *(_QWORD *)(a1 + 760);
      if ( platform_get_resource_byname(a1, 512, "irq-reg-base") )
      {
        if ( (of_property_read_variable_u32_array(v31, "qcom,irq-mask", v30 + 56, 1, 0) & 0x80000000) != 0 )
        {
          v7 = -19;
          v79 = &unk_842D;
        }
        else
        {
          v32 = devm_ioremap(v1);
          *(_QWORD *)(v30 + 40) = v32;
          if ( v32 )
            goto LABEL_34;
          v7 = -5;
          v79 = &unk_8581;
        }
      }
      else
      {
        v7 = -19;
        v79 = &unk_830D;
      }
      printk(v79, "qmp_parse_ipc");
      goto LABEL_53;
    }
LABEL_34:
    v33 = irq_of_parse_and_map(v8, 0);
    *(_DWORD *)(v9 + 60) = v33;
    if ( v33 )
    {
      LODWORD(v82[0]) = 0;
      v81 = 0;
      v80 = 0;
      if ( (of_property_read_variable_u32_array(v3, "mbox-desc-offset", &v81, 1, 0) & 0x80000000) != 0
        || (of_property_read_variable_u32_array(v3, "priority", &v80, 1, 0) & 0x80000000) != 0 )
      {
        printk(&unk_86CB, "qmp_mbox_init");
      }
      else
      {
        v34 = devm_kmalloc(*(_QWORD *)v5, 512, 3520);
        if ( !v34 )
          goto LABEL_52;
        v35 = v34;
        if ( (of_property_read_variable_u32_array(v3, "mbox-offset", v82, 1, 0) & 0x80000000) == 0 )
          *(_DWORD *)(v35 + 184) = v82[0];
        if ( (of_property_read_variable_u32_array(v3, "mbox-size", (char *)&v81 + 4, 1, 0) & 0x80000000) == 0 )
          *(_DWORD *)(v35 + 188) = HIDWORD(v81);
        v36 = v80;
        v37 = (unsigned int)v81;
        v38 = *(_QWORD *)(v5 + 32);
        *(_QWORD *)(v35 + 496) = v5;
        *(_DWORD *)(v35 + 152) = v36;
        *(_QWORD *)(v35 + 168) = v38 + v37;
        mbox_num_chans = get_mbox_num_chans(v3);
        v40 = mbox_num_chans - 1;
        v41 = 248LL * mbox_num_chans;
        v42 = *(_QWORD *)v5;
        *(_BYTE *)(v35 + 176) = mbox_num_chans > 1;
        v43 = devm_kmalloc(v42, v41, 3520);
        if ( !v43 )
          goto LABEL_52;
        v44 = (v41 - 241) / 0xF8;
        if ( v44 + 1 < v40 )
          v45 = v44 + 1;
        else
          v45 = mbox_num_chans - 1;
        if ( v45 < 2 || (v44 + 1 < v40 ? (v46 = v44 + 1) : (v46 = mbox_num_chans - 1), (v47 = v46 >> 31) != 0) )
        {
          v48 = 0;
        }
        else
        {
          v51 = v45 + 1;
          v52 = v51 & 1;
          if ( (v51 & 1) == 0 )
            v52 = 2;
          v48 = v51 - v52;
          do
          {
            v53 = v47 + 1;
            v54 = v43 + 248LL * (int)v47;
            LODWORD(v47) = v47 + 2;
            *(_QWORD *)(v54 + 240) = v35;
            *(_QWORD *)(v43 + 248LL * v53 + 240) = v35;
          }
          while ( v48 != (_DWORD)v47 );
        }
        do
        {
          if ( v41 <= 248LL * v48 + 240 )
LABEL_120:
            __break(1u);
          v55 = v43 + 248LL * v48++;
          *(_QWORD *)(v55 + 240) = v35;
        }
        while ( mbox_num_chans != v48 );
        *(_QWORD *)(v35 + 16) = *(_QWORD *)v5;
        *(_QWORD *)(v35 + 24) = &qmp_mbox_ops;
        *(_QWORD *)(v35 + 32) = v43;
        *(_WORD *)(v35 + 44) = 1;
        *(_DWORD *)(v35 + 40) = mbox_num_chans;
        *(_QWORD *)(v35 + 56) = qmp_mbox_of_xlate;
        v56 = mbox_controller_register(v35 + 16);
        if ( v56 )
        {
          v7 = v56;
          v77 = &unk_836F;
          v78 = "qmp_mbox_init";
LABEL_115:
          printk(v77, v78);
          goto LABEL_53;
        }
        *(_DWORD *)(v35 + 320) = 0;
        _mutex_init(v35 + 272, "&mbox->state_lock", &qmp_mbox_init___key);
        *(_DWORD *)(v35 + 264) = 0;
        *(_DWORD *)(v35 + 328) = 0;
        _init_swait_queue_head(v35 + 336, "&x->wait", &init_completion___key);
        *(_DWORD *)(v35 + 360) = 0;
        _init_swait_queue_head(v35 + 368, "&x->wait", &init_completion___key);
        *(_BYTE *)(v35 + 177) = 0;
        *(_QWORD *)(v35 + 392) = 0xFFFFFFFE00000LL;
        *(_DWORD *)(v35 + 156) = 0;
        *(_QWORD *)(v35 + 400) = v35 + 400;
        *(_QWORD *)(v35 + 408) = v35 + 400;
        *(_QWORD *)(v35 + 416) = qmp_notify_timeout;
        init_timer_key(v35 + 424, &delayed_work_timer_fn, 0x200000, 0, 0);
        v57 = *(_QWORD *)(v35 + 496);
        v58 = v5 + 16;
        *(_BYTE *)(v35 + 504) = 0;
        *(_BYTE *)(v57 + 153) = 0;
        v59 = v5 + 16;
        *(_BYTE *)(v5 + 154) = 0;
        while ( 1 )
        {
          v59 = *(_QWORD *)v59;
          if ( v59 == v58 )
            break;
          if ( *(_DWORD *)(v59 + 152) <= *(_DWORD *)(v35 + 152) )
          {
            v60 = *(__int64 **)(v59 + 8);
            if ( v59 != v35 && v60 != (__int64 *)v35 && *v60 == v59 )
            {
              *(_QWORD *)(v59 + 8) = v35;
              *(_QWORD *)v35 = v59;
LABEL_73:
              *(_QWORD *)(v35 + 8) = v60;
              *v60 = v35;
              goto LABEL_96;
            }
            goto LABEL_121;
          }
        }
        v60 = *(__int64 **)(v5 + 24);
        if ( v58 != v35 && v60 != (__int64 *)v35 && *v60 == v58 )
        {
          *(_QWORD *)(v5 + 24) = v35;
          *(_QWORD *)v35 = v58;
          goto LABEL_73;
        }
LABEL_121:
        _list_add_valid_or_report(v35, v60);
      }
LABEL_96:
      v72 = *(_QWORD *)(v5 + 8);
      *(_QWORD *)(a1 + 168) = v5;
      *(_QWORD *)(v5 + 144) = ipc_log_context_create(2, v72, 0);
      v73 = devm_request_threaded_irq(
              v1,
              *(unsigned int *)(v5 + 60),
              qmp_irq_handler,
              qmp_thread_irq_handler,
              1,
              *v3,
              v5);
      if ( (v73 & 0x80000000) != 0 )
      {
        v7 = v73;
        qmp_mbox_remove(a1);
        if ( (unsigned int)__ratelimit(&qmp_mbox_probe__rs, "qmp_mbox_probe") )
          printk("%s[%s]: request threaded irq on %d failed: %d\n", &unk_8479);
        ipc_log_string(
          *(_QWORD *)(v5 + 144),
          "%s[%s]: request threaded irq on %d failed: %d\n",
          (const char *)&unk_826D,
          "qmp_mbox_probe",
          *(_DWORD *)(v5 + 60),
          v7);
      }
      else
      {
        v74 = irq_set_irq_wake(*(unsigned int *)(v5 + 60), 1);
        if ( v74 < 0 )
        {
          v75 = v74;
          if ( (unsigned int)__ratelimit(&qmp_mbox_probe__rs_6, "qmp_mbox_probe") )
            printk("%s[%s]: enable_irq_wake on %d failed: %d\n", &unk_8479);
          ipc_log_string(
            *(_QWORD *)(v5 + 144),
            "%s[%s]: enable_irq_wake on %d failed: %d\n",
            (const char *)&unk_826D,
            "qmp_mbox_probe",
            *(_DWORD *)(v5 + 60),
            v75);
        }
        if ( of_find_property(v3, "qcom,early-boot", 0) )
        {
          for ( i = *(_QWORD **)(v5 + 16); i != (_QWORD *)(v5 + 16); i = (_QWORD *)*i )
            _qmp_rx_worker(i);
          v7 = 0;
          *(_BYTE *)(v5 + 152) = 1;
        }
        else
        {
          v7 = 0;
        }
      }
      goto LABEL_53;
    }
    v50 = &unk_83F6;
    goto LABEL_110;
  }
  v6 = qmp_get(v1);
  *(_QWORD *)(v5 + 136) = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = v6;
    goto LABEL_53;
  }
  v12 = of_get_property(*(_QWORD *)(a1 + 760), "label", 0);
  *(_QWORD *)(v5 + 8) = v12;
  if ( !v12 )
  {
    v50 = &unk_82F8;
    v61 = "qmp_shim_init";
LABEL_111:
    printk(v50, v61);
    v7 = -19;
    goto LABEL_53;
  }
  v13 = v5 + 16;
  *(_QWORD *)(v5 + 16) = v5 + 16;
  *(_QWORD *)(v5 + 24) = v5 + 16;
  *(_QWORD *)v5 = v1;
  v14 = devm_kmalloc(v1, 512, 3520);
  if ( !v14 )
    goto LABEL_52;
  v15 = v14;
  v16 = devm_kmalloc(*(_QWORD *)v5, 4096, 3520);
  *(_QWORD *)(v15 + 216) = v16;
  if ( !v16
    || (v17 = get_mbox_num_chans(*(_QWORD *)(a1 + 760)),
        v18 = v17 - 1,
        v19 = 248LL * v17,
        v20 = *(_QWORD *)v5,
        *(_BYTE *)(v15 + 176) = v17 > 1,
        (v21 = devm_kmalloc(v20, v19, 3520)) == 0) )
  {
LABEL_52:
    v7 = -12;
    goto LABEL_53;
  }
  v22 = (v19 - 241) / 0xF8;
  if ( v22 + 1 < v18 )
    v23 = v22 + 1;
  else
    v23 = v17 - 1;
  if ( v23 < 2 || (v22 + 1 < v18 ? (v24 = v22 + 1) : (v24 = v17 - 1), (v25 = v24 >> 31) != 0) )
  {
    v26 = 0;
  }
  else
  {
    v62 = v23 + 1;
    v63 = v62 & 1;
    if ( (v62 & 1) == 0 )
      v63 = 2;
    v26 = v62 - v63;
    do
    {
      v64 = v25 + 1;
      v65 = v21 + 248LL * (int)v25;
      LODWORD(v25) = v25 + 2;
      *(_QWORD *)(v65 + 240) = v15;
      *(_QWORD *)(v21 + 248LL * v64 + 240) = v15;
    }
    while ( v26 != (_DWORD)v25 );
  }
  do
  {
    if ( v19 <= 248LL * v26 + 240 )
      goto LABEL_120;
    v66 = v21 + 248LL * v26++;
    *(_QWORD *)(v66 + 240) = v15;
  }
  while ( v17 != v26 );
  *(_QWORD *)(v15 + 16) = *(_QWORD *)v5;
  *(_QWORD *)(v15 + 24) = &qmp_mbox_shim_ops;
  *(_QWORD *)(v15 + 32) = v21;
  *(_WORD *)(v15 + 44) = 1;
  *(_DWORD *)(v15 + 40) = v17;
  *(_QWORD *)(v15 + 56) = qmp_mbox_of_xlate;
  _mutex_init(v15 + 272, "&mbox->state_lock", &qmp_shim_init___key);
  *(_DWORD *)(v15 + 156) = 0;
  *(_QWORD *)(v15 + 224) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v15 + 496) = v5;
  *(_QWORD *)(v15 + 232) = v15 + 232;
  *(_QWORD *)(v15 + 240) = v15 + 232;
  *(_QWORD *)(v15 + 248) = qmp_shim_worker;
  v67 = mbox_controller_register(v15 + 16);
  if ( v67 )
  {
    v7 = v67;
    v77 = &unk_84E0;
    v78 = "qmp_shim_init";
    goto LABEL_115;
  }
  v68 = v5 + 16;
  while ( 1 )
  {
    v68 = *(_QWORD *)v68;
    if ( v68 == v13 )
      break;
    if ( *(_DWORD *)(v68 + 152) <= *(_DWORD *)(v15 + 152) )
    {
      v69 = *(__int64 **)(v68 + 8);
      if ( v68 != v15 && v69 != (__int64 *)v15 && *v69 == v68 )
      {
        *(_QWORD *)(v68 + 8) = v15;
        *(_QWORD *)v15 = v68;
LABEL_93:
        *(_QWORD *)(v15 + 8) = v69;
        *v69 = v15;
        goto LABEL_94;
      }
      goto LABEL_123;
    }
  }
  v69 = *(__int64 **)(v5 + 24);
  if ( v13 != v15 && v69 != (__int64 *)v15 && *v69 == v13 )
  {
    *(_QWORD *)(v5 + 24) = v15;
    *(_QWORD *)v15 = v13;
    goto LABEL_93;
  }
LABEL_123:
  _list_add_valid_or_report(v15, v69);
LABEL_94:
  v70 = ipc_log_context_create(2, *(_QWORD *)(v5 + 8), 0);
  v71 = *(_QWORD *)(v15 + 496);
  v7 = 0;
  *(_QWORD *)(v5 + 144) = v70;
  *(_BYTE *)(v71 + 153) = 0;
  *(_BYTE *)(v5 + 154) = 0;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v7;
}
