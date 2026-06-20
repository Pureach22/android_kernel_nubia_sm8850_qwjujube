unsigned __int64 __fastcall gen7_snapshot_rscc_registers(
        _QWORD *a1,
        unsigned int *a2,
        unsigned __int64 a3,
        unsigned int *a4)
{
  __int64 v8; // x20
  unsigned __int64 result; // x0
  unsigned int v10; // w10
  unsigned int *v11; // x9
  unsigned int v12; // t1
  unsigned int v13; // w9
  unsigned int v14; // w10
  int v15; // w11
  unsigned int *v16; // x12

  v8 = to_gen7_gmu((__int64)a1);
  result = (int)(4 * adreno_snapshot_regs_count(a4));
  if ( result <= a3 )
  {
    v10 = *a4;
    if ( *a4 != -1 )
    {
      do
      {
        v13 = a4[1] - v10;
        if ( v13 )
        {
          *a2 = v10;
          a2[1] = v13 + 1;
          v14 = *a4;
          v11 = a2 + 2;
          if ( *a4 <= a4[1] )
          {
            v15 = 4 * v14 - 327680;
            do
            {
              ++v14;
              v16 = (unsigned int *)(*(_QWORD *)(v8 + 1104) + v15);
              v15 += 4;
              *v11++ = *v16;
            }
            while ( v14 <= a4[1] );
          }
        }
        else
        {
          *a2 = v10 | 0x80000000;
          a2[1] = *(_DWORD *)(*(_QWORD *)(v8 + 1104) + 4 * *a4 - 327680);
          v11 = a2 + 2;
        }
        v12 = a4[2];
        a4 += 2;
        v10 = v12;
        a2 = v11;
      }
      while ( v12 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_rscc_registers__rs, "gen7_snapshot_rscc_registers") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "RSCC REGISTERS");
    return 0;
  }
  return result;
}
