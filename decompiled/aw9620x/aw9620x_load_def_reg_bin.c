__int64 __fastcall aw9620x_load_def_reg_bin(__int64 a1)
{
  __int64 v2; // x1
  int v3; // w22
  __int64 v4; // x1
  const void **v5; // x23
  __int64 v6; // x1
  unsigned __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x24
  size_t v12; // x2
  size_t v13; // x1
  __int64 v14; // x22
  int v15; // w0
  __int64 v16; // x1
  __int64 result; // x0
  int v18; // w23
  unsigned int v19; // w28
  unsigned __int64 v20; // x24
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x13
  int v27; // w26
  int v28; // w27
  int v29; // w0
  __int64 v30; // x1
  _QWORD v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v31[0] = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_load_def_reg_bin", 3112);
  snprintf((char *)(a1 + 763), 0x1Eu, "aw9620x_reg_%u.bin", *(_DWORD *)(a1 + 8));
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] name :%s\n",
    "aw9620x_load_def_reg_bin",
    3117,
    (const char *)(a1 + 763));
  v3 = request_firmware(v31, a1 + 763, *(_QWORD *)(a1 + 48));
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] ret = %d\n", "aw9620x_load_def_reg_bin", 3119, v3);
  v4 = *(_QWORD *)(a1 + 48);
  if ( v3 )
  {
    dev_printk(&unk_134C0, v4, "[%s:%d] parse %s err!\n", "aw9620x_load_def_reg_bin", 3121, a1 + 763);
LABEL_53:
    result = 0xFFFFFFFFLL;
    goto LABEL_54;
  }
  dev_printk(&unk_142BB, v4, "[%s:%d] parse %s ok!\n", "aw9620x_load_def_reg_bin", 3124, (const char *)(a1 + 763));
  v5 = (const void **)v31[0];
  v6 = *(_QWORD *)(a1 + 48);
  if ( !v31[0] )
  {
    dev_printk(&unk_134C0, v6, "[%s:%d] def_reg_bin request failed\n", "aw9620x_parse_def_reg_bin", 3046);
LABEL_52:
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] reg_bin %s load err!\n",
      "aw9620x_load_def_reg_bin",
      3128,
      a1 + 763);
    goto LABEL_53;
  }
  dev_printk(&unk_13D4F, v6, "[%s:%d] def_reg_bin request successfully\n", "aw9620x_parse_def_reg_bin", 3049);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] enter, cont->size = %d\n",
    "aw9620x_parse_def_reg_bin",
    3051,
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
      "aw9620x_parse_def_reg_bin",
      3057);
    goto LABEL_52;
  }
  v10 = v7 >> 2;
  if ( v7 >> 2 < 0x839 )
    goto LABEL_48;
  v11 = v7 & 0xFFFFFFFFFFFFFFFCLL;
  if ( (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4 || v10 == 2105 )
    goto LABEL_48;
  v12 = (size_t)*v5;
  if ( v7 >= 0x20E8 )
    v13 = v7 - 8424;
  else
    v13 = 0;
  *(_DWORD *)(v8 + 8420) = v12;
  if ( v13 < v12 )
    _fortify_panic(17);
  v14 = v8 + 8424;
  memcpy((void *)(v8 + 8424), v5[1], v12);
  release_firmware(v5);
  v15 = aw_parsing_bin_file(v9);
  v16 = *(_QWORD *)(a1 + 48);
  if ( v15 < 0 )
  {
    dev_printk(&unk_134C0, v16, "[%s:%d] aw9620x parse bin fail! ret = %d\n", "aw9620x_parse_def_reg_bin", 3068, v15);
LABEL_51:
    kfree(v9);
    goto LABEL_52;
  }
  if ( v10 < 0x839 || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x20E4 )
    goto LABEL_48;
  dev_printk(
    &unk_134C0,
    v16,
    "[%s:%d] reg chip name: %s, soc chip name: %s, len = %d\n",
    "aw9620x_parse_def_reg_bin",
    3073,
    (const char *)(a1 + 673),
    (const char *)(v9 + 48),
    *(_DWORD *)(v9 + 8420));
  if ( strcmp((const char *)(a1 + 673), (const char *)(v9 + 48)) )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] chip name(%s) incompatible with chip type(%s)\n",
      "aw9620x_parse_def_reg_bin",
      3079,
      (const char *)(a1 + 673),
      (const char *)(v9 + 48));
    goto LABEL_51;
  }
  if ( v11 == 80 || v7 < 0x50 || (v7 & 0xFFFFFFFFFFFFFFFCLL) == 0x50 )
    goto LABEL_48;
  if ( *(_DWORD *)(v9 + 80) )
  {
    if ( v11 != 84 && v7 >= 0x54 && (v7 & 0xFFFFFFFFFFFFFFFCLL) != 0x54 )
    {
      v18 = *(_DWORD *)(v9 + 84);
      v19 = 0;
      v20 = v7 & 0xFFFFFFFFFFFFFFFCLL;
      while ( 1 )
      {
        v21 = v18 + v19;
        if ( v7 <= v21 + 8424 )
          break;
        v22 = (unsigned int)(v21 + 1);
        if ( v7 <= v22 + 8424 )
          break;
        if ( v7 <= v21 + 8424 )
          break;
        if ( v7 <= v22 + 8424 )
          break;
        v23 = v18 + v19 + 2;
        if ( v7 <= v23 + 8424 )
          break;
        v24 = v18 + v19 + 3;
        if ( v7 <= v24 + 8424 )
          break;
        v25 = v18 + v19 + 4;
        if ( v7 <= v25 + 8424 )
          break;
        v26 = v18 + v19 + 5;
        if ( v7 <= v26 + 8424 || v7 <= v24 + 8424 || v7 <= v23 + 8424 || v7 <= v25 + 8424 || v7 <= v26 + 8424 )
          break;
        v27 = *(unsigned __int8 *)(v14 + v21) | (*(unsigned __int8 *)(v14 + v22) << 8);
        v28 = *(unsigned __int8 *)(v14 + v23)
            | (*(unsigned __int8 *)(v14 + v24) << 8)
            | (*(unsigned __int8 *)(v14 + v25) << 16)
            | (*(unsigned __int8 *)(v14 + v26) << 24);
        if ( v27 == 17428 )
        {
          *(_DWORD *)(a1 + 20) = v28;
          if ( v20 == 80 )
            break;
        }
        else
        {
          v29 = aw9620x_i2c_write(a1, v27, v28);
          v30 = *(_QWORD *)(a1 + 48);
          if ( v29 < 0 )
          {
            dev_printk(&unk_134C0, v30, "[%s:%d] i2c write err\n", "aw9620x_load_bin", 3028);
            dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] load_bin err\n", "aw9620x_parse_def_reg_bin", 3085);
            goto LABEL_51;
          }
          dev_printk(
            &unk_13D4F,
            v30,
            "[%s:%d] reg_addr = 0x%04x, reg_data = 0x%08x\n",
            "aw9620x_load_bin",
            3034,
            v27,
            v28);
          if ( v20 == 80 )
            break;
        }
        v19 += 6;
        if ( v19 >= *(_DWORD *)(v9 + 80) )
          goto LABEL_23;
      }
    }
LABEL_48:
    __break(1u);
    goto LABEL_49;
  }
LABEL_23:
  if ( (unsigned int)aw9620x_en_active(a1) )
  {
LABEL_49:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] en_active err\n", "aw9620x_parse_def_reg_bin", 3091);
    goto LABEL_51;
  }
  kfree(v9);
  dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] load_def_reg_bin ok!!!\n", "aw9620x_parse_def_reg_bin", 3097);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] reg_bin %s load ok!\n",
    "aw9620x_load_def_reg_bin",
    3131,
    (const char *)(a1 + 763));
  result = 0;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
