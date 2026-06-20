__int64 __fastcall ufs_qcom_probe(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x0
  unsigned __int8 *v6; // x22
  int v7; // w2
  unsigned int v8; // w0
  __int64 result; // x0
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v11 = 0;
  v10 = 0;
  v3 = nvmem_cell_get(a1 + 16, "boot_conf");
  if ( v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = v3;
    v5 = nvmem_cell_read();
    if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_warn(a1 + 16, "nvmem cell read failed\n");
    }
    else
    {
      v6 = (unsigned __int8 *)v5;
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "boot_device_type", &v10, 1, 0) & 0x80000000) != 0 )
      {
        dev_warn(a1 + 16, "boot_device_type not present\n");
      }
      else
      {
        v7 = (*v6 >> 1) & 0x1F;
        is_bootdevice_ufs = v10 == v7;
        if ( v10 != v7 )
          dev_err(a1 + 16, "boot dev in reg = 0x%x boot dev in dtsi = 0x%x\n", v7, v10);
      }
      kfree(v6);
    }
    nvmem_cell_put(v4);
  }
  if ( (is_bootdevice_ufs & 1) == 0 )
  {
    dev_err(a1 + 16, "UFS is not boot dev.\n");
    goto LABEL_17;
  }
  if ( of_find_property(v2, "secondary-storage", 0)
    && (!ufs_qcom_hosts || *(_DWORD *)(*(_QWORD *)(ufs_qcom_hosts + 16) + 4868LL) != 1) )
  {
    result = 4294966779LL;
    goto LABEL_18;
  }
  v8 = ufshcd_pltfrm_init(a1, &ufs_hba_qcom_vops);
  if ( !v8 )
  {
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_send_command, ufs_qcom_hook_send_command, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_compl_command, ufs_qcom_hook_compl_command, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_send_uic_command, ufs_qcom_hook_send_uic_command, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_send_tm_command, ufs_qcom_hook_send_tm_command, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_check_int_errors, ufs_qcom_hook_check_int_errors, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ufs_update_sdev, ufs_qcom_update_sdev, 0);
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  result = dev_err_probe(a1 + 16, v8, "ufshcd_pltfrm_init() failed\n");
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
