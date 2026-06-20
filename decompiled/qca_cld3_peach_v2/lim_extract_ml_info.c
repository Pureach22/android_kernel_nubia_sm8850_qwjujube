__int64 __fastcall lim_extract_ml_info(
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
  __int64 result; // x0
  __int64 v13; // x1
  __int64 v14; // x21
  __int64 v15; // x1
  __int64 v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 ap_link_by_link_id; // x0
  unsigned int v26; // w21
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 v36; // x27
  _DWORD *v37; // x22
  unsigned int v38; // w25
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x25
  _BYTE *v48; // x24

  result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    *(_DWORD *)(a2 + 576) = *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 168LL);
    v13 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 93LL);
    *(_DWORD *)(a2 + 580) = v13;
    *(_BYTE *)(a2 + 808) = *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 1360LL) + 3896LL);
    result = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 1360LL), v13);
    if ( result )
    {
      v14 = result;
      qdf_mem_copy((void *)(a2 + 592), *(const void **)(result + 32), 0x28u);
      qdf_mem_copy((void *)(a2 + 584), (const void *)(v14 + 24), 6u);
      qdf_mem_copy((void *)(a2 + 632), (const void *)v14, 6u);
      ap_link_by_link_id = *(_QWORD *)(a1 + 16);
      if ( (*(_BYTE *)(ap_link_by_link_id + 60) & 2) != 0 )
      {
        if ( (wlan_cm_is_link_add_connecting(ap_link_by_link_id, v17, v18, v19, v20, v21, v22, v23, v24) & 1) == 0 )
        {
          result = mlo_mgr_is_link_add_link_switch(*(_QWORD *)(a1 + 16));
          if ( (result & 1) == 0 )
            return result;
        }
        *(_BYTE *)(a2 + 640) = *(_BYTE *)(v14 + 12);
        *(_BYTE *)(a2 + 641) = *(_BYTE *)(v14 + 6);
        qdf_mem_copy((void *)(a2 + 656), *(const void **)(v14 + 32), 0x28u);
        qdf_mem_copy((void *)(a2 + 642), (const void *)(v14 + 24), 6u);
        qdf_mem_copy((void *)(a2 + 648), (const void *)v14, 6u);
        v27 = *(_QWORD *)(a1 + 16);
        *(_BYTE *)(a1 + 10696) = 0;
        ((void (__fastcall *)(__int64, __int64))mlo_link_recfg_get_add_partner_links)(v27, a1 + 10696);
        ap_link_by_link_id = qdf_trace_msg(
                               0x35u,
                               8u,
                               "%s: vdev:%d link_add Num of other partner: %d ",
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               "lim_extract_ml_info",
                               *(unsigned __int8 *)(a1 + 10),
                               *(unsigned __int8 *)(a1 + 10696));
        v26 = 1;
        if ( !*(_BYTE *)(a1 + 10696) )
        {
LABEL_18:
          *(_BYTE *)(a2 + 638) = v26;
          return qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: vdev:%d Num of partner links: %d",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "lim_extract_ml_info",
                   *(unsigned __int8 *)(a1 + 10),
                   v26);
        }
      }
      else
      {
        v26 = 0;
        if ( !*(_BYTE *)(a1 + 10696) )
          goto LABEL_18;
      }
      v36 = 0;
      v37 = (_DWORD *)(a1 + 10748);
      while ( v36 != 3 )
      {
        v38 = *((unsigned __int8 *)v37 - 38);
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(
                               *(_QWORD *)(*(_QWORD *)(a1 + 16) + 1360LL),
                               *((unsigned __int8 *)v37 - 38));
        if ( ap_link_by_link_id )
        {
          if ( *v37 )
          {
            ap_link_by_link_id = qdf_trace_msg(
                                   0x35u,
                                   8u,
                                   "%s: link id %d link_status_code %d",
                                   v39,
                                   v40,
                                   v41,
                                   v42,
                                   v43,
                                   v44,
                                   v45,
                                   v46,
                                   "lim_extract_ml_info",
                                   v38);
          }
          else
          {
            if ( v26 > 2 )
              break;
            v47 = ap_link_by_link_id;
            v48 = (_BYTE *)(a2 + 640 + 56LL * v26);
            *v48 = *(_BYTE *)(ap_link_by_link_id + 12);
            v48[1] = *(_BYTE *)(ap_link_by_link_id + 6);
            qdf_mem_copy(v48 + 16, *(const void **)(ap_link_by_link_id + 32), 0x28u);
            qdf_mem_copy(v48 + 2, (const void *)(v47 + 24), 6u);
            ap_link_by_link_id = (__int64)qdf_mem_copy(v48 + 8, (const void *)v47, 6u);
            ++v26;
          }
        }
        else
        {
          ap_link_by_link_id = qdf_trace_msg(
                                 0x35u,
                                 8u,
                                 "%s: no find link info for id %d",
                                 v39,
                                 v40,
                                 v41,
                                 v42,
                                 v43,
                                 v44,
                                 v45,
                                 v46,
                                 "lim_extract_ml_info",
                                 v38);
        }
        ++v36;
        v37 += 12;
        if ( v36 >= *(unsigned __int8 *)(a1 + 10696) )
          goto LABEL_18;
      }
      __break(0x5512u);
      return lim_intersect_ap_emlsr_caps(ap_link_by_link_id, v15, v16, 5292);
    }
  }
  return result;
}
