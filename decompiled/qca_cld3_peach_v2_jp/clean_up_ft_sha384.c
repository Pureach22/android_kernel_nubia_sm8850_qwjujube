__int64 __fastcall clean_up_ft_sha384(__int64 result, char a2)
{
  __int64 v2; // x19

  if ( (a2 & 1) != 0 )
  {
    v2 = result;
    _qdf_mem_free(*(_QWORD *)(result + 680));
    return _qdf_mem_free(*(_QWORD *)(v2 + 744));
  }
  return result;
}
