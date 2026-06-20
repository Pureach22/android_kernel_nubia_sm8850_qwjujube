__int64 __fastcall channels_show(__int64 a1, int a2, char *s)
{
  return sprintf(s, "%u\n", *(_DWORD *)(*(_QWORD *)(a1 + 984) + 24LL));
}
