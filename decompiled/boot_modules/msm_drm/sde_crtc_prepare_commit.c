__int64 __fastcall sde_crtc_prepare_commit(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x23
  __int64 v10; // x21
  __int64 i; // x0
  __int64 v12; // x9
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x25
  __int64 result; // x0
  char v17; // [xsp+0h] [xbp-20h]
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  if ( a1 && (v8 = a1[251]) != 0 )
  {
    v10 = *a1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_crtc_prepare_commit",
      3369,
      4,
      *((_DWORD *)a1 + 28),
      *(_DWORD *)(v8 + 1812),
      -1059143953,
      a8,
      v17);
    _ReadStatusReg(SP_EL0);
    *(_DWORD *)(v8 + 464) = 0;
    drm_connector_list_iter_begin(v10, v18);
    for ( i = drm_connector_list_iter_next(v18); i; i = drm_connector_list_iter_next(v18) )
    {
      v12 = *(_QWORD *)(i + 2512);
      if ( v12 )
      {
        if ( *(__int64 **)(v12 + 8) == a1 )
        {
          v13 = *(_DWORD *)(v8 + 464);
          if ( v13 <= 15 )
          {
            v14 = *(_QWORD *)(v12 + 16);
            if ( v14 )
            {
              v15 = i;
              sde_encoder_register_frame_event_callback(*(_QWORD *)(v12 + 16), &sde_crtc_frame_event_cb, a1);
              v13 = *(_DWORD *)(v8 + 464);
              i = v15;
            }
            *(_DWORD *)(v8 + 464) = v13 + 1;
            if ( (unsigned int)v13 >= 0x10 )
              __break(0x5512u);
            *(_QWORD *)(v8 + 336 + 8LL * (unsigned int)v13) = i;
            sde_connector_prepare_fence();
            ((void (__fastcall *)(__int64, __int64))sde_encoder_set_clone_mode)(v14, a1[251]);
          }
        }
      }
    }
    drm_connector_list_iter_end(v18);
    result = sde_fence_prepare(a1[404]);
  }
  else
  {
    result = printk(&unk_25E167, "sde_crtc_prepare_commit");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
