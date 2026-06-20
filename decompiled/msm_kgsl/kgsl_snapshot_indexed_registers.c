__int64 __fastcall kgsl_snapshot_indexed_registers(
        __int64 result,
        _QWORD *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        int a6)
{
  unsigned __int64 v6; // x8
  bool v7; // cf
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x19
  _QWORD *v10; // x19
  _DWORD *v11; // x20
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x9

  v6 = a2[12];
  v7 = v6 >= 8;
  v8 = v6 - 8;
  if ( v7 )
  {
    v9 = (unsigned int)(4 * a6) + 16LL;
    if ( v9 <= v8 )
    {
      v11 = (_DWORD *)a2[11];
      v11[2] = a3;
      v11[3] = a4;
      v11[4] = a5;
      v11[5] = a6;
      result = kgsl_regmap_read_indexed_interleaved((_DWORD *)(result + 13200), a3, a4, v11 + 6, a5, a6);
      v13 = (unsigned int)(v9 + 8);
      *v11 = 83995597;
      v11[1] = v13;
      v14 = a2[10];
      v15 = a2[11] + v13;
      v16 = a2[12];
      a2[11] = v15;
      a2[12] = v16 - (unsigned int)v11[1];
      a2[10] = v14 + (unsigned int)v11[1];
    }
    else
    {
      v10 = (_QWORD *)result;
      result = __ratelimit(&kgsl_snapshot_dump_indexed_regs__rs, "kgsl_snapshot_dump_indexed_regs");
      if ( (_DWORD)result )
        return dev_err(*v10, "snapshot: not enough snapshot memory for section %s\n", "INDEXED REGS");
    }
  }
  return result;
}
