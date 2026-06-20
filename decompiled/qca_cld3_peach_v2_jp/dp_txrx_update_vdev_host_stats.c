__int64 __fastcall dp_txrx_update_vdev_host_stats(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned __int16 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x20
  unsigned __int64 v20; // x8
  unsigned int v21; // w9
  unsigned int v28; // w11
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v51; // w9
  __int64 v52; // x8

  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18928);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18928);
      *(_QWORD *)(a1 + 18936) |= 1uLL;
    }
    v19 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v19 )
    {
      v20 = v19 + 40960;
      v21 = *(_DWORD *)(v19 + 42560);
      while ( v21 )
      {
        _X13 = (unsigned int *)(v19 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v28 = __ldxr(_X13);
          if ( v28 != v21 )
            break;
          if ( !__stlxr(v21 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v28 == v21;
        v21 = v28;
        if ( _ZF )
        {
          while ( 1 )
          {
            _X8 = (unsigned int *)(v20 + 1632);
            __asm { PRFM            #0x11, [X8] }
            do
              v51 = __ldxr(_X8);
            while ( __stxr(v51 + 1, _X8) );
            v52 = *(_QWORD *)(a1 + 18936);
            if ( (v52 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 18936) = v52 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 18928);
              v20 = a4;
              if ( !a4 )
                goto LABEL_27;
            }
            else
            {
              raw_spin_unlock(a1 + 18928);
              v20 = a4;
              if ( !a4 )
                goto LABEL_27;
            }
            if ( (_DWORD)v20 != 1 )
            {
              qdf_trace_msg(
                0x38u,
                4u,
                "%s: Invalid stats_id %d",
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                "dp_txrx_update_vdev_host_stats",
                a4);
              goto LABEL_27;
            }
            if ( !a3 )
              break;
            if ( !a5 )
            {
              v37 = *(_QWORD *)(v19 + 624);
              *(_QWORD *)(v19 + 616) += *(_QWORD *)(a3 + 216);
              v38 = v37 + *(_QWORD *)(a3 + 224);
              LODWORD(v37) = *(_DWORD *)(v19 + 632);
              *(_QWORD *)(v19 + 624) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 232);
              LODWORD(v37) = *(_DWORD *)(v19 + 636);
              *(_DWORD *)(v19 + 632) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 236);
              LODWORD(v37) = *(_DWORD *)(v19 + 640);
              *(_DWORD *)(v19 + 636) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 240);
              LODWORD(v37) = *(_DWORD *)(v19 + 644);
              *(_DWORD *)(v19 + 640) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 244);
              LODWORD(v37) = *(_DWORD *)(v19 + 648);
              *(_DWORD *)(v19 + 644) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 248);
              LODWORD(v37) = *(_DWORD *)(v19 + 652);
              *(_DWORD *)(v19 + 648) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 252);
              LODWORD(v37) = *(_DWORD *)(v19 + 656);
              *(_DWORD *)(v19 + 652) = v38;
              LODWORD(v38) = v37 + *(_DWORD *)(a3 + 256);
              LODWORD(v37) = *(_DWORD *)(v19 + 660);
              *(_DWORD *)(v19 + 656) = v38;
              v20 = (unsigned int)(v37 + *(_DWORD *)(a3 + 260));
              *(_DWORD *)(v19 + 660) = v20;
              goto LABEL_27;
            }
            __break(0x5512u);
          }
          qdf_trace_msg(
            0x89u,
            2u,
            "%s: %pK: Invalid host stats buf",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "dp_txrx_update_vdev_me_stats",
            *(_QWORD *)(*(_QWORD *)(v19 + 24) + 8LL));
          qdf_trace_msg(
            0x89u,
            2u,
            "%s: %pK: Invalid host stats buf",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "dp_txrx_update_vdev_igmp_me_stats",
            *(_QWORD *)(*(_QWORD *)(v19 + 24) + 8LL));
LABEL_27:
          dp_vdev_unref_delete(a1, v19, 7u, (unsigned int *)v20, v29, v30, v31, v32, v33, v34, v35, v36);
          return 0;
        }
      }
    }
    v39 = *(_QWORD *)(a1 + 18936);
    if ( (v39 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v39 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  qdf_trace_msg(
    0x89u,
    2u,
    "%s: %pK: Invalid vdev handle",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_txrx_update_vdev_host_stats",
    a1);
  return 16;
}
