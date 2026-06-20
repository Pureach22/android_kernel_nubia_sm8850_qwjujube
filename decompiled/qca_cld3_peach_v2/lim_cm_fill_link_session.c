__int64 __fastcall lim_cm_fill_link_session(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int16 a5)
{
  unsigned int v9; // w23
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 assoc_link_vdev; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 cmpt_obj; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  size_t v38; // x2
  __int64 v39; // x0
  __int64 v40; // x24
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w23
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v61; // w0

  v9 = a2;
  v10 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          a2,
          7);
  if ( v10 )
  {
    v19 = v10;
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v10);
    if ( assoc_link_vdev )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(assoc_link_vdev, v21, v22, v23, v24, v25, v26, v27, v28);
      if ( cmpt_obj )
      {
        v38 = *(unsigned __int8 *)(cmpt_obj + 178);
        if ( *(_BYTE *)(cmpt_obj + 178) )
        {
          *(_BYTE *)(a3 + 36) = v38;
          qdf_mem_copy((void *)(a3 + 37), (const void *)(cmpt_obj + 145), v38);
          v39 = _qdf_mem_malloc((unsigned __int16)(a5 + 104) + 4656LL, "lim_cm_fill_link_session", 3848);
          *(_QWORD *)(a3 + 112) = v39;
          if ( v39 )
          {
            mlo_roam_copy_partner_info(v39 + 4368, a4, v9, 0);
            v40 = *(_QWORD *)(a3 + 112);
            v41 = lim_roam_fill_bss_descr(a1, (unsigned __int16 *)a4, v40 + 4548, a3);
            if ( v41 )
            {
              v50 = v41;
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: LFR3:Failed to fill Bss Descr",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "lim_cm_fill_link_session");
            }
            else
            {
              v61 = lim_fill_pe_session(a1, a3, v40 + 4548, *(unsigned int *)(a4 + 2460), 0);
              if ( !v61 )
              {
                v51 = (unsigned int *)*(unsigned int *)(a3 + 80);
                v50 = 0;
                if ( (_DWORD)v51 == 3 )
                {
                  v51 = (_DWORD *)(&qword_8 + 2);
                  *(_DWORD *)(a3 + 80) = 10;
                  *(_DWORD *)(a3 + 72) = 11;
                }
                goto LABEL_14;
              }
              v50 = v61;
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Failed to fill pe session vdev id %d",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "lim_cm_fill_link_session",
                *(unsigned __int8 *)(a3 + 10));
            }
          }
          else
          {
            v50 = 2;
          }
LABEL_13:
          _qdf_mem_free(*(_QWORD *)(a3 + 112));
          *(_QWORD *)(a3 + 112) = 0;
LABEL_14:
          wlan_objmgr_vdev_release_ref(v19, 7u, v51, v52, v53, v54, v55, v56, v57, v58, v59);
          return v50;
        }
        *(_BYTE *)(a3 + 36) = 0;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get ssid vdev id %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_cm_fill_link_session",
        (unsigned __int8)v9);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Assoc vdev is NULL",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_cm_fill_link_session");
    }
    v50 = 16;
    goto LABEL_13;
  }
  qdf_trace_msg(0x35u, 2u, "%s: Vdev is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "lim_cm_fill_link_session");
  return 29;
}
