// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_17AD64(__int64 a1)
{
  __int64 v1; // x23
  int v2; // w8
  unsigned __int16 v3; // w10
  _DWORD *v4; // x11
  __int64 v5; // x2
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 v8; // x9
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 v11; // x21
  signed int v12; // w22
  __int64 v13; // x24
  __int64 v14; // x25
  __int64 v15; // x26
  int v16; // w27
  unsigned int v17; // w28

  if ( !v8 )
    return qdf_mem_copy_toio();
  while ( 1 )
  {
    ce_recv_buf_enqueue(a1);
    if ( v12 <= (unsigned int)(unsigned __int16)++v16 )
      break;
LABEL_18:
    a1 = *(_QWORD *)v11;
  }
  while ( 1 )
  {
    if ( ++v14 >= (unsigned __int64)*(unsigned int *)(v9 + 656) )
      return 0;
    if ( v14 == 12 )
      break;
    v1 = *(_QWORD *)(v15 + 8 * v14);
    if ( v1 && (*(_BYTE *)(v1 + 12) & 0x40) == 0 )
    {
      v11 = v13 + 136 * v14;
      v2 = *(_DWORD *)(v9 + 30712);
      if ( v2 < 1 )
        goto LABEL_21;
      v3 = 0;
      while ( 1 )
      {
        v4 = (_DWORD *)(*(_QWORD *)(v9 + 30704) + v3 * (unsigned __int64)v17);
        if ( *v4 == 1792 && v4[1] == 1 && v14 == v4[2] )
        {
          v12 = *(_DWORD *)(v11 + 24);
          v5 = *(_QWORD *)(v11 + 32);
          if ( v5 )
          {
            if ( v12 )
              break;
          }
        }
        if ( v2 <= (unsigned int)++v3 )
          goto LABEL_21;
      }
      *(_DWORD *)(v10 + 40) = v14;
      hif_prealloc_get_multi_pages(v9, 0xFu, v5, v12, v10, 0);
      if ( *(_WORD *)(v10 + 2) )
      {
        if ( v12 >= 1 )
        {
          v16 = 0;
          goto LABEL_18;
        }
      }
      else
      {
LABEL_21:
        v6 = hif_post_recv_buffers_for_pipe((__int64 *)(v13 + 136 * v14));
        if ( v6 && *(_BYTE *)(v1 + 273) == 1 && (*(_BYTE *)(v9 + 716) & 1) != 0 )
        {
          v7 = v6;
          goto LABEL_27;
        }
      }
    }
  }
  v7 = 4;
LABEL_27:
  qdf_trace_msg(61, 2, "%s: Failed to post buffers", "hif_start");
  return v7;
}
