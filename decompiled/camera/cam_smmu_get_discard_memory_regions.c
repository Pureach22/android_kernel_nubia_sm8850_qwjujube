__int64 __fastcall cam_smmu_get_discard_memory_regions(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // x0
  int v7; // w0
  unsigned int variable_u32_array; // w0
  unsigned int v9; // w6
  unsigned int v10; // w7
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  unsigned int v13; // w19
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 4294967274LL;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( !a2 || !a3 )
    goto LABEL_19;
  *a2 = 0;
  *a3 = 0;
  v7 = of_property_count_elems_of_size(a1, "iova-region-discard", 4);
  if ( v7 > 0 )
  {
    if ( v7 == 2 )
    {
      variable_u32_array = of_property_read_variable_u32_array(a1, "iova-region-discard", v14, 2, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v13 = variable_u32_array;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_smmu_get_discard_memory_regions",
          4682,
          "Can not read discard region %d",
          2);
        result = v13;
        goto LABEL_19;
      }
      v9 = v14[0];
      v10 = HIDWORD(v14[0]);
      if ( LODWORD(v14[0]) && HIDWORD(v14[0]) )
      {
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_smmu_get_discard_memory_regions",
            4692,
            "Discard region [0x%x 0x%x]",
            LODWORD(v14[0]),
            HIDWORD(v14[0]) + LODWORD(v14[0]));
          v9 = v14[0];
          v10 = HIDWORD(v14[0]);
          v12 = a2;
          v11 = a3;
        }
        else
        {
          v11 = a3;
          v12 = a2;
        }
        result = 0;
        *v12 = v9;
        *v11 = v10;
        goto LABEL_19;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_smmu_get_discard_memory_regions",
        4687,
        "Incorrect Discard region specified [0x%x 0x%x]",
        LODWORD(v14[0]),
        HIDWORD(v14[0]));
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_smmu_get_discard_memory_regions",
        4674,
        "Invalid discard region specified %d",
        v7);
    }
    result = 4294967274LL;
    goto LABEL_19;
  }
  result = 0;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_smmu_get_discard_memory_regions",
      4670,
      "No discard region specified");
    result = 0;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
