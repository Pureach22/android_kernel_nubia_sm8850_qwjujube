__int64 __fastcall out_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v5; // w0
  int v6; // w1
  char *v7; // x2

  v3 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 332LL);
  if ( (unsigned int)v3 < 3 )
    return (int)scnprintf(a3, 4096, "%s\n", str_tmc_etr_out_mode[v3]);
  __break(0x5512u);
  v5 = MEMORY[0x7115290]();
  return out_mode_store(v5, v6, v7);
}
