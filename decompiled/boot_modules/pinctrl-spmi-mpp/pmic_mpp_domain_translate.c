__int64 __fastcall pmic_mpp_domain_translate(__int64 a1, _DWORD *a2, _QWORD *a3, _DWORD *a4)
{
  unsigned int v4; // w8

  if ( a2[2] != 2 )
    return 4294967274LL;
  v4 = a2[3];
  if ( !v4 || v4 > *(unsigned __int16 *)(*(_QWORD *)(a1 + 32) + 172LL) )
    return 4294967274LL;
  *a3 = v4 - 1;
  *a4 = a2[4];
  return 0;
}
