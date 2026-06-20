__int64 __fastcall wlan_cm_update_mlme_fils_info(
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
  unsigned int v10; // w20
  __int64 ext_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  size_t v33; // x2
  size_t v34; // x2
  size_t v35; // x2

  v10 = *(unsigned __int8 *)(a1 + 168);
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    v21 = ext_hdl;
    if ( a2 )
    {
      v22 = *(_QWORD *)(ext_hdl + 24080);
      if ( v22 )
        _qdf_mem_free(v22);
      v23 = _qdf_mem_malloc(0x318u, "wlan_cm_update_mlme_fils_info", 2446);
      *(_QWORD *)(v21 + 24080) = v23;
      if ( v23 )
      {
        v32 = v23;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: FILS: vdev:%d update fils info",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_cm_update_mlme_fils_info",
          v10);
        *(_BYTE *)v32 = *(_BYTE *)a2;
        v33 = *(unsigned int *)(a2 + 4);
        *(_DWORD *)(v32 + 256) = v33;
        qdf_mem_copy((void *)(v32 + 1), (const void *)(a2 + 8), v33);
        v34 = *(unsigned int *)(a2 + 264);
        *(_DWORD *)(v32 + 656) = v34;
        qdf_mem_copy((void *)(v32 + 400), (const void *)(a2 + 268), v34);
        v35 = *(unsigned int *)(a2 + 528);
        *(_DWORD *)(v32 + 328) = v35;
        qdf_mem_copy((void *)(v32 + 264), (const void *)(a2 + 532), v35);
        *(_DWORD *)(v32 + 260) = *(unsigned __int16 *)(a2 + 524);
        *(_BYTE *)(v32 + 661) = *(_DWORD *)(a2 + 596);
        return 0;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: FILS: vdev:%d Clear fils info",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_cm_update_mlme_fils_info",
        v10);
      _qdf_mem_free(*(_QWORD *)(v21 + 24080));
      *(_QWORD *)(v21 + 24080) = 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL for vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_cm_update_mlme_fils_info",
      v10);
    return 16;
  }
}
