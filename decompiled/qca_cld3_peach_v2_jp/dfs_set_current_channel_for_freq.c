void **__fastcall dfs_set_current_channel_for_freq(
        void **result,
        __int16 a2,
        __int64 a3,
        __int16 a4,
        char a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        __int16 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int16 a17,
        __int64 a18,
        _BYTE *a19)
{
  void **v26; // x22
  _WORD *v27; // x1
  __int16 v28; // w27
  const char *v29; // x2
  unsigned int v30; // w1

  v26 = result;
  if ( a19 )
    *a19 = 0;
  if ( !result )
  {
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
    v30 = 2;
    return (void **)qdf_trace_msg(
                      0x27u,
                      v30,
                      v29,
                      a9,
                      a10,
                      a11,
                      a12,
                      a13,
                      a14,
                      a15,
                      a16,
                      "dfs_set_current_channel_for_freq");
  }
  v27 = result[1861];
  v28 = a2;
  if ( *v27 == a2
    && *((_QWORD *)v27 + 1) == a3
    && v27[8] == a4
    && *((unsigned __int8 *)v27 + 19) == a6
    && *((unsigned __int8 *)v27 + 20) == a7 )
  {
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_curchan already updated";
    v30 = 4;
    return (void **)qdf_trace_msg(
                      0x27u,
                      v30,
                      v29,
                      a9,
                      a10,
                      a11,
                      a12,
                      a13,
                      a14,
                      a15,
                      a16,
                      "dfs_set_current_channel_for_freq");
  }
  if ( *v27 )
  {
    result = (void **)qdf_mem_copy(result[1862], v27, 0x20u);
    v27 = v26[1861];
  }
  *v27 = v28;
  *((_QWORD *)v26[1861] + 1) = a3;
  *((_WORD *)v26[1861] + 8) = a4;
  *((_BYTE *)v26[1861] + 18) = a5;
  *((_BYTE *)v26[1861] + 19) = a6;
  *((_BYTE *)v26[1861] + 20) = a7;
  *((_WORD *)v26[1861] + 11) = a8;
  *((_WORD *)v26[1861] + 12) = a17;
  if ( a19 )
    *a19 = 1;
  return result;
}
