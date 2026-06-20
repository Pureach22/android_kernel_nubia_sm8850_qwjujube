__int64 __fastcall available_governors_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w20

  v4 = scnprintf(a3, 4096, "%s ", "FREQ_MON_GOV");
  return (int)(scnprintf(a3 + v4, 4096LL - v4, "%s\n", "BW_MON_RATIO_GOV") + v4);
}
