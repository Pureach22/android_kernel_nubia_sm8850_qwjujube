__int64 __fastcall state_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "state = %d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 104LL));
}
