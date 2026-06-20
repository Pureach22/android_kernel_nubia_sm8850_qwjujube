__int64 __fastcall sme_set_mlo_max_links(
        __int64 a1,
        unsigned int a2,
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
  __int64 result; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * (unsigned __int8)a2) )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: No session for id %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "sme_set_mlo_max_links");
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *(_QWORD *)(a1 + 21624),
             a2,
             11);
  if ( result )
  {
    v15 = result;
    v16 = _qdf_mem_malloc(0x1380u, "sme_set_mlo_max_links", 15866);
    if ( v16 )
    {
      v26 = v16;
      wlan_mlme_set_sta_mlo_conn_max_num(*(_QWORD *)(a1 + 21624), a3);
      wlan_mlme_set_user_set_link_num(*(_QWORD *)(a1 + 21624), a3);
      wlan_cm_roam_mlo_config(*(_QWORD *)(a1 + 21624), v15, v26);
      if ( (unsigned int)wlan_cm_tgt_send_roam_mlo_config(*(_QWORD *)(a1 + 21624), a2, v26 + 4964) )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: fail to send roam mlo config",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "sme_set_mlo_max_links");
      _qdf_mem_free(v26);
    }
    return wlan_objmgr_vdev_release_ref(v15, 0xBu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  return result;
}
