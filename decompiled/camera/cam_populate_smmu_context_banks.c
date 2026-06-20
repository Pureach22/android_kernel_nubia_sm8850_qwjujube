__int64 __fastcall cam_populate_smmu_context_banks(__int64 a1, int a2)
{
  __int64 v4; // x20
  int string_helper; // w0
  __int64 v6; // x6
  const char *v7; // x5
  __int64 v8; // x4
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  int v13; // w0
  unsigned int v14; // w21
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 v18; // x21
  __int64 v19; // x25
  int v20; // w27
  const char *v21; // x23
  unsigned int memory_regions_info; // w0
  const char *v23; // x5
  unsigned int v24; // w19
  __int64 v25; // x4
  __int64 property; // x21
  __int64 v27; // x0
  int v28; // w8
  unsigned int v29; // w22
  int v30; // w21
  unsigned int v31; // w22
  _DWORD *v32; // x8
  unsigned int v33; // w21
  __int64 v34; // x8
  unsigned int v35; // w19
  int v36; // w6
  _QWORD v37[2]; // [xsp+0h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_populate_smmu_context_banks",
      5230,
      "Error: Invalid device");
    result = 4294967277LL;
LABEL_54:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( dword_394064 >= (unsigned int)dword_394060 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_populate_smmu_context_banks",
      5236,
      "Error: populate more than allocated cb");
    result = 4294966775LL;
    goto LABEL_54;
  }
  v4 = iommu_cb_set + 14280LL * (unsigned int)dword_394064;
  *(_BYTE *)(v4 + 8616) = of_find_property(*(_QWORD *)(a1 + 744), "multiple-client-devices", 0) != 0;
  string_helper = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "cam-smmu-label", 0, 0, 0);
  v6 = (unsigned int)string_helper;
  *(_DWORD *)(v4 + 8624) = string_helper;
  if ( string_helper > 6 )
  {
    v7 = "Invalid count of client names count=%d";
    v8 = 5252;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      1,
      1,
      "cam_populate_smmu_context_banks",
      v8,
      v7,
      v6);
    result = 4294967274LL;
    goto LABEL_54;
  }
  v10 = *(_QWORD *)(a1 + 744);
  if ( (int)v6 < 1 )
    goto LABEL_23;
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 32, 1, 0);
  if ( (v11 & 0x80000000) != 0 )
  {
LABEL_26:
    v14 = v11;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_populate_smmu_context_banks",
      5263,
      "Error: failed to read label from sub device");
    result = v14;
    goto LABEL_54;
  }
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) < 2 )
  {
LABEL_23:
    v13 = of_property_read_string_helper(v10, "multiple-same-region-clients", 0, 0, 0);
    v6 = v13 & (unsigned int)~(v13 >> 31);
    *(_DWORD *)(v4 + 8628) = v6;
    if ( v13 < 3 )
    {
      v15 = v13;
      v16 = *(_QWORD *)(a1 + 744);
      if ( v15 >= 1 )
      {
        v17 = 0;
        v18 = 0;
        v19 = v4 + 8632;
        while ( 1 )
        {
          v11 = of_property_read_string_helper(v16, "multiple-same-region-clients", v19 + v17, 1, (unsigned int)v18);
          if ( (v11 & 0x80000000) != 0 )
          {
            v23 = "Error: failed to read label from sub device";
            v24 = v11;
            v25 = 5289;
            goto LABEL_52;
          }
          v20 = *(_DWORD *)(v4 + 8624);
          if ( v20 < 1 )
            break;
          if ( v18 == 2 )
            goto LABEL_96;
          v21 = *(const char **)(v19 + 8 * v18);
          v11 = strcmp(*(const char **)(v4 + 32), v21);
          if ( !(_DWORD)v11 )
          {
            if ( v20 == 1 )
              break;
            v11 = strcmp(*(const char **)(v4 + 40), v21);
            if ( !(_DWORD)v11 )
            {
              if ( v20 == 2 )
                break;
              v11 = strcmp(*(const char **)(v4 + 48), v21);
              if ( !(_DWORD)v11 )
              {
                if ( v20 == 3 )
                  break;
                v11 = strcmp(*(const char **)(v4 + 56), v21);
                if ( !(_DWORD)v11 )
                {
                  if ( v20 == 4 )
                    break;
                  v11 = strcmp(*(const char **)(v4 + 64), v21);
                  if ( !(_DWORD)v11 )
                  {
                    if ( v20 == 5 )
                      break;
                    v11 = strcmp(*(const char **)(v4 + 72), v21);
                    if ( !(_DWORD)v11 )
                    {
                      if ( v20 != 6 )
                        goto LABEL_96;
                      break;
                    }
                  }
                }
              }
            }
          }
          ++v18;
          v16 = *(_QWORD *)(a1 + 744);
          v17 += 8;
          if ( v18 >= *(int *)(v4 + 8628) )
            goto LABEL_47;
        }
        if ( (_DWORD)v18 == 2 )
          goto LABEL_96;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_populate_smmu_context_banks",
          5304,
          "%s multi region client not found in shared client list cb = %s",
          *(const char **)(v19 + 8 * v18),
          *(const char **)(v4 + 32));
        result = 4294967274LL;
        goto LABEL_54;
      }
LABEL_47:
      memory_regions_info = cam_smmu_get_memory_regions_info(v16, v4);
      if ( (memory_regions_info & 0x80000000) != 0 )
      {
        v23 = "Error: Getting region info";
        v24 = memory_regions_info;
        v25 = 5312;
LABEL_52:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          64,
          1,
          "cam_populate_smmu_context_banks",
          v25,
          v23);
      }
      else
      {
        if ( *(_BYTE *)(v4 + 80) == 1 )
        {
          *(_QWORD *)v4 = a1;
          result = 0;
          ++dword_394064;
          goto LABEL_54;
        }
        if ( a2 == 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_populate_smmu_context_banks",
            5326,
            "Error: QSMMU ctx not supported for : %s",
            *(const char **)(v4 + 32));
          result = 4294967277LL;
          goto LABEL_54;
        }
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_populate_smmu_context_banks",
            5331,
            "getting Arm SMMU ctx : %s",
            *(const char **)(v4 + 32));
        *(_DWORD *)(v4 + 8648) = 0;
        property = of_find_property(*(_QWORD *)(a1 + 744), "dma-coherent", 0);
        v27 = of_find_property(*(_QWORD *)(a1 + 744), "dma-coherent-hint-cached", 0);
        if ( property && v27 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_populate_smmu_context_banks",
            5342,
            "[%s] : Cannot enable both dma-coherent and dma-coherent-hint-cached",
            *(const char **)(v4 + 32));
          result = 4294967243LL;
          goto LABEL_54;
        }
        if ( property | v27 )
        {
          if ( property )
            v28 = 1;
          else
            v28 = 2;
          *(_DWORD *)(v4 + 8648) = v28;
        }
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_populate_smmu_context_banks",
            5352,
            "[%s] : io cohereny mode %d",
            *(const char **)(v4 + 32),
            *(_DWORD *)(v4 + 8648));
        result = cam_smmu_setup_cb(v4, a1);
        if ( (result & 0x80000000) != 0 )
        {
          v24 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_populate_smmu_context_banks",
            5357,
            "Error: failed to setup cb : %s",
            *(const char **)(v4 + 32));
        }
        else
        {
          if ( *(_BYTE *)(v4 + 84) )
          {
            if ( *(_QWORD *)(v4 + 8) )
            {
              v29 = result;
              iommu_set_fault_handler(*(_QWORD *)(v4 + 8), cam_smmu_iommu_fault_handler, *(_QWORD *)(v4 + 32));
              v30 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,iommu-faults", 0, 0, 0);
              result = v29;
              if ( v30 >= 1 )
              {
                v31 = 0;
                v37[0] = 0;
                do
                {
                  if ( (of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,iommu-faults", v37, 1, v31)
                      & 0x80000000) == 0 )
                    cam_smmu_check_for_fault_properties(v37[0], v4);
                  ++v31;
                }
                while ( v30 != v31 );
                result = 0;
              }
            }
          }
          v32 = *(_DWORD **)(a1 + 672);
          if ( v32
            || (v33 = result, v32 = devm_kmalloc(nullptr, a1, 16, 3520),
                              result = v33,
                              (*(_QWORD *)(a1 + 672) = v32) != 0) )
          {
            *v32 = -1;
            v34 = *(_QWORD *)(a1 + 672);
            if ( v34 )
              *(_QWORD *)(v34 + 8) = -1;
            else
              __break(0x800u);
            if ( byte_3940FA == 1 )
            {
              if ( (debug_mdl & 0x40) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40,
                  4,
                  "cam_populate_smmu_context_banks",
                  5395,
                  "[%s] setting max address mask",
                  *(const char **)(v4 + 32));
              result = dma_set_mask_and_coherent(a1);
              if ( (_DWORD)result )
              {
                v35 = result;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  64,
                  1,
                  "cam_populate_smmu_context_banks",
                  5400,
                  "[%s] Failed in setting max address mask, rc %d",
                  *(const char **)(v4 + 32),
                  result);
                result = v35;
              }
            }
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              64,
              2,
              "cam_populate_smmu_context_banks",
              5386,
              "Failed to allocate dma_params");
            result = v33;
            *(_QWORD *)(a1 + 672) = 0;
          }
          v36 = ++dword_394064;
          if ( (debug_mdl & 0x40) == 0 || debug_priority )
            goto LABEL_54;
          v24 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_populate_smmu_context_banks",
            5406,
            "X: cb init count :%d",
            v36);
        }
      }
      result = v24;
      goto LABEL_54;
    }
    v7 = "Invalid count of multi region clients = %d";
    v8 = 5277;
    goto LABEL_25;
  }
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 40, 1, 1);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) < 3 )
    goto LABEL_23;
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 48, 1, 2);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) <= 3 )
    goto LABEL_23;
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 56, 1, 3);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) < 5 )
    goto LABEL_23;
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 64, 1, 4);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) < 6 )
    goto LABEL_23;
  LODWORD(v11) = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 72, 1, 5);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  v10 = *(_QWORD *)(a1 + 744);
  if ( *(int *)(v4 + 8624) < 7 )
    goto LABEL_23;
  v11 = of_property_read_string_helper(v10, "cam-smmu-label", v4 + 80, 1, 6);
  if ( (v11 & 0x80000000) != 0 )
    goto LABEL_26;
  if ( *(int *)(v4 + 8624) <= 7 )
  {
    v10 = *(_QWORD *)(a1 + 744);
    goto LABEL_23;
  }
LABEL_96:
  __break(0x5512u);
  return cam_smmu_get_memory_regions_info(v11, v12);
}
