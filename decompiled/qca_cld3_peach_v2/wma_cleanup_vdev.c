__int64 __fastcall wma_cleanup_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 **v19; // x22
  unsigned int v20; // w19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x8
  const char *v40; // x2
  const char *v41; // x3
  unsigned int v42; // w0
  unsigned int v43; // w1

  result = (__int64)_cds_get_context(71, (__int64)"wma_cleanup_vdev", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = (__int64 **)result;
    v20 = *(unsigned __int8 *)(a1 + 168);
    result = (__int64)_cds_get_context(54, (__int64)"wma_cleanup_vdev", v11, v12, v13, v14, v15, v16, v17, v18);
    if ( result )
    {
      v29 = result;
      if ( !*(_QWORD *)(*(_QWORD *)(result + 520) + 488LL * v20) )
        return qdf_trace_msg(0x36u, 2u, "%s: vdev is NULL", v21, v22, v23, v24, v25, v26, v27, v28, "wma_cleanup_vdev");
      if ( !wlan_vdev_mlme_get_cmpt_obj(a1, v21, v22, v23, v24, v25, v26, v27, v28) )
        return qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Failed to get vdev mlme obj for vdev id %d",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "wma_cleanup_vdev",
                 v20);
      v38 = *(_QWORD *)(*(_QWORD *)(v29 + 520) + 488LL * v20);
      if ( v38 )
      {
        v39 = *(unsigned __int8 *)(v38 + 168);
        if ( (_DWORD)v39 == 255 )
        {
LABEL_18:
          result = wlan_objmgr_vdev_release_ref(a1, 8u, (unsigned int *)v39, v30, v31, v32, v33, v34, v35, v36, v37);
          *(_QWORD *)(*(_QWORD *)(v29 + 520) + 488LL * v20) = 0;
          *(_BYTE *)(*(_QWORD *)(v29 + 520) + 488LL * v20 + 184) = 0;
          return result;
        }
        if ( *v19 )
        {
          v39 = **v19;
          if ( v39 )
          {
            v39 = *(_QWORD *)(v39 + 24);
            if ( v39 )
            {
              if ( *(_DWORD *)(v39 - 4) != -1818723745 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64 **, _QWORD, _QWORD, _QWORD))v39)(v19, v20, 0, 0);
            }
          }
          goto LABEL_18;
        }
        v40 = "%s: Invalid Instance:";
        v41 = "cdp_vdev_detach";
        v42 = 137;
        v43 = 8;
      }
      else
      {
        v40 = "%s: vdev is NULL";
        v41 = "wma_cdp_vdev_detach";
        v42 = 54;
        v43 = 2;
      }
      qdf_trace_msg(v42, v43, v40, v30, v31, v32, v33, v34, v35, v36, v37, v41);
      goto LABEL_18;
    }
  }
  return result;
}
