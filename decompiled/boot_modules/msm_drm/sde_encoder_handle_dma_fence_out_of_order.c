__int64 __fastcall sde_encoder_handle_dma_fence_out_of_order(__int64 a1)
{
  __int64 v1; // x27
  __int64 v3; // x21
  __int64 v4; // x25
  int *v5; // x19
  __int64 v6; // x0
  unsigned int v7; // w20
  __int64 v8; // x22
  int v9; // w26
  int v10; // w21
  unsigned int v11; // w23
  int v12; // w2
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v16; // x0
  __int64 v17; // x1
  char v18; // [xsp+0h] [xbp-10h]
  char v19; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_handle_dma_fence_out_of_order");
    return 0;
  }
  v1 = *(_QWORD *)(a1 + 200);
  if ( !v1 )
  {
    printk(&unk_223EAA, "sde_encoder_handle_dma_fence_out_of_order");
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a1 + 80);
  v4 = *(_QWORD *)(v3 + 2008);
  v5 = *(int **)(v3 + 3232);
  v6 = ktime_get(a1);
  v7 = *(_DWORD *)(v1 + 2312);
  v8 = v6;
  if ( v7 )
    *(_DWORD *)(v1 + 2312) = 0;
  else
    v7 = *(_DWORD *)(v3 + 7940);
  v9 = *(_DWORD *)(a1 + 648);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_handle_dma_fence_out_of_order",
    2617,
    -1,
    v9 == 1,
    v7,
    *(unsigned __int8 *)(v1 + 2328),
    -1059143953,
    v18);
  if ( v9 == 1 )
  {
    v10 = 0;
    v11 = 0;
    if ( (*(_BYTE *)(v1 + 2328) & 1) == 0 )
    {
      v5[8] = v5[9] - 1;
      *(_BYTE *)(v1 + 2328) = 1;
    }
    v12 = 4;
  }
  else
  {
    v10 = *(_DWORD *)(v1 + 876);
    if ( v10 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_handle_dma_fence_out_of_order",
        2637,
        -1,
        *(_DWORD *)(a1 + 24),
        v10,
        13107,
        -1059143953,
        v19);
      v11 = sde_encoder_wait_for_event(a1, 1);
      if ( v11 != -11 && v11 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "wait for frame done failed %d\n", v11);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_handle_dma_fence_out_of_order",
          2642,
          -1,
          *(_DWORD *)(a1 + 24),
          v11,
          v10,
          60333,
          239);
      }
      v12 = 1;
    }
    else
    {
      v11 = 0;
      v12 = 1;
    }
  }
  sde_fence_error_ctx_update((int)v5, v7, v12);
  sde_fence_signal(v5, v8, 0, 0);
  v13 = sde_fence_error_ctx_update((int)v5, 0, 0);
  if ( *(int *)(v4 + 464) < 1 )
  {
LABEL_23:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_handle_dma_fence_out_of_order",
      2667,
      -1,
      v5[10],
      v5[11],
      v5[8],
      v10,
      239);
    return v11;
  }
  v14 = 0;
  while ( v14 != 16 )
  {
    v13 = sde_connector_fence_error_ctx_signal(*(_QWORD *)(v4 + 336 + 8 * v14++), v7, v9 == 1);
    if ( v14 >= *(int *)(v4 + 464) )
      goto LABEL_23;
  }
  __break(0x5512u);
  v16 = MEMORY[0x75B9E9C](v13);
  return sde_encoder_wait_for_event(v16, v17);
}
