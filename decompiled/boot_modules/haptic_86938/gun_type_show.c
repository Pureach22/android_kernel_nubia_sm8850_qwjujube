__int64 __fastcall gun_type_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "0x%02x\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 44LL));
}
