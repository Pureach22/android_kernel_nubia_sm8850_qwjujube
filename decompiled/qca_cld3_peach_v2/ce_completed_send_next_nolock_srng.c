__int64 __fastcall ce_completed_send_next_nolock_srng(
        __int64 *a1,
        _QWORD *a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        _DWORD *a5,
        _DWORD *a6,
        __int64 a7,
        __int64 a8,
        _DWORD *a9)
{
  __int64 v9; // x28
  __int64 v10; // x26
  __int64 v16; // x20
  int v17; // w27
  unsigned int v19; // w19
  __int64 v20; // x7
  unsigned int v21; // w8
  __int64 v22; // x9
  unsigned int *v23; // x27
  __int64 v24; // x8
  int v26; // [xsp+Ch] [xbp-4h]

  v9 = a1[17];
  v10 = *a1;
  v17 = *(_DWORD *)(v9 + 4);
  v16 = *(unsigned int *)(v9 + 8);
  if ( !(unsigned int)hal_srng_access_start_1(*(_QWORD *)(*a1 + 2560)) )
  {
    v20 = *(_QWORD *)(v9 + 80);
    v21 = (unsigned int)(*(_DWORD *)(v20 + 44) + *(_DWORD *)(v20 + 124)) % *(_DWORD *)(v20 + 36);
    if ( v21 == *(_DWORD *)(v20 + 136)
      || (v22 = *(_QWORD *)(v20 + 16),
          *(_DWORD *)(v20 + 124) = v21,
          v26 = v17,
          v20 = *(_QWORD *)(v9 + 80),
          (v23 = (unsigned int *)(v22 + 4LL * v21)) == nullptr) )
    {
      v19 = 16;
      v24 = *(_QWORD *)(v20 + 88);
      if ( (v24 & 1) != 0 )
      {
LABEL_10:
        *(_QWORD *)(v20 + 88) = v24 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v20 + 80);
        return v19;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, unsigned int *, _QWORD, _QWORD))hif_record_ce_srng_desc_event)(
        v10,
        *((unsigned int *)a1 + 2),
        5,
        v23,
        *(_QWORD *)(*(_QWORD *)(v9 + 88) + 8 * v16),
        (unsigned int)v16);
      *a4 = *v23 | ((unsigned __int64)(unsigned __int8)*(_QWORD *)(v23 + 1) << 32);
      *a5 = *((unsigned __int16 *)v23 + 3);
      *a6 = *((unsigned __int16 *)v23 + 4);
      *a9 = 0;
      if ( a2 )
        *a2 = a1[10];
      if ( a3 )
        *a3 = *(_QWORD *)(*(_QWORD *)(v9 + 88) + 8 * v16);
      v19 = 0;
      *(_QWORD *)(*(_QWORD *)(v9 + 88) + 8 * v16) = 0;
      v20 = *(_QWORD *)(v9 + 80);
      *(_DWORD *)(v9 + 8) = (v16 + 1) & v26;
      v24 = *(_QWORD *)(v20 + 88);
      if ( (v24 & 1) != 0 )
        goto LABEL_10;
    }
    raw_spin_unlock(v20 + 80);
    return v19;
  }
  return 16;
}
