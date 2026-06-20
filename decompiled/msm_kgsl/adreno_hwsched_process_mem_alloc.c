__int64 __fastcall adreno_hwsched_process_mem_alloc(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x2
  __int64 v8; // x19
  unsigned __int64 v9; // x21
  __int64 v10; // x10
  unsigned __int64 v11; // x20
  const char *v12; // x5
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x10
  int v16; // w8
  unsigned int v17; // w22
  unsigned int v18; // w23
  unsigned int attrs; // w0
  unsigned __int64 global; // x0
  __int64 v21; // x3
  int v22; // w22
  __int64 v23; // x8
  unsigned int v25; // w8
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x26
  __int64 v29; // x1
  __int64 v30; // x2
  int v31; // w8
  unsigned __int64 v32; // x24
  __int64 v33; // x27
  __int64 v34; // x22
  __int64 v35; // x28
  __int64 v36; // x8
  unsigned __int64 v37; // x28
  __int64 v38; // x22
  unsigned __int64 *v39; // x27
  int v40; // w8
  unsigned __int64 *v41; // x23
  __int64 v42; // x9
  const char *v43; // x6
  unsigned int v44; // w8
  unsigned __int64 v45; // x23
  int v46; // w9
  unsigned int v47; // w0
  __int64 v48; // x9
  const char *v49; // x6
  unsigned int v50; // w8
  unsigned __int64 v51; // x22
  unsigned int v52; // w23
  unsigned int v53; // w0
  unsigned int v54; // [xsp+4h] [xbp-Ch]
  int v55; // [xsp+8h] [xbp-8h]
  unsigned int v56; // [xsp+8h] [xbp-8h]
  char v57; // [xsp+Ch] [xbp-4h]

  v5 = *(_QWORD *)(a1 + 1544);
  v6 = *(unsigned int *)(a1 + 22440);
  v7 = *(unsigned int *)(a2 + 12);
  v8 = a2;
  v9 = a1;
  if ( (_DWORD)v6 )
  {
    v10 = 0;
    v11 = a1 + 20904;
    while ( v10 != 33 )
    {
      if ( *(_DWORD *)(v11 + 12) == (_DWORD)v7 && *(_DWORD *)(v11 + 20) == *(_DWORD *)(a2 + 20) )
      {
        if ( (unsigned int)v7 >= 0x1C )
          goto LABEL_11;
        goto LABEL_8;
      }
      ++v10;
      v11 += 48LL;
      if ( v6 == v10 )
        goto LABEL_10;
    }
    goto LABEL_105;
  }
LABEL_10:
  v11 = 0;
  if ( (unsigned int)v7 < 0x1C )
  {
LABEL_8:
    v12 = hfi_memkind_strings[v7];
    if ( v11 )
      goto LABEL_41;
  }
  else
  {
LABEL_11:
    v12 = "UNKNOWN";
    if ( v11 )
      goto LABEL_41;
  }
  if ( (unsigned int)v7 >= 0x1C )
  {
    dev_err(v5 + 16, "Invalid mem kind: %d\n", v7);
    LODWORD(v11) = -22;
    return (unsigned int)v11;
  }
  if ( (_DWORD)v6 == 32 )
  {
    dev_err(v5 + 16, "Reached max mem alloc entries\n");
    LODWORD(v11) = -12;
    return (unsigned int)v11;
  }
  if ( (unsigned int)v6 <= 0x20 )
  {
    v11 = a1 + 20904 + 48LL * (unsigned int)v6;
    *(_QWORD *)v11 = *(_QWORD *)a2;
    v14 = *(_QWORD *)(a2 + 16);
    v13 = *(_QWORD *)(a2 + 24);
    v15 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v11 + 32) = *(_DWORD *)(a2 + 32);
    *(_QWORD *)(v11 + 16) = v14;
    *(_QWORD *)(v11 + 24) = v13;
    *(_QWORD *)(v11 + 8) = v15;
    *(_DWORD *)(v11 + 16) = *(_DWORD *)(a2 + 20);
    a1 = *(unsigned int *)(a2 + 8);
    v16 = *(_DWORD *)(a2 + 12);
    if ( (a1 & 1) == 0 )
    {
      if ( v16 != 23 )
      {
        if ( v16 == 19 )
        {
          v17 = *(_DWORD *)(a2 + 28);
          if ( (a1 & 0x80) != 0 )
            v18 = 1;
          else
            v18 = 4;
          attrs = gmu_core_get_attrs(a1);
          global = ((__int64 (__fastcall *)(unsigned __int64, _QWORD, _QWORD, _QWORD, const char *, _QWORD, _QWORD))gmu_core_reserve_kernel_block_fixed)(
                     v9,
                     0,
                     v17,
                     v18,
                     "qcom,ipc-core",
                     attrs,
                     *(unsigned int *)(v8 + 32));
        }
        else
        {
          if ( (a1 & 0x80) != 0 )
            v21 = 1;
          else
            v21 = 4;
          global = ((__int64 (__fastcall *)(unsigned __int64, _QWORD, _QWORD, __int64, _QWORD, const char *))gmu_core_reserve_kernel_block)(
                     v9,
                     0,
                     *(unsigned int *)(a2 + 28),
                     v21,
                     *(unsigned int *)(a2 + 32),
                     v12);
        }
        *(_QWORD *)(v11 + 40) = global;
        if ( global < 0xFFFFFFFFFFFFF001LL )
        {
          *(_DWORD *)(v11 + 28) = *(_QWORD *)(global + 40);
          goto LABEL_39;
        }
LABEL_36:
        *(_QWORD *)(v11 + 32) = 0;
        *(_QWORD *)(v11 + 40) = 0;
        *(_QWORD *)(v11 + 16) = 0;
        *(_QWORD *)(v11 + 24) = 0;
        *(_QWORD *)v11 = 0;
        *(_QWORD *)(v11 + 8) = 0;
        v11 = (int)global;
        goto LABEL_41;
      }
LABEL_25:
      global = v9 + 23224;
LABEL_35:
      *(_QWORD *)(v11 + 40) = global;
      if ( global >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_36;
      *(_DWORD *)(v11 + 28) = *(_QWORD *)(global + 40);
      *(_QWORD *)v11 = *(_QWORD *)(global + 24);
      if ( (*(_BYTE *)(v8 + 8) & 8) == 0 )
      {
LABEL_40:
        ++*(_DWORD *)(v9 + 22440);
        goto LABEL_41;
      }
      v22 = gmu_core_import_buffer(v9, v11);
      global = *(_QWORD *)(v11 + 40);
      if ( !v22 )
      {
LABEL_39:
        *(_DWORD *)(v11 + 24) = *(_DWORD *)(global + 184);
        goto LABEL_40;
      }
      dev_err(v5 + 16, "gpuaddr: 0x%llx size: %lld bytes lost\n", *(_QWORD *)(global + 24), *(_QWORD *)(global + 40));
      *(_QWORD *)(v11 + 32) = 0;
      *(_QWORD *)(v11 + 40) = 0;
      *(_QWORD *)(v11 + 16) = 0;
      *(_QWORD *)(v11 + 24) = 0;
      *(_QWORD *)v11 = 0;
      *(_QWORD *)(v11 + 8) = 0;
      v11 = v22;
LABEL_41:
      if ( v11 < 0xFFFFFFFFFFFFF001LL )
      {
        v23 = *(_QWORD *)(v11 + 40);
        if ( v23 )
        {
          *(_QWORD *)v8 = *(_QWORD *)(v23 + 24);
          *(_DWORD *)(v8 + 24) = *(_DWORD *)(*(_QWORD *)(v11 + 40) + 184LL);
        }
        LODWORD(v11) = 0;
        *(_DWORD *)(v8 + 16) = *(_DWORD *)(v8 + 20);
      }
      return (unsigned int)v11;
    }
    if ( (unsigned int)(v16 - 4) >= 2 )
    {
      if ( v16 == 22 )
      {
        global = *(_QWORD *)(v9 + 40);
        goto LABEL_35;
      }
      if ( v16 == 23 )
        goto LABEL_25;
LABEL_27:
      global = kgsl_allocate_global(
                 v9,
                 *(unsigned int *)(a2 + 28),
                 0,
                 ((a1 >> 9) & 8 | ((((unsigned __int64)(unsigned int)a1 >> 2) & 1) << 24)) ^ 0x1000000,
                 (32 * (_BYTE)a1) & 0x40,
                 v12);
      goto LABEL_35;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(v9 + 14264) + 35LL) & 1) == 0 )
      goto LABEL_27;
    a2 = *(_QWORD *)(v11 + 40);
    if ( a2 )
    {
LABEL_53:
      v27 = *(unsigned int *)(v11 + 8);
      v57 = 32 * v27;
      v28 = (v27 >> 9) & 8 | ((((unsigned __int64)(unsigned int)v27 >> 2) & 1) << 24);
      if ( *(_QWORD *)(a2 + 24) )
      {
        if ( (v27 & 8) == 0 )
          goto LABEL_63;
      }
      else
      {
        LODWORD(v26) = kgsl_get_global_gpuaddr(
                         v9,
                         a2,
                         *(unsigned int *)(v11 + 28),
                         v28 ^ 0x1000000,
                         (32 * (_BYTE)v27) & 0x40,
                         v12);
        if ( (_DWORD)v26 )
          goto LABEL_96;
        LODWORD(v27) = *(_DWORD *)(v11 + 8);
        if ( (v27 & 8) == 0 )
        {
LABEL_63:
          v31 = *(_DWORD *)(v11 + 12);
          v32 = *(_QWORD *)(v9 + 24520);
          v33 = *(unsigned int *)(v11 + 28);
          if ( v31 == 5 )
            v34 = 23504;
          else
            v34 = 23448;
          v35 = *(_QWORD *)(*(_QWORD *)(v9 + 14264) + 64LL);
          if ( !*(_QWORD *)(v9 + v34) )
          {
            v48 = *(_QWORD *)(v11 + 40);
            if ( !*(_QWORD *)(v48 + 40) )
            {
LABEL_95:
              LODWORD(v26) = -28;
              goto LABEL_96;
            }
            if ( v31 == 5 )
              v49 = "sec_preempt_record_non_gmem";
            else
              v49 = "preempt_record_non_gmem";
            v26 = kgsl_alloc_map_gpu_global(
                    v9,
                    *(_QWORD *)(v48 + 24),
                    (unsigned int)(v32 - v35),
                    0,
                    v28 ^ 0x1000000,
                    v57 & 0x40,
                    v49);
            *(_QWORD *)(v9 + v34) = v26;
            if ( v26 > 0xFFFFFFFFFFFFF000LL )
            {
              *(_QWORD *)(v9 + v34) = 0;
              goto LABEL_96;
            }
            v50 = *(_DWORD *)(v11 + 8);
            if ( (v50 & 8) != 0 && !*(_DWORD *)(v26 + 184) )
            {
              v51 = v26;
              v56 = *(_DWORD *)(*(_QWORD *)(v11 + 40) + 184LL);
              v52 = (v50 & 0x80) != 0 ? 1 : 4;
              v53 = gmu_core_get_attrs(v50);
              LODWORD(v26) = gmu_core_map_gmu(v9, v51, v56, v52, v53, *(unsigned int *)(v11 + 32));
              if ( (_DWORD)v26 )
                goto LABEL_96;
            }
          }
          v36 = 4 * v32 - v35;
          v37 = v32;
          if ( v36 == v33 )
            v37 = v32 - *(_QWORD *)(*(_QWORD *)(v9 + 14264) + 64LL);
          v38 = 3;
          v39 = (unsigned __int64 *)(v9 + 23456);
          do
          {
            v40 = *(_DWORD *)(v11 + 12);
            if ( v40 == 5 )
              v41 = v39 + 7;
            else
              v41 = v39;
            if ( !*v41 )
            {
              v42 = *(_QWORD *)(v11 + 40);
              if ( *(_QWORD *)(v42 + 40) <= v37 )
                goto LABEL_95;
              if ( v40 == 5 )
                v43 = "sec_preempt_record_non_gmem";
              else
                v43 = "preempt_record_non_gmem";
              v26 = kgsl_alloc_map_gpu_global(
                      v9,
                      v37 + *(_QWORD *)(v42 + 24),
                      (unsigned int)*(_QWORD *)(v9 + 24520) - (unsigned int)*(_QWORD *)(*(_QWORD *)(v9 + 14264) + 64LL),
                      0,
                      v28 ^ 0x1000000,
                      v57 & 0x40,
                      v43);
              *v41 = v26;
              if ( v26 >= 0xFFFFFFFFFFFFF001LL )
              {
                *v41 = 0;
                goto LABEL_96;
              }
              v44 = *(_DWORD *)(v11 + 8);
              if ( (v44 & 8) != 0 && !*(_DWORD *)(v26 + 184) )
              {
                v45 = v26;
                v46 = (v44 & 0x80) != 0 ? 1 : 4;
                v54 = v46;
                v55 = *(_DWORD *)(*(_QWORD *)(v11 + 40) + 184LL);
                v47 = gmu_core_get_attrs(v44);
                LODWORD(v26) = gmu_core_map_gmu(
                                 v9,
                                 v45,
                                 (unsigned int)(v37 + v55),
                                 v54,
                                 v47,
                                 *(unsigned int *)(v11 + 32));
                if ( (_DWORD)v26 )
                  goto LABEL_96;
              }
            }
            --v38;
            v37 += v32;
            ++v39;
          }
          while ( v38 );
          global = *(_QWORD *)(v11 + 40);
          *(_DWORD *)(v11 + 28) = *(_QWORD *)(global + 40);
          *(_QWORD *)v11 = *(_QWORD *)(global + 24);
          goto LABEL_39;
        }
      }
      v29 = *(_QWORD *)(v11 + 40);
      if ( !*(_DWORD *)(v29 + 184) )
      {
        v30 = (v27 & 0x80) != 0 ? 1LL : 4LL;
        LODWORD(v26) = gmu_core_reserve_gmuaddr(v9, v29, v30, *(unsigned int *)(v11 + 32), a5, v12);
        if ( (_DWORD)v26 )
          goto LABEL_96;
      }
      goto LABEL_63;
    }
    v25 = *(_DWORD *)(v9 + 8216);
    if ( v25 == 32 )
    {
      LODWORD(v26) = -12;
LABEL_96:
      v11 = (int)v26;
      goto LABEL_41;
    }
    if ( v25 < 0x21 )
    {
      *(_DWORD *)(v9 + 8216) = v25 + 1;
      a2 = v9 + 208LL * v25 + 1560;
      *(_QWORD *)(v11 + 40) = a2;
      goto LABEL_53;
    }
  }
LABEL_105:
  __break(0x5512u);
  return adreno_hwsched_retire_cmdobj(a1, a2);
}
