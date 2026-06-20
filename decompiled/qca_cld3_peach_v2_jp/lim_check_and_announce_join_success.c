__int64 __fastcall lim_check_and_announce_join_success(__int64 a1, __int64 a2, __int16 *a3, __int64 a4)
{
  size_t v8; // x2
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int16 v18; // w9
  int v19; // w8
  const char *v20; // x2
  unsigned int v21; // w8
  __int64 v22; // x10
  __int64 v23; // x8
  int v24; // w9
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  char v34; // w8
  __int16 v35; // w2
  __int16 v36; // w8
  char v37; // w9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  __int64 v55; // x11
  __int64 v56; // [xsp+0h] [xbp-50h]
  __int64 v57; // [xsp+8h] [xbp-48h]
  _BYTE v58[4]; // [xsp+10h] [xbp-40h] BYREF
  __int16 v59; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v60; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v61[4]; // [xsp+20h] [xbp-30h] BYREF
  __int16 v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(a4 + 36);
  v62 = 0;
  memset(v61, 0, sizeof(v61));
  v60 = 0;
  v59 = 0;
  v58[0] = 0;
  result = (__int64)qdf_mem_copy((char *)v61 + 1, (const void *)(a4 + 37), v8);
  v18 = *a3;
  v19 = *(unsigned __int8 *)(a4 + 36);
  LOBYTE(v61[0]) = *(_BYTE *)(a4 + 36);
  if ( (v18 & 0xC) == 0 && (v18 & 0xF0) == 0x50 )
  {
    if ( v19 )
    {
      result = qdf_mem_cmp((const void *)(a2 + 12), v61, (unsigned __int8)(v19 + 1));
      if ( (_DWORD)result )
      {
        v20 = "%s: SSID received in Beacon does not match";
        goto LABEL_10;
      }
    }
  }
  if ( *(_DWORD *)(a4 + 88) == 2 )
  {
    if ( (*a3 & 0xF0) == 0x80 && (unsigned __int8)lim_is_null_ssid(a2 + 12) )
    {
      v20 = "%s: for hidden ap, waiting probersp to announce join success";
LABEL_10:
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 v20,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 "lim_check_and_announce_join_success");
      goto LABEL_38;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received Beacon/PR with BSSID:%02x:%02x:%02x:**:**:%02x pe session %d vdev %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_check_and_announce_join_success",
      *(unsigned __int8 *)(a4 + 24),
      *(unsigned __int8 *)(a4 + 25),
      *(unsigned __int8 *)(a4 + 26),
      *(unsigned __int8 *)(a4 + 29),
      *(unsigned __int16 *)(a4 + 8),
      *(unsigned __int8 *)(a4 + 10));
    lim_deactivate_and_change_timer(a1, 2);
    lim_deactivate_and_change_timer(a1, 18);
    if ( *(_DWORD *)(a4 + 7036) == 2 && *(_BYTE *)(a2 + 1328) )
    {
      v21 = *(_DWORD *)(a2 + 1333);
      if ( *(unsigned __int8 *)(a2 + 1331) >= 0x1Au )
        v21 += *(_DWORD *)(a2 + 1346);
      if ( v21 >= 0x2DC6C0 )
        v21 = 3000000;
      *(_DWORD *)(a4 + 7092) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3480LL);
      v22 = 4294968LL * v21;
      v23 = *(_QWORD *)(a1 + 8);
      v24 = *(_DWORD *)(v23 + 3480) + HIDWORD(v22);
      if ( (unsigned int)(v24 - 500) > 0x1194 )
        *(_DWORD *)(v23 + 3480) = 1000;
      else
        *(_DWORD *)(v23 + 3480) = v24;
    }
    else
    {
      *(_DWORD *)(a4 + 7092) = 0;
    }
    wlan_cm_get_check_assoc_disallowed(*(_QWORD *)(a1 + 21552), v58);
    if ( v58[0] == 1 && *(_BYTE *)(a2 + 2594) == 1 )
    {
      LODWORD(v57) = *(unsigned __int16 *)(a4 + 8);
      LODWORD(v56) = *(unsigned __int8 *)(a4 + 29);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Connection fails due to assoc disallowed reason(%d):%02x:%02x:%02x:**:**:%02x PESessionID %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "lim_check_and_announce_join_success",
        *(unsigned __int8 *)(a2 + 2595),
        *(unsigned __int8 *)(a4 + 24),
        *(unsigned __int8 *)(a4 + 25),
        *(unsigned __int8 *)(a4 + 26),
        v56,
        v57);
      v33 = *(_QWORD *)(a4 + 128);
      LODWORD(v60) = 516;
      v34 = *(_BYTE *)(a4 + 8);
      WORD2(v60) = 1;
      *(_DWORD *)(a4 + 72) = 1;
      BYTE6(v60) = v34;
      if ( v33 )
      {
        _qdf_mem_free(v33);
        *(_QWORD *)(a4 + 128) = 0;
      }
      result = lim_process_mlm_rsp_messages(a1, 1005, &v60);
    }
    else
    {
      if ( *(_BYTE *)(a2 + 1200) )
        lim_update_sta_run_time_ht_capability(a1, a2 + 1200);
      if ( *(_BYTE *)(a2 + 1260) )
        lim_update_sta_run_time_ht_info(a1, a2 + 1260, a4);
      v35 = *(_WORD *)(a4 + 8);
      *(_DWORD *)(a4 + 72) = 3;
      qdf_trace(53, 0, v35, 3);
      v36 = *(_WORD *)(a2 + 10);
      v37 = *(_BYTE *)(a4 + 8);
      LODWORD(v60) = 0;
      WORD2(v60) = 0;
      *(_WORD *)(a4 + 176) = v36;
      BYTE6(v60) = v37;
      lim_process_mlm_rsp_messages(a1, 1005, &v60);
      if ( *(_BYTE *)(a4 + 7170) && *(_BYTE *)(a2 + 2544) )
      {
        *(_BYTE *)(a4 + 8626) = 1;
        *(_BYTE *)(a4 + 8627) = *(_BYTE *)(a2 + 2541);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: VHT caps are present in vendor specific IE",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_check_and_announce_join_success");
      }
      if ( *(_BYTE *)(a2 + 2570) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: HS20 Indication Element Present, rel#:%u, id:%u",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_check_and_announce_join_success",
          *(unsigned __int8 *)(a2 + 2571) >> 4,
          (*(unsigned __int8 *)(a2 + 2571) >> 1) & 3);
        qdf_mem_copy((void *)(a4 + 8630), (const void *)(a2 + 2570), 2u);
        if ( (*(_BYTE *)(a2 + 2571) & 6) != 0 )
          qdf_mem_copy((void *)(a4 + 8632), (const void *)(a2 + 2572), 2u);
      }
      result = dph_lookup_hash_entry(
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 a1,
                 (unsigned __int8 *)(a4 + 30),
                 &v59,
                 a4 + 360);
      if ( result && *(_BYTE *)(a2 + 2718) )
      {
        v54 = *(_QWORD *)(a2 + 2718);
        v55 = *(_QWORD *)(a2 + 2726);
        *(_QWORD *)(result + 823) = *(_QWORD *)(a2 + 2731);
        *(_QWORD *)(result + 810) = v54;
        *(_QWORD *)(result + 818) = v55;
        result = lim_update_vdev_sr_elements(a4, result, v46, v47, v48, v49, v50, v51, v52, v53);
      }
    }
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
