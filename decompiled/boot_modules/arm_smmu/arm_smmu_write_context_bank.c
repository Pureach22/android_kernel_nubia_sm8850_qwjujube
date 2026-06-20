__int64 __fastcall arm_smmu_write_context_bank(__int64 a1, unsigned int a2)
{
  unsigned int *v3; // x22
  __int64 v4; // x19
  __int64 v5; // x24
  int v6; // w23
  int v7; // w21
  unsigned int v8; // w3
  __int64 v9; // x8
  void (*v10)(void); // x8
  __int64 v11; // x3
  int v12; // w8
  __int64 v13; // x8
  __int64 v14; // x1
  _DWORD *v15; // x8
  int v16; // w8
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x8
  __int64 v22; // x3
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64, __int64, __int64); // x8
  __int64 v25; // x8
  __int64 v26; // x3
  __int64 v27; // x1
  void (__fastcall *v28)(__int64, __int64, __int64, __int64); // x8
  __int64 v29; // x1
  __int64 v30; // x8
  __int64 v31; // x3
  void (__fastcall *v32)(__int64, __int64, __int64, __int64); // x8
  __int64 v33; // x8
  __int64 v34; // x3
  __int64 v35; // x1
  void (__fastcall *v36)(__int64, __int64, __int64, __int64); // x8
  __int64 v37; // x8
  __int64 v38; // x3
  __int64 v39; // x1
  void (__fastcall *v40)(__int64, __int64, __int64, __int64); // x8
  __int64 v41; // x8
  __int64 v42; // x3
  void (__fastcall *v43)(__int64, __int64, __int64, __int64); // x8
  __int64 v44; // x8
  __int64 v45; // x3
  __int64 v46; // x1
  void (__fastcall *v47)(__int64, __int64, __int64, __int64); // x8
  __int64 v48; // x8
  __int64 v49; // x3
  __int64 v50; // x1
  void (__fastcall *v51)(__int64, __int64, __int64, __int64); // x8
  __int64 v52; // x8
  __int64 v53; // x3
  __int64 v54; // x1
  void (__fastcall *v55)(__int64, __int64, __int64, __int64); // x8
  __int64 v56; // x8
  _DWORD *v57; // x9
  __int64 v58; // x2
  __int64 v60; // x3

  v3 = (unsigned int *)(*(_QWORD *)(a1 + 80) + 48LL * (int)a2);
  v4 = a1;
  v5 = *((_QWORD *)v3 + 5);
  if ( !v5 )
  {
    v13 = *(_QWORD *)(a1 + 48);
    v14 = *(_DWORD *)(a1 + 24) + a2;
    if ( !v13 || (v15 = *(_DWORD **)(v13 + 8)) == nullptr )
    {
      v16 = *(_DWORD *)(a1 + 28);
      v17 = *(_QWORD *)(a1 + 8);
      v18 = 0;
      return writel_relaxed_0(v18, v17 + (int)((_DWORD)v14 << v16));
    }
    v60 = 0;
    goto LABEL_95;
  }
  v6 = *(_DWORD *)(v5 + 12);
  v7 = 4 * a2;
  if ( *(_DWORD *)(a1 + 40) )
  {
    v8 = *(_DWORD *)(v5 + 16) == 1;
    if ( (*(_BYTE *)(a1 + 32) & 0x40) != 0 )
      v8 |= *(unsigned __int16 *)(v5 + 2) << 16;
    v9 = *(_QWORD *)(a1 + 48);
    if ( v9 && (v10 = *(void (**)(void))(v9 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v10 - 1) != -1008624849 )
        __break(0x8228u);
      v10();
    }
    else
    {
      writel_relaxed_0(v8, *(_QWORD *)(a1 + 8) + (1 << *(_DWORD *)(a1 + 28)) + v7 + 2048);
    }
  }
  v11 = (*(_DWORD *)(v5 + 12) & 3u) << 16;
  if ( *(_DWORD *)(v4 + 40) <= 1u )
    v11 = (unsigned int)v11 | (*(unsigned __int8 *)(v5 + 1) << 24);
  if ( v6 )
  {
    v12 = 62208;
LABEL_17:
    v11 = (unsigned int)v11 | v12;
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(v4 + 32) & 0x40) == 0 )
  {
    v12 = *(unsigned __int8 *)(v5 + 2);
    goto LABEL_17;
  }
LABEL_18:
  v19 = *(_QWORD *)(v4 + 48);
  if ( !v19 || (v20 = *(_DWORD **)(v19 + 8)) == nullptr )
  {
    writel_relaxed_0((unsigned int)v11, *(_QWORD *)(v4 + 8) + (1 << *(_DWORD *)(v4 + 28)) + v7);
    if ( !v6 )
      goto LABEL_25;
    goto LABEL_21;
  }
  if ( *(v20 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v20)(v4, 1, (unsigned int)v7, v11);
  if ( v6 )
  {
LABEL_21:
    if ( *(_DWORD *)(v4 + 40) )
    {
      v21 = *(_QWORD *)(v4 + 48);
      v22 = v3[5];
      v23 = *(_DWORD *)(v4 + 24) + a2;
      if ( v21 && (v24 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v21 + 8)) != nullptr )
      {
        if ( *((_DWORD *)v24 - 1) != -1008624849 )
          __break(0x8228u);
        v24(v4, v23, 16, v22);
      }
      else
      {
        writel_relaxed_0((unsigned int)v22, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v23 << *(_DWORD *)(v4 + 28)) + 16LL);
      }
    }
  }
LABEL_25:
  v25 = *(_QWORD *)(v4 + 48);
  v26 = v3[4];
  v27 = *(_DWORD *)(v4 + 24) + a2;
  if ( v25 && (v28 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v25 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v28 - 1) != -1008624849 )
      __break(0x8228u);
    v28(v4, v27, 48, v26);
  }
  else
  {
    writel_relaxed_0((unsigned int)v26, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v27 << *(_DWORD *)(v4 + 28)) + 48LL);
  }
  v29 = *(_DWORD *)(v4 + 24) + a2;
  if ( *(_DWORD *)(v5 + 16) == 3 )
  {
    v30 = *(_QWORD *)(v4 + 48);
    v31 = *(unsigned __int16 *)(v5 + 2);
    if ( v30 && (v32 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v30 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v32 - 1) != -1008624849 )
        __break(0x8228u);
      v32(v4, v29, 52, v31);
    }
    else
    {
      writel_relaxed_0(
        *(unsigned __int16 *)(v5 + 2),
        *(_QWORD *)(v4 + 8) + (int)((_DWORD)v29 << *(_DWORD *)(v4 + 28)) + 52LL);
    }
    v33 = *(_QWORD *)(v4 + 48);
    v34 = *v3;
    v35 = *(_DWORD *)(v4 + 24) + a2;
    if ( v33 && (v36 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v33 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v36 - 1) != -1008624849 )
        __break(0x8228u);
      v36(v4, v35, 32, v34);
    }
    else
    {
      writel_relaxed_0((unsigned int)v34, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v35 << *(_DWORD *)(v4 + 28)) + 32LL);
    }
    v37 = *(_QWORD *)(v4 + 48);
    v38 = v3[2];
    v39 = *(_DWORD *)(v4 + 24) + a2;
    if ( v37 && (v40 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v37 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v40 - 1) != -1008624849 )
        __break(0x8228u);
      v40(v4, v39, 40, v38);
      if ( !v6 )
        goto LABEL_51;
    }
    else
    {
      writel_relaxed_0((unsigned int)v38, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v39 << *(_DWORD *)(v4 + 28)) + 40LL);
      if ( !v6 )
        goto LABEL_51;
    }
LABEL_45:
    v48 = *(_QWORD *)(v4 + 48);
    v49 = v3[6];
    v50 = *(_DWORD *)(v4 + 24) + a2;
    if ( v48 && (v51 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v48 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v51 - 1) != -1008624849 )
        __break(0x8228u);
      v51(v4, v50, 56, v49);
    }
    else
    {
      writel_relaxed_0((unsigned int)v49, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v50 << *(_DWORD *)(v4 + 28)) + 56LL);
    }
    v52 = *(_QWORD *)(v4 + 48);
    v53 = v3[7];
    v54 = *(_DWORD *)(v4 + 24) + a2;
    if ( v52 && (v55 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v52 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v55 - 1) != -1008624849 )
        __break(0x8228u);
      v55(v4, v54, 60, v53);
    }
    else
    {
      writel_relaxed_0((unsigned int)v53, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v54 << *(_DWORD *)(v4 + 28)) + 60LL);
    }
    goto LABEL_51;
  }
  v41 = *(_QWORD *)(v4 + 48);
  v42 = *(_QWORD *)v3;
  if ( v41 )
  {
    v43 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v41 + 24);
    if ( v43 )
    {
      if ( *((_DWORD *)v43 - 1) != 1922493645 )
        __break(0x8228u);
      v43(v4, v29, 32, v42);
      if ( !v6 )
        goto LABEL_51;
      goto LABEL_42;
    }
  }
  writeq_relaxed(*(_QWORD *)v3, *(_QWORD *)(v4 + 8) + (int)((_DWORD)v29 << *(_DWORD *)(v4 + 28)) + 32LL);
  if ( v6 )
  {
LABEL_42:
    v44 = *(_QWORD *)(v4 + 48);
    v45 = *((_QWORD *)v3 + 1);
    v46 = *(_DWORD *)(v4 + 24) + a2;
    if ( v44 && (v47 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v44 + 24)) != nullptr )
    {
      if ( *((_DWORD *)v47 - 1) != 1922493645 )
        __break(0x8228u);
      v47(v4, v46, 40, v45);
    }
    else
    {
      writeq_relaxed(*((_QWORD *)v3 + 1), *(_QWORD *)(v4 + 8) + (int)((_DWORD)v46 << *(_DWORD *)(v4 + 28)) + 40LL);
    }
    goto LABEL_45;
  }
LABEL_51:
  v56 = *(_QWORD *)(v4 + 48);
  if ( !v56 )
  {
    LODWORD(v60) = v3[8];
    LODWORD(v14) = *(_DWORD *)(v4 + 24) + a2;
LABEL_58:
    v16 = *(_DWORD *)(v4 + 28);
    v17 = *(_QWORD *)(v4 + 8);
    v18 = (unsigned int)v60;
    return writel_relaxed_0(v18, v17 + (int)((_DWORD)v14 << v16));
  }
  v57 = *(_DWORD **)(v56 + 144);
  if ( v57 )
  {
    v58 = v3[8];
    if ( *(v57 - 1) != 1590729357 )
      __break(0x8229u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v57)(v4, a2, v58);
  }
  v15 = *(_DWORD **)(v56 + 8);
  v60 = v3[8];
  v14 = *(_DWORD *)(v4 + 24) + a2;
  if ( !v15 )
    goto LABEL_58;
  a1 = v4;
LABEL_95:
  if ( *(v15 - 1) != -1008624849 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v15)(a1, v14, 0, v60);
}
