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
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x22
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+8h] [xbp-18h]
  __int64 v43; // [xsp+10h] [xbp-10h] BYREF
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 **)(a2 + 8);
  v12 = *(_QWORD *)(a1 + 21552);
  v43 = 0;
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
            *(unsigned __int16 *)(hash_entry + 336),
            *(unsigned __int8 *)(hash_entry + 338),
            *(unsigned __int8 *)(hash_entry + 339),
            *(unsigned __int8 *)(hash_entry + 340),
            *(unsigned __int8 *)(hash_entry + 343),
            v42,
            v43,
            v44);
          qdf_mem_copy(&v43, (const void *)(v21 + 338), 6u);
          lim_release_peer_idx(a1, *(_WORD *)(v21 + 336), a3);
          lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(v21 + 338), *(unsigned __int16 *)(v21 + 336), a3);
          v22 = *(unsigned __int8 *)(a3 + 10);
          *(_DWORD *)(a3 + 72) = 1;
          v23 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v12, v22, 20);
          if ( v23 )
          {
            v24 = v23;
            ucfg_nan_datapath_event_handler(v12, v23, 0xEu, (__int64)&v43, a4, a5, a6, a7, a8, a9, a10, a11);
            wlan_objmgr_vdev_release_ref(v24, 0x14u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
            wlan_ndi_add_pasn_peer_to_nan(v12, (__int64)&v43, v34, v35, v36, v37, v38, v39, v40, v41);
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
