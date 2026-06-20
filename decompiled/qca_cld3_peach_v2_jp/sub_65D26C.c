// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_65D26C(
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
  __int16 v11; // w19
  __int64 result; // x0
  int v13; // w8
  unsigned __int8 v14; // w20
  const char *v15; // x2
  __int64 v16; // x4
  unsigned __int8 v17; // w22
  int v18; // w23
  unsigned int v20; // w21
  __int64 v21; // x24
  __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // w8
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
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  if ( (v11 & 0x8000) == 0 )
    return tgt_fwol_vdev_param_send(a1, a2, a3);
  v13 = *(_DWORD *)(a1 + 768);
  v14 = a2;
  if ( (v13 & 1) == 0 )
  {
    v15 = "%s: NAPI not initialized or entry %d not created";
    v16 = (unsigned __int8)a2;
LABEL_5:
    qdf_trace_msg(0x3Du, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "hif_napi_destroy", v16);
    return 4294967274LL;
  }
  v17 = a2 - 1;
  v18 = 1 << (a2 - 1);
  v20 = (unsigned __int8)(a2 - 1);
  if ( (*(_DWORD *)(a1 + 772) & v18) == 0 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: NAPI instance %d (pipe %d) not created",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hif_napi_destroy",
      (unsigned __int8)a2,
      (unsigned __int8)(a2 - 1));
    if ( v20 < 0xC )
    {
      if ( *(_QWORD *)(a1 + 8LL * v17 + 784) )
        qdf_trace_msg(
          0x3Du,
          2u,
          "%s: memory allocated but ce_map not set %d (pipe %d)",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "hif_napi_destroy",
          v14,
          v20);
      return 4294967274LL;
    }
LABEL_23:
    __break(0x5512u);
    JUMPOUT(0x663FEC);
  }
  if ( v20 > 0xB )
    goto LABEL_23;
  v21 = (unsigned __int8)(a2 - 1);
  v22 = *(_QWORD *)(a1 + 784 + 8 * v21);
  if ( !v22 )
  {
    v15 = "%s: napii & ce_map out of sync(ce %d)";
    v16 = (unsigned __int8)(a2 - 1);
    goto LABEL_5;
  }
  if ( v13 == 2 )
  {
    if ( !(_DWORD)a3 )
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Cannot destroy active NAPI %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hif_napi_destroy",
        (unsigned __int8)a2);
      return 0xFFFFFFFFLL;
    }
    napi_disable(v22 + 2696);
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: NAPI entry %d force disabled",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hif_napi_destroy",
      v14);
  }
  v31 = _netif_napi_del(v22 + 2696);
  synchronize_net(v31);
  v32 = _netif_napi_del(v22 + 5456);
  synchronize_net(v32);
  v33 = *(_DWORD *)(a1 + 772);
  *(_QWORD *)(a1 + 784 + 8 * v21) = 0;
  *(_DWORD *)(a1 + 772) = v33 & ~v18;
  *(_BYTE *)(v22 + 3128) = 0;
  _qdf_mem_free(v22);
  qdf_trace_msg(0x3Du, 8u, "%s: NAPI %d destroyed", v34, v35, v36, v37, v38, v39, v40, v41, "hif_napi_destroy", v14);
  result = 0;
  if ( !*(_DWORD *)(a1 + 772) )
  {
    if ( *(_QWORD *)(a1 + 2432) )
      qdf_cpuhp_unregister((_QWORD **)(a1 + 2432));
    memset((void *)(a1 + 880), 0, 0x600u);
    memset((void *)(a1 + 744), 0, 0x6A8u);
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: no NAPI instances. Zapped",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hif_napi_destroy");
    return 0;
  }
  return result;
}
