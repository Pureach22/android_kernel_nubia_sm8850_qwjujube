__int64 __fastcall dp_print_per_link_stats(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x21
  unsigned int v14; // w9
  unsigned int v21; // w11
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
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x23
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  __int64 v52; // x21
  __int64 v53; // x23
  unsigned int *v54; // x8
  __int64 v55; // x24
  unsigned int v57; // w9
  __int64 v58; // x8

  if ( a2 <= 5u )
  {
    v11 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 18928);
    }
    else
    {
      raw_spin_lock_bh(result + 18928);
      *(_QWORD *)(v11 + 18936) |= 1uLL;
    }
    v13 = *(_QWORD *)(v11 + 8LL * a2 + 12912);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 42560);
      while ( v14 )
      {
        _X13 = (unsigned int *)(v13 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v21 = __ldxr(_X13);
          if ( v21 != v14 )
            break;
          if ( !__stlxr(v14 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v21 == v14;
        v14 = v21;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v13 + 42596);
          __asm { PRFM            #0x11, [X8] }
          do
            v57 = __ldxr(_X8);
          while ( __stxr(v57 + 1, _X8) );
          v58 = *(_QWORD *)(v11 + 18936);
          if ( (v58 & 1) != 0 )
          {
            *(_QWORD *)(v11 + 18936) = v58 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v11 + 18928);
          }
          else
          {
            raw_spin_unlock(v11 + 18928);
          }
          v23 = dp_vdev_bss_peer_ref_n_get(v11, v13, 8u);
          if ( v23 )
          {
            v32 = v23;
            v33 = _qdf_mem_malloc(0xE90u, "dp_print_per_link_stats", 11742);
            if ( v33 )
            {
              v42 = v33;
              dp_get_peer_stats((__int64 *)v32, v33, v34, v35, v36, v37, v38, v39, v40, v41);
              dp_print_peer_stats(v32, v42, v43, v44, v45, v46, v47, v48, v49, v50);
              _qdf_mem_free(v42);
            }
            else
            {
              v55 = jiffies;
              if ( dp_print_per_link_stats___last_ticks_561 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: peer_stats malloc failed, vdev_id: %u, peer_id: %u",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  "dp_print_per_link_stats",
                  a2,
                  *(unsigned __int16 *)(v32 + 16));
                dp_print_per_link_stats___last_ticks_561 = v55;
              }
            }
            dp_peer_unref_delete(v32, 8u, v34, v35, v36, v37, v38, v39, v40, v41);
          }
          else
          {
            v53 = jiffies;
            v54 = (unsigned int *)(dp_print_per_link_stats___last_ticks_559 - jiffies);
            if ( dp_print_per_link_stats___last_ticks_559 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: Peer is NULL, vdev_id: %u",
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                "dp_print_per_link_stats",
                a2);
              dp_print_per_link_stats___last_ticks_559 = v53;
            }
          }
          return dp_vdev_unref_delete(v11, v13, 8u, v54, v24, v25, v26, v27, v28, v29, v30, v31);
        }
      }
    }
    v51 = *(_QWORD *)(v11 + 18936);
    if ( (v51 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 18936) = v51 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v11 + 18928);
    }
    else
    {
      result = raw_spin_unlock(v11 + 18928);
    }
  }
  v52 = jiffies;
  if ( dp_print_per_link_stats___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: vdev is null for vdev_id: %u",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "dp_print_per_link_stats",
               a2);
    dp_print_per_link_stats___last_ticks = v52;
  }
  return result;
}
