__int64 __fastcall target_if_get_curr_band(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *first_vdev; // x19
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int16 (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w0
  const char *v16; // x2
  unsigned int v17; // w1
  const char *v18; // x2
  unsigned int v19; // w20
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a1 )
  {
    if ( a2 == -1 )
    {
      first_vdev = wlan_objmgr_pdev_get_first_vdev(a1, 0x1Bu);
      if ( first_vdev )
        goto LABEL_4;
    }
    else
    {
      first_vdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x1Bu);
      if ( first_vdev )
      {
LABEL_4:
        v11 = first_vdev[27];
        if ( v11 && (v12 = *(_QWORD *)(v11 + 80)) != 0 )
        {
          v13 = *(_QWORD *)(v12 + 2136);
          if ( v13 )
          {
            v14 = *(__int16 (__fastcall **)(_QWORD))(v13 + 272);
            if ( *((_DWORD *)v14 - 1) != -810236724 )
              __break(0x8228u);
            v15 = v14(first_vdev);
            goto LABEL_13;
          }
          v18 = "%s: rx_ops is null";
        }
        else
        {
          v18 = "%s: psoc is NULL";
        }
        qdf_trace_msg(0x56u, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_get_chan_freq");
        v15 = -22;
LABEL_13:
        v19 = wlan_reg_freq_to_band(v15);
        wlan_objmgr_vdev_release_ref((__int64)first_vdev, 0x1Bu, v20, v21, v22, v23, v24, v25, v26, v27, v28);
        return v19;
      }
    }
    v16 = "%s: vdev is NULL";
    v17 = 8;
  }
  else
  {
    v16 = "%s: pdev is NULL";
    v17 = 2;
  }
  qdf_trace_msg(0x56u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_get_curr_band");
  return 3;
}
