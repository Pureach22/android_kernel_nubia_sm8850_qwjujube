__int64 __fastcall snapshot_legacy_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%d\n", *(unsigned __int8 *)(a1 + 11306));
}
