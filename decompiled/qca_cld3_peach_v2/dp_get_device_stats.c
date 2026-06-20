__int64 __fastcall dp_get_device_stats(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x21
  unsigned int v17; // w9
  unsigned int v24; // w11
  __int64 v25; // x20
  __int64 v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x23
  void *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  __int64 v47; // x8
  __int64 v48; // x8
  unsigned int v50; // w19
  unsigned int v53; // w9
  __int64 v54; // x8

  if ( a4 != 2 )
  {
    if ( a4 == 1 )
    {
      if ( a2 <= 5u )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 18984);
        }
        else
        {
          raw_spin_lock_bh(a1 + 18984);
          *(_QWORD *)(a1 + 18992) |= 1uLL;
        }
        v16 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
        if ( v16 )
        {
          v17 = *(_DWORD *)(v16 + 43384);
          do
          {
            if ( !v17 )
              goto LABEL_28;
            _X13 = (unsigned int *)(v16 + 43384);
            __asm { PRFM            #0x11, [X13] }
            while ( 1 )
            {
              v24 = __ldxr(_X13);
              if ( v24 != v17 )
                break;
              if ( !__stlxr(v17 + 1, _X13) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v24 == v17;
            v17 = v24;
          }
          while ( !_ZF );
          _X8 = (unsigned int *)(v16 + 43416);
          __asm { PRFM            #0x11, [X8] }
          do
            v53 = __ldxr(_X8);
          while ( __stxr(v53 + 1, _X8) );
          v54 = *(_QWORD *)(a1 + 18992);
          if ( (v54 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18992) = v54 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18984);
            v35 = *(_QWORD *)(v16 + 24);
            if ( !v35 )
              goto LABEL_34;
          }
          else
          {
            raw_spin_unlock(a1 + 18984);
            v35 = *(_QWORD *)(v16 + 24);
            if ( !v35 )
              goto LABEL_34;
          }
          v36 = *(_QWORD *)(v35 + 8);
          v37 = qdf_mem_malloc_atomic_fl(0xA758u, (__int64)"dp_vdev_getstats", 0x1F51u);
          if ( v37 )
          {
            v46 = (__int64)v37;
            dp_aggregate_vdev_stats(v16, (__int64)v37, 0);
            *(_DWORD *)a3 = *(_QWORD *)(v46 + 2472);
            *(_QWORD *)(a3 + 24) = *(_QWORD *)(v46 + 2480);
            *(_DWORD *)(a3 + 4) = *(_DWORD *)(v46 + 2572);
            *(_DWORD *)(a3 + 8) = *(_DWORD *)(v46 + 232)
                                + *(_DWORD *)(v46 + 236)
                                + *(_DWORD *)(v46 + 192)
                                + *(_DWORD *)(v46 + 264)
                                + *(_DWORD *)(v46 + 240)
                                + *(_DWORD *)(v46 + 2568);
            if ( (wlan_cfg_get_vdev_stats_hw_offload_config(*(_QWORD *)(v36 + 40)) & 1) != 0 )
            {
              *(_DWORD *)(a3 + 12) = *(_DWORD *)(v46 + 2440) + *(_DWORD *)(v46 + 2424) + *(_DWORD *)(v46 + 2456);
              v47 = *(_QWORD *)(v46 + 2448) + *(_QWORD *)(v46 + 2432) + *(_QWORD *)(v46 + 2464);
            }
            else
            {
              *(_DWORD *)(a3 + 12) = *(_QWORD *)(v46 + 5216);
              v47 = *(_QWORD *)(v46 + 5224);
            }
            *(_QWORD *)(a3 + 32) = v47;
            *(_DWORD *)(a3 + 16) = *(_DWORD *)(v46 + 5580)
                                 + *(_DWORD *)(v46 + 5576)
                                 + *(_DWORD *)(v46 + 5584)
                                 + *(_DWORD *)(v46 + 5588)
                                 + *(_DWORD *)(v46 + 5592)
                                 + *(_DWORD *)(v46 + 5596)
                                 + *(_DWORD *)(v46 + 5600);
            *(_DWORD *)(a3 + 20) = *(_DWORD *)(v46 + 5480)
                                 + *(_DWORD *)(v46 + 6588)
                                 + *(_DWORD *)(v46 + 6592)
                                 + *(_DWORD *)(v46 + 6596)
                                 + *(_DWORD *)(v46 + 5472)
                                 + *(_DWORD *)(v46 + 6916)
                                 + *(_DWORD *)(v46 + 5496);
            _qdf_mem_free(v46);
            v50 = 0;
            goto LABEL_37;
          }
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: %pK: DP alloc failure - unable to get alloc vdev stats",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "dp_vdev_getstats",
            v36);
LABEL_34:
          v50 = 16;
LABEL_37:
          dp_vdev_unref_delete(a1, v16, 7u, (unsigned int *)v35, v27, v28, v29, v30, v31, v32, v33, v34);
          return v50;
        }
LABEL_28:
        v48 = *(_QWORD *)(a1 + 18992);
        if ( (v48 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 18992) = v48 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 18984);
        }
        else
        {
          raw_spin_unlock(a1 + 18984);
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x3Fu,
        2u,
        "apstats cannot be updated for this input type %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a4);
    }
    return 16;
  }
  if ( a2 )
    return 16;
  v25 = *(_QWORD *)(a1 + 72);
  if ( !v25 )
    return 16;
  dp_aggregate_pdev_stats((_QWORD *)v25);
  *(_DWORD *)a3 = *(_QWORD *)(v25 + 2992);
  *(_QWORD *)(a3 + 24) = *(_QWORD *)(v25 + 3000);
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(v25 + 3092);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(v25 + 712)
                      + *(_DWORD *)(v25 + 784)
                      + *(_DWORD *)(v25 + 752)
                      + *(_DWORD *)(v25 + 756)
                      + *(_DWORD *)(v25 + 760)
                      + *(_DWORD *)(v25 + 3088)
                      + *(_DWORD *)(v25 + 92240);
  if ( (wlan_cfg_get_vdev_stats_hw_offload_config(*(_QWORD *)(*(_QWORD *)(v25 + 8) + 40LL)) & 1) != 0 )
  {
    *(_DWORD *)(a3 + 12) = *(_DWORD *)(v25 + 2960) + *(_DWORD *)(v25 + 2944) + *(_DWORD *)(v25 + 2976);
    v26 = *(_QWORD *)(v25 + 2968) + *(_QWORD *)(v25 + 2952) + *(_QWORD *)(v25 + 2984);
  }
  else
  {
    *(_DWORD *)(a3 + 12) = *(_QWORD *)(v25 + 5736);
    v26 = *(_QWORD *)(v25 + 5744);
  }
  *(_QWORD *)(a3 + 32) = v26;
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v25 + 496)
                       + *(_DWORD *)(v25 + 492)
                       + *(_DWORD *)(v25 + 6096)
                       + *(_DWORD *)(v25 + 6100)
                       + *(_DWORD *)(v25 + 6104)
                       + *(_DWORD *)(v25 + 6108)
                       + *(_DWORD *)(v25 + 6112)
                       + *(_DWORD *)(v25 + 6116)
                       + *(_DWORD *)(v25 + 6120);
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(v25 + 7112)
                       + *(_DWORD *)(v25 + 7108)
                       + *(_DWORD *)(v25 + 7116)
                       + *(_DWORD *)(v25 + 5992)
                       + *(_DWORD *)(v25 + 7436)
                       + *(_DWORD *)(v25 + 6000)
                       + *(_DWORD *)(v25 + 400)
                       + *(_DWORD *)(v25 + 404)
                       + *(_DWORD *)(v25 + 388)
                       + *(_DWORD *)(v25 + 384)
                       + *(_DWORD *)(v25 + 392)
                       + *(_DWORD *)(v25 + 396)
                       + *(_DWORD *)(v25 + 6016);
  return 0;
}
