__int64 __fastcall cm_roam_is_per_roam_allowed(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  int bss_peer_mac; // w22
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  int v34; // [xsp+10h] [xbp-10h] BYREF
  __int16 v35; // [xsp+14h] [xbp-Ch]
  __int64 v36; // [xsp+18h] [xbp-8h]

  v2 = a2;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v33 = 0;
  v34 = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v4 )
  {
    v13 = v4;
    bss_peer_mac = wlan_vdev_get_bss_peer_mac(v4, &v34, v5, v6, v7, v8, v9, v10, v11, v12);
    wlan_objmgr_vdev_release_ref(v13, 0x4Du, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( !bss_peer_mac )
    {
      mlme_get_peer_phymode(a1, &v34, &v33);
      if ( v33 > 4 )
      {
        result = 1;
        goto LABEL_7;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev:%d PER roam trigger disabled for phymode:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "cm_roam_is_per_roam_allowed");
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Vdev is null for vdev_id:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_roam_is_per_roam_allowed",
      v2);
  }
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
