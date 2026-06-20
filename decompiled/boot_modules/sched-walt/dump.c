__int64 __fastcall dump(
        __int16 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w20
  int v9; // w26
  __int64 result; // x0
  void (__fastcall *v12)(_QWORD); // x8
  void (__fastcall *v13)(_QWORD); // x8
  void (__fastcall *v14)(_QWORD); // x8
  _QWORD v15[12]; // [xsp+0h] [xbp-60h] BYREF

  v15[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v15, 0, 88);
  if ( !a1 )
  {
    result = printk(&unk_61D9B);
    goto LABEL_5;
  }
  v8 = *((_DWORD *)a1 + 7);
  v9 = *((_DWORD *)a1 + 8);
  result = ((__int64 (__fastcall *)(__int16 *, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64))getMostFrequent)(
             a1,
             v15,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8);
  if ( *a1 < 1 )
  {
    if ( v8 == v9 )
      goto LABEL_5;
    goto LABEL_4;
  }
  v12 = *((void (__fastcall **)(_QWORD))a1 + 9);
  if ( *((_DWORD *)v12 - 1) != -1066802076 )
    __break(0x8228u);
  v12(a1);
  v13 = *((void (__fastcall **)(_QWORD))a1 + 13);
  if ( *((_DWORD *)v13 - 1) != -1066802076 )
    __break(0x8228u);
  v13(a1);
  v14 = *((void (__fastcall **)(_QWORD))a1 + 12);
  if ( *((_DWORD *)v14 - 1) != -1066802076 )
    __break(0x8228u);
  v14(a1);
  for ( result = printk(&unk_62FA4); v8 != v9; v8 = (v8 + 1) % *((_DWORD *)a1 + 6) )
LABEL_4:
    result = printk(&unk_66016);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
