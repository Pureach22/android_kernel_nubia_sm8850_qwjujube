__int64 __fastcall _lim_process_operating_mode_action_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x23
  __int64 v14; // x24
  unsigned int v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  __int64 v25; // x21
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x22
  __int64 v45; // [xsp+0h] [xbp-10h] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 16);
  v13 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 40);
  WORD2(v45) = 0;
  LODWORD(v45) = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received Operating Mode action frame",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "__lim_process_operating_mode_action_frame",
    v45,
    v46);
  if ( *(_BYTE *)(a3 + 9794) == 1 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Ignore opmode change as channel switch is in progress",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "__lim_process_operating_mode_action_frame");
  }
  else
  {
    result = _qdf_mem_malloc(3u, "__lim_process_operating_mode_action_frame", 320);
    if ( result )
    {
      v25 = result;
      v26 = dot11f_unpack_operating_mode(a1, v13, v15, result, 0);
      if ( (v26 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to unpack and parse (0x%08x, %d bytes)",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__lim_process_operating_mode_action_frame",
          v26,
          v15);
      }
      else
      {
        if ( v26 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: warnings while unpacking (0x%08x, %d bytes):",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "__lim_process_operating_mode_action_frame",
            v26,
            v15);
        v35 = dph_lookup_hash_entry(
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                a1,
                (unsigned __int8 *)(v14 + 10),
                (_WORD *)&v45 + 2,
                a3 + 360);
        if ( v35 )
        {
          v44 = v35;
          lim_update_nss(a1, v35, (*(unsigned __int8 *)(v25 + 2) >> 4) & 7, a3);
          lim_update_channel_width(a1, v44, a3, *(_BYTE *)(v25 + 2) & 3, &v45);
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Station context not found",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "__lim_process_operating_mode_action_frame");
        }
      }
      result = _qdf_mem_free(v25);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
