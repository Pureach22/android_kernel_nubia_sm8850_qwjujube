__int64 __fastcall arm_smmu_device_reset(__int64 a1)
{
  __int64 (**v1)(void); // x8
  __int64 v2; // x20
  __int64 (*v4)(void); // x8
  unsigned int v5; // w0
  __int64 v6; // x8
  _DWORD *v7; // x8
  __int64 v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x8
  _DWORD *v11; // x8
  _DWORD **v12; // x8
  _DWORD *v13; // x8
  int v14; // w0
  unsigned int v15; // w9
  __int64 v16; // x8
  unsigned int v17; // w20
  unsigned int v18; // w21
  int v19; // w23
  unsigned int v20; // w22
  void (__fastcall *v21)(_QWORD); // x8
  int v22; // w8
  int v23; // w21
  int v24; // w22
  __int64 v25; // x20
  int v26; // w21
  __int64 v27; // x8
  _DWORD *v28; // x8
  unsigned int v30; // w9
  int v31; // w20
  __int64 v32; // x8
  __int64 v33; // x21
  _DWORD *v34; // x11
  __int64 v35; // x8
  __int64 v36; // x9
  unsigned int v37; // w9
  __int64 v38; // x3
  __int64 v39; // x10
  unsigned int v40; // w9
  __int64 v41; // x2
  _DWORD *v42; // x8
  unsigned __int16 *v43; // x8
  __int64 v44; // x3
  __int64 v45; // x8
  _DWORD *v46; // x8
  unsigned int v47; // w20
  __int64 v48; // x8
  __int64 v49; // x1
  void (__fastcall *v50)(__int64, __int64, __int64, __int64); // x8

  v1 = *(__int64 (***)(void))(a1 + 48);
  v2 = *(_QWORD *)a1;
  if ( v1 && (v4 = *v1) != nullptr )
  {
    if ( *((_DWORD *)v4 - 1) != 616069899 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    v5 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + 72LL));
  }
  v6 = *(_QWORD *)(a1 + 48);
  if ( v6 && (v7 = *(_DWORD **)(v6 + 8)) != nullptr )
  {
    if ( *(v7 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD))v7)(a1, 0, 72, v5);
  }
  else
  {
    writel_relaxed_0(v5, (unsigned int *)(*(_QWORD *)(a1 + 8) + 72LL));
  }
  if ( !of_find_property(*(_QWORD *)(v2 + 744), "qcom,reset-stream-mapping-groups", 0) )
  {
    mutex_lock(a1 + 120);
    if ( !*(_DWORD *)(a1 + 92) )
    {
LABEL_60:
      mutex_unlock(a1 + 120);
      if ( *(_DWORD *)(a1 + 56) )
      {
        v47 = 0;
        do
        {
          arm_smmu_write_context_bank(a1, v47);
          v48 = *(_QWORD *)(a1 + 48);
          v49 = v47 + *(_DWORD *)(a1 + 24);
          if ( v48 && (v50 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v48 + 8)) != nullptr )
          {
            if ( *((_DWORD *)v50 - 1) != -1008624849 )
              __break(0x8228u);
            v50(a1, v49, 88, 3221225982LL);
          }
          else
          {
            writel_relaxed_0(
              0xC00001FE,
              (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v49 << *(_DWORD *)(a1 + 28)) + 88LL));
          }
          ++v47;
        }
        while ( v47 < *(_DWORD *)(a1 + 56) );
      }
      goto LABEL_8;
    }
    v30 = 0;
    v31 = 2048;
    while ( 1 )
    {
      v32 = *(_QWORD *)(a1 + 48);
      v33 = (int)v30;
      if ( v32 )
      {
        v34 = *(_DWORD **)(v32 + 136);
        if ( v34 )
          break;
      }
      v36 = *(_QWORD *)(a1 + 112) + 24LL * (int)v30;
      v37 = ((*(_DWORD *)(v36 + 12) & 3) << 16) & 0xFCFFFFFF
          | ((*(_DWORD *)(v36 + 16) & 3) << 24)
          | *(unsigned __int8 *)(v36 + 20);
      v38 = v37 | 0x300;
      if ( (*(_BYTE *)(a1 + 33) & 0x10) != 0 )
      {
        v39 = *(_QWORD *)(a1 + 104);
        if ( v39 )
        {
          v40 = v37 | 0x700;
          if ( *(_BYTE *)(v39 + 8 * v33 + 4) )
            v38 = v40;
          else
            v38 = (unsigned int)v38;
        }
      }
      v41 = (unsigned int)(v31 + 1024);
      if ( v32 )
      {
        v42 = *(_DWORD **)(v32 + 8);
        if ( v42 )
        {
          if ( *(v42 - 1) != -1008624849 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v42)(a1, 0, v41, v38);
          v35 = *(_QWORD *)(a1 + 104);
          if ( !v35 )
            goto LABEL_32;
LABEL_47:
          v43 = (unsigned __int16 *)(v35 + 8 * v33);
          v44 = v43[1] | (*v43 << 16);
          if ( (*(_BYTE *)(a1 + 33) & 0x10) == 0 )
          {
            if ( *((_BYTE *)v43 + 4) )
              v44 = (unsigned int)v44 | 0x80000000;
            else
              v44 = (unsigned int)v44;
          }
          v45 = *(_QWORD *)(a1 + 48);
          if ( v45 && (v46 = *(_DWORD **)(v45 + 8)) != nullptr )
          {
            if ( *(v46 - 1) != -1008624849 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v46)(a1, 0, (unsigned int)v31, v44);
          }
          else
          {
            writel_relaxed_0(v44, (unsigned int *)(*(_QWORD *)(a1 + 8) + v31));
          }
          goto LABEL_32;
        }
      }
      writel_relaxed_0(v38, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)v41));
      v35 = *(_QWORD *)(a1 + 104);
      if ( v35 )
        goto LABEL_47;
LABEL_32:
      v30 = v33 + 1;
      v31 += 4;
      if ( (unsigned int)(v33 + 1) >= *(_DWORD *)(a1 + 92) )
        goto LABEL_60;
    }
    if ( *(v34 - 1) != -1998289792 )
      __break(0x822Bu);
    ((void (__fastcall *)(__int64, _QWORD))v34)(a1, v30);
    v35 = *(_QWORD *)(a1 + 104);
    if ( !v35 )
      goto LABEL_32;
    goto LABEL_47;
  }
LABEL_8:
  v8 = *(_QWORD *)(a1 + 48);
  if ( v8 && (v9 = *(_DWORD **)(v8 + 8)) != nullptr )
  {
    if ( *(v9 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v9)(a1, 0, 108, 0xFFFFFFFFLL);
    v10 = *(_QWORD *)(a1 + 48);
    if ( !v10 )
      goto LABEL_12;
  }
  else
  {
    writel_relaxed_0(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 8) + 108LL));
    v10 = *(_QWORD *)(a1 + 48);
    if ( !v10 )
      goto LABEL_12;
  }
  v11 = *(_DWORD **)(v10 + 8);
  if ( v11 )
  {
    if ( *(v11 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v11)(a1, 0, 104, 0xFFFFFFFFLL);
    v12 = *(_DWORD ***)(a1 + 48);
    if ( !v12 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_12:
  writel_relaxed_0(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 8) + 104LL));
  v12 = *(_DWORD ***)(a1 + 48);
  if ( !v12 )
  {
LABEL_14:
    v14 = readl_relaxed_0(*(unsigned int **)(a1 + 8));
    goto LABEL_15;
  }
LABEL_13:
  v13 = *v12;
  if ( !v13 )
    goto LABEL_14;
  if ( *(v13 - 1) != 616069899 )
    __break(0x8228u);
  v14 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v13)(a1, 0, 0);
LABEL_15:
  v15 = *(_DWORD *)(a1 + 32);
  v16 = *(_QWORD *)(a1 + 48);
  v17 = v15 >> 9;
  v18 = v14 & 0xFF3F03C8;
  if ( disable_bypass )
    v19 = 7222;
  else
    v19 = 6198;
  v20 = (v15 << 25) & 0x80000000;
  if ( v16 )
  {
    v21 = *(void (__fastcall **)(_QWORD))(v16 + 40);
    if ( v21 )
    {
      if ( *((_DWORD *)v21 - 1) != -1110832593 )
        __break(0x8228u);
      v21(a1);
    }
  }
  v22 = v18 | v19;
  v23 = v17 & 8;
  v24 = v22 | v20;
  v25 = raw_spin_lock_irqsave(a1 + 224);
  if ( (unsigned int)_arm_smmu_tlb_sync(a1, 0, 112, 116)
    && (unsigned int)__ratelimit(&arm_smmu_tlb_sync_global__rs, "arm_smmu_tlb_sync_global") )
  {
    dev_err(*(_QWORD *)a1, "TLB global sync failed!\n");
  }
  v26 = v24 | v23;
  raw_spin_unlock_irqrestore(a1 + 224, v25);
  v27 = *(_QWORD *)(a1 + 48);
  if ( !v27 )
    return writel_relaxed_0(v26 | 0xC00000u, *(unsigned int **)(a1 + 8));
  v28 = *(_DWORD **)(v27 + 8);
  if ( !v28 )
    return writel_relaxed_0(v26 | 0xC00000u, *(unsigned int **)(a1 + 8));
  if ( *(v28 - 1) != -1008624849 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v28)(a1, 0, 0, v26 | 0xC00000u);
}
