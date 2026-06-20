unsigned __int64 __fastcall coresight_get_platform_data(__int64 a1)
{
  unsigned __int64 v2; // x0
  int v3; // w28
  unsigned __int64 v4; // x21
  __int64 v5; // x0
  unsigned __int64 v6; // x20
  unsigned __int64 result; // x0
  __int64 v8; // x23
  __int64 child_by_name; // x21
  __int64 v10; // x22
  __int64 next_endpoint; // x0
  __int64 v12; // x23
  const char *v13; // x25
  __int64 device; // x26
  __int64 remote_endpoint; // x0
  __int64 port_parent; // x27
  unsigned __int64 reference; // x0
  const char *v18; // x27
  __int64 v19; // x0
  const char **v20; // x28
  __int64 v21; // x25
  const char *v22; // x3
  unsigned __int64 v23; // x0
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8
  unsigned __int64 v26; // [xsp+0h] [xbp-70h]
  __int64 v27; // [xsp+8h] [xbp-68h] BYREF
  unsigned __int64 v28; // [xsp+10h] [xbp-60h]
  __int64 v29; // [xsp+18h] [xbp-58h]
  __int64 v30; // [xsp+20h] [xbp-50h]
  __int64 v31; // [xsp+28h] [xbp-48h]
  unsigned __int64 v32; // [xsp+30h] [xbp-40h]
  __int64 v33; // [xsp+38h] [xbp-38h]
  __int64 v34; // [xsp+40h] [xbp-30h]
  _QWORD v35[2]; // [xsp+48h] [xbp-28h] BYREF
  _QWORD v36[3]; // [xsp+58h] [xbp-18h] BYREF

  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _dev_fwnode(a1);
  v3 = -2;
  if ( !v2 )
    goto LABEL_9;
  v4 = v2;
  if ( v2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_9;
  v5 = devm_kmalloc(a1, 24, 3520);
  if ( !v5 )
  {
    v3 = -12;
    goto LABEL_9;
  }
  v6 = v5;
  if ( *(_UNKNOWN **)(v4 + 8) != &of_fwnode_ops )
  {
    v3 = -2;
    goto LABEL_6;
  }
  v8 = *(_QWORD *)(a1 + 744);
  child_by_name = of_get_child_by_name(v8, "out-ports");
  v10 = child_by_name;
  if ( !child_by_name )
  {
    if ( (of_graph_is_present(v8) & 1) == 0 )
    {
LABEL_54:
      result = v6;
      goto LABEL_10;
    }
    if ( (of_get_coresight_platform_data___print_once & 1) == 0 )
    {
      of_get_coresight_platform_data___print_once = 1;
      dev_warn(a1, "Uses obsolete Coresight DT bindings\n");
    }
    v10 = v8;
  }
  next_endpoint = of_graph_get_next_endpoint(v10, 0);
  if ( !next_endpoint )
    goto LABEL_54;
  v12 = next_endpoint;
  v13 = "in-ports";
  while ( 1 )
  {
    if ( !child_by_name && of_find_property(v12, "slave-mode", 0) )
      goto LABEL_19;
    v36[0] = 0;
    v36[1] = 0;
    v35[0] = 0;
    v35[1] = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    if ( (unsigned int)of_graph_parse_endpoint(v12, v36) )
      goto LABEL_22;
    remote_endpoint = of_graph_get_remote_endpoint(v12);
    device = remote_endpoint;
    if ( !remote_endpoint )
      goto LABEL_23;
    port_parent = of_graph_get_port_parent(remote_endpoint);
    if ( (of_node_name_eq(port_parent, v13) & 1) != 0 || (of_node_name_eq(port_parent, "out-ports") & 1) != 0 )
      port_parent = of_get_next_parent(port_parent);
    if ( !port_parent || (unsigned int)of_graph_parse_endpoint(device, v35) )
    {
LABEL_22:
      device = 0;
LABEL_23:
      v3 = 0;
      goto LABEL_24;
    }
    device = bus_find_device(&platform_bus_type, 0, port_parent + 24, &device_match_fwnode);
    if ( device )
      break;
    device = bus_find_device(&amba_bustype, 0, port_parent + 24, &device_match_fwnode);
    if ( device )
      break;
    v3 = -517;
LABEL_24:
    put_device(device);
    if ( v3 )
      goto LABEL_6;
LABEL_19:
    v12 = of_graph_get_next_endpoint(v10, v12);
    if ( !v12 )
      goto LABEL_54;
  }
  LODWORD(v27) = v36[0];
  v26 = fwnode_handle_get(port_parent + 24);
  v28 = v26;
  HIDWORD(v27) = v35[0];
  reference = fwnode_find_reference(v12 + 24, "filter-source", 0);
  v32 = reference;
  if ( reference < 0xFFFFFFFFFFFFF001LL )
  {
    v18 = v13;
    v19 = bus_find_device(&coresight_bustype, 0, reference, &device_match_fwnode);
    if ( v19 )
    {
      v20 = (const char **)v19;
      v21 = v19 - 56;
      put_device(v19);
      v33 = v21;
      if ( v21 && *((_DWORD *)v20 - 12) != 3 )
      {
        v22 = v20[14];
        if ( !v22 )
          v22 = *v20;
        dev_warn(a1, "port %d: Filter handle is not a trace source : %s\n", v27, v22);
        v32 = 0;
        v33 = 0;
      }
    }
    else
    {
      v33 = 0;
    }
  }
  else
  {
    v18 = v13;
    v32 = 0;
  }
  v23 = coresight_add_out_conn(a1, v6, &v27);
  if ( v23 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = 0;
    v13 = v18;
    goto LABEL_24;
  }
  v3 = v23;
  if ( v26 )
  {
    if ( v26 <= 0xFFFFFFFFFFFFF000LL )
    {
      v24 = *(_QWORD *)(v26 + 8);
      if ( v24 )
      {
        v25 = *(void (__fastcall **)(_QWORD))(v24 + 8);
        if ( v25 )
        {
          if ( *((_DWORD *)v25 - 1) != -643302289 )
            __break(0x8228u);
          v25(v26);
        }
      }
    }
  }
LABEL_6:
  if ( v6 <= 0xFFFFFFFFFFFFF000LL )
    coresight_release_platform_data(0, a1, v6);
LABEL_9:
  result = v3;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
