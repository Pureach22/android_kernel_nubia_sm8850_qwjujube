__int64 __fastcall dp_vdev_update_lmacid(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w23
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x20
  unsigned int v17; // w8
  unsigned int v24; // w10
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x8
  __int64 v42; // x4
  __int64 v43; // x8
  __int64 v44; // x9
  char v45; // w8
  __int64 v46; // x8
  __int64 v47; // x8
  unsigned int v51; // w9
  __int64 v52; // x8

  v11 = a2;
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
    v16 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v16 )
    {
      v17 = *(_DWORD *)(v16 + 42560);
      while ( v17 )
      {
        _X12 = (unsigned int *)(v16 + 42560);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v24 = __ldxr(_X12);
          if ( v24 != v17 )
            break;
          if ( !__stlxr(v17 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v24 == v17;
        v17 = v24;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v16 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v51 = __ldxr(_X8);
          while ( __stxr(v51 + 1, _X8) );
          v52 = *(_QWORD *)(a1 + 18936);
          if ( (v52 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v52 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: update mac id %d for vdev id %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "dp_vdev_update_lmacid",
            a3,
            a2);
          v41 = (unsigned int *)*(unsigned int *)(v16 + 32);
          *(_BYTE *)(v16 + 62) = a3;
          if ( (_DWORD)v41 == 4 )
          {
            v42 = *(_QWORD *)(v16 + 24);
            if ( v42 && a3 <= 1u && (v43 = *(_QWORD *)(v42 + 95560)) != 0 )
            {
              v44 = v43 + 18528LL * a3;
              *(_BYTE *)(v44 + 9) = *(_BYTE *)(v16 + 59);
              v45 = *(_BYTE *)(v16 + 62);
              *(_QWORD *)(v44 + 16) = v16;
              *(_BYTE *)(v44 + 8) = v45;
              v46 = *(unsigned int *)(*(_QWORD *)(v16 + 42696) + 16LL);
              *(_DWORD *)(v44 + 32) = v46;
              *(_DWORD *)(v44 + 28) = *(_DWORD *)(*(_QWORD *)(v16 + 42696) + 12LL);
              *(_DWORD *)(v44 + 24) = *(_DWORD *)(*(_QWORD *)(v16 + 42696) + 8LL);
              if ( (unsigned int)v46 > 2 )
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: Band Unknown: %d",
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  "dp_monitor_update_mac_vdev_map",
                  (unsigned int)v46);
              else
                *(_DWORD *)(v42 + 4 * v46 + 272) = *(unsigned __int8 *)(v16 + 62);
              *(_BYTE *)(*(_QWORD *)(v16 + 42696) + 20LL) = *(_BYTE *)(v16 + 62);
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: mac_id %d vdev_id %d ch_num: %d freq: %d band %d",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "dp_monitor_update_mac_vdev_map",
                *(_DWORD *)(*(_QWORD *)(v16 + 42696) + 16LL));
            }
            else
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: map skipped pdev: %pK mac_id: %u vdev_id: %u",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "dp_monitor_update_mac_vdev_map");
            }
          }
          return dp_vdev_unref_delete(a1, v16, 7u, v41, v33, v34, v35, v36, v37, v38, v39, v40);
        }
      }
    }
    v47 = *(_QWORD *)(a1 + 18936);
    if ( (v47 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v47 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  return qdf_trace_msg(0x45u, 2u, "%s: invalid vdev %d", a4, a5, a6, a7, a8, a9, a10, a11, "dp_vdev_update_lmacid", v11);
}
