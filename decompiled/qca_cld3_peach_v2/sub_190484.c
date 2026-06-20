__int64 __fastcall sub_190484(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x11

  return _qdf_nbuf_page_frag_alloc(a1, a2, a3, a4, v4 - __ROR8__(a3, 31));
}
