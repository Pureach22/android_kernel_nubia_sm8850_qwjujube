__int64 __fastcall hdd_enable_ns_offload(
        __int64 a1,
        __int64 a2,
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
  __int64 v14; // x24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w2
  __int64 v34; // x19
  __int64 v35; // x25
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  const char *v45; // x2
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x4
  const char *v57; // x2
  unsigned int v58; // w0

  v14 = **(_QWORD **)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_enable_ns_offload");
  if ( !v14 )
  {
    v45 = "%s: psoc is NULL";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v45, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_enable_ns_offload");
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v25, v26, v27, v28, v29, v30, v31, v32, "hdd_enable_ns_offload");
  }
  v23 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 192LL);
  if ( !v23 )
  {
    v45 = "%s: IPv6 dev does not exist. Failed to request NSOffload";
    goto LABEL_8;
  }
  v24 = _qdf_mem_malloc(0x168u, "hdd_enable_ns_offload", 543);
  if ( v24 )
  {
    v33 = *(_BYTE *)(a2 + 168);
    v34 = v24;
    *(_QWORD *)v24 = v14;
    *(_DWORD *)(v24 + 12) = a3;
    *(_BYTE *)(v24 + 8) = v33;
    *(_DWORD *)(v24 + 16) = 0;
    v35 = v24 + 16;
    if ( (unsigned int)ucfg_pmo_ns_offload_check(v14, a3) )
    {
      v44 = "%s: NS offload is not required";
    }
    else
    {
      if ( !(unsigned int)hdd_fill_ipv6_uc_addr(v23, v34 + 20, v34 + 276, v34 + 292, v35)
        && !(unsigned int)hdd_fill_ipv6_ac_addr(v23, v34 + 20, v34 + 276, v34 + 292, v35) )
      {
        v47 = ucfg_pmo_cache_ns_offload_req(v34);
        if ( v47 )
        {
          v56 = v47;
          v57 = "%s: Failed to cache ns request; status:%d";
        }
        else
        {
          v58 = ucfg_pmo_enable_ns_offload_in_fwr(a2, a3);
          if ( !v58 )
          {
            hdd_wlan_offload_event(2, 1);
            goto LABEL_13;
          }
          v56 = v58;
          v57 = "%s: Failed to enable ns offload; status:%d";
        }
        qdf_trace_msg(0x33u, 8u, v57, v48, v49, v50, v51, v52, v53, v54, v55, "hdd_enable_ns_offload", v56);
LABEL_13:
        _qdf_mem_free(v34);
        return qdf_trace_msg(0x33u, 8u, "%s: exit", v25, v26, v27, v28, v29, v30, v31, v32, "hdd_enable_ns_offload");
      }
      hdd_disable_ns_offload(a1, a2, a3);
      v44 = "%s: Max supported addresses: disabling NS offload";
    }
    qdf_trace_msg(0x33u, 8u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "hdd_enable_ns_offload");
    goto LABEL_13;
  }
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v25, v26, v27, v28, v29, v30, v31, v32, "hdd_enable_ns_offload");
}
