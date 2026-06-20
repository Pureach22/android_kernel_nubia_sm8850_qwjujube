unsigned __int64 __fastcall pattern_trig_store_patterns(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        int a5)
{
  _DWORD *v10; // x24
  void (__fastcall *v11)(_QWORD); // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x8
  int v14; // w26
  _DWORD *v15; // x27
  __int64 v16; // x9
  int v17; // w8
  unsigned int v18; // w10
  unsigned __int64 v19; // x11
  unsigned int v20; // w9
  _DWORD *v21; // x10
  __int64 v22; // x8
  int v23; // w2
  int v24; // w9
  _DWORD *v25; // x9
  int v26; // w20
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (_DWORD *)a1[42];
  mutex_lock(v10 + 2054);
  if ( v10[2071] == 1 )
    hrtimer_cancel(v10 + 2082);
  else
    timer_delete_sync(v10 + 2072);
  if ( v10[2071] == 2 )
  {
    v11 = (void (__fastcall *)(_QWORD))a1[9];
    if ( *((_DWORD *)v11 - 1) != 1697309055 )
      __break(0x8228u);
    v11(a1);
  }
  v10[2071] = a5;
  v10[2066] = 0;
  if ( a2 )
  {
    if ( a4 != 1 )
    {
      v12 = 0;
      v13 = 0;
      v14 = 0;
      v15 = v10 + 2;
      while ( v12 < 0x400 )
      {
        v28 = 0;
        if ( sscanf((const char *)(a2 + v13), "%u %u %n", &v15[2 * v12 + 1], &v15[2 * v12], &v28) != 2 )
          goto LABEL_32;
        v16 = (unsigned int)v10[2066];
        if ( (unsigned int)v16 > 0x3FF )
          goto LABEL_38;
        if ( v15[2 * v16 + 1] > *(_DWORD *)(*(_QWORD *)v10 + 12LL) )
        {
LABEL_32:
          v10[2066] = 0;
          mutex_unlock(v10 + 2054);
          a4 = -22;
          goto LABEL_37;
        }
        v17 = v28;
        v12 = v16 + 1;
        v10[2066] = v12;
        v14 += v17;
        v13 = v14;
        if ( a4 - 1 <= v14 )
          break;
      }
    }
  }
  else if ( a4 )
  {
    v18 = 0;
    v19 = 0;
    v20 = 2;
    do
    {
      if ( v18 >= 0x400 )
LABEL_38:
        __break(0x5512u);
      v21 = &v10[2 * v18 + 2];
      v21[1] = *(_DWORD *)(a3 + 4 * v19);
      *v21 = *(_DWORD *)(a3 + 4LL * (v20 - 1));
      v19 = v20;
      v20 += 2;
      v18 = v10[2066] + 1;
      v10[2066] = v18;
    }
    while ( v19 < a4 );
  }
  v22 = a1[42];
  v23 = *(_DWORD *)(v22 + 8264);
  if ( !v23 )
    goto LABEL_36;
  v24 = *(_DWORD *)(v22 + 8284);
  if ( v24 == 2 )
  {
    v25 = (_DWORD *)a1[8];
    if ( *(v25 - 1) != -1238539376 )
      __break(0x8229u);
    v26 = ((__int64 (__fastcall *)(_QWORD *, __int64))v25)(a1, v22 + 8);
    if ( !v26 )
      goto LABEL_36;
  }
  else
  {
    if ( v23 != 1 )
    {
      *(_DWORD *)(v22 + 8276) = 0;
      *(_QWORD *)(v22 + 8200) = v22 + 8;
      *(_QWORD *)(v22 + 8208) = v22 + 16;
      if ( v24 == 1 )
      {
        hrtimer_start_range_ns(v22 + 8328, 0, 0, 1);
      }
      else
      {
        *(_QWORD *)(v22 + 8304) = jiffies;
        add_timer(v22 + 8288);
      }
LABEL_36:
      mutex_unlock(v10 + 2054);
      goto LABEL_37;
    }
    v26 = -22;
  }
  v10[2066] = 0;
  mutex_unlock(v10 + 2054);
  if ( v26 < 0 )
    a4 = v26;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return a4;
}
