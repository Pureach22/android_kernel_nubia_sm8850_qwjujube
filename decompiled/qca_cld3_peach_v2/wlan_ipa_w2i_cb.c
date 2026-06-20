__int64 __fastcall wlan_ipa_w2i_cb(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  __int64 v18; // x8
  unsigned int v19; // w21
  unsigned __int64 v20; // x22
  __int64 v21; // x1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x25
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x22
  __int64 v40; // x21
  const void *v41; // x22
  char v42; // w23
  _QWORD *vdev_by_macaddr_from_psoc; // x0
  __int64 v44; // x22
  __int64 v45; // x8
  __int64 v46; // x23
  __int64 *v47; // x21
  __int64 v48; // x9
  int v49; // w8
  __int16 v50; // w9
  __int64 v51; // x0
  __int64 v52; // x8
  void (*v53)(void); // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _BOOL4 is_ipv4_wapi_pkt; // w22
  __int64 v63; // x8
  __int64 (*v64)(void); // x8
  unsigned __int64 v65; // x4
  __int64 v66; // x23
  __int64 v67; // x22
  __int64 v68; // x22
  unsigned __int64 v69; // x8
  __int64 v70; // x8
  __int64 v71; // x20
  unsigned __int64 StatusReg; // x8
  __int64 *v73; // x8
  __int64 v74; // x22
  unsigned int *v75; // x8
  _QWORD *v76; // x23
  __int64 v77; // x22
  __int64 v78; // x22
  __int64 v79; // x23
  unsigned __int8 *v80; // x8
  __int64 v81; // x5
  __int64 v82; // x6
  __int64 v83; // x7
  void (__fastcall *v84)(__int64, __int64); // x8
  _QWORD *v85; // x21
  __int64 v86; // x1
  unsigned int *v87; // x8
  __int64 v88; // x9
  int v89; // w9
  __int64 v90; // x8
  void (__fastcall *v91)(__int64, __int64); // x8
  __int64 v92; // x1
  int v93; // [xsp+10h] [xbp-10h] BYREF
  __int16 v94; // [xsp+14h] [xbp-Ch]
  __int64 v95; // [xsp+18h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _qdf_op_protect();
  if ( (_DWORD)result )
  {
    if ( !a2 )
    {
      ++*(_QWORD *)(a1 + 4152);
      result = dev_kfree_skb_any_reason(a3, 1);
    }
    goto LABEL_90;
  }
  v94 = 0;
  v93 = 0;
  if ( !a1 )
  {
    if ( a2 )
    {
LABEL_89:
      result = _qdf_op_unprotect();
LABEL_90:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_88:
    dev_kfree_skb_any_reason(a3, 1);
    goto LABEL_89;
  }
  if ( a2 )
  {
    v17 = jiffies;
    if ( _wlan_ipa_w2i_cb___last_ticks_290 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: w2i cb wrong event: 0x%x",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "__wlan_ipa_w2i_cb",
        a2);
      _wlan_ipa_w2i_cb___last_ticks_290 = v17;
    }
    goto LABEL_89;
  }
  if ( (**(_BYTE **)(a1 + 1464) & 0x20) != 0 )
  {
    v20 = *(unsigned __int8 *)(a3 + 40);
    if ( v20 >= 5 )
      goto LABEL_120;
    v19 = *(unsigned __int8 *)(a1 + v20 + 7288);
    v21 = 0;
    ++*(_QWORD *)(a1 + 3664);
  }
  else
  {
    v18 = *(_QWORD *)(a3 + 40);
    v19 = *(unsigned __int8 *)(*(_QWORD *)(a3 + 224) + 2LL);
    if ( v18 )
      *(_QWORD *)(a3 + 40) = v18 + 4;
    LODWORD(v20) = 255;
    v21 = 4;
  }
  skb_pull(a3, v21);
  if ( v19 >= 3 )
  {
    v30 = jiffies;
    if ( _wlan_ipa_w2i_cb___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Invalid iface_id %u,session_id %x %x %x %x",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__wlan_ipa_w2i_cb",
        v19,
        (unsigned int)v20,
        *(unsigned __int8 *)(a3 + 41),
        *(unsigned __int8 *)(a3 + 42),
        *(unsigned __int8 *)(a3 + 43),
        0);
      _wlan_ipa_w2i_cb___last_ticks = v30;
    }
    if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a3 + 224)) )
    {
      v39 = jiffies;
      if ( _wlan_ipa_w2i_cb___last_ticks_278 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: EAPOL pkt. Sending to NW!",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "__wlan_ipa_w2i_cb");
        _wlan_ipa_w2i_cb___last_ticks_278 = v39;
      }
      v40 = *(_QWORD *)a1;
      if ( *(_BYTE *)(*(_QWORD *)a1 + 49LL) )
      {
        v41 = *(const void **)(a3 + 224);
        v42 = 0;
        while ( 1 )
        {
          vdev_by_macaddr_from_psoc = wlan_objmgr_get_vdev_by_macaddr_from_psoc(v40, v42, v41, 0x25u);
          if ( vdev_by_macaddr_from_psoc )
            break;
          if ( *(unsigned __int8 *)(v40 + 49) <= (unsigned int)(unsigned __int8)++v42 )
            goto LABEL_26;
        }
        if ( !*((_DWORD *)vdev_by_macaddr_from_psoc + 4) )
        {
          *(_QWORD *)(a3 + 96) = wlan_ipa_uc_rt_debug_destructor;
          v84 = *(void (__fastcall **)(__int64, __int64))(a1 + 7368);
          if ( v84 )
          {
            v85 = vdev_by_macaddr_from_psoc;
            v86 = *(_QWORD *)(*(_QWORD *)vdev_by_macaddr_from_psoc[85] + 32LL);
            if ( *((_DWORD *)v84 - 1) != -1095694526 )
              __break(0x8228u);
            v84(a3, v86);
            vdev_by_macaddr_from_psoc = v85;
          }
          v87 = (unsigned int *)(*(_QWORD *)(a1 + 4144) + 1LL);
          v88 = *(_QWORD *)(a1 + 3672) + 1LL;
          *(_QWORD *)(a1 + 4144) = v87;
          *(_QWORD *)(a1 + 3672) = v88;
          wlan_objmgr_vdev_release_ref(
            (__int64)vdev_by_macaddr_from_psoc,
            0x25u,
            v87,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38);
          goto LABEL_89;
        }
        v74 = jiffies;
        v75 = (unsigned int *)(wlan_ipa_send_sta_eapol_to_nw___last_ticks_293 - jiffies);
        if ( wlan_ipa_send_sta_eapol_to_nw___last_ticks_293 - jiffies + 125 < 0 )
        {
          v76 = vdev_by_macaddr_from_psoc;
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: device_mode is not STA",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "wlan_ipa_send_sta_eapol_to_nw");
          vdev_by_macaddr_from_psoc = v76;
          wlan_ipa_send_sta_eapol_to_nw___last_ticks_293 = v74;
        }
        wlan_objmgr_vdev_release_ref(
          (__int64)vdev_by_macaddr_from_psoc,
          0x25u,
          v75,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38);
      }
      else
      {
LABEL_26:
        v44 = jiffies;
        if ( wlan_ipa_send_sta_eapol_to_nw___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: Invalid vdev",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "wlan_ipa_send_sta_eapol_to_nw");
          wlan_ipa_send_sta_eapol_to_nw___last_ticks = v44;
        }
      }
    }
    v77 = jiffies;
    if ( _wlan_ipa_w2i_cb___last_ticks_280 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x61u, 2u, "%s: Pkt Dropped!", v31, v32, v33, v34, v35, v36, v37, v38, "__wlan_ipa_w2i_cb");
      _wlan_ipa_w2i_cb___last_ticks_280 = v77;
    }
    goto LABEL_87;
  }
  v45 = a1 + ((unsigned __int64)v19 << 7);
  if ( *(unsigned __int8 *)(v45 + 1116) >= 5u )
  {
    v46 = jiffies;
    if ( _wlan_ipa_w2i_cb___last_ticks_282 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: session_id of iface_id %u is invalid:%d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__wlan_ipa_w2i_cb",
        v19);
      _wlan_ipa_w2i_cb___last_ticks_282 = v46;
    }
LABEL_87:
    ++*(_QWORD *)(a1 + 4152);
    goto LABEL_88;
  }
  v47 = (__int64 *)(v45 + 1064);
  v48 = *(_QWORD *)(v45 + 1176);
  v49 = *(_DWORD *)(v45 + 1096);
  v47[14] = v48 + 1;
  if ( v49 == 1 )
  {
    qdf_mem_copy(&v93, (const void *)(*(_QWORD *)(a3 + 224) + 6LL), 6u);
  }
  else if ( !v49 )
  {
    v50 = *((_WORD *)v47 + 62);
    v93 = *((_DWORD *)v47 + 30);
    v94 = v50;
  }
  v51 = *(_QWORD *)(a1 + 1456);
  if ( v51 && *(_QWORD *)v51 && (v52 = *(_QWORD *)(*(_QWORD *)v51 + 152LL)) != 0 )
  {
    v53 = *(void (**)(void))(v52 + 80);
    if ( v53 )
    {
      if ( *((_DWORD *)v53 - 1) != 1073489957 )
        __break(0x8228u);
      v53();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "cdp_ipa_update_peer_rx_stats");
  }
  if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a3 + 224)) )
  {
    if ( *((_DWORD *)v47 + 8) == 1
      && (wlan_ipa_eapol_intrabss_fwd_check(a1, *((unsigned __int8 *)v47 + 52), a3) & 1) == 0 )
    {
      v79 = jiffies;
      if ( _wlan_ipa_w2i_cb___last_ticks_284 - jiffies + 125 < 0 )
      {
        v80 = *(unsigned __int8 **)(a3 + 224);
        if ( v80 )
        {
          v81 = *v80;
          v82 = v80[1];
          v83 = v80[2];
          LODWORD(v80) = v80[5];
        }
        else
        {
          v83 = 0;
          v81 = 0;
          v82 = 0;
        }
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: id %u EAPOL intrabss fwd drop DA: %02x:%02x:%02x:**:**:%02x",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "__wlan_ipa_w2i_cb",
          *((unsigned __int8 *)v47 + 52),
          v81,
          v82,
          v83,
          (_DWORD)v80,
          0);
        _wlan_ipa_w2i_cb___last_ticks_284 = v79;
      }
      goto LABEL_87;
    }
    is_ipv4_wapi_pkt = 1;
  }
  else
  {
    is_ipv4_wapi_pkt = _qdf_nbuf_is_ipv4_wapi_pkt(a3);
  }
  result = *(_QWORD *)(a1 + 1456);
  if ( result && *(_QWORD *)result && (v63 = *(_QWORD *)(*(_QWORD *)result + 72LL)) != 0 )
  {
    v64 = *(__int64 (**)(void))(v63 + 80);
    if ( v64 )
    {
      if ( *((_DWORD *)v64 - 1) != -223539710 )
        __break(0x8228u);
      result = v64();
      LODWORD(v64) = result == 3;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               1u,
               "%s invalid instance",
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               v60,
               v61,
               "cdp_peer_state_get");
    LODWORD(v64) = 0;
  }
  if ( ((is_ipv4_wapi_pkt | (unsigned int)v64) & 1) == 0 )
  {
    v66 = jiffies;
    if ( _wlan_ipa_w2i_cb___last_ticks_286 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Non EAPOL/WAPI packet received when peer %02x:%02x:%02x:**:**:%02x is unauthorized on id %u",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "__wlan_ipa_w2i_cb",
        (unsigned __int8)v93,
        BYTE1(v93),
        BYTE2(v93),
        HIBYTE(v94),
        *((unsigned __int8 *)v47 + 52),
        0);
      _wlan_ipa_w2i_cb___last_ticks_286 = v66;
    }
    goto LABEL_87;
  }
  v65 = *((unsigned __int8 *)v47 + 52);
  if ( v65 <= 4 )
  {
    if ( (*(_BYTE *)(a1 + v65 + 7352) & 1) != 0 || *((_DWORD *)v47 + 8) != 1 )
    {
      v67 = jiffies;
      if ( _wlan_ipa_w2i_cb___last_ticks_288 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: Intra-BSS fwd disabled for session_id %u",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "__wlan_ipa_w2i_cb");
        _wlan_ipa_w2i_cb___last_ticks_288 = v67;
      }
    }
    else if ( (unsigned int)wlan_ipa_rx_intrabss_fwd(a1, v47, a3) == 2 )
    {
      goto LABEL_89;
    }
    a1 = *v47;
    if ( !v47[3] )
    {
      v78 = jiffies;
      if ( wlan_ipa_send_skb_to_network___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: Invalid interface",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "wlan_ipa_send_skb_to_network");
        wlan_ipa_send_skb_to_network___last_ticks = v78;
      }
      goto LABEL_87;
    }
    *(_QWORD *)(a3 + 96) = wlan_ipa_uc_rt_debug_destructor;
    v68 = *v47;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v69 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v69 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v68 + 3360);
      v70 = *(_QWORD *)(v68 + 3368);
      if ( (*(_BYTE *)(v68 + 3376) & 1) != 0 )
        goto LABEL_71;
    }
    else
    {
      raw_spin_lock_bh(v68 + 3360);
      v70 = *(_QWORD *)(v68 + 3368) | 1LL;
      *(_QWORD *)(v68 + 3368) = v70;
      if ( (*(_BYTE *)(v68 + 3376) & 1) != 0 )
      {
LABEL_71:
        if ( (v70 & 1) != 0 )
        {
          *(_QWORD *)(v68 + 3368) = v70 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v68 + 3360);
        }
        else
        {
          raw_spin_unlock(v68 + 3360);
        }
        if ( *((_DWORD *)v47 + 8) == 1 && _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a3 + 224)) )
        {
          v71 = *v47;
          qdf_mem_set((void *)(a3 + 40), 0x30u, 0);
          *(_QWORD *)(a3 + 48) = v47;
          *(_BYTE *)(a3 + 64) = 1;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v71 + 3360);
          }
          else
          {
            raw_spin_lock_bh(v71 + 3360);
            *(_QWORD *)(v71 + 3368) |= 1uLL;
          }
          *(_QWORD *)a3 = 0;
          if ( *(_QWORD *)(v71 + 3288) )
            v73 = *(__int64 **)(v71 + 3296);
          else
            v73 = (__int64 *)(v71 + 3288);
          *v73 = a3;
          v89 = *(_DWORD *)(v71 + 3304);
          v90 = *(_QWORD *)(v71 + 3368);
          *(_QWORD *)(v71 + 3296) = a3;
          *(_DWORD *)(v71 + 3304) = v89 + 1;
          if ( (v90 & 1) != 0 )
          {
            *(_QWORD *)(v71 + 3368) = v90 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v71 + 3360);
          }
          else
          {
            raw_spin_unlock(v71 + 3360);
          }
          ++*(_QWORD *)(v71 + 3640);
          goto LABEL_89;
        }
        goto LABEL_111;
      }
    }
    if ( (v70 & 1) != 0 )
    {
      *(_QWORD *)(v68 + 3368) = v70 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v68 + 3360);
      v91 = *(void (__fastcall **)(__int64, __int64))(a1 + 7368);
      if ( v91 )
        goto LABEL_112;
      goto LABEL_115;
    }
    raw_spin_unlock(v68 + 3360);
LABEL_111:
    v91 = *(void (__fastcall **)(__int64, __int64))(a1 + 7368);
    if ( v91 )
    {
LABEL_112:
      v92 = v47[3];
      if ( *((_DWORD *)v91 - 1) != -1095694526 )
        __break(0x8228u);
      v91(a3, v92);
    }
LABEL_115:
    ++*(_QWORD *)(a1 + 4144);
    goto LABEL_89;
  }
LABEL_120:
  __break(0x5512u);
  return wlan_ipa_eapol_intrabss_fwd_check(result, v7, v8);
}
