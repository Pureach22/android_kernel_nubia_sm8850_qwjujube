__int64 __fastcall sde_lb_connector_get_modes(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x20
  _QWORD *v6; // x20
  _QWORD *v7; // x22
  _QWORD *v8; // t1
  unsigned int v9; // w21
  __int64 v10; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *a1;
    v12[0] = 0;
    v12[1] = 0;
    if ( v3 )
    {
      drm_connector_list_iter_begin(v3, v12);
      do
      {
        v4 = drm_connector_list_iter_next(v12);
        if ( !v4 )
        {
          drm_connector_list_iter_end(v12);
          goto LABEL_12;
        }
        v5 = v4;
      }
      while ( *(_DWORD *)(v4 + 156) != 16 );
      drm_connector_list_iter_end(v12);
      v8 = *(_QWORD **)(v5 + 176);
      v6 = (_QWORD *)(v5 + 176);
      v7 = v8;
      if ( v8 == v6 )
        goto LABEL_14;
      v9 = 0;
      do
      {
        v10 = drm_mode_duplicate(*a1, v7 - 8);
        drm_mode_probed_add(a1, v10);
        v7 = (_QWORD *)*v7;
        ++v9;
      }
      while ( v7 != v6 );
    }
    else
    {
      printk(&unk_21E943, a2);
LABEL_12:
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "primary connector is not created yet\n");
LABEL_14:
      v9 = 0;
    }
  }
  else
  {
    v9 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
