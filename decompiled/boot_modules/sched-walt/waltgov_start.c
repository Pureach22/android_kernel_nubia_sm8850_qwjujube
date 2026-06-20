__int64 __fastcall waltgov_start(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x8
  __int64 v4; // x8
  char v5; // w12
  bool v6; // zf
  unsigned __int64 v7; // x12
  unsigned __int64 v8; // x12
  bool v9; // cf
  _QWORD *v10; // x13
  char v11; // w13
  unsigned __int64 v12; // x13
  unsigned __int64 v13; // x13
  __int64 v14; // x15
  _QWORD *v15; // x14

  v1 = *(_QWORD *)(a1 + 88);
  v3 = *(_QWORD *)(v1 + 40);
  *(_QWORD *)(v1 + 176) = 1000LL * *(unsigned int *)(v3 + 168);
  *(_QWORD *)(v1 + 184) = 1000LL * *(unsigned int *)(v3 + 172);
  mutex_lock(&min_rate_lock);
  v4 = *(_QWORD *)(v1 + 176);
  if ( v4 >= *(_QWORD *)(v1 + 184) )
    v4 = *(_QWORD *)(v1 + 184);
  *(_QWORD *)(v1 + 168) = v4;
  mutex_unlock(&min_rate_lock);
  v5 = 0;
  *(_QWORD *)(v1 + 160) = 0;
  *(_QWORD *)(v1 + 192) = 0;
  *(_WORD *)(v1 + 392) = 0;
  do
  {
    v7 = (unsigned int)(-1LL << v5) & *(_DWORD *)a1;
    v6 = (_DWORD)v7 == 0;
    v8 = __clz(__rbit64(v7));
    if ( v6 )
      v8 = 32;
    if ( (unsigned int)v8 > 0x1F )
      break;
    v9 = v8 >= 0x1F;
    v10 = (_QWORD *)((char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v8));
    v10[1] = v1;
    v10[2] = 0;
    *((_DWORD *)v10 + 4) = v8;
    v5 = v8 + 1;
    v10[9] = 0;
    v10[10] = 0;
    v10[7] = 0;
    v10[8] = 0;
    v10[5] = 0;
    v10[6] = 0;
    v10[3] = 0;
    v10[4] = 0;
    *v10 = 0;
  }
  while ( !v9 );
  v11 = 0;
  do
  {
    v12 = (unsigned int)(-1LL << v11) & *(_DWORD *)a1;
    if ( !(_DWORD)v12 )
      break;
    v13 = __clz(__rbit64(v12));
    v14 = *((_QWORD *)&_per_cpu_offset + v13);
    v15 = (_QWORD *)((char *)&waltgov_cpu + v14);
    if ( !(_UNKNOWN *)((char *)&waltgov_cpu + v14) || *(_QWORD *)((char *)&waltgov_cb_data + v14) )
    {
      __break(0x800u);
    }
    else
    {
      *v15 = waltgov_update_freq;
      atomic_store(
        (unsigned __int64)v15,
        (unsigned __int64 *)((char *)&waltgov_cb_data + *((_QWORD *)&_per_cpu_offset + v13)));
    }
    v9 = v13 >= 0x1F;
    v11 = v13 + 1;
  }
  while ( !v9 );
  waltgov_disabled = 0;
  return 0;
}
