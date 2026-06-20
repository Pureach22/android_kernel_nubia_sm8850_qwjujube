_BYTE *__fastcall is_world_regdom(_BYTE *result)
{
  if ( result )
  {
    if ( *result == 48 )
      return (_BYTE *)(result[1] == 48);
    else
      return nullptr;
  }
  return result;
}
