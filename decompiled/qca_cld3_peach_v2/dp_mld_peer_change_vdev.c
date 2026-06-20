__int64 __fastcall dp_mld_peer_change_vdev(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x19
  unsigned __int8 v12; // w26
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x23
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
  __int64 v33; // x8
  __int64 v34; // x16
  __int64 v35; // x17
  __int64 v36; // x0
  __int64 v37; // x1
  char v38; // w21
  __int64 v39; // x11
  __int64 v40; // x10
  __int64 v41; // x13
  __int64 v42; // x26
  __int64 v43; // x12
  __int64 v44; // x9
  int v45; // w14
  _QWORD *v46; // x10
  __int64 v47; // x11
  _QWORD *v48; // x12
  _QWORD *v49; // x14
  _DWORD *v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8
  unsigned int v56; // w9
  __int64 v57; // x8
  unsigned __int8 v58; // [xsp+48h] [xbp-8h]

  v11 = *(_QWORD *)(a2 + 24);
  v12 = a3;
  if ( a3 <= 5u )
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
    v16 = *(_QWORD *)(a1 + 8LL * v12 + 12960);
    if ( v16 )
    {
      v17 = *(_DWORD *)(v16 + 43384);
      while ( v17 )
      {
        _X12 = (unsigned int *)(v16 + 43384);
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
          _X8 = (unsigned int *)(v16 + 43456);
          __asm { PRFM            #0x11, [X8] }
          do
            v56 = __ldxr(_X8);
          while ( __stxr(v56 + 1, _X8) );
          v57 = *(_QWORD *)(a1 + 18992);
          if ( (v57 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18992) = v57 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18984);
            *(_QWORD *)(a2 + 24) = v16;
            if ( !v11 )
              goto LABEL_38;
          }
          else
          {
            raw_spin_unlock(a1 + 18984);
            *(_QWORD *)(a2 + 24) = v16;
            if ( !v11 )
              goto LABEL_38;
          }
          if ( *(_DWORD *)(v11 + 43576) )
          {
            *(_WORD *)(v16 + 43580) = *(_WORD *)(v11 + 43580);
            dp_enable_ul_delay(v16, 1, 1);
            *(_DWORD *)(v16 + 43576) = 1;
            *(_DWORD *)(v11 + 43576) = 0;
            dp_enable_ul_delay(v11, 1, 0);
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: change reporting vdev from %d to %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "dp_update_mlo_latency_request_vdev",
              *(unsigned __int8 *)(v11 + 59),
              *(unsigned __int8 *)(v16 + 59));
            v16 = *(_QWORD *)(a2 + 24);
          }
          if ( v16 )
          {
            dp_enable_ul_delay(v11, 2, 0);
            v33 = 0;
            v34 = v16 + 46064;
            v35 = v16 + 46072;
            v36 = v11 + 46072;
            v37 = v11 + 46064;
            v38 = 0;
            v58 = v12;
LABEL_22:
            v39 = v37;
            v40 = v36;
            v41 = v35;
            v42 = v33;
            v43 = 24 * v33;
            v44 = v34;
            do
            {
              if ( *(_DWORD *)(v39 + 24 * v33) )
              {
                *(_DWORD *)(v39 + 24 * v33) = 0;
                v45 = *(_DWORD *)(v39 + v43 - 8);
                *(_DWORD *)(v44 + v43 - 8) = v45;
                if ( v45 == 1 )
                {
                  v46 = (_QWORD *)(v40 + v43);
                  v47 = 0;
                  *(_QWORD *)(v41 + 24 * v33) = *v46;
                  do
                  {
                    v48 = (_QWORD *)(v11 + 44384 + v47);
                    v49 = (_QWORD *)(v16 + 44288 + v47);
                    v47 += 208;
                    *(v49 - 13) = *(v48 - 25);
                    *(v49 - 12) = *(v48 - 24);
                    *(v49 - 11) = *(v48 - 23);
                    *(v49 - 10) = *(v48 - 22);
                    *(v49 - 9) = *(v48 - 21);
                    *(v49 - 8) = *(v48 - 20);
                    *(v49 - 7) = *(v48 - 19);
                    *(v49 - 6) = *(v48 - 18);
                    *(v49 - 5) = *(v48 - 17);
                    *(v49 - 4) = *(v48 - 16);
                    *(v49 - 3) = *(v48 - 15);
                    *(v49 - 2) = *(v48 - 14);
                    *(v49 - 1) = *(v48 - 13);
                    *v49 = *(v48 - 12);
                    v49[1] = *(v48 - 11);
                    v49[2] = *(v48 - 10);
                    v49[3] = *(v48 - 9);
                    v49[4] = *(v48 - 8);
                    v49[5] = *(v48 - 7);
                    v49[6] = *(v48 - 6);
                    v49[7] = *(v48 - 5);
                    v49[8] = *(v48 - 4);
                    v49[9] = *(v48 - 3);
                    v49[10] = *(v48 - 2);
                    v49[11] = *(v48 - 1);
                    v49[12] = *v48;
                  }
                  while ( v47 != 1872 );
LABEL_30:
                  v38 = 1;
                  *v46 = 0;
                  v50 = (_DWORD *)(v44 + 24 * v33);
                  *v50 = 1;
                  qdf_trace_msg(
                    0x45u,
                    5u,
                    "%s: Change Vdev %u to %u for Report Method: %u Type: %u",
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    a11,
                    "dp_qos_latency_copy_stats",
                    *(unsigned __int8 *)(v11 + 59),
                    *(unsigned __int8 *)(v16 + 59),
                    (unsigned int)v42,
                    (unsigned int)*(v50 - 2));
                  _ZF = v42 == 2;
                  v33 = v42 + 1;
                  v37 = v11 + 46064;
                  v34 = v16 + 46064;
                  v12 = v58;
                  v36 = v11 + 46072;
                  v35 = v16 + 46072;
                  if ( !_ZF )
                    goto LABEL_22;
                  goto LABEL_37;
                }
                if ( !v45 )
                {
                  v46 = (_QWORD *)(v40 + v43);
                  *(_QWORD *)(v41 + 24 * v33) = *v46;
                  *(_QWORD *)(v16 + 43600) = *(_QWORD *)(v11 + 43600);
                  *(_QWORD *)(v16 + 43608) = *(_QWORD *)(v11 + 43608);
                  *(_QWORD *)(v16 + 43616) = *(_QWORD *)(v11 + 43616);
                  *(_QWORD *)(v16 + 43624) = *(_QWORD *)(v11 + 43624);
                  *(_QWORD *)(v16 + 43632) = *(_QWORD *)(v11 + 43632);
                  *(_QWORD *)(v16 + 43640) = *(_QWORD *)(v11 + 43640);
                  *(_QWORD *)(v16 + 43648) = *(_QWORD *)(v11 + 43648);
                  *(_QWORD *)(v16 + 43656) = *(_QWORD *)(v11 + 43656);
                  *(_QWORD *)(v16 + 43664) = *(_QWORD *)(v11 + 43664);
                  *(_QWORD *)(v16 + 43672) = *(_QWORD *)(v11 + 43672);
                  *(_QWORD *)(v16 + 43680) = *(_QWORD *)(v11 + 43680);
                  *(_QWORD *)(v16 + 43688) = *(_QWORD *)(v11 + 43688);
                  *(_QWORD *)(v16 + 43696) = *(_QWORD *)(v11 + 43696);
                  *(_QWORD *)(v16 + 43704) = *(_QWORD *)(v11 + 43704);
                  *(_QWORD *)(v16 + 43712) = *(_QWORD *)(v11 + 43712);
                  *(_QWORD *)(v16 + 43720) = *(_QWORD *)(v11 + 43720);
                  *(_QWORD *)(v16 + 43728) = *(_QWORD *)(v11 + 43728);
                  *(_QWORD *)(v16 + 43736) = *(_QWORD *)(v11 + 43736);
                  *(_QWORD *)(v16 + 43744) = *(_QWORD *)(v11 + 43744);
                  *(_QWORD *)(v16 + 43752) = *(_QWORD *)(v11 + 43752);
                  *(_QWORD *)(v16 + 43760) = *(_QWORD *)(v11 + 43760);
                  *(_QWORD *)(v16 + 43768) = *(_QWORD *)(v11 + 43768);
                  *(_QWORD *)(v16 + 43776) = *(_QWORD *)(v11 + 43776);
                  *(_QWORD *)(v16 + 43784) = *(_QWORD *)(v11 + 43784);
                  *(_QWORD *)(v16 + 43792) = *(_QWORD *)(v11 + 43792);
                  *(_QWORD *)(v16 + 43800) = *(_QWORD *)(v11 + 43800);
                  *(_QWORD *)(v16 + 43808) = *(_QWORD *)(v11 + 43808);
                  *(_QWORD *)(v16 + 43816) = *(_QWORD *)(v11 + 43816);
                  *(_QWORD *)(v16 + 43824) = *(_QWORD *)(v11 + 43824);
                  *(_QWORD *)(v16 + 43832) = *(_QWORD *)(v11 + 43832);
                  *(_QWORD *)(v16 + 43840) = *(_QWORD *)(v11 + 43840);
                  *(_QWORD *)(v16 + 43848) = *(_QWORD *)(v11 + 43848);
                  *(_QWORD *)(v16 + 43856) = *(_QWORD *)(v11 + 43856);
                  *(_QWORD *)(v16 + 43864) = *(_QWORD *)(v11 + 43864);
                  *(_QWORD *)(v16 + 43872) = *(_QWORD *)(v11 + 43872);
                  *(_QWORD *)(v16 + 43880) = *(_QWORD *)(v11 + 43880);
                  *(_QWORD *)(v16 + 43888) = *(_QWORD *)(v11 + 43888);
                  *(_QWORD *)(v16 + 43896) = *(_QWORD *)(v11 + 43896);
                  *(_QWORD *)(v16 + 43904) = *(_QWORD *)(v11 + 43904);
                  *(_QWORD *)(v16 + 43912) = *(_QWORD *)(v11 + 43912);
                  *(_QWORD *)(v16 + 43920) = *(_QWORD *)(v11 + 43920);
                  *(_QWORD *)(v16 + 43928) = *(_QWORD *)(v11 + 43928);
                  *(_QWORD *)(v16 + 43936) = *(_QWORD *)(v11 + 43936);
                  *(_QWORD *)(v16 + 43944) = *(_QWORD *)(v11 + 43944);
                  *(_QWORD *)(v16 + 43952) = *(_QWORD *)(v11 + 43952);
                  *(_QWORD *)(v16 + 43960) = *(_QWORD *)(v11 + 43960);
                  *(_QWORD *)(v16 + 43968) = *(_QWORD *)(v11 + 43968);
                  *(_QWORD *)(v16 + 43976) = *(_QWORD *)(v11 + 43976);
                  *(_QWORD *)(v16 + 43984) = *(_QWORD *)(v11 + 43984);
                  *(_QWORD *)(v16 + 43992) = *(_QWORD *)(v11 + 43992);
                  *(_QWORD *)(v16 + 44000) = *(_QWORD *)(v11 + 44000);
                  *(_QWORD *)(v16 + 44008) = *(_QWORD *)(v11 + 44008);
                  *(_QWORD *)(v16 + 44016) = *(_QWORD *)(v11 + 44016);
                  *(_QWORD *)(v16 + 44024) = *(_QWORD *)(v11 + 44024);
                  *(_QWORD *)(v16 + 44032) = *(_QWORD *)(v11 + 44032);
                  *(_QWORD *)(v16 + 44040) = *(_QWORD *)(v11 + 44040);
                  *(_QWORD *)(v16 + 44048) = *(_QWORD *)(v11 + 44048);
                  *(_QWORD *)(v16 + 44056) = *(_QWORD *)(v11 + 44056);
                  *(_QWORD *)(v16 + 44064) = *(_QWORD *)(v11 + 44064);
                  *(_QWORD *)(v16 + 44072) = *(_QWORD *)(v11 + 44072);
                  *(_QWORD *)(v16 + 44080) = *(_QWORD *)(v11 + 44080);
                  *(_QWORD *)(v16 + 44088) = *(_QWORD *)(v11 + 44088);
                  *(_QWORD *)(v16 + 44096) = *(_QWORD *)(v11 + 44096);
                  *(_QWORD *)(v16 + 44104) = *(_QWORD *)(v11 + 44104);
                  *(_QWORD *)(v16 + 44112) = *(_QWORD *)(v11 + 44112);
                  *(_QWORD *)(v16 + 44120) = *(_QWORD *)(v11 + 44120);
                  *(_QWORD *)(v16 + 44128) = *(_QWORD *)(v11 + 44128);
                  *(_QWORD *)(v16 + 44136) = *(_QWORD *)(v11 + 44136);
                  *(_QWORD *)(v16 + 44144) = *(_QWORD *)(v11 + 44144);
                  *(_QWORD *)(v16 + 44152) = *(_QWORD *)(v11 + 44152);
                  *(_QWORD *)(v16 + 44160) = *(_QWORD *)(v11 + 44160);
                  *(_QWORD *)(v16 + 44168) = *(_QWORD *)(v11 + 44168);
                  goto LABEL_30;
                }
              }
              ++v42;
              v44 += 24;
              v41 += 24;
              v40 += 24;
              v39 += 24;
            }
            while ( v42 != 3 );
            v12 = v58;
            if ( (v38 & 1) == 0 )
              goto LABEL_38;
LABEL_37:
            dp_enable_ul_delay(v16, 2, 1);
          }
          goto LABEL_38;
        }
      }
    }
    v51 = *(_QWORD *)(a1 + 18992);
    if ( (v51 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v51 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
      *(_QWORD *)(a2 + 24) = 0;
      goto LABEL_38;
    }
    raw_spin_unlock(a1 + 18984);
  }
  *(_QWORD *)(a2 + 24) = 0;
LABEL_38:
  v52 = *(_QWORD *)(a2 + 24);
  **(_QWORD **)a2 = v52;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Change vdev for ML peer %02x:%02x:%02x:**:**:%02x old vdev %pK id %d new vdev %pK id %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_mld_peer_change_vdev",
    *(unsigned __int8 *)(a2 + 44),
    *(unsigned __int8 *)(a2 + 45),
    *(unsigned __int8 *)(a2 + 46),
    *(unsigned __int8 *)(a2 + 49),
    v11,
    *(unsigned __int8 *)(v11 + 59),
    v52,
    v12);
  return dp_vdev_unref_delete(a1, v11, 17);
}
