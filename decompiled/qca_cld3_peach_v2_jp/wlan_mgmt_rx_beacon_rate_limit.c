__int64 __fastcall wlan_mgmt_rx_beacon_rate_limit(__int64 a1, __int64 a2)
{
  __int64 pdev_by_id; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x8
  unsigned int v7; // w19

  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, *(unsigned __int8 *)(a2 + 48), 3);
  if ( pdev_by_id )
  {
    if ( *(_BYTE *)(pdev_by_id + 528) == 1
      && ((v3 = *(_QWORD *)(pdev_by_id + 544),
           v4 = (((v3 * *(unsigned __int8 *)(pdev_by_id + 552)) >> 2) * (unsigned __int128)0x28F5C28F5C28F5C3uLL) >> 64,
           v5 = *(_QWORD *)(pdev_by_id + 536),
           v5 + 1 < v3)
        ? (v6 = v5 + 1)
        : (v6 = 0),
          *(_QWORD *)(pdev_by_id + 536) = v6,
          v6 >= v4 >> 2) )
    {
      v7 = 1;
      ++*(_QWORD *)(pdev_by_id + 560);
    }
    else
    {
      v7 = 0;
    }
    wlan_objmgr_pdev_release_ref(pdev_by_id, 3);
  }
  else
  {
    return 0;
  }
  return v7;
}
