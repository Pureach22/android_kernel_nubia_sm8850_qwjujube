__int64 __fastcall sde_wb_connector_get_modes(_QWORD *a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x8
  unsigned int *v8; // x8
  unsigned int v9; // w8
  unsigned int v10; // w9
  unsigned int v11; // w23
  int v12; // w21
  __int64 v13; // x22
  bool v14; // cf
  char v15; // w24
  int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0

  v2 = 0;
  if ( a1 && a2 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    mutex_lock(a2 + 48);
    if ( *(_DWORD *)(a2 + 120) && *(_QWORD *)(a2 + 128) )
    {
      v2 = 0;
      while ( 1 )
      {
        v5 = drm_mode_create(*a1);
        if ( !v5 )
        {
          printk(&unk_2362BB, "sde_wb_connector_get_modes");
          goto LABEL_32;
        }
        v6 = v5;
        if ( (unsigned int)drm_mode_convert_umode(*(_QWORD *)a2, v5, *(_QWORD *)(a2 + 128) + 68LL * (int)v2) )
          break;
        drm_mode_probed_add(a1, v6);
        if ( ++v2 >= *(_DWORD *)(a2 + 120) )
          goto LABEL_32;
      }
      printk(&unk_240408, "sde_wb_connector_get_modes");
      goto LABEL_32;
    }
    v7 = *(_QWORD *)(a2 + 16);
    if ( v7 && (v8 = *(unsigned int **)(v7 + 48)) != nullptr )
    {
      v10 = *v8;
      v9 = v8[1];
      if ( v10 <= v9 )
        v11 = v9;
      else
        v11 = v10;
      v12 = drm_add_modes_noedid(a1, v11, 5120);
      if ( !v11 )
        goto LABEL_31;
      v13 = *a1;
      if ( v11 >> 10 < 5 )
      {
        v14 = v11 >= 0x870;
        v11 = 0;
        if ( !v14 )
        {
LABEL_31:
          v2 = v11 + v12;
LABEL_32:
          mutex_unlock(a2 + 48);
          return v2;
        }
        v15 = 1;
LABEL_26:
        v18 = drm_mode_duplicate(v13, &unk_28EA38);
        if ( v18 )
        {
          drm_mode_probed_add(a1, v18);
          ++v11;
        }
        if ( (v15 & 1) == 0 )
        {
          v19 = drm_mode_duplicate(v13, &unk_28EAB0);
          if ( v19 )
          {
            drm_mode_probed_add(a1, v19);
            ++v11;
          }
        }
        goto LABEL_31;
      }
    }
    else
    {
      v16 = drm_add_modes_noedid(a1, 5120, 5120);
      v13 = *a1;
      v12 = v16;
    }
    v17 = drm_mode_duplicate(v13, &sde_custom_wb_modes);
    if ( v17 )
    {
      drm_mode_probed_add(a1, v17);
      v15 = 0;
      v11 = 1;
    }
    else
    {
      v15 = 0;
      v11 = 0;
    }
    goto LABEL_26;
  }
  return v2;
}
