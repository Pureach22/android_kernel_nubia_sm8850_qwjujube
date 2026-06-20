__int64 __fastcall qsmmuv500_device_group(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x20
  __int64 result; // x0
  __int64 *v6; // x23
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 iommudata; // x0
  unsigned __int64 v11; // x14
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x19
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x15
  __int64 v18; // x16
  unsigned __int16 *v19; // x14
  int v20; // w15
  unsigned __int16 *v21; // x1
  int v22; // w17

  v2 = *(_QWORD *)(a1 + 824);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v2 + 56);
  result = 4294967274LL;
  if ( v3 )
  {
    v6 = *(__int64 **)(v2 + 72);
    if ( v6 )
    {
      v7 = *v6;
      v8 = a1;
      iommudata = iommu_group_get_iommudata(a2);
      if ( iommudata )
      {
        v11 = *(unsigned int *)(v7 + 352);
        if ( !(_DWORD)v11 )
          return 0;
      }
      else
      {
        v12 = _kmalloc_cache_noprof(device_match_fwnode, 3520, 8);
        if ( !v12 )
          return 4294967284LL;
        v13 = a2;
        v14 = v12;
        iommu_group_set_iommudata(v13, v12, qsmmuv500_release_group_iommudata);
        iommudata = v14;
        v11 = *(unsigned int *)(v7 + 352);
        if ( !(_DWORD)v11 )
          return 0;
      }
      v15 = *(unsigned int *)(v3 + 12);
      v16 = 0;
      v17 = v15;
      do
      {
        if ( v17 )
        {
          v18 = 0;
          v19 = (unsigned __int16 *)(*(_QWORD *)(v7 + 344) + 12 * v16);
          v20 = *((_DWORD *)v19 + 2);
          while ( 1 )
          {
            v21 = (unsigned __int16 *)(*(_QWORD *)(v7 + 104) + 8LL * (unsigned int)*((__int16 *)v6 + v18 + 4));
            v22 = *v19;
            if ( (*v21 & ~v22) == 0 && ((v21[1] ^ v19[1]) & ~v22) == 0 )
            {
              if ( (*(_BYTE *)iommudata & 1) != 0 )
              {
                if ( *(_DWORD *)(iommudata + 4) != v20 )
                {
                  dev_err(v8, "Invalid actlr setting\n");
                  return 4294967274LL;
                }
              }
              else
              {
                *(_DWORD *)(iommudata + 4) = v20;
                *(_BYTE *)iommudata = 1;
                v15 = *(unsigned int *)(v3 + 12);
              }
            }
            if ( ++v18 >= v15 )
            {
              v11 = *(unsigned int *)(v7 + 352);
              v17 = v15;
              break;
            }
          }
        }
        ++v16;
      }
      while ( v16 < v11 );
      return 0;
    }
  }
  return result;
}
