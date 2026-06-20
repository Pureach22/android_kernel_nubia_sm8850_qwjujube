__int64 __fastcall _qdf_nbuf_move_frag_page_offset(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( *(unsigned __int8 *)(v3 + 2) <= (unsigned int)a2 )
    return 16;
  if ( a2 >= 0x12u )
  {
    __break(0x5512u);
    return _qdf_nbuf_remove_frag();
  }
  else
  {
    *(_DWORD *)(v3 + 16LL * a2 + 100) += a3;
    skb_coalesce_rx_frag(a1, a2);
    return 0;
  }
}
