__int64 __fastcall syna_tcm_update_lockdown_config(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w21
  __int64 v5; // x2
  unsigned int v7; // w23
  unsigned int v8; // w20
  unsigned int v9; // w0
  __int64 v10; // x2
  unsigned int flash_boot_config; // w0
  int v12; // w0
  int v13; // w0
  unsigned int v14; // w21
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x19
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 result; // x0
  void *v22; // x0
  __int64 partition_id_string; // x0
  void *v24; // x0
  __int64 v25; // x0
  __int64 v26; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v27; // [xsp+10h] [xbp-E0h]
  _QWORD v28[6]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v29; // [xsp+48h] [xbp-A8h]
  _QWORD v30[7]; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v31; // [xsp+88h] [xbp-68h]
  __int64 v32; // [xsp+90h] [xbp-60h]
  __int64 v33; // [xsp+98h] [xbp-58h]
  _QWORD v34[6]; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v35; // [xsp+D0h] [xbp-20h]
  __int64 v36; // [xsp+D8h] [xbp-18h]
  __int64 v37; // [xsp+E0h] [xbp-10h]
  __int64 v38; // [xsp+E8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  if ( !a1 )
  {
    v22 = unk_3365A;
    goto LABEL_34;
  }
  if ( !a2 || !*(_DWORD *)a2 )
  {
    v22 = unk_37F8D;
LABEL_34:
    printk(v22, "syna_tcm_update_lockdown_config", a3);
    result = 4294967055LL;
    goto LABEL_30;
  }
  if ( *(_BYTE *)(a2 + 624) != 1 || !*(_QWORD *)(a2 + 632) )
  {
    partition_id_string = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a2 + 648));
    printk(unk_3C7C0, "syna_tcm_update_lockdown_config", partition_id_string);
    result = 4294967055LL;
    goto LABEL_30;
  }
  v4 = a3;
  v5 = *(unsigned int *)(a2 + 640);
  if ( (unsigned int)v5 <= 7 )
  {
    printk(unk_33918, "syna_tcm_update_lockdown_config", v5);
    result = 4294967055LL;
    goto LABEL_30;
  }
  v36 = 0x800000000LL;
  v37 = 0;
  v35 = 0;
  v33 = 0;
  memset(v34, 0, sizeof(v34));
  v31 = 0;
  v32 = 0;
  memset(v30, 0, sizeof(v30));
  if ( v4 )
  {
    v7 = *(_DWORD *)(a1 + 524);
    v8 = *(_DWORD *)(a1 + 488);
  }
  else
  {
    v8 = 0;
    v7 = 0;
  }
  v32 = 0;
  v33 = 0;
  _mutex_init(v34, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  LOBYTE(v29) = 0;
  v26 = 0;
  v27 = 0;
  _mutex_init(v28, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  *(_DWORD *)(a1 + 904) = 1;
  v9 = syna_tcm_set_up_flash_access(a1, (__int64)v30, v7, v8);
  if ( (v9 & 0x80000000) != 0 )
  {
    v14 = v9;
    v24 = unk_32BC8;
  }
  else
  {
    flash_boot_config = syna_tcm_read_flash_boot_config(a1, (__int64)v30, (__int64)&v26, v7);
    if ( (flash_boot_config & 0x80000000) == 0 )
    {
      if ( *(char *)(v26 + (unsigned int)(HIDWORD(v27) - 7)) < 0 )
      {
        printk(unk_356D0, "syna_tcm_update_lockdown_config", v10);
        v14 = 0;
      }
      else
      {
        v12 = syna_tcm_check_flash_block(a1);
        if ( v12 <= 0 )
        {
          v14 = v12;
          v25 = syna_tcm_get_partition_id_string(*(unsigned __int8 *)(a2 + 648));
          printk(unk_3ADCB, "syna_tcm_update_lockdown_config", v25);
        }
        else
        {
          v13 = syna_tcm_write_flash(
                  a1,
                  v30,
                  (unsigned int)(v31 + *(_DWORD *)(a2 + 640) - 8),
                  *(_QWORD *)(a2 + 632) + (unsigned int)(*(_DWORD *)(a2 + 640) - 8),
                  8,
                  v4);
          if ( v13 >= 0 )
            v14 = 8;
          else
            v14 = v13;
        }
      }
      goto LABEL_17;
    }
    v14 = flash_boot_config;
    v24 = unk_3728A;
  }
  printk(v24, "syna_tcm_update_lockdown_config", v10);
LABEL_17:
  if ( *(_BYTE *)(a1 + 9) == 11 )
    syna_tcm_switch_fw_mode(a1, 1, v8);
  *(_DWORD *)(a1 + 904) = 0;
  if ( (_BYTE)v29 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v29);
  v15 = v26;
  v16 = syna_request_managed_device();
  if ( v16 )
  {
    if ( v15 )
      devm_kfree(v16, v15);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v17);
  }
  v27 = 0;
  LOBYTE(v29) = 0;
  if ( (_BYTE)v35 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v35);
  v18 = v32;
  v19 = syna_request_managed_device();
  if ( v19 )
  {
    if ( v18 )
      devm_kfree(v19, v18);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v20);
  }
  result = v14;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
