__int64 __fastcall cam_smmu_alloc_firmware(int a1, __int64 *a2, _QWORD *a3, __int64 *a4)
{
  unsigned int v4; // w19
  int v5; // w21
  __int64 v6; // x23
  unsigned int v7; // w20
  __int64 result; // x0
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v14; // x0
  __int64 v15; // x28
  int v16; // w0
  __int64 v17; // x20
  __int64 v18; // x8
  unsigned int v19; // w19
  __int64 v20; // [xsp+18h] [xbp-18h]
  int v21; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == -1 || !a3 || !a2 || !a4 )
  {
    v9 = "Error: Input args are invalid";
    v10 = 1710;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_firmware",
      v10,
      v9);
    result = 4294967274LL;
    goto LABEL_24;
  }
  v4 = HIWORD(a1) & 0xFFF;
  if ( v4 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_firmware",
      1719,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v4,
      a1);
    result = 4294967274LL;
    goto LABEL_24;
  }
  v5 = a1 >> 28;
  v6 = iommu_cb_set + 14280LL * v4;
  v7 = 0;
  if ( (unsigned int)a1 >> 28 )
  {
    if ( *(_DWORD *)(v6 + 8628) )
    {
      v21 = a1 >> 28;
      v7 = a1 >> 28;
      if ( *(_DWORD *)(v6 + 288) - 1 < v5 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_validate_nested_region_idx",
          666,
          "Nested region idx=%d exceeds max regions=%d for region_id=%d in cb=%s",
          (unsigned int)&v21,
          *(_DWORD *)(v6 + 1640),
          0,
          *(const char **)(v6 + 32));
        result = 4294967274LL;
LABEL_24:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  if ( !*(_BYTE *)(v6 + 82) )
  {
    v9 = "Firmware memory not supported for this SMMU handle";
    v10 = 1731;
    goto LABEL_11;
  }
  v14 = mutex_lock(v6 + 8432);
  if ( v7 < 3 )
  {
    v15 = v6 + 672LL * v7;
    if ( *(_BYTE *)(v15 + 960) == 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_alloc_firmware",
        1739,
        "Trying to allocate twice");
    }
    else
    {
      v17 = *(_QWORD *)(v15 + 888);
      v20 = *(_QWORD *)(v15 + 880);
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_alloc_firmware",
          1747,
          "Firmware area from DT, firmware_start: %zu, firmware_len: %zu",
          v20,
          v17);
      v16 = cam_reserve_icp_fw(icp_fw + 32LL * v5, v17);
      if ( v16 )
        goto LABEL_23;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_alloc_firmware",
          1755,
          "DMA alloc returned fw = %pK, hdl = %pK",
          *(const void **)(icp_fw + 32LL * v5 + 8),
          *(const void **)(icp_fw + 32LL * v5 + 24));
      if ( !(unsigned int)cam_iommu_map(*(_QWORD *)(v6 + 8), v20, *(_QWORD *)(icp_fw + 32LL * v5 + 24), v17, 35) )
      {
        *(_BYTE *)(v15 + 960) = 1;
        *a2 = v20;
        *a3 = *(_QWORD *)(icp_fw + 32LL * v5 + 8);
        *a4 = v17;
        mutex_unlock(v6 + 8432);
        result = 0;
        goto LABEL_24;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_alloc_firmware",
        1773,
        "Failed to map FW into IOMMU");
      cam_unreserve_icp_fw(icp_fw + 32LL * v5);
    }
    v16 = -12;
LABEL_23:
    v18 = iommu_cb_set + 14280LL * v4;
    v19 = v16;
    mutex_unlock(v18 + 8432);
    result = v19;
    goto LABEL_24;
  }
  __break(0x5512u);
  return cam_smmu_get_multiregion_client_dev_idx(v14);
}
