__int64 __fastcall activate_mode_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "activate_mode = %d\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) - 141LL));
}
