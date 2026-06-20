__int64 __fastcall populate_dot11f_bcn_mlo_ie(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x25
  __int64 v5; // x26
  __int64 v6; // x28
  __int64 v7; // x9
  __int16 v8; // w8
  __int64 v9; // x9
  char v10; // w10
  char is_hw_emlsr_capable; // w21
  __int16 v12; // w9
  __int16 v13; // w23
  char v14; // w21
  __int16 v15; // w24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  char v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // w8
  char v42; // w9
  char v43; // w11
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  char v52; // w10
  char v53; // w9
  unsigned int v54; // w8
  _WORD *v55; // x19
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w10
  __int64 v65; // x22
  unsigned __int64 v66; // x20
  __int16 v67; // w8
  __int64 v68; // x0
  char is_mlo_vdev; // w8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 session_by_vdev_id; // x0
  unsigned __int64 v79; // x8
  __int64 v80; // x24
  __int64 v81; // x23
  _DWORD *v82; // x10
  _BYTE *v83; // x20
  __int64 v84; // x25
  _BYTE *v85; // x26
  _BOOL4 v86; // w19
  unsigned int v87; // w27
  char v88; // w8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int16 v97; // w8
  __int64 v98; // [xsp+0h] [xbp-60h]
  __int64 v99; // [xsp+8h] [xbp-58h]
  __int64 v100; // [xsp+10h] [xbp-50h]
  __int64 v101; // [xsp+18h] [xbp-48h]
  unsigned __int64 v102; // [xsp+20h] [xbp-40h]
  _DWORD *v103; // [xsp+28h] [xbp-38h]
  __int64 v104; // [xsp+30h] [xbp-30h]
  _BYTE v105[4]; // [xsp+38h] [xbp-28h] BYREF
  __int16 v106; // [xsp+3Ch] [xbp-24h] BYREF
  unsigned int v107; // [xsp+40h] [xbp-20h] BYREF
  unsigned __int16 v108; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v109; // [xsp+48h] [xbp-18h] BYREF
  __int64 v110; // [xsp+50h] [xbp-10h]
  __int64 v111; // [xsp+58h] [xbp-8h]

  result = 29;
  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v108 = 0;
  v106 = 0;
  if ( !a1 )
    goto LABEL_65;
  v4 = a2;
  if ( !a2 )
    goto LABEL_65;
  v5 = a1 + 12288;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v6 = a2 + 10660;
  v105[0] = 0;
  qdf_mem_set((void *)(a1 + 12464), 0x44u, 0);
  v7 = *(_QWORD *)(v4 + 16);
  *(_WORD *)(v4 + 10874) &= 0xFFF8u;
  qdf_mem_copy((void *)(v4 + 10877), (const void *)(*(_QWORD *)(v7 + 1360) + 17LL), 6u);
  v8 = *(_WORD *)(v4 + 10874);
  v9 = *(_QWORD *)(v4 + 16);
  *(_WORD *)(v4 + 10874) = v8 | 0x10;
  v10 = *(_BYTE *)(v4 + 10660);
  LOBYTE(v9) = *(_BYTE *)(v9 + 93);
  *(_WORD *)(v4 + 10874) = v8 | 0x30;
  *(_BYTE *)(v4 + 10884) = v10;
  *(_BYTE *)(v4 + 10883) = v9;
  is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*(_QWORD *)(a1 + 21624));
  wlan_mlme_get_sap_emlsr_mode_enabled(*(_QWORD *)(a1 + 21624), v105);
  if ( (is_hw_emlsr_capable & 1) != 0 && v105[0] == 1 )
  {
    v12 = *(_WORD *)(v4 + 10874);
    *(_BYTE *)(v4 + 10888) = 1;
    *(_WORD *)(v4 + 10874) = v12 | 0x80;
    wlan_mlme_get_eml_params(*(_QWORD *)(a1 + 21624), &v106);
    v13 = 432;
    v14 = 13;
    v15 = 18;
    *(_WORD *)(v4 + 10888) = *(_WORD *)(v4 + 10888) & 0x87FF | v106 & 0x7800;
  }
  else
  {
    v13 = 304;
    v14 = 11;
    v15 = 16;
  }
  *(_WORD *)(v4 + 10874) |= 0x100u;
  lim_get_mlo_vdev_list(v4, &v108, &v109);
  v24 = v108;
  if ( !v108 )
    goto LABEL_28;
  if ( v109
    && v109 != *(_QWORD *)(v4 + 16)
    && *(_DWORD *)(v109 + 16) == 1
    && (wlan_vdev_mlme_is_mlo_vdev(v109, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
  {
    if ( pe_find_session_by_vdev_id(a1, *(_BYTE *)(v109 + 168), v16, v17, v18, v19, v20, v21, v22, v23) )
    {
      if ( !*(_BYTE *)(a1 + 14881) )
        goto LABEL_17;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: link not active if cac running",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "populate_dot11f_bcn_mlo_ie");
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev id %d pe session is not created",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "populate_dot11f_bcn_mlo_ie",
        *(unsigned __int8 *)(v109 + 168));
    }
    --v24;
  }
LABEL_17:
  if ( v108 >= 2u )
  {
    if ( v110
      && v110 != *(_QWORD *)(v4 + 16)
      && *(_DWORD *)(v110 + 16) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(v110, v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
    {
      if ( pe_find_session_by_vdev_id(a1, *(_BYTE *)(v110 + 168), v25, v26, v27, v28, v29, v30, v31, v32) )
      {
        if ( !*(_BYTE *)(a1 + 14881) )
          goto LABEL_27;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: link not active if cac running",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "populate_dot11f_bcn_mlo_ie");
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev id %d pe session is not created",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "populate_dot11f_bcn_mlo_ie",
          *(unsigned __int8 *)(v110 + 168));
      }
      --v24;
    }
LABEL_27:
    if ( v108 > 2u )
    {
LABEL_66:
      __break(0x5512u);
      __break(1u);
    }
  }
LABEL_28:
  v41 = *(_WORD *)(v4 + 10890) & 0xFFF0 | (v24 - 1) & 0xF;
  *(_WORD *)(v4 + 10874) &= 0xF9FFu;
  *(_WORD *)(v4 + 10890) = v41;
  *(_BYTE *)(a1 + 12464) = 0;
  *(_BYTE *)(v4 + 10876) = v14;
  *(_WORD *)(a1 + 12466) = v15;
  v42 = *(_WORD *)(v4 + 10874);
  v43 = *(_WORD *)(v4 + 12967);
  *(_WORD *)(v4 + 12964) = 255;
  *(_BYTE *)(v4 + 12969) = v14;
  *(_BYTE *)(v4 + 12966) = 107;
  *(_WORD *)(v4 + 12967) = v43 & 8 | v13 | v42 & 7;
  qdf_mem_copy((void *)(v4 + 12970), (const void *)(v4 + 10877), 6u);
  v52 = *(_BYTE *)(v4 + 10874);
  v53 = *(_BYTE *)(v4 + 10884);
  *(_BYTE *)(v4 + 12976) = *(_BYTE *)(v4 + 12976) & 0xF0 | *(_BYTE *)(v4 + 10883) & 0xF;
  *(_BYTE *)(v4 + 12977) = v53;
  v54 = *(unsigned __int16 *)(v4 + 10888);
  if ( v52 < 0 )
  {
    v55 = (_WORD *)(v4 + 12980);
    *(_WORD *)(v4 + 12978) = *(_WORD *)(v4 + 12978) & 0x8000 | v54 & 0x7FFF;
  }
  else
  {
    v55 = (_WORD *)(v4 + 12978);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: EMLSR support: %d, padding delay: %d, transition delay: %d",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "populate_dot11f_bcn_mlo_ie",
    v54 & 1,
    (v54 >> 1) & 7,
    (v54 >> 4) & 7);
  v64 = v108;
  *v55 = *v55 & 0xFFF0 | *(_WORD *)(v4 + 10890) & 0xF;
  *(_WORD *)(v4 + 12962) = (_WORD)v55 - (v4 + 12964) + 2;
  if ( v64 )
  {
    v65 = 0;
    v66 = 0;
    v99 = v4 + 10898;
    v100 = a1 + 12288;
    v98 = a1 + 12468;
    v101 = v4;
    v104 = a1;
    while ( 1 )
    {
      if ( v65 == 2 )
        goto LABEL_66;
      v68 = *(&v109 + v65);
      if ( !v68 )
        goto LABEL_37;
      if ( v68 != *(_QWORD *)(v4 + 16) && *(_DWORD *)(v68 + 16) == 1 )
      {
        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v68, v56, v57, v58, v59, v60, v61, v62, v63);
        v68 = *(&v109 + v65);
        if ( (is_mlo_vdev & 1) != 0 )
          break;
      }
LABEL_36:
      lim_mlo_release_vdev_ref(v68);
LABEL_37:
      if ( ++v65 >= (unsigned __int64)v108 )
      {
        v97 = v66;
        goto LABEL_64;
      }
    }
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(_BYTE *)(v68 + 168), v70, v71, v72, v73, v74, v75, v76, v77);
    if ( !session_by_vdev_id )
      goto LABEL_35;
    if ( v66 > 4 )
      goto LABEL_66;
    v79 = *(unsigned __int8 *)(v5 + 176);
    *(_BYTE *)(v5 + 176) = v79 + 1;
    if ( v79 > 2 )
      goto LABEL_66;
    v80 = v99 + 516 * v66;
    v81 = session_by_vdev_id;
    v82 = (_DWORD *)(v98 + 32 * v79);
    *v82 = *(unsigned __int8 *)(*(&v109 + v65) + 168);
    v102 = v66;
    v103 = v82;
    v83 = (_BYTE *)(session_by_vdev_id + 0x2000);
    v82[1] = *(unsigned __int16 *)(session_by_vdev_id + 7158);
    *(_WORD *)(v80 + 2) = 0;
    v84 = v80 + 2;
    v85 = (_BYTE *)(v80 + 6);
    v86 = *(_BYTE *)(session_by_vdev_id + 10229) != 0;
    if ( *(_BYTE *)(session_by_vdev_id + 10229) )
    {
      v107 = 0;
      dot11f_pack_ie_chan_switch_ann(
        a1,
        (_BYTE *)(session_by_vdev_id + 10229),
        (_BYTE *)(v80 + 6),
        0x1FEu,
        (int *)&v107);
      v87 = 510 - v107;
      v85 += v107;
      *((_BYTE *)v103 + 28) = 1;
      if ( !v83[2041] )
      {
LABEL_49:
        if ( v83[2054] )
        {
          v107 = 0;
          dot11f_pack_ie_quiet(v104, (__int64)(v83 + 2054), v85, v87, (int *)&v107);
          v85 += v107;
          if ( !v83[2046] )
          {
LABEL_54:
            v66 = v102;
LABEL_55:
            v88 = (_BYTE)v85 - v84;
            *(_WORD *)v80 = (_WORD)v85 - v84;
            if ( ((unsigned __int64)&v85[-v84] & 0xFFFE) < 0x102 )
            {
              v5 = v100;
              v4 = v101;
              a1 = v104;
              *(_BYTE *)(v80 + 3) = v88 - 2;
            }
            else
            {
              *(_BYTE *)(v80 + 3) = -1;
              v5 = v100;
              v4 = v101;
              a1 = v104;
              if ( (unsigned int)lim_add_frag_ie_for_sta_profile(v80 + 2, v80) )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: STA profile flag error",
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  "populate_dot11f_bcn_mlo_ie");
                *(_WORD *)v80 = 257;
              }
            }
            v67 = *(_WORD *)(v80 + 4);
            ++v66;
            *(_WORD *)(v80 + 4) = v67 & 0xFFF0;
            *(_WORD *)(v80 + 4) = v67 & 0xFFF0 | *(_BYTE *)(*(_QWORD *)(v81 + 16) + 93LL) & 0xF;
            *((_WORD *)v103 + 8) = 4;
            goto LABEL_35;
          }
          v87 -= v107;
LABEL_53:
          v107 = 0;
          dot11f_pack_ie_max_chan_switch_time(v104, v83 + 2046, v85, v87, (int *)&v107);
          v85 += v107;
          goto LABEL_54;
        }
        if ( v83[2046] )
          goto LABEL_53;
        v66 = v102;
        if ( v86 )
          goto LABEL_55;
        v5 = v100;
        v4 = v101;
        a1 = v104;
LABEL_35:
        v68 = *(&v109 + v65);
        goto LABEL_36;
      }
    }
    else
    {
      v87 = 510;
      if ( !*(_BYTE *)(session_by_vdev_id + 10233) )
        goto LABEL_49;
    }
    v107 = 0;
    dot11f_pack_ie_ext_chan_switch_ann(v104, v83 + 2041, v85, v87, (int *)&v107);
    v86 = 1;
    v85 += v107;
    v87 -= v107;
    *((_BYTE *)v103 + 28) = 1;
    goto LABEL_49;
  }
  v97 = 0;
LABEL_64:
  result = 0;
  *(_WORD *)(v6 + 236) = v97;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
