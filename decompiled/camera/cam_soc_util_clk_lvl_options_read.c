__int64 __fastcall cam_soc_util_clk_lvl_options_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  size_t v4; // x24
  __int64 v5; // x20
  __int64 v6; // x27
  __int64 v7; // x20
  __int64 v8; // x8
  const char *v9; // x25
  size_t v10; // x0
  size_t v11; // x26
  size_t v12; // x0
  size_t v13; // x2
  size_t v14; // x0
  unsigned __int64 v15; // x19
  size_t v16; // x0
  size_t v17; // x4
  size_t v19; // x2
  __int64 v20; // x0

  v5 = *(_QWORD *)(a1 + 32);
  scnprintf(supported_clk_info, 256, "Supported levels: ");
  v6 = 0;
  v7 = v5 + 2860;
  while ( 1 )
  {
    if ( *(_BYTE *)(v7 + v6) == 1 )
    {
      if ( (unsigned int)(v6 - 1) > 8 )
      {
        v4 = 1;
        v9 = (const char *)&unk_3E455A;
      }
      else
      {
        v8 = (unsigned int)(v6 - 1);
        v4 = *(_QWORD *)((char *)&unk_4497F0 + v8 * 8);
        v9 = off_449838[v8];
      }
      v10 = strnlen(supported_clk_info, 0x100u);
      v11 = v10;
      if ( v10 >= 0x101 )
      {
        v19 = v10 + 1;
        goto LABEL_38;
      }
      v12 = strnlen(v9, v4);
      if ( v12 > v4 )
        goto LABEL_39;
      if ( v12 >= v4 )
        goto LABEL_40;
      if ( v11 != 256 )
      {
        if ( v12 + v11 >= 0x100 )
          v13 = 255 - v11;
        else
          v13 = v12;
        if ( v12 + v11 >= 0x100 )
          v4 = 255;
        else
          v4 = v12 + v11;
        memcpy(&supported_clk_info[v11], v9, v13);
        supported_clk_info[v4] = 0;
      }
      v14 = strnlen(supported_clk_info, 0x100u);
      if ( v14 >= 0x101 )
      {
LABEL_36:
        v19 = v14 + 1;
        goto LABEL_38;
      }
      if ( v14 != 256 )
        break;
    }
LABEL_3:
    if ( ++v6 == 10 )
      goto LABEL_26;
  }
  if ( v14 == 255 )
    v4 = 255;
  else
    v4 = v14 + 1;
  memcpy(&supported_clk_info[v14], " ", v14 != 255);
  if ( v4 <= 0xFF )
  {
    supported_clk_info[v4] = 0;
    goto LABEL_3;
  }
  do
  {
    __break(1u);
LABEL_26:
    v14 = strnlen(supported_clk_info, 0x100u);
    if ( v14 >= 0x101 )
      goto LABEL_36;
    if ( v14 == 256 )
      goto LABEL_33;
    if ( v14 == 255 )
      v15 = 255;
    else
      v15 = v14 + 1;
    memcpy(&supported_clk_info[v14], "\n", v14 != 255);
  }
  while ( v15 > 0xFF );
  supported_clk_info[v15] = 0;
LABEL_33:
  v16 = strnlen(supported_clk_info, 0x100u);
  v17 = v16;
  if ( v16 >= 0x101 )
  {
    while ( 1 )
    {
      v19 = v17 + 1;
LABEL_38:
      v12 = _fortify_panic(2, 256, v19);
LABEL_39:
      v12 = _fortify_panic(2, v4, v12 + 1);
LABEL_40:
      _fortify_panic(4, v4, v12 + 1);
    }
  }
  if ( v16 != 256 )
    return simple_read_from_buffer(a2, a3, a4, supported_clk_info, v16);
  v20 = _fortify_panic(4, 256, 257);
  return cam_soc_util_clk_lvl_options_open(v20);
}
