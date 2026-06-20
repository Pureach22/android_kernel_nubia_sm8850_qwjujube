_QWORD *__fastcall dfs_nol_addchan(
        __int64 a1,
        unsigned __int16 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x9
  _QWORD *v14; // x24
  __int64 v16; // x23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x3
  _QWORD *result; // x0
  const char *v28; // x2
  unsigned int v29; // w1
  _QWORD *v30; // x21
  __int64 v31; // x0
  _QWORD *v32; // x9
  __int64 v33; // x3
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w9

  if ( !a1 )
  {
    v28 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
    v29 = 2;
    return (_QWORD *)qdf_trace_msg(0x27u, v29, v28, a4, a5, a6, a7, a8, a9, a10, a11, "dfs_nol_addchan");
  }
  v14 = (_QWORD *)(a1 + 64);
  v13 = *(_QWORD *)(a1 + 64);
  if ( !v13 )
  {
    v16 = 0;
LABEL_15:
    result = (_QWORD *)_qdf_mem_malloc(0x90u, "dfs_nol_addchan", 438);
    if ( result )
    {
      v30 = result;
      qdf_mem_set(result, 0x90u, 0);
      v30[2] = a1;
      *((_DWORD *)v30 + 6) = a2;
      *((_DWORD *)v30 + 7) = 20;
      v31 = ktime_get_with_offset(1);
      v30[17] = 0;
      *((_DWORD *)v30 + 10) = 1000 * a3;
      v32 = (_QWORD *)(v16 + 136);
      if ( !v16 )
        v32 = v14;
      v30[4] = v31 / 1000;
      *v32 = v30;
      *((_DWORD *)v30 + 28) = 1;
      v30[15] = v30 + 6;
      v30[16] = dfs_remove_from_nol;
      hrtimer_init(v30 + 6, 1, 5);
      if ( *((_DWORD *)v30 + 28) == 1 )
        v33 = 5;
      else
        v33 = 1;
      v30[11] = _qdf_hrtimer_cb_0;
      result = (_QWORD *)hrtimer_start_range_ns(v30 + 6, 1000000LL * (unsigned int)(1000 * a3), 0, v33);
      v42 = *(_BYTE *)(a1 + 1);
      ++*(_DWORD *)(a1 + 84);
      if ( (v42 & 0x20) != 0 )
        return (_QWORD *)qdf_trace_msg(
                           0x27u,
                           8u,
                           "WLAN_DEBUG_DFS_NOL : %s: new NOL channel %d MHz / %d MHz",
                           v34,
                           v35,
                           v36,
                           v37,
                           v38,
                           v39,
                           v40,
                           v41,
                           "dfs_nol_addchan",
                           *((unsigned int *)v30 + 6),
                           *((unsigned int *)v30 + 7));
      return result;
    }
    if ( (*(_BYTE *)(a1 + 1) & 0x21) == 0 )
      return result;
    v28 = "WLAN_DEBUG_DFS_NOL | WLAN_DEBUG_DFS : %s: failed to allocate memory for nol entry";
    v29 = 8;
    return (_QWORD *)qdf_trace_msg(0x27u, v29, v28, a4, a5, a6, a7, a8, a9, a10, a11, "dfs_nol_addchan");
  }
  while ( 1 )
  {
    v16 = v13;
    if ( *(_DWORD *)(v13 + 24) == a2 && *(_DWORD *)(v13 + 28) == 20 )
      break;
    v13 = *(_QWORD *)(v13 + 136);
    if ( !v13 )
      goto LABEL_15;
  }
  v17 = ktime_get_with_offset(1);
  *(_DWORD *)(v16 + 40) = 1000 * a3;
  *(_QWORD *)(v16 + 32) = v17 / 1000;
  if ( (*(_BYTE *)(a1 + 1) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_NOL : %s: Update OS Ticks for NOL %d MHz / %d MHz",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dfs_nol_addchan",
      *(unsigned int *)(v16 + 24),
      *(unsigned int *)(v16 + 28));
  hrtimer_cancel(v16 + 48);
  if ( *(_DWORD *)(v16 + 112) == 1 )
    v26 = 5;
  else
    v26 = 1;
  return (_QWORD *)hrtimer_start_range_ns(v16 + 48, 1000000LL * *(unsigned int *)(v16 + 40), 0, v26);
}
