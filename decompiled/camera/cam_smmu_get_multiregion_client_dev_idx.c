__int64 __fastcall cam_smmu_get_multiregion_client_dev_idx(__int64 a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // w8
  int v5; // w8
  int v6; // w8

  v4 = 0;
  if ( !a2 || !*(_DWORD *)(a1 + 8628) )
    return v4;
  *a4 = a2;
  if ( a3 <= 3 )
  {
    if ( a3 <= 1 )
    {
      if ( a3 )
      {
        if ( a3 == 1 )
        {
          v5 = *(_DWORD *)(a1 + 1640);
          goto LABEL_18;
        }
        goto LABEL_20;
      }
      v5 = *(_DWORD *)(a1 + 288);
LABEL_18:
      if ( v5 - 1 < a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_validate_nested_region_idx",
          666,
          "Nested region idx=%d exceeds max regions=%d for region_id=%d in cb=%s",
          (_DWORD)a4,
          *(_DWORD *)(a1 + 1640),
          a3,
          *(const char **)(a1 + 32));
        return (unsigned int)-22;
      }
      return 0;
    }
    if ( a3 != 2 )
    {
      v6 = *(_DWORD *)(a1 + 2992);
LABEL_14:
      if ( v6 - 1 >= a2 )
        return 0;
    }
LABEL_15:
    v4 = 0;
    *a4 = 0;
    return v4;
  }
  if ( (unsigned int)(a3 - 4) < 2 )
    goto LABEL_15;
  if ( a3 == 6 )
  {
    v5 = *(_DWORD *)(a1 + 4344);
    goto LABEL_18;
  }
  if ( a3 == 7 )
  {
    v6 = *(_DWORD *)(a1 + 5696);
    goto LABEL_14;
  }
LABEL_20:
  v4 = 0;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_validate_nested_region_idx",
      657,
      "Invalid region id=%u on cb=%s to get nested region index",
      a3,
      *(const char **)(a1 + 32));
    return 0;
  }
  return v4;
}
