__int64 __fastcall wlan_hdd_netif_queue_control(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x25
  int *v15; // x23
  __int64 v16; // x22
  int v17; // w8
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x1
  int v21; // w9
  __int64 v22; // x26
  __int64 v23; // x0
  int v24; // w8
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x0
  int v29; // w9
  __int64 v30; // x26
  __int64 v31; // x0
  int v32; // w22
  int v33; // w22
  int v34; // w9
  __int64 v35; // x26
  __int64 v36; // x26
  __int64 v37; // x28
  __int64 v38; // x27
  __int64 v39; // x8
  __int64 v40; // x10
  __int64 v41; // x8
  __int64 v42; // x10
  int v43; // w22
  __int64 v44; // x0
  __int64 v45; // x10
  int v46; // w12
  __int64 v47; // x9
  char v48; // w8
  __int64 v49; // x8
  __int64 v50; // x9
  int *v51; // x9
  int v52; // w9
  unsigned __int64 v53; // x9
  __int64 v54; // x11
  __int64 v55; // x12
  __int64 v56; // x10
  __int64 v57; // x9
  unsigned __int64 v64; // x9

  if ( a1 && *(_DWORD *)a1 == 1885692259 && *(_QWORD *)(a1 + 32) )
  {
    v12 = jiffies;
    v15 = (int *)(a1 + 42092);
    if ( wlan_hdd_netif_queue_control___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: netif_control's vdev_id: %d, action: %d, reason: %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_hdd_netif_queue_control",
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL),
        a2,
        a3);
      wlan_hdd_netif_queue_control___last_ticks = v12;
    }
    switch ( a2 )
    {
      case 0u:
        goto LABEL_70;
      case 1u:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        v17 = *v15;
        if ( *v15 )
          goto LABEL_57;
        netif_tx_stop_all_queues(*(_QWORD *)(a1 + 32));
        goto LABEL_56;
      case 2u:
        raw_spin_lock_bh(a1 + 42100);
        goto LABEL_32;
      case 3u:
        raw_spin_lock_bh(a1 + 42100);
        v32 = *v15;
        *v15 &= ~(1 << a3);
        if ( (v32 & ~(1 << a3)) != 0 )
          goto LABEL_62;
        netif_tx_wake_all_queues(*(_QWORD *)(a1 + 32));
        goto LABEL_60;
      case 4u:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        v24 = *v15;
        if ( !*v15 )
        {
          netif_tx_stop_all_queues(*(_QWORD *)(a1 + 32));
          wlan_hdd_update_txq_timestamp(*(_QWORD *)(a1 + 32));
          v25 = *(_QWORD *)(a1 + 42128);
          v26 = jiffies - *(_QWORD *)(a1 + 42112);
          *(_QWORD *)(a1 + 42112) = jiffies;
          v27 = v26 + v25;
          v24 = *v15;
          *(_QWORD *)(a1 + 42128) = v27;
        }
        v28 = *(_QWORD *)(a1 + 32);
        *v15 = v24 | (1 << a3);
        netif_carrier_off(v28);
        goto LABEL_68;
      case 5u:
        raw_spin_lock_bh(a1 + 42100);
        netif_carrier_on(*(_QWORD *)(a1 + 32));
LABEL_32:
        v33 = *v15;
        *v15 &= ~(1 << a3);
        if ( (v33 & ~(1 << a3)) != 0 )
          goto LABEL_62;
        netif_tx_start_all_queues(*(_QWORD *)(a1 + 32));
        goto LABEL_60;
      case 8u:
        netif_carrier_on(*(_QWORD *)(a1 + 32));
        goto LABEL_70;
      case 9u:
        netif_carrier_off(*(_QWORD *)(a1 + 32));
        goto LABEL_70;
      case 0xAu:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( a3 == 12 )
          *(_DWORD *)(a1 + 42096) &= ~0x1000u;
        else
          *v15 &= ~(1 << a3);
        wlan_hdd_update_pause_time(a1);
        if ( !*v15 )
          netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL));
        goto LABEL_68;
      case 0xBu:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( *v15 )
          goto LABEL_50;
        v39 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL);
        *(_QWORD *)(v39 + 328) = jiffies;
        __dmb(0xBu);
        goto LABEL_94;
      case 0xCu:
        raw_spin_lock_bh(a1 + 42100);
        v21 = *v15;
        *(_DWORD *)(a1 + 42096) &= ~(1 << a3);
        if ( v21 )
          goto LABEL_62;
        v22 = *(_QWORD *)(a1 + 32);
        netif_tx_wake_queue(*(_QWORD *)(v22 + 24) + 384LL);
        netif_tx_wake_queue(*(_QWORD *)(v22 + 24) + 768LL);
        netif_tx_wake_queue(*(_QWORD *)(v22 + 24) + 1152LL);
        v23 = *(_QWORD *)(v22 + 24) + 1536LL;
        goto LABEL_20;
      case 0xDu:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( *v15 )
          goto LABEL_39;
        v19 = *(_QWORD *)(a1 + 32);
        v20 = 1;
        goto LABEL_24;
      case 0xEu:
        raw_spin_lock_bh(a1 + 42100);
        v29 = *v15;
        *(_DWORD *)(a1 + 42096) &= ~(1 << a3);
        if ( v29 )
          goto LABEL_62;
        v30 = *(_QWORD *)(a1 + 32);
        netif_tx_wake_queue(*(_QWORD *)(v30 + 24) + 1920LL);
        netif_tx_wake_queue(*(_QWORD *)(v30 + 24) + 2304LL);
        netif_tx_wake_queue(*(_QWORD *)(v30 + 24) + 2688LL);
        v23 = *(_QWORD *)(v30 + 24) + 3072LL;
LABEL_20:
        netif_tx_wake_queue(v23);
        v31 = a1;
        goto LABEL_61;
      case 0xFu:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( *v15 )
          goto LABEL_39;
        v19 = *(_QWORD *)(a1 + 32);
        v20 = 2;
LABEL_24:
        hdd_stop_queues_for_ac(v19, v20);
        wlan_hdd_update_txq_timestamp(*(_QWORD *)(a1 + 32));
        goto LABEL_38;
      case 0x10u:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( *v15 )
          goto LABEL_39;
        hdd_stop_queues_for_ac(*(_QWORD *)(a1 + 32), 3);
        hdd_stop_queues_for_ac(*(_QWORD *)(a1 + 32), 4);
        wlan_hdd_update_txq_timestamp(*(_QWORD *)(a1 + 32));
        if ( *(_DWORD *)(a1 + 42096) )
        {
LABEL_38:
          wlan_hdd_update_pause_time(a1);
        }
        else
        {
          v56 = *(_QWORD *)(a1 + 42128);
          v57 = jiffies - *(_QWORD *)(a1 + 42112);
          *(_QWORD *)(a1 + 42112) = jiffies;
          *(_QWORD *)(a1 + 42128) = v57 + v56;
        }
LABEL_39:
        *(_DWORD *)(a1 + 42096) |= 1 << a3;
        goto LABEL_68;
      case 0x11u:
        raw_spin_lock_bh(a1 + 42100);
        v34 = *v15;
        *(_DWORD *)(a1 + 42096) &= ~(1 << a3);
        if ( !v34 )
        {
          v35 = *(_QWORD *)(a1 + 32);
          netif_tx_wake_queue(*(_QWORD *)(v35 + 24) + 3456LL);
          netif_tx_wake_queue(*(_QWORD *)(v35 + 24) + 3840LL);
          netif_tx_wake_queue(*(_QWORD *)(v35 + 24) + 4224LL);
          netif_tx_wake_queue(*(_QWORD *)(v35 + 24) + 4608LL);
          v36 = *(_QWORD *)(a1 + 32);
          v37 = 4992;
          v38 = *(_DWORD *)(v36 + 2728) == 11 ? 33LL : 4LL;
          do
          {
            netif_tx_wake_queue(*(_QWORD *)(v36 + 24) + v37);
            --v38;
            v37 += 384;
          }
          while ( v38 );
          wlan_hdd_update_pause_time(a1);
          if ( *(_DWORD *)(a1 + 40) == 11 && (ucfg_dp_is_ndp_bw_flow_ctrl_enabled(**(_QWORD **)(a1 + 24)) & 1) != 0 )
            wlan_hdd_ndp_reset_subq_map_n_stats(a1);
        }
        goto LABEL_62;
      case 0x12u:
        raw_spin_lock_bh(a1 + 42100);
        v43 = *v15;
        *v15 &= ~(1 << a3);
        if ( (v43 & ~(1 << a3)) != 0 )
          goto LABEL_62;
        wlan_hdd_wake_non_priority_queue(a1);
LABEL_60:
        v31 = a1;
LABEL_61:
        wlan_hdd_update_pause_time(v31);
LABEL_62:
        v44 = a1 + 42100;
        goto LABEL_69;
      case 0x13u:
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        v17 = *v15;
        if ( !*v15 )
        {
          wlan_hdd_stop_non_priority_queue(a1);
LABEL_56:
          wlan_hdd_update_txq_timestamp(*(_QWORD *)(a1 + 32));
          v40 = *(_QWORD *)(a1 + 42128);
          v41 = jiffies - *(_QWORD *)(a1 + 42112);
          *(_QWORD *)(a1 + 42112) = jiffies;
          v42 = v41 + v40;
          v17 = *v15;
          *(_QWORD *)(a1 + 42128) = v42;
        }
LABEL_57:
        *v15 = v17 | (1 << a3);
        goto LABEL_68;
      default:
        if ( *(_DWORD *)(a1 + 40) != 11 || (ucfg_dp_is_ndp_bw_flow_ctrl_enabled(**(_QWORD **)(a1 + 24)) & 1) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: unsupported action %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "wlan_hdd_netif_queue_control",
            a2);
          goto LABEL_70;
        }
        v16 = 42100;
        raw_spin_lock_bh(a1 + 42100);
        if ( !*v15 )
          ((void (__fastcall *)(__int64, _QWORD, _QWORD))wlan_hdd_ndp_handle_bw_queue_control)(a1, a2, a3);
        break;
    }
    while ( 1 )
    {
LABEL_68:
      v44 = a1 + v16;
LABEL_69:
      raw_spin_unlock_bh(v44);
LABEL_70:
      raw_spin_lock_bh(a1 + 42100);
      if ( (*(_BYTE *)v15 & 0x40) != 0 )
        wlan_hdd_process_peer_unauthorised_pause(a1);
      v16 = *(unsigned __int8 *)(a1 + 42136);
      if ( (unsigned __int8)(v16 + 1) == 25 )
        v48 = 0;
      else
        v48 = v16 + 1;
      *(_BYTE *)(a1 + 42136) = v48;
      result = raw_spin_unlock_bh(a1 + 42100);
      if ( a2 <= 0x13 )
      {
        v39 = (unsigned int)(1 << a2);
        if ( (v39 & 0x6542C) != 0 )
        {
          if ( a3 > 0x11 )
            goto LABEL_93;
          v49 = a1 + 16LL * a3;
          v50 = 51748;
        }
        else
        {
          if ( (v39 & 0x9A812) == 0 )
            goto LABEL_83;
          if ( a3 >= 0x12 )
            goto LABEL_93;
          v49 = a1 + 16LL * a3;
          v50 = 51744;
        }
        ++*(_DWORD *)(v49 + v50);
      }
LABEL_83:
      v39 = jiffies;
      if ( (unsigned int)v16 <= 0x18 )
      {
        if ( a3 <= 8 )
          v51 = (int *)(a1 + 42092);
        else
          v51 = (int *)(a1 + 42096);
        v52 = *v51;
        *(_QWORD *)(a1 + 384LL * (unsigned int)v16 + 42144) = jiffies;
        v39 = *(_QWORD *)(a1 + 32);
        *(_WORD *)(a1 + 384LL * (unsigned int)v16 + 42152) = a2;
        *(_WORD *)(a1 + 384LL * (unsigned int)v16 + 42154) = a3;
        *(_DWORD *)(a1 + 384LL * (unsigned int)v16 + 42156) = v52;
        if ( !*(_DWORD *)(v39 + 1096) )
          return result;
        v53 = 0;
        v54 = 336;
        while ( v53 != 46 )
        {
          v55 = *(_QWORD *)(*(_QWORD *)(v39 + 24) + v54);
          v54 += 384;
          *(_QWORD *)(a1 + 384LL * (unsigned int)v16 + 42160 + 8 * v53++) = v55;
          if ( v53 >= *(unsigned int *)(v39 + 1096) )
            return result;
        }
      }
LABEL_93:
      __break(0x5512u);
LABEL_94:
      _X8 = (unsigned __int64 *)(v39 + 336);
      __asm { PRFM            #0x11, [X8] }
      do
        v64 = __ldxr(_X8);
      while ( __stxr(v64 | 1, _X8) );
      wlan_hdd_update_txq_timestamp(*(_QWORD *)(a1 + 32));
LABEL_50:
      if ( a3 == 12 )
      {
        wlan_hdd_update_pause_time(a1);
        *(_DWORD *)(a1 + 42096) |= 0x1000u;
      }
      else
      {
        v45 = *(_QWORD *)(a1 + 42128);
        v46 = *v15;
        v47 = jiffies - *(_QWORD *)(a1 + 42112);
        *(_QWORD *)(a1 + 42112) = jiffies;
        *(_QWORD *)(a1 + 42128) = v47 + v45;
        *v15 = v46 | (1 << a3);
      }
    }
  }
  return qdf_trace_msg(
           0x33u,
           2u,
           "%s: adapter is invalid",
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           "wlan_hdd_netif_queue_control");
}
