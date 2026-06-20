_WORD *__fastcall qdf_ether_addr_copy(_WORD *result, _WORD *a2)
{
  if ( !result || !a2 )
    return (_WORD *)qdf_trace_msg(
                      56,
                      2,
                      "%s called with NULL parameter, source:%pK destination:%pK",
                      "qdf_ether_addr_copy",
                      a2,
                      result);
  *(_DWORD *)result = *(_DWORD *)a2;
  result[2] = a2[2];
  return result;
}
