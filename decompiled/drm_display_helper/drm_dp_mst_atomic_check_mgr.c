__int64 __fastcall drm_dp_mst_atomic_check_mgr(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  unsigned int v7; // w21
  _QWORD *v8; // x25
  int v9; // w28
  int v10; // w27
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // x1
  int v16; // w21
  int v17; // w6
  int v18; // w8
  int v19; // w5
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x8
  __int64 v26; // x1

  *a4 = 0;
  if ( (*(_BYTE *)(a2 + 896) & 1) == 0 )
    return 0;
  mutex_lock(a2 + 800);
  v7 = drm_dp_mst_atomic_check_mstb_bw_limit(*(_QWORD *)(a2 + 904), a3, a4);
  mutex_unlock(a2 + 800);
  if ( (v7 & 0x80000000) != 0 )
    return v7;
  v8 = *(_QWORD **)(a3 + 56);
  v9 = *(unsigned __int8 *)(a3 + 72);
  if ( v8 != (_QWORD *)(a3 + 56) )
  {
    v10 = 0;
    do
    {
      v13 = *(_QWORD *)(a2 + 104);
      if ( (*((_BYTE *)v8 - 12) & 1) != 0 )
      {
        if ( v13 )
          v14 = *(_QWORD *)(v13 + 8);
        else
          v14 = 0;
        _drm_dev_dbg(0, v14, 4, "[MST PORT:%p] releases all time slots\n", (const void *)*(v8 - 4));
      }
      else
      {
        if ( v13 )
          v15 = *(_QWORD *)(v13 + 8);
        else
          v15 = 0;
        _drm_dev_dbg(0, v15, 4, "[MST PORT:%p] requires %d time slots\n", (const void *)*(v8 - 4), *((_DWORD *)v8 - 5));
        v16 = v9 - *((_DWORD *)v8 - 5);
        if ( v16 < 0 )
        {
          v23 = *(_QWORD *)(a2 + 104);
          if ( v23 )
            v24 = *(_QWORD *)(v23 + 8);
          else
            v24 = 0;
          _drm_dev_dbg(
            0,
            v24,
            4,
            "[MST PORT:%p] not enough time slots in mst state %p (avail=%d)\n",
            (const void *)*(v8 - 4),
            (const void *)a3,
            v9);
          return 4294967268LL;
        }
        v17 = *(_DWORD *)(a2 + 136);
        if ( ++v10 > v17 )
        {
          v25 = *(_QWORD *)(a2 + 104);
          if ( v25 )
            v26 = *(_QWORD *)(v25 + 8);
          else
            v26 = 0;
          _drm_dev_dbg(
            0,
            v26,
            4,
            "[MST MGR:%p] state %p has too many payloads (max=%d)\n",
            (const void *)a2,
            (const void *)a3,
            v17);
          return 4294967274LL;
        }
        if ( !*((_BYTE *)v8 - 23) )
        {
          v18 = __clz(__rbit64((unsigned int)~*(_DWORD *)(a3 + 48)));
          v19 = v18 + 1;
          *((_BYTE *)v8 - 23) = v18 + 1;
          v20 = *(_QWORD *)(a2 + 104);
          if ( v20 )
            v12 = *(_QWORD *)(v20 + 8);
          else
            v12 = 0;
          _drm_dev_dbg(0, v12, 4, "[MST PORT:%p] assigned VCPI #%d\n", (const void *)*(v8 - 4), v19);
          *(_DWORD *)(a3 + 48) |= 1LL << (*((_BYTE *)v8 - 23) - 1);
        }
        v9 = v16;
      }
      v8 = (_QWORD *)*v8;
    }
    while ( v8 != (_QWORD *)(a3 + 56) );
    if ( v10 )
      goto LABEL_26;
  }
  *(_DWORD *)(a3 + 76) = 0;
LABEL_26:
  v21 = *(_QWORD *)(a2 + 104);
  if ( v21 )
    v22 = *(_QWORD *)(v21 + 8);
  else
    v22 = 0;
  _drm_dev_dbg(
    0,
    v22,
    4,
    "[MST MGR:%p] mst state %p TU pbn_div=%d avail=%d used=%d\n",
    (const void *)a2,
    (const void *)a3,
    *(_DWORD *)(a3 + 76) >> 12,
    v9,
    *(unsigned __int8 *)(a3 + 72) - v9);
  return 0;
}
