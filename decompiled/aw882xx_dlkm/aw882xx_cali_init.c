__int64 __fastcall aw882xx_cali_init(__int64 a1)
{
  __int64 **v1; // x21
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x1
  char v6; // w8
  __int64 *v7; // x9
  __int64 v8; // x1
  __int64 *v9; // x8
  __int64 v10; // x1
  int v11; // w0
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 v16; // x1
  void *v17; // x0
  __int64 result; // x0
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  int v26; // [xsp+Ch] [xbp-14h] BYREF
  char *s1[2]; // [xsp+10h] [xbp-10h] BYREF

  v1 = (__int64 **)(a1 - 536);
  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 536);
  *(_QWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_BYTE *)a1 = 0;
  v4 = *(_QWORD *)(v3 + 744);
  s1[0] = nullptr;
  v26 = 0;
  if ( (of_property_read_variable_u32_array(v4, "aw-cali-check", &v26, 1, 0) & 0x80000000) != 0 )
  {
    v5 = (*v1)[14];
    if ( !v5 )
      v5 = **v1;
    printk(&unk_2886D, v5, "aw_cali_parse_dt");
    v6 = 0;
    v26 = 0;
  }
  else
  {
    v6 = v26;
  }
  v7 = *v1;
  *(_BYTE *)(a1 + 17) = v6;
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_24E75, v8, "aw_cali_parse_dt");
  if ( (of_property_read_string(v4, "aw-cali-mode", s1) & 0x80000000) != 0 )
  {
    v9 = *v1;
    *(_BYTE *)(a1 + 1) = 1;
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_22699, v10, "aw_cali_parse_dt");
  }
  else
  {
    v11 = strcmp(s1[0], "none");
    v12 = *v1;
    *(_BYTE *)(a1 + 1) = v11 != 0;
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    printk(&unk_261C8, v13, "aw_cali_parse_dt");
  }
  v14 = *v1;
  v15 = (*v1)[14];
  if ( *(_BYTE *)(a1 + 1) == 1 )
  {
    if ( !v15 )
      v15 = *v14;
    printk(&unk_26EB3, v15, "aw_cali_attr_init");
    if ( (sysfs_create_group(*v1, &aw_cali_attr_group) & 0x80000000) != 0 )
    {
      v19 = (*v1)[14];
      if ( !v19 )
        v19 = **v1;
      printk(&unk_22F71, v19, "aw_cali_attr_init");
    }
    if ( *(_DWORD *)(a1 - 596) )
    {
      v16 = (*v1)[14];
      if ( !v16 )
        v16 = **v1;
      v17 = &unk_27C4E;
      goto LABEL_46;
    }
    if ( (class_register(&aw_cali_class) & 0x80000000) != 0 )
    {
      v16 = (*v1)[14];
      if ( !v16 )
        v16 = **v1;
      v17 = &unk_24BBD;
      goto LABEL_46;
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_attr_re25_calib, 0) )
    {
      v20 = (*v1)[14];
      if ( !v20 )
        v20 = **v1;
      printk(&unk_24F21, v20, "aw_cali_class_attr_init");
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_attr_f0_calib, 0) )
    {
      v21 = (*v1)[14];
      if ( !v21 )
        v21 = **v1;
      printk(&unk_24F21, v21, "aw_cali_class_attr_init");
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_attr_cali_time, 0) )
    {
      v22 = (*v1)[14];
      if ( !v22 )
        v22 = **v1;
      printk(&unk_2859D, v22, "aw_cali_class_attr_init");
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_attr_re_show, 0) )
    {
      v23 = (*v1)[14];
      if ( !v23 )
        v23 = **v1;
      printk(&unk_24686, v23, "aw_cali_class_attr_init");
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_attr_f0_show, 0) )
    {
      v24 = (*v1)[14];
      if ( !v24 )
        v24 = **v1;
      printk(&unk_288C4, v24, "aw_cali_class_attr_init");
    }
    if ( (unsigned int)class_create_file_ns(&aw_cali_class, &class_att_re_range, 0) )
    {
      v16 = (*v1)[14];
      if ( !v16 )
        v16 = **v1;
      v17 = &unk_25DE7;
LABEL_46:
      printk(v17, v16, "aw_cali_class_attr_init");
    }
  }
  else
  {
    if ( !v15 )
      v15 = *v14;
    printk(&unk_261C8, v15, "aw882xx_cali_init");
  }
  mutex_lock(&g_cali_lock);
  if ( !g_misc_dev )
  {
    if ( (unsigned int)misc_register(&misc_cali) )
    {
      v25 = (*v1)[14];
      if ( !v25 )
        v25 = **v1;
      printk(&unk_285D0, v25, "aw_cali_misc_init");
    }
    else
    {
      g_misc_dev = (__int64)&misc_cali;
    }
  }
  mutex_unlock(&g_cali_lock);
  result = aw_cali_parse_re_dt(a1 - 648);
  *(_BYTE *)(a1 + 16) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
