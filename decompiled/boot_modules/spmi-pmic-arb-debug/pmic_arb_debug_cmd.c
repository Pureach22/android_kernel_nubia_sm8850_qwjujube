__int64 __fastcall pmic_arb_debug_cmd(__int64 a1, unsigned __int8 a2)
{
  if ( (unsigned int)a2 - 20 >= 0xFFFFFFFC )
    return 4294967201LL;
  else
    return 4294967274LL;
}
