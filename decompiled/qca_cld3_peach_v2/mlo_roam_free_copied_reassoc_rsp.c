_QWORD *__fastcall mlo_roam_free_copied_reassoc_rsp(_QWORD *result)
{
  __int64 v1; // x8
  __int64 v2; // x19

  if ( result )
  {
    v1 = result[170];
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 2224);
      if ( v2 )
      {
        result = *(_QWORD **)(v2 + 288);
        if ( result )
        {
          if ( result[18] )
          {
            result = wlan_cm_free_connect_resp(result);
            *(_QWORD *)(v2 + 288) = 0;
          }
        }
      }
    }
  }
  return result;
}
