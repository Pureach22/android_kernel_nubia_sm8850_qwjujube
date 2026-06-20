__int64 __fastcall boost_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%d\n", *(_DWORD *)(a1 + 220));
}
