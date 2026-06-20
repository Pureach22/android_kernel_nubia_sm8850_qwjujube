__int64 __fastcall repeat_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v5; // x20
  __int64 v6; // x21
  __int64 result; // x0
  void (__fastcall *v8)(_QWORD); // x8
  int v9; // w8
  __int64 v10; // x8
  int v11; // w2
  int v12; // w9
  _DWORD *v13; // x9
  int v14; // w20
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 152);
  v15 = 0;
  v6 = v5[42];
  LODWORD(result) = kstrtoint(a3, 10, &v15);
  if ( (_DWORD)result )
  {
    result = (int)result;
    goto LABEL_3;
  }
  result = -22;
  if ( v15 >= -1 && v15 )
  {
    mutex_lock(v6 + 8216);
    if ( *(_DWORD *)(v6 + 8284) == 1 )
      hrtimer_cancel(v6 + 8328);
    else
      timer_delete_sync(v6 + 8288);
    if ( *(_DWORD *)(v6 + 8284) == 2 )
    {
      v8 = (void (__fastcall *)(_QWORD))v5[9];
      if ( *((_DWORD *)v8 - 1) != 1697309055 )
        __break(0x8228u);
      v8(v5);
    }
    v9 = v15;
    *(_DWORD *)(v6 + 8268) = v15;
    *(_DWORD *)(v6 + 8272) = v9;
    *(_BYTE *)(v6 + 8280) = v9 == -1;
    v10 = v5[42];
    v11 = *(_DWORD *)(v10 + 8264);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v10 + 8284);
      if ( v12 == 2 )
      {
        v13 = (_DWORD *)v5[8];
        if ( *(v13 - 1) != -1238539376 )
          __break(0x8229u);
        v14 = ((__int64 (__fastcall *)(_QWORD *, __int64))v13)(v5, v10 + 8);
        mutex_unlock(v6 + 8216);
        if ( v14 >= 0 )
          result = a4;
        else
          result = v14;
        goto LABEL_3;
      }
      if ( v11 == 1 )
      {
        mutex_unlock(v6 + 8216);
        result = -22;
        goto LABEL_3;
      }
      *(_DWORD *)(v10 + 8276) = 0;
      *(_QWORD *)(v10 + 8200) = v10 + 8;
      *(_QWORD *)(v10 + 8208) = v10 + 16;
      if ( v12 == 1 )
      {
        hrtimer_start_range_ns(v10 + 8328, 0, 0, 1);
      }
      else
      {
        *(_QWORD *)(v10 + 8304) = jiffies;
        add_timer(v10 + 8288);
      }
    }
    mutex_unlock(v6 + 8216);
    result = a4;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
