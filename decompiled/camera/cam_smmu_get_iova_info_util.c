__int64 __fastcall cam_smmu_get_iova_info_util(_QWORD *a1, _QWORD *a2, _QWORD *a3, _DWORD *a4)
{
  __int64 v8; // x0
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v11; // x9
  __int64 result; // x0
  int v13; // w10
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a1;
  v16 = 0;
  v14 = 0;
  v15 = 0;
  if ( byte_3940FA == 1 )
  {
    if ( (of_property_read_u64(v8, "iova-region-start", &v15) & 0x80000000) != 0 )
    {
      v9 = "Failed to read iova-region-start";
      v10 = 4712;
      goto LABEL_13;
    }
    if ( (of_property_read_u64(*a1, "iova-region-len", &v14) & 0x80000000) != 0 )
    {
      v9 = "Failed to read iova-region-len";
      v10 = 4719;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_get_iova_info_util",
        v10,
        v9);
      result = 4294967274LL;
      goto LABEL_14;
    }
  }
  else
  {
    if ( (of_property_read_variable_u32_array(v8, "iova-region-start", &v15, 1, 0) & 0x80000000) != 0 )
    {
      v9 = "Failed to read iova-region-start";
      v10 = 4726;
      goto LABEL_13;
    }
    if ( (of_property_read_variable_u32_array(*a1, "iova-region-len", &v14, 1, 0) & 0x80000000) != 0 )
    {
      v9 = "Failed to read iova-region-len";
      v10 = 4733;
      goto LABEL_13;
    }
  }
  if ( (of_property_read_variable_u32_array(*a1, "iova-region-id", &v16, 1, 0) & 0x80000000) != 0 )
  {
    v9 = "Failed to read iova-region-id";
    v10 = 4740;
    goto LABEL_13;
  }
  v11 = v14;
  result = 0;
  v13 = v16;
  *a2 = v15;
  *a3 = v11;
  *a4 = v13;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
