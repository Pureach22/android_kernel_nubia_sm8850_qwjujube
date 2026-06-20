__int64 __fastcall sde_crtc_check_dest_scaler_data(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x24
  unsigned int v6; // w25
  unsigned int v7; // w21
  __int64 v8; // x8
  unsigned int v10; // w4
  int v11; // w6
  unsigned __int64 v18; // x10
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( a2 )
  {
    if ( a1 && *(_QWORD *)a1 && (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    {
      v5 = *(_QWORD *)(v4 + 8);
      if ( !v5 )
        printk(&unk_234896, "_sde_crtc_get_kms");
    }
    else
    {
      printk(&unk_25E167, "_sde_crtc_get_kms");
      v5 = 0;
    }
    mutex_lock(a1 + 1154);
    v6 = a1[548];
    if ( v6 && *(_BYTE *)(a2 + 6921) == 1 )
      v6 = *(_DWORD *)(a2 + 7084);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "crtc%d\n", a1[28]);
    if ( (*(_QWORD *)(a2 + 1792) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "dest scaler property not set, skip validation\n");
      goto LABEL_27;
    }
    if ( !v5 || (v8 = *(_QWORD *)(v5 + 152)) == 0 )
    {
      printk(&unk_23F134, "_sde_crtc_check_dest_scaler_data");
      v7 = -22;
      goto LABEL_28;
    }
    if ( (*(_BYTE *)(v8 + 708) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "dest scaler feature not supported\n");
      goto LABEL_27;
    }
    if ( !v6 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "mixers not allocated\n");
      goto LABEL_27;
    }
    v7 = sde_validate_hw_resources(a1, a2);
    if ( v7 )
    {
LABEL_41:
      _X8 = (unsigned __int64 *)(a2 + 1792);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      goto LABEL_28;
    }
    v10 = *(_DWORD *)(a2 + 2044);
    if ( v10 > *(_DWORD *)(*(_QWORD *)(v5 + 152) + 8840LL)
      || (v11 = *(_DWORD *)(a2 + 2060), v10 != v6) && ((v11 & 1) != 0 || (*(_BYTE *)(a2 + 6922) & 1) == 0) )
    {
      printk(&unk_245EE8, "_sde_crtc_check_dest_scaler_data");
      v7 = -22;
      goto LABEL_41;
    }
    if ( (v11 & 1) != 0 )
    {
      v7 = sde_crtc_check_dest_scaler_validate_ds(a1, a1, a2, a2 + 24, *(unsigned __int16 *)(a2 + 28) / v6, &v19);
      if ( v7 )
        goto LABEL_41;
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "disable dest scaler, num(%d) flags(%d)\n", v10, v11);
    }
    sde_crtc_check_dest_scaler_data_disable((int)a1, a2, v19);
LABEL_27:
    v7 = 0;
LABEL_28:
    mutex_unlock(a1 + 1154);
    goto LABEL_29;
  }
  v7 = -22;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v7;
}
