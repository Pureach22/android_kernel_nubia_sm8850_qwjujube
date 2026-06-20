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
  __int64 v19; // x19
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
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  void (__fastcall *v41)(_QWORD); // x8
  __int64 v42; // x21

  result = _qdf_mem_malloc((unsigned __int16)(a4 + 20), "lim_send_sme_mgmt_frame_ind", 10279);
  if ( result )
  {
    v17 = *(unsigned __int16 *)(a3 + 8);
    v18 = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(result + 4) = a6;
    v19 = result;
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
    qdf_mem_copy((void *)(v19 + 16), (const void *)a3, a4);
    if ( a2 == 13 && v22 != 255 )
    {
      v31 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *(_QWORD *)(a1 + 21552),
              v22,
              7);
      if ( !v31 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid VDEV %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "lim_send_sme_mgmt_frame_ind",
          v22);
        v41 = *(void (__fastcall **)(_QWORD))(a1 + 21536);
        if ( v41 )
          goto LABEL_16;
        goto LABEL_20;
      }
      wlan_objmgr_vdev_release_ref(v31, 7u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    }
    v41 = *(void (__fastcall **)(_QWORD))(a1 + 21536);
    if ( v41 )
    {
LABEL_16:
      if ( *((_DWORD *)v41 - 1) != -822195787 )
        __break(0x8228u);
      v41(v19);
      return _qdf_mem_free(v19);
    }
LABEL_20:
    v42 = jiffies;
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
      lim_send_sme_mgmt_frame_ind___last_ticks = v42;
    }
    return _qdf_mem_free(v19);
  }
  return result;
}
