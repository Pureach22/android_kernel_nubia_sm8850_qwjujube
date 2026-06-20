__int64 __fastcall msm_cvp_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 drv_data; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x21
  int v6; // w0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  int v12; // w8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  int v17; // w0
  int group; // w0
  unsigned __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // x2
  void *v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  void (__fastcall *v25)(__int64); // x8
  unsigned __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 inited; // x1
  __int64 v30; // x0
  __int64 v31; // x2
  __int64 v32; // x3
  int v33; // w8
  __int64 v34; // x9
  char v35; // w10
  int v36; // w0
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x2
  __int64 v40; // x3
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v42; // x8
  int v43; // w4
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8

  if ( msm_cvp_probe_allowed != 1 )
  {
    LODWORD(v5) = 0;
    return (unsigned int)v5;
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-cvp") )
  {
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-cvp,bus") )
    {
      LODWORD(v5) = cvp_read_bus_resources_from_dt(a1);
    }
    else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-cvp,context-bank") )
    {
      LODWORD(v5) = cvp_read_context_bank_resources_from_dt(a1);
    }
    else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-cvp,mem-cdsp") )
    {
      LODWORD(v5) = cvp_read_mem_cdsp_resources_from_dt(a1);
    }
    else
    {
      if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-cvp,ipclite") )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_8E7D2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        }
        __break(0x800u);
        goto LABEL_50;
      }
      LODWORD(v5) = cvp_read_ipclite_mappings_from_dt(a1);
    }
    return (unsigned int)v5;
  }
  if ( cvp_driver )
  {
    v2 = _kmalloc_large_noprof(51328, 3520);
    if ( !v2 )
    {
      LODWORD(v5) = -12;
      return (unsigned int)v5;
    }
    drv_data = cvp_get_drv_data(a1 + 16);
    *(_QWORD *)(a1 + 168) = v2;
    *(_QWORD *)(v2 + 264) = drv_data;
    if ( a1 )
    {
      v4 = *(_QWORD *)(a1 + 760);
      *(_DWORD *)(v2 + 600) = 0;
      *(_QWORD *)(v2 + 864) = a1;
      if ( v4 )
      {
        cvp_read_platform_resources_from_drv_data(v2);
        LODWORD(v5) = cvp_read_platform_resources_from_dt(v2);
        if ( !(_DWORD)v5 )
        {
          *(_QWORD *)(v2 + 280) = v2 + 280;
          *(_QWORD *)(v2 + 288) = v2 + 280;
          _mutex_init(v2, "&core->lock", &msm_cvp_initialize_core___key);
          _mutex_init(v2 + 48, "&core->clk_lock", &msm_cvp_initialize_core___key_58);
          *(_DWORD *)(v2 + 304) = 0;
          *(_DWORD *)(v2 + 312) = 0;
          _init_swait_queue_head(v2 + 320, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 344) = 0;
          _init_swait_queue_head(v2 + 352, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 376) = 0;
          _init_swait_queue_head(v2 + 384, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 408) = 0;
          _init_swait_queue_head(v2 + 416, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 440) = 0;
          _init_swait_queue_head(v2 + 448, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 472) = 0;
          _init_swait_queue_head(v2 + 480, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 504) = 0;
          _init_swait_queue_head(v2 + 512, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 536) = 0;
          _init_swait_queue_head(v2 + 544, "&x->wait", &init_completion___key);
          *(_DWORD *)(v2 + 568) = 0;
          _init_swait_queue_head(v2 + 576, "&x->wait", &init_completion___key);
          *(_QWORD *)(v2 + 1208) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v2 + 1216) = v2 + 1216;
          *(_QWORD *)(v2 + 1224) = v2 + 1216;
          *(_QWORD *)(v2 + 1232) = &msm_cvp_ssr_handler;
          *(_DWORD *)(v2 + 1260) = 0;
          v6 = alloc_chrdev_region(v2 + 96, 0, 1, "cvp");
          if ( v6 < 0 )
          {
            LODWORD(v5) = v6;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v14 = _ReadStatusReg(SP_EL0);
              printk(&unk_836D7, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
            }
            goto LABEL_89;
          }
          v7 = class_create("cvp");
          LODWORD(v5) = v7;
          *(_QWORD *)(v2 + 240) = v7;
          if ( v7 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v8 = _ReadStatusReg(SP_EL0);
              printk(&unk_911B2, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
            }
            goto LABEL_88;
          }
          v5 = device_create(v7, 0, *(unsigned int *)(v2 + 96), 0, "cvp");
          *(_QWORD *)(v2 + 248) = v5;
          if ( v5 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v16 = _ReadStatusReg(SP_EL0);
              printk(&unk_911E3, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
            }
            goto LABEL_87;
          }
          *(_QWORD *)(v5 + 152) = v2;
          cdev_init(v2 + 104, &cvp_fops);
          v17 = cdev_add(v2 + 104, *(_DWORD *)(v2 + 96) & 0xFFF00000, 1);
          if ( v17 < 0 )
          {
            LODWORD(v5) = v17;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v24 = _ReadStatusReg(SP_EL0);
              printk(&unk_87FAD, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
            }
            goto LABEL_86;
          }
          group = sysfs_create_group(*(_QWORD *)(v2 + 248), &msm_cvp_core_attr_group);
          if ( group )
          {
            LODWORD(v5) = group;
            if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
              goto LABEL_85;
            v19 = _ReadStatusReg(SP_EL0);
            v20 = *(unsigned int *)(v19 + 1800);
            v21 = *(unsigned int *)(v19 + 1804);
            v22 = &unk_8F263;
            goto LABEL_56;
          }
          v25 = *(void (__fastcall **)(__int64))off_199B8[0];
          if ( *(_DWORD *)(*(_QWORD *)off_199B8[0] + 0xFFFFFFFFFFFFFFFCLL) != -1096575152 )
            __break(0x8228u);
          v25(v2);
          v26 = cvp_hfi_initialize(*(unsigned int *)(v2 + 600), v2 + 608, cvp_handle_cmd_response);
          *(_QWORD *)(v2 + 256) = v26;
          if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
          {
            mutex_lock(cvp_driver);
            mutex_unlock(cvp_driver);
            if ( *(_QWORD *)(v2 + 256) )
              LODWORD(v5) = *(_QWORD *)(v2 + 256);
            else
              LODWORD(v5) = -521;
            if ( (_DWORD)v5 == -517 )
            {
              LODWORD(v5) = -517;
              if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_82CD2, "core", v39, v40);
                LODWORD(v5) = -517;
              }
              goto LABEL_85;
            }
            if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
            {
LABEL_85:
              cdev_del(v2 + 104);
LABEL_86:
              device_destroy(*(_QWORD *)(v2 + 240), *(unsigned int *)(v2 + 96));
LABEL_87:
              class_destroy(*(_QWORD *)(v2 + 240));
LABEL_88:
              unregister_chrdev_region(*(unsigned int *)(v2 + 96), 1);
LABEL_89:
              sysfs_remove_group(a1 + 16, &msm_cvp_core_attr_group);
              goto LABEL_90;
            }
            v46 = _ReadStatusReg(SP_EL0);
            v20 = *(unsigned int *)(v46 + 1800);
            v21 = *(unsigned int *)(v46 + 1804);
            v22 = &unk_8407C;
LABEL_56:
            printk(v22, v20, v21, &unk_8E7CE);
            goto LABEL_85;
          }
          cvp_synx_ftbl_init(v2);
          mutex_lock(cvp_driver);
          v27 = cvp_driver;
          *(_QWORD *)(cvp_driver + 48) = v2;
          v28 = mutex_unlock(v27);
          inited = msm_cvp_debugfs_init_drv(v28);
          *(_QWORD *)(cvp_driver + 56) = inited;
          if ( !inited && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v47 = _ReadStatusReg(SP_EL0);
            printk(&unk_8698D, *(unsigned int *)(v47 + 1800), *(unsigned int *)(v47 + 1804), &unk_8E7CE);
            inited = *(_QWORD *)(cvp_driver + 56);
          }
          v30 = msm_cvp_debugfs_init_core(v2, inited);
          v33 = *(_DWORD *)(v2 + 760);
          v34 = cvp_driver;
          v35 = BYTE1(msm_cvp_debug);
          *(_QWORD *)(v2 + 296) = v30;
          *(_DWORD *)(v34 + 68) = v33;
          if ( (v35 & 1) != 0 && !msm_cvp_debug_out )
            printk(&unk_8A51B, "core", v31, v32);
          v36 = of_platform_populate(*(_QWORD *)(a1 + 760), &_mod_of__msm_cvp_plat_match_device_table, 0, a1 + 16);
          if ( v36 )
          {
            LODWORD(v5) = v36;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v45 = _ReadStatusReg(SP_EL0);
              printk(&unk_840B1, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), &unk_8E7CE);
            }
            cvp_hfi_deinitialize(*(unsigned int *)(v2 + 600), *(_QWORD *)(v2 + 256));
            debugfs_remove(*(_QWORD *)(cvp_driver + 56));
            goto LABEL_85;
          }
          *(_QWORD *)(v2 + 1296) = 512;
          if ( *(_BYTE *)(v2 + 938) == 1 )
          {
            LODWORD(v5) = cvp_dsp_device_init();
            if ( (_DWORD)v5 && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
            {
              v42 = _ReadStatusReg(SP_EL0);
              printk(&unk_87408, *(unsigned int *)(v42 + 1800), *(unsigned int *)(v42 + 1804), "warn");
            }
          }
          else
          {
            LODWORD(v5) = 0;
            if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            {
              printk(&unk_8CE4B, "dsp", v37, v38);
              LODWORD(v5) = 0;
            }
          }
          v43 = *(_DWORD *)(*(_QWORD *)(v2 + 264) + 60LL);
          if ( v43 == 2 )
          {
            set_kaanapali_hal_functions();
            return (unsigned int)v5;
          }
          if ( v43 == 1 )
          {
            set_pakala_hal_functions();
            return (unsigned int)v5;
          }
          LODWORD(v5) = -22;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v44 = _ReadStatusReg(SP_EL0);
            printk(&unk_840F2, *(unsigned int *)(v44 + 1800), *(unsigned int *)(v44 + 1804), &unk_8E7CE);
            goto LABEL_50;
          }
          return (unsigned int)v5;
        }
      }
      else
      {
        LODWORD(v5) = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v23 = _ReadStatusReg(SP_EL0);
          printk(&unk_89B88, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
          LODWORD(v5) = -22;
        }
      }
    }
    else
    {
      LODWORD(v5) = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_92CD0, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
        LODWORD(v5) = -22;
      }
    }
    v12 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      printk(&unk_84122, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
      v12 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) == 0 )
        goto LABEL_90;
    }
    else if ( (msm_cvp_debug & 1) == 0 )
    {
LABEL_90:
      *(_QWORD *)(a1 + 168) = 0;
      kfree(v2);
      return (unsigned int)v5;
    }
    if ( !v12 )
    {
      v13 = _ReadStatusReg(SP_EL0);
      printk(&unk_8FF0B, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
    }
    goto LABEL_90;
  }
  LODWORD(v5) = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    printk(&unk_836AB, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
LABEL_50:
    LODWORD(v5) = -22;
  }
  return (unsigned int)v5;
}
