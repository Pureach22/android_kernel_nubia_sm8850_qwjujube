__int64 __fastcall get_ram_num(__int64 a1)
{
  char v1; // w8
  void (__fastcall *v3)(_QWORD); // x8
  void (__fastcall *v4)(__int64, __int64); // x8
  void (__fastcall *v5)(_QWORD); // x8
  void (__fastcall *v6)(__int64, unsigned __int16 *); // x8
  _DWORD *v7; // x8
  __int64 result; // x0
  unsigned __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(a1 + 6);
  v9 = 0;
  if ( (v1 & 1) != 0 )
  {
    mutex_lock(a1 + 752);
    v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 56LL);
    if ( *((_DWORD *)v3 - 1) != -2072377296 )
      __break(0x8228u);
    v3(a1);
    v4 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 104LL);
    if ( *((_DWORD *)v4 - 1) != 487251822 )
      __break(0x8228u);
    v4(a1, 1);
    v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 248LL);
    if ( *((_DWORD *)v5 - 1) != -2072377296 )
      __break(0x8228u);
    v5(a1);
    v6 = *(void (__fastcall **)(__int64, unsigned __int16 *))(*(_QWORD *)(a1 + 1480) + 304LL);
    if ( *((_DWORD *)v6 - 1) != 331536012 )
      __break(0x8228u);
    v6(a1, &v9);
    *(_BYTE *)(a1 + 1116) = (__rev16(v9) + ~*(_DWORD *)(a1 + 1112)) >> 2;
    printk(&unk_16180, "haptic_hv", 631, "get_ram_num");
    printk(&unk_15A08, "haptic_hv", 632, "get_ram_num");
    v7 = *(_DWORD **)(*(_QWORD *)(a1 + 1480) + 104LL);
    if ( *(v7 - 1) != 487251822 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v7)(a1, 0);
    result = mutex_unlock(a1 + 752);
  }
  else
  {
    result = printk(&unk_1578D, "haptic_hv", 616, "get_ram_num");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
