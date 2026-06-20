void __fastcall sde_encoder_phys_wb_enable(__int64 a1)
{
  int v2; // w4
  __int64 v3; // x8
  int v4; // w5
  _QWORD *v5; // x8
  __int64 v6; // x9
  __int64 v7; // x9

  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v2 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_8;
    }
    else
    {
      v2 = -1;
      if ( !a1 )
        goto LABEL_8;
    }
    v3 = *(_QWORD *)(a1 + 2864);
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 + 12) - 1;
LABEL_9:
      _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d]\n", v2, v4);
      goto LABEL_10;
    }
LABEL_8:
    v4 = -1;
    goto LABEL_9;
  }
LABEL_10:
  v5 = *(_QWORD **)a1;
  if ( *(_QWORD *)a1 && *v5 )
  {
    v6 = *(_QWORD *)(a1 + 8);
    if ( v6 && *(_QWORD **)(v6 + 2272) == v5 )
    {
      if ( *(_DWORD *)(v6 + 156) == 15 )
      {
        v7 = *(_QWORD *)(v6 + 2760);
      }
      else
      {
        printk(&unk_223EAA, "sde_wb_connector_get_wb");
        v5 = *(_QWORD **)a1;
        v7 = 0;
      }
      *(_QWORD *)(a1 + 2864) = v7;
      *(_DWORD *)(a1 + 832) = 4;
      *(_QWORD *)(a1 + 2936) = v5[10];
    }
    else
    {
      printk(&unk_278201, "sde_encoder_phys_wb_enable");
    }
  }
  else
  {
    printk(&unk_22BCB7, "sde_encoder_phys_wb_enable");
  }
}
