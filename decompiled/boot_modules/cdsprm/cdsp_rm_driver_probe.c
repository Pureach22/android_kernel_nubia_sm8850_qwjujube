__int64 __fastcall cdsp_rm_driver_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 property; // x0
  unsigned int v4; // w8
  __int64 v5; // x20
  unsigned int v6; // w21
  __int64 v7; // x0
  unsigned __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w0
  int v11; // w20
  unsigned __int64 v12; // x21
  _DWORD *v13; // x25
  __int64 v14; // x26
  unsigned int u32_index; // w0
  bool v16; // cc
  int v17; // w0
  int v18; // w8
  __int64 v19; // x21
  unsigned __int64 v20; // x20
  unsigned int v21; // w0
  char *v22; // x25
  unsigned __int64 v23; // x8
  __int64 dir; // x2
  __int64 file; // x0
  __int64 v26; // x8
  __int64 result; // x0
  unsigned int v28; // w20
  unsigned __int64 v29; // x21
  const char *v30; // x1
  unsigned int v31; // w21
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v32[0] = 0;
  property = of_find_property(v2, "qcom,qos-cores", 0);
  byte_A48C = property != 0;
  if ( !property )
    goto LABEL_10;
  of_find_property(*(_QWORD *)(a1 + 760), "qcom,qos-cores", &dword_A4F8);
  v4 = dword_A4F8;
  if ( !dword_A4F8 )
    goto LABEL_10;
  dword_A4F8 = (unsigned int)dword_A4F8 >> 2;
  v5 = _kmalloc_noprof(4LL * (v4 >> 2), 3520);
  if ( !v5 )
  {
    dev_err(a1 + 16, "kcalloc failed for cpucores\n");
    goto LABEL_68;
  }
  if ( dword_A4F8 )
  {
    v6 = 0;
    do
    {
      if ( (unsigned int)of_property_read_u32_index(*(_QWORD *)(a1 + 760), "qcom,qos-cores", v6, v5 + 4LL * (int)v6) )
      {
        dev_err(a1 + 16, "%s: failed to read QOS coree for core:%d\n", "qos_cores_init", v6);
        byte_A48C = 0;
      }
      ++v6;
    }
    while ( v6 < dword_A4F8 );
  }
  qword_A4F0 = v5;
  qword_A500 = _kmalloc_noprof(80LL * (unsigned int)dword_A4F8, 3520);
  if ( !qword_A500 )
  {
    dev_err(a1 + 16, "kcalloc failed for dev_pm_qos_req\n");
LABEL_68:
    byte_A48C = 0;
  }
LABEL_10:
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,qos-latency-us", &dword_A398, 1, 0) & 0x80000000) != 0
    || (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,qos-maxhold-ms", &dword_A39C, 1, 0) & 0x80000000) != 0 )
  {
    goto LABEL_63;
  }
  qword_A4A0 = debugfs_create_dir("compute", 0);
  if ( !qword_A4A0 )
    dev_err(a1 + 16, "Failed to create debugfs directory for cdsprm\n");
  dword_A3A0 = 4;
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,compute-priority-mode", &dword_A3A0, 1, 0);
  v7 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,compute-cx-limit-en", 0);
  byte_A3D8 = v7 != 0;
  if ( v7 )
  {
    if ( qword_A4A0 )
    {
      qword_A4A8 = debugfs_create_file("priority", 420, qword_A4A0, 0, &cdsprm_debugfs_fops);
      if ( !qword_A4A8 )
      {
        debugfs_remove(qword_A4A0);
        dev_err(a1 + 16, "Failed to create debugfs file\n");
      }
    }
  }
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "#cooling-cells", v32, 1, 0);
  if ( LODWORD(v32[0]) )
  {
    v8 = thermal_of_cooling_device_register(*(_QWORD *)(a1 + 760), "cdsp", 0, cdsp_cooling_ops);
    if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    {
      v29 = v8;
      dev_err(a1 + 16, "CDSP thermal driver reg failed\n");
      v8 = v29;
    }
    qword_A478 = v8;
  }
  byte_A48A = 1;
  v9 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,vtcm-partition-info", 0);
  dword_99A4 = v9 != 0;
  if ( !v9 )
    goto LABEL_47;
  v10 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "qcom,vtcm-partition-info", 4);
  v11 = v10 / 3;
  byte_A1AC = v10 / 3;
  if ( v10 != 3 * (v10 / 3) )
  {
    v30 = "Maps are expected to have %d elements each entry\n";
LABEL_62:
    dev_err(a1 + 16, v30);
    goto LABEL_63;
  }
  if ( (unsigned __int8)(v10 / 3) )
  {
    v12 = 0;
    v13 = &unk_A1B8;
    v14 = -48;
    while ( 1 )
    {
      u32_index = of_property_read_u32_index(
                    *(_QWORD *)(a1 + 760),
                    "qcom,vtcm-partition-info",
                    (unsigned int)(v14 + 48),
                    (char *)v32 + 4);
      if ( u32_index )
      {
LABEL_56:
        v28 = u32_index;
        dev_err(a1 + 16, "Error reading partition element %d :%d\n", v12, HIDWORD(v32[0]));
        result = v28;
        goto LABEL_64;
      }
      if ( !v14 )
LABEL_66:
        __break(0x5512u);
      v16 = v11 <= BYTE4(v32[0]);
      *((_BYTE *)v13 - 8) = BYTE4(v32[0]);
      if ( v16 )
        break;
      u32_index = of_property_read_u32_index(
                    *(_QWORD *)(a1 + 760),
                    "qcom,vtcm-partition-info",
                    (unsigned int)(v14 + 49),
                    (char *)v32 + 4);
      if ( u32_index )
        goto LABEL_56;
      *(v13 - 1) = HIDWORD(v32[0]);
      u32_index = of_property_read_u32_index(
                    *(_QWORD *)(a1 + 760),
                    "qcom,vtcm-partition-info",
                    (unsigned int)(v14 + 50),
                    (char *)v32 + 4);
      if ( u32_index )
        goto LABEL_56;
      ++v12;
      v14 += 3;
      *v13 = HIDWORD(v32[0]);
      v13 += 3;
      if ( v12 >= (unsigned __int8)byte_A1AC )
        goto LABEL_32;
    }
    v30 = "partition id is invalid: %d\n";
    goto LABEL_62;
  }
LABEL_32:
  v17 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "qcom,vtcm-partition-map", 4);
  if ( v17 >= 0 )
    v18 = v17;
  else
    v18 = v17 + 1;
  byte_A1AD = v18 >> 1;
  if ( (v17 & 1) != 0 )
  {
    dev_err(a1 + 16, "Maps to have %d elements each entry\n");
LABEL_63:
    result = 4294967274LL;
    goto LABEL_64;
  }
  if ( !(unsigned __int8)(v18 >> 1) )
  {
LABEL_42:
    dir = qword_A4A0;
    if ( qword_A4A0 || (dir = debugfs_create_dir("compute", 0), (qword_A4A0 = dir) != 0) )
    {
      file = debugfs_create_file("vtcm_partition_state", 420, dir, 0, &cdsprmvtcm_debugfs_fops);
      qword_A4B0 = file;
    }
    else
    {
      dev_err(a1 + 16, "Failed to find debugfs directory for cdsprm\n");
      file = qword_A4B0;
    }
    if ( !(file | qword_A4A8) )
    {
      debugfs_remove(qword_A4A0);
      dev_err(a1 + 16, "Failed to create debugfs file\n");
    }
LABEL_47:
    dword_99A8 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,resmgr-pdkill-enable", 0) != 0;
    dword_99AC = dword_99A8;
    if ( qword_A4A0 )
    {
      qword_A4B8 = debugfs_create_file(
                     "resmgr_pdkill_override_state",
                     420,
                     qword_A4A0,
                     0,
                     &cdsprm_resmgr_pdkill_debugfs_fops);
      if ( !qword_A4B8 )
        dev_err(a1 + 16, "Failed to create resmgr debugfs file\n");
      qword_A4C0 = debugfs_create_file("resmgr_pdkill_state", 292, qword_A4A0, 0, &cdsprm_resmgr_pdkill_state_fops);
      if ( !qword_A4C0 )
        dev_err(a1 + 16, "Failed to create resmgr debugfs file\n");
      qword_A4C8 = debugfs_create_file("dcvs_clients", 292, qword_A4A0, 0, &dcvs_clients_fops);
      if ( !qword_A4C8 )
        dev_err(a1 + 16, "Failed to create dcvs_clients_show file\n");
    }
    v26 = proc_create("dcvs_clients", 0, 0, &cdsp_zte_dcvs_fops);
    result = 0;
    proc_entry_dcvs_clients = v26;
    if ( !v26 )
    {
      printk(&unk_B777);
      result = 0;
    }
    goto LABEL_64;
  }
  v19 = 0;
  v20 = 0;
  while ( 1 )
  {
    v21 = of_property_read_u32_index(
            *(_QWORD *)(a1 + 760),
            "qcom,vtcm-partition-map",
            (unsigned int)v19,
            (char *)v32 + 4);
    if ( v21 )
      break;
    if ( v20 == 32 )
      goto LABEL_66;
    v22 = (char *)gcdsprm + v19;
    *((_BYTE *)&gcdsprm[566] + v19) = BYTE4(v32[0]);
    v21 = of_property_read_u32_index(
            *(_QWORD *)(a1 + 760),
            "qcom,vtcm-partition-map",
            (unsigned int)(v19 + 1),
            (char *)v32 + 4);
    if ( v21 )
      break;
    v23 = (unsigned __int8)byte_A1AD;
    ++v20;
    v19 += 2;
    v22[2265] = BYTE4(v32[0]);
    if ( v20 >= v23 )
      goto LABEL_42;
  }
  v31 = v21;
  dev_err(a1 + 16, "Error reading map element %d :%d\n", v20, HIDWORD(v32[0]));
  result = v31;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
