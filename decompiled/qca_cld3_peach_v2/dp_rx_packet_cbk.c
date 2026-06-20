__int64 __fastcall dp_rx_packet_cbk(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x20
  __int64 *v11; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x9
  _QWORD *v15; // x28
  __int64 v16; // x27
  __int64 *v17; // x28
  __int64 v18; // t1
  bool is_ipv4_arp_pkt; // w8
  __int64 v20; // x0
  int v21; // w23
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w24
  char v31; // w26
  bool is_ipv4_eapol_pkt; // w8
  __int64 v33; // x0
  int eapol_subtype; // w9
  int v35; // w23
  int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int8 *v45; // x8
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  _BOOL8 is_icmp_pkt; // x0
  __int64 v51; // x1
  unsigned int v52; // w8
  __int64 v53; // x9
  __int64 v54; // x8
  __int64 v55; // x23
  __int64 v56; // x25
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 (__fastcall *v65)(_QWORD); // x8
  __int64 v66; // x0
  _BYTE *v67; // x1
  unsigned __int16 v68; // w8
  char v69; // w9
  __int64 v70; // x6
  __int64 v71; // x7
  __int64 v72; // x28
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double updated; // d0
  unsigned int *v82; // x8
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x1
  __int64 v91; // x8
  int v92; // w8
  bool is_ipv4_dhcp_pkt; // w8
  _BYTE *v94; // x0
  int dhcp_subtype; // w0
  unsigned int v96; // w28
  char v97; // w8
  const char *v98; // x0
  _DWORD *v99; // x8
  __int64 v100; // x0
  char v101; // w24
  unsigned int v102; // w8
  __int64 v103; // x9
  unsigned int v104; // w8
  __int64 v105; // x9
  __int64 v106; // x8
  __int64 v107; // x8
  __int64 v108; // x0
  void (__fastcall *v109)(_QWORD); // x8
  __int64 v110; // x2
  __int64 v111; // x3
  unsigned int v114; // w9
  unsigned __int64 v121; // x9
  unsigned int v124; // w9
  __int64 result; // x0
  __int64 v126; // x20
  __int64 v127; // [xsp+0h] [xbp-80h]
  __int64 v128; // [xsp+8h] [xbp-78h]
  __int64 v129; // [xsp+10h] [xbp-70h]
  __int64 v130; // [xsp+18h] [xbp-68h]
  __int64 v131; // [xsp+28h] [xbp-58h]
  int v132; // [xsp+30h] [xbp-50h]
  bool is_arp_req; // [xsp+34h] [xbp-4Ch]
  __int64 v134; // [xsp+38h] [xbp-48h]
  unsigned int v135; // [xsp+40h] [xbp-40h]
  __int64 v136; // [xsp+48h] [xbp-38h]
  char v137[4]; // [xsp+54h] [xbp-2Ch] BYREF
  __int64 v138; // [xsp+58h] [xbp-28h]
  _BYTE v139[18]; // [xsp+60h] [xbp-20h] BYREF
  __int64 v140; // [xsp+78h] [xbp-8h]

  v140 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v137[0] = 0;
  if ( a1 )
  {
    v10 = a2;
    if ( a2 )
    {
      v11 = *(__int64 **)(a1 + 32);
      StatusReg = _ReadStatusReg(SP_EL0);
      v136 = *v11;
      ++*(_DWORD *)(StatusReg + 16);
      v135 = *(_DWORD *)(StatusReg + 40);
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule(a1);
      v132 = 0;
      v131 = 0;
      while ( 1 )
      {
        v15 = v10;
        v16 = (__int64)v10;
        v10 = (_QWORD *)*v10;
        v18 = v15[28];
        v17 = v15 + 28;
        *(_QWORD *)v16 = 0;
        is_ipv4_arp_pkt = _qdf_nbuf_data_is_ipv4_arp_pkt(v18);
        v20 = *v17;
        if ( is_ipv4_arp_pkt )
        {
          if ( !_qdf_nbuf_data_is_arp_rsp(v20)
            || (v21 = *((_DWORD *)v11 + 770), v21 != (unsigned int)_qdf_nbuf_get_arp_src_ip(*v17)) )
          {
            is_arp_req = _qdf_nbuf_data_is_arp_req(*v17);
LABEL_18:
            v134 = 0;
            v30 = 0;
            v31 = 0;
            goto LABEL_19;
          }
          ++*((_WORD *)v11 + 1361);
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: ARP packet received",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "dp_rx_packet_cbk");
          is_arp_req = 0;
          v30 = 0;
          v134 = 0;
          v31 = 0;
          BYTE4(v131) = 1;
        }
        else
        {
          is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(v20);
          v33 = *v17;
          if ( !is_ipv4_eapol_pkt )
          {
            is_ipv4_dhcp_pkt = _qdf_nbuf_data_is_ipv4_dhcp_pkt(v33);
            v94 = (_BYTE *)*v17;
            if ( is_ipv4_dhcp_pkt )
            {
              dhcp_subtype = _qdf_nbuf_data_get_dhcp_subtype(v94);
              if ( dhcp_subtype == 8 )
              {
                v30 = 0;
                v31 = 0;
                ++*((_WORD *)v11 + 1404);
                is_arp_req = 0;
                v134 = 1;
                v132 = 8;
                goto LABEL_19;
              }
              if ( dhcp_subtype == 7 )
              {
                v30 = 0;
                v31 = 0;
                ++*((_WORD *)v11 + 1402);
                is_arp_req = 0;
                v134 = 1;
                v132 = 7;
                goto LABEL_19;
              }
              v132 = dhcp_subtype;
            }
            else if ( _qdf_nbuf_data_is_ipv4_mcast_pkt((__int64)v94) || _qdf_nbuf_data_is_ipv6_mcast_pkt(*v17) )
            {
              v30 = 0;
              v31 = 1;
              is_arp_req = 0;
              v134 = 0;
              goto LABEL_19;
            }
            is_arp_req = 0;
            goto LABEL_18;
          }
          eapol_subtype = _qdf_nbuf_data_get_eapol_subtype(v33);
          if ( (*(_BYTE *)(v16 + 48) & 0x80) != 0 )
          {
            v35 = eapol_subtype;
            v36 = qdf_mem_cmp((const void *)*v17, (char *)v11 + 20, 6u);
            eapol_subtype = v35;
            if ( v36 )
            {
              v45 = (unsigned __int8 *)*v17;
              if ( *v17 )
              {
                v46 = *v45;
                v47 = v45[1];
                v48 = v45[2];
                v49 = v45[5];
              }
              else
              {
                v48 = 0;
                v46 = 0;
                v47 = 0;
                v49 = 0;
              }
              LODWORD(v130) = *((unsigned __int8 *)v11 + 25);
              LODWORD(v129) = *((unsigned __int8 *)v11 + 22);
              LODWORD(v128) = *((unsigned __int8 *)v11 + 21);
              LODWORD(v127) = *((unsigned __int8 *)v11 + 20);
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: da mac:%02x:%02x:%02x:**:**:%02xintf_mac:%02x:%02x:%02x:**:**:%02x",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "dp_rx_pkt_da_check",
                v46,
                v47,
                v48,
                v49,
                v127,
                v128,
                v129,
                v130);
              qdf_mem_copy((void *)*v17, (char *)v11 + 20, 6u);
              eapol_subtype = v35;
            }
          }
          if ( eapol_subtype == 3 )
          {
            is_arp_req = 0;
            v134 = 0x100000000LL;
            v31 = 0;
            v30 = 1;
            ++*((_WORD *)v11 + 1423);
            v132 = 3;
          }
          else if ( eapol_subtype == 1 )
          {
            is_arp_req = 0;
            v134 = 0x100000000LL;
            v31 = 0;
            v30 = 1;
            ++*((_WORD *)v11 + 1421);
            v132 = 1;
          }
          else
          {
            v132 = eapol_subtype;
            is_arp_req = 0;
            v31 = 0;
            v30 = 1;
            v134 = 0;
          }
        }
LABEL_19:
        is_icmp_pkt = _qdf_nbuf_data_is_icmp_pkt(*v17);
        if ( is_icmp_pkt )
        {
          v52 = *(unsigned __int16 *)(v16 + 62);
          if ( v52 != 0xFFFF )
          {
            v53 = *(_QWORD *)(v136 + 2936);
            if ( v53 )
            {
              if ( v52 >= 0x41 )
                goto LABEL_134;
              v54 = v53 + 96LL * *(unsigned __int16 *)(v16 + 62);
              if ( *(_BYTE *)(v54 + 262) )
              {
                v55 = v54 + 256;
                v56 = *(_QWORD *)(v54 + 272);
                *(_QWORD *)(v54 + 272) = sched_clock(is_icmp_pkt, v51);
                _X8 = (unsigned __int64 *)(v55 + 80);
                __asm { PRFM            #0x11, [X8] }
                do
                  v121 = __ldxr(_X8);
                while ( __stxr(v121 | 4, _X8) );
                if ( !v56 )
                  *(_DWORD *)(v55 + 88) = 1;
              }
            }
          }
        }
        *(_QWORD *)v139 = 0;
        *(_QWORD *)&v139[8] = 0;
        if ( (qdf_is_dp_pkt_timestamp_enabled() & 1) != 0 )
        {
          v138 = 0;
          v108 = v11[7];
          v109 = *(void (__fastcall **)(_QWORD))(*v11 + 408);
          __isb(0xFu);
          _ReadStatusReg(CNTVCT_EL0);
          if ( *((_DWORD *)v109 - 1) != -239780719 )
            __break(0x8228u);
          v109(v108);
          ((void (__fastcall *)(__int64, __int64, __int64))qdf_add_dp_pkt_timestamp)(v16, 3, v138);
          *(_DWORD *)&v139[4] = 32;
          _qdf_nbuf_set_rx_cksum(v16, v139, v110, v111);
          if ( !*((_DWORD *)v11 + 769) )
            goto LABEL_28;
LABEL_27:
          dp_tx_rx_collect_connectivity_stats_info(v16, a1, 1, v137, v57, v58, v59, v60, v61, v62, v63, v64);
          goto LABEL_28;
        }
        if ( *((_DWORD *)v11 + 769) )
          goto LABEL_27;
LABEL_28:
        if ( *(_BYTE *)(a1 + 76) )
        {
          v65 = *(__int64 (__fastcall **)(_QWORD))(v136 + 496);
          if ( v65 )
          {
            if ( *((_DWORD *)v65 - 1) != 1343853669 )
              __break(0x8228u);
            if ( (v65(v16) & 1) != 0 )
            {
              _X8 = (unsigned int *)(v11 + 333);
              __asm { PRFM            #0x11, [X8] }
              do
                v124 = __ldxr(_X8);
              while ( __stxr(v124 + 1, _X8) );
              goto LABEL_41;
            }
          }
        }
        v66 = *v17;
        *(_DWORD *)&v139[14] = 0;
        *(_QWORD *)&v139[6] = 0;
        if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(v66) )
        {
          v67 = (_BYTE *)*v17;
          v68 = *(_WORD *)(*v17 + 19);
          v139[0] = 1;
          v69 = v67[15];
          *(_DWORD *)&v139[2] = v68;
          v139[1] = v69;
          qdf_mem_copy(&v139[6], v67, 6u);
          qdf_mem_copy(&v139[12], (const void *)(*v17 + 6), 6u);
          host_diag_event_report_payload(2701, 18, v139);
        }
        qdf_dp_trace_log_pkt(*(unsigned __int8 *)(a1 + 24), v16, 1u, 0xFFu, *((_DWORD *)v11 + 7));
        qdf_dp_trace(v16, 0x1Au, 0xFFu, (__int64)v17, 8u, 1, v70, v71);
        qdf_dp_trace_data_pkt(v16, 0xFFu, 0xFu, 0, 1);
        v72 = *(_QWORD *)(v16 + 224);
        if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(
                              *(_QWORD *)(a1 + 40),
                              0x10u,
                              v73,
                              v74,
                              v75,
                              v76,
                              v77,
                              v78,
                              v79,
                              v80) )
        {
          updated = wlan_tdls_update_rx_pkt_cnt(*(_QWORD *)(a1 + 40), v72 + 6, v72);
          wlan_objmgr_vdev_release_ref(*(_QWORD *)(a1 + 40), 0x10u, v82, updated, v83, v84, v85, v86, v87, v88, v89);
        }
        v90 = v11[7];
        *(_QWORD *)(v16 + 16) = v90;
        *(_WORD *)(v16 + 180) = eth_type_trans(v16, v90);
        if ( v135 >= 0x20 )
LABEL_134:
          __break(0x5512u);
        ++*((_DWORD *)v11 + 19 * v135 + 73);
        v91 = v11[361] + 1;
        v11[361] = v91;
        v11[361] = v91 + *(unsigned __int16 *)(*(_QWORD *)(v16 + 216) + *(unsigned int *)(v16 + 212) + 6LL);
        if ( (*(_BYTE *)(v16 + 68) & 4) != 0 )
          v92 = *(unsigned __int16 *)(v16 + 66);
        else
          v92 = 0;
        v11[363] += (unsigned int)(*(_DWORD *)(v16 + 112) + v92);
        dp_nud_incr_gw_rx_pkt_cnt(v11, v72 + 6);
        if ( *(_BYTE *)(v136 + 174) == 1 && _qdf_nbuf_is_mcast_replay(v16) )
        {
          _X8 = (unsigned int *)(v11 + 333);
          __asm { PRFM            #0x11, [X8] }
          do
            v114 = __ldxr(_X8);
          while ( __stxr(v114 + 1, _X8) );
LABEL_41:
          _qdf_nbuf_free(v16);
          if ( !v10 )
          {
LABEL_128:
            result = 0;
            goto LABEL_129;
          }
        }
        else
        {
          v96 = *(_DWORD *)(v136 + 176);
          if ( v96 && (!*(_BYTE *)(a1 + 77) ? (v97 = 1) : (v97 = v31), (v97 & 1) == 0) )
          {
            if ( is_arp_req )
            {
              if ( !_qdf_nbuf_is_arp_local(v16, (unsigned __int8 *)v11 + 3872) )
              {
LABEL_56:
                LOBYTE(v131) = 0;
                if ( !v30 )
                  goto LABEL_82;
                goto LABEL_73;
              }
              v96 = *(_DWORD *)(v136 + 176);
            }
            else if ( (*(_BYTE *)(v16 + 128) & 7u) - 3 >= 0xFFFFFFFE )
            {
              goto LABEL_56;
            }
          }
          else if ( (v131 & 1) == 0 )
          {
            goto LABEL_56;
          }
          if ( (unsigned int)cds_get_ring_log_level(0) >= 3 )
          {
            v98 = qdf_wake_lock_name(v136 + 1200);
            ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(10, v98, v96, 0);
          }
          qdf_wake_lock_timeout_acquire(v136 + 1200, *(unsigned int *)(v136 + 176));
          LOBYTE(v131) = 1;
          if ( !v30 )
          {
LABEL_82:
            if ( (unsigned int)wlan_dp_rx_deliver_to_stack(v11, v16) )
              goto LABEL_83;
            goto LABEL_77;
          }
LABEL_73:
          v99 = *(_DWORD **)(v136 + 504);
          if ( !v99 )
            goto LABEL_82;
          v100 = v11[7];
          if ( *(v99 - 1) != 326986700 )
            __break(0x8228u);
          v101 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v99)(v100, a1 + 70, v16, 0);
          consume_skb(v16);
          if ( (v101 & 1) == 0 )
          {
LABEL_83:
            ++*((_DWORD *)v11 + 19 * v135 + 76);
            if ( (v131 & 0x100000000LL) != 0 )
              ++*((_WORD *)v11 + 1365);
            if ( HIDWORD(v134) )
            {
              v104 = v132 - 1;
              if ( (unsigned int)(v132 - 1) >= 5 )
                goto LABEL_134;
              v105 = 2874;
              goto LABEL_91;
            }
            if ( (_DWORD)v134 )
            {
              v104 = v132 - 5;
              if ( (unsigned int)(v132 - 5) > 4 )
                goto LABEL_134;
              v105 = 2834;
LABEL_91:
              ++*(_WORD *)((char *)v11 + 2 * v104 + v105);
            }
            if ( *((_DWORD *)v11 + 769) )
            {
              v106 = *(_QWORD *)(a1 + 32);
              if ( (*(_DWORD *)(v106 + 3076) & ~*(_DWORD *)(*(_QWORD *)v106 + 1196LL)) != 0 )
              {
                switch ( v137[0] )
                {
                  case 2:
                    ++*(_WORD *)(v106 + 2748);
                    break;
                  case 7:
                    ++*(_WORD *)(v106 + 2768);
                    break;
                  case 4:
                    ++*(_WORD *)(v106 + 2792);
                    break;
                }
              }
            }
            goto LABEL_7;
          }
LABEL_77:
          ++*((_DWORD *)v11 + 19 * v135 + 75);
          if ( (v131 & 0x100000000LL) != 0 )
            ++*((_WORD *)v11 + 1364);
          if ( HIDWORD(v134) )
          {
            v102 = v132 - 1;
            if ( (unsigned int)(v132 - 1) >= 5 )
              goto LABEL_134;
            v103 = 2866;
LABEL_101:
            ++*(_WORD *)((char *)v11 + 2 * v102 + v103);
            goto LABEL_102;
          }
          if ( (_DWORD)v134 )
          {
            v102 = v132 - 5;
            if ( (unsigned int)(v132 - 5) > 4 )
              goto LABEL_134;
            v103 = 2826;
            goto LABEL_101;
          }
LABEL_102:
          if ( *((_DWORD *)v11 + 769) )
          {
            v107 = *(_QWORD *)(a1 + 32);
            if ( (*(_DWORD *)(v107 + 3076) & ~*(_DWORD *)(*(_QWORD *)v107 + 1196LL)) != 0 )
            {
              switch ( v137[0] )
              {
                case 2:
                  ++*(_WORD *)(v107 + 2746);
                  break;
                case 7:
                  ++*(_WORD *)(v107 + 2766);
                  break;
                case 4:
                  ++*(_WORD *)(v107 + 2790);
                  break;
              }
            }
          }
LABEL_7:
          if ( !v10 )
            goto LABEL_128;
        }
      }
    }
  }
  v126 = jiffies;
  if ( dp_rx_packet_cbk___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Null params being passed", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_packet_cbk");
    dp_rx_packet_cbk___last_ticks = v126;
  }
  result = 16;
LABEL_129:
  _ReadStatusReg(SP_EL0);
  return result;
}
