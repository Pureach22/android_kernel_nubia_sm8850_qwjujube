__int64 __fastcall cqhci_enable(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  char v4; // w9
  int v5; // w8
  __int64 v6; // x20
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  int v8; // w0
  _DWORD *v9; // x8
  int v10; // w9
  __int64 v11; // x20
  int v12; // w10
  __int64 v13; // x9
  char v14; // w11
  __int64 v15; // x9
  int v16; // w12
  int v17; // w8
  int v18; // w12
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x0
  int v24; // w22
  int v25; // w27
  __int64 v26; // x26
  int v27; // w28
  _BYTE *v28; // x21
  __int64 v29; // x8
  void (__fastcall *v30)(__int64, __int64); // x8
  __int64 v31; // x1

  if ( *(_BYTE *)(a2 + 1282) != 1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 1464);
  if ( (*(_BYTE *)(v2 + 56) & 1) != 0 )
    return 0;
  v4 = *(_BYTE *)(v2 + 48);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 924);
  if ( (v4 & 1) != 0 )
  {
    v6 = a1;
    v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 16LL);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != 1427797680 )
        __break(0x8228u);
      v8 = v7(v2, 8);
    }
    else
    {
      v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(v2 + 8) + 8LL));
    }
    v9 = *(_DWORD **)(*(_QWORD *)v2 + 8LL);
    if ( v9 )
    {
      if ( *(v9 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v9)(v2, v8 | 0x100u, 8);
    }
    else
    {
      writel_relaxed(v8 | 0x100, (unsigned int *)(*(_QWORD *)(v2 + 8) + 8LL));
    }
    v5 = 16;
    a1 = v6;
  }
  else
  {
    v5 = 8;
  }
  v10 = *(unsigned __int8 *)(v2 + 32);
  v11 = a1;
  *(_BYTE *)(v2 + 89) = v5;
  if ( v10 == 1 )
  {
    v12 = 16;
    if ( (*(_DWORD *)(v2 + 52) & 1) != 0 )
      v13 = 12;
    else
      v13 = 16;
    if ( (*(_DWORD *)(v2 + 52) & 1) != 0 )
      v14 = 12;
    else
      v14 = 16;
    v15 = v13 << 32;
  }
  else
  {
    v15 = 0x800000000LL;
    v14 = 8;
    v12 = 8;
  }
  v16 = *(_DWORD *)(v2 + 36);
  v17 = v12 + v5;
  *(_BYTE *)(v2 + 104) = v14;
  *(_BYTE *)(v2 + 88) = v17;
  v18 = v16 * v17;
  v19 = *(_QWORD *)(v2 + 16);
  *(_BYTE *)(v2 + 90) = v12;
  *(_QWORD *)(v2 + 64) = v18;
  *(_QWORD *)(v2 + 72) = (v15 * *(unsigned __int8 *)(v19 + 1472) * (unsigned __int64)*(unsigned __int16 *)(v19 + 1016)) >> 32;
  v20 = dmam_alloc_attrs(*(_QWORD *)v19, v18, v2 + 112, 3264, 0);
  *(_QWORD *)(v2 + 80) = v20;
  if ( v20 )
  {
    v23 = dmam_alloc_attrs(**(_QWORD **)(v2 + 16), *(_QWORD *)(v2 + 72), v2 + 120, 3264, 0);
    *(_QWORD *)(v2 + 96) = v23;
    if ( v23 )
    {
      if ( *(int *)(v2 + 36) >= 1 )
      {
        v24 = 0;
        do
        {
          v25 = *(unsigned __int8 *)(v2 + 104);
          v26 = *(_QWORD *)(v2 + 120);
          v27 = *(unsigned __int16 *)(*(_QWORD *)(v2 + 16) + 1016LL);
          v28 = (_BYTE *)(*(_QWORD *)(v2 + 80)
                        + *(unsigned __int8 *)(v2 + 88) * (unsigned __int64)(unsigned __int8)v24
                        + *(unsigned __int8 *)(v2 + 89));
          memset(v28, 0, *(unsigned __int8 *)(v2 + 90));
          if ( *(unsigned __int8 *)(v2 + 90) >= 9u )
            v28[8] = 0;
          if ( (unsigned __int8)v24 == 31 && (*(_BYTE *)(*(_QWORD *)(v2 + 16) + 1003LL) & 1) != 0 )
          {
            *v28 = 2;
          }
          else
          {
            *v28 = 49;
            v29 = v26 + (unsigned __int8)v24 * v25 * v27;
            if ( *(_BYTE *)(v2 + 32) == 1 )
              *(_QWORD *)(v28 + 4) = v29;
            else
              *((_DWORD *)v28 + 1) = v29;
          }
          ++v24;
        }
        while ( v24 < *(_DWORD *)(v2 + 36) );
      }
      _cqhci_enable(v2);
      v30 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 72LL);
      if ( v30 )
      {
        if ( *((_DWORD *)v30 - 1) != -289083512 )
          __break(0x8228u);
        v30(v11, 1);
      }
      result = 0;
      *(_BYTE *)(v2 + 56) = 1;
      return result;
    }
    dmam_free_coherent(**(_QWORD **)(v2 + 16), *(_QWORD *)(v2 + 64), *(_QWORD *)(v2 + 80), *(_QWORD *)(v2 + 112));
    *(_QWORD *)(v2 + 80) = 0;
    *(_QWORD *)(v2 + 112) = 0;
  }
  v31 = *(_QWORD *)(v11 + 120);
  if ( !v31 )
    v31 = *(_QWORD *)(v11 + 8);
  printk(&unk_A112, v31, 4294967284LL, v21, v22);
  return 4294967284LL;
}
