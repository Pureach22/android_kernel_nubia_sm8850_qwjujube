__int64 __fastcall wlan_objmgr_pdev_obj_create(
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
  __int64 v12; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w0
  __int64 v23; // x8
  __int64 i; // x21
  __int64 v25; // x9
  __int64 (__fastcall *v26)(__int64, __int64); // x8
  __int64 v27; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x8
  int v30; // w21
  int v31; // w9
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 v42; // x21
  _DWORD *v43; // x9
  __int64 v44; // x1
  unsigned int v52; // w9
  unsigned int v55; // w9

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_objmgr_pdev_obj_create");
    return 0;
  }
  v12 = _qdf_mem_malloc(0x550u, "wlan_objmgr_pdev_obj_create", 113);
  v13 = v12;
  if ( v12 )
  {
    *(_DWORD *)(v12 + 1232) = 0;
    *(_DWORD *)(v12 + 1248) = 0;
    *(_QWORD *)(v12 + 1256) = 0;
    wlan_delayed_peer_obj_free_init(v12);
    if ( (unsigned int)wlan_objmgr_psoc_pdev_attach(a1, v13) )
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: pdev psoc attach failed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_objmgr_pdev_obj_create");
      _qdf_mem_free(v13);
      return 0;
    }
    wlan_minidump_log(v13, 1360, a1, 51, "wlan_objmgr_pdev");
    *(_QWORD *)(v13 + 80) = a1;
    *(_QWORD *)(v13 + 48) = v13 + 48;
    *(_QWORD *)(v13 + 56) = v13 + 48;
    *(_QWORD *)(v13 + 64) = 0x600000000LL;
    *(_WORD *)(v13 + 41) = 1536;
    *(_WORD *)(v13 + 72) = 0;
    *(_WORD *)(v13 + 76) = 0;
    *(_WORD *)(v13 + 74) = *(_WORD *)(a1 + 60);
    *(_DWORD *)(v13 + 528) = 0;
    *(_DWORD *)(v13 + 532) = 0;
    *(_QWORD *)(v13 + 24) = a2;
    *(_DWORD *)(v13 + 88) = 0;
    *(_BYTE *)(v13 + 43) = 0;
    _X8 = (unsigned int *)(v13 + 88);
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr(_X8);
    while ( __stxr(v52 + 1, _X8) );
    _X8 = (unsigned int *)(v13 + 92);
    __asm { PRFM            #0x11, [X8] }
    do
      v55 = __ldxr(_X8);
    while ( __stxr(v55 + 1, _X8) );
    for ( i = 0; i != 54; ++i )
    {
      v25 = g_umac_glb_obj + 8 * i;
      v26 = *(__int64 (__fastcall **)(__int64, __int64))(v25 + 2640);
      if ( v26 )
      {
        v27 = *(_QWORD *)(v25 + 3072);
        if ( *((_DWORD *)v26 - 1) != 223207110 )
          __break(0x8228u);
        v22 = v26(v13, v27);
      }
      else
      {
        v22 = 39;
      }
      v23 = v13 + 4 * i;
      *(_DWORD *)(v23 + 1016) = v22;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 1248);
    }
    else
    {
      raw_spin_lock_bh(v13 + 1248);
      *(_QWORD *)(v13 + 1256) |= 1uLL;
    }
    v29 = 0;
    v30 = 16;
    while ( 1 )
    {
      v31 = *(_DWORD *)(v13 + 4 * v29 + 1016);
      if ( v31 == 40 )
      {
        if ( !*(_QWORD *)(v13 + 8 * v29 + 584) )
        {
          v30 = 40;
          v32 = *(_QWORD *)(v13 + 1256);
          if ( (v32 & 1) == 0 )
            goto LABEL_26;
          goto LABEL_36;
        }
      }
      else if ( v31 == 2 || v31 == 16 )
      {
        goto LABEL_25;
      }
      if ( ++v29 == 54 )
      {
        v30 = 0;
LABEL_25:
        v32 = *(_QWORD *)(v13 + 1256);
        if ( (v32 & 1) == 0 )
        {
LABEL_26:
          raw_spin_unlock(v13 + 1248);
          if ( v30 != 40 )
          {
LABEL_27:
            if ( v30 == 16 )
            {
              qdf_trace_msg(
                0x57u,
                2u,
                "%s: PDEV component objects allocation failed",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "wlan_objmgr_pdev_obj_create");
              wlan_objmgr_pdev_obj_delete(v13);
              return 0;
            }
            v41 = g_umac_glb_obj;
            v42 = -432;
            *(_DWORD *)(v13 + 1232) = 1;
            do
            {
              v43 = *(_DWORD **)(v41 + v42 + 4800);
              if ( v43 )
              {
                v44 = *(_QWORD *)(v41 + v42 + 5232);
                if ( *(v43 - 1) != -1609821410 )
                  __break(0x8229u);
                ((void (__fastcall *)(__int64, __int64, _QWORD))v43)(v13, v44, 0);
                v41 = g_umac_glb_obj;
              }
              v42 += 8;
            }
            while ( v42 );
LABEL_38:
            qdf_trace_msg(
              0x57u,
              8u,
              "%s: Created pdev %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "wlan_objmgr_pdev_obj_create",
              *(unsigned __int8 *)(v13 + 40));
            return v13;
          }
LABEL_37:
          *(_DWORD *)(v13 + 1232) = 3;
          goto LABEL_38;
        }
LABEL_36:
        *(_QWORD *)(v13 + 1256) = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v13 + 1248);
        if ( v30 != 40 )
          goto LABEL_27;
        goto LABEL_37;
      }
    }
  }
  return v13;
}
