__int64 __fastcall kgsl_snapshot_indexed_registers_v2(
        __int64 result,
        _QWORD *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        int a6,
        int a7,
        int a8)
{
  unsigned __int64 v8; // x8
  bool v9; // cf
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x19
  _QWORD *v12; // x19
  _DWORD *v13; // x20
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  __int64 v18; // x9

  v8 = a2[12];
  v9 = v8 >= 8;
  v10 = v8 - 8;
  if ( v9 )
  {
    v11 = (unsigned int)(4 * a6) + 24LL;
    if ( v11 <= v10 )
    {
      v13 = (_DWORD *)a2[11];
      v13[2] = a3;
      v13[3] = a4;
      v13[4] = a5;
      v13[5] = a6;
      v13[6] = a7;
      v13[7] = a8;
      result = kgsl_regmap_read_indexed_interleaved((_DWORD *)(result + 13200), a3, a4, v13 + 8, a5, a6);
      v15 = (unsigned int)(v11 + 8);
      *v13 = 84061133;
      v13[1] = v15;
      v16 = a2[10];
      v17 = a2[11] + v15;
      v18 = a2[12];
      a2[11] = v17;
      a2[12] = v18 - (unsigned int)v13[1];
      a2[10] = v16 + (unsigned int)v13[1];
    }
    else
    {
      v12 = (_QWORD *)result;
      result = __ratelimit(&kgsl_snapshot_dump_indexed_regs_v2__rs, "kgsl_snapshot_dump_indexed_regs_v2");
      if ( (_DWORD)result )
        return dev_err(*v12, "snapshot: not enough snapshot memory for section %s\n", "INDEXED REGS");
    }
  }
  return result;
}
