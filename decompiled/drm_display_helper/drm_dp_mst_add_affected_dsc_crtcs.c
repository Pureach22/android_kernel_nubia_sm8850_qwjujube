__int64 __fastcall drm_dp_mst_add_affected_dsc_crtcs(__int64 a1, _QWORD *a2)
{
  unsigned __int64 private_obj_state; // x0
  _QWORD *v5; // x19
  _QWORD *v6; // x25
  _QWORD *v7; // x26
  __int64 v8; // x1
  unsigned __int64 connector_state; // x0
  const void *v10; // x23
  unsigned __int64 crtc_state; // x0
  unsigned __int64 v12; // x24
  __int64 v13; // x8

  private_obj_state = drm_atomic_get_private_obj_state(a1);
  v5 = (_QWORD *)private_obj_state;
  if ( private_obj_state < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = (_QWORD *)(private_obj_state + 56);
    v7 = *(_QWORD **)(private_obj_state + 56);
    if ( v7 != (_QWORD *)(private_obj_state + 56) )
    {
      do
      {
        if ( !*(_QWORD *)(*(v7 - 4) + 1624LL) )
        {
          LODWORD(v5) = -22;
          return (unsigned int)v5;
        }
        connector_state = drm_atomic_get_connector_state(a1);
        if ( connector_state >= 0xFFFFFFFFFFFFF001LL )
        {
          LODWORD(v5) = connector_state;
          return (unsigned int)v5;
        }
        v10 = *(const void **)(connector_state + 8);
        if ( v10 && drm_dp_mst_dsc_aux_for_port(*(v7 - 4)) )
        {
          crtc_state = drm_atomic_get_crtc_state(*v5, v10);
          v12 = crtc_state;
          if ( crtc_state >= 0xFFFFFFFFFFFFF001LL )
          {
            LODWORD(v5) = crtc_state;
            return (unsigned int)v5;
          }
          v13 = a2[13];
          if ( v13 )
            v8 = *(_QWORD *)(v13 + 8);
          else
            v8 = 0;
          _drm_dev_dbg(0, v8, 4, "[MST MGR:%p] Setting mode_changed flag on CRTC %p\n", a2, v10);
          *(_BYTE *)(v12 + 10) |= 2u;
        }
        v7 = (_QWORD *)*v7;
      }
      while ( v7 != v6 );
    }
    LODWORD(v5) = 0;
  }
  return (unsigned int)v5;
}
