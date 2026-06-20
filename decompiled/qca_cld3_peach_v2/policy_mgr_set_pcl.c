__int64 __fastcall policy_mgr_set_pcl(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  __int64 v25; // x20
  unsigned __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  unsigned __int64 v29; // x10
  __int64 result; // x0
  char v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // [xsp+8h] [xbp-38h] BYREF
  __int64 v41; // [xsp+10h] [xbp-30h]
  __int64 v42; // [xsp+18h] [xbp-28h]
  __int64 v43; // [xsp+20h] [xbp-20h]
  __int64 v44; // [xsp+28h] [xbp-18h]
  __int64 v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: msg is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "policy_mgr_set_pcl");
LABEL_18:
    result = 16;
    goto LABEL_19;
  }
  if ( !(unsigned int)mlme_get_roam_state(a1, a3) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Roam is not initialized on vdev:%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_set_pcl",
      (unsigned __int8)a3);
    goto LABEL_18;
  }
  v24 = _qdf_mem_malloc(0x410u, "policy_mgr_set_pcl", 2130);
  if ( v24 )
  {
    v25 = v24;
    *(_DWORD *)(v24 + 4) = policy_mgr_get_connected_roaming_vdev_band_mask(a1, a3);
    if ( *(_DWORD *)(a2 + 512) )
    {
      v26 = 0;
      v27 = 938;
      do
      {
        if ( v27 == 1040 )
          __break(0x5512u);
        v28 = 4 * v26++;
        *(_DWORD *)(v25 + v28 + 12) = *(_DWORD *)(a2 + v28);
        *(_BYTE *)(v25 + v27) = *(_BYTE *)(a2 + v27 - 530);
        ++v27;
        v29 = *(unsigned int *)(a2 + 512);
      }
      while ( v26 < v29 );
    }
    else
    {
      LODWORD(v29) = 0;
    }
    *(_DWORD *)(v25 + 420) = v29;
    *(_BYTE *)(v25 + 8) = a4 & 1;
    if ( (wlan_cm_roam_is_pcl_per_vdev_active(a1, a3) & 1) != 0 )
      v31 = a3;
    else
      v31 = -1;
    *(_BYTE *)v25 = v31;
    v41 = v25;
    LOWORD(v40) = 4289;
    result = scheduler_post_message_debug(
               0x4Fu,
               0x36u,
               54,
               (unsigned __int16 *)&v40,
               0x86Eu,
               (__int64)"policy_mgr_set_pcl");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: scheduler_post_msg failed!(err=%d)",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "policy_mgr_set_pcl",
        (unsigned int)result);
      _qdf_mem_free(v25);
      goto LABEL_18;
    }
  }
  else
  {
    result = 2;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
