__int64 __fastcall wlan_ipa_uc_op_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  __int64 v22; // x1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  __int64 v48; // x8
  void (*v49)(void); // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w4
  int v68; // w5
  int v69; // w6
  int v70; // w7
  unsigned int v71; // w22
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x1
  char v81; // w9
  __int64 v82; // x0
  __int64 v83; // x1
  int v84; // w3
  int v85; // w4
  int v86; // w5
  int v87; // w6
  int v88; // w7
  __int64 v89; // x0
  int v90; // w3
  int v91; // w4
  int v92; // w5
  int v93; // w6
  int v94; // w7
  char v95; // w8
  int v96; // w8
  __int64 v97; // x22
  char v99; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
    return qdf_trace_msg(0x61u, 2u, "%s: INVALID ARG", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_op_cb");
  if ( *(unsigned __int16 *)(a1 + 2) < 0x10u )
  {
    qdf_trace_msg(0x61u, 8u, "%s: OPCODE=%d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_op_cb");
    v21 = *(unsigned __int16 *)(a1 + 2);
    if ( v21 <= 8 )
    {
      if ( *(unsigned __int16 *)(a1 + 2) > 2u )
      {
        if ( v21 != 3 )
        {
          if ( v21 == 4 )
          {
            v96 = *(_DWORD *)(a2 + 4120);
            if ( v96 != 2 )
            {
              if ( v96 == 1 )
                wlan_ipa_print_fw_wdi_stats(a2, a1 + 32);
              return _qdf_mem_free(a1);
            }
            qdf_mutex_acquire(a2 + 7224);
            v89 = a2 + 7224;
            *(_DWORD *)(a2 + 4104) = *(_DWORD *)(a1 + 56) - *(_DWORD *)(a2 + 4112);
            *(_DWORD *)(a2 + 4108) = *(_DWORD *)(a1 + 108)
                                   - *(_DWORD *)(a2 + 4116)
                                   + *(_DWORD *)(a1 + 112)
                                   + *(_DWORD *)(a1 + 100);
            *(_DWORD *)(a2 + 4112) = *(_DWORD *)(a1 + 56);
            *(_DWORD *)(a2 + 4116) = *(_DWORD *)(a1 + 112) + *(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 100);
            goto LABEL_58;
          }
          if ( v21 != 8 )
            return _qdf_mem_free(a1);
          qdf_mutex_acquire(a2 + 7224);
          wlan_ipa_uc_loaded_handler(a2);
          goto LABEL_57;
        }
      }
      else if ( !*(_WORD *)(a1 + 2) || v21 != 1 )
      {
        qdf_mutex_acquire(a2 + 7224);
        if ( *(_WORD *)(a1 + 2) == 2 )
        {
          wlan_ipa_uc_disable_pipes(a2, 1, v23, v24, v25, v26, v27, v28, v29, v30);
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: Disable FW TX PIPE",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "wlan_ipa_uc_op_cb");
          v47 = *(_QWORD *)(a2 + 1456);
          if ( v47 && *(_QWORD *)v47 && (v48 = *(_QWORD *)(*(_QWORD *)v47 + 152LL)) != 0 )
          {
            v49 = *(void (**)(void))(v48 + 24);
            if ( v49 )
            {
              if ( *((_DWORD *)v49 - 1) != 193190764 )
                __break(0x8228u);
              v49();
            }
          }
          else
          {
            qdf_trace_msg(
              0x45u,
              1u,
              "%s invalid instance",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "cdp_ipa_set_active");
          }
        }
        if ( --*(_BYTE *)(a2 + 3704) != 0 )
          goto LABEL_57;
        *(_BYTE *)(a2 + 3721) = 0;
        qdf_event_set(a2 + 7392, v22);
        v82 = a2;
        v83 = 0;
        goto LABEL_56;
      }
      qdf_mutex_acquire(a2 + 7224);
      v81 = *(_BYTE *)(a2 + 3440);
      ++*(_BYTE *)(a2 + 3704);
      if ( (v81 & 1) == 0 )
      {
        *(_BYTE *)(a2 + 3720) = 0;
        qdf_event_set(a2 + 7392, v80);
        if ( (*(_BYTE *)(a2 + 6985) & 1) == 0 )
          *(_BYTE *)(a2 + 6985) = 1;
        v82 = a2;
        v83 = 1;
LABEL_56:
        wlan_ipa_uc_proc_pending_event(v82, v83);
        *(_BYTE *)(a2 + 3722) = 0;
      }
LABEL_57:
      v89 = a2 + 7224;
      goto LABEL_58;
    }
    if ( *(unsigned __int16 *)(a1 + 2) > 0xBu )
    {
      if ( v21 != 12 )
      {
        if ( v21 != 13 )
        {
          if ( v21 == 14
            && (((__int64 (__fastcall *)(__int64, _QWORD))wlan_ipa_opt_dp_ctrl_flt_add_status)(
                  a2,
                  *(unsigned int *)(a1 + 24))
              & 1) != 0
            && (*(_BYTE *)(a2 + 7512) & 1) == 0 )
          {
            qdf_trace_msg(
              0x61u,
              4u,
              "%s: opt_dp_ctrl: IPA notify filter del response: %d, hdl: %d",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "wlan_ipa_uc_op_cb",
              *(unsigned __int16 *)(a1 + 6),
              *(unsigned int *)(a1 + 24));
            wlan_ipa_log_message(
              (int)"wlan_ipa_uc_op_cb",
              (int)"opt_dp_ctrl: IPA notify filter del response: %d, hdl: %d",
              *(unsigned __int16 *)(a1 + 6),
              *(_DWORD *)(a1 + 24),
              v67,
              v68,
              v69,
              v70,
              v99);
            qdf_mutex_acquire(a2 + 7224);
            v71 = ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst(
                    *(unsigned int *)(a2 + 7460),
                    *(unsigned int *)(a1 + 24),
                    *(unsigned __int16 *)(a1 + 6));
            qdf_mutex_release(a2 + 7224);
            qdf_trace_msg(
              0x61u,
              8u,
              "%s: opt_dp_ctrl: return status for handle %d: %d",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "wlan_ipa_uc_op_cb",
              *(unsigned int *)(a1 + 24),
              v71);
          }
          return _qdf_mem_free(a1);
        }
        v97 = jiffies;
        if ( wlan_ipa_uc_op_cb___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: opt_dp_ctrl: handle opt_dp_ctrl tx pkt",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "wlan_ipa_uc_op_cb");
          wlan_ipa_uc_op_cb___last_ticks = v97;
        }
        qdf_mutex_acquire(a2 + 7224);
        cdp_ipa_tx_opt_dp_ctrl_pkt(*(_QWORD *)(a2 + 1456), *(unsigned __int8 *)(a1 + 8), *(_QWORD *)(a1 + 16));
        goto LABEL_57;
      }
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: opt_dp: IPA smmu pool unmap",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_ipa_uc_op_cb");
      qdf_mutex_acquire(a2 + 7224);
      v58 = *(_QWORD *)(a2 + 1456);
    }
    else
    {
      if ( v21 == 9 )
      {
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: opt_dp: IPA notify filter resrv response: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_ipa_uc_op_cb",
          *(unsigned __int8 *)(a1 + 1));
        wlan_ipa_log_message(
          (int)"wlan_ipa_uc_op_cb",
          (int)"opt_dp: IPA notify filter resrv response: %d",
          *(unsigned __int8 *)(a1 + 1),
          v84,
          v85,
          v86,
          v87,
          v88,
          v99);
        qdf_mutex_acquire(a2 + 7224);
        ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst(*(unsigned int *)(a2 + 7460), *(_BYTE *)(a1 + 1) != 0);
        goto LABEL_57;
      }
      if ( v21 == 10 )
      {
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: opt_dp: IPA notify filter rel_response: %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_ipa_uc_op_cb",
          *(unsigned __int8 *)(a1 + 1));
        wlan_ipa_log_message(
          (int)"wlan_ipa_uc_op_cb",
          (int)"opt_dp: IPA notify filter rel_response: %d",
          *(unsigned __int8 *)(a1 + 1),
          v90,
          v91,
          v92,
          v93,
          v94,
          v99);
        if ( *(_BYTE *)(a1 + 1) )
          wlan_ipa_opt_dp_wait_for_completion(a2);
        qdf_mutex_acquire(a2 + 7224);
        ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst(*(unsigned int *)(a2 + 7460), *(_BYTE *)(a1 + 1) != 0);
        v89 = a2 + 7224;
        if ( *(_BYTE *)(a1 + 1) )
          v95 = 3;
        else
          v95 = 1;
        *(_BYTE *)(a2 + 7439) = v95;
        goto LABEL_58;
      }
      if ( v21 != 11 )
        return _qdf_mem_free(a1);
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: opt_dp: IPA smmu pool map",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_ipa_uc_op_cb");
      qdf_mutex_acquire(a2 + 7224);
      v58 = *(_QWORD *)(a2 + 1456);
    }
    cdp_ipa_rx_buf_smmu_pool_mapping(v58, v50, v51, v52, v53, v54, v55, v56, v57);
    v89 = a2 + 7224;
LABEL_58:
    qdf_mutex_release(v89);
    return _qdf_mem_free(a1);
  }
  qdf_trace_msg(0x61u, 2u, "%s: INVALID OPCODE %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_op_cb");
  return _qdf_mem_free(a1);
}
