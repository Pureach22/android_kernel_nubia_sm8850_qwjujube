__int64 __fastcall audio_off(_QWORD *a1)
{
  _DWORD *v2; // x8
  void (__fastcall *v3)(_QWORD); // x8
  _QWORD *v4; // x9
  _QWORD *v5; // x22
  __int64 v6; // x8

  printk(&unk_14A18, "haptic_hv", 1893, "audio_off");
  mutex_lock(a1 + 94);
  v2 = *(_DWORD **)(a1[185] + 136LL);
  if ( *(v2 - 1) != 487251822 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, __int64))v2)(a1, 128);
  v3 = *(void (__fastcall **)(_QWORD))(a1[185] + 56LL);
  if ( *((_DWORD *)v3 - 1) != -2072377296 )
    __break(0x8228u);
  v3(a1);
  v4 = (_QWORD *)a1[179];
  if ( v4 != a1 + 178 )
  {
    do
    {
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (v6 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v4 - 1);
      v4 = v5;
    }
    while ( v5 != a1 + 178 );
  }
  return mutex_unlock(a1 + 94);
}
