__int64 __fastcall cam_icp_handle_secure_port_config(__int64 a1, char a2)
{
  void *v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w6
  unsigned int v9; // w9
  int v10; // w11
  unsigned int v11; // w10
  int v12; // w13
  int v13; // w11
  int v14; // w12
  int v15; // w16
  int v16; // w17
  int v17; // w13
  __int64 v18; // x16
  char v19; // w15
  unsigned __int64 v20; // x9
  __int64 v21; // x10
  _DWORD *v22; // x11
  const char *v23; // x14
  __int64 v24; // x8
  int v25; // w15
  __int16 v26; // w16
  const char *v27; // x20
  int v28; // w7
  const char *v29; // x6
  unsigned int v30; // w19
  const char *v31; // x5
  __int64 v32; // x4
  _DWORD *v33; // [xsp+10h] [xbp-140h]
  unsigned __int64 v34; // [xsp+18h] [xbp-138h]
  __int64 v35; // [xsp+20h] [xbp-130h]
  __int64 v36; // [xsp+28h] [xbp-128h]
  _DWORD v37[70]; // [xsp+30h] [xbp-120h] BYREF
  __int64 v38; // [xsp+148h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = memset(&v37[1], 0, 0x114u);
  if ( *(_DWORD *)(a1 + 88) == 1 )
  {
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_handle_secure_port_config",
        5080,
        "%s: Legacy acquire with all secure ports: %d",
        (const char *)(a1 + 29824),
        *(_DWORD *)(a1 + 104));
LABEL_49:
      result = 0;
    }
    goto LABEL_50;
  }
  v7 = *(_QWORD *)(a1 + 16);
  v8 = *(_DWORD *)(v7 + 8);
  if ( (unsigned int)(v8 - 2) > 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_camera_device_type",
      146,
      "Invalid hardware type: %u",
      v8);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_handle_secure_port_config",
      5089,
      "Invalid CPAS camera device type %d",
      6);
    result = 4294967274LL;
    goto LABEL_50;
  }
  v9 = *(_DWORD *)(v7 + 580);
  v37[0] = v8 + 1;
  if ( v9 )
  {
    if ( v9 == 1 )
    {
      v10 = 0;
      v11 = 0;
    }
    else
    {
      v12 = 0;
      v13 = 0;
      v14 = 0;
      v11 = v9 & 0xFFFFFFFE;
      do
      {
        v15 = 1 << v12;
        v16 = 2 << v12;
        v12 += 2;
        v13 |= v15;
        v14 |= v16;
      }
      while ( v11 != v12 );
      v10 = v14 | v13;
      if ( v9 == v11 )
        goto LABEL_14;
    }
    do
    {
      v17 = 1 << v11++;
      v10 |= v17;
    }
    while ( v11 < v9 );
LABEL_14:
    v37[1] = v10;
  }
  LOBYTE(v37[2]) = a2 & 1;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = a1 + 30108;
  v22 = &v37[5];
  v23 = "%s: Secure usecase on device %d has non-secure port %d";
LABEL_16:
  v24 = v18;
  do
  {
    if ( (*(_BYTE *)(v21 + v24) & 1) == 0 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(a1 + 16) + 8LL) != 2 )
      {
        v31 = "Dynamic port config is not supported on this device %d";
        v32 = 189;
LABEL_52:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_get_cpas_out_port_id",
          v32,
          v31);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_handle_secure_port_config",
          5116,
          "%s: Invalid port for the device type requested - %d",
          (const char *)(a1 + 29824),
          *(_DWORD *)(a1 + 104));
        result = 4294967274LL;
        goto LABEL_50;
      }
      if ( (int)v24 > 11 )
      {
        if ( (int)v24 > 50 )
        {
          if ( (_DWORD)v24 == 51 )
          {
            v25 = 6;
          }
          else
          {
            if ( (_DWORD)v24 != 61 )
            {
LABEL_53:
              v31 = "Invalid IPE output port ID: %u";
              v32 = 184;
              goto LABEL_52;
            }
            v25 = 7;
          }
        }
        else if ( (_DWORD)v24 == 12 )
        {
          v25 = 4;
        }
        else
        {
          if ( (_DWORD)v24 != 13 )
            goto LABEL_53;
          v25 = 5;
        }
      }
      else if ( (int)v24 > 9 )
      {
        if ( (_DWORD)v24 == 10 )
        {
          v25 = 2;
        }
        else
        {
          if ( (_DWORD)v24 != 11 )
            goto LABEL_53;
          v25 = 3;
        }
      }
      else if ( (_DWORD)v24 == 8 )
      {
        v25 = 0;
      }
      else
      {
        if ( (_DWORD)v24 != 9 )
          goto LABEL_53;
        v25 = 1;
      }
      if ( v20 > 0x40 )
      {
        __break(0x5512u);
        return cam_icp_mgr_device_resume(v4, v5);
      }
      v26 = debug_mdl;
      v22[v20] = v25;
      if ( (v26 & 0x100) != 0 && !debug_priority )
      {
        v27 = v23;
        v35 = v21;
        v36 = v24;
        v33 = v22;
        v34 = v20;
        v4 = (void *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64, __int64, _DWORD))cam_print_log)(
                       3,
                       v26 & 0x100,
                       4,
                       "cam_icp_handle_secure_port_config",
                       5111,
                       v23,
                       a1 + 29824,
                       2,
                       v24);
        v22 = v33;
        v20 = v34;
        v21 = v35;
        v24 = v36;
        v23 = v27;
      }
      ++v20;
      v18 = v24 + 1;
      v19 = 1;
      if ( v24 == 64 )
      {
        v37[4] = v20;
        goto LABEL_47;
      }
      goto LABEL_16;
    }
    ++v24;
  }
  while ( v24 != 65 );
  v37[4] = v20;
  if ( (v19 & 1) == 0 )
    goto LABEL_49;
LABEL_47:
  result = cam_cpas_config_cp_mapping_ctrl((__int64)v37);
  if ( (_DWORD)result )
  {
    v28 = *(_DWORD *)(a1 + 104);
    v29 = (const char *)(a1 + 29824);
    v30 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_handle_secure_port_config",
      5128,
      "%s: Unable to configure the output ports for the usecase:%d",
      v29,
      v28);
    result = v30;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
