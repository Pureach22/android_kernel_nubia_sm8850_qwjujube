__int64 __fastcall masters_show(__int64 a1, int a2, char *s)
{
  return sprintf(s, "%u %u\n", *(_DWORD *)(*(_QWORD *)(a1 + 984) + 16LL), *(_DWORD *)(*(_QWORD *)(a1 + 984) + 20LL));
}
