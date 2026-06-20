_QWORD *__fastcall drm_atomic_get_mst_payload_state(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9

  v2 = (_QWORD *)(a1 + 56);
  while ( 1 )
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == (_QWORD *)(a1 + 56) )
      break;
    if ( *(v2 - 4) == a2 )
      return v2 - 4;
  }
  return nullptr;
}
