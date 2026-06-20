__int64 __fastcall pmo_register_wow_default_patterns(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x4
  const char *v12; // x2
  unsigned int v13; // w8
  _QWORD *v14; // x23
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  unsigned int v25; // w0
  unsigned int v26; // w0
  const char *v27; // x3
  __int64 result; // x0
  __int64 v29; // x21
  __int64 v30; // x22
  unsigned int v31; // w0
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w0
  const char *v50; // x2
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x22
  const char *v61; // x2
  const char *v62; // x3
  unsigned int v63; // w0
  const char *v64; // x3
  const char *v65; // x2
  const char *v66; // x3
  unsigned int v67; // w1
  __int64 v68; // x0
  unsigned int v69; // w0
  __int64 v70; // x8
  unsigned int v71; // w0
  const char *v72; // x2
  unsigned int v73; // w0
  _BYTE *v74; // x8
  int v75; // [xsp+8h] [xbp-28h] BYREF
  __int16 v76; // [xsp+Ch] [xbp-24h]
  unsigned int v77; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v78; // [xsp+1Ch] [xbp-14h]
  int v79; // [xsp+20h] [xbp-10h] BYREF
  __int16 v80; // [xsp+24h] [xbp-Ch]
  __int64 v81; // [xsp+28h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v11 = *(unsigned __int8 *)(a1 + 168);
  if ( (unsigned int)v11 >= 7 )
  {
    v12 = "%s: Invalid vdev id %d";
LABEL_10:
    v27 = "pmo_register_wow_default_patterns";
    goto LABEL_11;
  }
  v13 = *(_DWORD *)(a1 + 16);
  if ( v13 == 17 )
  {
    v12 = "%s: Invalid vdev opmode %d";
    goto LABEL_10;
  }
  if ( (*(_BYTE *)(comp_private_obj + 1029) & 1) == 0 )
  {
    v12 = "%s: ptrn_match is disable for vdev %d";
    goto LABEL_10;
  }
  v14 = (_QWORD *)comp_private_obj;
  v15 = *(unsigned __int8 *)(a1 + 168);
  if ( (pmo_is_vdev_in_beaconning_mode(v13) & 1) != 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Config SAP default wow patterns vdev_id %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "pmo_register_wow_default_patterns",
      v15);
    v80 = 0;
    v79 = 0;
    v78 = 0;
    v77 = 0;
    v24 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    qdf_mem_set(&v79, 6u, 255);
    v25 = pmo_get_and_increment_wow_default_ptrn(v24);
    v26 = pmo_tgt_send_wow_patterns_to_fw(a1, v25, a1 + 74, 6, 0, &v79, 6, 0);
    if ( v26 )
    {
      v11 = v26;
      v12 = "%s: Failed to add WOW unicast pattern ret %d";
      v27 = "pmo_configure_wow_ap";
LABEL_11:
      result = qdf_trace_msg(0x4Du, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, v27, v11);
      goto LABEL_12;
    }
    pmo_get_vdev_bridge_addr(a1, &v77, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( v77 | v78
      && (v49 = pmo_get_and_increment_wow_default_ptrn(v24),
          (unsigned int)pmo_tgt_send_wow_patterns_to_fw(a1, v49, &v77, 6, 0, &v79, 6, 0)) )
    {
      v50 = "%s: Failed to add Bridge MAC address";
    }
    else
    {
      v63 = pmo_get_and_increment_wow_default_ptrn(v24);
      result = pmo_tgt_send_wow_patterns_to_fw(a1, v63, &arp_ptrn, 2, 12, &arp_mask, 2, 0);
      if ( !(_DWORD)result )
        goto LABEL_12;
      v50 = "%s: Failed to add WOW ARP pattern";
    }
    v64 = "pmo_configure_wow_ap";
LABEL_50:
    result = qdf_trace_msg(0x4Du, 2u, v50, v41, v42, v43, v44, v45, v46, v47, v48, v64);
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: Config STA default wow patterns vdev_id %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "pmo_register_wow_default_patterns",
    v15);
  v76 = 0;
  v75 = 0;
  v29 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  qdf_mem_set(&v75, 6u, 255);
  if ( *(_DWORD *)(a1 + 80) | *(unsigned __int16 *)(a1 + 84) )
    v30 = a1 + 80;
  else
    v30 = a1 + 74;
  v31 = pmo_get_and_increment_wow_default_ptrn(v29);
  v32 = pmo_tgt_send_wow_patterns_to_fw(a1, v31, v30, 6, 0, &v75, 6, 0);
  if ( v32 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: Failed to add WOW unicast pattern ret %d",
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               "pmo_configure_wow_sta",
               v32);
    goto LABEL_43;
  }
  v51 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  if ( (*(_BYTE *)(*(_QWORD *)v51 + 11LL) & 1) == 0 )
  {
    v65 = "%s: mDNS, SSDP, LLMNR patterns are disabled from ini";
    v66 = "pmo_configure_ssdp";
    v67 = 8;
LABEL_32:
    result = qdf_trace_msg(0x4Du, v67, v65, v52, v53, v54, v55, v56, v57, v58, v59, v66);
    goto LABEL_33;
  }
  v60 = v51;
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: enable_mc_list:%d",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "pmo_configure_ssdp",
    *(unsigned __int8 *)(*(_QWORD *)v51 + 12LL));
  if ( *(_BYTE *)(*(_QWORD *)v60 + 12LL) == 1 )
  {
    v80 = -1281;
    v79 = 2136866817;
    v78 = 0;
    v77 = 0;
    qdf_mem_copy(&v77, &v79, 6u);
    result = pmo_tgt_set_mc_filter_req(a1, v77 | ((unsigned __int64)v78 << 32));
    if ( (_DWORD)result )
    {
      v61 = "%s: unable to set ssdp as mc addr list filter";
      v62 = "pmo_configure_mc_ssdp";
LABEL_31:
      qdf_trace_msg(0x4Du, 2u, v61, v41, v42, v43, v44, v45, v46, v47, v48, v62);
      v65 = "%s: Failed to configure SSDP patterns to FW";
      v66 = "pmo_configure_wow_sta";
      v67 = 2;
      goto LABEL_32;
    }
  }
  else
  {
    v68 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v69 = pmo_get_and_increment_wow_default_ptrn(v68);
    result = pmo_tgt_send_wow_patterns_to_fw(a1, v69, &discvr_ptrn, 4, 30, &discvr_mask, 4, 0);
    if ( (_DWORD)result )
    {
      v61 = "%s: Failed to add WOW mDNS/SSDP/LLMNR pattern";
      v62 = "pmo_configure_wow_ssdp";
      goto LABEL_31;
    }
  }
LABEL_33:
  v70 = *(_QWORD *)v29;
  if ( *(_BYTE *)(*(_QWORD *)v29 + 2LL) != 1 || (*(_BYTE *)(v70 + 13) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: ARP offload is disabled in INI enable WoW for ARP",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "pmo_configure_wow_sta");
    v71 = pmo_get_and_increment_wow_default_ptrn(v29);
    result = pmo_tgt_send_wow_patterns_to_fw(a1, v71, &arp_ptrn, 2, 12, &arp_mask, 2, 0);
    if ( (_DWORD)result )
    {
      v72 = "%s: Failed to add WOW ARP pattern";
LABEL_42:
      result = qdf_trace_msg(0x4Du, 2u, v72, v41, v42, v43, v44, v45, v46, v47, v48, "pmo_configure_wow_sta");
      goto LABEL_43;
    }
    v70 = *(_QWORD *)v29;
  }
  if ( *(_BYTE *)(v70 + 8) != 1 || (*(_BYTE *)(v70 + 13) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: NS offload is disabled in INI enable WoW for NS",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "pmo_configure_wow_sta");
    v73 = pmo_get_and_increment_wow_default_ptrn(v29);
    result = pmo_tgt_send_wow_patterns_to_fw(a1, v73, &ns_ptrn, 2, 12, &arp_mask, 2, 0);
    if ( (_DWORD)result )
    {
      v72 = "%s: Failed to add WOW NS pattern";
      goto LABEL_42;
    }
  }
LABEL_43:
  v74 = (_BYTE *)*v14;
  if ( !*v14 )
  {
    v50 = "%s: PMO PSOC Context is NULL!";
    v64 = "pmo_register_wow_default_patterns";
    goto LABEL_50;
  }
  if ( v74[16] == 1 && ((v74[17] & 1) != 0 || v74[1] != 1 || (v74[952] & 1) == 0) )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Config STA RA wow pattern vdev_id %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "pmo_register_wow_default_patterns",
      v15);
    result = pmo_tgt_send_ra_filter_req(a1);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
