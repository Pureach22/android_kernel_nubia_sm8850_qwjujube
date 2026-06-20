__int64 __fastcall pmic_arb_wait_for_done(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int16 a4)
{
  unsigned __int8 *v4; // x24
  __int64 (*v9)(void); // x8
  __int64 result; // x0
  __int64 v11; // x23
  int v12; // w26
  int v13; // w22

  v4 = *(unsigned __int8 **)(a1 + 152);
  v9 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)v4 + 56LL) + 40LL);
  if ( *((_DWORD *)v9 - 1) != 1307277261 )
    __break(0x8228u);
  result = v9();
  if ( (result & 0x80000000) == 0 )
  {
    v11 = (unsigned int)(result + 8);
    v12 = -1000;
    while ( 1 )
    {
      v13 = readl_relaxed((unsigned int *)(a2 + v11));
      if ( (v13 & 1) != 0 )
        break;
      _const_udelay(4295);
      if ( __CFADD__(v12++, 1) )
      {
        dev_err(a1, "%s: %#x %#x %#x: timeout, status %#x\n", "pmic_arb_wait_for_done", v4[168], a3, a4, v13);
        return 4294967186LL;
      }
    }
    if ( (v13 & 4) != 0 )
    {
      dev_err(a1, "%s: %#x %#x: transaction denied (%#x)\n", "pmic_arb_wait_for_done", a3, a4, v13);
      return 0xFFFFFFFFLL;
    }
    else if ( (v13 & 2) != 0 )
    {
      dev_err(a1, "%s: %#x %#x: transaction failed (%#x) reg: 0x%x\n", "pmic_arb_wait_for_done", a3, a4, v13, v11);
      __break(0x800u);
      return 4294967291LL;
    }
    else if ( (v13 & 8) != 0 )
    {
      dev_err(a1, "%s: %#x %#x: transaction dropped (%#x)\n", "pmic_arb_wait_for_done", a3, a4, v13);
      return 4294967291LL;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
