__int64 __fastcall lt9611uxc_bridge_attach(__int64 a1)
{
  int v2; // w0
  unsigned __int64 v3; // x19
  const char *v4; // x0
  int v5; // w0
  __int64 v6; // x1
  int v7; // w0
  __int64 mipi_dsi_host_by_node; // x0
  unsigned __int64 v10; // x0
  int v11; // w0
  int v12; // w21
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = *(_QWORD *)"lt9611";
  memset(&v13[1], 0, 24);
  if ( *(_QWORD *)(a1 + 112) )
  {
    v2 = drm_connector_init(*(_QWORD *)(a1 + 104), a1 + 368, &lt9611uxc_connector_funcs, 11);
    if ( v2 )
    {
      LODWORD(v3) = v2;
      v4 = "Failed to initialize connector: %d\n";
LABEL_9:
      _drm_err(v4);
      goto LABEL_10;
    }
    *(_QWORD *)(a1 + 2456) = &lt9611uxc_connector_helper_funcs;
    v5 = drm_connector_register(a1 + 368);
    if ( v5 )
    {
      LODWORD(v3) = v5;
      v4 = "Failed to register connector: %d\n";
      goto LABEL_9;
    }
    v6 = *(_QWORD *)(a1 + 112);
    *(_BYTE *)(a1 + 2448) = 2;
    v7 = drm_connector_attach_encoder(a1 + 368, v6);
    if ( v7 )
    {
      LODWORD(v3) = v7;
      v4 = "Failed to link up connector to encoder: %d\n";
      goto LABEL_9;
    }
    mipi_dsi_host_by_node = of_find_mipi_dsi_host_by_node(*(_QWORD *)(a1 + 296));
    if ( mipi_dsi_host_by_node )
    {
      v10 = mipi_dsi_device_register_full(mipi_dsi_host_by_node, v13);
      v3 = v10;
      if ( v10 < 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)(v10 + 948) = 4;
        *(_QWORD *)(v10 + 960) = 21;
        v11 = mipi_dsi_attach(v10);
        if ( v11 < 0 )
        {
          v12 = v11;
          printk(&unk_B0A9, "lt9611uxc_bridge_attach");
          mipi_dsi_device_unregister(v3);
          LODWORD(v3) = v12;
        }
        else
        {
          *(_QWORD *)(a1 + 304) = v3;
          *(_BYTE *)(a1 + 4013) = 1;
          printk(&unk_AEFD, "lt9611uxc_bridge_attach");
          LODWORD(v3) = 0;
        }
      }
      else
      {
        _drm_err("failed to create dsi device\n");
      }
    }
    else
    {
      _drm_err("failed to find dsi host\n");
      LODWORD(v3) = -517;
    }
  }
  else
  {
    _drm_err("Parent encoder object not found");
    LODWORD(v3) = -19;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3;
}
