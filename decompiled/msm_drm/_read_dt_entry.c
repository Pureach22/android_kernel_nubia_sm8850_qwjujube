__int64 __fastcall read_dt_entry(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x28
  __int64 v9; // x20
  __int64 v10; // x27
  _DWORD *v11; // x25
  __int64 v12; // x24
  __int64 v13; // x19
  int v14; // w4
  int variable_u32_array; // w21
  __int64 v16; // x26
  __int64 v17; // x21
  int v18; // w23
  int v19; // w0
  int v20; // w9
  int v21; // w21
  const char *v22; // x21
  int v23; // w26
  __int64 property; // x0
  signed int v25; // w9
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned int *v28; // x11
  _DWORD *v29; // x13
  _BOOL4 v30; // w7
  int v31; // w23
  char v32; // w8
  int v33; // w9
  unsigned __int64 v34; // x21
  int v35; // w9
  int v36; // w9
  unsigned __int64 v37; // x26
  _DWORD *v38; // x19
  __int64 result; // x0
  unsigned int v40; // w19
  const char *v41; // [xsp+8h] [xbp-38h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  int v46; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
LABEL_62:
    result = 0;
    goto LABEL_63;
  }
  v6 = a6;
  v9 = 0;
  v10 = a6 + 256;
  v11 = (_DWORD *)(a6 + 260);
  v12 = a6;
  v44 = a3;
  while ( 1 )
  {
    v13 = a2 + 24 * v9;
    *(_BYTE *)(a5 + v9) = 1;
    v14 = *(_DWORD *)(v13 + 20);
    if ( v14 <= 1 )
    {
      if ( !v14 )
      {
        v30 = of_find_property(a1, *(_QWORD *)(v13 + 8), 0) != 0;
        *(_DWORD *)(v6 + 768 * v9) = v30;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "prop id:%d prop name:%s prop type:%d value:0x%x\n",
            v9,
            *(const char **)(v13 + 8),
            *(_DWORD *)(v13 + 20),
            v30);
        goto LABEL_5;
      }
      if ( v14 == 1 )
      {
        variable_u32_array = of_property_read_variable_u32_array(a1, *(_QWORD *)(v13 + 8), v6 + 768 * v9, 1, 0);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "prop id:%d prop name:%s prop type:%d value:0x%x\n",
            v9,
            *(const char **)(v13 + 8),
            *(_DWORD *)(v13 + 20),
            *(_DWORD *)(v6 + 768 * v9));
        if ( variable_u32_array < 0 )
          *(_BYTE *)(a5 + v9) = 0;
        goto LABEL_5;
      }
LABEL_30:
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "invalid property type:%d\n", v14);
      goto LABEL_5;
    }
    if ( v14 == 2 )
    {
      v16 = *(int *)(a4 + 4 * v9);
      if ( (int)v16 >= 65 )
      {
        printk(&unk_257BEE, "_parse_dt_u32_handler");
        v20 = -7;
      }
      else
      {
        v17 = a5;
        v18 = *(_DWORD *)(v13 + 16);
        v41 = *(const char **)(v13 + 8);
        v19 = of_property_read_variable_u32_array(a1, v41, a6 + 768 * v9, v16, 0);
        v20 = v19 & (v19 >> 31);
        if ( v18 && v19 < 0 )
        {
          v31 = v19 & (v19 >> 31);
          printk(&unk_224DED, "_parse_dt_u32_handler");
          v20 = v31;
          a5 = v17;
        }
        else
        {
          a5 = v17;
          if ( (v19 & 0x80000000) == 0 )
          {
LABEL_39:
            v32 = _drm_debug;
            if ( (_drm_debug & 4) != 0 )
            {
              _drm_dev_dbg(
                0,
                0,
                0,
                "prop id:%d prop name:%s prop type:%d",
                v9,
                *(const char **)(v13 + 8),
                *(_DWORD *)(v13 + 20));
              v32 = _drm_debug;
            }
            v33 = *(_DWORD *)(a4 + 4 * v9);
            v6 = a6;
            if ( v33 >= 1 )
            {
              v34 = 0;
              while ( 1 )
              {
                if ( (v32 & 4) != 0 )
                {
                  if ( v34 > 0x3F )
                    goto LABEL_67;
                  _drm_dev_dbg(0, 0, 0, " value[%d]:0x%x ", v34, *(_DWORD *)(v12 + 4 * v34));
                  v33 = *(_DWORD *)(a4 + 4 * v9);
                  v32 = _drm_debug;
                }
                if ( (__int64)++v34 >= v33 )
                  goto LABEL_60;
              }
            }
            goto LABEL_60;
          }
          if ( (_drm_debug & 4) != 0 )
          {
            v21 = v19 & (v19 >> 31);
            _drm_dev_dbg(0, 0, 0, "optional prop: %s u32 array read len:%d\n", v41, v16);
            v20 = v21;
          }
        }
      }
      if ( *(_DWORD *)(v13 + 16) )
      {
        v40 = v20;
        goto LABEL_65;
      }
      *(_BYTE *)(a5 + v9) = 0;
      goto LABEL_39;
    }
    if ( v14 == 5 )
      break;
    if ( v14 != 6 )
      goto LABEL_30;
LABEL_5:
    ++v9;
    v10 += 768;
    v11 += 192;
    v12 += 768;
    if ( v9 == v44 )
      goto LABEL_62;
  }
  v22 = *(const char **)(v13 + 8);
  v23 = *(_DWORD *)(v13 + 16);
  v46 = 0;
  property = of_get_property(a1, v22, &v46);
  if ( property )
  {
    v25 = (v46 >> 2) & 0xFFFFFFFE;
    v46 = v25;
    if ( v25 <= 128 )
    {
      v6 = a6;
      if ( v25 >= 1 )
      {
        v26 = 0;
        v27 = ((4LL * (unsigned int)(v25 - 2) + 4) & 0x7FFFFFFF8LL) + 8;
        while ( v26 != 512 )
        {
          v28 = (unsigned int *)(property + 4 + v26);
          v29 = (_DWORD *)(v10 + v26);
          v26 += 8;
          *v29 = bswap32(*(v28 - 1));
          v29[1] = bswap32(*v28);
          if ( v27 == v26 )
            goto LABEL_52;
        }
LABEL_67:
        __break(0x5512u);
      }
LABEL_52:
      v32 = _drm_debug;
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(
          0,
          0,
          0,
          "prop id:%d prop name:%s prop type:%d",
          v9,
          *(const char **)(v13 + 8),
          *(_DWORD *)(v13 + 20));
        v32 = _drm_debug;
      }
      v36 = *(_DWORD *)(a4 + 4 * v9);
      if ( v36 >= 1 )
      {
        v37 = 0;
        v38 = v11;
        do
        {
          if ( (v32 & 4) != 0 )
          {
            if ( v37 > 0x3F )
              goto LABEL_67;
            _drm_dev_dbg(0, 0, 0, "count[%d]: bit:0x%x off:0x%x\n", v37, *(v38 - 1), *v38);
            v36 = *(_DWORD *)(a4 + 4 * v9);
            v32 = _drm_debug;
          }
          ++v37;
          v38 += 2;
        }
        while ( (__int64)v37 < v36 );
      }
LABEL_60:
      if ( (v32 & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "\n");
      goto LABEL_5;
    }
    printk(&unk_22EFA0, "_parse_dt_bit_offset");
    v35 = -7;
    if ( *(_DWORD *)(v13 + 16) )
      goto LABEL_66;
LABEL_51:
    v6 = a6;
    *(_BYTE *)(a5 + v9) = 0;
    goto LABEL_52;
  }
  if ( !v23 )
  {
    v6 = a6;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "error optional property '%s' not found\n", v22);
    goto LABEL_52;
  }
  printk(&unk_2168A7, "_parse_dt_bit_offset");
  v35 = -22;
  if ( !*(_DWORD *)(v13 + 16) )
    goto LABEL_51;
LABEL_66:
  v40 = v35;
LABEL_65:
  printk(&unk_270C06, "_read_dt_entry");
  *(_BYTE *)(a5 + v9) = 0;
  result = v40;
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
