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
        __int16 a18,
        _BYTE *a19)
{
  void **v20; // x21
  _WORD *v21; // x1
  __int16 v22; // w27
  const char *v23; // x2
  unsigned int v24; // w1
  __int16 v25; // w20
  unsigned __int8 v26; // w23
  char v27; // w22
  unsigned __int8 v28; // w24
  __int16 v29; // w25
  __int64 v30; // [xsp+8h] [xbp-8h]

  v20 = result;
  if ( a19 )
    *a19 = 0;
  if ( !result )
  {
    v23 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
    v24 = 2;
    return (void **)qdf_trace_msg(
                      0x27u,
                      v24,
                      v23,
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
  v21 = result[1861];
  v22 = a2;
  if ( *v21 == a2
    && *((_QWORD *)v21 + 1) == a3
    && v21[8] == a4
    && *((unsigned __int8 *)v21 + 19) == a6
    && *((unsigned __int8 *)v21 + 20) == a7
    && v21[13] == a18 )
  {
    v23 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_curchan already updated";
    v24 = 4;
    return (void **)qdf_trace_msg(
                      0x27u,
                      v24,
                      v23,
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
  if ( *v21 )
  {
    v30 = a3;
    v25 = a8;
    v26 = a7;
    v27 = a5;
    v28 = a6;
    v29 = a4;
    result = (void **)qdf_mem_copy(result[1862], v21, 0x20u);
    a3 = v30;
    v21 = v20[1861];
    a4 = v29;
    a6 = v28;
    a5 = v27;
    a7 = v26;
    a8 = v25;
  }
  *v21 = v22;
  *((_QWORD *)v20[1861] + 1) = a3;
  *((_WORD *)v20[1861] + 8) = a4;
  *((_BYTE *)v20[1861] + 18) = a5;
  *((_BYTE *)v20[1861] + 19) = a6;
  *((_BYTE *)v20[1861] + 20) = a7;
  *((_WORD *)v20[1861] + 11) = a8;
  *((_WORD *)v20[1861] + 12) = a17;
  *((_WORD *)v20[1861] + 13) = a18;
  if ( a19 )
    *a19 = 1;
  return result;
}
