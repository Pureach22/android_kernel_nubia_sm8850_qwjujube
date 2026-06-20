__int64 __fastcall ram_vbat_comp_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "ram_vbat_comp = %d\n", *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) - 140LL));
}
