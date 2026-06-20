__int64 __fastcall aw_rtp_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  int v7; // w20
  void (__fastcall *v8)(_QWORD); // x8
  _DWORD *v9; // x8
  void (__fastcall *v10)(_QWORD); // x8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  v6 = kstrtouint(a3, 0, &v12);
  if ( v6 < 0 )
  {
    v7 = v6;
    printk(&unk_162DB, "haptic_hv", 2614, "aw_rtp_store");
    a4 = v7;
  }
  else
  {
    mutex_lock(v5 + 584);
    v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 56LL);
    if ( *((_DWORD *)v8 - 1) != -2072377296 )
      __break(0x8228u);
    v8(v5 - 168);
    v9 = *(_DWORD **)(*(_QWORD *)(v5 + 1312) + 272LL);
    if ( *(v9 - 1) != 487251822 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v9)(v5 - 168, 0);
    v10 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 240LL);
    if ( *((_DWORD *)v10 - 1) != -2072377296 )
      __break(0x8228u);
    v10(v5 - 168);
    if ( (unsigned int)(v12 - 1) > 3 )
    {
      printk(&unk_158A0, "haptic_hv", 2631, "aw_rtp_store");
    }
    else
    {
      *(_DWORD *)(v5 - 24) = v12;
      printk(&unk_14C20, "haptic_hv", 2627, "aw_rtp_store");
      queue_work_on(32, *(_QWORD *)(v5 + 928), v5 + 760);
    }
    mutex_unlock(v5 + 584);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
