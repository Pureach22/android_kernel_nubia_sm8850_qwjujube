unsigned __int64 __fastcall drm_dp_atomic_release_time_slots(__int64 a1, __int64 a2, _QWORD *a3)
{
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // t1
  __int64 v8; // x19
  __int64 v9; // x8
  _QWORD *v10; // x19
  __int64 v11; // t1
  const void *v12; // x21
  _BOOL4 v13; // w22
  __int64 v14; // x8
  char v15; // w8
  unsigned __int64 result; // x0
  _QWORD *v18; // x20
  __int64 v19; // x8
  __int64 v20; // x1
  unsigned __int64 v21; // x19
  const void *v22; // x4
  char v23; // w8
  char v24; // w9
  __int64 v25; // x8
  const void *v26; // x3
  __int64 v27; // x0

  v3 = *(_DWORD *)(a3[203] + 152LL);
  if ( v3 >= *(_DWORD *)(a1 + 40) )
  {
    v10 = (_QWORD *)&unk_8;
    v6 = 8;
    v9 = 0x12FB00001F2FALL;
LABEL_6:
    v14 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 56LL * *(unsigned int *)(v9 + 160) + 24);
    if ( !v14 )
      return 0;
    v15 = *(_BYTE *)(v14 + 10);
    if ( (v15 & 0xE) == 0 )
      return 0;
    v12 = a3;
    v13 = (v15 & 0xA) != 0;
    goto LABEL_9;
  }
  v4 = *(_QWORD *)(a1 + 48);
  v5 = *(_QWORD *)(v4 + 40LL * v3 + 16);
  v7 = *(_QWORD *)(v5 + 8);
  v6 = v5 + 8;
  if ( !v7 )
    return 0;
  v8 = *(_QWORD *)(v4 + 40LL * v3 + 24);
  v11 = *(_QWORD *)(v8 + 8);
  v10 = (_QWORD *)(v8 + 8);
  v9 = v11;
  if ( v11 )
    goto LABEL_6;
  v12 = a3;
  v13 = 1;
LABEL_9:
  result = drm_atomic_get_private_obj_state();
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  *(_DWORD *)(result + 24) |= 1 << *(_DWORD *)(*(_QWORD *)v6 + 160LL);
  if ( v13 )
  {
    v18 = (_QWORD *)(result + 56);
    do
    {
      v18 = (_QWORD *)*v18;
      if ( v18 == (_QWORD *)(result + 56) )
        goto LABEL_23;
    }
    while ( (const void *)*(v18 - 4) != v12 );
    if ( v18 == (_QWORD *)&unk_20 )
    {
LABEL_23:
      __break(0x800u);
      v25 = *(_QWORD *)(a2 + 104);
      v26 = (const void *)result;
      if ( v25 )
        v27 = *(_QWORD *)(v25 + 8);
      else
        v27 = 0;
      dev_err(v27, "[drm] *ERROR* No payload for [MST PORT:%p] found in mst state %p\n", v12, v26);
      return 4294967274LL;
    }
    if ( !*v10 )
    {
      v19 = *(_QWORD *)(a2 + 104);
      if ( v19 )
      {
        v20 = *(_QWORD *)(v19 + 8);
        v21 = result;
        v22 = v12;
      }
      else
      {
        v21 = result;
        v22 = v12;
        v20 = 0;
      }
      _drm_dev_dbg(0, v20, 4, "[MST PORT:%p] TU %d -> 0\n", v22, *((_DWORD *)v18 - 5));
      v23 = *((_BYTE *)v18 - 12);
      if ( (v23 & 1) == 0 )
      {
        v24 = *((_BYTE *)v18 - 23);
        *((_DWORD *)v18 - 4) = 0;
        *((_BYTE *)v18 - 12) = v23 | 1;
        *(_DWORD *)(v21 + 48) &= ~(unsigned int)(1LL << (v24 - 1));
      }
    }
  }
  return 0;
}
