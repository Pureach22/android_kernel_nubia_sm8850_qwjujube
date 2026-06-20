__int64 __fastcall dp_peer_rx_init_wrapper(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w22
  __int64 v9; // x8
  _DWORD *v10; // x8
  int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x10
  int v21; // w23
  __int64 v22; // x25
  int v23; // w26
  __int64 v24; // x8
  _DWORD *v25; // x8
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x4

  if ( !a3 || (*(_BYTE *)(a3 + 8) & 1) != 0 )
  {
    result = dp_peer_rx_tid_setup(a2);
    v9 = *a2;
    *((_DWORD *)a2 + 58) = 0;
    *((_BYTE *)a2 + 236) = 0;
    if ( v9 )
    {
      *(_DWORD *)(v9 + 64) = 0;
      *(_DWORD *)(*a2 + 76) = 0;
    }
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 8);
    v5 = _qdf_mem_malloc(0x3E8u, "dp_peer_rx_init_reorder_queue", 3756);
    result = dp_get_peer_vdev_roaming_in_progress(a2);
    if ( (result & 1) == 0 )
    {
      v7 = a2[11];
      if ( *(_DWORD *)(v7 + 2372) == 1 )
        v8 = *(unsigned __int16 *)(v7 + 2376);
      else
        v8 = 1;
      v10 = *(_DWORD **)(v4 + 1616);
      if ( *(v10 - 1) != -1687924027 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, _QWORD, _QWORD))v10)(v4, a2, 0x10000, v8, 0);
      v20 = " FAILED";
      if ( !v11 )
        v20 = " SUCCESS";
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: peer %pK %02x:%02x:%02x:**:**:%02x type %d setup tid %d ba_win_size %d%s",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_peer_rx_init_reorder_queue",
        a2,
        *((unsigned __int8 *)a2 + 44),
        *((unsigned __int8 *)a2 + 45),
        *((unsigned __int8 *)a2 + 46),
        *((unsigned __int8 *)a2 + 49),
        *((_DWORD *)a2 + 102),
        16,
        v8,
        v20);
      v21 = 0;
      v22 = 0;
      v23 = 0;
      do
      {
        if ( v5 )
        {
          v24 = a2[11] + v22;
          if ( *(_DWORD *)(v24 + 68) == 1 )
            v8 = *(unsigned __int16 *)(v24 + 72);
          else
            v8 = 1;
          v23 += snprintf((char *)(v5 + (unsigned __int16)v23), 1000LL - (unsigned __int16)v23, "%u:%u ", v21, v8);
        }
        v22 += 144;
        ++v21;
      }
      while ( v22 != 2304 );
      v25 = *(_DWORD **)(v4 + 1616);
      if ( *(v25 - 1) != -1687924027 )
        __break(0x8228u);
      v26 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, _QWORD, __int64))v25)(v4, a2, 0xFFFF, v8, 1);
      if ( v5 )
        v35 = (const char *)v5;
      else
        v35 = "NULL";
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: setup tid:ba(%s) status %d",
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 "dp_peer_rx_init_reorder_queue",
                 v35,
                 v26);
    }
    if ( v5 )
      return _qdf_mem_free(v5);
  }
  return result;
}
