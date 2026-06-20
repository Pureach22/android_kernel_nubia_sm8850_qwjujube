unsigned __int64 __fastcall gen8_legacy_snapshot_registers(_QWORD *a1, __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned __int64 v8; // x20
  int v9; // w8
  _DWORD *v10; // x8
  __int64 v11; // x9
  unsigned int *v12; // x22
  unsigned int v13; // w8
  unsigned int *v14; // x23
  unsigned int v15; // w8
  unsigned int v16; // w21
  unsigned int v17; // t1

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*(_QWORD *)(*(_QWORD *)a4 + 8LL)) + 28;
  if ( v8 <= a3 )
  {
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0xFFFFFFFF00000000LL;
    *(_QWORD *)(a2 + 20) = -1;
    if ( **(_DWORD **)a4 == 1 )
      v9 = a4[3];
    else
      v9 = -1;
    *(_DWORD *)(a2 + 16) = v9;
    v10 = *(_DWORD **)a4;
    v11 = *(_QWORD *)(*(_QWORD *)a4 + 16LL);
    if ( v11 )
    {
      kgsl_regmap_write(a1 + 1650, *(unsigned int *)(v11 + 8));
      v10 = *(_DWORD **)a4;
    }
    if ( *v10 )
      kgsl_regmap_write(a1 + 1650, ((a4[3] & 7) << 16) | 0x800000u);
    __dsb(0xFu);
    v12 = *(unsigned int **)(*(_QWORD *)a4 + 8LL);
    v13 = *v12;
    if ( *v12 != -1 )
    {
      v14 = (unsigned int *)(a2 + 28);
      do
      {
        if ( v12[1] == v13 )
        {
          *v14++ = v13;
          v16 = *v12;
          v15 = v12[1];
        }
        else
        {
          *v14 = v13 | 0x80000000;
          v15 = v12[1];
          v14[1] = v15;
          v14 += 2;
          v16 = *v12;
        }
        while ( v16 <= v15 )
        {
          *v14++ = kgsl_regmap_read(a1 + 1650);
          ++v16;
          v15 = v12[1];
        }
        v17 = v12[2];
        v12 += 2;
        v13 = v17;
      }
      while ( v17 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_legacy_snapshot_registers__rs, "gen8_legacy_snapshot_registers") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  return v8;
}
