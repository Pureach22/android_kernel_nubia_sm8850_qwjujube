__int64 __fastcall lim_process_auth_frame_type4(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int16 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x4
  __int64 v17; // x5
  const char *v18; // x2
  __int64 v19; // x6
  __int64 v20; // x7
  unsigned int v21; // w1
  int v22; // w8
  __int64 v24; // x2
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x0
  __int64 v28; // x5
  __int64 v29; // x6
  unsigned __int8 *v30; // x9
  __int64 v31; // x7
  int v32; // w8
  __int64 v33; // x20
  unsigned __int8 *v34; // x23
  int v35; // [xsp+0h] [xbp-10h]

  v12 = *(unsigned int *)(a4 + 72);
  if ( (_DWORD)v12 != 7 )
  {
    v17 = a2[10];
    v19 = a2[11];
    v18 = "%s: received unexpected Auth frame4 from peer in state %d, addr %02x:%02x:%02x:**:**:%02x";
    v20 = a2[12];
    v22 = a2[15];
    v21 = 3;
LABEL_8:
    v35 = v22;
    return qdf_trace_msg(
             0x35u,
             v21,
             v18,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "lim_process_auth_frame_type4",
             v12,
             v17,
             v19,
             v20,
             v35);
  }
  v12 = *a3;
  if ( (_DWORD)v12 != 1 )
  {
    v17 = a2[10];
    v19 = a2[11];
    v18 = "%s: received Auth frame4 from peer with invalid auth algo %d%02x:%02x:%02x:**:**:%02x";
    v20 = a2[12];
    v22 = a2[15];
LABEL_7:
    v21 = 2;
    goto LABEL_8;
  }
  if ( !(unsigned int)qdf_mem_cmp(a2 + 10, *(const void **)(a1 + 11376), 6u) )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL) == *a3 )
    {
      if ( a3[2] )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Authentication failure from peer %02x:%02x:%02x:**:**:%02x",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "lim_process_auth_frame_type4",
          a2[10],
          a2[11],
          a2[12],
          a2[15]);
        v24 = a3[2];
        v25 = a1;
        v26 = 513;
      }
      else
      {
        *(_DWORD *)(a4 + 172) = 1;
        v27 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
        v28 = a2[10];
        v29 = a2[11];
        v30 = a2;
        v31 = a2[12];
        v32 = a2[15];
        if ( !v27 )
        {
          v18 = "%s: Max pre-auth nodes reached SA: %02x:%02x:%02x:**:**:%02x";
          v21 = 3;
          v12 = a2[10];
          v17 = a2[11];
          v19 = a2[12];
          v20 = a2[15];
          return qdf_trace_msg(
                   0x35u,
                   v21,
                   v18,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_process_auth_frame_type4",
                   v12,
                   v17,
                   v19,
                   v20,
                   v35);
        }
        v33 = v27;
        v34 = v30;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Alloc new data: %pK peer %02x:%02x:%02x:**:**:%02x",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "lim_process_auth_frame_type4",
          v27,
          v28,
          v29,
          v31,
          v32);
        qdf_mem_copy((void *)(v33 + 8), *(const void **)(a1 + 11376), 6u);
        *(_BYTE *)(v33 + 278) &= ~1u;
        *(_DWORD *)(v33 + 16) = *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL);
        *(_WORD *)(v33 + 544) = *((_WORD *)v34 + 11) >> 4;
        *(_QWORD *)(v33 + 552) = qdf_mc_timer_get_system_ticks();
        lim_add_pre_auth_node(a1, v33);
        v24 = a3[2];
        v25 = a1;
        v26 = 0;
      }
      return lim_restore_from_auth_state(v25, v26, v24, a4);
    }
    v12 = a3[1];
    v17 = a2[10];
    v18 = "%s: received Authentication frame from peer with invalid auth seq number %d %02x:%02x:%02x:**:**:%02x";
    v19 = a2[11];
    v20 = a2[12];
    v22 = a2[15];
    goto LABEL_7;
  }
  v12 = a2[10];
  v17 = a2[11];
  v18 = "%s: received Auth frame4 from unexpected peer %02x:%02x:%02x:**:**:%02x";
  v19 = a2[12];
  v20 = a2[15];
  v21 = 3;
  return qdf_trace_msg(
           0x35u,
           v21,
           v18,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           "lim_process_auth_frame_type4",
           v12,
           v17,
           v19,
           v20,
           v35);
}
