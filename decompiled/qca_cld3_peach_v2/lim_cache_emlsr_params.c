__int64 __fastcall lim_cache_emlsr_params(
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
  __int64 v10; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x4
  int v23; // w5
  const char *v25; // x2
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v10 = *(_QWORD *)(a1 + 16);
  wlan_objmgr_vdev_get_ref(v10, 1u, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !v10 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev is null",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "lim_cache_emlsr_params");
  v20 = *(_QWORD *)(v10 + 1360);
  if ( v20 )
  {
    v21 = *(_QWORD *)(v20 + 2224);
    if ( v21 )
    {
      if ( (*(_BYTE *)(v10 + 49) & 4) != 0 )
      {
        v22 = 1;
        *(_BYTE *)(v21 + 1344) = 1;
        v23 = (*(unsigned __int16 *)(a2 + 5358) >> 11) & 0xF;
      }
      else
      {
        v22 = 0;
        LOBYTE(v23) = 0;
        *(_BYTE *)(v21 + 1344) = 0;
      }
      *(_BYTE *)(v21 + 1345) = v23;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: EML caps support%d timeout%d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_cache_emlsr_params",
        v22);
      return wlan_objmgr_vdev_release_ref(v10, 1u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    }
    v25 = "%s: sta ctx is null";
  }
  else
  {
    v25 = "%s: mlo dev ctx is null";
  }
  qdf_trace_msg(0x35u, 2u, v25, v12, v13, v14, v15, v16, v17, v18, v19, "lim_cache_emlsr_params");
  return wlan_objmgr_vdev_release_ref(v10, 1u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
}
