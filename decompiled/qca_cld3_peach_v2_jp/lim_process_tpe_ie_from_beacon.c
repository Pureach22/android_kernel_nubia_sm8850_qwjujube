__int64 __fastcall lim_process_tpe_ie_from_beacon(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  __int64 result; // x0
  __int64 v9; // x19
  unsigned __int16 ielen_from_bss_description; // w23
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4

  result = _qdf_mem_malloc(0x1490u, "lim_process_tpe_ie_from_beacon", 6614);
  if ( result )
  {
    v9 = result;
    ielen_from_bss_description = wlan_get_ielen_from_bss_description(a3);
    v11 = dot11f_unpack_beacon_i_es(a1, a3 + 104, ielen_from_bss_description, v9, 0);
    v20 = v11;
    if ( (v11 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_process_tpe_ie_from_beacon",
        v11,
        ielen_from_bss_description);
    }
    else
    {
      if ( v11 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: warnings (0x%08x, %d bytes):",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "lim_process_tpe_ie_from_beacon",
          v11,
          ielen_from_bss_description);
      lim_parse_tpe_ie(
        a1,
        a2,
        (__int64 *)(v9 + 1432),
        *(_BYTE *)(v9 + 1430),
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        a4);
    }
    return _qdf_mem_free(v9);
  }
  return result;
}
