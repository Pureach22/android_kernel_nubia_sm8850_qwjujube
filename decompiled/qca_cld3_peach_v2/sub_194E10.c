__int64 __fastcall sub_194E10(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, atomic_ullong *a6)
{
  unsigned int v6; // w10
  unsigned int v7; // w11
  unsigned int v8; // w30
  unsigned __int64 v9; // t2

  v9 = __PAIR64__(v7, v6);
  atomic_compare_exchange_strong(a6, &v9, v8);
  return _qdf_nbuf_move_frag_page_offset();
}
