__int64 __fastcall slc_mpam_start_stop(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x0
  __int64 (__fastcall **v5)(__int64, __int64 *, __int64, __int64, __int64); // x9
  __int64 (__fastcall *v6)(__int64, __int64 *, __int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 )
  {
    v3 = *(unsigned int *)(v2 + 12);
    v9 = a2;
    v8 = v3;
    v5 = *(__int64 (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(v2 + 40);
    v4 = *(_QWORD *)(v2 + 48);
    v6 = *v5;
    if ( *((_DWORD *)*v5 - 1) != 1737159351 )
      __break(0x8228u);
    result = v6(v4, &v8, 0x534C434D50414DLL, 4, 12);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
