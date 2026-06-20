__int64 __fastcall vmax_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "vmax = 0x%02X\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 120LL));
}
