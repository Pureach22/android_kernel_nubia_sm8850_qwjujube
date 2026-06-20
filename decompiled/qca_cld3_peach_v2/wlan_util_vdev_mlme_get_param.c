__int64 __fastcall wlan_util_vdev_mlme_get_param(
        __int64 result,
        int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  int v13; // w8

  if ( !result )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: VDEV MLME is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_util_vdev_mlme_get_param",
             v11,
             v12);
  if ( a2 > 5 )
  {
    if ( a2 > 8 )
    {
      switch ( a2 )
      {
        case 9:
          v13 = *(_DWORD *)(result + 296);
          break;
        case 10:
          v13 = *(_DWORD *)(result + 300);
          break;
        case 11:
          v13 = *(_DWORD *)(result + 304);
          break;
        default:
          return result;
      }
    }
    else if ( a2 == 6 )
    {
      v13 = *(unsigned __int8 *)(result + 57);
    }
    else if ( a2 == 7 )
    {
      v13 = *(unsigned __int8 *)(result + 58);
    }
    else
    {
      v13 = *(_DWORD *)(result + 292);
    }
  }
  else if ( a2 > 2 )
  {
    if ( a2 == 3 )
    {
      v13 = *(unsigned __int8 *)(result + 54);
    }
    else if ( a2 == 4 )
    {
      v13 = *(unsigned __int8 *)(result + 55);
    }
    else
    {
      v13 = *(unsigned __int8 *)(result + 56);
    }
  }
  else if ( a2 )
  {
    if ( a2 == 1 )
    {
      v13 = *(unsigned __int8 *)(result + 52);
    }
    else
    {
      if ( a2 != 2 )
        return result;
      v13 = *(unsigned __int8 *)(result + 53);
    }
  }
  else
  {
    v13 = *(unsigned __int16 *)(result + 20);
  }
  *a3 = v13;
  return result;
}
