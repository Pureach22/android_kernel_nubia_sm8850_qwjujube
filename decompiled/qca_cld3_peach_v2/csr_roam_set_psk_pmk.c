__int64 __fastcall csr_roam_set_psk_pmk(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v8; // x0
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 v27; // x8
  __int64 result; // x0
  bool v29; // zf
  bool v30; // zf
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // [xsp+8h] [xbp-18h] BYREF
  __int16 v40; // [xsp+Ch] [xbp-14h]
  unsigned int v41; // [xsp+10h] [xbp-10h] BYREF
  __int16 v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 21624);
  v40 = 0;
  v39 = 0;
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v8, a3, 11);
  if ( v9 )
  {
    v18 = v9;
    wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a3, &v39);
    v27 = *(unsigned int *)(v18 + 20);
    if ( (_DWORD)v27 != 3 )
      goto LABEL_4;
    v27 = *(unsigned __int8 *)(a2 + 87);
    if ( *(_BYTE *)(a2 + 87) )
      goto LABEL_4;
    v27 = v39;
    v29 = v39 == *(_DWORD *)a2 && v40 == *(_WORD *)(a2 + 4);
    if ( v29
      || ((v42 = 0,
           v41 = 0,
           wlan_vdev_get_bss_peer_mld_mac(v18, &v41, v19, v20, v21, v22, v23, v24, v25, v26),
           v27 = v41,
           v41 == *(_DWORD *)a2)
        ? (v30 = v42 == *(_WORD *)(a2 + 4))
        : (v30 = 0),
          v30) )
    {
LABEL_4:
      wlan_objmgr_vdev_release_ref(v18, 0xBu, (unsigned int *)v27, v19, v20, v21, v22, v23, v24, v25, v26);
      wlan_cm_set_psk_pmk(*(_QWORD *)(a1 + 21632), a3, (const void *)(a2 + 22), *(_BYTE *)(a2 + 86));
      if ( (a4 & 1) != 0 && (unsigned int)wlan_roam_update_cfg(*(_QWORD *)(a1 + 21624), a3, 0x25u) == 4 )
        wlan_mlme_defer_pmk_set_in_roaming(*(_QWORD *)(a1 + 21624), a3, 1);
      result = 0;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v18, 0xBu, (unsigned int *)v41, v19, v20, v21, v22, v23, v24, v25, v26);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Set pmksa received for non-connected bss",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "csr_roam_set_psk_pmk");
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(31, 8, a2 + 22, 2);
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: vdev is NULL", v10, v11, v12, v13, v14, v15, v16, v17, "csr_roam_set_psk_pmk");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
