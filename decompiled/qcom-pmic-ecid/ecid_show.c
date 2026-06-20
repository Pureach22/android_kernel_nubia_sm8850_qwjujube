__int64 __fastcall ecid_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 32, "%s\n", (const char *)(*(_QWORD *)(a1 + 152) + 8LL));
}
