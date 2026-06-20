bool __fastcall change_allowed(_BOOL8 result, _DWORD *a2)
{
  if ( result )
    return *a2 != 0;
  return result;
}
