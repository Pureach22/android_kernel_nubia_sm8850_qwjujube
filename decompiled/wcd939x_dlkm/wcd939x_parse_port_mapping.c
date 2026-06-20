__int64 __fastcall wcd939x_parse_port_mapping(__int64 a1, const char *a2, char a3)
{
  __int64 v3; // x19
  const char *v4; // x23
  unsigned __int64 v5; // x21
  __int64 v6; // x28
  __int64 v7; // x0
  __int64 v8; // x27
  unsigned int v9; // w24
  unsigned __int64 v10; // x22
  __int64 v11; // x20
  int variable_u32_array; // w0
  unsigned int v13; // w8
  unsigned int v14; // w9
  int v15; // w0
  _DWORD *v16; // x26
  int v17; // w25
  int v18; // w9
  int v19; // w0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v22; // x26
  __int64 v23; // [xsp+0h] [xbp-30h]
  int v24; // [xsp+Ch] [xbp-24h]
  __int64 v25; // [xsp+10h] [xbp-20h]
  __int64 v26; // [xsp+18h] [xbp-18h]
  unsigned int v27; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v3 = a1;
  v4 = a2;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 1 )
    v5 = 1668;
  else
    v5 = 388;
  v6 = *(_QWORD *)(a1 + 152);
  v7 = *(_QWORD *)(a1 + 744);
  v27 = 0;
  if ( a3 == 1 )
    v8 = 385;
  else
    v8 = 384;
  if ( of_find_property(v7, a2, &v27) )
  {
    v9 = v27;
    v10 = v27;
    v11 = _kmalloc_noprof(v27, 3520);
    if ( v11 )
    {
      while ( 1 )
      {
        variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v3 + 744), v4, v11, 5 * (v9 / 0x14), 0);
        if ( variable_u32_array < 0 )
          break;
        if ( v9 < 0x14 )
        {
          LOBYTE(v9) = 0;
LABEL_29:
          *(_BYTE *)(v6 + v8) = v9;
          kfree(v11);
          result = 0;
          goto LABEL_36;
        }
        v25 = v8;
        v26 = v6;
        v4 = nullptr;
        v8 = 20LL * (v9 / 0x14);
        v13 = 0;
        v14 = 0;
        v6 += v5;
        v5 = v10;
        v24 = variable_u32_array;
        v23 = v3;
        while ( v10 >= (unsigned __int64)v4 && v5 >= 4 )
        {
          v9 = *(_DWORD *)&v4[v11];
          if ( (v9 | v13) >= 8 )
          {
            dev_err(v23, "%s: Invalid port or channel number\n", "wcd939x_parse_port_mapping");
            goto LABEL_33;
          }
          if ( v10 < (unsigned __int64)(v4 + 4)
            || v5 - 4 < 4
            || v10 < (unsigned __int64)(v4 + 8)
            || v5 - 8 < 4
            || v10 < (unsigned __int64)(v4 + 12)
            || v5 - 12 < 4
            || v10 < (unsigned __int64)(v4 + 16)
            || v5 - 16 < 4 )
          {
            break;
          }
          if ( v9 == v14 )
            v3 = v13;
          else
            v3 = 0;
          v15 = *(_DWORD *)&v4[v11 + 8];
          v16 = (_DWORD *)(v6 + 160LL * v9 + 20LL * (unsigned int)v3);
          v17 = *(_DWORD *)&v4[v11 + 12];
          v18 = *(_DWORD *)&v4[v11 + 4];
          v16[1] = *(_DWORD *)&v4[v11 + 16];
          v16[2] = v15;
          *v16 = v18;
          v19 = _sw_hweight8();
          v4 += 20;
          v13 = v3 + 1;
          v5 -= 20LL;
          v14 = v9;
          v16[3] = v19;
          v16[4] = v17;
          if ( (const char *)v8 == v4 )
          {
            v8 = v25;
            v6 = v26;
            goto LABEL_29;
          }
        }
        __break(1u);
        v10 = v27;
        StatusReg = _ReadStatusReg(SP_EL0);
        v22 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v11 = _kmalloc_noprof(v10, 3520);
        *(_QWORD *)(StatusReg + 80) = v22;
        if ( !v11 )
          goto LABEL_35;
      }
      v24 = variable_u32_array;
      dev_err(v3, "%s: Failed to read  port mapping from prop %s\n", "wcd939x_parse_port_mapping", v4);
LABEL_33:
      kfree(v11);
      result = v24 & (unsigned int)(v24 >> 31);
    }
    else
    {
LABEL_35:
      result = 4294967284LL;
    }
  }
  else
  {
    dev_err(v3, "missing port mapping prop %s\n", v4);
    result = 4294967274LL;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
