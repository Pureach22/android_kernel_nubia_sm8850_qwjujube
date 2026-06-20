__int64 __fastcall dp_rx_tm_flush_by_vdev_id(unsigned __int8 *a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x21
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w8
  __int64 v15; // x21
  unsigned __int64 v16; // x25
  __int64 v17; // x28
  int v18; // w8
  unsigned __int8 *v19; // x19
  unsigned __int64 v20; // x23
  unsigned __int8 *v21; // x9
  __int64 v22; // x8
  unsigned __int8 *v23; // x10
  unsigned __int8 *v24; // x11
  unsigned __int8 **v25; // x12
  __int64 v26; // x24
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  unsigned __int64 v36; // x24
  __int64 v37; // x8
  __int64 v38; // x27
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 v41; // x22
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x13
  unsigned __int64 v45; // x5
  unsigned __int64 v46; // x6
  _DWORD *v47; // x8
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x8
  unsigned int *v51; // x8
  unsigned int v52; // w10
  __int64 v53; // x8
  __int64 v54; // x19
  signed int v55; // w22
  unsigned __int8 *v56; // x23
  unsigned __int64 v57; // x26
  unsigned int v58; // w0
  __int64 v59; // x5
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x4
  unsigned int v69; // w1
  const char *v70; // x2
  unsigned __int64 v71; // kr08_8
  unsigned __int64 v72; // x8
  unsigned __int64 v73; // x8
  unsigned __int64 v74; // kr00_8
  unsigned __int64 v75; // x5
  unsigned __int64 v77; // [xsp+0h] [xbp-30h]
  unsigned __int8 v78; // [xsp+Ch] [xbp-24h]
  unsigned __int64 v79; // [xsp+10h] [xbp-20h]
  __int64 v80; // [xsp+18h] [xbp-18h]
  _QWORD v81[2]; // [xsp+20h] [xbp-10h] BYREF

  v81[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  context = dp_get_context();
  v14 = *a1;
  v80 = context;
  v78 = a2;
  v77 = StatusReg;
  if ( *a1 )
  {
    v15 = a2;
    v16 = 0;
    v17 = 1LL << a2;
    v81[0] = 0;
    v79 = _ReadStatusReg(SP_EL0);
    do
    {
      v19 = *(unsigned __int8 **)(*((_QWORD *)a1 + 3) + 8 * v16);
      if ( v19 )
      {
        raw_spin_lock_bh(v19 + 460);
        __isb(0xFu);
        v20 = _ReadStatusReg(CNTVCT_EL0);
        v21 = *((unsigned __int8 **)v19 + 55);
        if ( v21 == v19 + 440 )
        {
          v22 = 0;
        }
        else
        {
          v22 = 0;
          do
          {
            v23 = *(unsigned __int8 **)v21;
            if ( v21[86] == (_DWORD)v15 )
            {
              --*((_DWORD *)v19 + 114);
              v24 = *(unsigned __int8 **)v21;
              v25 = *((unsigned __int8 ***)v21 + 1);
              *((_QWORD *)v21 + 1) = 0;
              *((_QWORD *)v24 + 1) = v25;
              *v25 = v24;
              *(_QWORD *)v21 = v22;
              v22 = (__int64)v21;
            }
            v21 = v23;
          }
          while ( v23 != v19 + 440 );
        }
        v26 = v22;
        raw_spin_unlock_bh(v19 + 460);
        v35 = v26;
        __isb(0xFu);
        v36 = _ReadStatusReg(CNTVCT_EL0);
        if ( v35 )
        {
          do
          {
            v37 = *(_QWORD *)(v35 + 72);
            v38 = *(_QWORD *)v35;
            *(_QWORD *)v35 = 0;
            if ( (v37 & 0xFE000000) != 0 )
            {
              v39 = *(_QWORD *)(v35 + 216) + *(unsigned int *)(v35 + 212);
              v40 = *(_QWORD *)(v39 + 8);
              *(_QWORD *)(v39 + 8) = 0;
              v37 = *(_QWORD *)(v35 + 72);
              *(_QWORD *)v35 = v40;
            }
            *((_DWORD *)v19 + 133) += BYTE3(v37);
            do
            {
              v41 = *(_QWORD *)v35;
              _qdf_nbuf_free(v35);
              v35 = v41;
            }
            while ( v41 );
            v35 = v38;
          }
          while ( v38 );
        }
        __isb(0xFu);
        v42 = _ReadStatusReg(CNTVCT_EL0);
        v43 = 10 * (v36 - v20);
        v44 = 10 * (v42 - v36);
        if ( v43 < v36 - v20 )
          v45 = 10 * ((v36 - v20) / 0xC0);
        else
          v45 = v43 / 0xC0;
        if ( v44 < v42 - v36 )
          v46 = 10 * ((v42 - v36) / 0xC0);
        else
          v46 = v44 / 0xC0;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Thread: %u lock held time: %llu us flush time: %llu us",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "dp_rx_tm_flush_nbuf_list",
          *v19,
          v45,
          v46,
          v77);
        if ( (unsigned int)v15 <= 5 )
        {
          v47 = *(_DWORD **)(v80 + 752);
          if ( *(v47 - 1) != 661844135 )
            __break(0x8228u);
          v48 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))v47)((unsigned int)v15, v81);
          if ( !(_DWORD)v48 && !*(_QWORD *)&v19[8 * v15 + 3904] )
          {
            v49 = v81[0];
            if ( v81[0] )
            {
              ++*(_DWORD *)(v79 + 16);
              v50 = *(_QWORD *)(v49 + 1320);
              v51 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v50);
              do
                v52 = __ldxr(v51);
              while ( __stxr(v52 + 1, v51) );
              v53 = *(_QWORD *)(v79 + 16) - 1LL;
              *(_DWORD *)(v79 + 16) = v53;
              if ( !v53 || !*(_QWORD *)(v79 + 16) )
                preempt_schedule_notrace(v48);
            }
            v18 = *((_DWORD *)v19 + 139);
            *(_QWORD *)&v19[8 * v15 + 3904] = v81[0];
            *((_DWORD *)v19 + 139) = v18 + 1;
          }
          qdf_event_reset((__int64)&v19[40 * (unsigned int)v15 + 176]);
          *((_QWORD *)v19 + 54) |= v17;
        }
        *((_QWORD *)v19 + 53) |= 0x10uLL;
        _wake_up(v19 + 1136, 1, 1, 0);
        v14 = *a1;
      }
      ++v16;
    }
    while ( v16 < v14 );
    if ( v14 )
    {
      v54 = 0;
      v55 = 6000;
      while ( 1 )
      {
        v56 = *(unsigned __int8 **)(*((_QWORD *)a1 + 3) + 8 * v54);
        if ( v56 )
          break;
LABEL_40:
        if ( ++v54 >= (unsigned __int64)*a1 )
          goto LABEL_57;
      }
      if ( (unsigned int)v15 >= 6 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Invalid vdev id received %u",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "dp_rx_tm_wait_vdev_del_event",
          (unsigned int)v15);
        goto LABEL_57;
      }
      __isb(0xFu);
      v57 = _ReadStatusReg(CNTVCT_EL0);
      v58 = qdf_wait_single_event((__int64)&v56[40 * (unsigned int)v15 + 176], v55);
      v68 = *v56;
      if ( v58 == 15 )
      {
        v69 = 2;
        v70 = "%s: thread:%d timed out waiting for napi gro flush";
      }
      else
      {
        v59 = v58;
        if ( v58 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: thread:%d event wait failed with status: %d",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "dp_rx_tm_wait_vdev_del_event",
            v68,
            v58);
LABEL_49:
          __isb(0xFu);
          v71 = _ReadStatusReg(CNTVCT_EL0) - v57;
          if ( 10 * v71 < v71 )
            v72 = 10 * (v71 / 0xC0);
          else
            v72 = 10 * v71 / 0xC0;
          if ( v55 >= 11 )
          {
            v73 = (unsigned __int64)((v72 * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 7;
            if ( v73 >= (unsigned int)v55 )
              v55 = 10;
            else
              v55 -= v73;
          }
          goto LABEL_40;
        }
        v69 = 8;
        v70 = "%s: thread:%d napi gro flush successfully";
      }
      qdf_trace_msg(
        0x45u,
        v69,
        v70,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "dp_rx_tm_wait_vdev_del_event",
        v68,
        v59,
        v77);
      goto LABEL_49;
    }
  }
LABEL_57:
  __isb(0xFu);
  v74 = _ReadStatusReg(CNTVCT_EL0) - v77;
  if ( 10 * v74 < v74 )
    v75 = 10 * (v74 / 0xC0);
  else
    v75 = 10 * v74 / 0xC0;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Vdev: %u total flush time: %llu us",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "dp_rx_tm_flush_by_vdev_id",
    v78,
    v75,
    v77);
  _ReadStatusReg(SP_EL0);
  return 0;
}
