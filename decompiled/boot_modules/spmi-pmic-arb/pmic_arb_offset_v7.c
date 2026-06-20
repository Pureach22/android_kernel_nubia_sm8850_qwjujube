__int64 __fastcall pmic_arb_offset_v7(_QWORD *a1, unsigned __int8 a2, unsigned __int16 a3, int a4)
{
  __int64 v4; // x23
  int v5; // w20
  __int64 (*v9)(void); // x8
  __int64 result; // x0

  v4 = *a1;
  v5 = a2;
  v9 = *(__int64 (**)(void))(*(_QWORD *)(*a1 + 56LL) + 32LL);
  if ( *((_DWORD *)v9 - 1) != -817839700 )
    __break(0x8228u);
  result = v9();
  if ( (result & 0x80000000) == 0 )
  {
    if ( a4 )
    {
      if ( a4 == 1 )
        return 32 * (unsigned __int16)result + (*(unsigned __int8 *)(v4 + 49) << 15);
      else
        return 0;
    }
    else if ( *(unsigned __int8 *)(a1[19] + 4LL * (unsigned __int16)result + 2) == *(unsigned __int8 *)(v4 + 49) )
    {
      return (unsigned __int16)result << 12;
    }
    else
    {
      dev_err(a1[5], "disallowed SPMI write to sid=%u, addr=0x%04X\n", v5, a3);
      return 0xFFFFFFFFLL;
    }
  }
  return result;
}
