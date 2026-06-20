__int64 __fastcall cont_brk_time_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "cont_brk_time = 0x%02X\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 1013LL));
}
