__int64 __fastcall wlan_mlme_get_tx_power(__int64 a1, int a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    if ( a2 == 2 )
    {
      return *(unsigned __int8 *)(result + 4625);
    }
    else if ( a2 == 1 )
    {
      return *(unsigned __int8 *)(result + 4624);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
