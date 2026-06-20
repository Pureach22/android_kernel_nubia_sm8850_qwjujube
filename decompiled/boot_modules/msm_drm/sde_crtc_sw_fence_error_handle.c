__int64 __fastcall sde_crtc_sw_fence_error_handle(
        __int64 *a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  unsigned int v10; // w19
  int v12; // w7
  __int64 v13; // x8
  __int64 *v14; // x26
  __int64 v15; // x27
  __int64 v16; // x21
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  _QWORD *v21; // x23
  _QWORD *i; // x25
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  void *v25; // x0
  char v27; // [xsp+0h] [xbp+0h]
  char v28; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_25E167, "sde_crtc_sw_fence_error_handle");
    return (unsigned int)-22;
  }
  v8 = a1[251];
  if ( !v8 )
    return 0;
  v10 = 0;
  if ( a2 < 0 && *(_QWORD *)(v8 + 1664) )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_sw_fence_error_handle", 4513, -1, 1, a2, -1059143953, a8, v27);
    v13 = *a1;
    *((_DWORD *)a1 + 1985) = a2;
    *((_BYTE *)a1 + 7944) = 1;
    v10 = 0;
    v14 = *(__int64 **)(v13 + 816);
    if ( v14 != (__int64 *)(v13 + 816) )
    {
      do
      {
        v15 = a1[251];
        if ( ((*(_DWORD *)(v15 + 20) >> *((_DWORD *)v14 + 15)) & 1) != 0
          && (v14 == (__int64 *)&unk_8
           || !v15
           || (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v14 - 1) & 1) == 0
           && ((*(_DWORD *)(v15 + 1812) >> *((_DWORD *)v14 + 15)) & 1) == 0) )
        {
          v10 = sde_encoder_handle_dma_fence_out_of_order(v14 - 1);
          if ( v10 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "Dma fence out of order failed, rc = %d\n", v10);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "sde_crtc_sw_fence_error_handle",
              4527,
              -1,
              v10,
              60333,
              -1059143953,
              v12,
              v28);
          }
        }
        v13 = *a1;
        v14 = (__int64 *)*v14;
      }
      while ( v14 != (__int64 *)(*a1 + 816) );
    }
    v16 = a1[276];
    if ( !v16 && (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "invalid crtc params %d\n", 0);
      v13 = *a1;
    }
    if ( v13 && (v17 = *(_QWORD *)(v13 + 56)) != 0 )
    {
      v18 = *(_QWORD *)(v17 + 8);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 136);
        if ( v19 )
        {
          v20 = *(_QWORD *)(v19 + 56);
          if ( v20 )
          {
            v21 = *(_QWORD **)(v20 + 5816);
            for ( i = (_QWORD *)(v20 + 5816); v21 != i; v21 = (_QWORD *)*v21 )
            {
              v23 = (__int64 (__fastcall *)(__int64, __int64))*(v21 - 3);
              if ( v23 )
              {
                v24 = *(v21 - 1);
                if ( *((_DWORD *)v23 - 1) != 1863972096 )
                  __break(0x8228u);
                v10 = v23(v16, v24);
                if ( v10 )
                {
                  printk(&unk_27D20E, "sde_crtc_sw_fence_error_handle");
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "sde_crtc_sw_fence_error_handle",
                    4550,
                    -1,
                    *(_DWORD *)(*(v21 - 2) + 764LL),
                    v10,
                    60333,
                    -1059143953,
                    v28);
                }
              }
            }
            return v10;
          }
        }
        goto LABEL_38;
      }
      v25 = &unk_234896;
    }
    else
    {
      v25 = &unk_25E167;
    }
    printk(v25, "_sde_crtc_get_kms");
LABEL_38:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_crtc_sw_fence_error_handle",
      4534,
      -1,
      *((_DWORD *)a1 + 28),
      60333,
      -1059143953,
      v12,
      v28);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid parameters\n");
    return (unsigned int)-22;
  }
  return v10;
}
