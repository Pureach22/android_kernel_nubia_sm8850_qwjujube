__int64 __fastcall vi530x_probe(__int64 *a1)
{
  __int64 **v2; // x0
  __int64 v3; // x21
  __int64 result; // x0
  __int64 *v5; // x9
  __int64 *v6; // x8
  __int64 **v7; // x20
  __int64 next_parent; // x0
  int named_gpio; // w0
  void *v10; // x0
  int v11; // w0
  int v12; // w0
  unsigned int v13; // w22
  void *v14; // x0
  __int64 *v15; // x8
  __int64 **v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 *v19; // x9
  __int64 **v20; // x8
  __int64 v21; // x9
  __int64 v22; // x0
  int v23; // w0
  int v24; // w9
  __int64 **v25; // x21
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w21
  unsigned int v29; // w0
  __int64 v30; // x0
  void (__fastcall *v31)(_QWORD); // x8
  void (__fastcall *v32)(_QWORD); // x8
  __int64 v33; // x0
  __int64 *device; // x0
  unsigned int v35; // w0
  unsigned int group; // w0
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x9
  __int64 v40; // x0
  unsigned __int64 v47; // x9
  char v48[4]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v49; // [xsp+4h] [xbp-Ch] BYREF
  char v50; // [xsp+6h] [xbp-Ah]
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_41BAC4);
  v2 = (__int64 **)_kmalloc_cache_noprof(input_register_device, 3520, 400);
  if ( !v2 )
  {
    printk(&unk_3F8437);
    result = 4294967284LL;
    goto LABEL_4;
  }
  v3 = a1[97];
  if ( !v3 )
  {
    kfree(v2);
    result = 4294967274LL;
    goto LABEL_4;
  }
  v5 = (__int64 *)a1[18];
  v6 = a1 + 4;
  if ( !v5 )
    v5 = (__int64 *)*v6;
  v2[12] = a1;
  *v2 = v6;
  v2[1] = v5;
  a1[23] = (__int64)v2;
  v7 = v2;
  _mutex_init(v2 + 33, "&vi530x_data->work_mutex", &vi530x_probe___key);
  next_parent = of_get_next_parent(v3);
  if ( next_parent )
    *((_BYTE *)v7 + 312) = of_find_property(next_parent, "qcom,pm-ctrl-client", 0) != 0;
  named_gpio = of_get_named_gpio(v3, "vi530x,pwren-gpio", 0);
  *((_DWORD *)v7 + 54) = named_gpio;
  if ( named_gpio < 0 )
  {
    v10 = &unk_432D3A;
LABEL_15:
    printk(v10);
    v13 = -19;
    v14 = &unk_417FC4;
    goto LABEL_16;
  }
  printk(&unk_3E420C);
  v11 = of_get_named_gpio(v3, "vi530x,irq-gpio", 0);
  *((_DWORD *)v7 + 52) = v11;
  if ( v11 < 0 )
  {
    v10 = &unk_43E684;
    goto LABEL_15;
  }
  printk(&unk_3E420C);
  v12 = of_get_named_gpio(v3, "vi530x,xshut-gpio", 0);
  *((_DWORD *)v7 + 53) = v12;
  if ( v12 < 0 )
  {
    v10 = &unk_432D5A;
    goto LABEL_15;
  }
  printk(&unk_41BAD3);
  v19 = v7[12];
  v20 = v7;
  if ( v19 )
  {
    v21 = v19[3];
    if ( v21 )
    {
      if ( *((_BYTE *)v7 + 312) == 1 )
      {
        v22 = *(_QWORD *)(v21 + 208);
        ++tof_i2c_open_count;
        v23 = _pm_runtime_resume(v22, 4);
        v20 = v7;
        if ( v23 < 0 )
        {
          printk(&unk_3CC265);
          v20 = v7;
        }
      }
    }
  }
  v24 = *((_DWORD *)v20 + 52);
  v48 = 0;
  v50 = 0;
  v49 = 0;
  if ( v24 < 0 || (*((_DWORD *)v20 + 53) & 0x80000000) != 0 || ((_DWORD)v20[27] & 0x80000000) != 0 )
  {
    v13 = -19;
    goto LABEL_32;
  }
  v25 = v20;
  ((void (*)(void))gpio_request)();
  gpio_request(*((unsigned int *)v25 + 53), "vi530x xshut gpio");
  gpio_request(*((unsigned int *)v25 + 52), "vi530x irq gpio");
  v26 = gpio_to_desc(*((unsigned int *)v25 + 52));
  gpiod_direction_input(v26);
  v27 = gpio_to_desc(*((unsigned int *)v25 + 52));
  v28 = gpiod_to_irq(v27);
  if ( (v28 & 0x80000000) != 0 )
  {
    printk(&unk_4004CD);
    v13 = -22;
    goto LABEL_61;
  }
  v29 = request_threaded_irq(v28, 0, vi530x_irq_handler, 8194, "vi530x_interrupt", v7);
  if ( v29 )
  {
    v13 = v29;
    printk(&unk_3EC583);
LABEL_60:
    free_irq(v28, v7);
LABEL_61:
    gpio_free(*((unsigned int *)v7 + 53));
    gpio_free(*((unsigned int *)v7 + 52));
    if ( qword_3C84B0 )
    {
      kthread_stop();
      qword_3C84B0 = 0;
    }
    v37 = (__int64)v7;
    if ( !v13 )
      goto LABEL_64;
LABEL_32:
    v14 = &unk_3F0858;
LABEL_16:
    printk(v14);
    v15 = v7[12];
    v16 = v7;
    if ( v15 )
    {
      v17 = v15[3];
      if ( v17 )
      {
        if ( *((_BYTE *)v7 + 312) == 1 )
        {
          v18 = *(_QWORD *)(v17 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v18, 4);
          v16 = v7;
        }
      }
    }
    a1[23] = 0;
    kfree(v16);
    result = v13;
    goto LABEL_4;
  }
  *((_DWORD *)v7 + 55) = v28;
  *((_BYTE *)v7 + 232) = 0;
  v30 = disable_irq(v28);
  *((_BYTE *)v7 + 233) = 0;
  vi530x_func_tbl = (__int64)vi530x_api_func_tbl;
  vi530x_setupAPIFunctions(v30);
  v31 = *(void (__fastcall **)(_QWORD))vi530x_func_tbl;
  if ( *(_DWORD *)(*(_QWORD *)vi530x_func_tbl - 4LL) != 1318018478 )
    __break(0x8228u);
  v31(v7);
  vi530x_read_multibytes(v7, 44, &v49, 3);
  vi530x_read_byte(v7, 6, &v48);
  v32 = *(void (__fastcall **)(_QWORD))(vi530x_func_tbl + 8);
  if ( *((_DWORD *)v32 - 1) != 1318018478 )
    __break(0x8228u);
  v32(v7);
  if ( v48 != 216 )
  {
    printk(&unk_3F0873);
    v13 = -14;
    goto LABEL_60;
  }
  v33 = printk(&unk_3E7F1C);
  device = (__int64 *)input_allocate_device(v33);
  v7[13] = device;
  if ( !device )
  {
    printk(&unk_3E0127);
    v13 = 0;
    goto LABEL_60;
  }
  *device = (__int64)"vi530x";
  *((_WORD *)v7[13] + 12) = 24;
  v7[13][89] = (__int64)v7;
  _X8 = (unsigned __int64 *)(v7[13] + 5);
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 | 8, _X8) );
  input_set_abs_params(v7[13], 16, 0, 0xFFFFFFFFLL, 0, 0);
  input_set_abs_params(v7[13], 17, 0, 255, 0, 0);
  input_set_abs_params(v7[13], 18, 0, 0xFFFFFFFFLL, 0, 0);
  input_set_abs_params(v7[13], 19, 0, 0xFFFFFFFFLL, 0, 0);
  input_set_abs_params(v7[13], 20, 0, 0xFFFFFFFFLL, 0, 0);
  v35 = input_register_device(v7[13]);
  if ( v35 )
  {
    v13 = v35;
    printk(&unk_3F432E);
LABEL_59:
    input_free_device(v7[13]);
    goto LABEL_60;
  }
  group = sysfs_create_group(v7[13] + 70, &vi530x_attr_group);
  if ( group )
  {
    v13 = group;
    printk(&unk_403DFC);
LABEL_58:
    input_unregister_device(v7[13]);
    goto LABEL_59;
  }
  if ( (unsigned int)sysfs_create_bin_file(v7[13] + 70, &vi530x_xtalk_data_attr) )
  {
    printk(&unk_3F08B8);
LABEL_57:
    sysfs_remove_group(v7[13] + 70, &vi530x_attr_group);
    v13 = -12;
    goto LABEL_58;
  }
  if ( (unsigned int)sysfs_create_bin_file(v7[13] + 70, &vi530x_offset_data_attr) )
  {
    printk(&unk_3F08B8);
    goto LABEL_56;
  }
  *((_DWORD *)v7 + 28) = 255;
  v7[15] = (__int64 *)"vi530x";
  v7[16] = (__int64 *)&vi530x_fops;
  if ( (unsigned int)((__int64 (*)(void))misc_register)()
    || (*((_DWORD *)v7 + 80) = 255,
        v7[41] = (__int64 *)"v4l-subdev_tof",
        v7[42] = (__int64 *)&vi530x_tof_fops,
        (unsigned int)misc_register(v7 + 40)) )
  {
    printk(&unk_43A8D4);
    sysfs_remove_bin_file(v7[13] + 70, &vi530x_offset_data_attr);
LABEL_56:
    sysfs_remove_bin_file(v7[13] + 70, &vi530x_xtalk_data_attr);
    goto LABEL_57;
  }
  *((_BYTE *)v7 + 234) = 0;
  dword_3C84D0 = 0;
  qword_3C84B8 = 0;
  qword_3C84C0 = (__int64)&qword_3C84C0;
  qword_3C84C8 = (__int64)&qword_3C84C0;
  v37 = (__int64)v7;
  *((_DWORD *)v7 + 63) = 30;
  *((_WORD *)v7 + 118) = 0;
  *((_DWORD *)v7 + 57) = 0;
LABEL_64:
  v38 = *(_QWORD *)(v37 + 96);
  if ( v38 )
  {
    v39 = *(_QWORD *)(v38 + 24);
    if ( v39 )
    {
      if ( *(_BYTE *)(v37 + 312) == 1 )
      {
        v40 = *(_QWORD *)(v39 + 208);
        --tof_i2c_open_count;
        _pm_runtime_idle(v40, 4);
        v37 = (__int64)v7;
      }
    }
  }
  result = 0;
  tof_ctl = v37;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
