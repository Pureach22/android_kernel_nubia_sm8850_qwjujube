__int64 *__fastcall qmi_rmnet_get_bearer_map(__int64 *result, unsigned __int8 a2)
{
  __int64 *v2; // x8

  if ( result )
  {
    v2 = result + 7;
    result += 7;
    while ( 1 )
    {
      result = (__int64 *)*result;
      if ( result == v2 )
        break;
      if ( *((unsigned __int8 *)result + 16) == a2 )
        return result;
    }
    return nullptr;
  }
  return result;
}
