_DWORD *__fastcall mdnie_art_in_progress(_DWORD *result)
{
  if ( result )
    return (_DWORD *)((*result >> 2) & 1);
  return result;
}
