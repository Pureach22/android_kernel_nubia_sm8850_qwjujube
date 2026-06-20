void __fastcall dsi_bridge_enable(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 (__fastcall *v8)(_QWORD); // x8
  int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x0

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 468) & 0x31) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d] seamless enable\n", *(_DWORD *)(a1 + 296));
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 304);
      v5 = *(unsigned int *)(*(_QWORD *)(v4 + 168) + 1608LL);
      if ( (unsigned int)v5 >= 3 )
      {
        __break(0x5512u);
        dsi_bridge_mode_validate_and_fixup(a1, a2, a3, a4);
      }
      else
      {
        v7 = *(_QWORD *)(a1 + 304);
        v8 = *(__int64 (__fastcall **)(_QWORD))(v4 + 8 * v5 + 1776);
        if ( *((_DWORD *)v8 - 1) != 2041732229 )
          __break(0x8228u);
        v9 = v8(v7);
        if ( v9 )
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%d] DSI display post enabled failed, rc=%d\n",
            *(_DWORD *)(a1 + 296),
            v9);
        if ( v4 )
        {
          v10 = *(_QWORD *)(v4 + 16);
          *(_BYTE *)(v4 + 1920) = 1;
          if ( v10 )
          {
            sde_connector_helper_bridge_enable(v10);
            if ( *(_BYTE *)(v4 + 1217) == 1 )
            {
              v11 = *(_QWORD *)(v4 + 16);
              *(_BYTE *)(v4 + 1217) = 0;
              sde_connector_schedule_status_work(v11, 1);
            }
          }
        }
      }
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
}
