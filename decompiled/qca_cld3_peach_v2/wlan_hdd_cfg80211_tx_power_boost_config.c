__int64 __fastcall wlan_hdd_cfg80211_tx_power_boost_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x4
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  const char *v37; // x3
  unsigned int v38; // w1
  char v39; // w8
  unsigned int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void *v49; // x0
  __int64 v50; // x20
  __int64 v51; // x21
  unsigned int v52; // w19
  int v53; // w8
  const char *v54; // x2
  const char *v55; // x3
  unsigned int v56; // w1
  unsigned int v57; // w0
  __int64 v58; // x20
  __int64 v59; // x21
  int v60; // w0
  const char *v61; // x2
  __int64 v62; // x20
  __int64 v63; // x20
  int v64; // w19
  int v65; // w8
  __int64 v66; // x0
  unsigned int v67; // w0
  __int64 v68; // x20
  __int64 v69; // x20
  __int64 *v70; // [xsp+0h] [xbp-130h] BYREF
  _QWORD v71[8]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v72; // [xsp+48h] [xbp-E8h] BYREF
  __int64 v73; // [xsp+50h] [xbp-E0h]
  __int64 v74; // [xsp+58h] [xbp-D8h]
  __int64 v75; // [xsp+60h] [xbp-D0h]
  __int64 v76; // [xsp+68h] [xbp-C8h]
  __int64 v77; // [xsp+70h] [xbp-C0h]
  __int64 v78; // [xsp+78h] [xbp-B8h]
  __int64 v79; // [xsp+80h] [xbp-B0h]
  __int64 v80; // [xsp+88h] [xbp-A8h]
  __int64 v81; // [xsp+90h] [xbp-A0h] BYREF
  __int64 v82; // [xsp+98h] [xbp-98h] BYREF
  __int64 v83; // [xsp+A0h] [xbp-90h]
  __int64 v84; // [xsp+A8h] [xbp-88h]
  __int64 v85; // [xsp+B0h] [xbp-80h]
  __int64 v86; // [xsp+B8h] [xbp-78h]
  __int64 v87; // [xsp+C0h] [xbp-70h]
  __int64 v88; // [xsp+C8h] [xbp-68h]
  __int64 v89; // [xsp+D0h] [xbp-60h]
  __int64 v90; // [xsp+D8h] [xbp-58h]
  __int64 v91; // [xsp+E0h] [xbp-50h]
  __int64 v92; // [xsp+E8h] [xbp-48h]
  __int64 v93; // [xsp+F0h] [xbp-40h]
  __int64 v94; // [xsp+F8h] [xbp-38h]
  __int64 v95; // [xsp+100h] [xbp-30h]
  __int64 v96; // [xsp+108h] [xbp-28h]
  __int64 v97; // [xsp+110h] [xbp-20h]
  __int64 v98; // [xsp+118h] [xbp-18h]
  __int64 v99; // [xsp+120h] [xbp-10h]
  __int64 v100; // [xsp+128h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v70 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v70, (__int64)"wlan_hdd_cfg80211_tx_power_boost_config");
  if ( (_DWORD)result )
    goto LABEL_20;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32) + 296LL;
    v98 = 0;
    v99 = 0;
    v96 = 0;
    v97 = 0;
    v94 = 0;
    v95 = 0;
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
    v88 = 0;
    v89 = 0;
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    v82 = 0;
    v83 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_tx_power_boost_config",
      v18);
    v27 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_tx_power_boost_config",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v27 )
    {
LABEL_19:
      v52 = v27;
      _osif_vdev_sync_op_stop((__int64)v70, (__int64)"wlan_hdd_cfg80211_tx_power_boost_config");
      result = v52;
LABEL_20:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (unsigned int)_nla_parse(&v82, 17, a3, a4, &qca_wlan_vendor_power_boost_policy, 31, 0) )
    {
      v36 = "%s: TPB: nla_parse failed for IQ DATA Inference";
      v37 = "__wlan_hdd_cfg80211_tx_power_boost_config";
      v38 = 2;
LABEL_18:
      qdf_trace_msg(0x33u, v38, v36, v28, v29, v30, v31, v32, v33, v34, v35, v37);
      v27 = -22;
      goto LABEL_19;
    }
    v39 = *(_BYTE *)(a1 + 10032);
    memset(v71, 0, sizeof(v71));
    if ( (v39 & 1) == 0 )
    {
      v36 = "%s: TPB: feature is not enabled";
      v37 = "hdd_tx_pb_configure";
      v38 = 3;
      goto LABEL_18;
    }
    if ( v83 )
    {
      v40 = *(_DWORD *)(v83 + 4);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: TPB: Inference cmd type: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_tx_pb_configure",
        v40);
      if ( v40 - 1 < 3 )
      {
        qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 10352));
        qdf_wake_lock_release(a1 + 10152, 0x20u);
        v49 = *(void **)(a1 + 10112);
        if ( v49 )
          qdf_mem_set(v49, *(unsigned int *)(a1 + 10144), 0);
        if ( v40 == 1 )
        {
          v60 = hdd_txpb_inference_app_stop(a1 + 1536, v71, v41, v42, v43, v44, v45, v46, v47, v48);
          if ( v60 )
          {
            v61 = "%s: TPB: Failed to send CMD_ABORT for APP_STOP";
LABEL_43:
            v64 = v60;
LABEL_56:
            qdf_trace_msg(0x33u, 2u, v61, v41, v42, v43, v44, v45, v46, v47, v48, "hdd_tx_pb_configure");
            v57 = v64;
            goto LABEL_57;
          }
          v54 = "%s: TPB: Send CMD_ABORT for APP_STOP successful";
        }
        else
        {
          if ( v40 != 2 )
          {
            v78 = 0;
            v79 = 0;
            v76 = 0;
            v77 = 0;
            v74 = 0;
            v75 = 0;
            v72 = 0;
            v73 = 0;
            if ( !v96 )
            {
              v63 = jiffies;
              if ( hdd_txpb_inference_cmd_failure___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: TPB: IQ_DATA_INFERENCE_COOKIE is not set",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  "hdd_txpb_inference_cmd_failure");
                hdd_txpb_inference_cmd_failure___last_ticks = v63;
              }
              goto LABEL_41;
            }
            v81 = 0;
            nla_memcpy(&v81, v96, 8);
            v50 = v81;
            if ( (unsigned int)hdd_txpb_req_dequeue(a1 + 1536, &v72, v81) )
            {
              v51 = jiffies;
              if ( hdd_txpb_inference_cmd_failure___last_ticks_67 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: TPB: Cookie: %llx didn't match",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  "hdd_txpb_inference_cmd_failure",
                  v50);
                hdd_txpb_inference_cmd_failure___last_ticks_67 = v51;
              }
LABEL_41:
              v60 = 4;
LABEL_42:
              v61 = "%s: TPB: Failed to send CMD_FAILURE";
              goto LABEL_43;
            }
            v60 = hdd_txpb_issue_app_stop_ready(a1 + 1536, (__int64)&v72, (__int64)"Fail_Init", (__int64)"CMD_FAILURE");
            if ( v60 )
              goto LABEL_42;
            v54 = "%s: TPB: Send CMD_FAILURE successful";
            goto LABEL_37;
          }
          v79 = 0;
          v80 = 0;
          v77 = 0;
          v78 = 0;
          v75 = 0;
          v76 = 0;
          v73 = 0;
          v74 = 0;
          v72 = 0;
          if ( !v96 )
          {
            v62 = jiffies;
            if ( hdd_txpb_inference_cmd___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: TPB: IQ_DATA_INFERENCE_COOKIE is not set",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "hdd_txpb_inference_cmd");
              hdd_txpb_inference_cmd___last_ticks = v62;
            }
            goto LABEL_54;
          }
          v81 = 0;
          nla_memcpy(&v81, v96, 8);
          v58 = v81;
          if ( (unsigned int)hdd_txpb_req_dequeue(a1 + 1536, &v72, v81) )
          {
            v59 = jiffies;
            if ( hdd_txpb_inference_cmd___last_ticks_76 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: TPB: Cookie: %llx didn't match",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "hdd_txpb_inference_cmd",
                v58);
              hdd_txpb_inference_cmd___last_ticks_76 = v59;
            }
LABEL_54:
            v64 = 4;
            goto LABEL_55;
          }
          if ( !v91 )
          {
            v68 = jiffies;
            if ( hdd_txpb_inference_cmd___last_ticks_77 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: TPB: IQ_DATA_INFERENCE_EVM is not set",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "hdd_txpb_inference_cmd");
              hdd_txpb_inference_cmd___last_ticks_77 = v68;
            }
            goto LABEL_54;
          }
          LODWORD(v80) = *(_DWORD *)(v91 + 4);
          if ( !v92 )
          {
            v69 = jiffies;
            if ( hdd_txpb_inference_cmd___last_ticks_79 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: TPB: IQ_DATA_INFERENCE_MASK_MARGIN is not set",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "hdd_txpb_inference_cmd");
              hdd_txpb_inference_cmd___last_ticks_79 = v69;
            }
            goto LABEL_54;
          }
          v65 = *(_DWORD *)(v92 + 4);
          v66 = *(_QWORD *)(a1 + 1544);
          HIDWORD(v74) = 1;
          HIDWORD(v80) = v65;
          v67 = ucfg_reg_txpb_send_inference_cmd(v66, v41, v42, v43, v44, v45, v46, v47, v48);
          if ( v67 )
          {
            v64 = v67;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: TPB: sme_txpb_send_inference_cmd failed: %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "hdd_txpb_inference_cmd",
              v67);
LABEL_55:
            v61 = "%s: TPB: Failed to send CMD_ESTIMATED_DATA";
            goto LABEL_56;
          }
          v54 = "%s: TPB: Send CMD_ESTIMATED_DATA successful";
        }
LABEL_37:
        v55 = "hdd_tx_pb_configure";
        v56 = 8;
        goto LABEL_38;
      }
      if ( !v40 )
      {
        v53 = *(unsigned __int8 *)(a1 + 10104);
        v78 = 0;
        v79 = 0;
        v76 = 0;
        v77 = 0;
        v74 = 0;
        v75 = 0;
        v72 = 0;
        v73 = 0;
        if ( v53 == 1 )
        {
          v54 = "%s: TPB: Boost ready already sent, no need to send again";
          v55 = "hdd_txpb_inference_app_start";
          v56 = 3;
LABEL_38:
          qdf_trace_msg(0x33u, v56, v54, v41, v42, v43, v44, v45, v46, v47, v48, v55);
          v57 = 0;
          goto LABEL_57;
        }
        v57 = hdd_txpb_issue_app_stop_ready(a1 + 1536, (__int64)&v72, (__int64)"Init", (__int64)"APP_START");
LABEL_57:
        v27 = qdf_status_to_os_return(v57);
        goto LABEL_19;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: Invalid Inference cmd type: %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_tx_pb_configure",
        v40);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: Inference cmd type NOT specified",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_tx_pb_configure");
    }
    v57 = 4;
    goto LABEL_57;
  }
  __break(0x800u);
  return hdd_tx_powerboost_init(result);
}
