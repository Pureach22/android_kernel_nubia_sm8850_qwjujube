__int64 __fastcall mlo_update_cache_link_assoc_rsp(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 v13; // x24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x25
  int v25; // w26
  unsigned __int8 *v26; // x21
  unsigned int v27; // w22
  const char *v28; // x2
  int v29; // w8
  int v30; // w8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void *v49; // x0
  size_t v50; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  int v60; // w9
  int v61; // w10
  int v62; // w11
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7

  v11 = a2;
  if ( a2 == 255 )
    return 4;
  v13 = *(_QWORD *)(a1 + 1360);
  if ( !v13 )
  {
    v28 = "%s: invalid mlo_dev_ctx";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v28, a4, a5, a6, a7, a8, a9, a10, a11, "mlo_update_cache_link_assoc_rsp");
    return 4;
  }
  qdf_mutex_acquire(v13 + 1656);
  v24 = *(unsigned __int8 **)(v13 + 2224);
  if ( !v24 )
  {
    qdf_mutex_release(v13 + 1656);
    v28 = "%s: invalid sta_ctx";
    goto LABEL_9;
  }
  v25 = v24[126];
  v26 = v24 + 120;
  if ( v25 == v11 )
  {
    v27 = 0;
  }
  else
  {
    if ( v25 == 255 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: find free slot %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "mlo_update_cache_link_assoc_rsp",
        0);
      v27 = 0;
    }
    else
    {
      v27 = 255;
    }
    v29 = v24[150];
    if ( v29 == v11 )
    {
      v26 = v24 + 144;
      v27 = 1;
    }
    else
    {
      if ( v29 == 255 && v25 != 255 )
      {
        v27 = 1;
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: find free slot %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "mlo_update_cache_link_assoc_rsp",
          1);
      }
      v30 = v24[174];
      if ( v30 == v11 )
      {
        v26 = v24 + 168;
        v27 = 2;
      }
      else
      {
        if ( (v30 & v27) == 0xFF )
        {
          v27 = 2;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: find free slot %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "mlo_update_cache_link_assoc_rsp",
            2);
        }
        else if ( v27 == 255 )
        {
          qdf_mutex_release(v13 + 1656);
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: no free slot, link id %d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "mlo_update_cache_link_assoc_rsp",
            v11);
          return 4;
        }
        v26 += 24 * v27;
      }
    }
  }
  v39 = *((_QWORD *)v26 + 2);
  if ( v39 )
  {
    _qdf_mem_free(v39);
    *((_QWORD *)v26 + 2) = 0;
  }
  v40 = _qdf_mem_malloc(*a3, "mlo_update_cache_link_assoc_rsp", 2295);
  *((_QWORD *)v26 + 2) = v40;
  if ( v40 )
  {
    wlan_vdev_get_bss_peer_mld_mac(a1, v26, v41, v42, v43, v44, v45, v46, v47, v48);
    v26[6] = v11;
    v49 = *((void **)v26 + 2);
    v50 = *a3;
    *((_DWORD *)v26 + 2) = v50;
    qdf_mem_copy(v49, *((const void **)a3 + 1), v50);
    if ( v26 )
    {
      v59 = *v26;
      v60 = v26[1];
      v61 = v26[2];
      v62 = v26[5];
    }
    else
    {
      v61 = 0;
      v59 = 0;
      v60 = 0;
      v62 = 0;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev %d link %d rsp len %d updated to slot %d ap mld %02x:%02x:%02x:**:**:%02x",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "mlo_update_cache_link_assoc_rsp",
      *(unsigned __int8 *)(a1 + 168),
      v11,
      *a3,
      v27,
      v59,
      v60,
      v61,
      v62);
    qdf_mutex_release(v13 + 1656);
    return 0;
  }
  else
  {
    qdf_mutex_release(v13 + 1656);
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: no free mem, link id %d, len %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "mlo_update_cache_link_assoc_rsp",
      v11,
      *a3);
    return 4;
  }
}
