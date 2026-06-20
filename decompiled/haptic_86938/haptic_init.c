__int64 __fastcall haptic_init(__int64 a1)
{
  char v2; // w9
  __int64 v3; // x10
  _DWORD *v4; // x8
  void (__fastcall *v5)(__int64, __int64); // x8
  void (__fastcall *v6)(_QWORD); // x8
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x1
  void (__fastcall *v9)(__int64, __int64); // x8
  _DWORD *v10; // x8
  _DWORD *v11; // x8
  void (__fastcall *v12)(_QWORD); // x8
  void (__fastcall *v13)(__int64, __int64); // x8

  printk(&unk_14A18, "haptic_hv", 4075, "haptic_init");
  *(_QWORD *)(a1 + 1240) = 0x534600000001LL;
  *(_QWORD *)(a1 + 1424) = a1 + 1424;
  *(_QWORD *)(a1 + 1432) = a1 + 1424;
  hrtimer_init(a1 + 1312, 1, 1);
  *(_QWORD *)(a1 + 1352) = audio_timer_func;
  *(_QWORD *)(a1 + 1376) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 1384) = a1 + 1384;
  *(_QWORD *)(a1 + 1392) = a1 + 1384;
  *(_QWORD *)(a1 + 1400) = audio_work_routine;
  _mutex_init(a1 + 1264, "&aw_haptic->haptic_audio.lock", &haptic_init___key_249);
  *(_QWORD *)(a1 + 1408) = a1 + 1408;
  *(_QWORD *)(a1 + 1416) = a1 + 1408;
  mutex_lock(a1 + 752);
  v2 = *(_BYTE *)(a1 + 1120);
  v3 = *(_QWORD *)(a1 + 1480);
  *(_QWORD *)(a1 + 124) = 255;
  *(_BYTE *)(a1 + 19) = 0;
  *(_BYTE *)(a1 + 29) = 0;
  *(_BYTE *)(a1 + 27) = v2;
  *(_DWORD *)(a1 + 1760) = 5;
  v4 = *(_DWORD **)(v3 + 152);
  if ( *(v4 - 1) != 487251822 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v4)(a1, 0);
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 128LL);
  if ( *((_DWORD *)v5 - 1) != 487251822 )
    __break(0x8228u);
  v5(a1, 1);
  v6 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 256LL);
  if ( *((_DWORD *)v6 - 1) != -2072377296 )
    __break(0x8228u);
  v6(a1);
  v7 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 112LL);
  if ( *((_DWORD *)v7 - 1) != -2072377296 )
    __break(0x8228u);
  v7(a1);
  v8 = *(unsigned int *)(a1 + 48);
  v9 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 160LL);
  if ( *((_DWORD *)v9 - 1) != 487251822 )
    __break(0x8228u);
  v9(a1, v8);
  v10 = *(_DWORD **)(*(_QWORD *)(a1 + 1480) + 216LL);
  if ( *(v10 - 1) != 2072477285 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v10)(a1, 1, 0);
  v11 = *(_DWORD **)(*(_QWORD *)(a1 + 1480) + 176LL);
  if ( *(v11 - 1) != 487251822 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v11)(a1, 0);
  v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 80LL);
  if ( *((_DWORD *)v12 - 1) != -2072377296 )
    __break(0x8228u);
  v12(a1);
  v13 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 184LL);
  if ( *((_DWORD *)v13 - 1) != 487251822 )
    __break(0x8228u);
  v13(a1, 1);
  *(_BYTE *)(a1 + 28) = 0;
  return mutex_unlock(a1 + 752);
}
