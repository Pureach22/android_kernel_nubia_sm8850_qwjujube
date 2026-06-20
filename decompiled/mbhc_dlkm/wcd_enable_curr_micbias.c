_QWORD *__fastcall wcd_enable_curr_micbias(_QWORD *result, int a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x8
  __int64 v4; // x1
  __int64 v5; // x1
  __int64 v6; // x1
  char v7; // w9
  int v8; // w10
  __int64 v9; // x8
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x0
  __int64 v17; // x8
  unsigned int v18; // w3
  __int64 v19; // x9
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1
  __int64 v23; // x8
  __int64 (__fastcall *v24)(__int64, __int64, __int64); // x8

  if ( *(_QWORD *)(result[15] + 208LL) )
    return result;
  v2 = result;
  if ( a2 <= 1 )
  {
    if ( !a2 )
    {
      v13 = result[107];
      v14 = *(unsigned int *)(v13 + 392);
      if ( (_DWORD)v14 )
      {
        snd_soc_component_update_bits(result[27], v14, *(unsigned __int8 *)(v13 + 396), 0);
        v13 = v2[107];
      }
      v15 = *(unsigned int *)(v13 + 360);
      if ( (_DWORD)v15 )
        snd_soc_component_update_bits(
          v2[27],
          v15,
          *(unsigned __int8 *)(v13 + 364),
          (unsigned int)(3 << *(_BYTE *)(v13 + 365)));
      v16 = v2[27];
      v17 = *(_QWORD *)(v2[14] + 8LL);
      if ( v17 )
      {
        v18 = *(unsigned __int8 *)(v17 + 65);
        v19 = v2[15];
        v20 = v17 + 80;
LABEL_34:
        v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v19 + 192);
        if ( *((_DWORD *)v24 - 1) != -226424819 )
          __break(0x8228u);
        return (_QWORD *)v24(v16, v20, v20 + 2LL * v18);
      }
      return (_QWORD *)dev_err(
                         *(_QWORD *)(*(_QWORD *)(v16 + 32) + 72LL),
                         "%s: calibration data is NULL\n",
                         "wcd_program_btn_threshold");
    }
    if ( a2 != 1 )
      return result;
    v3 = result[107];
    v4 = *(unsigned int *)(v3 + 360);
    if ( (_DWORD)v4 )
    {
      snd_soc_component_update_bits(result[27], v4, *(unsigned __int8 *)(v3 + 364), 0);
      v3 = v2[107];
    }
    v5 = *(unsigned int *)(v3 + 184);
    if ( (_DWORD)v5 )
    {
      snd_soc_component_update_bits(
        v2[27],
        v5,
        *(unsigned __int8 *)(v3 + 188),
        (unsigned int)(1 << *(_BYTE *)(v3 + 189)));
      v3 = v2[107];
    }
    v6 = *(unsigned int *)(v3 + 392);
    if ( (_DWORD)v6 )
    {
      v7 = *(_BYTE *)(v3 + 397);
      v8 = 2;
LABEL_31:
      snd_soc_component_update_bits(v2[27], v6, *(unsigned __int8 *)(v3 + 396), (unsigned int)(v8 << v7));
      goto LABEL_32;
    }
    goto LABEL_32;
  }
  if ( a2 == 2 )
  {
    v3 = result[107];
    v21 = *(unsigned int *)(v3 + 360);
    if ( (_DWORD)v21 )
    {
      snd_soc_component_update_bits(
        result[27],
        v21,
        *(unsigned __int8 *)(v3 + 364),
        (unsigned int)(3 << *(_BYTE *)(v3 + 365)));
      v3 = v2[107];
    }
    v22 = *(unsigned int *)(v3 + 184);
    if ( (_DWORD)v22 )
    {
      snd_soc_component_update_bits(
        v2[27],
        v22,
        *(unsigned __int8 *)(v3 + 188),
        (unsigned int)(1 << *(_BYTE *)(v3 + 189)));
      v3 = v2[107];
    }
    v6 = *(unsigned int *)(v3 + 392);
    if ( (_DWORD)v6 )
    {
      v7 = *(_BYTE *)(v3 + 397);
      v8 = 1;
      goto LABEL_31;
    }
LABEL_32:
    v16 = v2[27];
    v23 = *(_QWORD *)(v2[14] + 8LL);
    if ( v23 )
    {
      v18 = *(unsigned __int8 *)(v23 + 65);
      v19 = v2[15];
      v20 = v23 + 80;
      goto LABEL_34;
    }
    return (_QWORD *)dev_err(
                       *(_QWORD *)(*(_QWORD *)(v16 + 32) + 72LL),
                       "%s: calibration data is NULL\n",
                       "wcd_program_btn_threshold");
  }
  if ( a2 == 3 )
  {
    v9 = result[107];
    v10 = *(unsigned int *)(v9 + 360);
    if ( (_DWORD)v10 )
    {
      result = (_QWORD *)snd_soc_component_update_bits(result[27], v10, *(unsigned __int8 *)(v9 + 364), 0);
      v9 = v2[107];
    }
    v11 = *(unsigned int *)(v9 + 184);
    if ( (_DWORD)v11 )
    {
      result = (_QWORD *)snd_soc_component_update_bits(
                           v2[27],
                           v11,
                           *(unsigned __int8 *)(v9 + 188),
                           (unsigned int)(1 << *(_BYTE *)(v9 + 189)));
      v9 = v2[107];
    }
    v12 = *(unsigned int *)(v9 + 392);
    if ( (_DWORD)v12 )
      return (_QWORD *)snd_soc_component_update_bits(v2[27], v12, *(unsigned __int8 *)(v9 + 396), 0);
  }
  return result;
}
