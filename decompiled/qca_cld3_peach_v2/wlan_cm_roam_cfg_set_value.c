__int64 __fastcall wlan_cm_roam_cfg_set_value(__int64 a1, unsigned int a2, unsigned int a3, unsigned int *a4)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v9; // x26
  __int64 v10; // x0
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x25
  unsigned int *v21; // x8
  __int64 result; // x0
  __int64 v23; // x19
  __int64 ext_hdl_fl; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  int updated; // w0
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x23
  int v41; // w8
  const void *v42; // x1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  const char *v59; // x2
  __int64 v60; // x4
  __int64 v61; // x5
  int v62; // w8
  const void *v63; // x1
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  char v80; // w9
  unsigned int v81; // w19
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  _DWORD s[103]; // [xsp+Ch] [xbp-1A4h] BYREF
  __int64 v91; // [xsp+1A8h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    goto LABEL_6;
  v9 = psoc_ext_obj_fl;
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_cm_roam_cfg_set_value");
    result = 16;
    goto LABEL_79;
  }
  v20 = *(_QWORD *)(v10 + 216);
  if ( !v20 )
  {
    wlan_objmgr_vdev_release_ref(v10, 2u, v11, v12, v13, v14, v15, v16, v17, v18, v19);
    result = 4;
    goto LABEL_79;
  }
  v21 = (unsigned int *)*(unsigned int *)(v10 + 16);
  if ( ((unsigned int)v21 & 0xFFFFFFFD) != 0
    || (v23 = v10,
        ext_hdl_fl = cm_get_ext_hdl_fl(
                       v10,
                       (__int64)"wlan_cm_roam_cfg_set_value",
                       0x5BBu,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19),
        v10 = v23,
        !ext_hdl_fl) )
  {
    wlan_objmgr_vdev_release_ref(v10, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19);
LABEL_6:
    result = 16;
    goto LABEL_79;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: roam_cfg_type %d, uint val %d int val %d bool val %d num chan %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_cm_roam_cfg_set_value",
    a3,
    *a4,
    a4[1],
    *((unsigned __int8 *)a4 + 8),
    *((unsigned __int8 *)a4 + 16));
  switch ( a3 )
  {
    case 0u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 93) = (_BYTE)v33;
      goto LABEL_77;
    case 1u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 94) = (_BYTE)v33;
      goto LABEL_77;
    case 2u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 96) = (_DWORD)v33;
      goto LABEL_77;
    case 3u:
      *(_WORD *)(ext_hdl_fl + 146) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 10;
      goto LABEL_75;
    case 4u:
      *(_DWORD *)(ext_hdl_fl + 184) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 44;
      goto LABEL_75;
    case 5u:
      *(_BYTE *)(ext_hdl_fl + 188) = *((_BYTE *)a4 + 8);
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 45;
      goto LABEL_75;
    case 6u:
      updated = 0;
      *(_WORD *)(v9 + 1936) = *a4;
      v33 = (unsigned int *)*a4;
      *(_DWORD *)(ext_hdl_fl + 132) = (_DWORD)v33;
      goto LABEL_77;
    case 7u:
      *(_DWORD *)(ext_hdl_fl + 136) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 16;
      goto LABEL_75;
    case 8u:
      *(_DWORD *)(ext_hdl_fl + 104) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 17;
      goto LABEL_75;
    case 9u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      *(_BYTE *)(ext_hdl_fl + 92) = (_BYTE)v33;
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      *(_QWORD *)(ext_hdl_fl + 196) = 0;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 50;
      goto LABEL_75;
    case 0xAu:
      cm_flush_roam_channel_list(ext_hdl_fl + 112);
      v38 = *((_QWORD *)a4 + 3);
      v39 = *((unsigned __int8 *)a4 + 16);
      v40 = v23;
      updated = cm_update_roam_scan_channel_list(a1, v23, a2, ext_hdl_fl + 168, v38, v39, 1);
      if ( updated )
        goto LABEL_78;
      if ( *(_BYTE *)(v9 + 1912) != 1 )
        goto LABEL_84;
      v41 = *(unsigned __int8 *)(ext_hdl_fl + 168);
      v42 = *(const void **)(ext_hdl_fl + 176);
      s[0] = (unsigned __int8)a2;
      LOBYTE(s[1]) = v41;
      qdf_mem_copy(&s[2], v42, (unsigned int)(4 * v41));
      LOBYTE(s[102]) = 2;
      updated = cm_roam_acquire_lock(v23, v43, v44, v45, v46, v47, v48, v49, v50);
      v40 = v23;
      if ( updated )
        goto LABEL_78;
      if ( (unsigned int)mlme_get_roam_state(a1, a2) == 2 )
        goto LABEL_54;
      v59 = "%s: PREF_CHAN received while ROAM RSO not started";
      goto LABEL_86;
    case 0xBu:
      v60 = *((_QWORD *)a4 + 3);
      v61 = *((unsigned __int8 *)a4 + 16);
      v40 = v23;
      updated = cm_update_roam_scan_channel_list(a1, v23, a2, ext_hdl_fl + 112, v60, v61, 0);
      if ( updated )
        goto LABEL_78;
      if ( *(_BYTE *)(v9 + 1912) == 1 )
      {
        v62 = *(unsigned __int8 *)(ext_hdl_fl + 112);
        v63 = *(const void **)(ext_hdl_fl + 120);
        s[0] = (unsigned __int8)a2;
        LOBYTE(s[1]) = v62;
        qdf_mem_copy(&s[2], v63, (unsigned int)(4 * v62));
        LOBYTE(s[102]) = 2;
        updated = cm_roam_acquire_lock(v23, v64, v65, v66, v67, v68, v69, v70, v71);
        v40 = v23;
        if ( !updated )
        {
          if ( (unsigned int)mlme_get_roam_state(a1, a2) == 2 )
          {
LABEL_54:
            v40 = v23;
            cm_fill_rso_channel_list(a1, v23, ext_hdl_fl, (__int64)s, 2);
            v72 = wlan_cm_tgt_send_roam_freqs(a1, a2, s);
            cm_roam_release_lock(v23, v72, v73, v74, v75, v76, v77, v78, v79);
            updated = 0;
          }
          else
          {
            v59 = "%s: SPECIFIC_CHAN received while ROAM RSO not started";
LABEL_86:
            qdf_trace_msg(0x68u, 8u, v59, v51, v52, v53, v54, v55, v56, v57, v58, "wlan_cm_roam_cfg_set_value");
            v40 = v23;
            cm_roam_release_lock(v23, v82, v83, v84, v85, v86, v87, v88, v89);
            updated = 4;
          }
        }
      }
      else
      {
LABEL_84:
        updated = 0;
      }
LABEL_78:
      v81 = updated;
      wlan_objmgr_vdev_release_ref(v40, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
      result = v81;
      break;
    case 0xCu:
      *(_BYTE *)(ext_hdl_fl + 189) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 5;
      goto LABEL_75;
    case 0xDu:
      *(_BYTE *)(ext_hdl_fl + 128) = *a4;
      goto LABEL_66;
    case 0xEu:
LABEL_66:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 129) = (_BYTE)v33;
      goto LABEL_77;
    case 0xFu:
      *(_BYTE *)(ext_hdl_fl + 194) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 13;
      goto LABEL_75;
    case 0x10u:
      *(_WORD *)(ext_hdl_fl + 192) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 14;
      goto LABEL_75;
    case 0x11u:
      *(_WORD *)(ext_hdl_fl + 144) = *a4;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      *(_DWORD *)(v9 + 1944) = *a4;
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 7;
      goto LABEL_75;
    case 0x13u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 677) = (_BYTE)v33;
      goto LABEL_77;
    case 0x14u:
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 826) = *((_BYTE *)a4 + 8);
      v33 = (unsigned int *)*a4;
      *(_WORD *)(ext_hdl_fl + 828) = (_WORD)v33;
      goto LABEL_77;
    case 0x15u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 830) = (_BYTE)v33;
      goto LABEL_77;
    case 0x16u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 831) = (_BYTE)v33;
      goto LABEL_77;
    case 0x17u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 832) = (_BYTE)v33;
      goto LABEL_77;
    case 0x18u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 836) = (_DWORD)v33;
      goto LABEL_77;
    case 0x19u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 833) = (_BYTE)v33;
      goto LABEL_77;
    case 0x1Au:
      v33 = (unsigned int *)a4[1];
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 868) = (_DWORD)v33;
      goto LABEL_77;
    case 0x1Bu:
      *(_DWORD *)(ext_hdl_fl + 944) = *a4;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: [ROAM BAND] Set roam band:%d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_cm_roam_cfg_set_value");
      goto LABEL_76;
    case 0x1Du:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 190) = (_BYTE)v33;
      goto LABEL_77;
    case 0x1Eu:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 224) = (_BYTE)v33;
      goto LABEL_77;
    case 0x1Fu:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 1382) = (_BYTE)v33;
      goto LABEL_77;
    case 0x20u:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      v80 = *(_BYTE *)(ext_hdl_fl + 92);
      *(_BYTE *)(ext_hdl_fl + 1383) = (_BYTE)v33;
      if ( (v80 & 1) != 0 )
        goto LABEL_76;
      v33 = (unsigned int *)*(unsigned __int8 *)(v9 + 1912);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      if ( !cm_is_vdevid_active(v20, a2) )
        goto LABEL_76;
      v33 = (unsigned int *)*(unsigned __int8 *)(ext_hdl_fl + 1383);
      if ( (_DWORD)v33 != 1 )
        goto LABEL_76;
      v35 = a1;
      v36 = a2;
      v37 = 57;
LABEL_75:
      cm_roam_update_cfg(v35, v36, v37);
LABEL_76:
      updated = 0;
LABEL_77:
      v40 = v23;
      goto LABEL_78;
    case 0x21u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(v9 + 3644) = (_DWORD)v33;
      goto LABEL_77;
    case 0x22u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(v9 + 3648) = (_DWORD)v33;
      goto LABEL_77;
    case 0x23u:
      v33 = (unsigned int *)a4[1];
      updated = 0;
      *(_DWORD *)(v9 + 2768) = (_DWORD)v33;
      goto LABEL_77;
    case 0x24u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(v9 + 2772) = (_BYTE)v33;
      goto LABEL_77;
    case 0x25u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 204) = (_DWORD)v33;
      goto LABEL_77;
    case 0x26u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 208) = (_DWORD)v33;
      goto LABEL_77;
    case 0x27u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 212) = (_DWORD)v33;
      goto LABEL_77;
    case 0x28u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 149) = (_BYTE)v33;
      goto LABEL_77;
    case 0x29u:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 216) = (_DWORD)v33;
      goto LABEL_77;
    case 0x2Au:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 220) = (_DWORD)v33;
      goto LABEL_77;
    case 0x2Bu:
      v33 = (unsigned int *)*((unsigned __int8 *)a4 + 8);
      updated = 0;
      *(_BYTE *)(ext_hdl_fl + 1384) = (_BYTE)v33;
      goto LABEL_77;
    case 0x2Cu:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 228) = (_DWORD)v33;
      goto LABEL_77;
    case 0x2Du:
      v33 = (unsigned int *)*a4;
      updated = 0;
      *(_DWORD *)(ext_hdl_fl + 232) = (_DWORD)v33;
      goto LABEL_77;
    default:
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Invalid roam config requested:%d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_cm_roam_cfg_set_value",
        a3);
      updated = 16;
      goto LABEL_77;
  }
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return result;
}
