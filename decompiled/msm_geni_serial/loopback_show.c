__int64 __fastcall loopback_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4, "%d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 912LL));
}
