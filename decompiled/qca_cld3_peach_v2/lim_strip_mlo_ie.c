unsigned __int8 *__fastcall lim_strip_mlo_ie(__int64 a1, unsigned __int8 *a2, unsigned __int16 *a3)
{
  unsigned __int8 *result; // x0
  char *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w20

  result = wlan_get_ext_ie_ptr_from_ext_id("k", 1u, a2, *a3);
  if ( result )
  {
    v6 = (char *)_qdf_mem_malloc(0x101u, "lim_strip_mlo_ie", 8597);
    if ( v6 )
    {
      v15 = (__int64)v6;
      if ( (unsigned int)wlan_strip_ie(a2, a3, 0xFFu, 1, "k", 1u, v6, 255, v7, v8, v9, v10, v11, v12, v13, v14) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to strip MLO IE",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "lim_strip_mlo_ie");
      }
      else
      {
        v24 = *(unsigned __int8 *)(v15 + 1);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: remove supplicant mlo ie, %d bytes",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "lim_strip_mlo_ie",
          *(unsigned __int8 *)(v15 + 1));
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
          53,
          8,
          v15,
          (unsigned int)(v24 + 2));
      }
      return (unsigned __int8 *)_qdf_mem_free(v15);
    }
    else
    {
      return (unsigned __int8 *)qdf_trace_msg(
                                  0x35u,
                                  2u,
                                  "%s: Failed to allocate MLO IE buff",
                                  v7,
                                  v8,
                                  v9,
                                  v10,
                                  v11,
                                  v12,
                                  v13,
                                  v14,
                                  "lim_strip_mlo_ie");
    }
  }
  return result;
}
