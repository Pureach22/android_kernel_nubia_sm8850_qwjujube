__int64 __fastcall aw9620x_reg_update_boot_work(__int64 a1)
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
  __int64 v17; // x22
  int v18; // w5
  __int64 v19; // x1
  __int64 result; // x0
  const void **v21; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v22[2]; // [xsp+8h] [xbp-38h] BYREF
  int v23; // [xsp+18h] [xbp-28h]
  int v24; // [xsp+1Ch] [xbp-24h]
  _QWORD *v25; // [xsp+20h] [xbp-20h]
  _QWORD v26[3]; // [xsp+28h] [xbp-18h] BYREF

  v26[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v21 = nullptr;
  dev_printk(&unk_134C0, v2, "[%s:%d] enter\n", "aw9620x_reg_update_boot_work", 3199);
  snprintf((char *)(a1 + 733), 0x1Eu, "aw9620x_bt_%u.bin", *(_DWORD *)(a1 + 8));
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] name :%s\n",
    "aw9620x_reg_update_boot_work",
    3204,
    (const char *)(a1 + 733));
  v3 = request_firmware(&v21, a1 + 733, *(_QWORD *)(a1 + 48));
  v4 = *(_QWORD *)(a1 + 48);
  if ( v3 )
  {
    dev_printk(&unk_134C0, v4, "[%s:%d] parse %s err!\n", "aw9620x_reg_update_boot_work", 3208, a1 + 733);
LABEL_32:
    result = 0xFFFFFFFFLL;
    goto LABEL_33;
  }
  dev_printk(&unk_142BB, v4, "[%s:%d] parse %s ok!\n", "aw9620x_reg_update_boot_work", 3211, (const char *)(a1 + 733));
  v5 = v21;
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_reg_parse_boot", 3150);
  v6 = *(_QWORD *)(a1 + 48);
  if ( !v5 )
  {
    dev_printk(&unk_134C0, v6, "[%s:%d] frimware request failed\n", "aw9620x_reg_parse_boot", 3153);
LABEL_31:
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] boot %s err!\n",
      "aw9620x_reg_update_boot_work",
      3215,
      a1 + 733);
    goto LABEL_32;
  }
  dev_printk(&unk_13D4F, v6, "[%s:%d] frimware request successfully\n", "aw9620x_reg_parse_boot", 3156);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] enter, cont->size = %d\n",
    "aw9620x_reg_parse_boot",
    3158,
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
      "aw9620x_reg_parse_boot",
      3164);
    goto LABEL_31;
  }
  v10 = v7 >> 2;
  if ( v7 >> 2 < 0x839 )
    goto LABEL_34;
  v11 = v7 & 0xFFFFFFFFFFFFFFFCLL;
  if ( (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4 || v10 == 2105 )
    goto LABEL_34;
  v12 = (size_t)*v5;
  if ( v7 >= 0x20E8 )
    v13 = v7 - 8424;
  else
    v13 = 0;
  *(_DWORD *)(v8 + 8420) = v12;
  if ( v13 < v12 )
LABEL_35:
    _fortify_panic(17);
  v14 = v8 + 8424;
  memcpy((void *)(v8 + 8424), v5[1], v12);
  release_firmware(v5);
  v15 = aw_parsing_bin_file(v9);
  v16 = *(_QWORD *)(a1 + 48);
  if ( v15 < 0 )
  {
    dev_printk(&unk_134C0, v16, "[%s:%d] aw9620x parse bin fail! ret = %d\n", "aw9620x_reg_parse_boot", 3175, v15);
LABEL_30:
    kfree(v9);
    goto LABEL_31;
  }
  if ( v11 == 100
    || v10 < 0x839
    || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4
    || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x64
    || (dev_printk(
          &unk_134C0,
          v16,
          "[%s:%d] chip name: %s, len = %d, version:0x%08x\n",
          "aw9620x_reg_parse_boot",
          3181,
          (const char *)(v9 + 48),
          *(_DWORD *)(v9 + 8420),
          *(_DWORD *)(v9 + 100)),
        v11 == 84)
    || v7 < 0x54
    || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x54
    || (v17 = *(unsigned int *)(v9 + 84),
        dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_update_boot_to_flash", 3140),
        v11 == 80)
    || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x50 )
  {
LABEL_34:
    __break(1u);
    goto LABEL_35;
  }
  v18 = *(_DWORD *)(v9 + 80);
  v19 = *(_QWORD *)(a1 + 48);
  v26[0] = 2040;
  v26[1] = 0x7FC000007F8LL;
  v22[0] = 0;
  v22[1] = v14 + v17;
  v23 = v18;
  v24 = 0;
  v25 = v26;
  if ( !(v14 + v17) )
  {
    dev_printk(&unk_142BB, v19, "[%s:%d] w_bin_offset is null err\n", "aw9620x_update_bt_to_flash", 1571);
LABEL_29:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] update_firmware err!\n", "aw9620x_reg_parse_boot", 3185);
    goto LABEL_30;
  }
  dev_printk(&unk_142BB, v19, "[%s:%d] update_data_len = %d\n", "aw9620x_update_bt_to_flash", 1575, v18);
  if ( (unsigned int)aw9620x_flash_update(a1, (unsigned __int8 *)v22) )
    goto LABEL_29;
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] update_firmware ok!\n", "aw9620x_reg_parse_boot", 3187);
  kfree(v9);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] boot %s ok!\n",
    "aw9620x_reg_update_boot_work",
    3218,
    (const char *)(a1 + 733));
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
