__int64 __fastcall lim_ndp_add_sta_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 v34; // x0
  __int64 result; // x0
  __int16 v36; // w8
  __int64 v37; // x21
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  void *v48; // x0
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x22
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned __int16 v67; // [xsp+14h] [xbp-3Ch] BYREF
  _QWORD v68[7]; // [xsp+18h] [xbp-38h] BYREF

  v68[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  if ( a3 )
  {
    v14 = a1 + 0x2000;
    *(_QWORD *)(a1 + 8888) = "lim_ndp_add_sta_rsp";
    *(_BYTE *)(a1 + 8885) = 1;
    qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a4, a5, a6, a7, a8, a9, a10, a11);
    v23 = *(unsigned __int8 *)(v14 + 693);
    memset(v68, 0, 48);
    if ( v23 )
    {
      if ( *(_WORD *)(v14 + 496) )
      {
        LOWORD(v68[0]) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v68) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "lim_post_msg_to_process_deferred_queue",
            LOWORD(v68[0]));
      }
    }
    v24 = dph_lookup_hash_entry(v15, v16, v17, v18, v19, v20, v21, v22, a1, (unsigned __int8 *)(a3 + 9), &v67, a2 + 360);
    if ( v24 )
    {
      v33 = *(unsigned int *)(a3 + 112);
      if ( (_DWORD)v33 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: NAN: ADD_STA_RSP error %x for MAC addr: %02x:%02x:%02x:**:**:%02x",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "lim_ndp_add_sta_rsp",
          v33,
          *(unsigned __int8 *)(a3 + 9),
          *(unsigned __int8 *)(a3 + 10),
          *(unsigned __int8 *)(a3 + 11),
          *(unsigned __int8 *)(a3 + 14));
        lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(a3 + 9), v67, a2);
      }
      else
      {
        v36 = *(_WORD *)v24;
        *(_DWORD *)(v24 + 8) = 14;
        *(_WORD *)v24 = v36 | 1;
        v37 = *(_QWORD *)(a1 + 21624);
        if ( v37 )
        {
          v38 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                  *(_QWORD *)(a1 + 21624),
                  *(unsigned __int8 *)(a3 + 143),
                  20);
          if ( v38 )
          {
            v47 = v38;
            v48 = (void *)_qdf_mem_malloc(8u, "lim_send_sme_ndp_add_sta_rsp", 447);
            if ( v48 )
            {
              v58 = (__int64)v48;
              qdf_mem_copy(v48, (const void *)(a3 + 9), 6u);
              ucfg_nan_datapath_event_handler(v37, v47, 0xDu, v58, v59, v60, v61, v62, v63, v64, v65, v66);
              _qdf_mem_free(v58);
            }
            wlan_objmgr_vdev_release_ref(v47, 0x14u, v49, v50, v51, v52, v53, v54, v55, v56, v57);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to get vdev from id",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "lim_send_sme_ndp_add_sta_rsp");
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Invalid psoc",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "lim_send_sme_ndp_add_sta_rsp");
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: NAN: ADD_STA_RSP for unknown MAC addr %02x:%02x:%02x:**:**:%02x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "lim_ndp_add_sta_rsp",
        *(unsigned __int8 *)(a3 + 9),
        *(unsigned __int8 *)(a3 + 10),
        *(unsigned __int8 *)(a3 + 11),
        *(unsigned __int8 *)(a3 + 14));
    }
    v34 = a3;
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid add_sta_rsp", a4, a5, a6, a7, a8, a9, a10, a11, "lim_ndp_add_sta_rsp");
    v34 = 0;
  }
  result = _qdf_mem_free(v34);
  _ReadStatusReg(SP_EL0);
  return result;
}
