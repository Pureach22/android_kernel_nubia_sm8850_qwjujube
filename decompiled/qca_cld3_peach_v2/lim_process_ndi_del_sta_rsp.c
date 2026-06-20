__int64 __fastcall lim_process_ndi_del_sta_rsp(
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
  unsigned __int16 *v11; // x20
  __int64 v12; // x21
  __int64 v13; // x4
  __int64 hash_entry; // x0
  const char *v18; // x2
  __int64 result; // x0
  const char *v20; // x2
  __int64 v21; // x24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x1
  __int64 v31; // x0
  __int64 v32; // x22
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // [xsp+8h] [xbp-18h]
  __int64 v51; // [xsp+10h] [xbp-10h] BYREF
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 **)(a2 + 8);
  v12 = *(_QWORD *)(a1 + 21624);
  v51 = 0;
  if ( v11 )
  {
    v13 = *v11;
    if ( *(_DWORD *)(a3 + 88) == 6 )
    {
      hash_entry = dph_get_hash_entry(a1, *v11, a3 + 360);
      if ( hash_entry )
      {
        if ( *((_DWORD *)v11 + 1) )
        {
          v18 = "%s: DEL STA failed!";
        }
        else
        {
          v21 = hash_entry;
          qdf_trace_msg(
            0x35u,
            4u,
            "%s: Deleted STA AssocID %d MAC %02x:%02x:%02x:**:**:%02x",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "lim_process_ndi_del_sta_rsp",
            *(unsigned __int16 *)(hash_entry + 348),
            *(unsigned __int8 *)(hash_entry + 350),
            *(unsigned __int8 *)(hash_entry + 351),
            *(unsigned __int8 *)(hash_entry + 352),
            *(unsigned __int8 *)(hash_entry + 355),
            v50,
            v51,
            v52);
          qdf_mem_copy(&v51, (const void *)(v21 + 350), 6u);
          lim_release_peer_idx(v22, v23, v24, v25, v26, v27, v28, v29, a1, *(unsigned __int16 *)(v21 + 348), a3);
          lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(v21 + 350), *(unsigned __int16 *)(v21 + 348), a3);
          v30 = *(unsigned __int8 *)(a3 + 10);
          *(_DWORD *)(a3 + 72) = 1;
          v31 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v12, v30, 20);
          if ( v31 )
          {
            v32 = v31;
            ucfg_nan_datapath_event_handler(v12, v31, 0xEu, (__int64)&v51, a4, a5, a6, a7, a8, a9, a10, a11);
            wlan_objmgr_vdev_release_ref(v32, 0x14u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
            wlan_ndi_add_pasn_peer_to_nan(v12, (__int64)&v51, v42, v43, v44, v45, v46, v47, v48, v49);
            goto LABEL_11;
          }
          v18 = "%s: Failed to get vdev from id";
        }
        qdf_trace_msg(0x35u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_ndi_del_sta_rsp");
LABEL_11:
        result = _qdf_mem_free((__int64)v11);
        *(_QWORD *)(a2 + 8) = 0;
        goto LABEL_12;
      }
      v13 = *v11;
      v20 = "%s: DPH Entry for STA %X is missing";
    }
    else
    {
      v20 = "%s: Session %d is not NDI role";
    }
    qdf_trace_msg(0x35u, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_ndi_del_sta_rsp", v13);
    goto LABEL_11;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: del_sta_params is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_process_ndi_del_sta_rsp");
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
