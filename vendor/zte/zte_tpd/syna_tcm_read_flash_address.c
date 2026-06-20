__int64 __fastcall syna_tcm_read_flash_address(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, unsigned int a5)
{
  unsigned int v7; // w21
  __int64 v10; // x3
  int v11; // w25
  unsigned int v12; // w24
  __int64 v13; // x2
  size_t v14; // x24
  void *v15; // x0
  void *v16; // x24
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x0
  __int64 v20; // x2
  void *v21; // x2
  unsigned int flash; // w0
  __int64 v23; // x19
  __int64 v24; // x0
  __int64 v25; // x2
  void *v27; // x0
  void *v28; // x0
  __int64 v29; // x2
  _QWORD v30[8]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v31; // [xsp+40h] [xbp-60h]
  __int64 v32; // [xsp+48h] [xbp-58h]
  _QWORD v33[6]; // [xsp+50h] [xbp-50h] BYREF
  __int64 v34; // [xsp+80h] [xbp-20h]
  __int64 v35; // [xsp+88h] [xbp-18h]
  __int64 v36; // [xsp+90h] [xbp-10h]
  __int64 v37; // [xsp+98h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v34 = 0;
  v32 = 0;
  memset(v33, 0, sizeof(v33));
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( !a1 )
  {
    v27 = unk_3365A;
LABEL_30:
    printk(v27, "syna_tcm_read_flash_address", a3);
    v12 = -241;
    goto LABEL_27;
  }
  if ( !a4 )
  {
    v27 = unk_3ADA8;
    goto LABEL_30;
  }
  v7 = a3;
  if ( a5 )
    v10 = *(unsigned int *)(a1 + 488);
  else
    v10 = 0;
  v11 = *(unsigned __int8 *)(a1 + 9);
  if ( v11 == 11 )
  {
    v12 = 0;
  }
  else
  {
    v12 = syna_tcm_set_up_flash_access(a1, v30, a5, v10);
    if ( (v12 & 0x80000000) != 0 )
    {
      printk(unk_32BC8, "syna_tcm_read_flash_address", v13);
      goto LABEL_27;
    }
  }
  LOBYTE(v34) = 0;
  v31 = 0;
  v32 = 0;
  _mutex_init(v33, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  if ( !v7 )
    goto LABEL_20;
  v14 = *(unsigned int *)(a4 + 8);
  v15 = *(void **)a4;
  if ( (unsigned int)v14 >= v7 )
    goto LABEL_18;
  if ( !v15 )
  {
LABEL_14:
    v19 = syna_request_managed_device();
    if ( v19 )
      goto LABEL_15;
LABEL_36:
    v28 = unk_3BE43;
    goto LABEL_37;
  }
  v16 = *(void **)a4;
  v17 = syna_request_managed_device();
  if ( v17 )
  {
    devm_kfree(v17, v16);
    goto LABEL_14;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v18);
  v19 = syna_request_managed_device();
  if ( !v19 )
    goto LABEL_36;
LABEL_15:
  if ( (int)v7 <= 0 )
  {
    v28 = unk_38286;
LABEL_37:
    printk(v28, "syna_pal_mem_alloc", v20);
    *(_QWORD *)a4 = 0;
    goto LABEL_38;
  }
  v14 = v7;
  v15 = (void *)devm_kmalloc(v19, v7, 3520);
  *(_QWORD *)a4 = v15;
  if ( v15 )
  {
    *(_DWORD *)(a4 + 8) = v7;
LABEL_18:
    memset(v15, 0, v14);
    v21 = *(void **)a4;
    *(_DWORD *)(a4 + 12) = 0;
    flash = syna_tcm_read_flash(a1, a2, v21, v7, a5);
    if ( (flash & 0x80000000) != 0 )
    {
      v12 = flash;
      printk(unk_39B25, "syna_tcm_read_flash_address", v7);
    }
    else
    {
      v12 = 0;
      *(_DWORD *)(a4 + 12) = v7;
    }
    goto LABEL_20;
  }
LABEL_38:
  printk(unk_3703C, "syna_tcm_buf_alloc", v7);
  *(_QWORD *)(a4 + 8) = 0;
  printk(unk_33E5C, "syna_tcm_read_flash_address", v29);
  v12 = -243;
LABEL_20:
  if ( v11 == 1 )
    syna_tcm_switch_fw_mode(a1, 1, a5);
  if ( (_BYTE)v34 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v34);
  v23 = v31;
  v24 = syna_request_managed_device();
  if ( v24 )
  {
    if ( v23 )
      devm_kfree(v24, v23);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v25);
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v12;
}
