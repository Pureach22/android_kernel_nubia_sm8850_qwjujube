__int64 __fastcall cam_smmu_retrieve_region_info(
        __int64 a1,
        int a2,
        int a3,
        unsigned int a4,
        bool *a5,
        _QWORD *a6,
        _QWORD *a7,
        _QWORD *a8,
        long double a9,
        long double a10,
        long double a11,
        _QWORD *a12)
{
  __int64 v12; // x23
  __int64 v13; // x9
  _DWORD *v14; // x19
  _DWORD *v15; // x8
  __int64 v16; // x9
  _DWORD *v17; // x9

  if ( a2 == 7 )
  {
    *a5 = *(_BYTE *)(a1 + 88) != 0;
    if ( a4 > 1 )
      goto LABEL_44;
    v16 = a1 + 672LL * a4 + 5704;
    if ( *(_BYTE *)(a1 + 672LL * a4 + 6369) == 1 )
    {
      v14 = (_DWORD *)(a1 + 672LL * a4 + 5712);
      if ( *v14 != a3 )
      {
        v14 = (_DWORD *)(a1 + 672LL * a4 + 5808);
        if ( *v14 != a3 )
        {
          v14 = (_DWORD *)(a1 + 672LL * a4 + 5904);
          if ( *v14 != a3 )
          {
            if ( *(_DWORD *)(a1 + 672LL * a4 + 6000) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 6000);
            }
            else if ( *(_DWORD *)(a1 + 672LL * a4 + 6096) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 6096);
            }
            else if ( *(_DWORD *)(a1 + 672LL * a4 + 6192) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 6192);
            }
            else
            {
              v14 = nullptr;
            }
          }
        }
      }
      if ( !v14 || (unsigned __int64)v14 >= 0xFFFFFFFFFFFFF001LL )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_retrieve_region_info",
          1909,
          "Failed to find subregion: %d in region: %d cb: %s",
          (_DWORD)v14,
          7,
          *(const char **)(a1 + 32));
        return (unsigned int)v14;
      }
      *a8 = v14 + 22;
      v17 = v14 + 18;
      *a12 = v14 + 2;
LABEL_39:
      v15 = v14 + 20;
      *a6 = v17;
      goto LABEL_40;
    }
LABEL_21:
    *a8 = v16 + 664;
    *a12 = v16 + 584;
    v15 = (_DWORD *)(v16 + 656);
    *a6 = v16 + 648;
LABEL_40:
    LODWORD(v14) = 0;
    goto LABEL_41;
  }
  if ( a2 == 6 )
  {
    if ( a4 > 1 )
      goto LABEL_44;
    v16 = a1 + 672LL * a4 + 4352;
    if ( *(_BYTE *)(a1 + 672LL * a4 + 5017) == 1 )
    {
      v14 = (_DWORD *)(a1 + 672LL * a4 + 4360);
      if ( *v14 != a3 )
      {
        v14 = (_DWORD *)(a1 + 672LL * a4 + 4456);
        if ( *v14 != a3 )
        {
          v14 = (_DWORD *)(a1 + 672LL * a4 + 4552);
          if ( *v14 != a3 )
          {
            if ( *(_DWORD *)(a1 + 672LL * a4 + 4648) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 4648);
            }
            else if ( *(_DWORD *)(a1 + 672LL * a4 + 4744) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 4744);
            }
            else if ( *(_DWORD *)(a1 + 672LL * a4 + 4840) == a3 )
            {
              v14 = (_DWORD *)(a1 + 672LL * a4 + 4840);
            }
            else
            {
              v14 = nullptr;
            }
          }
        }
      }
      if ( !v14 || (unsigned __int64)v14 >= 0xFFFFFFFFFFFFF001LL )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_retrieve_region_info",
          1937,
          "Failed to find subregion: %d in region: %d cb: %s",
          (_DWORD)v14,
          6,
          *(const char **)(a1 + 32));
        return (unsigned int)v14;
      }
      *a5 = 1;
      *a8 = v14 + 22;
      *a12 = v14 + 2;
      v17 = v14 + 18;
      goto LABEL_39;
    }
    goto LABEL_21;
  }
  if ( a2 != 5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_retrieve_region_info",
      1959,
      "Unsupported region: %u in cb: %s for mapping known phy addr",
      a2,
      *(const char **)(a1 + 32));
    LODWORD(v14) = -22;
    return (unsigned int)v14;
  }
  *a5 = *(_BYTE *)(a1 + 87) != 0;
  if ( a4 < 2 )
  {
    v13 = a1 + 672LL * a4;
    LODWORD(v14) = 0;
    *a8 = v13 + 7720;
    *a12 = v13 + 7640;
    v15 = (_DWORD *)(v13 + 7712);
    *a6 = v13 + 7704;
LABEL_41:
    *a7 = v15;
    return (unsigned int)v14;
  }
LABEL_44:
  __break(0x5512u);
  return cam_smmu_unmap_phy_mem_region(a9, a10, a11, *(float *)(v12 + 14392));
}
