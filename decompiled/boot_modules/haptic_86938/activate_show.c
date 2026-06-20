__int64 __fastcall activate_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "activate = %d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 104LL));
}
