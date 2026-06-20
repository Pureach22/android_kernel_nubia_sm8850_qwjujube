__int64 __fastcall wlan_ipa_send_msg(__int64 a1, __int64 a2, unsigned int a3, const void *a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 result; // x0
  void *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 2621440;
  v8 = _qdf_mem_malloc(0x28u, "wlan_ipa_send_msg", 3544);
  if ( !v8 )
  {
    result = 2;
    goto LABEL_15;
  }
  v9 = v8;
  _qdf_ipa_set_meta_msg_type(&v45, a3);
  if ( !a1 )
  {
    v18 = a2;
    if ( a2 )
      goto LABEL_9;
LABEL_13:
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: No valid net dev for IPA EVT: %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_ipa_set_msg_ifname_by_iface",
      a3);
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Evt: %d fail",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_ipa_send_msg",
      (unsigned __int8)v45);
    goto LABEL_14;
  }
  v18 = *(_QWORD *)(a1 + 24);
  if ( !(a2 | v18) )
    goto LABEL_13;
  if ( !v18 )
    v18 = a2;
LABEL_9:
  _wlan_ipa_set_msg_ifname(v18 + 296, a3, v9);
  v20 = qdf_mem_copy((void *)(v9 + 32), a4, 6u);
  *(_WORD *)(v9 + 38) = *(_DWORD *)(a2 + 224);
  if ( a3 == 2 )
    ipa_is_wds_enabled(v20);
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: %s: Evt: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_ipa_send_msg",
    v9,
    (unsigned __int8)v45);
  result = ipa_send_msg(&v45, v9, wlan_ipa_msg_free_fn);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: %s: Evt: %d fail",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_ipa_send_msg",
      v9,
      (unsigned __int8)v45);
LABEL_14:
    _qdf_mem_free(v9);
    result = 16;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
