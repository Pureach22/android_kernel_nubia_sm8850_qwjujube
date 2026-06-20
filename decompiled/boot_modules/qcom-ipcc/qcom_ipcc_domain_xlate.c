__int64 __fastcall qcom_ipcc_domain_xlate(__int64 a1, __int64 a2, __int64 a3, int a4, _QWORD *a5, int *a6)
{
  if ( a4 != 3 )
    return 4294967274LL;
  *a5 = (unsigned int)*(unsigned __int16 *)(a3 + 4) | (*(_DWORD *)a3 << 16);
  *a6 = *(_DWORD *)(a3 + 8) & 0xF;
  return 0;
}
