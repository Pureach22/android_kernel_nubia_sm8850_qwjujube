_QWORD *__fastcall qdf_nbuf_list_free(_QWORD *result)
{
  void (*v1)(void); // x8
  _QWORD *v2; // x20

  if ( result )
  {
    do
    {
      while ( 1 )
      {
        v1 = (void (*)(void))nbuf_free_cb;
        v2 = (_QWORD *)*result;
        if ( nbuf_free_cb )
          break;
        dev_kfree_skb_any_reason(result, 1);
        result = v2;
        if ( !v2 )
          return result;
      }
      if ( *((_DWORD *)nbuf_free_cb - 1) != 303786302 )
        __break(0x8228u);
      v1();
      result = v2;
    }
    while ( v2 );
  }
  return result;
}
