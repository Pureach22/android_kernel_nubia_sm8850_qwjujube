__int64 __fastcall _qdf_nbuf_free(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = (__int64 (*)(void))nbuf_free_cb;
  if ( !nbuf_free_cb )
    return dev_kfree_skb_any_reason(a1, 1);
  if ( *((_DWORD *)nbuf_free_cb - 1) != 303786302 )
    __break(0x8228u);
  return v1();
}
