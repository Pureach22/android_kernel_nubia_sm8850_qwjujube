__int64 *__fastcall hdd_apf_read_memory_callback(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 *result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 *v38; // x20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  unsigned int v48; // w4
  unsigned int v49; // w5
  unsigned int v50; // w8
  const char *v51; // x2
  unsigned int v52; // w9
  bool v53; // cf
  unsigned int v54; // w9
  size_t v55; // x2
  unsigned int v56; // w1
  __int64 v57; // x1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_apf_read_memory_callback");
  v20 = _wlan_hdd_validate_context(a1, (__int64)"hdd_apf_read_memory_callback", v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !a2 || v20 )
    return (__int64 *)qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: HDD context is invalid or event buf(%pK) is null",
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        "hdd_apf_read_memory_callback",
                        a2);
  result = (__int64 *)hdd_get_link_info_by_vdev(a1, *(_DWORD *)a2);
  if ( result )
  {
    v38 = result;
    result = (__int64 *)_hdd_validate_adapter(
                          *result,
                          (__int64)"hdd_apf_read_memory_callback",
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          v35,
                          v36,
                          v37);
    if ( !(_DWORD)result )
    {
      v47 = *v38;
      if ( *(_DWORD *)(v47 + 52216) == 72831828 )
      {
        v48 = *(_DWORD *)(a2 + 4);
        v49 = *(_DWORD *)(v47 + 52284);
        v50 = v48 - v49;
        if ( v48 < v49 )
          return (__int64 *)qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: Offset in read event(%d) smaller than offset in request(%d)!",
                              v39,
                              v40,
                              v41,
                              v42,
                              v43,
                              v44,
                              v45,
                              v46,
                              "hdd_apf_read_memory_callback");
        v52 = *(_DWORD *)(v47 + 52280);
        v53 = v52 >= v50;
        v54 = v52 - v50;
        if ( v53 )
        {
          v55 = *(unsigned int *)(a2 + 8);
          if ( v54 >= (unsigned int)v55 )
          {
            qdf_mem_copy((void *)(*(_QWORD *)(v47 + 52272) + v50), *(const void **)(a2 + 16), v55);
            if ( (*(_BYTE *)(a2 + 12) & 1) == 0 )
            {
              *(_DWORD *)(v47 + 52216) = 0;
              qdf_event_set(v47 + 52224, v57);
            }
            v51 = "%s: exit";
            v56 = 8;
            return (__int64 *)qdf_trace_msg(
                                0x33u,
                                v56,
                                v51,
                                v39,
                                v40,
                                v41,
                                v42,
                                v43,
                                v44,
                                v45,
                                v46,
                                "hdd_apf_read_memory_callback");
          }
        }
        v51 = "%s: Read chunk exceeding allocated space";
      }
      else
      {
        v51 = "%s: Caller timed out or corrupt magic, simply return";
      }
      v56 = 2;
      return (__int64 *)qdf_trace_msg(
                          0x33u,
                          v56,
                          v51,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43,
                          v44,
                          v45,
                          v46,
                          "hdd_apf_read_memory_callback");
    }
  }
  return result;
}
