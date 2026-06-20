__int64 __fastcall sde_encoder_virt_modeset_rc(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  _BOOL4 v7; // w24
  __int64 v8; // x8
  __int64 v9; // x22
  _BOOL4 v10; // w8
  __int64 result; // x0
  __int64 v12; // x1
  unsigned int v13; // w8
  unsigned int v14; // w9
  int v15; // w8
  int v16; // w23
  int v17; // w8
  unsigned int v19; // w8
  int v20; // w22
  __int64 v21; // x8
  int v22; // w22
  int v23; // w8
  __int64 v24; // x9
  unsigned int v25; // w8
  unsigned int v26; // w0
  unsigned int v27; // w21
  int v28; // w20
  int v29; // w8
  int v30; // w4
  int v31; // w6
  int v32; // w0
  char v33; // w9
  int v34; // w2
  int v35; // w5
  int v36; // w7
  int v37; // w8
  unsigned int v38; // w19
  unsigned int v39; // w20
  char v40; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v7 = 0;
    if ( (a4 & 1) != 0 )
      goto LABEL_3;
LABEL_23:
    if ( a3 )
    {
      v19 = *(_DWORD *)(a3 + 8);
      if ( (v19 & 4) != 0 || (v7 & (v19 >> 4)) == 1 )
      {
        sde_encoder_resource_control(a1, 5);
      }
      else if ( (v19 & 0xC0) != 0 )
      {
        sde_encoder_modeset_helper_locked(a1, 5);
      }
    }
    return 0;
  }
  v7 = *(_DWORD *)(a1 + 648) == 2;
  if ( (a4 & 1) == 0 )
    goto LABEL_23;
LABEL_3:
  v8 = *(_QWORD *)(a1 + 328);
  if ( v8 )
    v9 = v8 + 520;
  else
    v9 = 0;
  if ( v9 )
    v10 = v7;
  else
    v10 = 0;
  if ( v10 && (drm_mode_match(v9, a2, 1) & 1) == 0 && (*(_BYTE *)(a1 + 700) & 1) != 0
    || (result = sde_encoder_is_cwb_disabling(a1, *(_QWORD *)(a1 + 80)), (result & 1) != 0) )
  {
    result = sde_encoder_wait_for_event(a1, 1u);
    if ( (_DWORD)result != -11 )
    {
      if ( (_DWORD)result )
      {
        v39 = result;
        printk(&unk_24C8F4, "sde_encoder_virt_modeset_rc");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_virt_modeset_rc",
          3516,
          -1,
          *(_DWORD *)(a1 + 24),
          v39,
          60333,
          -1059143953,
          v40);
        return v39;
      }
    }
  }
  *(_DWORD *)(a1 + 4952) = 0;
  if ( v9 )
  {
    v13 = *(unsigned __int16 *)(v9 + 14);
    v14 = *(unsigned __int16 *)(a2 + 14);
    if ( v13 <= v14 )
    {
      if ( v13 >= v14 )
      {
        v16 = drm_mode_vrefresh(v9);
        result = drm_mode_vrefresh(a2);
        if ( v16 <= (int)result )
        {
          v20 = drm_mode_vrefresh(v9);
          result = drm_mode_vrefresh(a2);
          if ( v20 >= (int)result )
            goto LABEL_33;
          v17 = 1;
        }
        else
        {
          v17 = 2;
        }
        v15 = *(_DWORD *)(a1 + 4952) | v17;
      }
      else
      {
        v15 = 4;
      }
    }
    else
    {
      v15 = 8;
    }
    *(_DWORD *)(a1 + 4952) = v15;
  }
LABEL_33:
  if ( a1 )
  {
    v21 = *(_QWORD *)(a1 + 328);
    if ( v21 )
    {
      v22 = *(_DWORD *)(v21 + 668);
      if ( !a3 )
        return 0;
      goto LABEL_51;
    }
    v23 = *(_DWORD *)(a1 + 196);
    if ( v23 )
    {
      v24 = *(_QWORD *)(a1 + 200);
      if ( v24 )
        goto LABEL_39;
      if ( v23 != 1 )
      {
        v24 = *(_QWORD *)(a1 + 208);
        if ( v24 )
          goto LABEL_39;
        if ( v23 == 2 )
          goto LABEL_50;
        v24 = *(_QWORD *)(a1 + 216);
        if ( v24 )
          goto LABEL_39;
        if ( v23 == 3 )
          goto LABEL_50;
        v24 = *(_QWORD *)(a1 + 224);
        if ( v24 )
        {
LABEL_39:
          v22 = *(_DWORD *)(v24 + 668);
          if ( !a3 )
            return 0;
          goto LABEL_51;
        }
        if ( v23 != 4 )
          goto LABEL_84;
      }
    }
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_get_intf_mode");
  }
LABEL_50:
  v22 = 0;
  if ( !a3 )
    return 0;
LABEL_51:
  v25 = *(_DWORD *)(a3 + 8);
  if ( (v25 & 4) != 0 || (v7 & (v25 >> 4)) == 1 )
  {
    v26 = sde_encoder_resource_control(a1, 4);
    if ( v26 )
    {
      v38 = v26;
      printk(&unk_26C949, "sde_encoder_virt_modeset_rc");
      return v38;
    }
    sde_encoder_dce_disable(a1);
    return 0;
  }
  if ( (v25 & 0xC0) == 0 )
    return 0;
  sde_encoder_modeset_helper_locked(a1, 4);
  v27 = *(_DWORD *)(a3 + 8) & 0x80;
  if ( (*(_DWORD *)(a3 + 8) & 0x40) != 0 )
  {
    v28 = 1;
    *(_DWORD *)(a1 + 648) = 1;
    result = ((__int64 (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
    if ( v22 == 1 )
    {
      v29 = *(_DWORD *)(a1 + 196);
      if ( !v29
        || (*(_QWORD *)(a1 + 200) = *(_QWORD *)(a1 + 232), v29 == 1)
        || (*(_QWORD *)(a1 + 208) = *(_QWORD *)(a1 + 240), v29 == 2)
        || (*(_QWORD *)(a1 + 216) = *(_QWORD *)(a1 + 248), v29 == 3)
        || (*(_QWORD *)(a1 + 224) = *(_QWORD *)(a1 + 256), v29 == 4) )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "enc%d switch to video physical encoder\n", *(_DWORD *)(a1 + 24));
        v30 = *(_DWORD *)(a1 + 24);
        v31 = v27 >> 7;
        v32 = sde_dbg_base_evtlog;
        v33 = 51;
        v34 = 3384;
        v35 = 1;
        v36 = 1;
        goto LABEL_81;
      }
LABEL_84:
      __break(0x5512u);
      return sde_encoder_modeset_helper_locked(result, v12);
    }
  }
  else
  {
    if ( v27 )
      *(_DWORD *)(a1 + 648) = 2;
    ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
    v28 = 0;
  }
  result = 0;
  if ( v22 == 2 && v27 )
  {
    v37 = *(_DWORD *)(a1 + 196);
    if ( !v37
      || (*(_QWORD *)(a1 + 200) = *(_QWORD *)(a1 + 264), v37 == 1)
      || (*(_QWORD *)(a1 + 208) = *(_QWORD *)(a1 + 272), v37 == 2)
      || (*(_QWORD *)(a1 + 216) = *(_QWORD *)(a1 + 280), v37 == 3)
      || (*(_QWORD *)(a1 + 224) = *(_QWORD *)(a1 + 288), v37 == 4) )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "enc%d switch to command physical encoder\n", *(_DWORD *)(a1 + 24));
      v30 = *(_DWORD *)(a1 + 24);
      v33 = 68;
      v32 = sde_dbg_base_evtlog;
      v34 = 3391;
      v35 = 2;
      v31 = 1;
      v36 = v28;
LABEL_81:
      sde_evtlog_log(v32, "sde_encoder_virt_mode_switch", v34, -1, v30, v35, v31, v36, v33);
      return 0;
    }
    goto LABEL_84;
  }
  return result;
}
