__int64 __fastcall lim_roam_mlo_create_peer(__int64 a1, __int64 a2, unsigned int a3, _BYTE *a4)
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
  __int64 v18; // x19
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w24
  unsigned int sta_link_mac_addr; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  _QWORD *peer_by_mac; // x0
  __int64 v53; // x20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // [xsp+0h] [xbp-C0h] BYREF
  __int16 v63; // [xsp+4h] [xbp-BCh]
  __int64 v64; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v65[22]; // [xsp+10h] [xbp-B0h] BYREF

  v65[21] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 21624);
  v64 = 0;
  memset(v65, 0, 168);
  v63 = 0;
  v62 = 0;
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v8, a3, 7);
  if ( v9 )
  {
    v18 = v9;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v9, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
    {
      v28 = ((__int64 (__fastcall *)(_QWORD, __int64))mlo_roam_get_link_id)(a3, a2);
      LOBYTE(v64) = 1;
      sta_link_mac_addr = mlo_get_sta_link_mac_addr(a3, a2, &v62);
      if ( sta_link_mac_addr )
      {
        v38 = sta_link_mac_addr;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Link mac address not found",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "lim_roam_mlo_create_peer");
      }
      else
      {
        qdf_mem_copy(v65, &v62, 6u);
        if ( v65 )
          v48 = LOBYTE(v65[0]);
        else
          v48 = 0;
        if ( v65 )
          v49 = BYTE1(v65[0]);
        else
          v49 = 0;
        if ( v65 )
          v50 = BYTE2(v65[0]);
        else
          v50 = 0;
        if ( v65 )
          v51 = BYTE5(v65[0]);
        else
          v51 = 0;
        BYTE6(v65[0]) = v28;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: link_addr %02x:%02x:%02x:**:**:%02x",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "lim_roam_mlo_create_peer",
          v48,
          v49,
          v50,
          v51);
        peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), a4, 7u);
        if ( peer_by_mac )
        {
          v53 = (__int64)peer_by_mac;
          v38 = wlan_mlo_peer_create(v18, peer_by_mac, &v64, 0, 0);
          if ( v38 )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: MLO peer creation failed",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "lim_roam_mlo_create_peer");
          wlan_objmgr_peer_release_ref(v53, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
        }
        else
        {
          v38 = 4;
        }
      }
    }
    else
    {
      v38 = 0;
    }
    wlan_objmgr_vdev_release_ref(v18, 7u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    v38 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v38;
}
