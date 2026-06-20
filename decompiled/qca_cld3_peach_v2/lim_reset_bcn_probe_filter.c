__int64 __fastcall lim_reset_bcn_probe_filter(
        __int64 a1,
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
  __int64 v10; // x19
  __int64 v11; // x5
  const char *v12; // x2
  unsigned int v13; // w1
  __int64 v14; // x4
  __int64 v16; // x20
  const char *v17; // x2

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Invalid session pointer",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_reset_bcn_probe_filter");
  v10 = *(unsigned __int8 *)(a2 + 8);
  v11 = *(unsigned int *)(a2 + 92);
  if ( (unsigned int)v10 < 6 )
  {
    v16 = a1 + 20480;
    if ( (_DWORD)v11 == 1 )
    {
      if ( *(_BYTE *)(a1 + 21746) )
        --*(_BYTE *)(a1 + 21746);
      v17 = "%s: Cleared SAP Filter for session %d";
      *(_BYTE *)(a1 + v10 + 21747) = 0;
    }
    else
    {
      if ( (_DWORD)v11 )
      {
LABEL_14:
        v14 = *(unsigned __int8 *)(v16 + 1229);
        v11 = *(unsigned __int8 *)(v16 + 1266);
        v12 = "%s: sta %d sap %d";
        v13 = 8;
        return qdf_trace_msg(0x35u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "lim_reset_bcn_probe_filter", v14, v11);
      }
      if ( *(_BYTE *)(a1 + 21709) )
        --*(_BYTE *)(a1 + 21709);
      qdf_mem_set((void *)(a1 + 6LL * (unsigned int)v10 + 21710), 6u, 0);
      v17 = "%s: Cleared STA Filter for session %d";
    }
    qdf_trace_msg(0x35u, 8u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "lim_reset_bcn_probe_filter", (unsigned int)v10);
    goto LABEL_14;
  }
  v12 = "%s: Invalid session_id %d of type %d";
  v13 = 2;
  v14 = (unsigned int)v10;
  return qdf_trace_msg(0x35u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "lim_reset_bcn_probe_filter", v14, v11);
}
