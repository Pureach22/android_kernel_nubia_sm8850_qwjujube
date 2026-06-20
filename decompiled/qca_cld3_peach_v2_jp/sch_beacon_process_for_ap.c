__int64 __fastcall sch_beacon_process_for_ap(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int v26; // w8
  __int64 v27; // x8
  int v28; // w9
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  __int64 v38; // x22
  unsigned int v39; // w8
  unsigned int v40; // w23
  unsigned __int64 v41; // x9
  unsigned __int64 *v42; // x11
  __int64 i; // x12
  char v44; // w9
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const void *v61; // x1
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // [xsp+8h] [xbp-28h] BYREF
  __int64 v103; // [xsp+10h] [xbp-20h]
  __int64 v104; // [xsp+18h] [xbp-18h]
  int v105; // [xsp+20h] [xbp-10h]
  __int64 v106; // [xsp+28h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v105 = 0;
  v103 = 0;
  v104 = 0;
  v102 = 0;
  if ( !a3 || !a4 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: bcn %pK or rx_pkt_info %pKis NULL",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "sch_beacon_process_for_ap",
               a4,
               a3);
    goto LABEL_22;
  }
  result = pe_find_session_by_session_id(a1, a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v16 = result;
    if ( *(_DWORD *)(result + 88) == 1 )
    {
      result = (__int64)qdf_mem_set(&v102, 0x1Cu, 0);
      HIWORD(v103) = 0;
      LOBYTE(v102) = *(_BYTE *)(v16 + 10);
      if ( (*(_BYTE *)(v16 + 10020) & 1) == 0 )
      {
        if ( *(_BYTE *)(v16 + 8740) )
        {
          v25 = *(unsigned __int8 *)(v16 + 8745);
          if ( (v25 & 0x3F) == 0 )
          {
            if ( *(_BYTE *)(a4 + 2700) )
            {
              if ( (*(_BYTE *)(a4 + 2705) & 0x3F) != 0 )
              {
                v37 = v16 + 16LL * ((*(_BYTE *)(a4 + 2705) & 0x3Fu) - 1);
                ++*(_QWORD *)(v37 + 8776);
                *(_QWORD *)(v37 + 8768) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
              }
              else
              {
                v39 = v25 | 0x80;
                *(_BYTE *)(v16 + 8745) = v39;
                v40 = 0;
                HIWORD(v103) = 2048;
                v41 = *(_QWORD *)(v16 + 8776);
                *(_BYTE *)(v16 + 8766) = 10;
                v42 = (unsigned __int64 *)(v16 + 8792);
                for ( i = 1; i != 63; ++i )
                {
                  if ( !*v42 )
                  {
                    LOBYTE(v40) = i + 1;
                    goto LABEL_47;
                  }
                  if ( v41 > *v42
                    && 1000 * ((jiffies / 0xFAuLL) & 0xFFFFFFFFFFFFFFFLL) + 4 * (jiffies % 0xFAuLL) - *(v42 - 1) >= 0x7531 )
                  {
                    v40 = (unsigned __int8)i + 1;
                    v41 = *v42;
                  }
                  v42 += 2;
                }
                result = qdf_trace_msg(
                           0x35u,
                           8u,
                           "%s: new bss color: %d",
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           "ap_get_new_bss_color",
                           v40);
                v39 = *(unsigned __int8 *)(v16 + 8745);
LABEL_47:
                v44 = *(_BYTE *)(v16 + 8767) & 0xC0 | v40 & 0x3F;
                *(_BYTE *)(v16 + 8745) = v39 & 0xC0 | v40 & 0x3F;
                *(_BYTE *)(v16 + 8767) = v44;
                HIDWORD(v104) = v40 & 0x3F;
                LOBYTE(v105) = v39 >> 7;
                *(_BYTE *)(v16 + 9776) = 1;
              }
            }
          }
        }
      }
      if ( !*(_BYTE *)(v16 + 428) || (*(_BYTE *)(v16 + 10006) & 1) != 0 )
        goto LABEL_71;
      v26 = *(_DWORD *)(v16 + 168);
      if ( v26 )
      {
        if ( v26 != 1 || !*(_BYTE *)(v16 + 155) || *(_DWORD *)(a4 + 72) != *(_DWORD *)(v16 + 284) )
          goto LABEL_71;
        v27 = *(_QWORD *)(a3 + 16);
        if ( !*(_BYTE *)(a4 + 1260) || (v28 = (*(_DWORD *)(a4 + 1262) >> 8) & 3, v28 == 3) )
        {
LABEL_18:
          result = lim_update_overlap_sta_param(a1, (const void *)(v27 + 16), (char *)(v16 + 1228));
          if ( *(_BYTE *)(v16 + 1228) && !*(_BYTE *)(v16 + 1229) )
            result = lim_update_11a_protection(a1, 1, 1, (__int64)&v102, v16, v29, v30, v31, v32, v33, v34, v35, v36);
          goto LABEL_71;
        }
        if ( v28 != 2 )
        {
          if ( v28 == 1 )
            goto LABEL_18;
LABEL_71:
          if ( !*(_BYTE *)(a1 + 14809) && HIWORD(v103) )
          {
            ((void (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v16);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Beacon for PE session[%d] got changed",
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              "sch_beacon_process_for_ap",
              *(unsigned __int16 *)(v16 + 8));
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: sending beacon param change bitmap: 0x%x",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "sch_beacon_process_for_ap",
              HIWORD(v103));
            result = lim_send_beacon_params(a1, (unsigned __int16 *)&v102, v16);
          }
          goto LABEL_22;
        }
        v61 = (const void *)(v27 + 16);
LABEL_64:
        result = lim_update_overlap_sta_param(a1, v61, (char *)(v16 + 1230));
        if ( *(_BYTE *)(v16 + 1230) && !*(_BYTE *)(v16 + 1231) )
          result = lim_enable_ht20_protection(a1, 1, 1, (__int64)&v102, v16, v62, v63, v64, v65, v66, v67, v68, v69);
        goto LABEL_71;
      }
      v38 = *(_QWORD *)(a3 + 16);
      if ( *(_DWORD *)(v16 + 7232) == 2 )
      {
        if ( !*(_BYTE *)(v16 + 155) )
        {
          if ( *(_DWORD *)(a4 + 72) != *(_DWORD *)(v16 + 284) )
            goto LABEL_71;
          if ( *(_BYTE *)(a4 + 2475) )
          {
            if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 3332LL) & 1) != 0 || (*(_BYTE *)(a4 + 1132) & 3) == 0 )
              goto LABEL_71;
          }
          else if ( *(_BYTE *)(a4 + 1260) )
          {
            goto LABEL_71;
          }
          if ( (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v16 + 10)) & 1) != 0 )
            qdf_trace_msg(
              0x35u,
              4u,
              "%s: [INFOLOG]ESE 11g erpPresent=%d useProtection=%d nonErpPresent=%d",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "ap_beacon_process_24_ghz",
              *(unsigned __int8 *)(a4 + 2475),
              (*(unsigned __int8 *)(a4 + 1132) >> 1) & 1,
              *(_BYTE *)(a4 + 1132) & 1);
          result = lim_enable_overlap11g_protection(a1, (__int64)&v102, v38, v16);
          goto LABEL_71;
        }
      }
      else if ( !*(_BYTE *)(v16 + 155) )
      {
        goto LABEL_71;
      }
      if ( *(_DWORD *)(a4 + 72) != *(_DWORD *)(v16 + 284) )
        goto LABEL_71;
      if ( *(_BYTE *)(a4 + 2475) )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 3332LL) & 1) != 0 || (*(_BYTE *)(a4 + 1132) & 3) == 0 )
        {
LABEL_52:
          if ( (*(_BYTE *)(a4 + 1132) & 3) == 0 && !*(_BYTE *)(a4 + 1260) )
          {
            result = lim_update_overlap_sta_param(a1, (const void *)(v38 + 16), (char *)(v16 + 1226));
            if ( *(_BYTE *)(v16 + 1226) )
            {
              if ( !*(_BYTE *)(v16 + 1227) )
                result = lim_enable_ht_protection_from11g(
                           a1,
                           1,
                           1,
                           (__int64)&v102,
                           v16,
                           v94,
                           v95,
                           v96,
                           v97,
                           v98,
                           v99,
                           v100,
                           v101);
            }
          }
          goto LABEL_54;
        }
      }
      else if ( *(_BYTE *)(a4 + 1260) )
      {
LABEL_54:
        if ( !*(_BYTE *)(a4 + 1260) )
          goto LABEL_71;
        if ( (*(_DWORD *)(a4 + 1262) & 0x300) != 0x200 )
        {
          if ( (*(_DWORD *)(a4 + 1262) & 0x300) == 0x100
            && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 3188LL) & 1) == 0
            && (*(_DWORD *)(a1 + 12232) | 2) != 3 )
          {
            result = lim_update_overlap_sta_param(a1, (const void *)(v38 + 16), (char *)(v16 + 1226));
            if ( *(_BYTE *)(v16 + 1226) )
            {
              if ( !*(_BYTE *)(v16 + 1227) )
                result = lim_enable_ht_protection_from11g(
                           a1,
                           1,
                           1,
                           (__int64)&v102,
                           v16,
                           v53,
                           v54,
                           v55,
                           v56,
                           v57,
                           v58,
                           v59,
                           v60);
            }
          }
          goto LABEL_71;
        }
        v61 = (const void *)(v38 + 16);
        goto LABEL_64;
      }
      if ( (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v16 + 10)) & 1) != 0 )
        qdf_trace_msg(
          0x35u,
          4u,
          "%s: [INFOLOG]ESE 11g erpPresent=%d useProtection=%d nonErpPresent=%d",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "ap_beacon_process_24_ghz",
          *(unsigned __int8 *)(a4 + 2475),
          (*(unsigned __int8 *)(a4 + 1132) >> 1) & 1,
          *(_BYTE *)(a4 + 1132) & 1);
      result = lim_enable_overlap11g_protection(a1, (__int64)&v102, v38, v16);
      if ( !*(_BYTE *)(a4 + 2475) )
        goto LABEL_54;
      goto LABEL_52;
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
