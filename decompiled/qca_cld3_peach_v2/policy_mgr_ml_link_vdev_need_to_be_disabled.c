__int64 __fastcall policy_mgr_ml_link_vdev_need_to_be_disabled(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v14; // w8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  __int64 assoc_link_vdev; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w21
  unsigned int operation_chan_freq; // w0
  _WORD v36[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v37; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 16)
    || (wlan_vdev_mlme_is_mlo_vdev(a2, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0
    || (*(_BYTE *)(a2 + 60) & 2) == 0 )
  {
    goto LABEL_4;
  }
  v37 = 0;
  v36[0] = 0;
  if ( (ml_is_nlink_service_supported(a1) & 1) != 0 )
  {
    ml_nlink_get_dynamic_inactive_links(a1, a2, &v37, v36);
    v24 = 1 << *(_BYTE *)(a2 + 93);
    if ( (a3 & 1) != 0 )
    {
      if ( ((unsigned __int16)v24 & v37) != 0 )
      {
LABEL_4:
        v14 = 0;
        goto LABEL_5;
      }
    }
    else if ( ((unsigned __int16)v24 & (unsigned __int16)(v36[0] | v37)) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev %d linkid %d is forced inactived 0x%0x dyn 0x%x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "policy_mgr_vdev_disabled_by_link_force",
        *(unsigned __int8 *)(a2 + 168));
      v14 = 1;
      goto LABEL_5;
    }
  }
  if ( a2 && !*(_DWORD *)(a2 + 16) && (wlan_vdev_mlme_is_mlo_vdev(a2, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(a2)) != 0 )
    {
      if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v26, v27, v28, v29, v30, v31, v32, v33) )
        v34 = 3;
      else
        v34 = 1;
    }
    else
    {
      v34 = 1;
    }
  }
  else
  {
    v34 = 0;
  }
  operation_chan_freq = wlan_get_operation_chan_freq(a2);
  v14 = policy_mgr_is_concurrency_allowed(a1, 0, operation_chan_freq, 3, v34, 0) ^ 1;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
