__int64 __fastcall tmc_sync_etr_buf(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v4; // x8
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x23
  __int64 v10; // x8
  unsigned int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x24
  __int64 result; // x0
  __int64 v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64, __int64); // x8
  __int64 v18; // x0
  _DWORD *v19; // x8
  __int64 v20; // x0
  _DWORD *v21; // x8

  v1 = a1[2];
  v2 = a1[15];
  v4 = *(_QWORD *)(v1 + 40);
  if ( *(_BYTE *)(v1 + 32) == 1 )
  {
    v5 = readl_relaxed_1((unsigned int *)(v4 + 20));
    v6 = *(_QWORD *)(v1 + 40);
    v7 = v5;
    v8 = (unsigned int)readl_relaxed_1((unsigned int *)(v6 + 56));
  }
  else
  {
    if ( *(_DWORD *)(v4 - 4) != -340433967 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v4)(20, 1, 0);
    v19 = *(_DWORD **)(v1 + 40);
    v7 = v18;
    if ( *(v19 - 1) != -340433967 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v19)(56, 1, 0);
  }
  v9 = a1[2];
  v10 = *(_QWORD *)(v9 + 40);
  if ( *(_BYTE *)(v9 + 32) == 1 )
  {
    v11 = readl_relaxed_1((unsigned int *)(v10 + 24));
    v12 = *(_QWORD *)(v9 + 40);
    v13 = v11;
    v14 = (unsigned int)readl_relaxed_1((unsigned int *)(v12 + 60));
  }
  else
  {
    if ( *(_DWORD *)(v10 - 4) != -340433967 )
      __break(0x8228u);
    v20 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(24, 1, 0);
    v21 = *(_DWORD **)(v9 + 40);
    v13 = v20;
    if ( *(v21 - 1) != -340433967 )
      __break(0x8228u);
    v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v21)(60, 1, 0);
  }
  result = readl_relaxed_1((unsigned int *)(a1[1] + 12LL));
  if ( (result & 0x20) != 0 )
  {
    __break(0x800u);
    *(_QWORD *)(v2 + 40) = 0;
    *(_BYTE *)(v2 + 8) = 0;
  }
  else
  {
    v16 = *(_QWORD *)(v2 + 48);
    *(_BYTE *)(v2 + 8) = result & 1;
    if ( !v16 || (v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v16 + 8)) == nullptr )
    {
      __break(0x800u);
      v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v2 + 48) + 8LL);
    }
    if ( *((_DWORD *)v17 - 1) != 1827367162 )
      __break(0x8228u);
    return v17(v2, v7 | (v8 << 32), v13 | (v14 << 32));
  }
  return result;
}
