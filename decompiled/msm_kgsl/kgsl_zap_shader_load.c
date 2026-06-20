__int64 __fastcall kgsl_zap_shader_load(__int64 a1, const char *a2)
{
  __int64 v4; // x0
  __int64 child_by_name; // x0
  unsigned __int64 v6; // x21
  int v7; // w0
  unsigned __int64 size; // x0
  __int64 v9; // x23
  __int64 v10; // x0
  __int64 v11; // x22
  int v12; // w0
  __int64 v14; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v15; // [xsp+8h] [xbp-B8h]
  __int64 v16; // [xsp+10h] [xbp-B0h]
  __int64 v17; // [xsp+18h] [xbp-A8h]
  __int64 v18; // [xsp+20h] [xbp-A0h]
  __int64 v19; // [xsp+28h] [xbp-98h]
  __int64 v20; // [xsp+30h] [xbp-90h]
  __int64 v21; // [xsp+38h] [xbp-88h]
  __int64 v22; // [xsp+40h] [xbp-80h]
  __int64 v23; // [xsp+48h] [xbp-78h]
  __int64 v24; // [xsp+50h] [xbp-70h]
  __int64 v25; // [xsp+58h] [xbp-68h]
  __int64 v26; // [xsp+60h] [xbp-60h] BYREF
  _QWORD v27[11]; // [xsp+68h] [xbp-58h] BYREF

  v27[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  child_by_name = of_get_child_by_name(v4, "zap-shader");
  if ( child_by_name )
  {
    memset(v27, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(child_by_name, "memory-region", 0, 0, 0, v27) || !v27[0] )
    {
      dev_err(a1, "Couldn't parse the mem-region from the zap-shader node\n");
      LODWORD(v6) = -22;
    }
    else
    {
      LODWORD(v6) = of_address_to_resource(v27[0], 0, &v14);
      if ( !(_DWORD)v6 )
      {
        v7 = request_firmware(&v26, a2, a1);
        if ( v7 )
        {
          LODWORD(v6) = v7;
          dev_err(a1, "Couldn't load the firmware %s\n", a2);
        }
        else
        {
          size = qcom_mdt_get_size(v26);
          v6 = size;
          if ( (size & 0x8000000000000000LL) == 0 )
          {
            v9 = v14;
            if ( size <= v15 - v14 + 1 )
            {
              v10 = memremap(v14, size, 4);
              if ( v10 )
              {
                v11 = v10;
                v12 = qcom_mdt_load(a1, v26, a2, 13, v10, v9, v6, 0);
                if ( v12 )
                {
                  LODWORD(v6) = v12;
                  dev_err(a1, "Error %d while loading the MDT\n", v12);
                }
                else
                {
                  LODWORD(v6) = qcom_scm_pas_auth_and_reset(13);
                }
                memunmap(v11);
              }
              else
              {
                LODWORD(v6) = -12;
              }
            }
            else
            {
              LODWORD(v6) = -7;
            }
          }
          release_firmware(v26);
        }
      }
    }
  }
  else
  {
    dev_err(a1, "zap-shader node not found. Please update the device tree\n");
    LODWORD(v6) = -19;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
