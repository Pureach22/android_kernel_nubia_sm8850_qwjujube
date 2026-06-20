__int64 __fastcall adreno_gmu_context_queue_write(__int64 a1, __int64 a2, int *a3, __int64 a4, __int64 a5, __int64 *a6)
{
  _DWORD *v6; // x24
  unsigned int v7; // w19
  __int64 v8; // x8
  unsigned int v9; // w25
  unsigned int v10; // w9
  bool v11; // cc
  unsigned int v12; // w10
  unsigned int v13; // w9
  _DWORD *v15; // x10
  bool v16; // cf
  int v17; // w9
  unsigned int v18; // w11
  __int64 v19; // x12
  int v21; // t1
  unsigned int v22; // w11
  void (*v24)(void); // x8

  v6 = *(_DWORD **)(a2 + 8);
  v7 = (unsigned int)a4 >> 2;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  v9 = v6[6];
  v10 = v6[5];
  v12 = v10 - v9;
  v11 = v10 > v9;
  v13 = (((unsigned int)a4 >> 2) + 3) & 0x7FFFFFFC;
  if ( !v11 )
    v12 += v6[2];
  if ( v12 <= v13 )
    return 4294967268LL;
  if ( (a4 & 3) != 0 )
    return 4294967274LL;
  v15 = v6 + 12;
  if ( (unsigned int)a4 >= 4 )
  {
    v18 = v6[2];
    v19 = (unsigned int)a4 >> 2;
    do
    {
      v21 = *a3++;
      v15[v9] = v21;
      --v19;
      v9 = (v9 + 1) % v18;
    }
    while ( v19 );
    v16 = v7 >= v13;
    v17 = v7 - v13;
    if ( v16 )
      goto LABEL_17;
    goto LABEL_14;
  }
  v16 = v13 == 0;
  v17 = -v13;
  if ( !v16 )
  {
LABEL_14:
    v22 = v6[2];
    do
    {
      v15[v9] = -84215046;
      v16 = __CFADD__(v17++, 1);
      v9 = (v9 + 1) % v22;
    }
    while ( !v16 );
  }
LABEL_17:
  __dsb(0xEu);
  if ( a5 )
  {
    if ( (*(_BYTE *)(a5 + 16) & 4) != 0 )
    {
      v24 = *(void (**)(void))(v8 + 152);
      if ( *((_DWORD *)v24 - 1) != -944375624 )
        __break(0x8228u);
      v24();
    }
    else
    {
      adreno_hwsched_add_profile_events(a1, a5, a6, a4);
      adreno_profile_submit_time(a6);
    }
  }
  __dsb(0xEu);
  v6[6] = v9;
  __dsb(0xEu);
  return 0;
}
