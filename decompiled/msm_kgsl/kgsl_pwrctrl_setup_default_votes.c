__int64 __fastcall kgsl_pwrctrl_setup_default_votes(__int64 a1)
{
  int v1; // w20
  unsigned int v3; // w0
  __int64 v4; // x8
  _DWORD *v5; // x8
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 14232) != 1 )
    return 0;
  v1 = *(_DWORD *)(a1 + 10040);
  v3 = kgsl_pwrctrl_adjust_pwrlevel(a1, *(_DWORD *)(a1 + 10052));
  v4 = *(_QWORD *)(a1 + 8752);
  *(_DWORD *)(a1 + 10040) = v3;
  *(_DWORD *)(a1 + 10044) = v1;
  v5 = *(_DWORD **)(v4 + 248);
  if ( *(v5 - 1) != -1642886764 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1, v3);
  if ( !(_DWORD)result )
    return kgsl_pwrctrl_axi(a1, 1);
  return result;
}
