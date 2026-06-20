__int64 __fastcall priority_show(__int64 a1, int a2, char *s)
{
  return sprintf(s, "%#lx\n", *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 32LL));
}
