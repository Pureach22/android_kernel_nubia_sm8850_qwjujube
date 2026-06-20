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
  _QWORD *v15; // x27
  __int64 v16; // x25
  __int64 *v17; // x27
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
  int v30; // w28
  char v31; // w24
  bool is_ipv4_eapol_pkt; // w8
  __int64 v33; // x0
  int eapol_subtype; // w0
  _BOOL8 is_icmp_pkt; // x0
  __int64 v36; // x1
  unsigned int v37; // w8
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x23
  __int64 v41; // x26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  _BYTE *v52; // x1
  unsigned __int16 v53; // w8
  char v54; // w9
  __int64 v55; // x6
  __int64 v56; // x7
  __int64 v57; // x27
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double updated; // d0
  unsigned int *v67; // x8
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  int v76; // w8
  bool is_ipv4_dhcp_pkt; // w8
  _BYTE *v78; // x0
  int dhcp_subtype; // w0
  unsigned int v80; // w27
  char v81; // w8
  const char *v82; // x0
  _DWORD *v83; // x8
  __int64 v84; // x0
  char v85; // w26
  unsigned int v86; // w8
  __int64 v87; // x9
  unsigned int v88; // w8
  __int64 v89; // x9
  __int64 v90; // x8
  __int64 v91; // x8
  __int64 v92; // x0
  void (__fastcall *v93)(_QWORD); // x8
  __int64 v94; // x2
  __int64 v95; // x3
  unsigned int v98; // w9
  unsigned __int64 v105; // x9
  unsigned int v108; // w9
  __int64 result; // x0
  __int64 v110; // x20
  __int64 v111; // [xsp+8h] [xbp-58h]
  int v112; // [xsp+10h] [xbp-50h]
  bool is_arp_req; // [xsp+14h] [xbp-4Ch]
  __int64 v114; // [xsp+18h] [xbp-48h]
  unsigned int v115; // [xsp+20h] [xbp-40h]
  __int64 v116; // [xsp+28h] [xbp-38h]
  _BYTE v117[4]; // [xsp+34h] [xbp-2Ch] BYREF
  __int64 v118; // [xsp+38h] [xbp-28h]
  _BYTE v119[18]; // [xsp+40h] [xbp-20h] BYREF
  __int64 v120; // [xsp+58h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v117[0] = 0;
  if ( a1 )
  {
    v10 = a2;
    if ( a2 )
    {
      v11 = *(__int64 **)(a1 + 32);
      StatusReg = _ReadStatusReg(SP_EL0);
      v116 = *v11;
      ++*(_DWORD *)(StatusReg + 16);
      v115 = *(_DWORD *)(StatusReg + 40);
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule(a1);
      v112 = 0;
      v111 = 0;
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
LABEL_17:
            v114 = 0;
            v30 = 0;
            v31 = 0;
            goto LABEL_18;
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
          v114 = 0;
          v31 = 0;
          BYTE4(v111) = 1;
        }
        else
        {
          is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(v20);
          v33 = *v17;
          if ( !is_ipv4_eapol_pkt )
          {
            is_ipv4_dhcp_pkt = _qdf_nbuf_data_is_ipv4_dhcp_pkt(v33);
            v78 = (_BYTE *)*v17;
            if ( is_ipv4_dhcp_pkt )
            {
              dhcp_subtype = _qdf_nbuf_data_get_dhcp_subtype(v78);
              if ( dhcp_subtype == 8 )
              {
                v30 = 0;
                v31 = 0;
                ++*((_WORD *)v11 + 1404);
                is_arp_req = 0;
                v114 = 1;
                v112 = 8;
                goto LABEL_18;
              }
              if ( dhcp_subtype == 7 )
              {
                v30 = 0;
                v31 = 0;
                ++*((_WORD *)v11 + 1402);
                is_arp_req = 0;
                v114 = 1;
                v112 = 7;
                goto LABEL_18;
              }
              v112 = dhcp_subtype;
            }
            else if ( _qdf_nbuf_data_is_ipv4_mcast_pkt((__int64)v78) || _qdf_nbuf_data_is_ipv6_mcast_pkt(*v17) )
            {
              v30 = 0;
              v31 = 1;
              is_arp_req = 0;
              v114 = 0;
              goto LABEL_18;
            }
            is_arp_req = 0;
            goto LABEL_17;
          }
          eapol_subtype = _qdf_nbuf_data_get_eapol_subtype(v33);
          if ( eapol_subtype == 3 )
          {
            is_arp_req = 0;
            v114 = 0x100000000LL;
            v31 = 0;
            v30 = 1;
            ++*((_WORD *)v11 + 1423);
            v112 = 3;
          }
          else if ( eapol_subtype == 1 )
          {
            is_arp_req = 0;
            v114 = 0x100000000LL;
            v31 = 0;
            v30 = 1;
            ++*((_WORD *)v11 + 1421);
            v112 = 1;
          }
          else
          {
            v112 = eapol_subtype;
            is_arp_req = 0;
            v31 = 0;
            v30 = 1;
            v114 = 0;
          }
        }
LABEL_18:
        is_icmp_pkt = _qdf_nbuf_data_is_icmp_pkt(*v17);
        if ( is_icmp_pkt )
        {
          v37 = *(unsigned __int16 *)(v16 + 62);
          if ( v37 != 0xFFFF )
          {
            v38 = *(_QWORD *)(v116 + 2936);
            if ( v38 )
            {
              if ( v37 >= 0x41 )
                goto LABEL_128;
              v39 = v38 + 96LL * *(unsigned __int16 *)(v16 + 62);
              if ( *(_BYTE *)(v39 + 262) )
              {
                v40 = v39 + 256;
                v41 = *(_QWORD *)(v39 + 272);
                *(_QWORD *)(v39 + 272) = sched_clock(is_icmp_pkt, v36);
                _X8 = (unsigned __int64 *)(v40 + 80);
                __asm { PRFM            #0x11, [X8] }
                do
                  v105 = __ldxr(_X8);
                while ( __stxr(v105 | 4, _X8) );
                if ( !v41 )
                  *(_DWORD *)(v40 + 88) = 1;
              }
            }
          }
        }
        *(_QWORD *)v119 = 0;
        *(_QWORD *)&v119[8] = 0;
        if ( (qdf_is_dp_pkt_timestamp_enabled() & 1) != 0 )
        {
          v118 = 0;
          v92 = v11[7];
          v93 = *(void (__fastcall **)(_QWORD))(*v11 + 408);
          __isb(0xFu);
          _ReadStatusReg(CNTVCT_EL0);
          if ( *((_DWORD *)v93 - 1) != -239780719 )
            __break(0x8228u);
          v93(v92);
          ((void (__fastcall *)(__int64, __int64, __int64))qdf_add_dp_pkt_timestamp)(v16, 3, v118);
          *(_DWORD *)&v119[4] = 32;
          _qdf_nbuf_set_rx_cksum(v16, v119, v94, v95);
          if ( !*((_DWORD *)v11 + 769) )
            goto LABEL_27;
LABEL_26:
          dp_tx_rx_collect_connectivity_stats_info(v16, a1, 1, v117, v42, v43, v44, v45, v46, v47, v48, v49);
          goto LABEL_27;
        }
        if ( *((_DWORD *)v11 + 769) )
          goto LABEL_26;
LABEL_27:
        if ( *(_BYTE *)(a1 + 76) )
        {
          v50 = *(__int64 (__fastcall **)(_QWORD))(v116 + 496);
          if ( v50 )
          {
            if ( *((_DWORD *)v50 - 1) != 1343853669 )
              __break(0x8228u);
            if ( (v50(v16) & 1) != 0 )
            {
              _X8 = (unsigned int *)(v11 + 333);
              __asm { PRFM            #0x11, [X8] }
              do
                v108 = __ldxr(_X8);
              while ( __stxr(v108 + 1, _X8) );
              goto LABEL_40;
            }
          }
        }
        v51 = *v17;
        *(_DWORD *)&v119[14] = 0;
        *(_QWORD *)&v119[6] = 0;
        if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(v51) )
        {
          v52 = (_BYTE *)*v17;
          v53 = *(_WORD *)(*v17 + 19);
          v119[0] = 1;
          v54 = v52[15];
          *(_DWORD *)&v119[2] = v53;
          v119[1] = v54;
          qdf_mem_copy(&v119[6], v52, 6u);
          qdf_mem_copy(&v119[12], (const void *)(*v17 + 6), 6u);
          host_diag_event_report_payload(2701, 18, v119);
        }
        qdf_dp_trace_log_pkt(*(unsigned __int8 *)(a1 + 24), v16, 1u, 0xFFu, *((_DWORD *)v11 + 7));
        qdf_dp_trace(v16, 0x1Au, 0xFFu, (__int64)v17, 8u, 1, v55, v56);
        qdf_dp_trace_data_pkt(v16, 0xFFu, 0xFu, 0, 1);
        v57 = *(_QWORD *)(v16 + 224);
        if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(
                              *(_QWORD *)(a1 + 40),
                              0x10u,
                              v58,
                              v59,
                              v60,
                              v61,
                              v62,
                              v63,
                              v64,
                              v65) )
        {
          updated = wlan_tdls_update_rx_pkt_cnt(*(_QWORD *)(a1 + 40), v57 + 6, v57);
          wlan_objmgr_vdev_release_ref(*(_QWORD *)(a1 + 40), 0x10u, v67, updated, v68, v69, v70, v71, v72, v73, v74);
        }
        *(_QWORD *)(v16 + 16) = v11[7];
        *(_WORD *)(v16 + 180) = eth_type_trans(v16);
        if ( v115 >= 0x20 )
LABEL_128:
          __break(0x5512u);
        ++*((_DWORD *)v11 + 19 * v115 + 73);
        v75 = v11[361] + 1;
        v11[361] = v75;
        v11[361] = v75 + *(unsigned __int16 *)(*(_QWORD *)(v16 + 216) + *(unsigned int *)(v16 + 212) + 6LL);
        if ( (*(_BYTE *)(v16 + 68) & 4) != 0 )
          v76 = *(unsigned __int16 *)(v16 + 66);
        else
          v76 = 0;
        v11[363] += (unsigned int)(*(_DWORD *)(v16 + 112) + v76);
        dp_nud_incr_gw_rx_pkt_cnt(v11, v57 + 6);
        if ( *(_BYTE *)(v116 + 174) == 1 && _qdf_nbuf_is_mcast_replay(v16) )
        {
          _X8 = (unsigned int *)(v11 + 333);
          __asm { PRFM            #0x11, [X8] }
          do
            v98 = __ldxr(_X8);
          while ( __stxr(v98 + 1, _X8) );
LABEL_40:
          _qdf_nbuf_free(v16);
          if ( !v10 )
          {
LABEL_122:
            result = 0;
            goto LABEL_123;
          }
        }
        else
        {
          v80 = *(_DWORD *)(v116 + 176);
          if ( v80 && (!*(_BYTE *)(a1 + 77) ? (v81 = 1) : (v81 = v31), (v81 & 1) == 0) )
          {
            if ( is_arp_req )
            {
              if ( !_qdf_nbuf_is_arp_local(v16, (unsigned __int8 *)v11 + 3872) )
              {
LABEL_57:
                LOBYTE(v111) = 0;
                if ( !v30 )
                  goto LABEL_76;
                goto LABEL_67;
              }
              v80 = *(_DWORD *)(v116 + 176);
            }
            else if ( (*(_BYTE *)(v16 + 128) & 7u) - 3 >= 0xFFFFFFFE )
            {
              goto LABEL_57;
            }
          }
          else if ( (v111 & 1) == 0 )
          {
            goto LABEL_57;
          }
          if ( (unsigned int)cds_get_ring_log_level(0) >= 3 )
          {
            v82 = qdf_wake_lock_name(v116 + 1200);
            ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(10, v82, v80, 0);
          }
          qdf_wake_lock_timeout_acquire(v116 + 1200, *(unsigned int *)(v116 + 176));
          LOBYTE(v111) = 1;
          if ( !v30 )
          {
LABEL_76:
            if ( (unsigned int)wlan_dp_rx_deliver_to_stack(v11, v16) )
              goto LABEL_77;
            goto LABEL_71;
          }
LABEL_67:
          v83 = *(_DWORD **)(v116 + 504);
          if ( !v83 )
            goto LABEL_76;
          v84 = v11[7];
          if ( *(v83 - 1) != 326986700 )
            __break(0x8228u);
          v85 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v83)(v84, a1 + 70, v16, 0);
          consume_skb(v16);
          if ( (v85 & 1) == 0 )
          {
LABEL_77:
            ++*((_DWORD *)v11 + 19 * v115 + 76);
            if ( (v111 & 0x100000000LL) != 0 )
              ++*((_WORD *)v11 + 1365);
            if ( HIDWORD(v114) )
            {
              v88 = v112 - 1;
              if ( (unsigned int)(v112 - 1) >= 5 )
                goto LABEL_128;
              v89 = 2874;
              goto LABEL_85;
            }
            if ( (_DWORD)v114 )
            {
              v88 = v112 - 5;
              if ( (unsigned int)(v112 - 5) > 4 )
                goto LABEL_128;
              v89 = 2834;
LABEL_85:
              ++*(_WORD *)((char *)v11 + 2 * v88 + v89);
            }
            if ( *((_DWORD *)v11 + 769) )
            {
              v90 = *(_QWORD *)(a1 + 32);
              if ( (*(_DWORD *)(v90 + 3076) & ~*(_DWORD *)(*(_QWORD *)v90 + 1196LL)) != 0 )
              {
                switch ( v117[0] )
                {
                  case 2:
                    ++*(_WORD *)(v90 + 2748);
                    break;
                  case 7:
                    ++*(_WORD *)(v90 + 2768);
                    break;
                  case 4:
                    ++*(_WORD *)(v90 + 2792);
                    break;
                }
              }
            }
            goto LABEL_7;
          }
LABEL_71:
          ++*((_DWORD *)v11 + 19 * v115 + 75);
          if ( (v111 & 0x100000000LL) != 0 )
            ++*((_WORD *)v11 + 1364);
          if ( HIDWORD(v114) )
          {
            v86 = v112 - 1;
            if ( (unsigned int)(v112 - 1) >= 5 )
              goto LABEL_128;
            v87 = 2866;
LABEL_95:
            ++*(_WORD *)((char *)v11 + 2 * v86 + v87);
            goto LABEL_96;
          }
          if ( (_DWORD)v114 )
          {
            v86 = v112 - 5;
            if ( (unsigned int)(v112 - 5) > 4 )
              goto LABEL_128;
            v87 = 2826;
            goto LABEL_95;
          }
LABEL_96:
          if ( *((_DWORD *)v11 + 769) )
          {
            v91 = *(_QWORD *)(a1 + 32);
            if ( (*(_DWORD *)(v91 + 3076) & ~*(_DWORD *)(*(_QWORD *)v91 + 1196LL)) != 0 )
            {
              switch ( v117[0] )
              {
                case 2:
                  ++*(_WORD *)(v91 + 2746);
                  break;
                case 7:
                  ++*(_WORD *)(v91 + 2766);
                  break;
                case 4:
                  ++*(_WORD *)(v91 + 2790);
                  break;
              }
            }
          }
LABEL_7:
          if ( !v10 )
            goto LABEL_122;
        }
      }
    }
  }
  v110 = jiffies;
  if ( dp_rx_packet_cbk___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Null params being passed", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_packet_cbk");
    dp_rx_packet_cbk___last_ticks = v110;
  }
  result = 16;
LABEL_123:
  _ReadStatusReg(SP_EL0);
  return result;
}
