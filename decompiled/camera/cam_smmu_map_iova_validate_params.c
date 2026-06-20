__int64 __fastcall cam_smmu_map_iova_validate_params(
        unsigned int a1,
        unsigned int a2,
        _QWORD *a3,
        _QWORD *a4,
        int a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v7; // w6

  if ( a3 && a4 )
  {
    if ( a1 == -1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_map_iova_validate_params",
        3883,
        "Invalid handle",
        a7,
        0xFFFFFFFFLL);
    }
    else
    {
      *a3 = 0;
      if ( a5 != 1 )
        *a4 = 0;
      if ( a2 >= 3 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_translate_dir",
          1131,
          "Error: Direction is invalid. dir = %d",
          a2);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_map_iova_validate_params",
          3894,
          "translate direction failed. dir = %d",
          a2);
      }
      else
      {
        v7 = HIWORD(a1) & 0xFFF;
        if ( v7 < dword_394060 )
          return 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_map_iova_validate_params",
          3901,
          "handle or index invalid. idx = %d hdl = %x",
          v7,
          a1);
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_iova_validate_params",
      3878,
      "Input pointers are invalid");
  }
  return 4294967274LL;
}
