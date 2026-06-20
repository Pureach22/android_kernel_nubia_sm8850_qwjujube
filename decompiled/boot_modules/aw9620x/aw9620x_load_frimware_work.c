__int64 __fastcall aw9620x_load_frimware_work(__int64 a1)
{
  __int64 v2; // x1
  int v3; // w0
  __int64 v4; // x1
  const void **v5; // x22
  __int64 v6; // x1
  unsigned __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x24
  size_t v12; // x2
  size_t v13; // x1
  __int64 v14; // x23
  int v15; // w0
  __int64 v16; // x1
  int v17; // w0
  __int64 v18; // x1
  int updated; // w0
  __int64 v20; // x1
  __int64 result; // x0
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v22[0] = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_load_frimware_work", 3316);
  snprintf((char *)(a1 + 703), 0x1Eu, "aw9620x_fw_%d.bin", *(_DWORD *)(a1 + 8));
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] name :%s\n",
    "aw9620x_load_frimware_work",
    3321,
    (const char *)(a1 + 703));
  v3 = request_firmware(v22, a1 + 703, *(_QWORD *)(a1 + 48));
  v4 = *(_QWORD *)(a1 + 48);
  if ( v3 )
  {
    dev_printk(&unk_134C0, v4, "[%s:%d] parse %s err!\n", "aw9620x_load_frimware_work", 3325, a1 + 703);
LABEL_34:
    result = 0xFFFFFFFFLL;
    goto LABEL_35;
  }
  dev_printk(&unk_142BB, v4, "[%s:%d] parse %s ok!\n", "aw9620x_load_frimware_work", 3328, (const char *)(a1 + 703));
  v5 = (const void **)v22[0];
  v6 = *(_QWORD *)(a1 + 48);
  if ( !v22[0] )
  {
    dev_printk(&unk_134C0, v6, "[%s:%d] frimware request failed\n", "aw9620x_parse_frimware", 3255);
LABEL_33:
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] reg_bin %s load err!\n",
      "aw9620x_load_frimware_work",
      3333,
      a1 + 703);
    goto LABEL_34;
  }
  dev_printk(&unk_13D4F, v6, "[%s:%d] frimware request successfully\n", "aw9620x_parse_frimware", 3258);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] enter, cont->size = %d\n",
    "aw9620x_parse_frimware",
    3260,
    *(_DWORD *)v5);
  v7 = (unsigned __int64)*v5 + 8424;
  v8 = _kmalloc_noprof(v7, 3520);
  v9 = v8;
  if ( !v8 )
  {
    kfree(0);
    release_firmware(v5);
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] failed to allcating memory!\n",
      "aw9620x_parse_frimware",
      3266);
    goto LABEL_33;
  }
  v10 = v7 >> 2;
  if ( v7 >> 2 < 0x839 )
    goto LABEL_36;
  v11 = v7 & 0xFFFFFFFFFFFFFFFCLL;
  if ( (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4 || v10 == 2105 )
    goto LABEL_36;
  v12 = (size_t)*v5;
  if ( v7 >= 0x20E8 )
    v13 = v7 - 8424;
  else
    v13 = 0;
  *(_DWORD *)(v8 + 8420) = v12;
  if ( v13 < v12 )
LABEL_37:
    _fortify_panic(17);
  v14 = v8 + 8424;
  memcpy((void *)(v8 + 8424), v5[1], v12);
  release_firmware(v5);
  v15 = aw_parsing_bin_file(v9);
  v16 = *(_QWORD *)(a1 + 48);
  if ( v15 < 0 )
  {
    dev_printk(&unk_134C0, v16, "[%s:%d] aw9620x parse bin fail! ret = %d\n", "aw9620x_parse_frimware", 3277, v15);
LABEL_32:
    kfree(v9);
    goto LABEL_33;
  }
  if ( v10 < 0x839 || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4 )
  {
LABEL_36:
    __break(1u);
    goto LABEL_37;
  }
  dev_printk(
    &unk_134C0,
    v16,
    "[%s:%d] reg chip name: %s, soc chip name: %s, len = %d\n",
    "aw9620x_parse_frimware",
    3282,
    (const char *)(a1 + 673),
    (const char *)(v9 + 48),
    *(_DWORD *)(v9 + 8420));
  if ( *(_BYTE *)(a1 + 3) == 1 )
  {
    if ( v11 != 80
      && v11 != 84
      && v7 >= 0x54
      && (v7 & 0xFFFFFFFFFFFFFFFCLL) != 0x54
      && (v7 & 0xFFFFFFFFFFFFFFFCLL) != 0x50 )
    {
      updated = aw9620x_update_fw_to_flash(a1, v14 + *(unsigned int *)(v9 + 84), *(_DWORD *)(v9 + 80));
      v20 = *(_QWORD *)(a1 + 48);
      if ( updated )
      {
        dev_printk(&unk_134C0, v20, "[%s:%d] reg update_firmware err!\n", "aw9620x_parse_frimware", 3295);
        goto LABEL_32;
      }
      dev_printk(&unk_142BB, v20, "[%s:%d] reg update_firmware ok!\n", "aw9620x_parse_frimware", 3298);
      goto LABEL_29;
    }
    goto LABEL_36;
  }
  if ( !*(_BYTE *)(a1 + 3) )
  {
    v17 = aw9620x_update_firmware(a1, v9);
    v18 = *(_QWORD *)(a1 + 48);
    if ( v17 )
    {
      dev_printk(&unk_134C0, v18, "[%s:%d] update_firmware err!\n", "aw9620x_parse_frimware", 3287);
      goto LABEL_32;
    }
    dev_printk(&unk_142BB, v18, "[%s:%d] update_firmware ok!\n", "aw9620x_parse_frimware", 3290);
  }
LABEL_29:
  kfree(v9);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] reg_bin %s load ok!\n",
    "aw9620x_load_frimware_work",
    3336,
    (const char *)(a1 + 703));
  result = 0;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
