__int64 __fastcall cam_smmu_map_phy_mem_region(int a1, unsigned int a2, unsigned int a3, _QWORD *a4, _QWORD *a5)
{
  unsigned int v5; // w19
  __int64 v6; // x22
  __int64 v7; // x6
  unsigned int v8; // w23
  __int64 result; // x0
  _BYTE *v14; // x28
  _QWORD *v15; // x8
  __int64 v16; // x8
  const char *v17; // x5
  __int64 v18; // x4
  const char *v19; // x5
  __int64 v20; // x4
  _QWORD *v21; // x27
  __int64 v22; // x2
  __int64 v23; // x1
  __int64 v24; // x3
  unsigned int v25; // w8
  __int64 v26; // x4
  unsigned int v27; // w0
  unsigned int v28; // w21
  _QWORD *v29; // x9
  _QWORD *v30; // x10
  int v31; // w11
  _QWORD *v32; // x8
  int *v33; // x9
  _QWORD *v34; // x9
  unsigned __int64 v41; // x13
  unsigned __int64 v44; // x10
  __int64 v45; // [xsp+28h] [xbp-48h]
  __int64 v46; // [xsp+30h] [xbp-40h]
  _QWORD *v47; // [xsp+38h] [xbp-38h] BYREF
  _BYTE *v48; // [xsp+40h] [xbp-30h] BYREF
  char v49[4]; // [xsp+4Ch] [xbp-24h] BYREF
  _QWORD *v50; // [xsp+50h] [xbp-20h] BYREF
  int *v51; // [xsp+58h] [xbp-18h] BYREF
  unsigned int v52; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+68h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v49[0] = 0;
  v47 = nullptr;
  if ( a1 == -1 || !a4 || !a5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_phy_mem_region",
      1985,
      "Error: Input args are invalid");
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  v5 = HIWORD(a1) & 0xFFF;
  if ( v5 >= dword_394060 )
  {
    v19 = "Error: handle or index invalid. idx = %d hdl = %x";
    v20 = 1994;
    v7 = v5;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_phy_mem_region",
      v20,
      v19,
      v7,
      (unsigned int)a1);
    goto LABEL_16;
  }
  v6 = iommu_cb_set + 14280LL * v5;
  v7 = *(unsigned int *)(v6 + 8480);
  if ( (_DWORD)v7 != (a1 & 0xFFFFFFF) )
  {
    v19 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v20 = 2002;
    goto LABEL_15;
  }
  v8 = a1 >> 28;
  result = cam_smmu_get_multiregion_client_dev_idx(iommu_cb_set + 14280LL * v5, a1 >> 28, a2, &v52);
  if ( (_DWORD)result )
    goto LABEL_17;
  v50 = nullptr;
  v51 = nullptr;
  v48 = nullptr;
  result = cam_smmu_retrieve_region_info(v6, a2, a3, v52, v49, &v51, &v50, &v48, &v47);
  if ( (_DWORD)result )
    goto LABEL_17;
  if ( (v49[0] & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_phy_mem_region",
      2022,
      "region: %u not supported for phy addr mapping in cb: %s",
      a2,
      *(const char **)(v6 + 32));
    goto LABEL_16;
  }
  mutex_lock(v6 + 8432);
  v14 = v48;
  if ( *v48 == 1 )
  {
    v15 = v50;
    if ( ((*(_QWORD *)((char *)v50 + (((unsigned __int64)(int)v8 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v8) & 1) == 0 )
    {
      v29 = a5;
      v30 = a4;
      _X12 = &v50[v8 >> 6];
      __asm { PRFM            #0x11, [X12] }
      do
        v41 = __ldxr(_X12);
      while ( __stxr(v41 | (1LL << v8), _X12) );
      v31 = *v51 + 1;
      *v51 = v31;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_map_phy_mem_region",
          2041,
          "Trying to allocate region: %u [subregion: %u] on cb: %s for different clients: 0x%x ref_cnt: %u",
          a2,
          a3,
          *(const char **)(v6 + 32),
          *v15,
          v31);
        v30 = a4;
        v29 = a5;
      }
      v32 = v47;
      v28 = 0;
      *v30 = *v47;
      *v29 = v32[1];
      goto LABEL_35;
    }
    v16 = *(_QWORD *)(v6 + 32);
    v17 = "Trying to allocate region: %u [subregion: %u] twice on cb: %s";
    v18 = 2032;
    goto LABEL_34;
  }
  v21 = v47;
  v22 = v47[4];
  if ( !v22 )
  {
    v16 = *(_QWORD *)(v6 + 32);
    v17 = "Invalid phy addr for region: %u [subregion: %u] on cb: %s";
    v18 = 2052;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_phy_mem_region",
      v18,
      v17,
      a2,
      a3,
      v16);
    v28 = -12;
    goto LABEL_35;
  }
  v23 = *v47;
  v24 = v47[1];
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    v45 = v47[1];
    v46 = *v47;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_map_phy_mem_region",
      2062,
      "mapping region= %u [subregion = %u] for va = 0x%x len = %zu phy = 0x%x prot=0x%x",
      a2,
      a3,
      v23,
      v24,
      v22,
      3);
    v24 = v45;
    v23 = v46;
    v25 = a2;
    v22 = v21[4];
  }
  else
  {
    v25 = a2;
  }
  if ( v25 == 7 )
    v26 = 19;
  else
    v26 = 3;
  v27 = cam_iommu_map(*(_QWORD *)(v6 + 8), v23, v22, v24, v26);
  if ( v27 )
  {
    v28 = v27;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_phy_mem_region",
      2078,
      "Failed to map region = %u into IOMMU cb = %s",
      a2,
      *(const char **)(v6 + 32));
LABEL_35:
    mutex_unlock(iommu_cb_set + 14280LL * v5 + 8432);
    result = v28;
    goto LABEL_17;
  }
  v33 = v51;
  *v14 = 1;
  ++*v33;
  *a4 = *v21;
  v34 = v50;
  *a5 = v21[1];
  _X9 = &v34[v8 >> 6];
  __asm { PRFM            #0x11, [X9] }
  do
    v44 = __ldxr(_X9);
  while ( __stxr(v44 | (1LL << v8), _X9) );
  mutex_unlock(iommu_cb_set + 14280LL * v5 + 8432);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
