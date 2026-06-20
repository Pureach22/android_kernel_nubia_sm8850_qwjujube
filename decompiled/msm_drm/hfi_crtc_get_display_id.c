__int64 __fastcall hfi_crtc_get_display_id(__int64 *a1, __int64 a2)
{
  unsigned int i; // w21
  __int64 v5; // x0
  __int64 *v6; // x23
  __int64 *v7; // x22
  char v8; // w8
  __int64 *v9; // x23
  __int64 v10; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  i = -1;
  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v5 = *a1;
    v12[0] = 0;
    v12[1] = 0;
    v6 = *(__int64 **)(v5 + 816);
    if ( v6 != (__int64 *)(v5 + 816) )
    {
      v7 = nullptr;
      do
      {
        if ( ((*(_DWORD *)(a2 + 20) >> *((_DWORD *)v6 + 15)) & 1) != 0 )
        {
          v8 = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v6 - 1);
          v5 = *a1;
          if ( (v8 & 1) == 0 )
            v7 = v6 - 1;
        }
        v6 = (__int64 *)*v6;
      }
      while ( v6 != (__int64 *)(v5 + 816) );
      if ( v7 )
        goto LABEL_20;
    }
    v9 = *(__int64 **)(v5 + 816);
    if ( v9 == (__int64 *)(v5 + 816) )
      goto LABEL_25;
    v7 = nullptr;
    do
    {
      if ( ((*((_DWORD *)a1 + 1968) >> *((_DWORD *)v9 + 15)) & 1) != 0
        && (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v9 - 1) & 1) == 0 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "found encoder from cached\n");
        v7 = v9 - 1;
      }
      v5 = *a1;
      v9 = (__int64 *)*v9;
    }
    while ( v9 != (__int64 *)(*a1 + 816) );
    if ( !v7 )
    {
LABEL_25:
      i = -1;
    }
    else
    {
LABEL_20:
      drm_connector_list_iter_begin(v5, v12);
      v10 = drm_connector_list_iter_next(v12);
      for ( i = -1; v10; v10 = drm_connector_list_iter_next(v12) )
      {
        if ( *(__int64 **)(v10 + 2744) == v7 )
          i = *(_DWORD *)(v10 + 2740);
      }
      drm_connector_list_iter_end(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return i;
}
