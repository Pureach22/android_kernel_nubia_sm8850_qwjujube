__int64 __fastcall cam_smmu_unmap_user_iova(unsigned int a1, unsigned int a2, __int64 a3, __int64 a4, char a5)
{
  unsigned int v5; // w19
  __int64 v10; // x8
  __int64 mapping_by_ion_index; // x0
  int v13; // w8
  bool v14; // nf
  unsigned int v15; // w21
  const char *v16; // x5
  __int64 v17; // x4
  unsigned int v18; // w0

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_validate_params",
      4219,
      "Error: Invalid handle");
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_user_iova",
      4244,
      "unmap util validation failure");
    return 4294967274LL;
  }
  v5 = HIWORD(a1) & 0xFFF;
  if ( v5 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_validate_params",
      4228,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v5,
      a1);
    goto LABEL_7;
  }
  mutex_lock(iommu_cb_set + 14280LL * v5 + 8432);
  v10 = iommu_cb_set + 14280LL * v5;
  if ( *(_BYTE *)(v10 + 80) == 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_user_iova",
      4252,
      "Error: can't unmap non-secure mem from secure cb");
  }
  else
  {
    if ( *(_DWORD *)(v10 + 8480) == (a1 & 0xFFFFFFF) )
    {
      mapping_by_ion_index = cam_smmu_find_mapping_by_ion_index(v5, a2, a3);
      if ( mapping_by_ion_index )
      {
        v13 = *(_DWORD *)(mapping_by_ion_index + 36) - 1;
        v14 = *(_DWORD *)(mapping_by_ion_index + 36) - 2 < 0;
        *(_DWORD *)(mapping_by_ion_index + 36) = v13;
        if ( v14 != __OFSUB__(v13, 1) )
        {
          *(_DWORD *)(mapping_by_ion_index + 36) = 0;
          if ( (a5 & 1) != 0 || *(_DWORD *)(mapping_by_ion_index + 40) < 2u )
          {
            if ( (debug_mdl & 0x40) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40,
                4,
                "cam_smmu_unmap_user_iova",
                4297,
                "SMMU: removing buffer idx = %d",
                v5);
            v18 = cam_smmu_unmap_buf_and_remove_from_list();
            if ( (v18 & 0x80000000) != 0 )
            {
              v15 = v18;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                64,
                1,
                "cam_smmu_unmap_user_iova",
                4300,
                "Error: unmap or remove list fail");
            }
            else
            {
              v15 = 0;
            }
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              64,
              1,
              "cam_smmu_unmap_user_iova",
              4291,
              "[SMMU_BT] Error: can't unmap buffer as it's still active, idx: %d, cb: %s, fd: 0x%x, ino: 0x%x, ref_count: %d",
              v5,
              *(const char **)(iommu_cb_set + 14280LL * v5 + 32),
              a2,
              *(_QWORD *)(mapping_by_ion_index + 80),
              *(_DWORD *)(mapping_by_ion_index + 40));
            v15 = -1;
          }
        }
        else
        {
          v15 = 0;
          if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40,
              4,
              "cam_smmu_unmap_user_iova",
              4282,
              "idx: %d, cb: %s fd = %d , ino: 0x%x, map_count: %d, ref_count: %d",
              v5,
              *(const char **)(iommu_cb_set + 14280LL * v5 + 32),
              a2,
              *(_QWORD *)(mapping_by_ion_index + 80),
              v13,
              *(_DWORD *)(mapping_by_ion_index + 40));
            v15 = 0;
          }
        }
        goto LABEL_18;
      }
      v16 = "Error: Invalid params idx = %d, fd = %d";
      v17 = 4271;
    }
    else
    {
      v16 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
      v17 = 4260;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_user_iova",
      v17,
      v16);
  }
  v15 = -22;
LABEL_18:
  mutex_unlock(iommu_cb_set + 14280LL * v5 + 8432);
  return v15;
}
