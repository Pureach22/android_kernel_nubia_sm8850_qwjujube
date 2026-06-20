__int64 __fastcall lim_process_updated_ies_in_probe_rsp(__int64 result, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned __int8 *v7; // x23
  __int64 v8; // x21
  __int64 hash_entry; // x0
  unsigned int v10; // w24
  __int64 v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  double v37; // d0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // [xsp+38h] [xbp-58h]
  __int64 v47; // [xsp+48h] [xbp-48h]

  if ( *(_DWORD *)(a2 + 72) == 14 )
  {
    v47 = v4;
    v7 = (unsigned __int8 *)(a2 + 4096);
    v8 = result;
    hash_entry = dph_get_hash_entry(result, 1u, a2 + 360);
    v10 = v7[2928];
    v11 = hash_entry;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Vdev_id: %d mac: %02x:%02x:%02x:**:**:%02x wmeEdcaPresent: %d wme_enabled: %d edcaPresent: %d, qos_en"
               "abled: %d edcaParams.qosInfo.count: %d schObject.gLimEdcaParamSetCount: %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_process_updated_ies_in_probe_rsp",
               *(unsigned __int8 *)(a2 + 10),
               *(unsigned __int8 *)(a2 + 24),
               *(unsigned __int8 *)(a2 + 25),
               *(unsigned __int8 *)(a2 + 26),
               *(unsigned __int8 *)(a2 + 29),
               (unsigned __int8)a3[2469],
               (v10 >> 1) & 1,
               (unsigned __int8)a3[2467],
               v10 & 1,
               a3[339] & 0xF,
               v7[3060],
               v46,
               v3,
               v47);
    if ( (!a3[2469] || (v10 & 2) == 0) && (!a3[2467] || (v10 & 1) == 0) || (a3[339] & 0xF) == v7[3060] )
      goto LABEL_12;
    if ( (unsigned int)sch_beacon_edca_process(v8, a3 + 337, a2) )
    {
      v36 = "%s: EDCA param process error";
    }
    else
    {
      if ( v11 )
      {
        qdf_mem_copy((void *)(v11 + 239), a3 + 337, 0x18u);
        lim_set_active_edca_params(v8, a2 + 7096, a2);
        v37 = lim_send_edca_params(v8, a2 + 7136, *(unsigned __int8 *)(a2 + 10), 0);
        result = sch_qos_concurrency_update(v37);
LABEL_12:
        if ( v7[3165] == 1 )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Check probe resp for caps change",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "lim_process_updated_ies_in_probe_rsp");
          return lim_detect_change_in_ap_capabilities(v8, (__int64)a3, a2, 0, v38, v39, v40, v41, v42, v43, v44, v45);
        }
        return result;
      }
      v36 = "%s: SelfEntry missing in Hash";
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               v36,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               "lim_process_updated_ies_in_probe_rsp");
    goto LABEL_12;
  }
  return result;
}
