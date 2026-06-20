__int64 __fastcall pmic_gpio_of_xlate(__int64 a1, __int64 a2, _DWORD *a3)
{
  if ( *(_DWORD *)(a1 + 592) < 2u )
    return 4294967274LL;
  if ( a3 )
    *a3 = *(_DWORD *)(a2 + 16);
  return (unsigned int)(*(_DWORD *)(a2 + 12) - 1);
}
