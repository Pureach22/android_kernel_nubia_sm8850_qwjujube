_QWORD *__fastcall dp_rx_get_txrx_peer_and_vdev(
        __int64 a1,
        _QWORD *a2,
        unsigned int a3,
        _QWORD *a4,
        _QWORD *a5,
        _QWORD *a6,
        _DWORD *a7,
        _DWORD *a8)
{
  _QWORD *ref_by_id; // x0
  _QWORD *result; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  _QWORD *v19; // x21

  ref_by_id = (_QWORD *)dp_peer_get_ref_by_id(a1, a3, 2);
  if ( !ref_by_id )
    goto LABEL_7;
  if ( !*ref_by_id )
  {
    dp_peer_unref_delete(ref_by_id, 2);
    goto LABEL_7;
  }
  *a4 = ref_by_id;
  result = (_QWORD *)*ref_by_id;
  if ( !result )
  {
LABEL_7:
    *a2 = 0;
    dp_rx_deliver_to_stack_no_peer(a1, a2);
    return nullptr;
  }
  v17 = *result;
  *a5 = *result;
  if ( v17 )
  {
    v18 = *(_QWORD *)(v17 + 24);
    *a6 = v18;
    *a7 = *(unsigned __int8 *)(v18 + 95938);
    *a8 = 255;
  }
  else
  {
    v19 = result;
    if ( a2 )
      _qdf_nbuf_free((__int64)a2);
    ++*(_DWORD *)(a1 + 13748);
    return v19;
  }
  return result;
}
