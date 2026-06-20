__int64 __fastcall aw22xxx_multi_breath_pattern_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, " pattern_status = %d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) + 760LL));
}
