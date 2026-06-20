__int64 __fastcall dsi_display_get_phandle_index(_QWORD *a1, char *a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x23
  unsigned int u32_array; // w22
  unsigned __int64 v9; // x21
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x25
  int variable_u32_array; // w0
  unsigned __int64 v13; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x26

  v4 = a1[34];
  u32_array = a3;
  if ( (a3 & 0x80000000) != 0 )
  {
    v10 = 0;
    u32_array = -12;
  }
  else
  {
    v9 = 4LL * a3;
    v10 = _kmalloc_noprof(v9, 3520);
    while ( 1 )
    {
      if ( v10 < 0x11 )
      {
        u32_array = -12;
        goto LABEL_15;
      }
      if ( (int)a4 >= (int)u32_array )
      {
        u32_array = 0;
        goto LABEL_15;
      }
      v11 = v10;
      if ( a1[198] )
      {
        u32_array = dsi_parser_read_u32_array(a1[35], a2);
        if ( u32_array )
          goto LABEL_14;
      }
      else
      {
        variable_u32_array = of_property_read_variable_u32_array(v4, a2, v10, u32_array, 0);
        u32_array = variable_u32_array & (variable_u32_array >> 31);
        if ( u32_array )
          goto LABEL_14;
      }
      v13 = 4LL * a4;
      if ( v9 >= v13 && v9 - v13 >= 4 )
        break;
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &dsi_display_get_phandle_index__alloc_tag;
      v9 = 4LL * u32_array;
      v10 = _kmalloc_noprof(v9, 3520);
      *(_QWORD *)(StatusReg + 80) = v16;
    }
    u32_array = *(_DWORD *)(v11 + 4LL * a4);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s index=%d\n", a2, u32_array);
LABEL_14:
    v10 = v11;
  }
LABEL_15:
  kfree(v10);
  return u32_array;
}
