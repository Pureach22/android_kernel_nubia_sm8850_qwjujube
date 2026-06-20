__int64 __fastcall wma_find_vdev_id_by_bssid(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x25
  unsigned __int64 v15; // x24
  __int64 v16; // x0
  __int64 cmpt_obj; // x0

  if ( !*(_WORD *)(a1 + 162) )
    return 16;
  v14 = 0;
  v15 = 0;
  do
  {
    v16 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + v14);
    if ( v16 )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v16, a4, a5, a6, a7, a8, a9, a10, a11);
      if ( cmpt_obj )
      {
        if ( *(_DWORD *)(cmpt_obj + 168) == *(_DWORD *)a2
          && *(unsigned __int16 *)(cmpt_obj + 172) == *(unsigned __int16 *)(a2 + 4) )
        {
          *a3 = v15;
          return 0;
        }
      }
      else
      {
        qdf_trace_msg(0x36u, 2u, "%s: Failed to get mlme_obj", a4, a5, a6, a7, a8, a9, a10, a11, "wma_get_vdev_bssid");
      }
    }
    ++v15;
    v14 += 488;
  }
  while ( v15 < *(unsigned __int16 *)(a1 + 162) );
  return 16;
}
