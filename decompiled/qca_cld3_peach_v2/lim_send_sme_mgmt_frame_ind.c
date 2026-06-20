__int64 __fastcall lim_send_sme_mgmt_frame_ind(
        __int64 a1,
        char a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int16 a5,
        int a6,
        char a7,
        int a8)
{
  __int64 result; // x0
  int v17; // w8
  int v18; // w9
  unsigned __int16 *v19; // x19
  bool v20; // zf
  bool v21; // zf
  unsigned __int16 v22; // w24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  double updated; // d0
  unsigned int *v42; // x8
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  void (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x21

  result = _qdf_mem_malloc((unsigned __int16)(a4 + 20), "lim_send_sme_mgmt_frame_ind", 10279);
  if ( result )
  {
    v17 = *(unsigned __int16 *)(a3 + 8);
    v18 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(result + 4) = a6;
    v19 = (unsigned __int16 *)result;
    v20 = v17 == 0xFFFF && v18 == -1;
    *(_WORD *)result = a4;
    v21 = v20 && a5 == 0;
    *(_BYTE *)(result + 9) = a2;
    if ( v21 )
      v22 = 255;
    else
      v22 = a5;
    *(_BYTE *)(result + 10) = a7;
    *(_BYTE *)(result + 8) = v22;
    *(_DWORD *)(result + 12) = a8;
    qdf_mem_set((void *)(result + 16), a4, 0);
    qdf_mem_copy(v19 + 8, (const void *)a3, a4);
    if ( a2 == 13 && v22 != 255 )
    {
      v31 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *(_QWORD *)(a1 + 21624),
              v22,
              7);
      if ( !v31 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid VDEV %d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "lim_send_sme_mgmt_frame_ind",
          v22);
        v50 = *(void (__fastcall **)(_QWORD))(a1 + 21608);
        if ( v50 )
          goto LABEL_16;
        goto LABEL_20;
      }
      v40 = v31;
      updated = wlan_mlo_update_action_frame_to_user(v31, v19 + 8, *v19);
      wlan_objmgr_vdev_release_ref(v40, 7u, v42, updated, v43, v44, v45, v46, v47, v48, v49);
    }
    v50 = *(void (__fastcall **)(_QWORD))(a1 + 21608);
    if ( v50 )
    {
LABEL_16:
      if ( *((_DWORD *)v50 - 1) != -822195787 )
        __break(0x8228u);
      v50(v19);
      return _qdf_mem_free((__int64)v19);
    }
LABEL_20:
    v51 = jiffies;
    if ( lim_send_sme_mgmt_frame_ind___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Management indication callback not registered!!",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_send_sme_mgmt_frame_ind");
      lim_send_sme_mgmt_frame_ind___last_ticks = v51;
    }
    return _qdf_mem_free((__int64)v19);
  }
  return result;
}
