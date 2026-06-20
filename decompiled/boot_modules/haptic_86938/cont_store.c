__int64 __fastcall cont_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  void (__fastcall *v7)(_QWORD); // x8
  void (__fastcall *v8)(__int64, __int64); // x8
  void (__fastcall *v9)(_QWORD); // x8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v6 = kstrtouint(a3, 0, &v11);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    v7 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 56LL);
    if ( *((_DWORD *)v7 - 1) != -2072377296 )
      __break(0x8228u);
    v7(v5 - 168);
    if ( v11 )
    {
      v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1312) + 280LL);
      if ( *((_DWORD *)v8 - 1) != -746885483 )
        __break(0x8228u);
      v8(v5 - 168, 1);
      v9 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 72LL);
      if ( *((_DWORD *)v9 - 1) != -2072377296 )
        __break(0x8228u);
      v9(v5 - 168);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
