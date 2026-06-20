__int64 __fastcall cam_smmu_get_subregions_memory_info(__int64 *a1, int *a2, __int64 a3)
{
  __int64 v5; // x21
  __int64 next_available_child; // x0
  __int64 v7; // x1
  unsigned int v8; // w22
  __int64 result; // x0
  __int64 v10; // x22
  unsigned int v11; // w28
  int v12; // w19
  unsigned int v13; // w0
  int v14; // w27
  __int64 v15; // x19
  __int64 v16; // x26
  __int64 v17; // x8
  __int64 v18; // x9
  unsigned int variable_u32_array; // w0
  int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x9
  const char *v23; // x5
  unsigned int v24; // w19
  __int64 v25; // x4
  __int64 v26; // [xsp+28h] [xbp-38h]
  __int64 v27; // [xsp+30h] [xbp-30h] BYREF
  __int64 v28; // [xsp+38h] [xbp-28h] BYREF
  __int64 v29; // [xsp+40h] [xbp-20h] BYREF
  __int64 v30; // [xsp+48h] [xbp-18h] BYREF
  int v31; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+58h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v31 = 0;
  v29 = 0;
  v30 = 0;
  v28 = 0;
  v27 = 0;
  next_available_child = of_get_next_available_child(v5, 0);
  if ( next_available_child )
  {
    v7 = next_available_child;
    v8 = 0;
    do
    {
      ++v8;
      v7 = of_get_next_available_child(v5, v7);
    }
    while ( v7 );
    v30 = 0;
    if ( v8 >= 7 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_get_subregions_memory_info",
        4773,
        "Invalid number of subregions max=%u count=%u cb=%s",
        6,
        v8,
        *(const char **)(a3 + 32));
      goto LABEL_24;
    }
  }
  else
  {
    v30 = 0;
  }
  result = of_get_next_available_child(v5, 0);
  v30 = result;
  if ( result )
  {
    v10 = result;
    v11 = 0;
    v26 = a3;
    do
    {
      v12 = *a2;
      if ( (unsigned int)*a2 > 6 )
        __break(0x5512u);
      v13 = of_property_read_string(v10, "iova-region-name", &v29);
      if ( (v13 & 0x80000000) != 0 )
      {
        v23 = "IOVA subregion not found";
        v24 = v13;
        v25 = 4784;
LABEL_26:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_subregions_memory_info",
          v25,
          v23);
        result = v24;
        break;
      }
      result = cam_smmu_get_iova_info_util(&v30, &v28, &v27, &v31);
      if ( (_DWORD)result )
        break;
      v14 = v31;
      v15 = (__int64)&a2[24 * v12 + 2];
      if ( (unsigned int)(v31 - 1) >= 5 )
      {
        if ( v31 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_subregions_memory_info",
            4821,
            "Unsupported subregion_id: %d",
            v31);
LABEL_24:
          result = 4294967274LL;
          break;
        }
        if ( (v11 & 1) != 0 )
        {
LABEL_23:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_subregions_memory_info",
            4840,
            "Subregion=%u was already populated in cb=%s subregion_mask=0x%x",
            v31,
            *(const char **)(v26 + 32),
            v11);
          goto LABEL_24;
        }
        v21 = v27;
        v22 = v28;
        LODWORD(v16) = 1;
        *(_DWORD *)v15 = 0;
        *(_QWORD *)(v15 + 8) = v22;
        *(_QWORD *)(v15 + 16) = v21;
      }
      else
      {
        v16 = 1LL << v31;
        if ( ((1LL << v31) & v11) != 0 )
          goto LABEL_23;
        v17 = v27;
        v18 = v28;
        *(_DWORD *)v15 = v31;
        *(_QWORD *)(v15 + 8) = v18;
        *(_QWORD *)(v15 + 16) = v17;
        variable_u32_array = of_property_read_variable_u32_array(v10, "phy-addr", v15 + 40, 1, 0);
        if ( (variable_u32_array & 0x80000000) != 0 )
        {
          v23 = "Failed to read phy addr";
          v24 = variable_u32_array;
          v25 = 4816;
          goto LABEL_26;
        }
      }
      v20 = *a2 + 1;
      *a2 = v20;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_get_subregions_memory_info",
          4832,
          "cb=%s region=%d iova=0x%x len=0x%x phy=0x%pK num_subregions=%u",
          *(const char **)(v26 + 32),
          v14,
          *(_QWORD *)(v15 + 8),
          *(_QWORD *)(v15 + 16),
          *(const void **)(v15 + 40),
          v20);
      v11 |= v16;
      result = of_get_next_available_child(v5, v10);
      v10 = result;
      v30 = result;
    }
    while ( result );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
