bool __fastcall dp_fisa_aggregation_should_stop(__int64 a1, int a2, unsigned __int16 a3, __int64 a4, __int64 a5)
{
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w20
  int v12; // w25
  __int64 v13; // x8
  __int64 v14; // x8
  void (__fastcall *v15)(__int64, char *, __int64 *, int *); // x8
  void (__fastcall *v16)(__int64, int *, int *); // x8
  _BOOL8 result; // x0
  unsigned int v18; // w9
  int v19; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  int v21; // [xsp+10h] [xbp-10h] BYREF
  int v22; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 200) + 256LL) + 74392LL) + 1272LL);
  if ( *((_DWORD *)v10 - 1) != 855462014 )
    __break(0x8228u);
  v11 = v10(a4);
  v12 = *(unsigned __int16 *)(a1 + 194);
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 200) + 256LL);
  v22 = 0;
  v21 = 0;
  v14 = *(_QWORD *)(v13 + 74392);
  v20 = 0;
  v19 = 0;
  v15 = *(void (__fastcall **)(__int64, char *, __int64 *, int *))(v14 + 1496);
  if ( *((_DWORD *)v15 - 1) != -1038736894 )
    __break(0x8228u);
  v15(a4, (char *)&v20 + 4, &v20, &v19);
  v16 = *(void (__fastcall **)(__int64, int *, int *))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 200) + 256LL) + 74392LL)
                                                     + 1296LL);
  if ( *((_DWORD *)v16 - 1) != 348550285 )
    __break(0x8228u);
  v16(a4, &v22, &v21);
  result = 1;
  if ( !*(_BYTE *)(a1 + 192) && !v20 && v11 >= v21 + v22 + 72 && *(unsigned __int16 *)(a1 + 194) < (unsigned int)a3 )
  {
    v18 = a3 - v12;
    if ( v18 <= 0x5C6 && *(_DWORD *)(a1 + 216) + 1 == a2 && v18 == v11 - (v21 + v22) )
      result = v11 != *(unsigned __int16 *)(a5 + 60);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
