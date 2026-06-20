__int64 __fastcall aw22xxx_effect_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x22
  unsigned int v6; // w3
  __int64 v7; // x0
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  char v10[4]; // [xsp+10h] [xbp-10h] BYREF
  char v11[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( sscanf(s, "%x", &v9) == 1 )
  {
    mutex_lock(v5 + 672);
    v6 = v9;
    if ( (unsigned int)(v9 - 8) <= 2 && init_flag == 1 )
    {
      printk(&unk_12DD4, "aw22xxx_effect_store");
      *(_DWORD *)(v5 + 752) = 4;
      aw22xxx_get_fwname(4);
      aw22xxx_cfg_update_wait_from_dyn_name(v5 - 16);
      aw22xxx_set_cfg_run_state(*(unsigned int *)(v5 + 752));
      printk(&unk_136FD, "aw22xxx_effect_store");
      if ( !g_cfg_cur_state )
      {
        printk(&unk_13C1D, "aw22xxx_chip_enable");
        v10[0] = 0;
        aw22xxx_i2c_read((_QWORD *)(v5 - 16), 2, v10);
        v10[0] &= ~1u;
        aw22xxx_i2c_write((__int64 *)(v5 - 16), 2, v10[0]);
        usleep_range_state(2000, 3000, 2);
        g_init_flg = 0;
      }
      init_flag = 0;
      printk(&unk_13E40, "aw22xxx_effect_store");
      v6 = v9;
    }
    *(_DWORD *)(v5 + 752) = v6;
    if ( v6 <= 3 && v6 != 1 && (init_flag & 1) == 0 )
    {
      init_flag = 1;
      printk(&unk_137FD, "aw22xxx_effect_store");
    }
    printk(&unk_140CB, "aw22xxx_effect_store");
    aw22xxx_get_fwname(*(unsigned int *)(v5 + 752));
    v9 = 1;
    aw22xxx_cfg_update_wait_from_dyn_name(v5 - 16);
    v7 = *(unsigned int *)(v5 + 752);
    if ( !(_DWORD)v7 )
    {
      msleep(100);
      v7 = *(unsigned int *)(v5 + 752);
    }
    aw22xxx_set_cfg_run_state(v7);
    printk(&unk_136FD, "aw22xxx_effect_store");
    if ( !g_cfg_cur_state )
    {
      printk(&unk_13C1D, "aw22xxx_chip_enable");
      v11[0] = 0;
      aw22xxx_i2c_read((_QWORD *)(v5 - 16), 2, v11);
      v11[0] &= ~1u;
      aw22xxx_i2c_write((__int64 *)(v5 - 16), 2, v11[0]);
      usleep_range_state(2000, 3000, 2);
      g_init_flg = 0;
    }
    mutex_unlock(v5 + 672);
  }
  else
  {
    printk(&unk_12D0C, "aw22xxx_effect_store");
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
