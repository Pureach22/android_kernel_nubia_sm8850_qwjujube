__int64 __fastcall regmap_bus_read(__int64 a1, unsigned __int16 *a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  __int64 v6; // x20
  unsigned int v9; // w8
  unsigned int v11; // w8
  __int64 result; // x0
  __int64 v14; // x24
  int v15; // w25
  int v16; // w27
  unsigned __int64 v17; // x26
  int v18; // w28
  _DWORD *v19; // x9
  __int64 v20; // x2
  int v21; // w0
  int v22; // w23
  unsigned int v23; // w19
  _BYTE v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v24[0] = 0;
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(&regmap_bus_read__rs, "regmap_bus_read") )
    {
      dev_err(a1, "%s: priv is NULL\n", "regmap_bus_read");
LABEL_11:
      result = 4294967274LL;
      goto LABEL_14;
    }
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( !a2 || !a4 )
  {
    if ( (unsigned int)__ratelimit(&regmap_bus_read__rs_9, "regmap_bus_read") )
    {
      dev_err(a1, "%s: reg or val is NULL\n", "regmap_bus_read");
      goto LABEL_11;
    }
    goto LABEL_13;
  }
  if ( a3 != 2 )
  {
    if ( (unsigned int)__ratelimit(&regmap_bus_read__rs_10, "regmap_bus_read") )
    {
      dev_err(a1, "%s: register size %zd bytes, not supported\n", "regmap_bus_read", a3);
      result = 4294967274LL;
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  v9 = *a2;
  if ( v9 >= 0xBBD )
  {
    if ( v9 - 4096 >= 0xF8D )
    {
      if ( v9 - 0x2000 >= 0xBE5 )
      {
        if ( v9 - 0x4000 >= 0xBE5 )
        {
          if ( v9 - 12288 > 0x5A8 )
          {
LABEL_31:
            result = 0;
            goto LABEL_14;
          }
          v11 = 3;
        }
        else
        {
          v11 = 4;
        }
      }
      else
      {
        v11 = 2;
      }
    }
    else
    {
      v11 = 1;
    }
  }
  else
  {
    v11 = 0;
  }
  v14 = v11;
  if ( *(_BYTE *)(v6 + v11 + 217) != 1 )
    goto LABEL_31;
  mutex_lock(v6 + 72);
  if ( a5 )
  {
    v15 = 0;
    v16 = macro_id_base_offset[v14];
    v17 = 0;
    v18 = 1;
    while ( 1 )
    {
      v19 = *(_DWORD **)(v6 + 904);
      v20 = (unsigned int)*a2 + v15 - v16;
      if ( *(v19 - 1) != -868256214 )
        __break(0x8229u);
      v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _BYTE *))v19)(v6, (unsigned int)v14, v20, v24);
      if ( v21 < 0 )
        break;
      v15 += 4;
      *(_BYTE *)(a4 + v17) = v24[0];
      v17 = v18++;
      if ( v17 >= a5 )
        goto LABEL_36;
    }
    v22 = v21;
    if ( (unsigned int)__ratelimit(&regmap_bus_read__rs_11, "regmap_bus_read") )
      dev_err(a1, "%s: Codec read failed (%d), reg: 0x%x, size:%zd\n", "regmap_bus_read", v22, *a2 + v15, a5);
    v21 = v22;
  }
  else
  {
    v21 = -22;
  }
LABEL_36:
  v23 = v21;
  mutex_unlock(v6 + 72);
  result = v23;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
