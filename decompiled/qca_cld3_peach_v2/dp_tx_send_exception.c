__int64 __fastcall dp_tx_send_exception(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned __int16 *a4)
{
  __int64 ref_by_id_1; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x21
  char v18; // w8
  int v19; // w8
  __int64 v20; // x9
  __int64 v21; // x0
  char is_opt_wifi_dp_enabled; // w0
  __int64 v23; // x8
  __int64 v24; // x0
  unsigned int v25; // w9
  int v27; // w9
  bool v28; // w10
  const char *v29; // x2
  char v31; // w8
  unsigned int v32; // w23
  __int64 v33; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v35; // x23
  __int64 v36; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  int v41; // w9
  int v42; // w8
  int v43; // w23
  __int64 (__fastcall *v44)(__int64, __int64, __int64, unsigned __int16 *); // x8
  __int64 v45; // x0
  __int64 v46; // x1
  int v47; // w3
  __int64 v48; // x4
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w8
  unsigned int v64; // w10
  int v66; // w9
  unsigned __int8 *v67; // x8
  __int64 v68; // x4
  __int64 v69; // x5
  __int64 v70; // x6
  __int64 v71; // x7
  int v72; // w8
  int v73; // w8
  unsigned int v75; // w9
  _QWORD v76[15]; // [xsp+0h] [xbp-F0h] BYREF
  __int64 v77; // [xsp+78h] [xbp-78h] BYREF
  __int64 v78; // [xsp+80h] [xbp-70h]
  __int64 v79; // [xsp+88h] [xbp-68h]
  __int64 v80; // [xsp+90h] [xbp-60h]
  __int64 v81; // [xsp+98h] [xbp-58h]
  __int64 v82; // [xsp+A0h] [xbp-50h]
  __int64 v83; // [xsp+A8h] [xbp-48h]
  _QWORD v84[2]; // [xsp+B0h] [xbp-40h] BYREF
  __int64 v85; // [xsp+C0h] [xbp-30h]
  __int64 v86; // [xsp+C8h] [xbp-28h]
  __int64 v87; // [xsp+D0h] [xbp-20h]
  __int64 v88; // [xsp+D8h] [xbp-18h]
  __int64 v89; // [xsp+E0h] [xbp-10h]
  __int64 v90; // [xsp+E8h] [xbp-8h]

  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84[1] = 0;
  v85 = 0;
  v83 = 0;
  v84[0] = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 0x13u);
  if ( !ref_by_id_1 )
  {
LABEL_52:
    if ( is_dp_verbose_debug_enabled == 1 )
      qdf_trace_msg(0x45u, 8u, "%s: pkt send failed", v8, v9, v10, v11, v12, v13, v14, v15, "dp_tx_send_exception");
    goto LABEL_54;
  }
  v16 = *(_QWORD *)(ref_by_id_1 + 24);
  v17 = ref_by_id_1;
  if ( !v16 || (qdf_mem_set(&v77, 0x70u, 0), !a4) )
  {
LABEL_51:
    dp_vdev_unref_delete(a1, v17, 0x13u, (unsigned int *)v16, v8, v9, v10, v11, v12, v13, v14, v15);
    goto LABEL_52;
  }
  v18 = *((_BYTE *)a4 + 2);
  BYTE6(v87) = 0;
  BYTE4(v78) = v18;
  if ( (is_dp_verbose_debug_enabled & 1) != 0 )
  {
    v67 = *(unsigned __int8 **)(a3 + 224);
    if ( v67 )
    {
      v68 = *v67;
      v69 = v67[1];
      v70 = v67[2];
      v71 = v67[5];
    }
    else
    {
      v70 = 0;
      v68 = 0;
      v69 = 0;
      v71 = 0;
    }
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: skb %02x:%02x:%02x:**:**:%02x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_tx_send_exception",
      v68,
      v69,
      v70,
      v71);
  }
  ++*(_QWORD *)(v17 + 408);
  if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
    v19 = *(unsigned __int16 *)(a3 + 66);
  else
    v19 = 0;
  v20 = *(_QWORD *)(v17 + 24);
  *(_QWORD *)(v17 + 416) += (unsigned int)(*(_DWORD *)(a3 + 112) + v19);
  v21 = *(_QWORD *)(*(_QWORD *)(v20 + 8) + 40LL);
  BYTE4(v77) = *(_BYTE *)(v17 + 59);
  if ( *(_BYTE *)(v21 + 540) != 1 )
    goto LABEL_11;
  is_opt_wifi_dp_enabled = ipa_config_is_opt_wifi_dp_enabled();
  v23 = *(_QWORD *)(v17 + 24);
  if ( (is_opt_wifi_dp_enabled & 1) != 0 )
  {
    v21 = *(_QWORD *)(*(_QWORD *)(v23 + 8) + 40LL);
LABEL_11:
    if ( (wlan_cfg_is_lapb_enabled(v21) & 1) != 0 )
    {
      v23 = *(_QWORD *)(v17 + 24);
      if ( (*(_DWORD *)(a3 + 168) & 0xF000000) == 0xB000000 )
        LOBYTE(v23) = *(_BYTE *)(*(_QWORD *)(v23 + 8) + 7201LL) - 1;
      else
        LODWORD(v23) = *(unsigned __int16 *)(a3 + 124) % (*(unsigned __int8 *)(*(_QWORD *)(v23 + 8) + 7201LL) - 1);
    }
    else
    {
      LOWORD(v23) = (unsigned int)*(_WORD *)(a3 + 124)
                  % *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v17 + 24) + 8LL) + 7201LL);
    }
    goto LABEL_17;
  }
  LOBYTE(v23) = *(_BYTE *)v23;
LABEL_17:
  BYTE5(v77) = v23;
  dp_tx_update_proto_stats();
  v25 = *((unsigned __int8 *)a4 + 2);
  _ZF = v25 <= 0x10 || v25 == 31;
  v27 = !_ZF;
  v28 = (a4[6] & 1) != 0 && a4[7] == 0;
  if ( ((v27 | ((unsigned __int8)(a4[6] & 2) >> 1)) & 1) != 0 )
  {
    if ( (a4[6] & 2) == 0 )
    {
LABEL_28:
      v29 = "%s: Invalid parameters in exception path";
LABEL_50:
      qdf_trace_msg(0x7Du, 2u, v29, v8, v9, v10, v11, v12, v13, v14, v15, "dp_tx_send_exception");
      goto LABEL_51;
    }
  }
  else
  {
    v31 = a4[2] > 6u || *((_DWORD *)a4 + 2) > 0xCu || v28;
    if ( (v31 & 1) != 0 )
      goto LABEL_28;
  }
  v32 = *a4;
  if ( v32 != 0xFFFF )
  {
    v33 = *(_QWORD *)(*(_QWORD *)(v17 + 24) + 8LL);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v33 + 13304);
    }
    else
    {
      raw_spin_lock_bh(v33 + 13304);
      *(_QWORD *)(v33 + 13312) |= 1uLL;
    }
    if ( *(_DWORD *)(v33 + 13324) > v32 )
    {
      v35 = *(_QWORD *)(*(_QWORD *)(v33 + 13136) + 8LL * v32);
      if ( !v35 )
        goto LABEL_45;
      if ( *(unsigned __int8 *)(v35 + 388) <= 2u )
      {
        v58 = *(_DWORD *)(v35 + 40);
        while ( v58 )
        {
          _X12 = (unsigned int *)(v35 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v64 = __ldxr(_X12);
            if ( v64 != v58 )
              break;
            if ( !__stlxr(v58 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v64 == v58;
          v58 = v64;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v35 + 340);
            __asm { PRFM            #0x11, [X8] }
            do
              v75 = __ldxr(_X8);
            while ( __stxr(v75 + 1, _X8) );
            goto LABEL_45;
          }
        }
      }
    }
    v35 = 0;
LABEL_45:
    v36 = *(_QWORD *)(v33 + 13312);
    if ( (v36 & 1) != 0 )
    {
      *(_QWORD *)(v33 + 13312) = v36 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v33 + 13304);
      if ( v35 )
        goto LABEL_47;
    }
    else
    {
      raw_spin_unlock(v33 + 13304);
      if ( v35 )
      {
LABEL_47:
        v24 = dp_peer_unref_delete(v35, 0x13u, v8, v9, v10, v11, v12, v13, v14, v15);
        goto LABEL_48;
      }
    }
    v16 = (unsigned int)(*(_DWORD *)(v17 + 780) + 1);
    *(_DWORD *)(v17 + 780) = v16;
    goto LABEL_51;
  }
LABEL_48:
  if ( *(_DWORD *)(v17 + 64) )
  {
    v29 = "%s: Mesh mode is not supported in exception path";
    goto LABEL_50;
  }
  v38 = *(_QWORD *)(a3 + 216) + *(unsigned int *)(a3 + 212);
  if ( *(_WORD *)(v38 + 4) && (*(_BYTE *)(v38 + 24) & 0x11) != 0 )
  {
    if ( is_dp_verbose_debug_enabled == 1 )
    {
      qdf_trace_msg(0x45u, 8u, "%s: TSO frame %pK", v8, v9, v10, v11, v12, v13, v14, v15, "dp_tx_send_exception", v17);
      v39 = *(_QWORD *)(v17 + 24);
      if ( v39 )
      {
LABEL_59:
        ++*(_QWORD *)(v39 + 92216);
        v40 = *(_QWORD *)(v17 + 24);
        if ( v40 )
        {
          if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
            v41 = *(unsigned __int16 *)(a3 + 66);
          else
            v41 = 0;
          *(_QWORD *)(v40 + 92224) += (unsigned int)(*(_DWORD *)(a3 + 112) + v41);
        }
      }
    }
    else
    {
      v39 = *(_QWORD *)(v17 + 24);
      if ( v39 )
        goto LABEL_59;
    }
    if ( (unsigned int)dp_tx_prepare_tso(v17, a3, &v77) )
    {
      v16 = *(_QWORD *)(v17 + 24);
      if ( v16 )
      {
        ++*(_QWORD *)(v16 + 92240);
        v16 = *(_QWORD *)(v17 + 24);
        if ( v16 )
        {
          if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
            v66 = *(unsigned __int16 *)(a3 + 66);
          else
            v66 = 0;
          *(_QWORD *)(v16 + 92248) += (unsigned int)(*(_DWORD *)(a3 + 112) + v66);
        }
      }
      goto LABEL_51;
    }
    *(_QWORD *)(v17 + 408) += (unsigned int)(v78 - 1);
    goto LABEL_95;
  }
  if ( *(_DWORD *)(a3 + 116) )
  {
    memset(v76, 0, sizeof(v76));
    a3 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64 *))dp_tx_prepare_sg)(v17, a3, v76, &v77);
    if ( !a3 )
      goto LABEL_51;
    if ( is_dp_verbose_debug_enabled != 1 )
      goto LABEL_106;
    goto LABEL_119;
  }
  if ( (a4[6] & 1) != 0 )
  {
    ++*(_QWORD *)(v17 + 824);
    if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
      v42 = *(unsigned __int16 *)(a3 + 66);
    else
      v42 = 0;
    *(_QWORD *)(v17 + 832) += (unsigned int)(*(_DWORD *)(a3 + 112) + v42);
    v43 = a4[7];
    v24 = (__int64)qdf_mem_set(v84, 0x24u, 0);
    HIDWORD(v85) |= 6u;
    LODWORD(v86) = v86 | v43;
    *(_WORD *)((char *)&v78 + 5) = 257;
  }
  if ( BYTE4(v77) > 4uLL )
  {
    __break(0x5512u);
LABEL_119:
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: non-TSO SG frame %pK",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_tx_send_exception",
      v17);
LABEL_106:
    ++*(_QWORD *)(v17 + 568);
    if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
      v72 = *(unsigned __int16 *)(a3 + 66);
    else
      v72 = 0;
    *(_QWORD *)(v17 + 576) += (unsigned int)(*(_DWORD *)(a3 + 112) + v72);
LABEL_95:
    a3 = dp_tx_send_msdu_multiple(v17, a3, (int *)&v77, v8, v9, v10, v11, v12, v13, v14, v15);
    goto LABEL_51;
  }
  ++*(_DWORD *)(v17 + 4LL * BYTE4(v77) + 432);
  v44 = *(__int64 (__fastcall **)(__int64, __int64, __int64, unsigned __int16 *))(a1 + 1320);
  if ( v44 )
  {
    if ( *((_DWORD *)v44 - 1) != -1687607186 )
      __break(0x8228u);
    v24 = v44(a1, v17, a3, a4);
    a3 = v24;
    if ( !v24 )
      goto LABEL_51;
  }
  if ( (a4[6] & 2) != 0 )
  {
    if ( *(_BYTE *)(v17 + 56) == 1 )
    {
      dp_tx_nawds_handler(v24, v17, (__int64)&v77, a3, *a4);
      ++*(_QWORD *)(v17 + 504);
      if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
        v73 = *(unsigned __int16 *)(a3 + 66);
      else
        v73 = 0;
      *(_QWORD *)(v17 + 512) += (unsigned int)(*(_DWORD *)(a3 + 112) + v73);
    }
    v45 = v17;
    v46 = a3;
    v47 = 65534;
    v48 = 0;
  }
  else
  {
    v47 = *a4;
    v45 = v17;
    v46 = a3;
    v48 = (__int64)a4;
  }
  a3 = (__int64)dp_tx_send_msdu_single(v45, v46, (__int64)&v77, v47, v48, v8, v9, v10, v11, v12, v13, v14, v15);
  dp_vdev_unref_delete(a1, v17, 0x13u, v49, v50, v51, v52, v53, v54, v55, v56, v57);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return a3;
}
