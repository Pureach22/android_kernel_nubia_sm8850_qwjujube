__int64 __fastcall hif_dump_ce_registers(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  int v4; // w23
  int v5; // w28
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  __int64 result; // x0
  _QWORD v11[12]; // [xsp+0h] [xbp-60h] BYREF

  v11[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 656) )
  {
    v2 = -12288;
    v3 = 60;
    v4 = *(_DWORD *)(*(_QWORD *)(a1 + 624) + 256LL);
    memset(v11, 0, 88);
    do
    {
      if ( !v2 )
      {
LABEL_20:
        __break(0x5512u);
LABEL_21:
        __break(1u);
      }
      v5 = v3 - 60;
      if ( *(_QWORD *)(a1 + 8 * v3) )
      {
        if ( (unsigned int)hif_diag_read_mem(a1, v4 + (int)v2 + 12288, v11, 0x58u) )
        {
          qdf_trace_msg(61, 2, "%s: Dumping CE register failed!", "hif_dump_ce_registers");
          result = 4294967283LL;
          goto LABEL_19;
        }
        qdf_trace_msg(61, 8, "%s: CE%d=>", "hif_dump_ce_registers", v5);
        ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(61, 8, v11, 88);
        v6 = *(unsigned int *)(*(_QWORD *)(a1 + 616) + 352LL);
        if ( (unsigned int)v6 > 0x57 )
          goto LABEL_20;
        if ( *(_DWORD *)(*(_QWORD *)(a1 + 616) + 352LL) >> 2 == 22 )
          goto LABEL_21;
        qdf_trace_msg(
          56,
          2,
          "%s: ADDR:[0x%08X], SR_WR_INDEX:%d",
          "hif_dump_ce_registers",
          v4 + v2 + v6 + 12288,
          *((_DWORD *)v11 + (v6 >> 2)));
        v7 = *(unsigned int *)(*(_QWORD *)(a1 + 624) + 24LL);
        if ( (unsigned int)v7 > 0x57 )
          goto LABEL_20;
        if ( *(_DWORD *)(*(_QWORD *)(a1 + 624) + 24LL) >> 2 == 22 )
          goto LABEL_21;
        qdf_trace_msg(
          56,
          2,
          "%s: ADDR:[0x%08X], CURRENT_SRRI:%d",
          "hif_dump_ce_registers",
          v4 + v2 + v7 + 12288,
          *((_DWORD *)v11 + (v7 >> 2)));
        v8 = **(unsigned int **)(a1 + 624);
        if ( (unsigned int)v8 > 0x57 )
          goto LABEL_20;
        if ( **(_DWORD **)(a1 + 624) >> 2 == 22 )
          goto LABEL_21;
        qdf_trace_msg(
          56,
          2,
          "%s: ADDR:[0x%08X], DST_WR_INDEX:%d",
          "hif_dump_ce_registers",
          v4 + v2 + v8 + 12288,
          *((_DWORD *)v11 + (v8 >> 2)));
        v9 = *(unsigned int *)(*(_QWORD *)(a1 + 624) + 28LL);
        if ( (unsigned int)v9 > 0x57 )
          goto LABEL_20;
        if ( *(_DWORD *)(*(_QWORD *)(a1 + 624) + 28LL) >> 2 == 22 )
          goto LABEL_21;
        qdf_trace_msg(
          56,
          2,
          "%s: ADDR:[0x%08X], CURRENT_DRRI:%d",
          "hif_dump_ce_registers",
          v4 + v2 + v9 + 12288,
          *((_DWORD *)v11 + (v9 >> 2)));
        qdf_trace_msg(56, 2, "%s: ---", "hif_dump_ce_registers");
      }
      else
      {
        qdf_trace_msg(61, 8, "%s: CE%d not used", "hif_dump_ce_registers", v5);
      }
      ++v3;
      v2 += 1024;
    }
    while ( *(_DWORD *)(a1 + 656) > (unsigned int)(v3 - 60) );
  }
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
