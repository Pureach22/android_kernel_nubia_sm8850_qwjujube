__int64 __fastcall pmic_arb_fmt_cmd_v2(int a1, __int64 a2, unsigned __int8 a3, char a4)
{
  return (16 * a3) | (a1 << 27) | a4 & 7u;
}
