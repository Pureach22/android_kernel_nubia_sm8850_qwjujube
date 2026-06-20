__int64 __fastcall cpufreq_walt_get_adaptive_freq(_QWORD *a1, unsigned int *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // x13
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned int v9; // w10
  unsigned int v10; // w9
  __int64 v11; // x9
  unsigned int v12; // w10
  unsigned int v13; // w9
  __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w8

  if ( (unsigned int)a1 >= 0x20 )
  {
    __break(0x5512u);
    *a1 = v4;
    JUMPOUT(0x463A8);
  }
  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  v5 = *((_QWORD *)&_per_cpu_offset + (unsigned int)a1);
  if ( ((_cpu_possible_mask >> (char)a1) & 1) == 0 )
    return 4294967282LL;
  result = 4294967274LL;
  if ( a2 && a3 && a4 )
  {
    result = 0;
    v7 = *(_QWORD *)((char *)&waltgov_cpu + v5 + 8);
    v8 = *(_QWORD *)(v7 + 40);
    v9 = *(_DWORD *)(v8 + 192);
    v10 = *(_DWORD *)(v8 + 204);
    if ( v9 > v10 )
      v10 = v9;
    *a2 = v10;
    v11 = *(_QWORD *)(v7 + 40);
    v12 = *(_DWORD *)(v11 + 196);
    v13 = *(_DWORD *)(v11 + 208);
    if ( v12 > v13 )
      v13 = v12;
    *a3 = v13;
    v14 = *(_QWORD *)(v7 + 40);
    v15 = *(_DWORD *)(v14 + 200);
    v16 = *(_DWORD *)(v14 + 212);
    if ( v15 > v16 )
      v16 = v15;
    *a4 = v16;
  }
  return result;
}
