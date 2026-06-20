__int64 __fastcall ifas_enable_show(__int64 a1, __int64 a2, __int64 a3)
{
  int ifas_enable; // w0

  ifas_enable = get_ifas_enable();
  return (int)scnprintf(a3, 4096, "%d\n", ifas_enable);
}
