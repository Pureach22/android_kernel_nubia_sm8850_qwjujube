unsigned __int64 __fastcall of_qcom_ice_get(__int64 a1)
{
  __int64 resource_byname; // x0
  unsigned __int64 result; // x0
  __int64 v4; // x0
  int v5; // w8
  const char **v6; // x21
  _QWORD *device_by_node; // x0
  _QWORD *v8; // x20
  unsigned __int64 v9; // x21
  __int64 v10; // x8
  const char *v11; // x2
  const char *v12; // x2
  _QWORD v13[11]; // [xsp+8h] [xbp-58h] BYREF

  v13[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *(_QWORD *)(a1 + 744) )
  {
    resource_byname = platform_get_resource_byname(a1 - 16, 512, "ice");
    if ( resource_byname )
    {
      result = devm_ioremap_resource(a1, resource_byname);
      if ( result <= 0xFFFFFFFFFFFFF000LL )
        result = qcom_ice_create(a1, result);
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 744);
      memset(v13, 0, 80);
      v5 = _of_parse_phandle_with_args(v4, "qcom,ice", 0, 0, 0, v13);
      result = 0;
      if ( !v5 )
      {
        v6 = (const char **)v13[0];
        if ( v13[0] )
        {
          device_by_node = (_QWORD *)of_find_device_by_node(v13[0]);
          if ( device_by_node )
          {
            v8 = device_by_node;
            if ( device_by_node[21] )
            {
              v9 = device_by_node[21];
              v10 = device_link_add(a1, device_by_node + 2, 16);
              result = v9;
              *(_QWORD *)(v9 + 16) = v10;
              if ( !v10 )
              {
                v11 = *(const char **)(a1 + 112);
                if ( !v11 )
                  v11 = *(const char **)a1;
                dev_err(v8 + 2, "Failed to create device link to consumer %s\n", v11);
                platform_device_put(v8);
                result = -22;
              }
            }
            else
            {
              v12 = (const char *)device_by_node[16];
              if ( !v12 )
                v12 = (const char *)device_by_node[2];
              dev_err(a1, "Cannot get ice instance from %s\n", v12);
              platform_device_put(v8);
              result = -517;
            }
          }
          else
          {
            dev_err(a1, "Cannot find device node %s\n", *v6);
            result = -517;
          }
        }
      }
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
