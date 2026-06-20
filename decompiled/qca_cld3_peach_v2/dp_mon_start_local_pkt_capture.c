__int64 __fastcall dp_mon_start_local_pkt_capture(
        __int64 a1,
        char a2,
        __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v13; // x21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 (__fastcall *v28)(_QWORD); // x9
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x8
  __int64 v33; // x10
  __int16 v34; // w9
  __int64 v35; // x24
  char v36; // w11
  __int64 v37; // x8
  __int64 v38; // x12
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x10
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x10
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x10
  __int64 v53; // x10
  __int64 v54; // x10
  __int64 v55; // x10
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x8
  void (__fastcall *v59)(_QWORD); // x8
  __int64 v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x20
  unsigned __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x19
  unsigned __int64 v73; // x8
  __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x8
  __int64 v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  const char *v93; // x2
  __int64 v94; // x8
  _QWORD v95[3]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v96; // [xsp+20h] [xbp-50h]
  __int64 v97; // [xsp+28h] [xbp-48h]
  __int64 v98; // [xsp+30h] [xbp-40h]
  __int64 v99; // [xsp+38h] [xbp-38h]
  __int64 v100; // [xsp+40h] [xbp-30h]
  __int64 v101; // [xsp+48h] [xbp-28h]
  __int128 v102; // [xsp+50h] [xbp-20h]
  int v103; // [xsp+60h] [xbp-10h]
  __int64 v104; // [xsp+68h] [xbp-8h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 || (v11 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: pdev Context is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_mon_start_local_pkt_capture");
    result = 4;
    goto LABEL_65;
  }
  v13 = *(_QWORD *)(v11 + 96456);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Invalid pdev_id %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_mon_get_is_local_pkt_capture_running",
      0);
    goto LABEL_8;
  }
  if ( *(_BYTE *)(v13 + 39317) != 1 )
  {
LABEL_8:
    *(_BYTE *)(v13 + 37072) = *(_BYTE *)a3;
    *(_WORD *)(v13 + 37074) = a3[1];
    *(_WORD *)(v13 + 37076) = a3[2];
    *(_WORD *)(v13 + 37078) = a3[3];
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v16 = raw_spin_lock(v13 + 40);
      v25 = *(_QWORD *)(v11 + 8);
      if ( !v25 )
        goto LABEL_61;
    }
    else
    {
      v16 = raw_spin_lock_bh(v13 + 40);
      *(_QWORD *)(v13 + 48) |= 1uLL;
      v25 = *(_QWORD *)(v11 + 8);
      if ( !v25 )
        goto LABEL_61;
    }
    v26 = *(_QWORD *)(v25 + 20112);
    if ( !v26 )
      goto LABEL_77;
    v27 = *(_QWORD *)(v26 + 416);
    if ( !v27 )
      goto LABEL_77;
    v28 = *(__int64 (__fastcall **)(_QWORD))(v27 + 584);
    if ( !v28 )
      goto LABEL_77;
    if ( *((_DWORD *)v28 - 1) != -1557217772 )
      __break(0x8229u);
    v16 = v28(v11);
    v25 = *(_QWORD *)(v11 + 8);
    if ( v25 )
    {
LABEL_77:
      v29 = *(_QWORD *)(v25 + 20112);
      if ( v29 )
      {
        v30 = *(_QWORD *)(v29 + 416);
        if ( v30 )
        {
          v31 = *(__int64 (__fastcall **)(_QWORD))(v30 + 656);
          if ( v31 )
          {
            if ( *((_DWORD *)v31 - 1) != -1116635294 )
              __break(0x8228u);
            v16 = v31(v11);
          }
          v32 = *(_QWORD *)(v11 + 96456);
          v33 = 0xFFFF0000FFFFLL;
          v34 = *a3;
          memset(v95, 0, sizeof(v95));
          v35 = v32 + 36864;
          v36 = *(_BYTE *)(v32 + 37072);
          LOBYTE(v95[0]) = 1;
          v102 = 0u;
          v103 = 0;
          if ( (v36 & 2) != 0 )
            v37 = -1;
          else
            v37 = 0xFFFF0000FFFFLL;
          v100 = 0;
          v101 = 0;
          *(_QWORD *)((char *)&v95[1] + 4) = v37;
          v38 = -4294877279LL;
          v98 = 0;
          v99 = 0;
          if ( (v36 & 2) == 0 )
            v38 = 0xFFFF00005FA1LL;
          v39 = v38 | ~(v34 << 12) & 0x2000;
          v96 = 0;
          v97 = 0;
          *(_DWORD *)((char *)&v102 + 6) = 1536;
          if ( (v34 & 1) != 0 )
          {
            v40 = 0xFFFF0000FFFF0000LL;
            if ( (v36 & 2) == 0 )
              v40 = 0;
            v39 = v38 & 0xFFFF000000017FA1LL | ~(v34 << 12) & 0x2000 | ((unsigned __int64)(unsigned __int16)a3[1] << 32);
            *(_QWORD *)((char *)&v95[1] + 4) = v40
                                             | (unsigned __int16)a3[2]
                                             | ((unsigned __int64)(unsigned __int16)a3[3] << 32);
            v33 = *(_QWORD *)((char *)&v95[1] + 4) & 0xFFFF0000FFFFLL;
          }
          if ( (v34 & 2) != 0 )
          {
            v39 = v39 & 0xFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int16)a3[4] << 48) | 0x10000;
            *(_QWORD *)((char *)&v95[1] + 4) = v33
                                             | ((unsigned __int64)(unsigned __int16)a3[5] << 16)
                                             | ((unsigned __int64)(unsigned __int16)a3[6] << 48);
          }
          *(_QWORD *)((char *)v95 + 4) = v39 & 0xFFFFFFFFFFFF7FFFLL;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dp_mon_filter_show_filter)(v16, 0, v95);
          v49 = v102;
          v50 = **(_QWORD **)(v35 + 200);
          *(_QWORD *)(v50 + 156) = v101;
          v51 = *((_QWORD *)&v102 + 1);
          *(_QWORD *)(v50 + 164) = v49;
          LODWORD(v49) = v103;
          *(_QWORD *)(v50 + 172) = v51;
          *(_DWORD *)(v50 + 180) = v49;
          v52 = v98;
          *(_QWORD *)(v50 + 124) = v97;
          *(_QWORD *)(v50 + 132) = v52;
          v53 = v100;
          *(_QWORD *)(v50 + 140) = v99;
          *(_QWORD *)(v50 + 148) = v53;
          v54 = v95[1];
          *(_QWORD *)(v50 + 92) = v95[0];
          *(_QWORD *)(v50 + 100) = v54;
          v55 = v96;
          *(_QWORD *)(v50 + 108) = v95[2];
          *(_QWORD *)(v50 + 116) = v55;
          v56 = *(_QWORD *)(v11 + 8);
          if ( v56 )
          {
            v57 = *(_QWORD *)(v56 + 20112);
            if ( v57 )
            {
              v58 = *(_QWORD *)(v57 + 416);
              if ( v58 )
              {
                v59 = *(void (__fastcall **)(_QWORD))(v58 + 648);
                if ( v59 )
                {
                  if ( *((_DWORD *)v59 - 1) != -1116635294 )
                    __break(0x8228u);
                  v59(v11);
                }
                v60 = *(_QWORD *)(v13 + 48);
                if ( (v60 & 1) != 0 )
                {
                  *(_QWORD *)(v13 + 48) = v60 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v13 + 40);
                }
                else
                {
                  raw_spin_unlock(v13 + 40);
                }
                qdf_trace_msg(
                  0x73u,
                  8u,
                  "%s: local pkt capture tx filter set",
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  "dp_mon_start_local_pkt_capture");
                v69 = *(_QWORD *)(v11 + 96456);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (v70 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v70 + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(v70 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v69 + 18496);
                }
                else
                {
                  raw_spin_lock_bh(v69 + 18496);
                  *(_QWORD *)(v69 + 18504) |= 1uLL;
                }
                v71 = *(_QWORD *)(v69 + 18504);
                *(_QWORD *)(v69 + 18456) = 0;
                *(_QWORD *)(v69 + 18448) = 0;
                *(_QWORD *)(v69 + 18440) = 0;
                *(_QWORD *)(v69 + 18464) = 0;
                *(_QWORD *)(v69 + 18472) = 0;
                *(_QWORD *)(v69 + 18480) = 0;
                *(_BYTE *)(v69 + 18488) = 1;
                if ( (v71 & 1) != 0 )
                {
                  *(_QWORD *)(v69 + 18504) = v71 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v69 + 18496);
                }
                else
                {
                  raw_spin_unlock(v69 + 18496);
                }
                v72 = *(_QWORD *)(v11 + 96456);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (v73 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v73 + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(v73 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v72 + 37024);
                }
                else
                {
                  raw_spin_lock_bh(v72 + 37024);
                  *(_QWORD *)(v72 + 37032) |= 1uLL;
                }
                *(_QWORD *)(v72 + 36976) = 0;
                *(_QWORD *)(v72 + 36984) = 0;
                *(_QWORD *)(v72 + 36968) = 0;
                v74 = *(_QWORD *)(v72 + 37032);
                *(_QWORD *)(v72 + 36992) = 0;
                *(_QWORD *)(v72 + 37000) = 0;
                *(_QWORD *)(v72 + 37008) = 0;
                *(_BYTE *)(v72 + 37016) = 1;
                if ( (v74 & 1) != 0 )
                {
                  *(_QWORD *)(v72 + 37032) = v74 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v72 + 37024);
                  if ( v13 )
                    goto LABEL_56;
                }
                else
                {
                  raw_spin_unlock(v72 + 37024);
                  if ( v13 )
                  {
LABEL_56:
                    *(_BYTE *)(v13 + 39317) = 1;
                    qdf_trace_msg(
                      0x73u,
                      8u,
                      "%s: local_pkt_capture_running is set to %d",
                      v75,
                      v76,
                      v77,
                      v78,
                      v79,
                      v80,
                      v81,
                      v82,
                      "dp_mon_set_local_pkt_capture_running",
                      1);
LABEL_72:
                    result = 0;
                    goto LABEL_65;
                  }
                }
                qdf_trace_msg(
                  0x73u,
                  2u,
                  "%s: Invalid monitor pdev",
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  "dp_mon_set_local_pkt_capture_running");
                goto LABEL_72;
              }
            }
          }
          qdf_trace_msg(
            0x73u,
            2u,
            "%s: Rx mon filter update failed ops uninitialized",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "dp_mon_filter_update");
          v83 = **(_QWORD **)(*(_QWORD *)(v11 + 96456) + 37064LL);
          *(_DWORD *)(v83 + 180) = 0;
          *(_QWORD *)(v83 + 172) = 0;
          *(_QWORD *)(v83 + 164) = 0;
          *(_QWORD *)(v83 + 156) = 0;
          *(_QWORD *)(v83 + 148) = 0;
          *(_QWORD *)(v83 + 140) = 0;
          *(_QWORD *)(v83 + 132) = 0;
          *(_QWORD *)(v83 + 124) = 0;
          *(_QWORD *)(v83 + 116) = 0;
          *(_QWORD *)(v83 + 108) = 0;
          *(_QWORD *)(v83 + 100) = 0;
          *(_QWORD *)(v83 + 92) = 0;
          v84 = *(_QWORD *)(v13 + 48);
          if ( (v84 & 1) != 0 )
          {
            *(_QWORD *)(v13 + 48) = v84 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v13 + 40);
          }
          else
          {
            raw_spin_unlock(v13 + 40);
          }
          v93 = "%s: local pkt capture set rx filter failed";
LABEL_64:
          qdf_trace_msg(0x73u, 2u, v93, v85, v86, v87, v88, v89, v90, v91, v92, "dp_mon_start_local_pkt_capture");
          result = 16;
          goto LABEL_65;
        }
      }
    }
LABEL_61:
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Tx mon filter update failed ops uninitialized",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_tx_mon_filter_update");
    v94 = *(_QWORD *)(v13 + 48);
    if ( (v94 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 48) = v94 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 40);
    }
    else
    {
      raw_spin_unlock(v13 + 40);
    }
    v93 = "%s: local pkt capture set tx filter failed";
    goto LABEL_64;
  }
  qdf_trace_msg(
    0x73u,
    2u,
    "%s: Can't start local pkt capture. Already running",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_mon_start_local_pkt_capture");
  result = 6;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
