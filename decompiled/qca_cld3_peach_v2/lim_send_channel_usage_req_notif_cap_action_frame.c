__int64 __fastcall lim_send_channel_usage_req_notif_cap_action_frame(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _BYTE *v20; // x26
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x23
  unsigned int v24; // w9
  unsigned int v25; // w22
  int v26; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char v35; // w24
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _BYTE *v44; // x21
  unsigned int packed_channel_usage_reqSize; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w22
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned __int8 *v63; // x23
  char *v64; // x24
  const void *v65; // x24
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x6
  __int64 v76; // x7
  int v77; // w8
  int v78; // w9
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  _QWORD *v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // [xsp+8h] [xbp-218h]
  int v97; // [xsp+10h] [xbp-210h]
  int v98; // [xsp+4Ch] [xbp-1D4h] BYREF
  int v99[2]; // [xsp+50h] [xbp-1D0h] BYREF
  __int64 v100; // [xsp+58h] [xbp-1C8h] BYREF
  __int16 v101; // [xsp+60h] [xbp-1C0h] BYREF
  char v102; // [xsp+62h] [xbp-1BEh]
  __int16 v103; // [xsp+64h] [xbp-1BCh] BYREF
  char v104; // [xsp+66h] [xbp-1BAh]
  __int16 v105; // [xsp+67h] [xbp-1B9h]
  char v106; // [xsp+69h] [xbp-1B7h]
  char opclass_from_freq_width; // [xsp+6Ah] [xbp-1B6h]
  char v108; // [xsp+6Bh] [xbp-1B5h]
  _BYTE v109[428]; // [xsp+6Ch] [xbp-1B4h] BYREF
  __int64 v110; // [xsp+218h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(
              53,
              (__int64)"lim_send_channel_usage_req_notif_cap_action_frame",
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
  v100 = 0;
  result = (__int64)memset(v109, 0, sizeof(v109));
  if ( context )
  {
    v102 = 0;
    v101 = 0;
    *(_QWORD *)v99 = 0;
    v98 = 0;
    result = pe_find_session_by_vdev_id(context, a1);
    if ( result )
    {
      if ( *(_DWORD *)(result + 7036) == 2 )
      {
        v20 = (_BYTE *)(result + 8676);
        if ( *(_BYTE *)(result + 9795) == 1 )
        {
          v21 = *(_QWORD *)(*(_QWORD *)(result + 16) + 216LL);
          if ( v21 )
          {
            v22 = *(_QWORD *)(v21 + 80);
            if ( v22 )
            {
              v103 = 5386;
              v23 = result;
              v24 = *(unsigned __int8 *)(result + 13286);
              if ( v24 <= 1 )
                LOBYTE(v24) = 1;
              *(_BYTE *)(result + 13286) = v24 + 1;
              v104 = v24;
              v105 = 1281;
              wlan_reg_read_current_country(v22, &v101, v12, v13, v14, v15, v16, v17, v18, v19);
              v25 = *(_DWORD *)(v23 + 284);
              v26 = *(_DWORD *)(v23 + 7176);
              v35 = wlan_reg_freq_to_chan(
                      *(_QWORD *)(*(_QWORD *)(v23 + 16) + 216LL),
                      v25,
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      v34);
              opclass_from_freq_width = wlan_reg_get_opclass_from_freq_width(
                                          (unsigned __int8 *)&v101,
                                          v25,
                                          v26,
                                          1u,
                                          v36,
                                          v37,
                                          v38,
                                          v39,
                                          v40,
                                          v41,
                                          v42,
                                          v43);
              v106 = 2;
              v108 = v35;
              populate_dot11_supp_operating_classes(context, &v109[252], v23);
              v44 = (_BYTE *)v23;
              populate_dot11f_ht_caps(context, v23, &v109[304]);
              if ( wlan_reg_is_5ghz_ch_freq(v25)
                || wlan_reg_is_24ghz_ch_freq(v25) && *(_BYTE *)(context[1] + 2875LL) == 1 )
              {
                populate_dot11f_vht_caps(context, v23, &v109[288]);
              }
              if ( *v20 == 1 )
              {
                populate_dot11f_he_caps(
                  (int)context,
                  0,
                  *(_DWORD *)(v23 + 7036),
                  *(_DWORD *)(v23 + 284),
                  *(_DWORD *)(v23 + 7176),
                  (int)&v109[364]);
                if ( wlan_reg_is_6ghz_chan_freq(v25) )
                  populate_dot11f_he_6ghz_cap(context, v23, &v109[424]);
              }
              packed_channel_usage_reqSize = dot11f_get_packed_channel_usage_reqSize(context, &v103, &v98);
              if ( (packed_channel_usage_reqSize & 0x10000000) != 0 )
              {
                result = qdf_trace_msg(
                           0x35u,
                           8u,
                           "%s: Failed to calculate the packed size(0x%08x).",
                           v46,
                           v47,
                           v48,
                           v49,
                           v50,
                           v51,
                           v52,
                           v53,
                           "lim_send_channel_usage_req_notif_cap_action_frame",
                           packed_channel_usage_reqSize);
              }
              else
              {
                if ( packed_channel_usage_reqSize )
                  qdf_trace_msg(
                    0x35u,
                    3u,
                    "%s: Warnings in calculating the packed size(0x%08x).",
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    "lim_send_channel_usage_req_notif_cap_action_frame");
                v54 = v98 + 24;
                if ( (unsigned int)cds_packet_alloc((unsigned __int16)v98 + 24, v99, &v100) || !v100 )
                {
                  result = qdf_trace_msg(
                             0x35u,
                             2u,
                             "%s: Failed to allocate %d bytes",
                             v55,
                             v56,
                             v57,
                             v58,
                             v59,
                             v60,
                             v61,
                             v62,
                             "lim_send_channel_usage_req_notif_cap_action_frame",
                             v54);
                }
                else
                {
                  qdf_mem_set(*(void **)v99, v54, 0);
                  v63 = *(unsigned __int8 **)v99;
                  v64 = *(char **)v99;
                  *(_BYTE *)(*(_QWORD *)v99 + 16LL) = v44[24];
                  v65 = v64 + 16;
                  v63[17] = v44[25];
                  v63[18] = v44[26];
                  v63[19] = v44[27];
                  v63[20] = v44[28];
                  v63[21] = v44[29];
                  lim_populate_mac_header((__int64)context, *(__int64 *)v99, 0, 13, v65, v44 + 30);
                  lim_set_protected_bit(context, v44, v65, v63);
                  v66 = dot11f_pack_channel_usage_req(context, &v103, *(_QWORD *)v99 + 24LL, v54, &v98);
                  if ( (v66 & 0x10000000) != 0 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Failed to pack frame(0x%08x).",
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      "lim_send_channel_usage_req_notif_cap_action_frame",
                      v66);
                    result = cds_packet_free(v100);
                  }
                  else
                  {
                    if ( v66 )
                      qdf_trace_msg(
                        0x35u,
                        3u,
                        "%s: Warnings in packing frame0x%08x).",
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        v72,
                        v73,
                        v74,
                        "lim_send_channel_usage_req_notif_cap_action_frame");
                    if ( v65 )
                    {
                      v75 = v63[16];
                      v76 = v63[17];
                      v77 = v63[18];
                      v78 = v63[21];
                    }
                    else
                    {
                      v77 = 0;
                      v75 = 0;
                      v76 = 0;
                      v78 = 0;
                    }
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: vdev %d seq num %d to %02x:%02x:%02x:**:**:%02x len %d",
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      "lim_send_channel_usage_req_notif_cap_action_frame",
                      (unsigned __int8)a1,
                      *((unsigned __int16 *)context + 10802),
                      v75,
                      v76,
                      v77,
                      v78,
                      v54);
                    v87 = _cds_get_context(
                            54,
                            (__int64)"lim_send_channel_usage_req_notif_cap_action_frame",
                            v79,
                            v80,
                            v81,
                            v82,
                            v83,
                            v84,
                            v85,
                            v86);
                    LOBYTE(v97) = v44[10];
                    LOBYTE(v96) = 64;
                    result = wma_tx_packet(
                               v87,
                               v100,
                               v54,
                               3,
                               1,
                               7,
                               lim_tx_complete,
                               *(_QWORD *)v99,
                               0,
                               v96,
                               v97,
                               0,
                               0,
                               12,
                               0,
                               0);
                    if ( (_DWORD)result )
                    {
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Failed to send chan usage req frame(0x%x)!",
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        v95,
                        "lim_send_channel_usage_req_notif_cap_action_frame",
                        (unsigned int)result);
                      result = cds_packet_free(v100);
                    }
                    v20[1119] = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
