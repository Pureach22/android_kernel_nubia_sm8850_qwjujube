__int64 __fastcall aw9620x_flash_update(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w8
  unsigned int v5; // w21
  int v6; // w0
  __int64 v7; // x1
  unsigned int v8; // w23
  int v9; // w25
  __int64 v10; // x22
  int v11; // w21
  unsigned int v12; // w21
  int v13; // w0
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x23
  unsigned int v17; // w21
  int v18; // w0
  __int64 v19; // x1
  unsigned int v20; // w22
  int v21; // w0
  __int64 v22; // x1
  int v23; // w0
  __int64 v24; // x1
  unsigned int bin_checksum; // w23
  int v26; // w0
  __int64 v27; // x1
  int v28; // w8
  const char *v29; // x5
  __int64 result; // x0
  int v31; // w22
  int v32; // w4
  int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] enter read_len = %d\n",
    "aw9620x_flash_update",
    1455,
    *((_DWORD *)a2 + 4));
  dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 1.opne register access enable\n", "aw9620x_flash_update", 1458);
  if ( (unsigned int)aw9620x_i2c_write(a1, 65312, 1006698495) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_flash_update", 1461);
LABEL_51:
    result = 0xFFFFFFFFLL;
    goto LABEL_52;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 17476, 0x10000) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 0x4444 write 0x10000 err\n", "aw9620x_flash_update", 1466);
    goto LABEL_51;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 18464, 6) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 0x4820 write 0x6 err\n", "aw9620x_flash_update", 1471);
    goto LABEL_51;
  }
  if ( *a2 == 1 && (unsigned int)aw9620x_i2c_write(a1, 18324, 1516468565) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4794 err\n", "aw9620x_flash_update", 1477);
    goto LABEL_51;
  }
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 2.Erase sector (0x3800~0x37ff)\n", "aw9620x_flash_update", 1482);
  v4 = **((_DWORD **)a2 + 3);
  if ( (v4 & 0x7F) != 0 )
    v5 = (v4 >> 7) + 1;
  else
    v5 = v4 >> 7;
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] enter temp = %d erase_cnt = %d\n",
    "aw9620x_erase_sector",
    1372,
    (**((_DWORD **)a2 + 3) & 0x7F) != 0,
    v5);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 1.open host write FMC protect\n", "aw9620x_erase_sector", 1375);
  if ( (unsigned int)aw9620x_i2c_write(a1, 65312, 1006694801) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_erase_sector", 1378);
LABEL_50:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] erase_sector_main err\n", "aw9620x_flash_update", 1485);
    goto LABEL_51;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 18464, 6) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_erase_sector", 1384);
    goto LABEL_50;
  }
  if ( !*a2 && (unsigned int)aw9620x_i2c_write(a1, 18324, 1516468565) )
  {
    dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4794 err\n", "aw9620x_erase_sector", 1391);
    goto LABEL_50;
  }
  if ( v5 )
  {
    v31 = 0;
    while ( 1 )
    {
      if ( (unsigned int)aw9620x_i2c_write(a1, 18180, (unsigned int)(v31 + *(_DWORD *)(*((_QWORD *)a2 + 3) + 4LL))) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4794 err\n", "aw9620x_erase_sector", 1401);
        goto LABEL_50;
      }
      if ( (unsigned int)aw9620x_i2c_write(a1, 18192, 5) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4710 err\n", "aw9620x_erase_sector", 1407);
        goto LABEL_50;
      }
      if ( (unsigned int)aw9620x_i2c_write(a1, 18220, 240) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x472c err\n", "aw9620x_erase_sector", 1413);
        goto LABEL_50;
      }
      if ( (unsigned int)aw9620x_i2c_write(a1, 18196, 1) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4714 err\n", "aw9620x_erase_sector", 1419);
        goto LABEL_50;
      }
      if ( (unsigned int)aw9620x_check_isp_go_reg(a1) )
        break;
      --v5;
      v31 += 128;
      if ( !v5 )
        goto LABEL_14;
    }
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] check_isp_go_reg err\n", "aw9620x_erase_sector", 1425);
    goto LABEL_50;
  }
LABEL_14:
  if ( (unsigned int)aw9620x_i2c_write(a1, 18220, 22) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x472c err\n", "aw9620x_erase_sector", 1431);
    goto LABEL_50;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 18464, 4) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4820 err\n", "aw9620x_erase_sector", 1437);
    goto LABEL_50;
  }
  v6 = aw9620x_i2c_write(a1, 65312, 1006694417);
  v7 = *(_QWORD *)(a1 + 48);
  if ( v6 )
  {
    dev_printk(&unk_134C0, v7, "[%s:%d] write 0xff20 err\n", "aw9620x_erase_sector", 1443);
    goto LABEL_50;
  }
  dev_printk(&unk_142BB, v7, "[%s:%d] 3.write boot\n", "aw9620x_flash_update", 1490);
  v8 = *((_DWORD *)a2 + 4);
  v9 = *((_DWORD *)a2 + 5);
  v10 = *((_QWORD *)a2 + 1);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_reg_write_bin_to_flash", 1329);
  v11 = *a2;
  if ( (unsigned int)aw9620x_i2c_write(a1, 65312, 1006694801) )
  {
    v32 = 1094;
LABEL_72:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_close_write_flash_protect", v32);
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] close_write_flash_protect err\n",
      "aw9620x_reg_write_bin_to_flash",
      1333);
LABEL_73:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] erase_sector_main err\n", "aw9620x_flash_update", 1493);
    goto LABEL_51;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 18464, 6) )
  {
    v32 = 1101;
    goto LABEL_72;
  }
  if ( !v11 && (unsigned int)aw9620x_i2c_write(a1, 18324, 1516468565) )
  {
    v32 = 1109;
    goto LABEL_72;
  }
  if ( v8 )
  {
    v12 = 0;
    while ( !(unsigned int)aw9620x_reg_write_to_flash_once(
                             a1,
                             v9 + v12,
                             (*(unsigned __int8 *)(v10 + v12 + 3) << 24)
                           | (*(unsigned __int8 *)(v10 + v12 + 2) << 16)
                           | (*(unsigned __int8 *)(v10 + v12 + 1) << 8)
                           | (unsigned int)*(unsigned __int8 *)(v10 + v12)) )
    {
      v12 += 4;
      if ( v12 >= v8 )
        goto LABEL_25;
    }
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] write aw9620x_reg_write_bin_once err\n",
      "aw9620x_reg_write_bin_to_flash",
      1343);
    goto LABEL_73;
  }
LABEL_25:
  if ( (unsigned int)aw9620x_i2c_write(a1, 18464, 4) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4820 err\n", "aw9620x_reg_write_bin_to_flash", 1351);
    goto LABEL_73;
  }
  v13 = aw9620x_i2c_write(a1, 65312, 1006694417);
  v14 = *(_QWORD *)(a1 + 48);
  if ( v13 )
  {
    dev_printk(&unk_134C0, v14, "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_bin_to_flash", 1357);
    goto LABEL_73;
  }
  dev_printk(&unk_142BB, v14, "[%s:%d] 4.read data check\n", "aw9620x_flash_update", 1498);
  v15 = *(_QWORD *)(a1 + 48);
  v16 = *((_QWORD *)a2 + 1);
  v17 = *((_DWORD *)a2 + 4);
  v33 = 0;
  dev_printk(&unk_142BB, v15, "[%s:%d] enter\n", "aw9620x_rd_or_wi_cmp", 1274);
  if ( (unsigned int)aw9620x_i2c_write(a1, 65312, 1006694801) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_rd_or_wi_cmp", 1279);
LABEL_83:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] reg_read_bin err\n", "aw9620x_flash_update", 1504);
    goto LABEL_51;
  }
  v18 = aw9620x_i2c_write(a1, 18464, 4);
  v19 = *(_QWORD *)(a1 + 48);
  if ( v18 )
  {
    dev_printk(&unk_134C0, v19, "[%s:%d] config PMU_CFG reg err\n", "aw9620x_rd_or_wi_cmp", 1285);
    goto LABEL_83;
  }
  dev_printk(&unk_134C0, v19, "[%s:%d] read_cnt = %d\n", "aw9620x_rd_or_wi_cmp", 1289, v17);
  if ( v17 )
  {
    v20 = 0;
    while ( 1 )
    {
      if ( (unsigned int)aw9620x_reg_read_val(a1, &v33, v20 + *((_DWORD *)a2 + 5)) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] reg_read_bin err\n", "aw9620x_rd_or_wi_cmp", 1294);
        goto LABEL_83;
      }
      if ( ((*(unsigned __int8 *)(v16 + v20 + 3) << 24)
          | (*(unsigned __int8 *)(v16 + v20 + 2) << 16)
          | (*(unsigned __int8 *)(v16 + v20 + 1) << 8)
          | *(unsigned __int8 *)(v16 + v20)) != v33 )
        break;
      v20 += 4;
      if ( v20 >= v17 )
        goto LABEL_34;
    }
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] w_data != r_data err!\n", "aw9620x_rd_or_wi_cmp", 1303);
    goto LABEL_83;
  }
LABEL_34:
  v21 = aw9620x_i2c_write(a1, 65312, 1006694417);
  v22 = *(_QWORD *)(a1 + 48);
  if ( v21 )
  {
    dev_printk(&unk_134C0, v22, "[%s:%d] write 0xff20 err\n", "aw9620x_rd_or_wi_cmp", 1310);
    goto LABEL_83;
  }
  dev_printk(&unk_142BB, v22, "[%s:%d] END\n", "aw9620x_rd_or_wi_cmp", 1314);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 5.write checksum\n", "aw9620x_flash_update", 1509);
  v23 = aw9620x_reg_write_val_to_flash(a1, *(unsigned int *)(*((_QWORD *)a2 + 3) + 8LL), 539107362, a2);
  v24 = *(_QWORD *)(a1 + 48);
  if ( v23 )
  {
    dev_printk(&unk_134C0, v24, "[%s:%d] write checksum en err\n", "aw9620x_flash_update", 1513);
    goto LABEL_51;
  }
  dev_printk(&unk_142BB, v24, "[%s:%d] write checksum en ok\n", "aw9620x_flash_update", 1516);
  bin_checksum = aw9620x_get_bin_checksum(*((_QWORD *)a2 + 1), *((unsigned int *)a2 + 4), **((unsigned int **)a2 + 3));
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] check_sum = 0x%x\n", "aw9620x_flash_update", 1521, bin_checksum);
  v26 = aw9620x_reg_write_val_to_flash(a1, *(unsigned int *)(*((_QWORD *)a2 + 3) + 12LL), bin_checksum, a2);
  v27 = *(_QWORD *)(a1 + 48);
  if ( v26 )
  {
    dev_printk(&unk_134C0, v27, "[%s:%d] 5.write checksum err\n", "aw9620x_flash_update", 1525);
    goto LABEL_51;
  }
  dev_printk(&unk_142BB, v27, "[%s:%d] 5.write checksum ok\n", "aw9620x_flash_update", 1528);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 6.open flash protect\n", "aw9620x_flash_update", 1531);
  v28 = *a2;
  if ( v28 == 1 )
  {
    if ( (unsigned int)aw9620x_i2c_write(a1, 18324, 0) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 6.open flash protect err\n", "aw9620x_flash_update", 1535);
      goto LABEL_51;
    }
    v28 = *a2;
  }
  if ( v28 )
    v29 = "fw";
  else
    v29 = "bt";
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] %s update success!!!\n", "aw9620x_flash_update", 1547, v29);
  result = 0;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
