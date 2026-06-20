__int64 __fastcall msm_vidc_adjust_blur_type(__int64 a1, __int64 a2)
{
  int v3; // w20
  unsigned int v4; // w22
  __int64 v5; // x21
  _BOOL4 v6; // w8
  int v7; // w8

  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 196);
    if ( !v3 )
      return 0;
    goto LABEL_5;
  }
  v3 = *(_DWORD *)(a1 + 16616);
  if ( v3 )
  {
LABEL_5:
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            73,
            119,
            "msm_vidc_adjust_blur_type")
        & 1) == 0 )
      return 4294967274LL;
    v4 = *(_DWORD *)(a1 + 1828);
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            73,
            71,
            "msm_vidc_adjust_blur_type")
        & 1) == 0 )
      return 4294967274LL;
    v5 = *(_QWORD *)(a1 + 16280);
    if ( v3 != 2 )
    {
      if ( v3 == 1 )
      {
        v6 = *(_DWORD *)(a1 + 1880) == *(_DWORD *)(a1 + 1896)
          && *(_DWORD *)(a1 + 1884) == *(_DWORD *)(a1 + 1900)
          && *(_DWORD *)(a1 + 1888) == *(_DWORD *)(a1 + 1904)
          && *(_DWORD *)(a1 + 1892) == *(_DWORD *)(a1 + 1908);
        if ( v5 )
          v3 = 0;
        else
          v3 = v6;
      }
      goto LABEL_39;
    }
    if ( (is_valid_cap(a1, 23) & 1) == 0 )
      goto LABEL_19;
    if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
            a1,
            73,
            23,
            "msm_vidc_adjust_blur_type")
        & 1) == 0 )
      return 4294967274LL;
    if ( (*(_BYTE *)(a1 + 8232) & 0x80) == 0 || (~*(_DWORD *)(a1 + 8216) & 3LL) != 0 )
    {
LABEL_19:
      if ( *(_DWORD *)(a1 + 1880) == *(_DWORD *)(a1 + 1896)
        && *(_DWORD *)(a1 + 1884) == *(_DWORD *)(a1 + 1900)
        && *(_DWORD *)(a1 + 1888) == *(_DWORD *)(a1 + 1904) )
      {
        v3 = 0;
        if ( *(_DWORD *)(a1 + 1892) != *(_DWORD *)(a1 + 1908) )
          goto LABEL_39;
        if ( v5 )
          goto LABEL_39;
        v3 = 0;
        if ( v4 > 4 || ((1 << v4) & 0x13) == 0 )
          goto LABEL_39;
        if ( *(_DWORD *)(a1 + 312) != 2 )
        {
          v3 = 2;
LABEL_39:
          ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
            a1,
            73,
            v3,
            "msm_vidc_adjust_blur_type");
          return 0;
        }
        if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
                a1,
                73,
                82,
                "msm_vidc_adjust_blur_type")
            & 1) != 0 )
        {
          v3 = 2;
          v7 = *(_DWORD *)(a1 + 18128);
          if ( v7 > 127 )
          {
            if ( v7 != 256 && v7 != 128 )
              goto LABEL_39;
          }
          else if ( v7 != 8 && v7 != 16 )
          {
            goto LABEL_39;
          }
          goto LABEL_38;
        }
        return 4294967274LL;
      }
    }
LABEL_38:
    v3 = 0;
    goto LABEL_39;
  }
  return 0;
}
