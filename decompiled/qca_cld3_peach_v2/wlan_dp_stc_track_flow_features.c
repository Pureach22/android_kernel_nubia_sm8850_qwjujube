__int64 __fastcall wlan_dp_stc_track_flow_features(
        __int64 a1,
        __int64 a2,
        unsigned __int64 *a3,
        __int64 a4,
        __int64 a5,
        unsigned __int16 a6,
        unsigned int a7)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x23
  unsigned int v22; // w10
  int v23; // w11
  unsigned __int64 v24; // x9
  unsigned int v25; // w5
  unsigned __int64 v26; // x4
  unsigned __int64 *v27; // x8
  int v28; // t1
  unsigned __int64 *v29; // x9
  int v30; // w11
  __int64 v31; // x8
  __int64 v32; // x8
  int v33; // t1
  int v34; // w8
  unsigned __int64 v35; // x6
  unsigned __int64 v36; // x5
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x10
  unsigned int v39; // w7
  unsigned __int64 v40; // x8
  unsigned int v41; // w10
  __int64 v42; // x5
  unsigned int v43; // w8
  unsigned int v44; // w8
  int v45; // w9
  int v46; // w11
  unsigned __int64 v50; // x9
  unsigned __int64 v57; // x8

  v11 = sched_clock(a1, a2);
  if ( *((_DWORD *)a3 + 2) != a7 )
  {
    qdf_mem_set(a3, 0x188u, 0);
    *((_DWORD *)a3 + 2) = a7;
  }
  v20 = *a3;
  if ( *a3 )
  {
    v21 = v11 - v20;
    if ( a3[9] - 1 >= v11 - v20 )
      a3[9] = v21;
    if ( a3[10] < v21 )
      a3[10] = v21;
    a3[12] += v21;
  }
  else
  {
    v21 = 0;
  }
  v22 = *((_DWORD *)a3 + 15) - 1;
  v23 = *((_DWORD *)a3 + 14) + 1;
  a3[6] += a6;
  *((_DWORD *)a3 + 14) = v23;
  if ( v22 >= a6 )
    *((_DWORD *)a3 + 15) = a6;
  if ( *((_DWORD *)a3 + 16) < (unsigned int)a6 )
    *((_DWORD *)a3 + 16) = a6;
  v24 = *((unsigned int *)a3 + 10);
  if ( WORD1(v24) <= 4u )
  {
    v25 = (unsigned __int16)*((_DWORD *)a3 + 10);
    if ( v25 <= 1 )
    {
      v26 = v24 >> 16;
      if ( (unsigned __int16)*((_DWORD *)a3 + 10) )
      {
        _X9 = a3 + 4;
        __asm { PRFM            #0x11, [X9] }
        do
          v57 = __ldxr(_X9);
        while ( __stlxr(v57 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
        __dmb(0xBu);
        if ( (v57 & 2) != 0 )
        {
          v27 = &a3[6 * (unsigned int)v26];
          v28 = *((_DWORD *)v27 + 26);
          v27 += 13;
          v29 = &v27[3 * v25];
          v30 = *((_DWORD *)v27 + 1);
          *(_DWORD *)v29 = v28;
          *((_DWORD *)v29 + 1) = v30;
          v29[1] = v27[1];
          v29[2] = v27[2];
        }
      }
      v31 = (__int64)&a3[6 * (unsigned int)v26 + 3 * v25];
      v33 = *(_DWORD *)(v31 + 104);
      v32 = v31 + 104;
      if ( v33 - 1 >= (unsigned int)a6 )
        *(_DWORD *)v32 = a6;
      if ( *(_DWORD *)(v32 + 4) < (unsigned int)a6 )
        *(_DWORD *)(v32 + 4) = a6;
      _X10 = a3 + 4;
      __asm { PRFM            #0x11, [X10] }
      do
        v50 = __ldxr(_X10);
      while ( __stlxr(v50 & 0xFFFFFFFFFFFFFFFELL, _X10) );
      __dmb(0xBu);
      if ( (v50 & 1) == 0 )
      {
        if ( *(_QWORD *)(v32 + 8) - 1LL >= v21 )
          *(_QWORD *)(v32 + 8) = v21;
        if ( *(_QWORD *)(v32 + 16) < v21 )
          *(_QWORD *)(v32 + 16) = v21;
        a3[11] += v21;
      }
      if ( (*(_BYTE *)(a1 + 148) & 0x20) != 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: STC: [%hu:%hu] mdata 0x%x len %u [%u - %u] iat %llu [%llu - %llu]",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_dp_stc_track_flow_features",
          *(_DWORD *)v32,
          *(_DWORD *)(v32 + 4),
          v21,
          *(_QWORD *)(v32 + 8),
          *(_QWORD *)(v32 + 16));
        v34 = *((_DWORD *)a3 + 3);
        if ( !v34 )
          goto LABEL_48;
        goto LABEL_34;
      }
LABEL_33:
      v34 = *((_DWORD *)a3 + 3);
      if ( !v34 )
        goto LABEL_48;
      goto LABEL_34;
    }
  }
  if ( (*(_BYTE *)(a1 + 148) & 0x10) == 0 )
    goto LABEL_33;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: STC: mdata 0x%x len %u iat %llu burst_state %u [%llu] [%llu]",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_dp_stc_track_flow_features",
    a7,
    a6,
    v21,
    *((unsigned int *)a3 + 3),
    a3[2],
    v20);
  v34 = *((_DWORD *)a3 + 3);
  if ( !v34 )
    goto LABEL_48;
LABEL_34:
  if ( v34 == 1 )
  {
    v42 = a3[2];
    goto LABEL_50;
  }
  if ( v34 != 2 )
    goto LABEL_61;
  if ( v21 < 0x59682F01 )
  {
    *((_DWORD *)a3 + 7) += a6;
    goto LABEL_61;
  }
  v35 = *a3;
  v36 = a3[2];
  v37 = a3[43];
  v38 = a3[45];
  v39 = *((_DWORD *)a3 + 7);
  *((_DWORD *)a3 + 3) = 0;
  v40 = v35 - v36;
  a3[45] = v38 + v35 - v36;
  if ( v37 - 1 >= v35 - v36 )
    a3[43] = v40;
  if ( a3[44] < v40 )
    a3[44] = v40;
  v41 = *((_DWORD *)a3 + 92) - 1;
  a3[47] += v39;
  if ( v41 >= v39 )
    *((_DWORD *)a3 + 92) = v39;
  if ( *((_DWORD *)a3 + 93) < v39 )
    *((_DWORD *)a3 + 93) = v39;
  if ( (*(_BYTE *)(a1 + 148) & 0x10) != 0 )
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: Flow mdata 0x%x ts: start %llu end: %llu Burst end with size %u dur %llu curr_ts %llu",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_dp_stc_track_flow_features",
      *((unsigned int *)a3 + 2),
      v35 - v36,
      v11);
  *((_DWORD *)a3 + 3) = 0;
  a3[2] = v11;
  a3[3] = 0;
LABEL_48:
  v42 = v11;
  a3[2] = v11;
  *((_DWORD *)a3 + 3) = 1;
LABEL_50:
  v43 = *((_DWORD *)a3 + 6);
  if ( (unsigned int)(v11 - v42) >= 0x989680 )
  {
    if ( (_DWORD)v11 - (_DWORD)v42 == 10000000 || v43 >> 3 > 0x270 )
      goto LABEL_57;
    v43 = 0;
    v42 = v11;
    a3[2] = v11;
    a3[3] = 0;
    *((_DWORD *)a3 + 3) = 1;
  }
  v44 = v43 + a6;
  if ( v44 >> 3 <= 0x270 )
  {
    *((_DWORD *)a3 + 6) = v44;
    goto LABEL_61;
  }
  if ( v44 == 5000 )
  {
LABEL_57:
    a3[2] = v11;
    *((_DWORD *)a3 + 3) = 1;
    *((_DWORD *)a3 + 6) = a6;
    *((_DWORD *)a3 + 7) = 0;
    goto LABEL_61;
  }
  v45 = *((_DWORD *)a3 + 96);
  v46 = *((_DWORD *)a3 + 7);
  *((_DWORD *)a3 + 3) = 2;
  *((_DWORD *)a3 + 96) = v45 + 1;
  *((_DWORD *)a3 + 6) = v44;
  *((_DWORD *)a3 + 7) = v46 + v44;
  if ( (*(_BYTE *)(a1 + 148) & 0x10) != 0 )
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: Flow mdata 0x%x ts %llu Burst start: %u B",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_dp_stc_track_flow_features",
      *((unsigned int *)a3 + 2),
      v42);
LABEL_61:
  *a3 = v11;
  return 0;
}
