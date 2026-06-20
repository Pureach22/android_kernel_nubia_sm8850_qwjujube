__int64 __fastcall regmap_bus_gather_write(
        __int64 a1,
        unsigned __int16 *a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5)
{
  __int64 v5; // x20
  unsigned int v9; // w8
  unsigned int v11; // w8
  __int64 v14; // x24
  int v15; // w25
  int v16; // w26
  unsigned __int64 v17; // x8
  int v18; // w27
  _DWORD *v19; // x10
  __int64 v20; // x3
  __int64 v21; // x2
  int v22; // w0
  int v23; // w23
  unsigned int v24; // w19

  v5 = *(_QWORD *)(a1 + 152);
  if ( !v5 )
  {
    if ( !(unsigned int)__ratelimit(&regmap_bus_gather_write__rs, "regmap_bus_gather_write") )
      return 4294967274LL;
    dev_err(a1, "%s: priv is NULL\n", "regmap_bus_gather_write");
    return 4294967274LL;
  }
  if ( !a2 || !a4 )
  {
    if ( !(unsigned int)__ratelimit(&regmap_bus_gather_write__rs_3, "regmap_bus_gather_write") )
      return 4294967274LL;
    dev_err(a1, "%s: reg or val is NULL\n", "regmap_bus_gather_write");
    return 4294967274LL;
  }
  if ( a3 != 2 )
  {
    if ( (unsigned int)__ratelimit(&regmap_bus_gather_write__rs_5, "regmap_bus_gather_write") )
    {
      dev_err(a1, "%s: register size %zd bytes, not supported\n", "regmap_bus_gather_write", a3);
      return 4294967274LL;
    }
    return 4294967274LL;
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
            return 0;
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
  if ( *(_BYTE *)(v5 + v11 + 217) != 1 )
    return 0;
  mutex_lock(v5 + 72);
  if ( a5 )
  {
    v15 = 0;
    v16 = macro_id_base_offset[v14];
    v17 = 0;
    v18 = 1;
    while ( 1 )
    {
      v19 = *(_DWORD **)(v5 + 912);
      v20 = *(unsigned __int8 *)(a4 + v17);
      v21 = (unsigned int)*a2 + v15 - v16;
      if ( *(v19 - 1) != -2037647885 )
        __break(0x822Au);
      v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v19)(v5, (unsigned int)v14, v21, v20);
      if ( v22 < 0 )
        break;
      v17 = v18++;
      v15 += 4;
      if ( v17 >= a5 )
        goto LABEL_35;
    }
    v23 = v22;
    if ( (unsigned int)__ratelimit(&regmap_bus_gather_write__rs_7, "regmap_bus_gather_write") )
      dev_err(a1, "%s: Codec write failed (%d), reg:0x%x, size:%zd\n", "regmap_bus_gather_write", v23, *a2 + v15, a5);
    v22 = v23;
  }
  else
  {
    v22 = -22;
  }
LABEL_35:
  v24 = v22;
  mutex_unlock(v5 + 72);
  return v24;
}
