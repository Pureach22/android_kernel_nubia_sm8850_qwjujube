__int64 __fastcall gen7_snapshot_shader_memory(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 a4)
{
  _DWORD *v4; // x19

  v4 = *(_DWORD **)a4;
  if ( (unsigned __int64)(unsigned int)(4 * *(_DWORD *)(*(_QWORD *)a4 + 4LL)) + 24 <= a3 )
  {
    *a2 = *v4;
    a2[1] = *(_DWORD *)(a4 + 8);
    a2[5] = v4[1];
    a2[2] = *(_DWORD *)(a4 + 12);
    a2[4] = v4[5];
    a2[3] = v4[4];
    memcpy(
      a2 + 6,
      (const void *)(*(_QWORD *)(gen7_crashdump_registers + 8) + *(_QWORD *)(a4 + 24)),
      (unsigned int)(4 * v4[1]));
    return (unsigned int)(4 * v4[1]) + 24LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_shader_memory__rs, "gen7_snapshot_shader_memory") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "SHADER MEMORY");
    return 0;
  }
}
