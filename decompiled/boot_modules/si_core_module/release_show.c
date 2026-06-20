__int64 __fastcall release_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d %d\n", pending_releases, release_failed);
}
