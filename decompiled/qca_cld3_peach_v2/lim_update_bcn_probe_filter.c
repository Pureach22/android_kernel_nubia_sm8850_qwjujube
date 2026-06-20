__int64 __fastcall lim_update_bcn_probe_filter(
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
  unsigned __int8 v18; // w0
  const char *v19; // x2
  __int64 v20; // x5
  __int64 v21; // x4

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
             "lim_update_bcn_probe_filter");
  v10 = *(unsigned __int8 *)(a2 + 8);
  v11 = *(unsigned int *)(a2 + 92);
  if ( (unsigned int)v10 < 6 )
  {
    v16 = a1 + 20480;
    if ( (_DWORD)v11 == 1 )
    {
      v18 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a2 + 284), a3, a4, a5, a6, a7, a8, a9, a10);
      v19 = "%s: Updated SAP Filter for session %d channel %d";
      *(_BYTE *)(a1 + v10 + 21747) = v18;
      v20 = v18;
      v21 = (unsigned int)v10;
    }
    else
    {
      v19 = "%s: Invalid session type %d session id %d";
      v21 = (unsigned int)v11;
      v20 = *(unsigned __int8 *)(a2 + 8);
    }
    qdf_trace_msg(0x35u, 8u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "lim_update_bcn_probe_filter", v21, v20);
    v14 = *(unsigned __int8 *)(v16 + 1229);
    v11 = *(unsigned __int8 *)(v16 + 1266);
    v12 = "%s: sta %d sap %d";
    v13 = 8;
  }
  else
  {
    v12 = "%s: Invalid session_id %d of type %d";
    v13 = 2;
    v14 = (unsigned int)v10;
  }
  return qdf_trace_msg(0x35u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "lim_update_bcn_probe_filter", v14, v11);
}
