__int64 __fastcall qmp_sdca_dmic_hw_free(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w11
  int v7; // w17
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x20
  bool v11; // zf
  unsigned int v12; // w20
  int v13; // w8

  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  v9 = *(_QWORD *)(v8 + 16);
  if ( !v9 )
    return 4294967274LL;
  v10 = *(unsigned int *)(a2 + 8);
  if ( (((unsigned __int64)*(int *)(v8 + 200) >> v10) & 1) == 0 )
    return 0;
  if ( (unsigned int)v10 < 3 )
  {
    stream_agg_remove_channel(a1, *(unsigned __int8 *)(v8 + v10 + 204), (_DWORD)v10 == 1, *(unsigned __int8 *)(v9 + 64));
    v11 = (_DWORD)v10 == 1;
    if ( (_DWORD)v10 == 1 )
      v12 = 2;
    else
      v12 = 1;
    if ( v11
      || (v13 = *(_DWORD *)(v8 + 168) - 1,
          v11 = *(_DWORD *)(v8 + 168) == 1,
          *(_DWORD *)(v8 + 168) = v13 & ~(v13 >> 31),
          v13 < 0 || v11) )
    {
      regmap_write(*(_QWORD *)v8, (v12 << 22) | 0x40000108, 3);
      wait_for_pde_state(v8, 3, v12);
    }
    return 0;
  }
  __break(0x5512u);
  return qmp_sdca_dmic_prepare(a1, a2, a3, a4, a5, a6, v6 | __ROR4__(v7, 39));
}
