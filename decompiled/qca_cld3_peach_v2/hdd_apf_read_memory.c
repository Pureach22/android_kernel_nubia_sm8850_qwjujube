__int64 __fastcall hdd_apf_read_memory(
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
  __int64 v10; // x23
  __int64 v11; // x19
  __int64 v12; // x22
  const char *v13; // x2
  unsigned int v14; // w1
  __int64 v15; // x8
  __int64 v16; // x8
  size_t v17; // x20
  __int64 v19; // x0
  __int64 v20; // x21
  unsigned int work_memory; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w19
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x19
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
  int v67; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v68; // [xsp+Ch] [xbp-14h]
  unsigned int v69; // [xsp+10h] [xbp-10h]
  int v70; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v71; // [xsp+18h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  v67 = 0;
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v13 = "%s: mac ctx NULL";
    v14 = 8;
LABEL_20:
    qdf_trace_msg(0x33u, v14, v13, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_apf_read_memory");
    goto LABEL_21;
  }
  v12 = a1 + 49152;
  if ( *(_BYTE *)(a1 + 52264) == 1 )
  {
    v13 = "%s: Cannot get/set while interpreter is enabled";
LABEL_19:
    v14 = 2;
    goto LABEL_20;
  }
  v15 = *(_QWORD *)(a2 + 40);
  LOBYTE(v67) = *(_BYTE *)(*(_QWORD *)(a1 + 52832) + 8LL);
  if ( !v15 )
  {
    v13 = "%s: attr apf memory offset failed";
    goto LABEL_19;
  }
  v68 = *(_DWORD *)(v15 + 4);
  if ( v68 <= 0x1000 )
  {
    v16 = *(_QWORD *)(a2 + 32);
    if ( !v16 )
    {
      v13 = "%s: attr apf packet size failed";
      goto LABEL_19;
    }
    v17 = *(unsigned int *)(v16 + 4);
    v69 = v17;
    if ( !(_DWORD)v17 )
    {
      v13 = "%s: apf read length cannot be zero!";
      goto LABEL_19;
    }
    v19 = _qdf_mem_malloc(v17, "hdd_apf_read_memory", 536);
    if ( !v19 )
    {
      result = 4294967284LL;
      goto LABEL_22;
    }
    v20 = v19;
    qdf_event_reset(a1 + 52224);
    *(_DWORD *)(v12 + 3132) = v68;
    *(_QWORD *)(v12 + 3120) = v20;
    *(_DWORD *)(v12 + 3128) = v17;
    *(_DWORD *)(v12 + 3064) = 72831828;
    work_memory = sme_apf_read_work_memory(v11, (__int64)&v67, (__int64)hdd_apf_read_memory_callback);
    if ( work_memory )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to post sme APF read memory message (status-%d)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_apf_read_memory",
        work_memory);
      goto LABEL_15;
    }
    if ( (unsigned int)qdf_wait_for_event_completion(a1 + 52224, 0x2710u) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Target response timed out",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_apf_read_memory");
      *(_DWORD *)(v12 + 3064) = 0;
      result = 4294967186LL;
      v31 = *(_QWORD *)(v12 + 3120);
      if ( !v31 )
        goto LABEL_22;
    }
    else
    {
      v41 = _cfg80211_alloc_reply_skb(*(_QWORD *)(v10 + 24), 103, 197, (unsigned int)(*(_DWORD *)(v12 + 3128) + 28));
      if ( v41 )
      {
        v50 = v41;
        v70 = 4;
        if ( (unsigned int)nla_put(v41, 1, 4, &v70) || (unsigned int)nla_put(v50, 6, v69, *(_QWORD *)(v12 + 3120)) )
        {
          qdf_trace_msg(0x33u, 2u, "%s: put fail", v51, v52, v53, v54, v55, v56, v57, v58, "hdd_apf_read_memory");
          sk_skb_reason_drop(0, v50, 2);
LABEL_15:
          result = 4294967274LL;
          v31 = *(_QWORD *)(v12 + 3120);
          if ( !v31 )
            goto LABEL_22;
          goto LABEL_26;
        }
        cfg80211_vendor_cmd_reply(v50);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Reading APF work memory from offset 0x%X:",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "hdd_apf_read_memory",
          v68);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(51, 8, *(_QWORD *)(v12 + 3120), v69);
        result = 0;
        v31 = *(_QWORD *)(v12 + 3120);
        if ( !v31 )
          goto LABEL_22;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "hdd_apf_read_memory");
        result = 4294967284LL;
        v31 = *(_QWORD *)(v12 + 3120);
        if ( !v31 )
          goto LABEL_22;
      }
    }
LABEL_26:
    v40 = result;
    _qdf_mem_free(v31);
    result = v40;
    *(_QWORD *)(v12 + 3120) = 0;
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: attr apf memory offset should be less than %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_apf_read_memory",
    4096);
LABEL_21:
  result = 4294967274LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
