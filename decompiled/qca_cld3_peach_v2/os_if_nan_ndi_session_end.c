__int64 __fastcall os_if_nan_ndi_session_end(__int64 a1)
{
  _QWORD *v2; // x19
  int ndi_state; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned __int16 v32; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v84; // [xsp+8h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 216) + 24LL);
  ndi_state = ucfg_nan_get_ndi_state();
  if ( ndi_state == 9 || ndi_state == 2 )
  {
    v13 = _cfg80211_alloc_event_skb(*v2, 0, 103, 197, 0, 26, 48, 3264);
    if ( v13 )
    {
      v22 = v13;
      v83 = 2;
      if ( (unsigned int)nla_put(v13, 1, 4, &v83) )
      {
        v31 = "%s: VENDOR_ATTR_NDP_SUBCMD put fail";
      }
      else
      {
        LOWORD(v83) = ucfg_nan_get_ndp_delete_transaction_id(a1, v23, v24, v25, v26, v27, v28, v29, v30);
        if ( (unsigned int)nla_put(v22, 2, 2, &v83) )
        {
          v31 = "%s: VENDOR_ATTR_NDP_TRANSACTION_ID put fail";
        }
        else
        {
          v83 = ucfg_nan_get_ndi_delete_rsp_status(a1, v23, v24, v25, v26, v27, v28, v29, v30);
          if ( (unsigned int)nla_put(v22, 14, 4, &v83) )
          {
            v31 = "%s: VENDOR_ATTR_NDP_DRV_RETURN_TYPE put fail";
          }
          else
          {
            v83 = ucfg_nan_get_ndi_delete_rsp_reason(a1, v23, v24, v25, v26, v27, v28, v29, v30);
            if ( !(unsigned int)nla_put(v22, 15, 4, &v83) )
            {
              v32 = ucfg_nan_get_ndp_delete_transaction_id(a1, v23, v24, v25, v26, v27, v28, v29, v30);
              v41 = ucfg_nan_get_ndi_delete_rsp_status(a1, v33, v34, v35, v36, v37, v38, v39, v40);
              v50 = ucfg_nan_get_ndi_delete_rsp_reason(a1, v42, v43, v44, v45, v46, v47, v48, v49);
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: delete transaction id: %u, status code: %u reason: %u",
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                "os_if_nan_ndi_session_end",
                v32,
                v41,
                v50);
              ucfg_nan_set_ndp_delete_transaction_id(a1, 0, v59, v60, v61, v62, v63, v64, v65, v66);
              _ucfg_nan_set_ndi_state(
                a1,
                3u,
                (__int64)"os_if_nan_ndi_session_end",
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74);
              ucfg_ndi_remove_entry_from_policy_mgr(a1, v75, v76, v77, v78, v79, v80, v81, v82);
              result = _cfg80211_send_event_skb(v22, 3264);
              goto LABEL_17;
            }
            v31 = "%s: VENDOR_ATTR_NDP_DRV_RETURN_VALUE put fail";
          }
        }
      }
      qdf_trace_msg(0x48u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "os_if_nan_ndi_session_end");
      result = sk_skb_reason_drop(0, v22, 2);
    }
    else
    {
      result = qdf_trace_msg(
                 0x48u,
                 2u,
                 "%s: wlan_cfg80211_vendor_event_alloc failed",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "os_if_nan_ndi_session_end");
    }
  }
  else if ( ndi_state == 1 )
  {
    result = qdf_trace_msg(
               0x48u,
               8u,
               "%s: NDI interface is just created: %u",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "os_if_nan_ndi_session_end");
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: NDI interface deleted: state: %u",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "os_if_nan_ndi_session_end");
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
