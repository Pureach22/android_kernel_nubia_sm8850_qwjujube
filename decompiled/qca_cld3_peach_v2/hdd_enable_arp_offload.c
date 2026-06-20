__int64 __fastcall hdd_enable_arp_offload(
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
  __int64 v14; // x23
  __int64 result; // x0
  char v16; // w2
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  unsigned int v27; // w1
  __int64 v28; // x23
  __int64 v29; // x22
  int v30; // w8
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x4
  const char *v41; // x2
  unsigned int v42; // w0

  v14 = **(_QWORD **)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_enable_arp_offload");
  result = _qdf_mem_malloc(0x18u, "hdd_enable_arp_offload", 1331);
  if ( result )
  {
    v16 = *(_BYTE *)(a2 + 168);
    v17 = result;
    *(_QWORD *)result = v14;
    *(_DWORD *)(result + 16) = a3;
    *(_BYTE *)(result + 8) = v16;
    if ( (unsigned int)ucfg_pmo_check_arp_offload(v14, a3) )
    {
      v26 = "%s: ARP offload not required";
      v27 = 8;
    }
    else
    {
      v28 = *(_QWORD *)(a1 + 32);
      v29 = *(_QWORD *)(v28 + 968);
      if ( v29 )
      {
        do
        {
          v29 = *(_QWORD *)(v29 + 16);
          if ( !v29 )
            goto LABEL_10;
        }
        while ( strcmp((const char *)(v28 + 296), (const char *)(v29 + 76)) );
        v30 = *(_DWORD *)(v29 + 48);
        if ( !v30 )
          goto LABEL_10;
        *(_DWORD *)(v17 + 12) = v30;
        v31 = ucfg_pmo_cache_arp_offload_req(v17);
        if ( v31 )
        {
          v40 = v31;
          v41 = "%s: failed to cache arp offload req; status:%d";
        }
        else
        {
          v42 = ucfg_pmo_enable_arp_offload_in_fwr(a2, a3);
          if ( !v42 )
          {
            hdd_wlan_offload_event(0, 1);
            return _qdf_mem_free(v17);
          }
          v40 = v42;
          v41 = "%s: failed arp offload config in fw; status:%d";
        }
        qdf_trace_msg(0x33u, 2u, v41, v32, v33, v34, v35, v36, v37, v38, v39, "hdd_enable_arp_offload", v40);
        return _qdf_mem_free(v17);
      }
LABEL_10:
      v26 = "%s: IP Address is not assigned";
      v27 = 4;
    }
    qdf_trace_msg(0x33u, v27, v26, v18, v19, v20, v21, v22, v23, v24, v25, "hdd_enable_arp_offload");
    return _qdf_mem_free(v17);
  }
  return result;
}
