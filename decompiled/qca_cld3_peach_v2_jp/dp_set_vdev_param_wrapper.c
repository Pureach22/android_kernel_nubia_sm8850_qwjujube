__int64 __fastcall dp_set_vdev_param_wrapper(__int64 a1, unsigned __int8 a2, unsigned int a3, __int64 *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x21
  _BYTE *v11; // x24
  unsigned int v12; // w8
  unsigned int v19; // w10
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 result; // x0
  unsigned int v30; // w23
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  unsigned int v41; // w22
  __int64 v42; // x8
  const char *v43; // x2
  const char *v44; // x3
  __int64 v45; // x4
  __int64 v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _DWORD *v55; // x8
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x4
  const char *v75; // x3
  unsigned int v78; // w9
  __int64 v79; // x8
  __int64 v80; // [xsp+28h] [xbp-38h] BYREF
  __int64 v81; // [xsp+30h] [xbp-30h]
  __int64 v82; // [xsp+38h] [xbp-28h]
  _QWORD v83[4]; // [xsp+40h] [xbp-20h] BYREF

  v83[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a4;
  v5 = a4[1];
  v82 = a4[2];
  v80 = v4;
  v81 = v5;
  if ( a2 > 5u )
  {
    result = 16;
    goto LABEL_62;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18928);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18928);
    *(_QWORD *)(a1 + 18936) |= 1uLL;
  }
  v10 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
  if ( !v10 )
  {
LABEL_20:
    v28 = *(_QWORD *)(a1 + 18936);
    if ( (v28 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v28 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
    result = 16;
    goto LABEL_62;
  }
  v11 = (_BYTE *)(v10 + 42424);
  v12 = *(_DWORD *)(v10 + 42560);
  do
  {
    if ( !v12 )
      goto LABEL_20;
    _X12 = (unsigned int *)(v10 + 42560);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v19 = __ldxr(_X12);
      if ( v19 != v12 )
        break;
      if ( !__stlxr(v12 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v19 == v12;
    v12 = v19;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v10 + 42592);
  __asm { PRFM            #0x11, [X8] }
  do
    v78 = __ldxr(_X8);
  while ( __stxr(v78 + 1, _X8) );
  v79 = *(_QWORD *)(a1 + 18936);
  if ( (v79 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 18928);
LABEL_18:
    switch ( a3 )
    {
      case 0u:
        *(_BYTE *)(v10 + 56) = v80;
        goto LABEL_59;
      case 1u:
        *(_BYTE *)(v10 + 57) = v80;
        goto LABEL_59;
      case 2u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: wds_enable %d for vdev(%pK) id(%d)",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v80,
          v10,
          *(unsigned __int8 *)(v10 + 59));
        *(_BYTE *)(v10 + 48) = v80;
        goto LABEL_59;
      case 3u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: mec_enable %d for vdev(%pK) id(%d)",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v80,
          v10,
          *(unsigned __int8 *)(v10 + 59));
        *(_BYTE *)(v10 + 49) = v80;
        goto LABEL_59;
      case 4u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: da_war_enable %d for vdev(%pK) id(%d)",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v80,
          v10,
          *(unsigned __int8 *)(v10 + 59));
        *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL) + 18650LL) = v80;
        dp_wds_flush_ast_table_wifi3(*(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL));
        goto LABEL_59;
      case 5u:
        *v11 = *v11 & 0xFE | v80;
        goto LABEL_59;
      case 6u:
        *(_BYTE *)(v10 + 320) = v80;
        goto LABEL_59;
      case 7u:
        if ( (_DWORD)v80 )
        {
          if ( (_DWORD)v80 != *(_DWORD *)(v10 + 52) )
            qdf_timer_mod_0(*(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL) + 17592LL, v80);
        }
        else
        {
          timer_delete((timer_t)(*(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL) + 17592LL));
        }
        *(_DWORD *)(v10 + 52) = v80;
        goto LABEL_59;
      case 8u:
        if ( *(_DWORD *)(v10 + 32) == 3 )
          *(_BYTE *)(v10 + 42440) = 0;
        else
          *(_BYTE *)(v10 + 42440) = v80;
        goto LABEL_59;
      case 9u:
        *(_DWORD *)(v10 + 42444) = v80;
        goto LABEL_59;
      case 0xAu:
        *v11 = *v11 & 0xFB | (4 * v80);
        goto LABEL_59;
      case 0xBu:
        v43 = "%s: vdev %d Multipass enable %d";
        v44 = "dp_set_vdev_param";
        v45 = a2;
        *(_BYTE *)(v10 + 80) = v80;
        goto LABEL_39;
      case 0xCu:
        *(_DWORD *)(v10 + 40) = v80;
        goto LABEL_59;
      case 0xDu:
        *(_DWORD *)(v10 + 44) = v80;
        goto LABEL_59;
      case 0xFu:
        *(_BYTE *)(v10 + 42458) = v80;
        goto LABEL_59;
      case 0x10u:
        *(_BYTE *)(v10 + 42449) = v80;
        goto LABEL_59;
      case 0x13u:
        *(_BYTE *)(v10 + 58) = v80;
        goto LABEL_59;
      case 0x14u:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d enable hlod tid override %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v80);
        qdf_trace_msg(
          0x89u,
          5u,
          "%s: %pK: val %d",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "dp_vdev_set_hlos_tid_override",
          *(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL),
          (unsigned __int8)v80);
        *(_BYTE *)(v10 + 74) = *(_BYTE *)(v10 + 74) & 0xFD | (2 * ((_BYTE)v80 != 0));
        goto LABEL_59;
      case 0x15u:
        *(_BYTE *)(v10 + 75) = v80;
        goto LABEL_59;
      case 0x1Au:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d drop 3 addr mcast :%d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v80);
        *(_BYTE *)(v10 + 50) = v80;
        goto LABEL_59;
      case 0x1Bu:
        *v11 = *v11 & 0xFD | (2 * v80);
        goto LABEL_59;
      case 0x1Cu:
        *(_BYTE *)(v10 + 45318) = v80;
        goto LABEL_59;
      case 0x1Du:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d to_fw :%d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v80);
        *(_BYTE *)(v10 + 45344) = v80;
        goto LABEL_59;
      case 0x1Eu:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: set mac addr, old mac addr%02x:%02x:%02x:**:**:%02x new mac addr: %02x:%02x:%02x:**:**:%02x for vdev %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          *(unsigned __int8 *)(v10 + 96),
          *(unsigned __int8 *)(v10 + 97),
          *(unsigned __int8 *)(v10 + 98),
          *(unsigned __int8 *)(v10 + 101),
          (unsigned __int8)v80,
          BYTE1(v80),
          BYTE2(v80),
          BYTE5(v80),
          *(unsigned __int8 *)(v10 + 59));
        qdf_mem_copy((void *)(v10 + 96), &v80, 6u);
        goto LABEL_59;
      case 0x1Fu:
        v46 = *(_QWORD *)(v10 + 42696);
        if ( !v46 )
        {
          v74 = *(unsigned __int8 *)(v10 + 59);
          v75 = "dp_monitor_set_chan_num";
          goto LABEL_69;
        }
        v43 = "%s: vdev_id %d channel number: %d";
        v44 = "dp_monitor_set_chan_num";
        *(_DWORD *)(v46 + 8) = v80;
        v45 = *(unsigned __int8 *)(v10 + 59);
LABEL_39:
        qdf_trace_msg(0x45u, 5u, v43, v20, v21, v22, v23, v24, v25, v26, v27, v44, v45);
        goto LABEL_59;
      case 0x20u:
        v30 = v80;
        v31 = wlan_reg_freq_to_band(v80);
        v40 = *(_QWORD *)(v10 + 42696);
        v41 = v31;
        if ( v40 )
        {
          *(_DWORD *)(v40 + 12) = v80;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: vdev_id %d freq: %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "dp_monitor_set_chan_freq",
            *(unsigned __int8 *)(v10 + 59),
            v30);
          v42 = *(_QWORD *)(v10 + 42696);
          if ( v42 )
          {
LABEL_28:
            *(_DWORD *)(v42 + 16) = v41;
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: vdev_id %d ch band: %d",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "dp_monitor_set_chan_band",
              *(unsigned __int8 *)(v10 + 59),
              v41);
            goto LABEL_59;
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: mon vdev is null for vdev %u",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "dp_monitor_set_chan_freq",
            *(unsigned __int8 *)(v10 + 59));
          v42 = *(_QWORD *)(v10 + 42696);
          if ( v42 )
            goto LABEL_28;
        }
        v74 = *(unsigned __int8 *)(v10 + 59);
        v75 = "dp_monitor_set_chan_band";
LABEL_69:
        qdf_trace_msg(0x45u, 2u, "%s: mon vdev is null for vdev %u", v20, v21, v22, v23, v24, v25, v26, v27, v75, v74);
        goto LABEL_59;
      case 0x21u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: eapol_over_control_port_disable %d for vdev(%pK) id(%d)",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v80,
          v10,
          *(unsigned __int8 *)(v10 + 59));
        *(_BYTE *)(v10 + 45376) = v80;
        goto LABEL_59;
      default:
        goto LABEL_59;
    }
  }
  *(_QWORD *)(a1 + 18936) = v79 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 18928);
  if ( a3 <= 0x21 )
    goto LABEL_18;
LABEL_59:
  dp_tx_vdev_update_search_flags(v10);
  v83[0] = v80;
  v83[1] = v81;
  v55 = *(_DWORD **)(a1 + 1448);
  v83[2] = v82;
  if ( *(v55 - 1) != 608967745 )
    __break(0x8228u);
  v56 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD *))v55)(a1, v10, a3, v83);
  dp_pdev_update_fast_rx_flag(v57, v58, v59, v60, v61, v62, v63, v64, v56, *(_QWORD *)(v10 + 24));
  dp_vdev_unref_delete(a1, v10, 7u, v65, v66, v67, v68, v69, v70, v71, v72, v73);
  result = 0;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
