__int64 __fastcall qdf_nbuf_add_frag_debug(
        __int64 a1,
        const void *a2,
        __int64 a3,
        int a4,
        __int64 a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        const char *a9,
        int a10)
{
  __int64 v11; // x8
  __int64 v12; // x8
  _QWORD *v13; // x9
  unsigned int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x22
  int v22; // w9
  int v23; // w11
  int v24; // w9
  int v25; // w10

  if ( a2 && (_DWORD)a5 )
  {
    if ( a3 )
    {
      v11 = *(_QWORD *)(a3 + 216) + *(unsigned int *)(a3 + 212);
      if ( *(unsigned __int8 *)(v11 + 2) < 0x11u )
      {
        v12 = a3;
LABEL_9:
        _qdf_nbuf_add_rx_frag((__int64)a2, v12, a4, a5, a6, a7 & 1);
        return 0;
      }
      v13 = *(_QWORD **)(v11 + 8);
      if ( v13 )
      {
        do
        {
          v12 = (__int64)v13;
          v13 = (_QWORD *)*v13;
        }
        while ( v13 );
        if ( *(unsigned __int8 *)(*(_QWORD *)(v12 + 216) + *(unsigned int *)(v12 + 212) + 2LL) < 0x11u )
          goto LABEL_9;
      }
    }
    v19 = a5;
    v20 = _qdf_nbuf_alloc(a1, a8, a8, 4, a5, "qdf_nbuf_add_frag_debug", 7142);
    if ( v20 )
    {
      v21 = v20;
      _qdf_nbuf_add_rx_frag((__int64)a2, v20, a4, v19, a6, a7 & 1);
      if ( v21 == a3 )
      {
        return 0;
      }
      else
      {
        if ( (*(_BYTE *)(v21 + 68) & 4) != 0 )
          v22 = *(unsigned __int16 *)(v21 + 66);
        else
          v22 = 0;
        v23 = *(_DWORD *)(v21 + 112);
        *(_QWORD *)(*(_QWORD *)(a3 + 216) + *(unsigned int *)(a3 + 212) + 8LL) = v21;
        v24 = v23 + v22;
        v25 = *(_DWORD *)(a3 + 116) + v24;
        *(_DWORD *)(a3 + 112) += v24;
        *(_DWORD *)(a3 + 116) = v25;
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(56, 2, "%s : %d no memory to allocate\n", a9, a10);
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "%s : %d frag[ buf[%pK] len[%d]] not valid\n", a9, a10, a2, a5);
    return 4;
  }
}
