__int64 __fastcall mhi_gen_tre(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x24
  int v9; // w8
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  unsigned int v11; // w21
  __int64 v12; // x21
  __int64 v13; // x5
  bool v14; // zf
  int v15; // w9
  int v16; // w8
  int v17; // w6
  int v18; // w7
  __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8

  raw_write_lock_bh(a2 + 368);
  v8 = *(_QWORD *)(a2 + 56);
  if ( *(_BYTE *)(v8 + 52) == 1 )
    __break(0x800u);
  v9 = *(unsigned __int8 *)(a3 + 53);
  *(_BYTE *)(v8 + 53) = v9;
  if ( v9 == 1 )
    *(_QWORD *)(v8 + 32) = *(_QWORD *)(a3 + 32);
  else
    *(_QWORD *)v8 = *(_QWORD *)a3;
  *(_QWORD *)(v8 + 24) = *(_QWORD *)(a3 + 24);
  *(_QWORD *)(v8 + 16) = *(_QWORD *)(a2 + 152);
  *(_DWORD *)(v8 + 48) = *(_DWORD *)(a2 + 216);
  *(_QWORD *)(v8 + 40) = *(_QWORD *)(a3 + 40);
  if ( (*(_BYTE *)(a3 + 53) & 1) != 0 )
    goto LABEL_10;
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 552);
  if ( *((_DWORD *)v10 - 1) != -549273137 )
    __break(0x8228u);
  v11 = v10(a1, v8);
  if ( !v11 )
  {
LABEL_10:
    v12 = *(_QWORD *)(a2 + 152);
    v13 = *(_QWORD *)(v8 + 32);
    v14 = *(_DWORD *)(a2 + 208) == 0;
    *(_QWORD *)v12 = v13;
    v15 = (a4 >> 2) & 1 | ((a4 & 3) << 8);
    if ( v14 )
      v16 = 0x20000;
    else
      v16 = 132096;
    v17 = *(unsigned __int16 *)(a3 + 40);
    v18 = v15 | v16;
    *(_DWORD *)(v12 + 8) = v17;
    *(_DWORD *)(v12 + 12) = v15 | v16;
    v19 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v19 && !*(_DWORD *)(v19 + 24) )
      ipc_log_string(
        *(_QWORD *)(v19 + 32),
        "[D][%s] Chan: %d WP: 0x%llx TRE: 0x%llx 0x%08x 0x%08x\n",
        "mhi_gen_tre",
        *(_DWORD *)(a2 + 200),
        v12 - *(_QWORD *)(a2 + 136) + *(_QWORD *)(a2 + 112),
        v13,
        v17,
        v18);
    v11 = 0;
    v20 = *(_QWORD *)(a2 + 152) + *(_QWORD *)(a2 + 160);
    if ( v20 >= *(_QWORD *)(a2 + 136) + *(_QWORD *)(a2 + 168) )
      v20 = *(_QWORD *)(a2 + 136);
    *(_QWORD *)(a2 + 152) = v20;
    __dmb(0xAu);
    v21 = *(_QWORD *)(a2 + 56) + *(_QWORD *)(a2 + 64);
    if ( v21 >= *(_QWORD *)(a2 + 40) + *(_QWORD *)(a2 + 72) )
      v21 = *(_QWORD *)(a2 + 40);
    *(_QWORD *)(a2 + 56) = v21;
    __dmb(0xAu);
  }
  raw_write_unlock_bh(a2 + 368);
  return v11;
}
