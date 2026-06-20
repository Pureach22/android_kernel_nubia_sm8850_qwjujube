__int64 __fastcall show_enable(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%u\n", *(unsigned __int8 *)(a1 + 136));
}
