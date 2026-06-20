__int64 __fastcall sme_get_operation_channel(__int64 a1, _DWORD *a2, unsigned __int8 a3)
{
  __int64 result; // x0
  __int64 v5; // x9

  result = 16;
  if ( a1 )
  {
    if ( a3 <= 5u )
    {
      v5 = *(_QWORD *)(a1 + 17296);
      if ( v5 )
      {
        if ( *(_BYTE *)(v5 + 96LL * a3 + 1) == 1 )
        {
          *a2 = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a3);
          return 0;
        }
      }
    }
  }
  return result;
}
