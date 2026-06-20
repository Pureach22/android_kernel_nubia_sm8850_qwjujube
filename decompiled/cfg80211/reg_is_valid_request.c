bool __fastcall reg_is_valid_request(unsigned __int8 *a1)
{
  _BOOL8 result; // x0

  if ( !last_request )
    return 0;
  result = 0;
  if ( a1 && (*((_BYTE *)last_request + 37) & 1) == 0 )
  {
    if ( *((unsigned __int8 *)last_request + 28) == *a1 )
      return *((unsigned __int8 *)last_request + 29) == a1[1];
    return 0;
  }
  return result;
}
