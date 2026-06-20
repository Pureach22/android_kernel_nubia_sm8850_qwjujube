__int64 __fastcall phase_sync_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "sync flag : %d\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 16LL));
}
