__int64 __fastcall sde_crtc_fences_wait_list(__int64 *a1, char a2, __int64 a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 *v8; // x22
  int v9; // w21
  __int64 intf_mode; // x0
  int v11; // w23
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  int v18; // w7
  __int64 *v19; // x22
  unsigned __int64 v20; // x26
  char v21; // w23
  __int64 v22; // x21
  unsigned __int64 v23; // x28
  __int64 v24; // x8
  unsigned __int64 v25; // x26
  __int64 v26; // x27
  unsigned __int64 v27; // x24
  __int64 v28; // x24
  __int64 (__fastcall *v29)(_QWORD); // x8
  const char *v30; // x0
  int v31; // w8
  int v32; // w10
  unsigned __int64 v33; // x11
  __int64 v34; // x8
  __int64 v36; // x0
  unsigned int v37; // w24
  char v38; // w8
  __int64 connector; // x0
  __int64 v40; // x8
  unsigned int v41; // w8
  __int64 v43; // [xsp+0h] [xbp-30h]
  unsigned int v44; // [xsp+Ch] [xbp-24h]
  __int64 v45; // [xsp+10h] [xbp-20h]
  __int64 v46; // [xsp+18h] [xbp-18h]
  int v47; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[251];
  v47 = 0;
  v7 = **(_QWORD **)v6;
  v8 = *(__int64 **)(v7 + 816);
  if ( v8 == (__int64 *)(v7 + 816) )
    goto LABEL_2;
  while ( 1 )
  {
    if ( ((*(_DWORD *)(v6 + 20) >> *((_DWORD *)v8 + 15)) & 1) != 0 )
    {
      v38 = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v8 - 1);
      v7 = **(_QWORD **)v6;
      if ( (v38 & 1) == 0 )
        break;
    }
    v8 = (__int64 *)*v8;
    if ( v8 == (__int64 *)(v7 + 816) )
      goto LABEL_2;
  }
  connector = sde_encoder_get_connector(v7, v8 - 1);
  if ( connector && (v40 = *(_QWORD *)(connector + 2512)) != 0 )
  {
    v41 = *(_DWORD *)(v40 + 3240);
    if ( (v41 & 0x40) != 0 )
      LOBYTE(v9) = 1;
    else
      v9 = (v41 >> 7) & 1;
  }
  else
  {
LABEL_2:
    LOBYTE(v9) = 0;
  }
  intf_mode = sde_crtc_get_intf_mode(a1, a1[251]);
  v11 = intf_mode;
  v12 = ktime_get(intf_mode);
  v19 = *(__int64 **)(*a1 + 840);
  if ( v19 != (__int64 *)(*a1 + 840) )
  {
    v44 = v11 - 3;
    v20 = 0;
    v21 = v9 | a2 ^ 1;
    v22 = *(_QWORD *)(a1[251] + 1800) + v12;
    v45 = a3 - 8;
    v46 = a3;
    while ( ((*(_DWORD *)(a1[251] + 12) >> *((_DWORD *)v19 + 437)) & 1) == 0 )
    {
LABEL_5:
      v19 = (__int64 *)*v19;
      if ( v19 == (__int64 *)(*a1 + 840) )
        goto LABEL_51;
    }
    if ( (v21 & 1) == 0 )
    {
      v23 = v20;
      if ( v19 == (__int64 *)&unk_8 || (v24 = v19[220]) == 0 )
      {
        v12 = printk(&unk_2196F6, "_sde_plane_get_input_hw_fence");
      }
      else
      {
        v25 = *(_QWORD *)(v24 + 1752);
        if ( v25 )
        {
          if ( (*(_QWORD *)(v25 + 48) & 0x10000) == 0 )
          {
            v26 = *(_QWORD *)(v25 + 48);
            if ( (v26 & 0x80000000) != 0 )
            {
              v27 = *(_QWORD *)(v24 + 1752);
              if ( (_drm_debug & 4) != 0 )
              {
                v28 = *(_QWORD *)(v25 + 40);
                v29 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v25 + 8) + 16LL);
                v43 = *(_QWORD *)(v25 + 32);
                if ( *((_DWORD *)v29 - 1) != -352706110 )
                  __break(0x8228u);
                v30 = (const char *)v29(v25);
                _drm_dev_dbg(0, 0, 0, "input hwfence ctx:%llu seqno:%llu f:0x%lx timeline:%s\n", v43, v28, v26, v30);
LABEL_26:
                v27 = v25;
              }
LABEL_28:
              v12 = sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "_sde_plane_get_input_hw_fence",
                      4474,
                      4,
                      *((_DWORD *)v19 + 24),
                      *(_QWORD *)(v25 + 48),
                      -1059143953,
                      v18,
                      v43);
              a3 = v46;
              v20 = v23;
              *(_QWORD *)(v46 + 8 * v23) = v27;
              if ( v27 && v23 <= 0x17 )
              {
                v34 = v23;
                while ( v34 >= 1 )
                {
                  if ( *(_QWORD *)(v45 + 8 * v34--) == v27 )
                  {
                    *(_QWORD *)(v46 + 8 * v23) = 0;
                    goto LABEL_41;
                  }
                }
                v20 = v23 + 1;
LABEL_41:
                if ( v44 > 1 )
                  goto LABEL_5;
              }
              goto LABEL_37;
            }
            goto LABEL_27;
          }
          if ( v25 <= 0xFFFFFFFFFFFFF000LL )
          {
            if ( (*(_QWORD *)(v25 + 48) & 0x20000) != 0
              || (v12 = spec_sync_wait_bind_array(v25, 84), (v12 & 0x80000000) == 0) )
            {
              v31 = *(_DWORD *)(v25 + 68);
              if ( v31 )
              {
                v32 = 0;
                while ( 1 )
                {
                  v33 = *(_QWORD *)(*(_QWORD *)(v25 + 80) + 8LL * v32);
                  v27 = 0;
                  if ( !v33 || v33 > 0xFFFFFFFFFFFFF000LL )
                    goto LABEL_28;
                  if ( (*(_QWORD *)(v33 + 48) & 0x80000000) == 0 )
                    break;
                  if ( v31 == ++v32 )
                    goto LABEL_26;
                }
              }
LABEL_27:
              v27 = 0;
              goto LABEL_28;
            }
          }
        }
      }
      v20 = v23;
      *(_QWORD *)(a3 + 8 * v23) = 0;
    }
    do
    {
LABEL_37:
      v36 = ktime_get(v12);
      v37 = (((int)v22 - (int)v36) / 1000000) & ~(unsigned int)((v22 - v36) >> 63);
      v12 = sde_plane_wait_input_fence(v19 - 1, v37, &v47);
    }
    while ( v37 && (_DWORD)v12 == -512 );
    goto LABEL_5;
  }
  LODWORD(v20) = 0;
LABEL_51:
  sde_crtc_sw_fence_error_handle(a1, v47, v13, v14, v15, v16, v17, v18);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v20;
}
