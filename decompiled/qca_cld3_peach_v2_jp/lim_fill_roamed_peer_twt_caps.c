__int64 __fastcall lim_fill_roamed_peer_twt_caps(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w19
  __int64 session_by_vdev_id; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 result; // x0
  __int64 v17; // x19
  unsigned __int16 v18; // w23
  __int64 v19; // x24
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int16 v29; // w9
  __int64 v30; // x0
  __int64 v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v4 = a2;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v31) = 0;
  LODWORD(v31) = 0;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( session_by_vdev_id )
  {
    v15 = session_by_vdev_id;
    result = _qdf_mem_malloc(0xEC4u, "lim_fill_roamed_peer_twt_caps", 2776);
    if ( result )
    {
      v17 = result;
      v18 = *(_WORD *)(a3 + 6) - 24;
      v19 = a3 + *(unsigned __int16 *)(a3 + 4);
      v20 = dot11f_unpack_re_assoc_response(a1, v19 + 24, v18, result, 0);
      if ( (v20 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to parse a Re-association Rsp (0x%08x, %d bytes):",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_fill_roamed_peer_twt_caps",
          v20,
          v18,
          v31,
          v32);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 4, v19 + 24, v18);
      }
      else
      {
        if ( v20 )
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Warnings while unpacking a Re-association Rsp (0x%08x, %d bytes):",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "lim_fill_roamed_peer_twt_caps",
            v20,
            v18,
            v31,
            v32);
        if ( *(_BYTE *)(v15 + 8676) == 1 )
        {
          v29 = *(_WORD *)(a3 + 18);
          v30 = *(_QWORD *)(a1 + 21552);
          LODWORD(v31) = *(_DWORD *)(a3 + 14);
          WORD2(v31) = v29;
          wlan_set_peer_twt_capabilities(
            v30,
            &v31,
            (*(_DWORD *)(v17 + 2013) >> 18) & 4
          | (*(_DWORD *)(v17 + 2013) >> 1) & 3
          | (*(_DWORD *)(v17 + 2013) >> 27) & 8
          | (16 * ((*(unsigned __int8 *)(v17 + 2073) >> 3) & 1u)));
        }
      }
      result = _qdf_mem_free(v17);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: session not found for given vdev_id %d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_fill_roamed_peer_twt_caps",
               v4,
               v31,
               v32);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
