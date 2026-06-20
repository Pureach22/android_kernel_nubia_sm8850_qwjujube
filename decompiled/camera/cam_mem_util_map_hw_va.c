__int64 __fastcall cam_mem_util_map_hw_va(
        unsigned int a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        char *a6,
        __int64 *a7,
        unsigned int a8,
        char a9)
{
  int v15; // w8
  __int64 v16; // x27
  __int64 v17; // x26
  __int64 result; // x0
  int v19; // w0
  unsigned __int64 v20; // x9
  int v21; // w6
  char *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11
  unsigned __int64 v26; // x9
  int v27; // w6
  char *v28; // x8
  unsigned int v29; // w0
  int v30; // w9
  __int64 v31; // x0
  __int64 v32; // x0
  const char *v33; // x6
  unsigned int v34; // w21
  __int64 v35; // x23
  unsigned int *v36; // x24
  __int64 v37; // x0
  int v38; // w21
  int v39; // [xsp+0h] [xbp-60h]
  unsigned int v40; // [xsp+34h] [xbp-2Ch]
  char v42[4]; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v43; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v44[2]; // [xsp+50h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a1 & 2) != 0 )
  {
    v15 = 1;
LABEL_7:
    v40 = v15;
    goto LABEL_8;
  }
  if ( (a1 & 4) != 0 )
  {
    v15 = 2;
    goto LABEL_7;
  }
  if ( (a1 & 0x21) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_util_map_hw_va",
      2101,
      "fail to map DMA direction, dir=%d",
      -22);
    result = 4294967274LL;
    goto LABEL_48;
  }
  v40 = 0;
LABEL_8:
  v43 = 0;
  v44[0] = 0;
  v42[0] = 0;
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
  {
    v38 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_util_map_hw_va",
      2110,
      "map_hw_va : fd = %d, flags = 0x%x, dir=%d, num_hdls=%d",
      a4,
      a1,
      v40,
      a3);
    a3 = v38;
    if ( v38 >= 1 )
      goto LABEL_11;
LABEL_47:
    result = 0xFFFFFFFFLL;
    goto LABEL_48;
  }
  if ( a3 < 1 )
    goto LABEL_47;
LABEL_11:
  v16 = 0;
  v17 = (unsigned int)a3;
  result = 0xFFFFFFFFLL;
  while ( 1 )
  {
    v26 = *(unsigned int *)(a2 + 4 * v16);
    v27 = v26 & 0xFFFFFFF;
    if ( (HIWORD(*(_DWORD *)(a2 + 4 * v16)) & 0xFFF) >= dword_391BA8 )
    {
      v32 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x400000,
              1,
              "cam_mem_mgr_get_hwva_entry_idx",
              165,
              "Invalid mem_hdl: 0x%x, failed to lookup",
              v27);
      if ( (cam_smmu_is_expanded_memory(v32) & 1) == 0 )
        goto LABEL_26;
LABEL_20:
      v29 = cam_smmu_supports_shared_region(*(unsigned int *)(a2 + 4 * v16), v42);
      if ( v29 )
      {
        v34 = v29;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_util_map_hw_va",
          2122,
          "Failed to check SMMU shared region support, mmu_hdl=%d",
          *(_DWORD *)(a2 + 4 * v16));
        goto LABEL_37;
      }
      if ( (a1 & 0x10040) != 0 )
        v30 = 1;
      else
        v30 = a8;
      if ( v42[0] )
        a8 = v30;
      goto LABEL_26;
    }
    v28 = &a6[40 * ((v26 >> 16) & 0xFFF)];
    if ( v28[33] == 1 && *(_DWORD *)v28 == v27 )
      goto LABEL_15;
    if ( (cam_smmu_is_expanded_memory(result) & 1) != 0 )
      goto LABEL_20;
LABEL_26:
    v31 = *(unsigned int *)(a2 + 4 * v16);
    if ( (a1 & 0x20) != 0 )
    {
      v19 = cam_smmu_map_stage2_iova(v31, a4, a5, v40, v44, a7, &v43);
      if ( v19 )
        break;
      goto LABEL_13;
    }
    LOBYTE(v39) = a9 & 1;
    v19 = cam_smmu_map_user_iova(v31, a4, a5, (a1 >> 13) & 1, v40, v44, a7, a8, v39, &v43);
    if ( v19 )
      break;
LABEL_13:
    v20 = *(unsigned int *)(a2 + 4 * v16);
    v21 = v20 & 0xFFFFFFF;
    if ( (HIWORD(*(_DWORD *)(a2 + 4 * v16)) & 0xFFF) >= dword_391BA8 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_get_hwva_entry_idx",
        165,
        "Invalid mem_hdl: 0x%x, failed to lookup",
        v21);
      result = 0;
    }
    else
    {
      v22 = &a6[40 * ((v20 >> 16) & 0xFFF)];
      v23 = *a7;
      result = 0;
      *((_WORD *)v22 + 16) = 257;
      v25 = v43;
      v24 = v44[0];
      *(_DWORD *)v22 = v21;
      *((_QWORD *)v22 + 1) = v24;
      *((_QWORD *)v22 + 2) = v23;
      *((_QWORD *)v22 + 3) = v25;
    }
LABEL_15:
    if ( v17 == ++v16 )
      goto LABEL_48;
  }
  if ( (a1 & 0x20) != 0 )
    v33 = (const char *)&unk_3E455A;
  else
    v33 = "secured";
  v34 = v19;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_util_map_hw_va",
    2141,
    "Failed %s map to smmu, i=%d, fd=%d, dir=%d, mmu_hdl=%d, rc=%d",
    v33,
    v16,
    a4,
    v40,
    *(_DWORD *)(a2 + 4 * v16),
    v19);
LABEL_37:
  if ( dword_391BA8 >= 1 )
  {
    v35 = 0;
    v36 = (unsigned int *)a6;
    do
    {
      if ( *((_BYTE *)v36 + 33) == 1 )
      {
        v37 = *v36;
        if ( (a1 & 0x20) != 0 )
          cam_smmu_unmap_stage2_iova(v37, a4, a5, 0);
        else
          cam_smmu_unmap_user_iova(v37, a4, a5, 3, 0);
      }
      ++v35;
      v36 += 10;
    }
    while ( v35 < dword_391BA8 );
  }
  memset(a6, 0, qword_391BB0);
  result = v34;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
