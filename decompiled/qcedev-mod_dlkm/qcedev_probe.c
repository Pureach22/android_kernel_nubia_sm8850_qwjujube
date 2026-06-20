__int64 __fastcall qcedev_probe(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w0
  __int64 v10; // x2
  __int64 v11; // x3
  unsigned __int64 v12; // x0
  __int64 v13; // x3
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x2
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x0
  __int64 v22; // x21
  unsigned int v23; // w0
  __int64 v24; // x3
  __int64 v25; // x2
  __int64 v26; // x3
  int v27; // w8
  int v28; // w9
  int v29; // w10
  int v30; // w11
  __int64 result; // x0
  int *v32; // x11
  __int64 v33; // x3
  unsigned int v34; // w19
  void *v35; // x0
  unsigned int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !(unsigned int)of_device_is_compatible(a1[95], "qcom,qcedev") )
  {
    if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,qcedev,context-bank") )
      result = qcedev_parse_context_bank(a1);
    else
      result = 4294967274LL;
    goto LABEL_46;
  }
  v2 = alloc_chrdev_region(&qcedev_device_no, 0, 1, &unk_12A35);
  v36 = v2;
  if ( (v2 & 0x80000000) != 0 )
  {
    v34 = v2;
    printk(&unk_12B5F, v2, v3, v4);
    result = v34;
    goto LABEL_46;
  }
  driver_class = class_create(&unk_12A35);
  if ( (unsigned __int64)driver_class >= 0xFFFFFFFFFFFFF001LL )
  {
    v36 = -12;
    printk(&unk_120D7, 4294967284LL, v5, v6);
LABEL_45:
    unregister_chrdev_region((unsigned int)qcedev_device_no, 1);
    result = v36;
    qword_E90 = 0;
    a1[21] = 0;
    qword_F38 = 0;
    goto LABEL_46;
  }
  class_dev = device_create();
  if ( (unsigned __int64)class_dev >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_127A0, v36, v7, v8);
    v36 = -12;
LABEL_44:
    class_destroy(driver_class);
    goto LABEL_45;
  }
  cdev_init(&unk_EA0, &qcedev_fops);
  qword_F00 = (__int64)&_this_module;
  v9 = cdev_add(&unk_EA0, qcedev_device_no & 0xFFF00000, 1);
  v36 = v9;
  if ( (v9 & 0x80000000) != 0 )
  {
    printk(&unk_12D76, v9, v10, v11);
LABEL_43:
    device_destroy(driver_class, (unsigned int)qcedev_device_no);
    goto LABEL_44;
  }
  dword_F28 = 0;
  dword_E64 = 0;
  qword_F48 = (__int64)&qword_F48;
  qword_F50 = (__int64)&qword_F48;
  qword_F58 = 0;
  qword_F90 = (__int64)&qword_F90;
  qword_F98 = (__int64)&qword_F90;
  dword_F60 = 0;
  tasklet_init(&unk_F68, req_done, &qce_dev);
  v12 = of_icc_get(a1 + 2, "data_path");
  qword_E90 = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v36 = v12;
    printk(&unk_12680, "qcedev_probe_device", v12, v13);
LABEL_42:
    cdev_del(&unk_EA0);
    goto LABEL_43;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,icc_avg_bw", &dword_E98, 1, 0) & 0x80000000) != 0 )
  {
    printk(&unk_125AF, "qcedev_probe_device", v14, v15);
    dword_E98 = 384;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,icc_peak_bw", &dword_E9C, 1, 0) & 0x80000000) != 0 )
  {
    printk(&unk_12C8F, "qcedev_probe_device", v16, v17);
    v18 = 384;
    dword_E9C = 384;
  }
  else
  {
    v18 = (unsigned int)dword_E9C;
  }
  v36 = icc_set_bw(qword_E90, (unsigned int)dword_E98, v18);
  if ( v36 )
  {
    printk(&unk_11C4C, "qcedev_probe_device", v19, v20);
    goto LABEL_40;
  }
  v21 = qce_open(a1, &v36);
  if ( !v21 )
  {
    v36 = -19;
LABEL_39:
    icc_set_bw(qword_E90, 0, 0);
LABEL_40:
    if ( qword_E90 )
      icc_put();
    goto LABEL_42;
  }
  v22 = v21;
  qword_F30 = v21;
  v23 = qce_set_irqs();
  v36 = v23;
  if ( v23 )
  {
    printk(&unk_11FE7, "qcedev_probe_device", v23, v24);
    goto LABEL_39;
  }
  v36 = icc_set_bw(qword_E90, 0, 0);
  if ( v36 )
  {
    v35 = &unk_11F03;
LABEL_37:
    printk(v35, "qcedev_probe_device", v25, v26);
LABEL_38:
    qce_close(v22);
    qword_F30 = 0;
    goto LABEL_39;
  }
  qword_F38 = (__int64)a1;
  a1[21] = &qce_dev;
  qce_hw_support(qword_F30, &unk_E68);
  if ( byte_E72 == 1 )
  {
    v27 = 0;
    v28 = 0;
    v29 = (unsigned __int8)byte_E74;
    v30 = 1;
  }
  else
  {
    v32 = (int *)a1[20];
    v27 = *v32;
    v28 = v32[1];
    v29 = v32[2];
    v30 = v32[3];
  }
  qce_dev = v27;
  dword_E54 = v28;
  dword_E58 = v29;
  dword_E5C = v30;
  qword_FA0 = qcedev_mem_new_client(0);
  if ( !qword_FA0 )
  {
    v35 = &unk_12B80;
    goto LABEL_37;
  }
  result = of_platform_populate(a1[95], &_mod_of__qcedev_match_device_table, 0, a1 + 2);
  v36 = result;
  if ( (_DWORD)result )
  {
    printk(&unk_11AAC, "qcedev_probe_device", (unsigned int)result, v33);
    if ( qword_FA0 )
      qcedev_mem_delete_client();
    qword_FA0 = 0;
    goto LABEL_38;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
