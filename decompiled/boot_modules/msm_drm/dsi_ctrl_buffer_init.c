__int64 __fastcall dsi_ctrl_buffer_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned __int64 v5; // x0
  unsigned int v6; // w20
  const char *v7; // x3
  unsigned int iova; // w0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  if ( !a1 )
  {
    v7 = "inv";
    goto LABEL_8;
  }
  v2 = *(_QWORD *)(a1 + 80);
  if ( !v2 || (v3 = msm_gem_smmu_address_space_get(v2, 0)) == 0 )
  {
    v7 = *(const char **)(a1 + 16);
LABEL_8:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to get address space\n", v7);
    v6 = -12;
    goto LABEL_9;
  }
  v4 = v3;
  v5 = msm_gem_new(*(_QWORD *)(a1 + 80), 4096, 0x40000);
  v6 = v5;
  *(_QWORD *)(a1 + 2768) = v5;
  if ( v5 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_DWORD *)(a1 + 2776) = 4096;
    iova = msm_gem_get_iova(v5, v4, v10);
    if ( iova )
    {
      v6 = iova;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to get iova, rc=%d\n",
        *(const char **)(a1 + 16),
        iova);
      dsi_ctrl_buffer_deinit(a1);
    }
    else if ( (v10[0] & 7) != 0 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Tx command buffer is not 8 byte aligned\n",
        *(const char **)(a1 + 16));
      dsi_ctrl_buffer_deinit(a1);
      v6 = -524;
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to allocate gem, rc=%d\n",
      *(const char **)(a1 + 16),
      v5);
    *(_QWORD *)(a1 + 2768) = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v6;
}
