__int64 __fastcall sde_kms_set_crtc_for_conn(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x1
  unsigned __int64 crtc_state; // x19
  unsigned __int64 connector_state; // x21
  _QWORD v11[3]; // [xsp+8h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v11[1] = 0;
  drm_connector_list_iter_begin(a1, v11);
  do
  {
    v5 = drm_connector_list_iter_next(v11);
    if ( !v5 )
    {
      drm_connector_list_iter_end(v11);
      goto LABEL_11;
    }
  }
  while ( *(_QWORD *)(*(_QWORD *)(v5 + 2512) + 16LL) != a2 );
  v6 = v5;
  drm_connector_list_iter_end(v11);
  v7 = *(_QWORD *)(a2 + 80);
  if ( !v7 )
  {
LABEL_11:
    printk(&unk_23F7B7, "sde_kms_set_crtc_for_conn");
    LODWORD(crtc_state) = -22;
    goto LABEL_9;
  }
  crtc_state = drm_atomic_get_crtc_state(a3, v7);
  if ( crtc_state >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_2354B2, "sde_kms_set_crtc_for_conn");
  }
  else
  {
    connector_state = drm_atomic_get_connector_state(a3, v6);
    if ( connector_state >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_219CD8, "sde_kms_set_crtc_for_conn");
      LODWORD(crtc_state) = connector_state;
    }
    else
    {
      sde_crtc_force_async_mode(a2, crtc_state);
      *(_WORD *)(crtc_state + 8) = 257;
      LODWORD(crtc_state) = drm_atomic_set_crtc_for_connector(connector_state, *(_QWORD *)(a2 + 80));
      if ( (_DWORD)crtc_state )
        printk(&unk_269341, "sde_kms_set_crtc_for_conn");
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)crtc_state;
}
