__int64 __fastcall lim_cm_send_connect_rsp(__int64 result, __int64 a2, __int64 a3, int a4, int a5, int a6, char a7)
{
  __int64 v9; // x22
  __int64 v14; // x19
  __int64 v15; // x24
  int v16; // w8
  size_t v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int16 v27; // w9
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x8
  int v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  size_t v41; // x0
  void *v42; // x0
  unsigned int v43; // w27
  __int64 v44; // x26
  size_t v45; // x0
  void *v46; // x0
  size_t v47; // x0
  void *v48; // x0
  char v49; // w8
  size_t v50; // x0
  void *v51; // x0
  size_t v52; // x0
  void *v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 hash_entry; // x0
  int v72; // w22
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  char v78; // w8
  char v79; // w9
  __int64 v80; // x4
  __int64 v81; // x5
  const char *v82; // x2
  __int64 v83; // [xsp+8h] [xbp-38h] BYREF
  __int64 v84; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v85)(__int64); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v86)(); // [xsp+20h] [xbp-20h]
  __int64 v87; // [xsp+28h] [xbp-18h]
  __int64 v88; // [xsp+30h] [xbp-10h]
  __int64 v89; // [xsp+38h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !(a2 | a3) )
    goto LABEL_58;
  v9 = result;
  v87 = 0;
  v88 = 0;
  v85 = nullptr;
  v86 = nullptr;
  v83 = 0;
  v84 = 0;
  result = _qdf_mem_malloc(0xD0u, "lim_cm_send_connect_rsp", 613);
  if ( !result )
    goto LABEL_58;
  v14 = result;
  *(_QWORD *)result = *(_QWORD *)(v9 + 21552);
  v15 = result + 8;
  if ( a2 )
  {
    *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(result + 8) = *(_BYTE *)(a2 + 10);
    qdf_ether_addr_copy((_WORD *)(result + 16), (_WORD *)(a2 + 24));
    wlan_cm_connect_resp_fill_mld_addr_from_cm_id();
    v16 = *(_DWORD *)(a2 + 284);
    *(_DWORD *)(v14 + 64) = a4;
    *(_DWORD *)(v14 + 68) = a6;
    *(_DWORD *)(v14 + 56) = v16;
    *(_DWORD *)(v14 + 60) = a5;
    if ( *(unsigned __int8 *)(a2 + 36) >= 0x20u )
      v17 = 32;
    else
      v17 = *(unsigned __int8 *)(a2 + 36);
    *(_BYTE *)(v14 + 22) = v17;
    qdf_mem_copy((void *)(v14 + 23), (const void *)(a2 + 37), v17);
    if ( (**(_BYTE **)(a2 + 9976) & 1) != 0 )
      *(_BYTE *)(v14 + 160) = 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: is_fils_connection %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "lim_set_fils_connection");
    if ( *(_QWORD *)(a2 + 320) )
    {
      v41 = *(unsigned int *)(a2 + 312);
      *(_DWORD *)(v14 + 80) = v41;
      v42 = (void *)_qdf_mem_malloc(v41, "lim_cm_prepare_join_rsp_from_pe_session", 415);
      *(_QWORD *)(v14 + 88) = v42;
      if ( !v42 )
        goto LABEL_39;
      qdf_mem_copy(v42, *(const void **)(a2 + 320), *(unsigned int *)(v14 + 80));
    }
    v43 = *(_DWORD *)(v14 + 80);
    v44 = *(_QWORD *)(v14 + 88);
    if ( *(_QWORD *)(a2 + 336) )
    {
      v45 = *(unsigned int *)(a2 + 328);
      *(_DWORD *)(v14 + 112) = v45;
      v46 = (void *)_qdf_mem_malloc(v45, "lim_cm_prepare_join_rsp_from_pe_session", 428);
      *(_QWORD *)(v14 + 120) = v46;
      if ( !v46 )
        goto LABEL_39;
      qdf_mem_copy(v46, *(const void **)(a2 + 336), *(unsigned int *)(v14 + 112));
    }
    if ( *(_QWORD *)(a2 + 352) )
    {
      v47 = *(unsigned int *)(a2 + 344);
      *(_DWORD *)(v14 + 128) = v47;
      v48 = (void *)_qdf_mem_malloc(v47, "lim_cm_prepare_join_rsp_from_pe_session", 439);
      *(_QWORD *)(v14 + 136) = v48;
      if ( !v48 )
        goto LABEL_39;
      qdf_mem_copy(v48, *(const void **)(a2 + 352), *(unsigned int *)(v14 + 128));
    }
    v49 = *(_BYTE *)(v14 + 9) & 0xFE | *(_BYTE *)(a2 + 7023);
    *(_BYTE *)(v14 + 9) = v49;
    *(_BYTE *)(v14 + 9) = v49 & 0xFD | (2 * *(_BYTE *)(a2 + 7364));
    if ( a5 )
      goto LABEL_37;
    *(_DWORD *)(v14 + 68) = 0;
    populate_fils_connect_params(v9, a2, v15);
    *(_BYTE *)(v14 + 72) = *(_BYTE *)(a2 + 180);
    if ( !*(_QWORD *)(a2 + 400) )
    {
LABEL_23:
      if ( *(_QWORD *)(a2 + 416) )
      {
        v52 = *(unsigned int *)(a2 + 408);
        *(_DWORD *)(v14 + 184) = v52;
        v53 = (void *)_qdf_mem_malloc(v52, "lim_copy_tspec_ie", 342);
        *(_QWORD *)(v14 + 192) = v53;
        if ( v53 )
        {
          qdf_mem_copy(v53, *(const void **)(a2 + 416), *(unsigned int *)(v14 + 184));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ESE-TspecLen: %d",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "lim_copy_tspec_ie",
            *(unsigned int *)(v14 + 184));
        }
      }
      if ( v43 >= 0x25 )
      {
        if ( v44 )
        {
          vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                     &unk_A30390,
                                     3u,
                                     (unsigned __int8 *)(v44 + 36),
                                     (unsigned __int16)v43 - 36);
          if ( *(_DWORD *)(v9 + 17164) )
          {
            if ( vendor_ie_ptr_from_oui
              && *(_BYTE *)(a2 + 8635) == 2
              && (*(_BYTE *)(*(_QWORD *)(v9 + 8) + 1072LL) != 1 || wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a2 + 284))) )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: sending SMPS intolrent vdev_param",
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                "lim_send_smps_intolerent");
              wma_cli_set_command(*(unsigned __int8 *)(a2 + 10), 113, 1, 1);
            }
          }
        }
      }
      hash_entry = dph_get_hash_entry(v9, 1u, a2 + 360);
      if ( hash_entry )
        *(_BYTE *)(v14 + 200) = *(_BYTE *)(hash_entry + 643);
      *(_BYTE *)(v14 + 201) = *(_BYTE *)(a2 + 7273);
LABEL_37:
      v72 = 1;
      v73 = *(_QWORD *)(a2 + 320);
      if ( !v73 )
        goto LABEL_41;
      goto LABEL_40;
    }
    v50 = *(unsigned int *)(a2 + 392);
    *(_DWORD *)(v14 + 168) = v50;
    v51 = (void *)_qdf_mem_malloc(v50, "lim_cm_prepare_join_rsp_from_pe_session", 458);
    *(_QWORD *)(v14 + 176) = v51;
    if ( v51 )
    {
      qdf_mem_copy(v51, *(const void **)(a2 + 400), *(unsigned int *)(v14 + 168));
      goto LABEL_23;
    }
LABEL_39:
    v72 = 0;
    v73 = *(_QWORD *)(a2 + 320);
    if ( !v73 )
    {
LABEL_41:
      v74 = *(_QWORD *)(a2 + 336);
      if ( v74 )
      {
        _qdf_mem_free(v74);
        *(_QWORD *)(a2 + 336) = 0;
        *(_DWORD *)(a2 + 328) = 0;
      }
      v75 = *(_QWORD *)(a2 + 352);
      if ( v75 )
      {
        _qdf_mem_free(v75);
        *(_QWORD *)(a2 + 352) = 0;
        *(_DWORD *)(a2 + 344) = 0;
      }
      v76 = *(_QWORD *)(a2 + 400);
      if ( v76 )
      {
        _qdf_mem_free(v76);
        *(_QWORD *)(a2 + 400) = 0;
        *(_DWORD *)(a2 + 392) = 0;
      }
      v77 = *(_QWORD *)(a2 + 416);
      if ( v77 )
      {
        _qdf_mem_free(v77);
        *(_QWORD *)(a2 + 416) = 0;
        *(_DWORD *)(a2 + 408) = 0;
      }
      if ( !v72 )
      {
        v80 = *(unsigned __int8 *)(v14 + 8);
        v81 = *(unsigned int *)(v14 + 12);
        v82 = "%s: vdev_id: %d cm_id 0x%x : fail to prepare rsp";
        goto LABEL_57;
      }
      LOBYTE(v32) = *(_BYTE *)(v14 + 9);
      goto LABEL_51;
    }
LABEL_40:
    _qdf_mem_free(v73);
    *(_QWORD *)(a2 + 320) = 0;
    *(_DWORD *)(a2 + 312) = 0;
    goto LABEL_41;
  }
  *(_DWORD *)(result + 12) = *(_DWORD *)(a3 + 4);
  *(_BYTE *)(result + 8) = *(_BYTE *)a3;
  v26 = *(_QWORD *)(a3 + 48);
  v27 = *(_WORD *)(v26 + 5);
  LODWORD(v26) = *(_DWORD *)(v26 + 1);
  *(_WORD *)(result + 20) = v27;
  *(_DWORD *)(result + 16) = v26;
  LODWORD(v26) = *(_DWORD *)(*(_QWORD *)(a3 + 48) + 1064LL);
  *(_DWORD *)(result + 60) = 16;
  *(_DWORD *)(result + 64) = a4;
  *(_DWORD *)(result + 56) = v26;
  v28 = *(_QWORD *)(a3 + 48);
  *(_QWORD *)(result + 22) = *(_QWORD *)(v28 + 13);
  LOBYTE(v27) = *(_BYTE *)(v28 + 45);
  v29 = *(_QWORD *)(v28 + 37);
  v30 = *(_QWORD *)(v28 + 21);
  v31 = *(_QWORD *)(v28 + 29);
  *(_BYTE *)(result + 54) = v27;
  *(_QWORD *)(result + 46) = v29;
  *(_QWORD *)(result + 38) = v31;
  LODWORD(v31) = *(unsigned __int8 *)(result + 9);
  *(_QWORD *)(result + 30) = v30;
  LODWORD(v31) = v31 & 0xFFFFFFFE | (*(unsigned __int8 *)(a3 + 8) >> 1) & 1;
  *(_BYTE *)(result + 9) = v31;
  v32 = v31 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a3 + 8) >> 2) & 1));
  *(_BYTE *)(result + 9) = v32;
  *(_DWORD *)(result + 68) = *(_DWORD *)(a3 + 92);
LABEL_51:
  v78 = v32 & 0xFB;
  if ( (a7 & 1) != 0 )
    v79 = 4;
  else
    v79 = 0;
  *(_BYTE *)(v14 + 9) = v78 | v79;
  qdf_mem_set(&v83, 0x30u, 0);
  v84 = v14;
  v85 = wlan_cm_send_connect_rsp;
  v86 = lim_cm_flush_connect_rsp;
  result = scheduler_post_message_debug(
             0x35u,
             0x48u,
             72,
             (unsigned __int16 *)&v83,
             0x289u,
             (__int64)"lim_cm_send_connect_rsp");
  if ( (_DWORD)result )
  {
    v80 = *(unsigned __int8 *)(v14 + 8);
    v81 = *(unsigned int *)(v14 + 12);
    v82 = "%s: vdev_id: %d cm_id 0x%x : msg post fails";
LABEL_57:
    qdf_trace_msg(0x35u, 2u, v82, v33, v34, v35, v36, v37, v38, v39, v40, "lim_cm_send_connect_rsp", v80, v81);
    result = wlan_cm_free_connect_rsp(v14);
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
