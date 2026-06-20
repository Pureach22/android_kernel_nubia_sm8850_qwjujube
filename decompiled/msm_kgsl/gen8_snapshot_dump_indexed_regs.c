__int64 __fastcall gen8_snapshot_dump_indexed_regs(_QWORD *a1, char *a2, unsigned __int64 a3, unsigned int *a4)
{
  unsigned int v4; // w24
  unsigned int v6; // w26
  __int64 v8; // x8
  unsigned __int64 v9; // x28
  char *v10; // x22
  unsigned int v11; // w8
  size_t v12; // x23
  unsigned int v13; // w20
  unsigned __int64 v14; // x9
  unsigned __int64 *v15; // x8
  _QWORD *v16; // x8
  __int64 v17; // x9
  unsigned int v18; // w11
  unsigned int v19; // w10
  __int64 v20; // x10
  __int64 v21; // x13
  unsigned __int64 v22; // x12
  unsigned __int64 v23; // x13
  size_t v24; // x12
  __int64 v25; // x9

  v4 = a4[3];
  if ( (unsigned __int64)(4 * v4) + 24 <= a3 )
  {
    v6 = a4[2];
    v8 = *(_QWORD *)(gen8_capturescript + 40);
    *(_DWORD *)a2 = *a4;
    *((_DWORD *)a2 + 1) = a4[1];
    *((_DWORD *)a2 + 3) = a4[3];
    *((_DWORD *)a2 + 2) = a4[2];
    *((_DWORD *)a2 + 4) = a4[4];
    *((_DWORD *)a2 + 5) = a4[5];
    if ( v4 )
    {
      v9 = (unsigned __int64)(v8 + 0x1FFFFFFFD0LL) >> 5;
      v10 = a2 + 24;
      while ( 1 )
      {
        v11 = a4[5];
        v12 = 0;
        if ( v4 >= (unsigned int)v9 )
          v13 = v9;
        else
          v13 = v4;
        if ( v11 == -1 )
          LOBYTE(v11) = 0;
        v14 = (((unsigned __int16)a4[4] & 0xFu) << 12) | ((unsigned __int64)(v11 & 7) << 16);
        v15 = *(unsigned __int64 **)(gen8_capturescript + 8);
        *v15 = v14 | 0x800000;
        v15[1] = 0x81E00000200001LL;
        v16 = v15 + 2;
        if ( (_DWORD)v9 )
        {
          v17 = gen8_crashdump_registers;
          v18 = v6;
          if ( v13 <= 1 )
            v19 = 1;
          else
            v19 = v13;
          v20 = 4LL * v19;
          do
          {
            v21 = v18++;
            v22 = ((unsigned __int64)*a4 << 44) | 0x200001;
            *v16 = v21;
            v16[1] = v22;
            v23 = ((unsigned __int64)a4[1] << 44) | 1;
            v24 = v12 + *(_QWORD *)(v17 + 24);
            v12 += 4LL;
            v16[2] = v24;
            v16[3] = v23;
            v16 += 4;
          }
          while ( v20 != v12 );
        }
        gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + ((unsigned int)v12 & 0xFFFFFFFC);
        *(_DWORD *)gen8_cd_reg_end = -1431655766;
        v25 = *(_QWORD *)(gen8_crashdump_registers + 24);
        v16[3] = 0;
        *v16 = v25 + ((unsigned int)v12 & 0xFFFFFFFC);
        v16[1] = 0x84500000000001LL;
        v16[2] = 0;
        if ( (gen8_do_crashdump((__int64)a1) & 1) == 0 )
          break;
        memcpy(v10, *(const void **)(gen8_crashdump_registers + 8), v12);
        v4 -= v13;
        v6 += v13;
        v10 += v12;
        if ( !v4 )
          return 4 * a4[3] + 24LL;
      }
      *((_DWORD *)a2 + 3) = a4[3] - v4;
      return v10 - a2;
    }
    else
    {
      return 4 * a4[3] + 24LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_dump_indexed_regs__rs, "gen8_snapshot_dump_indexed_regs") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "INDEXED REGS");
    return 0;
  }
}
