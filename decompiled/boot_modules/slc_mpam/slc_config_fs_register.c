__int64 __fastcall slc_config_fs_register(__int64 a1)
{
  __int64 v2; // x21
  __int64 root_group; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x27
  unsigned int i; // w20
  __int64 v8; // x21
  __int64 v9; // x0
  unsigned __int64 config_node; // x0
  unsigned __int64 v11; // x24
  unsigned int v12; // w25
  __int64 result; // x0
  const char *v14; // [xsp+8h] [xbp-28h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v16; // [xsp+18h] [xbp-18h]
  int v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  v17 = 0;
  *(_QWORD *)s = 0;
  v16 = 0;
  v14 = nullptr;
  root_group = platform_mpam_get_root_group();
  if ( !root_group )
    goto LABEL_16;
  v4 = root_group;
  of_property_read_string(v2, "qcom,msc-name", &v14);
  ::root_group = configfs_register_default_group(v4, v14, &slc_mpam_root_type);
  if ( (unsigned __int64)::root_group >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1, "Error register group %s\n", v14);
    result = (unsigned int)::root_group;
    goto LABEL_17;
  }
  v5 = qcom_msc_lookup(2);
  if ( v5 && *(_WORD *)(v5 + 14) == 2 )
  {
    v6 = *(_QWORD *)(v5 + 16);
    if ( *(_DWORD *)v6 )
    {
      for ( i = 0; i < *(_DWORD *)v6; ++i )
      {
        v8 = *(_QWORD *)(v6 + 4) + 21LL * (int)i;
        if ( *(_BYTE *)(v8 + 12) )
        {
          v9 = *(_QWORD *)(v8 + 13);
          if ( *(unsigned __int16 *)(v8 + 2) < 2u )
          {
            create_config_node(v9, a1, i, 0, ::root_group, &slc_mpam_item_type);
          }
          else
          {
            config_node = create_config_node(v9, a1, i, 0xFFFFFFFFLL, ::root_group, &slc_mpam_client_monitor_type);
            if ( config_node > 0xFFFFFFFFFFFFF000LL )
              break;
            if ( *(_WORD *)(v8 + 2) )
            {
              v11 = config_node;
              v12 = 0;
              do
              {
                snprintf(s, 0x14u, "partid%d", v12);
                create_config_node(s, a1, i, v12++, v11, &slc_mpam_item_type);
              }
              while ( v12 < *(unsigned __int16 *)(v8 + 2) );
            }
          }
        }
      }
    }
    result = 0;
  }
  else
  {
LABEL_16:
    result = 4294967274LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
