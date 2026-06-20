__int64 __fastcall validate_dt_entry(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4, unsigned int *a5)
{
  unsigned int v10; // w0
  unsigned int v11; // w24
  __int64 v12; // x22
  _DWORD *v13; // x25
  int v14; // w4
  int string_helper; // w0
  unsigned int v16; // w8
  int v17; // w5
  unsigned int v18; // w0
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( !a5 || (v10 = of_property_count_elems_of_size(a1, *(_QWORD *)(a2 + 8), 4), *a5 = v10, v10 < 0xD) )
  {
    if ( !a3 )
    {
      v11 = 0;
      goto LABEL_61;
    }
    v12 = 0;
    v11 = 0;
    v13 = (_DWORD *)(a2 + 16);
    while ( 1 )
    {
      v14 = v13[1];
      if ( v14 > 3 )
      {
        if ( v14 == 4 )
        {
          string_helper = of_property_read_string_helper(a1, *((_QWORD *)v13 - 1), 0, 0, 0);
LABEL_23:
          a4[v12] = string_helper;
          if ( string_helper < 0 )
            v11 = string_helper;
          if ( (_drm_debug & 4) != 0 )
            goto LABEL_26;
          goto LABEL_30;
        }
        if ( v14 == 5 )
        {
          if ( of_get_property(a1, *((_QWORD *)v13 - 1), &v20) )
          {
            a4[v12] = v20 >> 3;
            if ( (_drm_debug & 4) != 0 )
              goto LABEL_26;
          }
          else
          {
            a4[v12] = 0;
            if ( (_drm_debug & 4) != 0 )
              goto LABEL_26;
          }
          goto LABEL_30;
        }
        if ( v14 != 6 )
        {
LABEL_29:
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "invalid property type:%d\n", v14);
            if ( (_drm_debug & 4) != 0 )
              goto LABEL_26;
          }
          goto LABEL_30;
        }
        if ( !of_get_child_by_name(a1, *((_QWORD *)v13 - 1)) )
          v11 = -22;
        if ( (_drm_debug & 4) != 0 )
        {
LABEL_26:
          _drm_dev_dbg(
            0,
            0,
            0,
            "prop id:%d prop name:%s prop type:%d prop_count:%d\n",
            v12,
            *((const char **)v13 - 1),
            v13[1],
            a4[v12]);
          if ( v11 )
            goto LABEL_31;
          goto LABEL_27;
        }
      }
      else
      {
        if ( !v14 )
          goto LABEL_48;
        if ( v14 != 1 )
        {
          if ( v14 != 2 )
            goto LABEL_29;
          string_helper = of_property_count_elems_of_size(a1, *((_QWORD *)v13 - 1), 4);
          goto LABEL_23;
        }
        v18 = of_property_read_variable_u32_array(a1, *((_QWORD *)v13 - 1), &v20, 1, 0);
        if ( (v18 & 0x80000000) == 0 )
        {
          v11 = 0;
LABEL_48:
          a4[v12] = 1;
          if ( (_drm_debug & 4) != 0 )
            goto LABEL_26;
          goto LABEL_30;
        }
        v11 = v18;
        if ( (_drm_debug & 4) != 0 )
          goto LABEL_26;
      }
LABEL_30:
      if ( v11 )
      {
LABEL_31:
        v16 = v13[1];
        if ( *v13 && (v16 == 6 || v16 == 1) )
        {
          printk(&unk_2324FA, "_validate_dt_entry");
          goto LABEL_61;
        }
        if ( v16 > 6 )
          goto LABEL_36;
        goto LABEL_35;
      }
LABEL_27:
      v16 = v13[1];
      if ( v16 > 6 )
        goto LABEL_36;
LABEL_35:
      if ( ((1 << v16) & 0x43) != 0 )
        goto LABEL_8;
LABEL_36:
      if ( a5 )
      {
        v17 = a4[v12];
        if ( v17 != *a5 )
        {
          if ( *v13 )
          {
            printk(&unk_25F612, "_validate_dt_entry");
            v11 = -22;
            goto LABEL_61;
          }
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "prop:%s count:%d is different compared to offset array:%d\n",
              *((const char **)v13 - 1),
              v17,
              *a5);
          v11 = 0;
        }
      }
      if ( (a4[v12] & 0x80000000) != 0 )
      {
        a4[v12] = 0;
        if ( *v13 )
        {
          printk(&unk_274667, "_validate_dt_entry");
          v11 = -22;
          goto LABEL_9;
        }
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "prop:%s count:%d is negative\n", *((const char **)v13 - 1), 0);
LABEL_8:
        v11 = 0;
      }
LABEL_9:
      ++v12;
      v13 += 6;
      if ( a3 == v12 )
        goto LABEL_61;
    }
  }
  if ( *(_DWORD *)(a2 + 16) )
  {
    printk(&unk_24D348, "_validate_dt_entry");
    v11 = -22;
  }
  else
  {
    v11 = 0;
  }
  *a5 = 0;
  memset(a4, 0, 4LL * a3);
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return v11;
}
