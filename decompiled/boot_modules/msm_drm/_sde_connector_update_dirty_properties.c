__int64 __fastcall sde_connector_update_dirty_properties(__int64 a1)
{
  __int64 v2; // x20
  _BYTE *v3; // x26
  __int64 v4; // x8
  int v5; // w0
  const char *v6; // x28
  char *v7; // x22
  char *v8; // x24
  __int64 *v9; // x23
  const char *v10; // x21
  __int64 v11; // x8
  __int64 v12; // x27
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 (__fastcall *v15)(__int64, __int64, __int64); // x8
  __int64 v16; // x1
  unsigned int v17; // w27
  int v18; // w5
  int v19; // w6
  int v20; // w9
  int v21; // w8
  _DWORD *v22; // x25
  _BYTE *v23; // x20
  char *v24; // x26
  char *v25; // x22
  const char *v26; // x24
  __int64 *v27; // x21
  const char *v28; // x23
  __int64 v29; // x28
  __int64 v30; // x2
  int v31; // w8
  unsigned int (__fastcall *v32)(__int64, __int64); // x8
  __int64 v33; // x1
  _QWORD *v34; // x8
  _QWORD *v35; // x20
  _DWORD *v36; // x21
  int v37; // w4
  int v38; // w5
  int v39; // w8
  _DWORD *v40; // x8
  __int64 v42; // [xsp+18h] [xbp-8h]

  if ( !a1 )
  {
    printk(&unk_215A31, "_sde_connector_update_dirty_properties");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 2512);
  v3 = (_BYTE *)(a1 + 4096);
  mutex_lock(a1 + 3392);
  v4 = *(_QWORD *)(a1 + 2512);
  if ( v4 )
    LODWORD(v4) = (*(unsigned __int8 *)(v4 + 2016) >> 2) & 1;
  v3[1264] = v4;
  v5 = msm_property_pop_dirty(a1 + 3312, v2 + 448);
  if ( (v5 & 0x80000000) == 0 )
  {
    v6 = "conn%d updated hdr metadata: %d\n";
    v7 = "ress";
    v8 = "_sde_connector_update_power_locked";
    v9 = &qword_294000;
    v10 = "conn %d - dpms %d, lp %d, panel %d\n";
    v42 = v2;
    do
    {
      switch ( v5 )
      {
        case 6:
          v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 3088);
          if ( v15 )
          {
            v16 = *(_QWORD *)(a1 + 2760);
            if ( *((_DWORD *)v15 - 1) != -950625686 )
              __break(0x8228u);
            v17 = v15(a1, v16, v2);
            if ( v17 )
              printk(&unk_24CF79, "_sde_connector_update_hdr_metadata");
          }
          else
          {
            v17 = 0;
          }
          if ( (v7[4000] & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, v6, *(unsigned int *)(a1 + 64), v17);
          break;
        case 27:
          v13 = *(_QWORD *)(a1 + 2512);
          if ( v13 )
          {
            v14 = *(unsigned int *)(v13 + 1344);
            if ( (v3[1264] & 1) == 0 )
              goto LABEL_22;
          }
          else
          {
            v14 = 0;
            if ( (v3[1264] & 1) == 0 )
            {
LABEL_22:
              if ( (v3[1265] & 1) == 0 )
                backlight_device_set_brightness(*(_QWORD *)(a1 + 4360), v14);
            }
          }
          break;
        case 31:
          mutex_lock(a1 + 2816);
          v11 = *(_QWORD *)(a1 + 2512);
          if ( v11 )
            v12 = *(_QWORD *)(v11 + 1472);
          else
            LODWORD(v12) = 0;
          v18 = *(_DWORD *)(a1 + 3288);
          *(_DWORD *)(a1 + 3292) = v12;
          if ( v18 > 1 )
          {
            if ( v18 == 2 )
            {
              v19 = v12;
              LODWORD(v12) = 4;
            }
            else
            {
              if ( v18 != 3 )
                goto LABEL_51;
              v19 = v12;
              LODWORD(v12) = 5;
            }
          }
          else if ( v18 )
          {
            if ( v18 == 1 )
            {
              v19 = v12;
              LODWORD(v12) = 3;
              goto LABEL_37;
            }
LABEL_51:
            printk(&unk_27A7EB, v8);
            v18 = *(_DWORD *)(a1 + 3288);
            v19 = *(_DWORD *)(a1 + 3292);
          }
          else
          {
            v19 = v12;
          }
LABEL_37:
          sde_evtlog_log(v9[191], v8, 951, -1, *(_DWORD *)(a1 + 64), v18, v19, v12, *(_DWORD *)(a1 + 3296));
          if ( (v7[4000] & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              v10,
              *(unsigned int *)(a1 + 64),
              *(unsigned int *)(a1 + 3288),
              *(unsigned int *)(a1 + 3292),
              (unsigned int)v12);
          if ( !(_DWORD)v12 )
            goto LABEL_44;
          if ( (_DWORD)v12 == 5 )
          {
            v20 = 2;
            goto LABEL_45;
          }
          v21 = *(_DWORD *)(a1 + 3296);
          if ( (_DWORD)v12 == 1 && v21 == 5 )
          {
LABEL_44:
            v20 = 1;
LABEL_45:
            v21 = *(_DWORD *)(a1 + 3296);
            *(_DWORD *)(a1 + 4720) = v20;
          }
          if ( (_DWORD)v12 != v21 )
          {
            v22 = *(_DWORD **)(a1 + 3032);
            if ( v22 )
            {
              v23 = v3;
              v24 = v7;
              v25 = v8;
              v26 = v10;
              v27 = v9;
              v28 = v6;
              v29 = *(_QWORD *)(a1 + 2760);
              mutex_unlock(a1 + 2816);
              v30 = v29;
              v6 = v28;
              v9 = v27;
              v10 = v26;
              v8 = v25;
              v7 = v24;
              v3 = v23;
              v2 = v42;
              if ( *(v22 - 1) != -754378392 )
                __break(0x8239u);
              ((void (__fastcall *)(__int64, _QWORD, __int64))v22)(a1, (unsigned int)v12, v30);
              mutex_lock(a1 + 2816);
            }
          }
          *(_DWORD *)(a1 + 3296) = v12;
          mutex_unlock(a1 + 2816);
          sde_connector_schedule_status_work(a1, (_DWORD)v12 == 0);
          mutex_lock(a1 + 2816);
          mutex_unlock(a1 + 2816);
          break;
      }
      v5 = msm_property_pop_dirty(a1 + 3312, v2 + 448);
    }
    while ( (v5 & 0x80000000) == 0 );
  }
  mutex_unlock(a1 + 3392);
  v31 = (unsigned __int8)v3[1264];
  if ( v31 != (unsigned __int8)v3[1265] )
    v3[1265] = v31;
  if ( v3[648] != 1 )
    goto LABEL_59;
  v32 = *(unsigned int (__fastcall **)(__int64, __int64))(a1 + 2984);
  v3[648] = 0;
  if ( !v32 )
    goto LABEL_59;
  v33 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v32 - 1) != 282792832 )
    __break(0x8228u);
  if ( v32(a1, v33) )
  {
    printk(&unk_27DECD, "sde_connector_set_colorspace");
    if ( (v3[428] & 1) == 0 )
    {
LABEL_60:
      if ( !*(_DWORD *)(a1 + 4536) )
        return 0;
    }
  }
  else
  {
LABEL_59:
    if ( (v3[428] & 1) == 0 )
      goto LABEL_60;
  }
  if ( *(_DWORD *)(a1 + 2736) == 16 )
  {
    v34 = (_QWORD *)(a1 + 2760);
    if ( v3[1032] == 1 )
      v34 = (_QWORD *)*v34;
    v35 = (_QWORD *)*v34;
    if ( *v34 )
    {
      v36 = (_DWORD *)v35[33];
      if ( v36 )
      {
        if ( *(_DWORD *)(a1 + 4528) >= 0x400u )
          v37 = 1024;
        else
          v37 = *(_DWORD *)(a1 + 4528);
        v36[375] = v37;
        if ( *(_DWORD *)(a1 + 4532) >= 0x3FFFCu )
          v38 = 262140;
        else
          v38 = *(_DWORD *)(a1 + 4532);
        v36[376] = v38;
        if ( (v3[444] & 1) != 0 )
        {
          v39 = *(_DWORD *)(a1 + 4536);
          if ( v39 )
            v36[374] = v39;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "bl_scale = %u, bl_scale_sv = %u, bl_level = %u\n", v37, v38, v36[374]);
          if ( !v36[374] )
            goto LABEL_81;
          v40 = *(_DWORD **)(a1 + 2968);
          if ( *(v40 - 1) != 1064465684 )
            __break(0x8228u);
          if ( !((unsigned int (__fastcall *)(__int64, _QWORD *))v40)(a1, v35) )
LABEL_81:
            sde_dimming_bl_notify(a1, v36 + 368);
          *(_DWORD *)(a1 + 4536) = 0;
        }
        else
        {
          *(_DWORD *)(a1 + 4536) = v36[374];
        }
      }
      else
      {
        printk(&unk_227B42, "_sde_connector_update_bl_scale");
      }
    }
  }
  v3[428] = 0;
  return 0;
}
