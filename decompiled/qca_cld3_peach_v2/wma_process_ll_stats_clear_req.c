__int64 __fastcall wma_process_ll_stats_clear_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  __int64 v11; // x8
  __int64 result; // x0
  const char *v14; // x2
  __int64 v15; // [xsp+0h] [xbp-20h]
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v17) = 0;
  v15 = 0;
  v16 = 0;
  if ( !a1 || !a2 )
  {
    v14 = "%s: input pointer is NULL";
    goto LABEL_7;
  }
  v10 = *(unsigned __int8 *)(a2 + 4);
  v11 = *(_QWORD *)(a1[65] + 488 * v10);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev is NULL for vdev_%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_process_ll_stats_clear_req",
      v10,
      0,
      v16,
      v17,
      v18);
    goto LABEL_9;
  }
  BYTE4(v15) = v10;
  BYTE4(v16) = *(_BYTE *)(a2 + 12);
  LODWORD(v16) = *(_DWORD *)(a2 + 8);
  qdf_mem_copy((char *)&v16 + 5, (const void *)(v11 + 74), 6u);
  result = wmi_unified_process_ll_stats_clear_cmd(*a1);
  if ( (_DWORD)result )
  {
    v14 = "%s: Failed to send clear link stats req";
LABEL_7:
    qdf_trace_msg(0x36u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_ll_stats_clear_req", v15, v16, v17, v18);
LABEL_9:
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
