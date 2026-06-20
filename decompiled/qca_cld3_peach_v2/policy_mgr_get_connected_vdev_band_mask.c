__int64 __fastcall policy_mgr_get_connected_vdev_band_mask(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  char is_mlo_vdev; // w8
  char v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  unsigned __int16 *v21; // x0
  __int64 v22; // x19
  unsigned __int16 *active_channel; // x0
  const char *v24; // x2
  unsigned int v25; // w1
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  unsigned __int16 *v36; // x0
  unsigned __int16 v37; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-18h] BYREF
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v37 = 0;
  if ( !a1 )
  {
    v24 = "%s: vdev is NULL";
LABEL_15:
    v25 = 2;
LABEL_16:
    qdf_trace_msg(0x4Fu, v25, v24, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_get_connected_vdev_band_mask");
    goto LABEL_17;
  }
  if ( *(_DWORD *)(a1 + 16) )
    goto LABEL_11;
  v9 = a1;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  a1 = v9;
  if ( (is_mlo_vdev & 1) != 0 && (*(_BYTE *)(v9 + 60) & 2) != 0 )
  {
    v24 = "%s: skip mlo link sta";
    v25 = 8;
    goto LABEL_16;
  }
  if ( *(_DWORD *)(v9 + 16)
    || (v11 = wlan_vdev_mlme_is_mlo_vdev(v9, a2, a3, a4, a5, a6, a7, a8, a9), a1 = v9, (v11 & 1) == 0) )
  {
LABEL_11:
    active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(a1);
    if ( active_channel )
    {
      v22 = 1LL << wlan_reg_freq_to_band(*active_channel);
      goto LABEL_18;
    }
    v24 = "%s: no active channel";
    goto LABEL_15;
  }
  mlo_get_ml_vdev_list(v9, &v37, &v38);
  if ( !v37 )
  {
LABEL_17:
    LODWORD(v22) = 0;
    goto LABEL_18;
  }
  v20 = v38;
  if ( ucfg_cm_is_vdev_connected(v38, v12, v13, v14, v15, v16, v17, v18, v19)
    && (v21 = (unsigned __int16 *)wlan_vdev_get_active_channel(v20)) != nullptr )
  {
    v22 = 1LL << wlan_reg_freq_to_band(*v21);
  }
  else
  {
    LODWORD(v22) = 0;
  }
  mlo_release_vdev_ref(v20);
  if ( v37 >= 2u )
  {
    v35 = v39;
    if ( ucfg_cm_is_vdev_connected(v39, v27, v28, v29, v30, v31, v32, v33, v34) )
    {
      v36 = (unsigned __int16 *)wlan_vdev_get_active_channel(v35);
      if ( v36 )
        LODWORD(v22) = v22 | (1LL << wlan_reg_freq_to_band(*v36));
    }
    mlo_release_vdev_ref(v35);
    if ( v37 > 2u )
      __break(0x5512u);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v22;
}
