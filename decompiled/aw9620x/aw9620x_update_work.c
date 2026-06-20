__int64 __fastcall aw9620x_update_work(__int64 a1)
{
  _BYTE *v2; // x19
  _QWORD *v3; // x23
  unsigned int v4; // w8
  __int64 v5; // x1
  __int64 v6; // x1
  _QWORD *v7; // x22
  unsigned __int64 v8; // x26
  int *v9; // x8
  int v10; // w23
  int v11; // w24
  bool v12; // cf
  int updated; // w0
  __int64 v14; // x1
  __int64 result; // x0
  __int64 v16; // x1
  int v17; // w0
  __int64 v18; // x1
  int chipid; // w0
  __int64 v20; // x1
  int init_over_irq; // w0
  __int64 v22; // x1
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v2 = (_BYTE *)(a1 - 520);
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&aw_lock);
  v3 = (_QWORD *)(a1 - 472);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 - 472), "[%s:%d] enter\n", "aw9620x_update_work", 3349);
  v4 = *(unsigned __int8 *)(a1 - 514);
  if ( v4 > 2 )
  {
    if ( v4 == 3 )
      goto LABEL_8;
    if ( v4 == 5 )
    {
LABEL_20:
      updated = aw9620x_reg_update_boot_work(v2);
      v14 = *v3;
      if ( updated )
      {
        dev_printk(&unk_134C0, v14, "[%s:%d] reg_update_boot err\n", "aw9620x_update_work", 3382);
        goto LABEL_29;
      }
      dev_printk(&unk_142BB, v14, "[%s:%d] reg_update_boot ok\n", "aw9620x_update_work", 3385);
      *(_BYTE *)(a1 - 517) = 1;
      if ( (unsigned int)aw9620x_load_frimware_work((__int64)v2) )
      {
        dev_printk(&unk_134C0, *v3, "[%s:%d] reg frimware load err!\n", "aw9620x_update_work", 3392);
        goto LABEL_29;
      }
      if ( (unsigned int)aw9620x_recover_fun(v2, 0) )
      {
        dev_printk(&unk_134C0, *v3, "[%s:%d] recover_fun err\n", "aw9620x_update_work", 3398);
        goto LABEL_29;
      }
      if ( (unsigned int)aw9620x_soft_reset(v2) )
      {
        dev_printk(&unk_134C0, *v3, "[%s:%d] soft_reset err\n", "aw9620x_update_work", 3403);
        goto LABEL_29;
      }
      if ( (unsigned int)aw9620x_read_chipid(v2) )
      {
        dev_printk(&unk_134C0, *v3, "[%s:%d] read_chipid err\n", "aw9620x_update_work", 3410);
        goto LABEL_29;
      }
      if ( (unsigned int)aw9620x_read_init_over_irq(v2) )
      {
        dev_printk(&unk_134C0, *v3, "[%s:%d] init_over_irq err\n", "aw9620x_update_work", 3416);
        goto LABEL_29;
      }
      goto LABEL_9;
    }
LABEL_28:
    dev_printk(&unk_142BB, *v3, "[%s:%d] aw9620x->init_err_flag error\n", "aw9620x_update_work", 3421);
    goto LABEL_29;
  }
  if ( !*(_BYTE *)(a1 - 514) )
    goto LABEL_8;
  if ( v4 != 2 )
    goto LABEL_28;
  dev_printk(&unk_134C0, *v3, "[%s:%d] enter\n", "aw9620x_error_chipid_handle", 1004);
  v5 = *v3;
  v23 = 0;
  dev_printk(&unk_142BB, v5, "[%s:%d] enter\n", "aw9620x_check_chipid", 843);
  if ( (aw9620x_reg_read_all_val(v2, &v23, 16784) & 0x80000000) != 0 )
  {
    dev_printk(&unk_134C0, *v3, "[%s:%d] read chipid err\n", "aw9620x_check_chipid", 848);
LABEL_6:
    dev_printk(&unk_134C0, *v3, "[%s:%d] nvr chipid err!\n", "aw9620x_error_chipid_handle", 1027);
    goto LABEL_29;
  }
  v16 = *v3;
  switch ( v23 )
  {
    case 539124232:
      dev_printk(&unk_142BB, v16, "[%s:%d] AW96208CSR check CHIP ID : 0x%08X\n", "aw9620x_check_chipid", 860, 539124232);
      break;
    case 539124229:
      dev_printk(&unk_142BB, v16, "[%s:%d] AW96205DNR check CHIP ID : 0x%08X\n", "aw9620x_check_chipid", 857, 539124229);
      break;
    case 539124227:
      dev_printk(&unk_142BB, v16, "[%s:%d] AW96203CSR check CHIP ID : 0x%08X\n", "aw9620x_check_chipid", 854, 539124227);
      break;
    default:
      dev_printk(&unk_142BB, v16, "[%s:%d] check chipid error, CHIP ID : 0x%08x\n", "aw9620x_check_chipid", 863, v23);
      goto LABEL_6;
  }
  dev_printk(&unk_134C0, *v3, "[%s:%d] update boot\n", "aw9620x_error_chipid_handle", 1007);
  v17 = aw9620x_reg_update_boot_work(v2);
  v18 = *v3;
  if ( v17 )
  {
    dev_printk(
      &unk_134C0,
      v18,
      "[%s:%d] update_boot_to_flash failed :%d\n",
      "aw9620x_error_chipid_handle",
      1023,
      0xFFFFFFFFLL);
    goto LABEL_29;
  }
  dev_printk(&unk_134C0, v18, "[%s:%d] update boot to flash update fw ok!!!\n", "aw9620x_error_chipid_handle", 1010);
  if ( (unsigned int)aw9620x_soft_reset(v2) )
  {
    dev_printk(&unk_134C0, *v3, "[%s:%d] soft_reset failed :%d\n", "aw9620x_error_chipid_handle", 1013, 0xFFFFFFFFLL);
    goto LABEL_29;
  }
  chipid = aw9620x_read_chipid(v2);
  v20 = *v3;
  if ( chipid )
  {
    dev_printk(
      &unk_134C0,
      v20,
      "[%s:%d] after update boot, read chipid failed, ret=%d, \n",
      "aw9620x_error_chipid_handle",
      1020,
      chipid);
    goto LABEL_29;
  }
  dev_printk(&unk_142BB, v20, "[%s:%d] after update boot, read chipid ok!\n", "aw9620x_error_chipid_handle", 1018);
  init_over_irq = aw9620x_read_init_over_irq(v2);
  v22 = *v3;
  if ( init_over_irq == -3 )
  {
    dev_printk(&unk_134C0, v22, "[%s:%d] _read_init_over_irq, ret=%d, \n", "aw9620x_update_work", 3361, -3);
    aw9620x_get_err_info(v2);
  }
  else
  {
    if ( init_over_irq == -1 )
    {
      dev_printk(&unk_134C0, v22, "[%s:%d] read chipid failed\n", "aw9620x_update_work", 3358);
      goto LABEL_29;
    }
    dev_printk(&unk_134C0, v22, "[%s:%d] read_init_over_irq ok!\n", "aw9620x_update_work", 3364);
  }
LABEL_8:
  *(_BYTE *)(a1 - 517) = 0;
  if ( (unsigned int)aw9620x_load_frimware_work((__int64)v2) )
  {
    dev_printk(&unk_134C0, *v3, "[%s:%d] frimware load err!\n", "aw9620x_update_work", 3376);
    goto LABEL_20;
  }
LABEL_9:
  if ( *v2 == 1 )
  {
    v6 = *v3;
    v7 = (_QWORD *)(a1 - 472);
    *v2 = 0;
    dev_printk(&unk_142BB, v6, "[%s:%d] start to download para!\n", "aw9620x_para_loaded", 2982);
    v8 = 0;
    *(_BYTE *)(a1 - 516) = 1;
    do
    {
      if ( v8 == 200 )
      {
        *(_DWORD *)(a1 - 500) = 15;
      }
      else
      {
        v9 = (int *)((char *)&aw9620x_reg_default + 4 * v8);
        v10 = *v9;
        v11 = v9[1];
        aw9620x_i2c_write((__int64)v2, *v9, v11);
        dev_printk(
          &unk_13D4F,
          *v7,
          "[%s:%d] reg_addr = 0x%04x, reg_data = 0x%08x\n",
          "aw9620x_para_loaded",
          2996,
          v10,
          v11);
      }
      v12 = v8 >= 0xDE;
      v8 += 2LL;
    }
    while ( !v12 );
    aw9620x_en_active(v2);
    dev_printk(&unk_13D4F, *v7, "[%s:%d] para writen completely\n", "aw9620x_para_loaded", 3001);
  }
  else if ( (unsigned int)aw9620x_load_def_reg_bin(v2) )
  {
    dev_printk(&unk_134C0, *v3, "[%s:%d] reg_bin load err!\n", "aw9620x_update_work", 3432);
  }
LABEL_29:
  result = mutex_unlock(&aw_lock);
  _ReadStatusReg(SP_EL0);
  return result;
}
