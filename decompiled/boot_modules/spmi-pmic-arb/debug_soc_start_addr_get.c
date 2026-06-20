__int64 __fastcall debug_soc_start_addr_get(unsigned int *a1, _QWORD *a2)
{
  __int64 v3; // x2
  _DWORD *v4; // x8
  __int64 result; // x0
  _QWORD v6[13]; // [xsp+8h] [xbp-68h] BYREF

  v6[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[46];
  v4 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 112LL);
  memset(v6, 0, 96);
  if ( *(v4 - 1) != 364718830 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(unsigned int *, _QWORD, __int64, _QWORD *))v4)(a1, WORD1(v3) & 0x1F, v3, v6);
  if ( !(_DWORD)result )
    *a2 = v6[0];
  _ReadStatusReg(SP_EL0);
  return result;
}
