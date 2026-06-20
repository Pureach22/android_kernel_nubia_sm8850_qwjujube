__int64 __fastcall enableMicroPump(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 result; // x0
  __int64 v21; // x0
  unsigned int v22; // w0
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x4
  void *v26; // x0
  __int64 v27; // x2
  unsigned int v28; // w0
  __int64 v29; // x4
  __int16 v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_97B3, "aw86320", 668, "enableMicroPump", a2, a6, a7);
  if ( a2 )
  {
    if ( (*(_DWORD *)(a1 + 24) & 0x80000000) == 0 )
    {
      printk(&unk_A59A, "aw86320", 683, "enableMicroPump", v9, v10, v11);
      v21 = gpio_to_desc(*(unsigned int *)(a1 + 24));
      gpiod_direction_output_raw(v21, 1);
    }
    aw86320_misc_para_init(a1);
    v30 = 0;
    v22 = haptic_i2c_read(a1, 1, &v30);
    if ( (v22 & 0x80000000) != 0 )
    {
      v25 = v22;
      v26 = &unk_A1EE;
      v27 = 175;
    }
    else
    {
      v28 = haptic_i2c_write(a1, 1, v30 & 0xFFCF | 0x10u);
      if ( (v28 & 0x80000000) == 0 )
      {
LABEL_12:
        printk(&unk_96B7, "aw86320", 291, "aw86320_play_mode", v29, v23, v24);
        haptic_i2c_write(a1, 27, 0xE0Eu);
        haptic_i2c_write(a1, 37, 0);
        _const_udelay(12885000);
        aw86320_interrupt_setup(a1);
        *(_QWORD *)(a1 + 608) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(a1 + 616) = a1 + 616;
        *(_QWORD *)(a1 + 624) = a1 + 616;
        *(_QWORD *)(a1 + 632) = ram_work_routine;
        init_timer_key(a1 + 640, &delayed_work_timer_fn, 0x200000, 0, 0);
        queue_delayed_work_on(32, system_wq, a1 + 608, 2000);
        result = aw86320_play_atsin0(*(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 8), *(unsigned __int16 *)(a1 + 20));
        goto LABEL_13;
      }
      v25 = v28;
      v26 = &unk_A45E;
      v27 = 184;
    }
    printk(v26, "aw86320", v27, "haptic_i2c_write_bits", v25, v23, v24);
    goto LABEL_12;
  }
  *(_DWORD *)(a1 + 16) = 0;
  printk(&unk_96B7, "aw86320", 291, "aw86320_play_mode", v9, v10, v11);
  haptic_i2c_write(a1, 27, 0xE0Eu);
  haptic_i2c_write(a1, 37, 0);
  _const_udelay(12885000);
  v15 = *(unsigned int *)(a1 + 24);
  if ( (v15 & 0x80000000) == 0 )
  {
    v16 = gpio_to_desc(v15);
    gpiod_direction_output_raw(v16, 0);
    printk(&unk_9FD5, "aw86320", 700, "enableMicroPump", v17, v18, v19);
  }
  result = printk(&unk_9D54, "aw86320", 702, "enableMicroPump", v12, v13, v14);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
