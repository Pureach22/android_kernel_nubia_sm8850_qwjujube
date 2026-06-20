_QWORD *__fastcall tdls_get_peer(__int64 *a1, unsigned __int8 *a2)
{
  _QWORD *result; // x0

  result = tdls_find_peer((__int64)a1, a2);
  if ( !result )
    return (_QWORD *)tdls_add_peer(a1, a2);
  return result;
}
