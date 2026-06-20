__int64 __fastcall pmic_arb_cmd(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  if ( (unsigned __int8)(a2 - 20) < 0xFCu )
    return 4294967274LL;
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 56LL) + 56LL);
  if ( *((_DWORD *)v3 - 1) != -1901230658 )
    __break(0x8228u);
  return v3(a1, a2);
}
