_QWORD *__fastcall qdf_get_nbuf_valid_frag(_QWORD *result)
{
  __int64 v1; // x8
  _QWORD *v2; // x9
  _QWORD *v3; // x8

  if ( result )
  {
    v1 = result[27] + *((unsigned int *)result + 53);
    if ( *(unsigned __int8 *)(v1 + 2) >= 0x11u )
    {
      v2 = *(_QWORD **)(v1 + 8);
      if ( v2 )
      {
        do
        {
          v3 = v2;
          v2 = (_QWORD *)*v2;
        }
        while ( v2 );
        if ( *(unsigned __int8 *)(v3[27] + *((unsigned int *)v3 + 53) + 2LL) >= 0x11u )
          return nullptr;
        else
          return v3;
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}
