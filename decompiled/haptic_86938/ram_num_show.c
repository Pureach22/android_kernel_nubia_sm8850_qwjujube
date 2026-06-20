__int64 __fastcall ram_num_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x20

  v3 = *(_QWORD *)(a1 + 152);
  get_ram_num(v3 - 168);
  return snprintf(a3, 0x1000u, "ram_num = %d\n", *(unsigned __int8 *)(v3 + 948));
}
