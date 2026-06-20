__int64 __fastcall lim_cm_send_connect_rsp(
        __int64 result,
        __int64 a2,
        unsigned __int64 a3,
        int a4,
        int a5,
        int a6,
        char a7)
{
  __int64 v9; // x22
  __int64 v14; // x19
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  size_t v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int16 v35; // w9
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x11
  __int64 v39; // x8
  int v40; // w9
  unsigned int v41; // w9
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  size_t v50; // x0
  void *v51; // x0
  unsigned int v52; // w27
  __int64 v53; // x26
  size_t v54; // x0
  void *v55; // x0
  size_t v56; // x0
  void *v57; // x0
  char v58; // w8
  size_t v59; // x0
  void *v60; // x0
  size_t v61; // x0
  void *v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 hash_entry; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  int v86; // w8
  __int64 v87; // x27
  unsigned __int64 v88; // x28
  __int64 v89; // x24
  unsigned int v90; // w25
  __int64 v91; // x22
  int v92; // w10
  __int64 v93; // x2
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned __int8 v102; // w0
  __int16 v103; // w0
  __int64 v104; // x22
  char v105; // w9
  __int64 v106; // x4
  __int64 v107; // x5
  const char *v108; // x2
  char v109; // [xsp+8h] [xbp-48h]
  __int64 v110; // [xsp+10h] [xbp-40h] BYREF
  __int64 v111; // [xsp+18h] [xbp-38h]
  __int64 (__fastcall *v112)(__int64); // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v113)(); // [xsp+28h] [xbp-28h]
  __int64 v114; // [xsp+30h] [xbp-20h]
  __int64 v115; // [xsp+38h] [xbp-18h]
  unsigned __int8 v116[4]; // [xsp+40h] [xbp-10h] BYREF
  _BYTE v117[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v118; // [xsp+48h] [xbp-8h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !(a2 | a3) )
    goto LABEL_67;
  v9 = result;
  v114 = 0;
  v115 = 0;
  v112 = nullptr;
  v113 = nullptr;
  v110 = 0;
  v111 = 0;
  result = _qdf_mem_malloc(0x180u, "lim_cm_send_connect_rsp", 613);
  if ( !result )
    goto LABEL_67;
  v14 = result;
  v15 = *(_QWORD *)(v9 + 21624);
  *(_QWORD *)v14 = v15;
  if ( a2 )
  {
    *(_DWORD *)(v14 + 12) = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(v14 + 8) = *(_BYTE *)(a2 + 10);
    qdf_ether_addr_copy((_WORD *)(v14 + 16), (_WORD *)(a2 + 24));
    wlan_cm_connect_resp_fill_mld_addr_from_cm_id(
      *(_QWORD *)(a2 + 16),
      *(_DWORD *)(a2 + 4),
      v14 + 8,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23);
    v24 = *(_DWORD *)(a2 + 284);
    *(_DWORD *)(v14 + 64) = a4;
    *(_DWORD *)(v14 + 68) = a6;
    *(_DWORD *)(v14 + 56) = v24;
    *(_DWORD *)(v14 + 60) = a5;
    if ( *(unsigned __int8 *)(a2 + 36) >= 0x20u )
      v25 = 32;
    else
      v25 = *(unsigned __int8 *)(a2 + 36);
    *(_BYTE *)(v14 + 22) = v25;
    qdf_mem_copy((void *)(v14 + 23), (const void *)(a2 + 37), v25);
    if ( (**(_BYTE **)(a2 + 9976) & 1) != 0 )
      *(_BYTE *)(v14 + 160) = 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: is_fils_connection %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_set_fils_connection");
    if ( *(_QWORD *)(a2 + 320) )
    {
      v50 = *(unsigned int *)(a2 + 312);
      *(_DWORD *)(v14 + 80) = v50;
      v51 = (void *)_qdf_mem_malloc(v50, "lim_cm_prepare_join_rsp_from_pe_session", 415);
      *(_QWORD *)(v14 + 88) = v51;
      if ( !v51 )
        goto LABEL_39;
      qdf_mem_copy(v51, *(const void **)(a2 + 320), *(unsigned int *)(v14 + 80));
    }
    v52 = *(_DWORD *)(v14 + 80);
    v53 = *(_QWORD *)(v14 + 88);
    if ( *(_QWORD *)(a2 + 336) )
    {
      v54 = *(unsigned int *)(a2 + 328);
      *(_DWORD *)(v14 + 112) = v54;
      v55 = (void *)_qdf_mem_malloc(v54, "lim_cm_prepare_join_rsp_from_pe_session", 428);
      *(_QWORD *)(v14 + 120) = v55;
      if ( !v55 )
        goto LABEL_39;
      qdf_mem_copy(v55, *(const void **)(a2 + 336), *(unsigned int *)(v14 + 112));
    }
    if ( *(_QWORD *)(a2 + 352) )
    {
      v56 = *(unsigned int *)(a2 + 344);
      *(_DWORD *)(v14 + 128) = v56;
      v57 = (void *)_qdf_mem_malloc(v56, "lim_cm_prepare_join_rsp_from_pe_session", 439);
      *(_QWORD *)(v14 + 136) = v57;
      if ( !v57 )
        goto LABEL_39;
      qdf_mem_copy(v57, *(const void **)(a2 + 352), *(unsigned int *)(v14 + 128));
    }
    v58 = *(_BYTE *)(v14 + 9) & 0xFE | *(_BYTE *)(a2 + 7023);
    *(_BYTE *)(v14 + 9) = v58;
    *(_BYTE *)(v14 + 9) = v58 & 0xFD | (2 * *(_BYTE *)(a2 + 7364));
    if ( a5 )
      goto LABEL_37;
    *(_DWORD *)(v14 + 68) = 0;
    populate_fils_connect_params(v9, a2, v14 + 8);
    *(_BYTE *)(v14 + 72) = *(_BYTE *)(a2 + 180);
    if ( !*(_QWORD *)(a2 + 400) )
    {
LABEL_23:
      if ( *(_QWORD *)(a2 + 416) )
      {
        v61 = *(unsigned int *)(a2 + 408);
        *(_DWORD *)(v14 + 360) = v61;
        v62 = (void *)_qdf_mem_malloc(v61, "lim_copy_tspec_ie", 342);
        *(_QWORD *)(v14 + 368) = v62;
        if ( v62 )
        {
          qdf_mem_copy(v62, *(const void **)(a2 + 416), *(unsigned int *)(v14 + 360));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ESE-TspecLen: %d",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "lim_copy_tspec_ie",
            *(unsigned int *)(v14 + 360));
        }
      }
      if ( v52 >= 0x25 )
      {
        if ( v53 )
        {
          vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                     &unk_B35EB0,
                                     3u,
                                     (unsigned __int8 *)(v53 + 36),
                                     (unsigned __int16)v52 - 36);
          if ( *(_DWORD *)(v9 + 17236) )
          {
            if ( vendor_ie_ptr_from_oui
              && *(_BYTE *)(a2 + 8635) == 2
              && (*(_BYTE *)(*(_QWORD *)(v9 + 8) + 1072LL) != 1 || wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a2 + 284))) )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: sending SMPS intolrent vdev_param",
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                "lim_send_smps_intolerent");
              wma_cli_set_command(*(unsigned __int8 *)(a2 + 10), 113, 1, 1);
            }
          }
        }
      }
      hash_entry = dph_get_hash_entry(v9, 1u, a2 + 360);
      if ( hash_entry )
        *(_BYTE *)(v14 + 376) = *(_BYTE *)(hash_entry + 659);
      *(_BYTE *)(v14 + 377) = *(_BYTE *)(a2 + 7273);
      mlo_mgr_update_link_status_code(*(_QWORD *)(a2 + 16), *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 93LL), 0);
LABEL_37:
      v109 = 1;
      v81 = *(_QWORD *)(a2 + 320);
      if ( !v81 )
      {
LABEL_41:
        v82 = *(_QWORD *)(a2 + 336);
        if ( v82 )
        {
          _qdf_mem_free(v82);
          *(_QWORD *)(a2 + 336) = 0;
          *(_DWORD *)(a2 + 328) = 0;
        }
        v83 = *(_QWORD *)(a2 + 352);
        if ( v83 )
        {
          _qdf_mem_free(v83);
          *(_QWORD *)(a2 + 352) = 0;
          *(_DWORD *)(a2 + 344) = 0;
        }
        v84 = *(_QWORD *)(a2 + 400);
        if ( v84 )
        {
          _qdf_mem_free(v84);
          *(_QWORD *)(a2 + 400) = 0;
          *(_DWORD *)(a2 + 392) = 0;
        }
        v85 = *(_QWORD *)(a2 + 416);
        if ( v85 )
        {
          _qdf_mem_free(v85);
          *(_QWORD *)(a2 + 416) = 0;
          *(_DWORD *)(a2 + 408) = 0;
        }
        v86 = *(unsigned __int8 *)(a2 + 10696);
        v117[0] = 0;
        *(_BYTE *)(v14 + 168) = v86;
        if ( v86 )
        {
          v87 = 0;
          v88 = 0;
          v89 = a2 + 10710;
          v116[0] = 0;
          do
          {
            if ( v87 == 144 )
              __break(0x5512u);
            v90 = *(unsigned __int8 *)(v89 + v87);
            v91 = v14 + v87;
            *(_BYTE *)(v91 + 182) = v90;
            v92 = *(_DWORD *)(a2 + v87 + 10704);
            *(_WORD *)(v91 + 180) = *(_WORD *)(a2 + v87 + 10708);
            *(_DWORD *)(v91 + 176) = v92;
            v93 = *(unsigned int *)(a2 + v87 + 10748);
            *(_DWORD *)(v91 + 220) = v93;
            mlo_mgr_update_link_status_code(*(_QWORD *)(a2 + 16), *(unsigned __int8 *)(v89 + v87), v93);
            wlan_get_chan_by_bssid_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), a2 + 10704 + v87, v117, v116);
            v102 = v117[0];
            if ( v117[0]
              || (wlan_get_chan_by_link_id_from_rnr(*(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 4), v90, v117, v116),
                  (v102 = v117[0]) != 0) )
            {
              v103 = wlan_reg_chan_opclass_to_freq_auto(v102, v116[0], 0, v94, v95, v96, v97, v98, v99, v100, v101);
              *(_WORD *)(v91 + 186) = v103;
              if ( !v103 )
              {
                v104 = jiffies;
                if ( lim_copy_ml_partner_info___last_ticks - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Invalid op_class %d",
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    "lim_copy_ml_partner_info",
                    v116[0]);
                  lim_copy_ml_partner_info___last_ticks = v104;
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Failed to get channel info for link ID:%d",
                v94,
                v95,
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                "lim_copy_ml_partner_info",
                v90);
            }
            ++v88;
            v87 += 48;
          }
          while ( v88 < *(unsigned __int8 *)(v14 + 168) );
        }
        if ( (v109 & 1) == 0 )
        {
          v106 = *(unsigned __int8 *)(v14 + 8);
          v107 = *(unsigned int *)(v14 + 12);
          v108 = "%s: vdev_id: %d cm_id 0x%x : fail to prepare rsp";
          goto LABEL_66;
        }
        goto LABEL_60;
      }
LABEL_40:
      _qdf_mem_free(v81);
      *(_QWORD *)(a2 + 320) = 0;
      *(_DWORD *)(a2 + 312) = 0;
      goto LABEL_41;
    }
    v59 = *(unsigned int *)(a2 + 392);
    *(_DWORD *)(v14 + 344) = v59;
    v60 = (void *)_qdf_mem_malloc(v59, "lim_cm_prepare_join_rsp_from_pe_session", 458);
    *(_QWORD *)(v14 + 352) = v60;
    if ( v60 )
    {
      qdf_mem_copy(v60, *(const void **)(a2 + 400), *(unsigned int *)(v14 + 344));
      goto LABEL_23;
    }
LABEL_39:
    v109 = 0;
    v81 = *(_QWORD *)(a2 + 320);
    if ( !v81 )
      goto LABEL_41;
    goto LABEL_40;
  }
  *(_DWORD *)(v14 + 12) = *(_DWORD *)(a3 + 4);
  *(_BYTE *)(v14 + 8) = *(_BYTE *)a3;
  v34 = *(_QWORD *)(a3 + 48);
  v35 = *(_WORD *)(v34 + 5);
  LODWORD(v34) = *(_DWORD *)(v34 + 1);
  *(_WORD *)(v14 + 20) = v35;
  *(_DWORD *)(v14 + 16) = v34;
  LODWORD(v34) = *(_DWORD *)(*(_QWORD *)(a3 + 48) + 1192LL);
  *(_DWORD *)(v14 + 60) = 16;
  *(_DWORD *)(v14 + 64) = a4;
  *(_DWORD *)(v14 + 56) = v34;
  v36 = *(_QWORD *)(a3 + 48);
  *(_QWORD *)(v14 + 22) = *(_QWORD *)(v36 + 13);
  LOBYTE(v35) = *(_BYTE *)(v36 + 45);
  v37 = *(_QWORD *)(v36 + 37);
  v38 = *(_QWORD *)(v36 + 21);
  v39 = *(_QWORD *)(v36 + 29);
  *(_BYTE *)(v14 + 54) = v35;
  v40 = *(unsigned __int8 *)(v14 + 9);
  *(_QWORD *)(v14 + 46) = v37;
  *(_QWORD *)(v14 + 38) = v39;
  *(_QWORD *)(v14 + 30) = v38;
  v41 = v40 & 0xFFFFFFFE | (*(unsigned __int8 *)(a3 + 8) >> 1) & 1;
  *(_BYTE *)(v14 + 9) = v41;
  *(_BYTE *)(v14 + 9) = (*(_BYTE *)(a3 + 8) >> 1) & 2 | v41 & 0xFD;
  *(_DWORD *)(v14 + 68) = *(_DWORD *)(a3 + 268);
  wlan_cm_connect_resp_fill_mld_addr_from_vdev_id(v15, *(unsigned __int8 *)a3, *(_QWORD *)(a3 + 48), v14 + 8);
LABEL_60:
  if ( (a7 & 1) != 0 )
    v105 = 4;
  else
    v105 = 0;
  *(_BYTE *)(v14 + 9) = *(_BYTE *)(v14 + 9) & 0xFB | v105;
  qdf_mem_set(&v110, 0x30u, 0);
  v111 = v14;
  v112 = wlan_cm_send_connect_rsp;
  v113 = lim_cm_flush_connect_rsp;
  result = scheduler_post_message_debug(
             0x35u,
             0x48u,
             72,
             (unsigned __int16 *)&v110,
             0x289u,
             (__int64)"lim_cm_send_connect_rsp");
  if ( (_DWORD)result )
  {
    v106 = *(unsigned __int8 *)(v14 + 8);
    v107 = *(unsigned int *)(v14 + 12);
    v108 = "%s: vdev_id: %d cm_id 0x%x : msg post fails";
LABEL_66:
    qdf_trace_msg(0x35u, 2u, v108, v42, v43, v44, v45, v46, v47, v48, v49, "lim_cm_send_connect_rsp", v106, v107);
    result = wlan_cm_free_connect_rsp(v14);
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
