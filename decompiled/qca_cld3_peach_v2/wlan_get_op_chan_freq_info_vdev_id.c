__int64 __fastcall wlan_get_op_chan_freq_info_vdev_id(__int64 a1, char a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  unsigned int *v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  unsigned int v19; // w20
  __int64 active_channel; // x0
  unsigned __int16 *v22; // x21

  *a3 = 0;
  *a4 = 0;
  *a5 = 0;
  if ( a1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 7u);
    v18 = (__int64)vdev_by_id_from_pdev;
    if ( vdev_by_id_from_pdev
      && !(unsigned int)wlan_vdev_mlme_is_active((__int64)vdev_by_id_from_pdev)
      && (active_channel = wlan_vdev_get_active_channel(v18)) != 0 )
    {
      v22 = (unsigned __int16 *)active_channel;
      if ( (unsigned int)wlan_mlme_get_sta_ch_width(v18, a5, 0) )
        *a5 = *((_DWORD *)v22 + 6);
      v19 = 0;
      *a3 = *v22;
      v9 = (unsigned int *)*((unsigned int *)v22 + 4);
      *a4 = (_DWORD)v9;
    }
    else
    {
      v19 = 4;
    }
    wlan_objmgr_vdev_release_ref(v18, 7u, v9, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  else
  {
    return 4;
  }
  return v19;
}
