__int64 __fastcall aw_i2c_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v8; // x22
  __int64 (*v9)(void); // x8
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x23
  unsigned int named_gpio; // w0
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x19
  unsigned int v21; // w0
  __int64 v22; // x4
  unsigned int v23; // w23
  __int64 v24; // x6
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  unsigned int v28; // w20
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x0
  unsigned int v32; // w0
  __int64 v33; // x5
  __int64 v34; // x6
  _BOOL8 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  _BOOL8 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  unsigned int v47; // w0
  __int64 v48; // x5
  __int64 v49; // x6
  unsigned int v50; // w20
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x4
  __int64 v54; // x0
  __int64 v55; // x5
  __int64 v56; // x6
  __int64 v57; // x4
  __int64 v58; // x2
  __int64 v59; // x3
  __int64 v60; // x4
  __int64 v61; // x5
  __int64 v62; // x6
  __int64 v63; // x4
  __int64 v64; // x5
  __int64 v65; // x6
  __int64 v66; // x0
  unsigned __int16 v67; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v68; // [xsp+8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 776);
  printk(&unk_A4E8, "aw86320", "aw_i2c_probe", a4, a5, a6, a7);
  v9 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL) + 32LL);
  if ( *((_DWORD *)v9 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v9() & 1) == 0 )
  {
    printk(&unk_9994, "aw86320", "aw_i2c_probe", v10, v11, v12, v13);
    result = 4294967291LL;
    goto LABEL_6;
  }
  v14 = devm_kmalloc(a1 + 32, 888, 3520);
  if ( v14 )
  {
    *(_QWORD *)(v14 + 480) = a1 + 32;
    *(_QWORD *)(v14 + 488) = a1;
    *(_QWORD *)(a1 + 184) = v14;
    v16 = v14;
    named_gpio = of_get_named_gpio(v8, "power-en", 0);
    v20 = v16;
    *(_DWORD *)(v16 + 24) = named_gpio;
    if ( (named_gpio & 0x80000000) != 0 )
    {
      printk(&unk_97D1, "aw86320", 617, "aw86320_parse_dt", named_gpio, v18, v19);
      *(_DWORD *)(v16 + 24) = -22;
    }
    else
    {
      v21 = gpio_request(named_gpio, "awp86320_power_en");
      v22 = *(unsigned int *)(v16 + 24);
      v23 = v21;
      printk(&unk_9807, "aw86320", 622, "aw86320_parse_dt", v22, v21, v24);
      if ( (v23 & 0x80000000) != 0 )
      {
        v28 = v23;
        printk(&unk_98FA, "aw86320", 624, "aw86320_parse_dt", *(unsigned int *)(v20 + 24), v23, v27);
        *(_DWORD *)(v20 + 24) = -22;
        goto LABEL_13;
      }
      printk(&unk_9BB9, "aw86320", 628, "aw86320_parse_dt", v25, v26, v27);
      v31 = gpio_to_desc(*(unsigned int *)(v20 + 24));
      gpiod_direction_output_raw(v31, 1);
      v32 = of_get_named_gpio(v8, "irq-gpio", 0);
      *(_DWORD *)(v20 + 4) = v32;
      if ( (v32 & 0x80000000) == 0 )
      {
        printk(&unk_A391, "aw86320", 640, "aw86320_parse_dt", v32, v33, v34);
        *(_QWORD *)(v20 + 8) = 0x3FF00000050LL;
        *(_WORD *)(v20 + 20) = 450;
        printk(&unk_A0E0, "aw86320", 646, "aw86320_parse_dt", 1023, 80, 450);
        v35 = of_find_property(v8, "is_fifo_method_play", 0) != 0;
        *(_BYTE *)(v20 + 837) = v35;
        printk(&unk_A4F9, "aw86320", 649, "aw86320_parse_dt", v35, v36, v37);
        v38 = of_find_property(v8, "is_reg_method_play", 0) != 0;
        *(_BYTE *)(v20 + 838) = v38;
        printk(&unk_A11A, "aw86320", 652, "aw86320_parse_dt", v38, v39, v40);
        if ( (of_property_read_variable_u32_array(v8, "atsin0_polor", v20 + 840, 1, 0) & 0x80000000) != 0 )
          printk(&unk_A487, "aw86320", 656, "aw86320_parse_dt", v41, v42, v43);
        if ( (of_property_read_variable_u32_array(v8, "atsin0_phase", v20 + 844, 1, 0) & 0x80000000) != 0 )
          printk(&unk_9F3D, "aw86320", 659, "aw86320_parse_dt", v44, v45, v46);
        if ( (unsigned int)devm_request_threaded_irq(
                             a1 + 32,
                             *(unsigned int *)(a1 + 948),
                             0,
                             irq_handle,
                             8194,
                             "aw86320",
                             v20) )
          dev_err(a1 + 32, "Unable to request IRQ.\n");
        v67 = 0;
        haptic_i2c_write(v20, 0, 0xAAAAu);
        usleep_range_state(3000, 3500, 2);
        v47 = haptic_i2c_read(v20, 0, &v67);
        if ( (v47 & 0x80000000) != 0 )
        {
          printk(&unk_9B13, "aw86320", 205, "read_chipid", v47, v48, v49);
          v50 = -5;
          printk(&unk_A3C0, "aw86320", 222, "parse_chipid", 4294967291LL, v51, v52);
        }
        else
        {
          v50 = v47;
        }
        v53 = v67;
        if ( v67 == 24615 )
        {
          *(_WORD *)(v20 + 2) = 24615;
          g_chip_id = 0x30323336387761LL;
          v54 = printk(&unk_9747, "aw86320", 227, "parse_chipid", v53, v48, v49);
          v57 = v50;
          if ( (v50 & 0x80000000) == 0 )
          {
            g_aw86320 = v20;
            create_pump_proc_entry(v54);
            _mutex_init(v20 + 496, "&aw_haptic->lock", &aw_i2c_probe___key);
            aw86320_misc_para_init(v20);
            haptic_i2c_write_bits(v20, 1, 4294967247LL, 16);
            aw86320_play_mode((_BYTE *)v20, 0, v58, v59, v60, v61, v62);
            aw86320_interrupt_setup(v20);
            ram_work_init(v20);
            printk(&unk_A006, "aw86320", 1132, "aw_i2c_probe", v63, v64, v65);
            enableMicroPump(v20, 0);
            result = 0;
            goto LABEL_6;
          }
        }
        else
        {
          printk(&unk_9ADF, "aw86320", 230, "parse_chipid", v67, v48, v49);
          usleep_range_state(2000, 2500, 2);
          v57 = 4294967274LL;
        }
        v28 = v57;
        printk(&unk_9AB3, "aw86320", 1114, "aw_i2c_probe", v57, v55, v56);
        v66 = gpio_to_desc(*(unsigned int *)(v20 + 24));
        gpiod_direction_output_raw(v66, 0);
        if ( (*(_DWORD *)(v20 + 24) & 0x80000000) != 0 )
          goto LABEL_15;
        goto LABEL_14;
      }
      printk(&unk_9F0A, "aw86320", 636, "aw86320_parse_dt", v32, v33, v34);
      *(_DWORD *)(v20 + 4) = -22;
    }
    v28 = -517;
LABEL_13:
    printk(&unk_9CF0, "aw86320", 1098, "aw_i2c_probe", v28, v29, v30);
    if ( (*(_DWORD *)(v20 + 24) & 0x80000000) != 0 )
    {
LABEL_15:
      result = v28;
      goto LABEL_6;
    }
LABEL_14:
    gpio_free();
    *(_DWORD *)(v20 + 24) = -22;
    goto LABEL_15;
  }
  result = 4294967284LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
