__int64 __fastcall gen8_snapshot_shader_memory(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 a4)
{
  _DWORD *v4; // x19
  int v7; // w8

  v4 = *(_DWORD **)a4;
  if ( (unsigned __int64)(unsigned int)(4 * *(_DWORD *)(*(_QWORD *)a4 + 4LL)) + 32 <= a3 )
  {
    *a2 = *v4;
    if ( v4[6] == 1 )
      v7 = *(_DWORD *)(a4 + 16);
    else
      v7 = -1;
    a2[1] = v7;
    a2[2] = *(_DWORD *)(a4 + 8);
    a2[3] = *(_DWORD *)(a4 + 12);
    a2[4] = v4[4];
    a2[5] = v4[5];
    a2[6] = 1;
    a2[7] = v4[1];
    memcpy(
      a2 + 8,
      (const void *)(*(_QWORD *)(gen8_crashdump_registers + 8) + *(_QWORD *)(a4 + 32)),
      (unsigned int)(4 * v4[1]));
    return (unsigned int)(4 * v4[1]) + 32LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_shader_memory__rs, "gen8_snapshot_shader_memory") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "SHADER MEMORY");
    return 0;
  }
}
