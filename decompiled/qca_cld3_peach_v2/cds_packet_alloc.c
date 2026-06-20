__int64 __fastcall cds_packet_alloc(unsigned __int16 a1, _QWORD *a2, _QWORD *a3)
{
  _DWORD *v6; // x0
  _DWORD *v7; // x22
  int v8; // w8
  __int64 result; // x0
  int v10; // w8
  int v11; // w9

  v6 = (_DWORD *)_qdf_nbuf_alloc(0, (a1 + 67) & 0x1FFFC, 64, 4, 0, "cds_packet_alloc", 98);
  if ( !v6 )
    return 16;
  v7 = v6;
  if ( v6[29] )
  {
    if ( !a1 )
      goto LABEL_9;
    v8 = 0;
  }
  else
  {
    v11 = v6[52];
    v10 = v6[53];
    if ( v10 - v11 >= (unsigned __int64)a1 )
      goto LABEL_9;
    v8 = v11 - v10;
  }
  if ( (unsigned int)pskb_expand_head(v6, 0, v8 + (unsigned int)a1, 2080) )
  {
    dev_kfree_skb_any_reason(v7, 1);
    goto LABEL_10;
  }
LABEL_9:
  skb_put(v7, a1);
LABEL_10:
  result = 0;
  *((_WORD *)v7 + 90) = 22;
  *a3 = v7;
  *a2 = *((_QWORD *)v7 + 28);
  return result;
}
