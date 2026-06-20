__int64 __fastcall timeline_get_value_str(__int64 a1, char *s, int a3)
{
  return snprintf(s, a3, "%lld", *(_QWORD *)(*(_QWORD *)(a1 + 64) + 16LL));
}
