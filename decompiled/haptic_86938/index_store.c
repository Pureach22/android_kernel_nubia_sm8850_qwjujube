__int64 __fastcall index_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x8
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v6 = kstrtouint(a3, 0, &v10);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else if ( v10 <= *(unsigned __int8 *)(v5 + 948) )
  {
    printk(&unk_14087, "haptic_hv", 2420, "index_store");
    mutex_lock(v5 + 584);
    v8 = *(_QWORD *)(v5 + 1312);
    *(_DWORD *)(v5 - 100) = v10;
    v9 = *(void (__fastcall **)(_QWORD))(v8 + 168);
    if ( *((_DWORD *)v9 - 1) != 487251822 )
      __break(0x8228u);
    v9(v5 - 168);
    mutex_unlock(v5 + 584);
  }
  else
  {
    printk(&unk_15BE3, "haptic_hv", 2417, "index_store");
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
