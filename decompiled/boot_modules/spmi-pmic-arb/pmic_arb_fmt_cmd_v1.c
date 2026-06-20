__int64 __fastcall pmic_arb_fmt_cmd_v1(int a1, char a2, unsigned __int16 a3, char a4)
{
  return (a1 << 27) | ((a2 & 0xF) << 20) | (16 * a3) | a4 & 7u;
}
