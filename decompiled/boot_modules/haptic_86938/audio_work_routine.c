__int64 __fastcall audio_work_routine(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x23
  _QWORD *v4; // x21
  unsigned int v5; // w8
  unsigned int v6; // w9
  bool v7; // cf
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned int v11; // w24
  int v12; // w25
  _QWORD *v13; // x9
  int v14; // w8
  __int64 v15; // x8
  _QWORD *v16; // x9
  _QWORD *v17; // x0
  _QWORD *v18; // x8
  __int64 v19; // x10
  __int64 (__fastcall *v20)(_QWORD); // x8
  int v21; // w22
  __int64 result; // x0
  int v23; // w8
  __int64 v24; // x20
  void (__fastcall *v25)(_QWORD); // x8
  void (__fastcall *v26)(__int64, __int64); // x8
  __int64 v27; // x2
  _DWORD *v28; // x8
  _DWORD *v29; // x8
  __int64 v30; // x2
  _DWORD *v31; // x8
  __int64 v32; // x1
  void (__fastcall *v33)(__int64, __int64); // x8
  __int64 v34; // x0
  __int64 v35; // x1
  void (__fastcall *v36)(__int64, __int64); // x8
  void (__fastcall *v37)(_QWORD); // x8
  _QWORD *v38; // x10

  v1 = a1 - 112;
  mutex_lock(a1 - 112);
  v3 = *(_QWORD **)(a1 + 56);
  v4 = (_QWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  if ( v3 == (_QWORD *)(a1 + 48) )
  {
    printk(&unk_140DE, "haptic_hv", 1954, "audio_work_routine");
  }
  else
  {
    if ( (_QWORD *)*v4 == v4 )
      v5 = 0;
    else
      v5 = *(unsigned __int8 *)(*v4 - 8LL);
    v6 = *((unsigned __int8 *)v3 - 8);
    v7 = v5 >= v6;
    v8 = v5 - v6;
    if ( v7 )
      v9 = v8;
    else
      v9 = 0;
    v10 = v8 + 32;
    if ( v7 )
      v11 = v9;
    else
      v11 = v10;
    if ( v11 >= 3 )
    {
      v12 = 0;
      do
      {
        if ( v3 == v4 )
          break;
        v13 = v3;
        v14 = *((unsigned __int8 *)v3 - 6);
        v3 = (_QWORD *)v3[1];
        if ( !v14 && (*((_BYTE *)v13 - 7) & 0xF) == 1 )
        {
          if ( (_QWORD *)*v3 == v13 && (v15 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
          {
            *(_QWORD *)(v15 + 8) = v3;
            *v3 = v15;
          }
          else
          {
            _list_del_entry_valid_or_report(v13);
          }
          *v13 = 0xDEAD000000000100LL;
          v13[1] = 0xDEAD000000000122LL;
          kfree(v13 - 1);
          ++v12;
        }
      }
      while ( v12 != v11 );
    }
  }
  v16 = *(_QWORD **)(a1 + 56);
  if ( v16 != v4 )
  {
    v17 = v16 - 1;
    *(_BYTE *)(a1 + 64) = *((_BYTE *)v16 - 8);
    *(_BYTE *)(a1 + 65) = *((_BYTE *)v16 - 7);
    *(_BYTE *)(a1 + 66) = *((_BYTE *)v16 - 6);
    *(_BYTE *)(a1 + 69) = *((_BYTE *)v16 - 3);
    *(_BYTE *)(a1 + 67) = *((_BYTE *)v16 - 5);
    *(_BYTE *)(a1 + 68) = *((_BYTE *)v16 - 4);
    v18 = (_QWORD *)v16[1];
    if ( (_QWORD *)*v18 == v16 && (v19 = *v16, *(_QWORD **)(*v16 + 8LL) == v16) )
    {
      *(_QWORD *)(v19 + 8) = v18;
      *v18 = v19;
    }
    else
    {
      _list_del_entry_valid_or_report(v16);
      v17 = v38;
    }
    *v16 = 0xDEAD000000000100LL;
    v16[1] = 0xDEAD000000000122LL;
    kfree(v17);
  }
  if ( *(_BYTE *)(a1 + 66) )
    printk(&unk_15029, "haptic_hv", 2013, "audio_work_routine");
  v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 104) + 40LL);
  if ( *((_DWORD *)v20 - 1) != 1361900016 )
    __break(0x8228u);
  v21 = v20(a1 - 1376);
  result = mutex_unlock(v1);
  if ( !v21 && *(_BYTE *)(a1 + 65) == 1 )
  {
    v23 = *(unsigned __int8 *)(a1 + 66);
    if ( v23 == 2 )
    {
      v24 = a1 - 624;
      mutex_lock(a1 - 624);
      v37 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 104) + 56LL);
      if ( *((_DWORD *)v37 - 1) != -2072377296 )
        __break(0x8228u);
      v37(a1 - 1376);
    }
    else
    {
      if ( v23 == 8 )
      {
        v24 = a1 - 624;
        mutex_lock(a1 - 624);
        v35 = *(unsigned __int8 *)(a1 + 68);
        v34 = a1 - 1376;
        v36 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 104) + 136LL);
      }
      else
      {
        if ( v23 != 1 )
          return result;
        printk(&unk_16231, "haptic_hv", 2102, "audio_work_routine");
        v24 = a1 - 624;
        mutex_lock(a1 - 624);
        v25 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 104) + 56LL);
        if ( *((_DWORD *)v25 - 1) != -2072377296 )
          __break(0x8228u);
        v25(a1 - 1376);
        v26 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 104) + 152LL);
        if ( *((_DWORD *)v26 - 1) != 487251822 )
          __break(0x8228u);
        v26(a1 - 1376, 1);
        v27 = *(unsigned __int8 *)(a1 + 69);
        v28 = *(_DWORD **)(*(_QWORD *)(a1 + 104) + 192LL);
        if ( *(v28 - 1) != 2072477285 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v28)(a1 - 1376, 0, v27);
        v29 = *(_DWORD **)(*(_QWORD *)(a1 + 104) + 192LL);
        if ( *(v29 - 1) != 2072477285 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v29)(a1 - 1376, 1, 0);
        v30 = *(unsigned __int8 *)(a1 + 67);
        v31 = *(_DWORD **)(*(_QWORD *)(a1 + 104) + 200LL);
        if ( *(v31 - 1) != 2072477285 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v31)(a1 - 1376, 0, v30);
        v32 = *(unsigned __int8 *)(a1 + 68);
        v33 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 104) + 136LL);
        if ( *((_DWORD *)v33 - 1) != 487251822 )
          __break(0x8228u);
        v33(a1 - 1376, v32);
        v34 = a1 - 1376;
        v35 = 1;
        v36 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 104) + 96LL);
      }
      if ( *((_DWORD *)v36 - 1) != 487251822 )
        __break(0x8228u);
      v36(v34, v35);
    }
    return mutex_unlock(v24);
  }
  return result;
}
