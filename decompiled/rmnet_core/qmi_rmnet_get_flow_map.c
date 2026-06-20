__int64 *__fastcall qmi_rmnet_get_flow_map(__int64 *result, int a2, int a3)
{
  __int64 *v3; // x8

  if ( result )
  {
    v3 = result + 5;
    for ( result = (__int64 *)result[5]; result != v3; result = (__int64 *)*result )
    {
      if ( *((_DWORD *)result + 5) == a2 && *((_DWORD *)result + 6) == a3 )
        return result;
    }
    return nullptr;
  }
  return result;
}
