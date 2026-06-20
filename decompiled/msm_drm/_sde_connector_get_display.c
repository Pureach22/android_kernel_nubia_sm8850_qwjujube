__int64 *__fastcall sde_connector_get_display(__int64 *result)
{
  __int64 *v1; // x8

  if ( result )
  {
    if ( *((_DWORD *)result + 684) == 16 )
    {
      v1 = result + 345;
      if ( *((_BYTE *)result + 5128) == 1 )
        v1 = (__int64 *)*v1;
      return (__int64 *)*v1;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}
