unsigned int *__fastcall apply_zdet_correction(unsigned int *result, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // w8
  __int64 v6; // x10
  unsigned __int64 v7; // x11
  int v8; // w9
  int v9; // w12
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x12
  unsigned __int8 *v14; // x10

  v4 = *result;
  if ( a2 )
    a3 = a4;
  v6 = 0;
  v7 = (((v4 * (unsigned __int64)a3) << 16) * (unsigned __int128)0x346DC5D63886594BuLL) >> 64;
  if ( a2 )
    v8 = -20000;
  else
    v8 = -10000;
  v9 = 1;
  v10 = v4 + v8;
  v11 = v7 >> 27;
  while ( 1000 * (unsigned int)zdet_dnl_table[v6 + 6] <= (unsigned int)v10 )
  {
    v6 += 6;
    ++v9;
    if ( v6 == 174 )
      goto LABEL_14;
  }
  if ( v9 <= 0 )
    return (unsigned int *)printk(&unk_18F74, "interpolate_zdet_val");
  if ( (unsigned int)(v9 - 1) >= 0x1D )
  {
    if ( (_DWORD)v6 == 174 )
    {
LABEL_14:
      v12 = 51;
      if ( !a2 )
        v12 = -55;
      if ( v11 > v12 )
        goto LABEL_17;
      return result;
    }
    __break(0x5512u);
LABEL_26:
    __break(1u);
    return (unsigned int *)update_xtalk_scale_and_alpha(result);
  }
  v13 = 4;
  if ( !a2 )
    v13 = 2;
  if ( v13 + v6 == 174 )
    goto LABEL_26;
  v14 = &zdet_dnl_table[v6];
  v12 = ((1000LL * v14[6] - v10) * *(__int16 *)&v14[v13] + (v10 - 1000LL * *v14) * *(__int16 *)&v14[v13 + 6])
      / (1000LL
       * (v14[6] - *v14));
  if ( v11 > v12 )
LABEL_17:
    *result = v11 - v12;
  return result;
}
