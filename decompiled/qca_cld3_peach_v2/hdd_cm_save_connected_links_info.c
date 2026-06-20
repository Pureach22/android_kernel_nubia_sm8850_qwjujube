__int64 __fastcall hdd_cm_save_connected_links_info(
        unsigned __int8 *a1,
        int *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 link_info_by_link_addr; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x23
  __int64 v33; // x5
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v43; // w9
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7

  context = _cds_get_context(51, (__int64)"hdd_cm_save_connected_links_info", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    link_info_by_link_addr = hdd_get_link_info_by_link_addr(context, a1);
    if ( link_info_by_link_addr )
    {
      v32 = link_info_by_link_addr;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %s: old_link_id:%d new_link_id:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_cm_set_ieee_link_id",
        "conn_info",
        *(unsigned int *)(link_info_by_link_addr + 976),
        a3);
      v33 = *(unsigned int *)(v32 + 1672);
      *(_DWORD *)(v32 + 976) = a3;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %s: old_link_id:%d new_link_id:%d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "hdd_cm_set_ieee_link_id",
        "cache_conn_info",
        v33,
        a3);
      *(_DWORD *)(v32 + 1672) = a3;
      v43 = *a2;
      *(_WORD *)(v32 + 312) = *((_WORD *)a2 + 2);
      *(_DWORD *)(v32 + 308) = v43;
      return 0;
    }
    if ( a1 )
    {
      v44 = *a1;
      v45 = a1[1];
      v46 = a1[2];
      v47 = a1[5];
    }
    else
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v47 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No link info with MAC: %02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hdd_cm_save_connected_links_info",
      v44,
      v45,
      v46,
      v47);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_cm_save_connected_links_info");
  }
  return 4;
}
