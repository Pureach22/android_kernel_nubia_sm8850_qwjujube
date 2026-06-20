__int64 __fastcall gen7_snapshot_trace_buffer_gfx_trace(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned int v7; // w0
  int v8; // w9
  __int64 v9; // x4
  __int64 v10; // x5

  if ( a3 > 0x819 )
  {
    *(_QWORD *)(a2 + 6) = *(_QWORD *)(a4 + 6);
    *(_QWORD *)(a2 + 14) = *(_QWORD *)(a4 + 14);
    *(_WORD *)(a2 + 4) = *(_WORD *)(a4 + 4);
    *(_WORD *)(a2 + 2) = *(_WORD *)(a4 + 2);
    *(_WORD *)a2 = *(_WORD *)a4;
    v7 = kgsl_regmap_read(a1 + 1650);
    if ( v7 )
    {
      v8 = 4 * (v7 & 0x1FF);
      if ( v7 >= 0x1000 )
        v9 = (v7 & 0x1FF) + 1;
      else
        v9 = 0;
      if ( v7 < 0x1000 )
      {
        v10 = v7 & 0x1FF;
      }
      else
      {
        v8 = 2048;
        v10 = 512;
      }
      *(_DWORD *)(a2 + 22) = v8;
      kgsl_regmap_read_indexed_interleaved(a1 + 1650, 1691, 1692, a2 + 26, v9, v10);
      return *(unsigned int *)(a2 + 22) + 26LL;
    }
    else
    {
      *(_DWORD *)(a2 + 22) = 0;
      return 26;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_trace_buffer_gfx_trace__rs, "gen7_snapshot_trace_buffer_gfx_trace") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "TRACE 2K BUFFER");
    return 0;
  }
}
