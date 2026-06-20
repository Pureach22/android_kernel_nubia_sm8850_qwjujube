__int64 __fastcall p2p_packet_alloc(unsigned __int16 a1, _QWORD *a2, _QWORD *a3)
{
  unsigned int v3; // w19
  _DWORD *v7; // x0
  _DWORD *v8; // x22
  int v9; // w8
  int v11; // w8
  int v12; // w9
  void *v13; // x0

  v3 = a1;
  v7 = (_DWORD *)_qdf_nbuf_alloc(0, (a1 + 67) & 0x1FFFC, 64, 4, 0, "p2p_packet_alloc", 1073);
  if ( !v7 )
    return 16;
  v8 = v7;
  if ( v7[29] )
  {
    if ( !a1 )
      goto LABEL_9;
    v9 = 0;
  }
  else
  {
    v12 = v7[52];
    v11 = v7[53];
    if ( v11 - v12 >= (unsigned __int64)a1 )
      goto LABEL_9;
    v9 = v12 - v11;
  }
  if ( (unsigned int)pskb_expand_head(v7, 0, v9 + v3, 2080) )
  {
    dev_kfree_skb_any_reason(v8, 1);
    goto LABEL_10;
  }
LABEL_9:
  skb_put(v8, v3);
LABEL_10:
  *((_WORD *)v8 + 90) = 22;
  *a3 = v8;
  v13 = *((void **)v8 + 28);
  *a2 = v13;
  qdf_mem_set(v13, v3, 0);
  return 0;
}
