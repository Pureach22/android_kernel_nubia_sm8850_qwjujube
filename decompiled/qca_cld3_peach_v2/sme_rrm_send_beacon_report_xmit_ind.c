__int64 __fastcall sme_rrm_send_beacon_report_xmit_ind(
        __int64 a1,
        unsigned __int8 a2,
        __int64 *a3,
        char a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v14; // w27
  __int64 v15; // x26
  int v16; // w24
  unsigned int v17; // w20
  __int64 v18; // x0
  __int64 v19; // x27
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  __int64 v29; // x25
  int v30; // w19
  const void *v31; // x26
  unsigned int v32; // t1
  unsigned int v33; // w28
  void *v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  const char *v48; // x2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x4
  char v58; // w8
  __int64 v60; // [xsp+0h] [xbp-80h]
  __int64 v61; // [xsp+8h] [xbp-78h]
  __int64 v63; // [xsp+20h] [xbp-60h]
  __int64 v66; // [xsp+38h] [xbp-48h]
  __int64 v67; // [xsp+40h] [xbp-40h]
  __int64 v68; // [xsp+48h] [xbp-38h]
  __int64 v69; // [xsp+50h] [xbp-30h]
  __int64 v70; // [xsp+58h] [xbp-28h]
  __int64 v71; // [xsp+60h] [xbp-20h]
  __int64 v72; // [xsp+68h] [xbp-18h]
  __int64 v73; // [xsp+70h] [xbp-10h]
  __int64 v74; // [xsp+78h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 6u )
  {
    v72 = 0;
    v73 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    if ( !a3 && !a4 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Beacon report xmit Ind to PE Failed",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "sme_rrm_send_beacon_report_xmit_ind");
      v14 = 16;
      goto LABEL_44;
    }
    v63 = a1 + 544LL * a2 + 17488;
    if ( a3 )
      v15 = *a3;
    else
      v15 = 0;
    v16 = 0;
    v17 = a5;
    while ( 1 )
    {
      v18 = _qdf_mem_malloc(0x58u, "sme_rrm_send_beacon_report_xmit_ind", 193);
      if ( !v18 )
        goto LABEL_43;
      v19 = v18;
      *(_DWORD *)v18 = 5772334;
      *(_BYTE *)(v18 + 4) = a2;
      *(_WORD *)(v18 + 12) = *(_WORD *)v63;
      *(_WORD *)(v18 + 16) = *(_WORD *)(v63 + 114);
      *(_BYTE *)(v18 + 18) = *(_BYTE *)(v63 + 8);
      qdf_mem_copy((void *)(v18 + 5), (const void *)(v63 + 2), 6u);
      if ( !v15 )
        break;
      v28 = 0;
      v29 = v19 + 24;
      v30 = (unsigned __int8)v16 + 1;
      while ( 1 )
      {
        v32 = *(unsigned __int16 *)(v15 + 56);
        v31 = (const void *)(v15 + 56);
        v33 = v32 + 2;
        v34 = (void *)_qdf_mem_malloc(v32 + 2LL, "sme_rrm_send_beacon_report_xmit_ind", 212);
        *(_QWORD *)(v29 + 8 * v28) = v34;
        if ( !v34 )
          break;
        qdf_mem_copy(v34, v31, v33);
        v43 = *(_QWORD *)(v29 + 8 * v28);
        *(&v66 + v28) = v43;
        if ( v43 == -2 )
        {
          v46 = 0;
          v44 = 0;
          v45 = 0;
          v47 = 0;
        }
        else
        {
          v44 = *(unsigned __int8 *)(v43 + 2);
          v45 = *(unsigned __int8 *)(v43 + 3);
          v46 = *(unsigned __int8 *)(v43 + 4);
          v47 = *(unsigned __int8 *)(v43 + 7);
        }
        LODWORD(v60) = *(_DWORD *)(v43 + 28);
        LODWORD(v61) = -*(char *)(v43 + 24);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: RRM Result Bssid = %02x:%02x:%02x:**:**:%02x freq= %d, rssi = -%d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "sme_rrm_send_beacon_report_xmit_ind",
          v44,
          v45,
          v46,
          v47,
          v60,
          v61);
        ++*(_BYTE *)(v19 + 19);
        if ( v28 == 7 )
        {
          LODWORD(v28) = 8;
          break;
        }
        if ( v30 + (int)v28 >= v17 )
        {
          LODWORD(v28) = v28 + 1;
          break;
        }
        v15 = a3[(unsigned int)(v30 + v28++)];
        if ( !v15 )
          goto LABEL_22;
      }
      v15 = 0;
      v16 += v28;
      if ( !a3 || (unsigned __int8)v16 >= (unsigned int)a5 )
        goto LABEL_23;
      v48 = "%s: Move to the next BSS set in cur_result list";
      v15 = a3[(unsigned __int8)v16];
LABEL_29:
      qdf_trace_msg(0x34u, 8u, v48, v20, v21, v22, v23, v24, v25, v26, v27, "sme_rrm_send_beacon_report_xmit_ind");
      v57 = *(unsigned __int8 *)(v19 + 19);
      if ( v15 )
        v58 = 0;
      else
        v58 = a4;
      *(_BYTE *)(v19 + 14) = v58;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: SME Sending BcnRepXmit to PE numBss %d i %d j %d",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "sme_rrm_send_beacon_report_xmit_ind",
        v57,
        (unsigned __int8)v28,
        (unsigned __int8)v16);
      v14 = umac_send_mb_message_to_mac(v19);
      if ( v14 )
      {
        if ( (_BYTE)v28 )
        {
          _qdf_mem_free(v66);
          if ( (unsigned __int8)v28 != 1 )
          {
            _qdf_mem_free(v67);
            if ( (unsigned __int8)v28 != 2 )
            {
              _qdf_mem_free(v68);
              if ( (unsigned __int8)v28 != 3 )
              {
                _qdf_mem_free(v69);
                if ( (unsigned __int8)v28 != 4 )
                {
                  _qdf_mem_free(v70);
                  if ( (unsigned __int8)v28 != 5 )
                  {
                    _qdf_mem_free(v71);
                    if ( (unsigned __int8)v28 != 6 )
                    {
                      _qdf_mem_free(v72);
                      if ( (unsigned __int8)v28 != 7 )
                      {
                        _qdf_mem_free(v73);
                        if ( (unsigned __int8)v28 != 8 )
                          goto LABEL_42;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( !v15 )
        goto LABEL_44;
    }
    LODWORD(v28) = 0;
LABEL_22:
    v15 = 0;
    v16 += v28;
LABEL_23:
    v48 = "%s: Reached to  max/last BSS in cur_result list";
    goto LABEL_29;
  }
LABEL_42:
  __break(0x5512u);
LABEL_43:
  v14 = 2;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v14;
}
