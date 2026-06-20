__int64 __fastcall sde_connector_set_blob_data(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x8
  _QWORD *v9; // x23
  _DWORD *v10; // x8
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x27
  unsigned int v14; // w22
  __int64 v15; // x28
  __int64 v16; // x2
  unsigned int v17; // w21
  __int64 v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x2
  unsigned int v21; // w0
  void *v22; // x0
  void *v23; // x0
  __int64 v25; // [xsp+8h] [xbp-738h]
  unsigned int mode_info; // [xsp+14h] [xbp-72Ch]
  _QWORD *v27; // [xsp+18h] [xbp-728h]
  _BYTE s[904]; // [xsp+20h] [xbp-720h] BYREF
  __int64 v29[115]; // [xsp+3A8h] [xbp-398h] BYREF

  v29[113] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 )
  {
    printk(&unk_215A31, "sde_connector_set_blob_data");
    v17 = -22;
    goto LABEL_63;
  }
  v6 = vzalloc_noprof(16396);
  v7 = v6;
  if ( !v6 )
  {
    v17 = -12;
    goto LABEL_63;
  }
  sde_kms_info_reset(v6);
  if ( a3 != 1 )
  {
    if ( a3 )
    {
      printk(&unk_2433AF, "sde_connector_set_blob_data");
      goto LABEL_50;
    }
    memset(s, 0, sizeof(s));
    if ( a2 )
    {
      memcpy(s, (const void *)(a2 + 2208), sizeof(s));
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "conn%d invalid connector state\n", *(_DWORD *)(a1 + 64));
    }
    v19 = *(_DWORD **)(a1 + 2880);
    if ( !v19 )
      goto LABEL_48;
    v20 = *(_QWORD *)(a1 + 2760);
    if ( *(v19 - 1) != 1715117205 )
      __break(0x8228u);
    v21 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _BYTE *))v19)(a1, v7, v20, s);
    if ( !v21 )
    {
LABEL_48:
      v18 = 4224;
      goto LABEL_49;
    }
    v17 = v21;
    v23 = &unk_274190;
LABEL_60:
    printk(v23, "sde_connector_set_blob_data");
    goto LABEL_51;
  }
  if ( !*(_QWORD *)a1 || (v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v22 = &unk_242658;
LABEL_56:
    printk(v22, "sde_connector_get_kms");
    printk(&unk_234896, "sde_connector_populate_mode_info");
LABEL_58:
    v17 = -22;
LABEL_59:
    v23 = &unk_26951B;
    goto LABEL_60;
  }
  v25 = *(_QWORD *)(v8 + 8);
  if ( !v25 )
  {
    v22 = &unk_234896;
    goto LABEL_56;
  }
  if ( !*(_QWORD *)(a1 + 2952) )
  {
    printk(&unk_2577EF, "sde_connector_populate_mode_info");
    goto LABEL_58;
  }
  v9 = *(_QWORD **)(a1 + 176);
  v27 = (_QWORD *)(a1 + 176);
  if ( v9 != (_QWORD *)(a1 + 176) )
  {
    do
    {
      while ( 1 )
      {
        memset(v29, 0, 0x388u);
        mode_info = sde_connector_get_mode_info(a1, (__int64)(v9 - 8), 0, (__int64)v29);
        if ( mode_info )
          break;
        ((void (__fastcall *)(__int64, const char *, _QWORD *))sde_kms_info_add_keystr)(v7, "mode_name", v9 + 2);
        sde_kms_info_add_keyint(v7, (__int64)"bit_clk_rate", v29[3]);
        v10 = *(_DWORD **)(a1 + 3208);
        if ( v10 )
        {
          v11 = *(_QWORD *)(a1 + 2760);
          if ( *(v10 - 1) != 186804649 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD *))v10)(a1, v7, v11, v9 - 8);
        }
        else
        {
          v12 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_conn_get_topology_name)(
                  a1,
                  *(__int64 *)((char *)&v29[4] + 4),
                  *(__int64 *)((char *)&v29[5] + 4));
          if ( v12 )
            ((void (__fastcall *)(__int64, const char *, __int64))sde_kms_info_add_keystr)(v7, "topology", v12);
        }
        sde_kms_info_add_keyint(v7, (__int64)"qsync_min_fps", LODWORD(v29[108]));
        if ( (*(_BYTE *)(a1 + 4714) & 1) == 0 )
          sde_kms_info_add_keyint(v7, (__int64)"avr_step_fps", HIDWORD(v29[108]));
        v13 = v29[107];
        if ( v29[107] && *(_DWORD *)(v29[107] + 8) )
        {
          v14 = 0;
          do
          {
            v15 = 32LL * (int)v14;
            sde_kms_info_add_keyint(v7, (__int64)"Frame_interval:", *(unsigned int *)(*(_QWORD *)v13 + v15 + 12));
            sde_kms_info_add_keyint(v7, (__int64)"usecase:", *(unsigned int *)(*(_QWORD *)v13 + v15 + 20));
            sde_kms_info_add_list(
              v7,
              "Pattern:",
              *(_QWORD *)(*(_QWORD *)v13 + v15),
              *(unsigned int *)(*(_QWORD *)v13 + v15 + 8));
            ++v14;
          }
          while ( v14 < *(_DWORD *)(v13 + 8) );
        }
        if ( *(_BYTE *)(a1 + 4713) == 1 )
          sde_kms_info_add_keyint(v7, (__int64)"has_vhm_support", 1);
        if ( *(_BYTE *)(a1 + 4712) == 1 )
          sde_kms_info_add_keyint(v7, (__int64)"early_ept_timeout", 58000000);
        sde_kms_info_add_keyint(v7, (__int64)"has_cwb_crop", (*(_QWORD *)(*(_QWORD *)(v25 + 152) + 22008LL) >> 4) & 1LL);
        sde_kms_info_add_keyint(
          v7,
          (__int64)"has_dedicated_cwb_support",
          (*(_QWORD *)(*(_QWORD *)(v25 + 152) + 22008LL) >> 6) & 1LL);
        if ( (*(_QWORD *)(*(_QWORD *)(v25 + 152) + 22008LL) & 0x80LL) != 0 )
          v16 = 2;
        else
          v16 = 1;
        sde_kms_info_add_keyint(v7, (__int64)"max_cwb", v16);
        sde_kms_info_add_keyint(v7, (__int64)"mdp_transfer_time_us", HIDWORD(v29[99]));
        if ( LODWORD(v29[100]) && HIDWORD(v29[100]) )
        {
          sde_kms_info_add_keyint(v7, (__int64)"mdp_transfer_time_us_min", LODWORD(v29[100]));
          sde_kms_info_add_keyint(v7, (__int64)"mdp_transfer_time_us_max", HIDWORD(v29[100]));
        }
        sde_kms_info_add_keyint(v7, (__int64)"allowed_mode_switch", LODWORD(v29[101]));
        if ( HIDWORD(v29[93]) )
        {
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_num_roi", HIDWORD(v29[93]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_xstart", LODWORD(v29[94]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_walign", HIDWORD(v29[94]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_wmin", LODWORD(v29[96]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_ystart", LODWORD(v29[95]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_halign", HIDWORD(v29[95]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_hmin", HIDWORD(v29[96]));
          sde_kms_info_add_keyint(v7, (__int64)"partial_update_roimerge", BYTE1(v29[93]));
        }
        v9 = (_QWORD *)*v9;
        if ( v9 == v27 )
          goto LABEL_41;
      }
      printk(&unk_277629, "sde_connector_populate_mode_info");
      v9 = (_QWORD *)*v9;
    }
    while ( v9 != v27 );
    v17 = mode_info;
    goto LABEL_59;
  }
LABEL_41:
  v18 = 4256;
LABEL_49:
  msm_property_set_blob(a1 + 3312, a1 + v18, v7, (unsigned int)(*(_DWORD *)(v7 + 0x4000) + 1), a3);
LABEL_50:
  v17 = 0;
LABEL_51:
  vfree(v7);
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return v17;
}
