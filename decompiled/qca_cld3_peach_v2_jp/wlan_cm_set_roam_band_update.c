__int64 __fastcall wlan_cm_set_roam_band_update(__int64 a1, unsigned int a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  unsigned int v15; // w19
  __int64 result; // x0
  __int64 v17; // x21
  __int64 ext_hdl_fl; // x0
  int v19; // w8
  char v20; // w8
  __int64 v21; // x0
  unsigned int v22; // t1
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w19
  _DWORD s[103]; // [xsp+Ch] [xbp-1A4h] BYREF
  __int64 v42; // [xsp+1A8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    goto LABEL_9;
  if ( *(_BYTE *)(psoc_ext_obj_fl + 1708) != 1 )
  {
    result = 4;
    goto LABEL_10;
  }
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v5 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_set_roam_band_update");
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  if ( (*(_DWORD *)(v5 + 16) & 0xFFFFFFFD) != 0 )
  {
    v14 = 16;
    goto LABEL_6;
  }
  v17 = v5;
  ext_hdl_fl = cm_get_ext_hdl_fl(
                 v5,
                 (__int64)"wlan_cm_set_roam_band_update",
                 0xAE0u,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13);
  if ( !ext_hdl_fl )
  {
    v14 = 16;
    v5 = v17;
    goto LABEL_6;
  }
  v19 = *(unsigned __int8 *)(ext_hdl_fl + 112);
  s[0] = (unsigned __int8)a2;
  if ( v19 )
  {
    v14 = (unsigned int)cm_roam_refine_channels(v17, s, ext_hdl_fl + 112);
    v5 = v17;
    if ( (_DWORD)v14 )
      goto LABEL_6;
    v20 = 1;
LABEL_19:
    LOBYTE(s[102]) = v20;
    if ( (*(_DWORD *)(v5 + 16) & 0xFFFFFFFD) != 0 )
    {
      v14 = 4;
    }
    else
    {
      v23 = cm_get_ext_hdl_fl(v5, (__int64)"cm_roam_acquire_lock", 0x7C4u, v6, v7, v8, v9, v10, v11, v12, v13);
      cm_roam_acquire_lock_rso_cfg = v23;
      if ( v23 )
      {
        v14 = (unsigned int)qdf_mutex_acquire(v23);
        v5 = v17;
        if ( !(_DWORD)v14 )
        {
          if ( (unsigned int)mlme_get_roam_state(a1, a2) == 2 )
          {
            v32 = wlan_cm_tgt_send_roam_freqs(a1, a2, s);
            v40 = 0;
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: CHAN update received while ROAM RSO not started",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "wlan_cm_set_roam_band_update");
            v40 = 4;
          }
          cm_roam_release_lock(v17, v32, v33, v34, v35, v36, v37, v38, v39);
          v5 = v17;
          v14 = v40;
        }
      }
      else
      {
        v14 = 4;
        v5 = v17;
      }
    }
    goto LABEL_6;
  }
  v22 = *(unsigned __int8 *)(ext_hdl_fl + 168);
  v21 = ext_hdl_fl + 168;
  v14 = v22;
  if ( !v22 )
  {
    v5 = v17;
    goto LABEL_6;
  }
  v14 = (unsigned int)cm_roam_refine_channels(v17, s, v21);
  v5 = v17;
  if ( !(_DWORD)v14 )
  {
    v20 = 2;
    goto LABEL_19;
  }
LABEL_6:
  v15 = v14;
  wlan_objmgr_vdev_release_ref(v5, 2u, (unsigned int *)v14, v6, v7, v8, v9, v10, v11, v12, v13);
  result = v15;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
