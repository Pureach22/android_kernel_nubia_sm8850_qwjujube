__int64 __fastcall os_if_dp_send_flow_status_event(__int64 a1, __int64 a2, char a3)
{
  __int64 pdev_by_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *v14; // x8
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _BYTE v71[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v72[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v73; // [xsp+8h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0x61u);
  if ( !pdev_by_id )
    goto LABEL_14;
  v14 = *(_QWORD **)(pdev_by_id + 24);
  v15 = pdev_by_id;
  if ( !v14 )
  {
    v51 = "%s: PDEV OS private structure is NULL";
LABEL_13:
    qdf_trace_msg(0x48u, 2u, v51, v6, v7, v8, v9, v10, v11, v12, v13, "os_if_dp_send_flow_status_event");
    wlan_objmgr_pdev_release_ref(v15, 0x61u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
    goto LABEL_14;
  }
  v16 = _cfg80211_alloc_event_skb(*v14, 0, 103, 197, 0, 71, 60, 3264);
  if ( !v16 )
  {
    v51 = "%s: STC: vendor event alloc failed for flow sample";
    goto LABEL_13;
  }
  v17 = v16;
  if ( (a3 & 8) != 0 )
  {
    os_if_dp_print_tuple(a2);
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: traffic type: %u status: %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      *(unsigned __int8 *)(a2 + 48),
      *(unsigned int *)(a2 + 52));
  }
  if ( (os_if_dp_fill_flow_tuple(v17, a2) & 0x80000000) == 0 )
  {
    v71[0] = *(_BYTE *)(a2 + 48);
    if ( !(unsigned int)nla_put(v17, 2, 1, v71) )
    {
      v72[0] = *(_DWORD *)(a2 + 52);
      if ( !(unsigned int)nla_put(v17, 3, 1, v72) )
      {
        _cfg80211_send_event_skb(v17, 3264);
        wlan_objmgr_pdev_release_ref(v15, 0x61u, v62, v63, v64, v65, v66, v67, v68, v69, v70);
        result = 60;
        goto LABEL_15;
      }
    }
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: STC: traffic type put failed",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "os_if_dp_send_flow_status_event");
  }
  wlan_objmgr_pdev_release_ref(v15, 0x61u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: STC: flow status nla_put api failed",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "os_if_dp_send_flow_status_event");
  sk_skb_reason_drop(0, v17, 2);
LABEL_14:
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
