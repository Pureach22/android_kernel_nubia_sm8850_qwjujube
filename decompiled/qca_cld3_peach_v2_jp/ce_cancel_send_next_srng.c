__int64 __fastcall ce_cancel_send_next_srng(
        _QWORD *a1,
        _QWORD *a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7)
{
  __int64 v7; // x19
  __int64 v10; // x20
  int v11; // w21
  __int64 v18; // x8
  unsigned int v19; // w10
  __int64 v20; // x9
  unsigned int *v21; // x9
  int v22; // w8
  unsigned int v23; // w20
  __int64 v24; // x8
  __int64 v25; // x9

  v7 = a1[17];
  if ( !v7 )
    return 16;
  v11 = *(_DWORD *)(v7 + 4);
  v10 = *(unsigned int *)(v7 + 8);
  if ( (unsigned int)hal_srng_access_start_1(*(_QWORD *)(*a1 + 2560LL)) )
    return 16;
  v18 = *(_QWORD *)(v7 + 80);
  v19 = (unsigned int)(*(_DWORD *)(v18 + 44) + *(_DWORD *)(v18 + 124)) % *(_DWORD *)(v18 + 36);
  if ( v19 == *(_DWORD *)(v18 + 120)
    || (v20 = *(_QWORD *)(v18 + 16), *(_DWORD *)(v18 + 124) = v19, (v21 = (unsigned int *)(v20 + 4LL * v19)) == nullptr) )
  {
    v22 = 16;
  }
  else
  {
    *a4 = *v21 | ((unsigned __int64)(unsigned __int8)*(_QWORD *)(v21 + 1) << 32);
    *a5 = *((unsigned __int16 *)v21 + 3);
    *a6 = *((unsigned __int16 *)v21 + 4);
    *a7 = 0;
    if ( a2 )
      *a2 = a1[10];
    if ( a3 )
      *a3 = *(_QWORD *)(*(_QWORD *)(v7 + 88) + 8 * v10);
    v22 = 0;
    *(_QWORD *)(*(_QWORD *)(v7 + 88) + 8 * v10) = 0;
    *(_DWORD *)(v7 + 8) = (v10 + 1) & v11;
  }
  v23 = v22;
  v24 = *(_QWORD *)(v7 + 80);
  v25 = *(_QWORD *)(v24 + 88);
  if ( (v25 & 1) != 0 )
  {
    *(_QWORD *)(v24 + 88) = v25 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v24 + 80);
  }
  else
  {
    raw_spin_unlock(v24 + 80);
  }
  return v23;
}
