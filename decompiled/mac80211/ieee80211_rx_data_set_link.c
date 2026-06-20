__int64 __fastcall ieee80211_rx_data_set_link(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x9

  *(_DWORD *)(result + 76) = a2;
  if ( a2 >= 0x10u )
  {
    __break(0x5512u);
    return ieee80211_release_reorder_frame(result);
  }
  else
  {
    v2 = *(_QWORD *)(result + 40);
    *(_QWORD *)(result + 32) = *(_QWORD *)(*(_QWORD *)(result + 24) + 8LL * a2 + 4568);
    if ( v2 )
    {
      if ( (((unsigned __int64)*(unsigned __int16 *)(v2 + 2872) >> a2) & 1) != 0 )
        *(_QWORD *)(result + 48) = *(_QWORD *)(v2 + 8LL * a2 + 2568);
    }
  }
  return result;
}
