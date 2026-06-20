__int64 __fastcall gen8_snapshot_trace_buffer_etb(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x10
  __int64 v5; // x11
  __int64 v6; // x10
  __int64 v7; // x10
  int v8; // w9
  __int64 v9; // x9
  unsigned int v10; // w10
  int v13; // w10
  _DWORD *v14; // x9
  int v15; // w10
  int v16; // w11

  v4 = tmc_virt_0;
  __dsb(0xEu);
  *(_DWORD *)(v4 + 4016) = -978530731;
  __dsb(0xFu);
  LODWORD(v4) = *(_DWORD *)(tmc_virt_0 + 772);
  __dsb(0xDu);
  v5 = tmc_virt_0;
  __dsb(0xEu);
  *(_DWORD *)(v5 + 772) = v4 | 0x40;
  __dsb(0xFu);
  v6 = tmc_virt_0;
  __dsb(0xEu);
  *(_DWORD *)(v6 + 32) = 0;
  v7 = tmc_virt_0;
  __dsb(0xEu);
  *(_DWORD *)(v7 + 40) = 0;
  __dsb(0xFu);
  v8 = *(_DWORD *)(tmc_virt_0 + 4);
  __dsb(0xDu);
  LODWORD(v9) = 4 * v8;
  LODWORD(v7) = *(_DWORD *)(tmc_virt_0 + 20);
  __dsb(0xDu);
  v10 = *(_DWORD *)(tmc_virt_0 + 24) - v7;
  __dsb(0xDu);
  if ( v10 )
    v9 = v10;
  else
    v9 = (unsigned int)v9;
  if ( v9 + 26 <= a3 )
  {
    *(_DWORD *)(a2 + 22) = v9 & 0xFFFFFFFC;
    *(_WORD *)a2 = *(_WORD *)a4;
    *(_QWORD *)(a2 + 6) = *(_QWORD *)(a4 + 6);
    *(_QWORD *)(a2 + 14) = *(_QWORD *)(a4 + 14);
    *(_WORD *)(a2 + 4) = *(_WORD *)(a4 + 4);
    *(_WORD *)(a2 + 2) = *(_WORD *)(a4 + 2);
    if ( (v9 & 0xFFFFFFFC) != 0 )
    {
      v13 = v9 & 0xFFFFFFFC;
      v14 = (_DWORD *)(a2 + 26);
      v15 = -v13;
      do
      {
        v15 += 4;
        v16 = *(_DWORD *)(tmc_virt_0 + 16);
        __dsb(0xDu);
        *v14++ = v16;
      }
      while ( v15 );
      return *(unsigned int *)(a2 + 22) + 26LL;
    }
    else
    {
      return 26;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_trace_buffer_etb__rs, "gen8_snapshot_trace_buffer_etb") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "ETB BUFFER");
    return 0;
  }
}
