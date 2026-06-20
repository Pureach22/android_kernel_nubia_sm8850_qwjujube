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
  __int16 v22; // w8
  int v23; // w0
  __int64 v24; // x8
  __int64 i; // x21
  __int64 v26; // x9
  __int64 (__fastcall *v27)(__int64, __int64); // x8
  __int64 v28; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x8
  int v31; // w21
  int v32; // w9
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  __int64 v43; // x21
  _DWORD *v44; // x9
  __int64 v45; // x1
  unsigned int v53; // w9
  unsigned int v56; // w9

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_objmgr_pdev_obj_create");
    return 0;
  }
  v12 = _qdf_mem_malloc(0x548u, "wlan_objmgr_pdev_obj_create", 113);
  v13 = v12;
  if ( v12 )
  {
    *(_DWORD *)(v12 + 1224) = 0;
    *(_DWORD *)(v12 + 1240) = 0;
    *(_QWORD *)(v12 + 1248) = 0;
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
    wlan_minidump_log(v13, 1352, a1, 51, "wlan_objmgr_pdev");
    *(_QWORD *)(v13 + 80) = a1;
    *(_QWORD *)(v13 + 48) = v13 + 48;
    *(_QWORD *)(v13 + 56) = v13 + 48;
    *(_QWORD *)(v13 + 64) = 0x600000000LL;
    *(_WORD *)(v13 + 41) = 1536;
    *(_WORD *)(v13 + 72) = 0;
    *(_WORD *)(v13 + 76) = 0;
    v22 = *(_WORD *)(a1 + 60);
    *(_QWORD *)(v13 + 24) = a2;
    *(_WORD *)(v13 + 74) = v22;
    *(_DWORD *)(v13 + 88) = 0;
    *(_BYTE *)(v13 + 43) = 0;
    _X8 = (unsigned int *)(v13 + 88);
    __asm { PRFM            #0x11, [X8] }
    do
      v53 = __ldxr(_X8);
    while ( __stxr(v53 + 1, _X8) );
    _X8 = (unsigned int *)(v13 + 92);
    __asm { PRFM            #0x11, [X8] }
    do
      v56 = __ldxr(_X8);
    while ( __stxr(v56 + 1, _X8) );
    for ( i = 0; i != 54; ++i )
    {
      v26 = g_umac_glb_obj + 8 * i;
      v27 = *(__int64 (__fastcall **)(__int64, __int64))(v26 + 2632);
      if ( v27 )
      {
        v28 = *(_QWORD *)(v26 + 3064);
        if ( *((_DWORD *)v27 - 1) != 223207110 )
          __break(0x8228u);
        v23 = v27(v13, v28);
      }
      else
      {
        v23 = 39;
      }
      v24 = v13 + 4 * i;
      *(_DWORD *)(v24 + 1008) = v23;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 1240);
    }
    else
    {
      raw_spin_lock_bh(v13 + 1240);
      *(_QWORD *)(v13 + 1248) |= 1uLL;
    }
    v30 = 0;
    v31 = 16;
    while ( 1 )
    {
      v32 = *(_DWORD *)(v13 + 4 * v30 + 1008);
      if ( v32 == 40 )
      {
        if ( !*(_QWORD *)(v13 + 8 * v30 + 576) )
        {
          v31 = 40;
          v33 = *(_QWORD *)(v13 + 1248);
          if ( (v33 & 1) == 0 )
            goto LABEL_26;
          goto LABEL_36;
        }
      }
      else if ( v32 == 2 || v32 == 16 )
      {
        goto LABEL_25;
      }
      if ( ++v30 == 54 )
      {
        v31 = 0;
LABEL_25:
        v33 = *(_QWORD *)(v13 + 1248);
        if ( (v33 & 1) == 0 )
        {
LABEL_26:
          raw_spin_unlock(v13 + 1240);
          if ( v31 != 40 )
          {
LABEL_27:
            if ( v31 == 16 )
            {
              qdf_trace_msg(
                0x57u,
                2u,
                "%s: PDEV component objects allocation failed",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "wlan_objmgr_pdev_obj_create");
              wlan_objmgr_pdev_obj_delete(v13);
              return 0;
            }
            v42 = g_umac_glb_obj;
            v43 = -432;
            *(_DWORD *)(v13 + 1224) = 1;
            do
            {
              v44 = *(_DWORD **)(v42 + v43 + 4792);
              if ( v44 )
              {
                v45 = *(_QWORD *)(v42 + v43 + 5224);
                if ( *(v44 - 1) != -1609821410 )
                  __break(0x8229u);
                ((void (__fastcall *)(__int64, __int64, _QWORD))v44)(v13, v45, 0);
                v42 = g_umac_glb_obj;
              }
              v43 += 8;
            }
            while ( v43 );
LABEL_38:
            qdf_trace_msg(
              0x57u,
              8u,
              "%s: Created pdev %d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "wlan_objmgr_pdev_obj_create",
              *(unsigned __int8 *)(v13 + 40));
            return v13;
          }
LABEL_37:
          *(_DWORD *)(v13 + 1224) = 3;
          goto LABEL_38;
        }
LABEL_36:
        *(_QWORD *)(v13 + 1248) = v33 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v13 + 1240);
        if ( v31 != 40 )
          goto LABEL_27;
        goto LABEL_37;
      }
    }
  }
  return v13;
}
