__int64 __fastcall dp_mon_stop_local_pkt_capture(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  void (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x8
  unsigned __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 v41; // x9
  void (__fastcall *v42)(_QWORD); // x9
  __int64 v43; // x8
  __int64 v44; // x8
  void (__fastcall *v45)(_QWORD); // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  __int64 v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x9
  char v66; // w8
  unsigned __int64 v67; // x23
  __int64 v68; // x27
  char v69; // w26
  __int64 v70; // x8
  __int64 *v71; // x0
  __int64 *v72; // x8
  __int64 v73; // x8
  __int64 *v74; // x0
  __int64 *v75; // x8
  __int64 v76; // x8

  if ( a2 || (v10 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: pdev Context is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_stop_local_pkt_capture");
    return 4;
  }
  v11 = *(_QWORD *)(v10 + 96456);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Invalid pdev_id %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_get_is_local_pkt_capture_running",
      0);
    goto LABEL_37;
  }
  if ( (*(_BYTE *)(v11 + 39317) & 1) == 0 )
  {
LABEL_37:
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Local pkt capture is not running",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_stop_local_pkt_capture");
    return 0;
  }
  *(_BYTE *)(v11 + 39317) = 0;
  qdf_trace_msg(
    0x73u,
    8u,
    "%s: local_pkt_capture_running is set to %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_mon_set_local_pkt_capture_running",
    0);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 40);
  }
  else
  {
    raw_spin_lock_bh(v11 + 40);
    *(_QWORD *)(v11 + 48) |= 1uLL;
  }
  v21 = *(_QWORD *)(v10 + 96456);
  v22 = v21 + 36864;
  v23 = **(_QWORD **)(v21 + 37064);
  *(_BYTE *)(v23 + 92) = 1;
  *(_QWORD *)(v23 + 93) = 0;
  *(_QWORD *)(v23 + 101) = 0;
  *(_QWORD *)(v23 + 109) = 0;
  *(_QWORD *)(v23 + 117) = 0;
  *(_QWORD *)(v23 + 125) = 0;
  *(_QWORD *)(v23 + 133) = 0;
  *(_QWORD *)(v23 + 141) = 0;
  *(_QWORD *)(v23 + 149) = 0;
  *(_QWORD *)(v23 + 157) = 0;
  *(_QWORD *)(v23 + 165) = 0;
  *(_QWORD *)(v23 + 173) = 0;
  *(_DWORD *)(v23 + 180) = 0;
  if ( v21 )
  {
    *(_BYTE *)(v21 + 37072) = 3;
    v24 = v21 + 37076;
    *(_WORD *)(v22 + 210) = -289;
    *(_QWORD *)v24 = -1;
    *(_WORD *)(v24 + 8) = -1;
  }
  v25 = *(_QWORD *)(v10 + 8);
  if ( v25 )
  {
    v26 = *(_QWORD *)(v25 + 20112);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 416);
      if ( v27 )
      {
        v28 = *(void (__fastcall **)(_QWORD))(v27 + 648);
        if ( v28 )
        {
          if ( *((_DWORD *)v28 - 1) != -1116635294 )
            __break(0x8228u);
          v28(v10);
        }
        v29 = *(_QWORD *)(v11 + 48);
        if ( (v29 & 1) != 0 )
        {
          *(_QWORD *)(v11 + 48) = v29 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v11 + 40);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
            goto LABEL_22;
        }
        else
        {
          raw_spin_unlock(v11 + 40);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
            goto LABEL_22;
        }
        v30 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v30 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v30 + 16) & 0xFF00) == 0 )
        {
          raw_spin_lock_bh(v11 + 40);
          *(_QWORD *)(v11 + 48) |= 1uLL;
          v39 = *(_QWORD *)(v10 + 8);
          if ( !v39 )
            goto LABEL_48;
LABEL_23:
          v40 = *(_QWORD *)(v39 + 20112);
          if ( !v40 )
            goto LABEL_75;
          v41 = *(_QWORD *)(v40 + 416);
          if ( !v41 )
            goto LABEL_75;
          v42 = *(void (__fastcall **)(_QWORD))(v41 + 592);
          if ( !v42 )
            goto LABEL_75;
          if ( *((_DWORD *)v42 - 1) != -1557217772 )
            __break(0x8229u);
          v42(v10);
          v39 = *(_QWORD *)(v10 + 8);
          if ( v39 )
          {
LABEL_75:
            v43 = *(_QWORD *)(v39 + 20112);
            if ( v43 )
            {
              v44 = *(_QWORD *)(v43 + 416);
              if ( v44 )
              {
                v45 = *(void (__fastcall **)(_QWORD))(v44 + 656);
                if ( v45 )
                {
                  if ( *((_DWORD *)v45 - 1) != -1116635294 )
                    __break(0x8228u);
                  v45(v10);
                }
                goto LABEL_49;
              }
            }
          }
LABEL_48:
          qdf_trace_msg(
            0x73u,
            2u,
            "%s: Tx mon filter update failed ops uninitialized",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "dp_tx_mon_filter_update");
LABEL_49:
          v56 = *(_QWORD *)(v11 + 48);
          if ( (v56 & 1) != 0 )
          {
            *(_QWORD *)(v11 + 48) = v56 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v11 + 40);
          }
          else
          {
            raw_spin_unlock(v11 + 40);
          }
          qdf_trace_msg(
            0x73u,
            8u,
            "%s: local pkt capture stopped",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "dp_mon_stop_local_pkt_capture");
          v65 = 0;
          v66 = 1;
          v67 = _ReadStatusReg(SP_EL0);
          do
          {
            v68 = *(_QWORD *)(v10 + 96456) + 18528 * v65;
            v69 = v66;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v67 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v67 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v68 + 18496);
            }
            else
            {
              raw_spin_lock_bh(v68 + 18496);
              *(_QWORD *)(v68 + 18504) |= 1uLL;
            }
            while ( 1 )
            {
              v71 = *(__int64 **)(v68 + 18440);
              if ( !v71 )
                break;
              v72 = *(__int64 **)(v68 + 18448);
              --*(_DWORD *)(v68 + 18456);
              if ( v71 == v72 )
              {
                v70 = 0;
                *(_QWORD *)(v68 + 18448) = 0;
              }
              else
              {
                v70 = *v71;
              }
              *(_QWORD *)(v68 + 18440) = v70;
              *v71 = 0;
              _qdf_nbuf_free((__int64)v71);
            }
            while ( 1 )
            {
              v74 = *(__int64 **)(v68 + 18464);
              if ( !v74 )
                break;
              v75 = *(__int64 **)(v68 + 18472);
              --*(_DWORD *)(v68 + 18480);
              if ( v74 == v75 )
              {
                v73 = 0;
                *(_QWORD *)(v68 + 18472) = 0;
              }
              else
              {
                v73 = *v74;
              }
              *(_QWORD *)(v68 + 18464) = v73;
              *v74 = 0;
              _qdf_nbuf_free((__int64)v74);
            }
            v76 = *(_QWORD *)(v68 + 18504);
            if ( (v76 & 1) != 0 )
            {
              *(_QWORD *)(v68 + 18504) = v76 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v68 + 18496);
            }
            else
            {
              raw_spin_unlock(v68 + 18496);
            }
            v66 = 0;
            v65 = 1;
          }
          while ( (v69 & 1) != 0 );
          return 0;
        }
LABEL_22:
        raw_spin_lock(v11 + 40);
        v39 = *(_QWORD *)(v10 + 8);
        if ( !v39 )
          goto LABEL_48;
        goto LABEL_23;
      }
    }
  }
  qdf_trace_msg(
    0x73u,
    2u,
    "%s: Rx mon filter update failed ops uninitialized",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "dp_mon_filter_update");
  qdf_trace_msg(
    0x73u,
    2u,
    "%s: local pkt capture set rx filter failed",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "dp_mon_stop_local_pkt_capture");
  v55 = *(_QWORD *)(v11 + 48);
  if ( (v55 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 48) = v55 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 40);
  }
  else
  {
    raw_spin_unlock(v11 + 40);
  }
  return 16;
}
