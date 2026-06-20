__int64 __fastcall sdhci_msm_set_timeout(__int64 a1, __int64 a2)
{
  unsigned int v4; // w8
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 result; // x0
  int v7; // w8

  v4 = *(_DWORD *)(*(_QWORD *)(a1 + 72) + 1440LL);
  if ( !v4 )
    v4 = *(_DWORD *)(a1 + 820);
  *(_DWORD *)(a1 + 808) = v4 / 0xFA0;
  _sdhci_set_timeout(a1, a2);
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 64) + 16LL);
  if ( !v5 )
  {
    result = readb(*(_QWORD *)(a1 + 24) + 46LL);
    if ( !a2 )
      return result;
    goto LABEL_5;
  }
  if ( *((_DWORD *)v5 - 1) != 1955121254 )
    __break(0x8228u);
  result = v5(a1, 46);
  if ( a2 )
  {
LABEL_5:
    if ( *(_QWORD *)(a2 + 40) )
    {
      v7 = *(_DWORD *)(a1 + 820);
      if ( (unsigned int)(v7 - 400001) <= 0x2F4D5FF && 0x8000 << result > (unsigned int)(10 * v7) )
        *(_QWORD *)(a1 + 1272) = 22000000000LL;
    }
  }
  return result;
}
