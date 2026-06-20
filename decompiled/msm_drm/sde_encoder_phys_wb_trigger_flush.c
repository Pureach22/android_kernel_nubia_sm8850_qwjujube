void __fastcall sde_encoder_phys_wb_trigger_flush(__int64 a1)
{
  __int64 v1; // x4
  __int64 v2; // x8
  __int64 v3; // x5
  int v4; // w4
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w5
  __int64 v8; // x4
  __int64 v9; // x8

  if ( !a1 || !*(_QWORD *)(a1 + 2680) )
  {
    printk(&unk_26FCAB, "sde_encoder_phys_wb_trigger_flush");
    return;
  }
  if ( *(_BYTE *)(a1 + 2290) != 1 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_20;
    if ( *(_QWORD *)a1 )
    {
      v4 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      v5 = *(_QWORD *)(a1 + 2864);
      if ( v5 )
      {
LABEL_11:
        v6 = a1;
        v7 = *(_DWORD *)(v5 + 12) - 1;
LABEL_19:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d]\n", v4, v7);
        a1 = v6;
LABEL_20:
        if ( *(_QWORD *)(a1 + 2816) )
        {
          ((void (*)(void))sde_encoder_helper_trigger_flush)();
          return;
        }
        if ( (_drm_debug & 4) == 0 )
          return;
        if ( *(_QWORD *)a1 )
        {
          v8 = *(unsigned int *)(*(_QWORD *)a1 + 24LL);
          v9 = *(_QWORD *)(a1 + 2864);
          if ( v9 )
          {
LABEL_26:
            _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] no out FB\n", v8, (unsigned int)(*(_DWORD *)(v9 + 12) - 1));
            return;
          }
        }
        else
        {
          v8 = 0xFFFFFFFFLL;
          v9 = *(_QWORD *)(a1 + 2864);
          if ( v9 )
            goto LABEL_26;
        }
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] no out FB\n", v8, 0xFFFFFFFFLL);
        return;
      }
    }
    else
    {
      v4 = -1;
      v5 = *(_QWORD *)(a1 + 2864);
      if ( v5 )
        goto LABEL_11;
    }
    v6 = a1;
    v7 = -1;
    goto LABEL_19;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v1 = *(unsigned int *)(*(_QWORD *)a1 + 24LL);
      v2 = *(_QWORD *)(a1 + 2864);
      if ( v2 )
      {
LABEL_7:
        v3 = (unsigned int)(*(_DWORD *)(v2 + 12) - 1);
LABEL_15:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] in CWB mode. early return\n", v1, v3);
        return;
      }
    }
    else
    {
      v1 = 0xFFFFFFFFLL;
      v2 = *(_QWORD *)(a1 + 2864);
      if ( v2 )
        goto LABEL_7;
    }
    v3 = 0xFFFFFFFFLL;
    goto LABEL_15;
  }
}
