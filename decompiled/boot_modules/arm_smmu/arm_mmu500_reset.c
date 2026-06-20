__int64 __fastcall arm_mmu500_reset(__int64 *a1)
{
  __int64 (**v1)(void); // x8
  __int64 (*v3)(void); // x8
  char v4; // w0
  _DWORD **v5; // x8
  char v6; // w20
  _DWORD *v7; // x8
  unsigned int v8; // w0
  __int64 v9; // x10
  unsigned int v10; // w8
  _DWORD *v11; // x10
  int v12; // w21
  __int64 (__fastcall **v13)(__int64 *, __int64, __int64); // x8
  __int64 v14; // x1
  __int64 (__fastcall *v15)(__int64 *, __int64, __int64); // x8
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x1
  _DWORD *v19; // x8
  __int64 (__fastcall **v20)(__int64 *, __int64, __int64); // x8
  __int64 v21; // x1
  __int64 (__fastcall *v22)(__int64 *, __int64, __int64); // x8
  __int64 v23; // x0

  v1 = (__int64 (**)(void))a1[6];
  if ( v1 && (v3 = *v1) != nullptr )
  {
    if ( *((_DWORD *)v3 - 1) != 616069899 )
      __break(0x8228u);
    v4 = v3();
  }
  else
  {
    v4 = readl_relaxed(a1[1] + 60);
  }
  v5 = (_DWORD **)a1[6];
  v6 = v4;
  if ( v5 && (v7 = *v5) != nullptr )
  {
    if ( *(v7 - 1) != 616069899 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64))v7)(a1, 0, 16);
  }
  else
  {
    v8 = readl_relaxed(a1[1] + 16);
  }
  v9 = a1[6];
  v10 = v8 & 0xFBFFFAFF;
  if ( (v6 & 0xE0) == 0 )
    v10 = v8;
  if ( v9 && (v11 = *(_DWORD **)(v9 + 8)) != nullptr )
  {
    if ( *(v11 - 1) != -1008624849 )
      __break(0x822Au);
    ((void (__fastcall *)(__int64 *, _QWORD, __int64, _QWORD))v11)(a1, 0, 16, v10 | 0x500);
    if ( *((_DWORD *)a1 + 14) )
      goto LABEL_12;
  }
  else
  {
    writel_relaxed(v10 | 0x500, a1[1] + 16);
    if ( *((_DWORD *)a1 + 14) )
    {
LABEL_12:
      v12 = 0;
      while ( 1 )
      {
        v13 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))a1[6];
        v14 = (unsigned int)(v12 + *((_DWORD *)a1 + 6));
        if ( v13 && (v15 = *v13) != nullptr )
        {
          if ( *((_DWORD *)v15 - 1) != 616069899 )
            __break(0x8228u);
          v16 = v15(a1, v14, 4);
        }
        else
        {
          v16 = readl_relaxed(a1[1] + (int)((_DWORD)v14 << *((_DWORD *)a1 + 7)) + 4);
        }
        v17 = a1[6];
        v18 = (unsigned int)(v12 + *((_DWORD *)a1 + 6));
        if ( v17 && (v19 = *(_DWORD **)(v17 + 8)) != nullptr )
        {
          if ( *(v19 - 1) != -1008624849 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, __int64, __int64, _QWORD))v19)(a1, v18, 4, v16 & 0xFFFFFFFD);
        }
        else
        {
          writel_relaxed(v16 & 0xFFFFFFFD, a1[1] + (int)((_DWORD)v18 << *((_DWORD *)a1 + 7)) + 4);
        }
        v20 = (__int64 (__fastcall **)(__int64 *, __int64, __int64))a1[6];
        v21 = (unsigned int)(v12 + *((_DWORD *)a1 + 6));
        if ( v20 )
        {
          v22 = *v20;
          if ( v22 )
            break;
        }
        if ( (readl_relaxed(a1[1] + (int)((_DWORD)v21 << *((_DWORD *)a1 + 7)) + 4) & 2) != 0 )
          goto LABEL_23;
LABEL_13:
        if ( (unsigned int)++v12 >= *((_DWORD *)a1 + 14) )
          return 0;
      }
      if ( *((_DWORD *)v22 - 1) != 616069899 )
        __break(0x8228u);
      if ( (v22(a1, v21, 4) & 2) == 0 )
        goto LABEL_13;
LABEL_23:
      if ( (arm_mmu500_reset___print_once & 1) == 0 )
      {
        v23 = *a1;
        arm_mmu500_reset___print_once = 1;
        dev_warn(v23, "Failed to disable prefetcher [errata #841119 and #826419], check ACR.CACHE_LOCK\n");
      }
      goto LABEL_13;
    }
  }
  return 0;
}
