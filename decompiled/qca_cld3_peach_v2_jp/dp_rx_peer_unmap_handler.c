__int64 __fastcall dp_rx_peer_unmap_handler(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned __int8 a5)
{
  __int64 v8; // x24
  __int64 v10; // x27
  int v11; // w26
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x19
  unsigned int v14; // w8
  unsigned int v21; // w10
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x8
  char v33; // w9
  _BYTE *v34; // x8
  _QWORD *v35; // x24
  char v36; // w8
  unsigned __int64 v37; // x8
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w10
  int v48; // w11
  int v49; // w12
  int v50; // w13
  unsigned __int64 v51; // x8
  unsigned __int16 *v52; // x8
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x23
  _DWORD *v63; // x8
  _DWORD *v64; // x8
  __int64 v65; // x0
  _DWORD *v66; // x8
  __int64 v67; // x3
  unsigned __int64 v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w20
  __int64 v78; // x8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x0
  unsigned int v104; // w1
  unsigned __int16 *v105; // x9
  unsigned int v107; // w9
  __int64 v108; // x8
  __int64 v109; // [xsp+0h] [xbp-60h]
  __int64 v110; // [xsp+8h] [xbp-58h]
  _QWORD v111[2]; // [xsp+40h] [xbp-20h] BYREF
  __int64 v112; // [xsp+50h] [xbp-10h]
  __int64 v113; // [xsp+58h] [xbp-8h]

  v8 = result;
  v10 = result + 0x4000;
  v113 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
    ++*(_DWORD *)(result + 17508);
  v11 = a5;
  if ( !a5 || (*(_BYTE *)(result + 17650) & 1) == 0 || *(_BYTE *)(result + 17651) == 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 13256);
    }
    else
    {
      raw_spin_lock_bh(result + 13256);
      *(_QWORD *)(v8 + 13264) |= 1uLL;
    }
    if ( *(_DWORD *)(v8 + 13276) > (unsigned int)(unsigned __int16)a2 )
    {
      v13 = *(_QWORD *)(*(_QWORD *)(v8 + 13088) + 8LL * (unsigned __int16)a2);
      if ( v13 )
      {
        v14 = *(_DWORD *)(v13 + 40);
        do
        {
          if ( !v14 )
            goto LABEL_21;
          _X12 = (unsigned int *)(v13 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v21 = __ldxr(_X12);
            if ( v21 != v14 )
              break;
            if ( !__stlxr(v14 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v21 == v14;
          v14 = v21;
        }
        while ( !_ZF );
        _X8 = (unsigned int *)(v13 + 308);
        __asm { PRFM            #0x11, [X8] }
        do
          v107 = __ldxr(_X8);
        while ( __stxr(v107 + 1, _X8) );
        v108 = *(_QWORD *)(v8 + 13264);
        if ( (v108 & 1) != 0 )
        {
          *(_QWORD *)(v8 + 13264) = v108 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v8 + 13256);
          if ( !*(_QWORD *)v13 )
          {
LABEL_28:
            v35 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v13 + 24) + 24LL) + 8LL);
            v36 = _ReadStatusReg(DAIF);
            if ( a5 )
            {
              if ( v36 < 0
                || (v37 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v37 + 16) & 0xF0000) != 0)
                || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v35 + 2197);
                v38 = v35[2198];
                if ( (v38 & 1) == 0 )
                {
LABEL_33:
                  raw_spin_unlock(v35 + 2197);
LABEL_34:
                  if ( a4 )
                  {
                    v47 = *a4;
                    v48 = a4[1];
                    v49 = a4[2];
                    v50 = a4[5];
                  }
                  else
                  {
                    v49 = 0;
                    v47 = 0;
                    v48 = 0;
                    v50 = 0;
                  }
                  qdf_trace_msg(
                    0x45u,
                    1u,
                    "%s: AST entry not found with peer %pK peer_id %u peer_mac %02x:%02x:%02x:**:**:%02x mac_addr %02x:%0"
                    "2x:%02x:**:**:%02x vdev_id %u next_hop %u",
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    "dp_rx_peer_unmap_handler",
                    v13,
                    *(unsigned __int16 *)(v13 + 16),
                    *(unsigned __int8 *)(v13 + 44),
                    *(unsigned __int8 *)(v13 + 45),
                    *(unsigned __int8 *)(v13 + 46),
                    *(unsigned __int8 *)(v13 + 49),
                    v47,
                    v48,
                    v49,
                    v50,
                    (unsigned __int8)a3,
                    v11);
                  v103 = v13;
                  v104 = 13;
LABEL_66:
                  result = dp_peer_unref_delete(v103, v104, v95, v96, v97, v98, v99, v100, v101, v102);
                  goto LABEL_67;
                }
              }
              else
              {
                raw_spin_lock_bh(v35 + 2197);
                v38 = v35[2198] | 1LL;
                v35[2198] = v38;
                if ( (v38 & 1) == 0 )
                  goto LABEL_33;
              }
              v35[2198] = v38 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v35 + 2197);
              goto LABEL_34;
            }
            if ( v36 < 0
              || (v51 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v51 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v51 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v35 + 2197);
              v52 = *(unsigned __int16 **)(v13 + 208);
              if ( !v52 )
              {
LABEL_40:
                *(_QWORD *)(v13 + 32) = 0;
                v53 = v35[2198];
                if ( (v53 & 1) != 0 )
                {
                  v35[2198] = v53 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v35 + 2197);
                }
                else
                {
                  raw_spin_unlock(v35 + 2197);
                }
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: peer_unmap_event (soc:%pK) peer_id %d peer %pK",
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  "dp_rx_peer_unmap_handler",
                  v35,
                  (unsigned __int16)a2,
                  v13);
                v62 = *(_QWORD *)(v13 + 24);
                dp_peer_find_id_to_obj_remove((__int64)v35, a2);
                v63 = (_DWORD *)v35[202];
                if ( v63 )
                {
                  if ( *(v63 - 1) != 83699819 )
                    __break(0x8228u);
                  ((void (__fastcall *)(_QWORD *, _QWORD))v63)(v35, a2);
                }
                *(_WORD *)(v13 + 16) = -1;
                if ( (wlan_cfg_is_ipa_enabled(v35[5]) & 1) == 0 )
                {
                  v64 = *(_DWORD **)(v35[1] + 104LL);
                  if ( v64 )
                  {
                    v65 = v35[2];
                    if ( *(v64 - 1) != -1042620198 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, _QWORD, _QWORD, unsigned __int8 *))v64)(v65, a2, a3, a4);
                  }
                }
                dp_update_vdev_stats_on_peer_unmap(v62, v13);
                v66 = *(_DWORD **)(v35[1] + 360LL);
                if ( v66 )
                {
                  v67 = *(unsigned __int8 *)(*(_QWORD *)(v13 + 24) + 59LL);
                  if ( *(v66 - 1) != -1684742716 )
                    __break(0x8228u);
                  ((void (__fastcall *)(_QWORD *, __int64, _QWORD, __int64, __int64))v66)(v35, 2, a2, v67, v13 + 44);
                }
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (v68 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v68 + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(v68 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v13 + 384);
                }
                else
                {
                  raw_spin_lock_bh(v13 + 384);
                  *(_QWORD *)(v13 + 392) |= 1uLL;
                }
                v77 = *(unsigned __int8 *)(v13 + 380);
                if ( v77 != 3 )
                  qdf_trace_msg(
                    0x45u,
                    1u,
                    "%s: Invalid state shift from %u to %u peer %02x:%02x:%02x:**:**:%02x",
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    "dp_peer_update_state",
                    *(unsigned __int8 *)(v13 + 380),
                    4,
                    *(unsigned __int8 *)(v13 + 44),
                    *(unsigned __int8 *)(v13 + 45),
                    *(unsigned __int8 *)(v13 + 46),
                    *(unsigned __int8 *)(v13 + 49));
                v78 = *(_QWORD *)(v13 + 392);
                *(_BYTE *)(v13 + 380) = 4;
                if ( (v78 & 1) != 0 )
                {
                  *(_QWORD *)(v13 + 392) = v78 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v13 + 384);
                }
                else
                {
                  raw_spin_unlock(v13 + 384);
                }
                LODWORD(v110) = *(unsigned __int8 *)(v13 + 49);
                LODWORD(v109) = *(unsigned __int8 *)(v13 + 46);
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: Updating peer state from %u to %u mac %02x:%02x:%02x:**:**:%02x\n",
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  "dp_peer_update_state",
                  v77,
                  4,
                  *(unsigned __int8 *)(v13 + 44),
                  *(unsigned __int8 *)(v13 + 45),
                  v109,
                  v110);
                dp_peer_unref_delete(v13, 0xDu, v87, v88, v89, v90, v91, v92, v93, v94);
                v103 = v13;
                v104 = 12;
                goto LABEL_66;
              }
            }
            else
            {
              raw_spin_lock_bh(v35 + 2197);
              v35[2198] |= 1uLL;
              v52 = *(unsigned __int16 **)(v13 + 208);
              if ( !v52 )
                goto LABEL_40;
            }
            do
            {
              v105 = *((unsigned __int16 **)v52 + 6);
              if ( *((_BYTE *)v52 + 14) == 1 )
                *(_QWORD *)(v35[2194] + 8LL * *v52) = 0;
              v52 = v105;
            }
            while ( v105 );
            goto LABEL_40;
          }
        }
        else
        {
          raw_spin_unlock(v8 + 13256);
          if ( !*(_QWORD *)v13 )
            goto LABEL_28;
        }
        v32 = *(_QWORD *)(v13 + 24);
        v111[0] = 0;
        v111[1] = v13 + 44;
        v112 = 0;
        v33 = *(_BYTE *)(v32 + 59);
        v34 = *(_BYTE **)(v32 + 24);
        LOBYTE(v111[0]) = v33;
        BYTE1(v112) = *v34;
        dp_wdi_event_handler(299, v8, v111, a2, 0xFFFFFFFFLL);
        goto LABEL_28;
      }
    }
LABEL_21:
    v22 = *(_QWORD *)(v8 + 13264);
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(v8 + 13264) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v8 + 13256);
    }
    else
    {
      raw_spin_unlock(v8 + 13256);
    }
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Received unmap event for invalid peer_id %u",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "dp_rx_peer_unmap_handler",
               (unsigned __int16)a2);
    if ( v8 )
      ++*(_DWORD *)(v10 + 1128);
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
