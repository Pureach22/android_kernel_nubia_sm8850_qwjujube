__int64 __fastcall arm_smmu_rmr_install_bypass_smr(_QWORD *a1)
{
  _DWORD **v2; // x8
  _DWORD *v3; // x8
  int v4; // w0
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 *v7; // x8
  const char *v8; // x3
  int v9; // w2
  unsigned int v10; // w13
  unsigned int i; // w12
  __int64 v12; // x17
  int v13; // w0
  __int64 v14; // x13
  __int64 v15; // x15
  unsigned int v16; // w16
  int v17; // w0
  signed int v18; // w17
  __int16 *v19; // x1
  __int64 result; // x0
  _QWORD v21[3]; // [xsp+8h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = v21;
  v21[1] = v21;
  _dev_fwnode(*a1);
  v2 = (_DWORD **)a1[6];
  if ( v2 && (v3 = *v2) != nullptr )
  {
    if ( *(v3 - 1) != 616069899 )
      __break(0x8228u);
    v4 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD))v3)(a1, 0, 0);
    v5 = a1[6];
    if ( !v5 )
      goto LABEL_5;
  }
  else
  {
    v4 = readl_relaxed_0((unsigned int *)a1[1]);
    v5 = a1[6];
    if ( !v5 )
    {
LABEL_5:
      writel_relaxed_0(v4 | 1, (unsigned int *)a1[1]);
      goto LABEL_6;
    }
  }
  v6 = *(_DWORD **)(v5 + 8);
  if ( !v6 )
    goto LABEL_5;
  if ( *(v6 - 1) != -1008624849 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD))v6)(a1, 0, 0, v4 | 1u);
LABEL_6:
  v7 = (__int64 *)v21[0];
  v8 = "s";
  v9 = 0;
  if ( (_QWORD *)v21[0] != v21 )
  {
    do
    {
      v10 = *((_DWORD *)v7 + 14);
      if ( v10 )
      {
        for ( i = 0; i < v10; ++i )
        {
          v15 = a1[13];
          v16 = *(unsigned __int16 *)(v7[6] + 4LL * (int)i);
          if ( !v15 )
            goto LABEL_11;
          v17 = *((_DWORD *)a1 + 23);
          if ( v17 )
          {
            v18 = 0;
            v16 = -28;
            while ( 1 )
            {
              v19 = (__int16 *)(v15 + 8LL * v18);
              if ( (v19[3] & 1) != 0 )
                break;
              if ( (v16 & 0x80000000) != 0 )
                v16 = v18;
              if ( v17 == ++v18 )
                goto LABEL_24;
            }
            v16 = v18;
            if ( *v19 != -1 )
              continue;
LABEL_24:
            if ( (v16 & 0x80000000) == 0 )
            {
LABEL_11:
              v12 = a1[14];
              v13 = *(_DWORD *)(v12 + 24LL * v16 + 8);
              if ( !v13 )
              {
                *(_WORD *)(v15 + 8LL * v16 + 2) = *(_WORD *)(v7[6] + 4LL * (int)i);
                *(_WORD *)(a1[13] + 8LL * v16) = 0;
                *(_BYTE *)(a1[13] + 8LL * v16 + 4) = 1;
                *(_BYTE *)(a1[13] + 8LL * v16 + 6) = 1;
                v12 = a1[14];
                v13 = *(_DWORD *)(v12 + 24LL * v16 + 8);
              }
              ++v9;
              v14 = 24LL * v16;
              *(_DWORD *)(v12 + v14 + 8) = v13 + 1;
              *(_DWORD *)(a1[14] + v14 + 12) = 1;
              *(_DWORD *)(a1[14] + v14 + 16) = 0;
              v10 = *((_DWORD *)v7 + 14);
            }
          }
        }
      }
      v7 = (__int64 *)*v7;
    }
    while ( v7 != v21 );
    if ( v9 == 1 )
      v8 = (const char *)&unk_17C28;
  }
  dev_notice(*a1, "\tpreserved %d boot mapping%s\n", v9, v8);
  result = _dev_fwnode(*a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
