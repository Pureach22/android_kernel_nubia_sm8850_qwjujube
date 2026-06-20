__int64 __fastcall wma_state_info_dump(
        _QWORD *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w26
  int v32; // w19
  unsigned int v33; // w22
  __int64 v34; // x20
  __int64 cmpt_obj; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w25
  __int64 v45; // x10
  int v46; // w19
  int v47; // w23
  int v48; // w28
  int v49; // w24
  __int64 v50; // kr00_8
  char is_vdev_up; // w0
  double v52; // d0
  int v53; // w0
  unsigned int *v54; // x8
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _QWORD *v62; // [xsp+B8h] [xbp-F8h]
  __int64 v63; // [xsp+C0h] [xbp-F0h]
  int v64; // [xsp+CCh] [xbp-E4h]
  int v65; // [xsp+D0h] [xbp-E0h]
  int v66; // [xsp+D4h] [xbp-DCh]
  __int64 v67; // [xsp+D8h] [xbp-D8h]
  __int64 v68; // [xsp+E8h] [xbp-C8h]
  int v69; // [xsp+F4h] [xbp-BCh]
  int v70; // [xsp+F8h] [xbp-B8h]
  int v71; // [xsp+FCh] [xbp-B4h]
  int v72; // [xsp+100h] [xbp-B0h]
  int v73; // [xsp+104h] [xbp-ACh]
  int v74; // [xsp+108h] [xbp-A8h]
  __int64 v75; // [xsp+10Ch] [xbp-A4h]
  __int64 v76; // [xsp+114h] [xbp-9Ch]
  int v77; // [xsp+11Ch] [xbp-94h]
  int v78; // [xsp+120h] [xbp-90h]
  __int64 v79; // [xsp+128h] [xbp-88h]
  __int64 v80; // [xsp+130h] [xbp-80h] BYREF
  __int64 v81; // [xsp+138h] [xbp-78h]
  __int64 v82; // [xsp+140h] [xbp-70h]
  __int64 v83; // [xsp+148h] [xbp-68h]
  __int64 v84; // [xsp+150h] [xbp-60h]
  __int64 v85; // [xsp+158h] [xbp-58h]
  __int64 v86; // [xsp+160h] [xbp-50h]
  __int64 v87; // [xsp+168h] [xbp-48h]
  __int64 v88; // [xsp+170h] [xbp-40h]
  __int64 v89; // [xsp+178h] [xbp-38h]
  __int64 v90; // [xsp+180h] [xbp-30h]
  __int64 v91; // [xsp+188h] [xbp-28h]
  __int64 v92; // [xsp+190h] [xbp-20h]
  __int64 v93; // [xsp+198h] [xbp-18h]
  __int64 v94; // [xsp+1A0h] [xbp-10h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v63 = v12;
  v80 = 0;
  v81 = 0;
  result = (__int64)_cds_get_context(54, (__int64)"wma_state_info_dump", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v22 = result;
    v62 = a1;
    result = qdf_trace_msg(
               0x36u,
               8u,
               "%s: size of buffer: %d",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "wma_state_info_dump",
               *a2);
    if ( *(_WORD *)(v22 + 162) )
    {
      v31 = 0;
      v32 = 0;
      v33 = 0;
      do
      {
        v34 = *(_QWORD *)(v22 + 520) + 488LL * (unsigned __int8)v33;
        result = *(_QWORD *)v34;
        if ( *(_QWORD *)v34 )
        {
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(result, v23, v24, v25, v26, v27, v28, v29, v30);
          if ( cmpt_obj )
          {
            v44 = *(_DWORD *)(cmpt_obj + 288);
            result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       *(_QWORD *)(v22 + 24),
                       v33,
                       8);
            if ( result )
            {
              v79 = result;
              ucfg_mc_cp_stats_get_vdev_wake_lock_stats(result, &v80);
              v45 = (unsigned __int16)v32;
              v78 = v32;
              v46 = HIDWORD(v88);
              v47 = *(unsigned __int8 *)(v34 + 178);
              v77 = v87;
              v48 = *(_DWORD *)(v34 + 180);
              v49 = *(unsigned __int8 *)(v34 + 184);
              v67 = v45;
              v68 = *a2 - v45;
              v76 = v86;
              v73 = HIDWORD(v80);
              v74 = v80;
              v75 = v85;
              v72 = HIDWORD(v84);
              v69 = HIDWORD(v81);
              v50 = v82;
              v70 = v84;
              v71 = v81;
              v65 = HIDWORD(v87);
              v66 = v83;
              v64 = v88;
              is_vdev_up = wma_is_vdev_up(v33);
              v52 = scnprintf(
                      v63 + v67,
                      v68,
                      "\n"
                      "vdev_id %d\n"
                      "WoW Stats\n"
                      "\tpno_match %u\n"
                      "\tpno_complete %u\n"
                      "\tgscan %u\n"
                      "\tlow_rssi %u\n"
                      "\trssi_breach %u\n"
                      "\tucast %u\n"
                      "\tbcast %u\n"
                      "\ticmpv4 %u\n"
                      "\ticmpv6 %u\n"
                      "\tipv4_mcast %u\n"
                      "\tipv6_mcast %u\n"
                      "\tipv6_mcast_ra %u\n"
                      "\tipv6_mcast_ns %u\n"
                      "\tipv6_mcast_na %u\n"
                      "\toem_response %u\n"
                      "\tuc_drop %u\n"
                      "\tfatal_event %u\n"
                      "dtimPeriod %d\n"
                      "chan_width %d\n"
                      "vdev_active %d\n"
                      "vdev_up %d\n"
                      "aid %d\n"
                      "rate_flags %d\n"
                      "nss %d\n"
                      "nwType %d\n"
                      "tx_streams %d",
                      v31,
                      v77,
                      HIDWORD(v76),
                      v76,
                      HIDWORD(v75),
                      v75,
                      v74,
                      v73,
                      v70,
                      v72,
                      v71,
                      v69,
                      v50,
                      HIDWORD(v50),
                      v66,
                      v65,
                      v64,
                      v46,
                      v47,
                      v48,
                      v49,
                      is_vdev_up & 1,
                      *(unsigned __int16 *)(v34 + 208),
                      v44,
                      *(unsigned __int8 *)(v34 + 236),
                      *(_DWORD *)(v34 + 240),
                      *(_DWORD *)(v34 + 264));
              v32 = v78 + v53;
              result = wlan_objmgr_vdev_release_ref(v79, 8u, v54, v52, v55, v56, v57, v58, v59, v60, v61);
            }
          }
          else
          {
            result = qdf_trace_msg(
                       0x36u,
                       2u,
                       "%s: ailed to get mlme_obj",
                       v36,
                       v37,
                       v38,
                       v39,
                       v40,
                       v41,
                       v42,
                       v43,
                       "wma_get_vdev_rate_flag");
          }
        }
        v31 = (unsigned __int8)++v33;
      }
      while ( *(unsigned __int16 *)(v22 + 162) > (unsigned int)(unsigned __int8)v33 );
    }
    else
    {
      LOWORD(v32) = 0;
    }
    *a2 -= v32;
    *v62 += (unsigned __int16)v32;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
