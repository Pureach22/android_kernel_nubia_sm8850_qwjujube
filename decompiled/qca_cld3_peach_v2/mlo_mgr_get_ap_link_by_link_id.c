unsigned __int8 *__fastcall mlo_mgr_get_ap_link_by_link_id(__int64 a1, unsigned int a2)
{
  unsigned __int8 *result; // x0

  result = nullptr;
  if ( a1 )
  {
    if ( a2 <= 0xE )
    {
      result = *(unsigned __int8 **)(a1 + 3880);
      if ( result[6] != a2 )
      {
        if ( result[54] == a2 )
        {
          result += 48;
        }
        else if ( result[102] == a2 )
        {
          result += 96;
        }
        else
        {
          return nullptr;
        }
      }
    }
  }
  return result;
}
