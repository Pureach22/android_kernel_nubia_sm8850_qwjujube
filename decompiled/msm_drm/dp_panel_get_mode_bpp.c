__int64 __fastcall dp_panel_get_mode_bpp(__int64 a1, unsigned int a2, int a3, char a4)
{
  int v6; // w8
  unsigned int v7; // w19
  unsigned int v8; // w8
  __int64 v10; // x9
  __int64 v11; // x24
  unsigned int v12; // w22
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x10
  char v16; // w12
  signed __int64 v17; // x8
  __int64 v18; // x8
  char v19; // w9
  int v20; // w9
  unsigned __int64 v21; // x8
  unsigned int v22; // w12
  __int64 v23; // x0
  __int64 ipc_log_context; // x0
  __int64 v26; // x0

  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_get_mode_bpp");
    return 0;
  }
  if ( *(_BYTE *)(a1 + 872) == 1 )
  {
    v6 = *(_DWORD *)(*(_QWORD *)(a1 + 1200) + 20LL);
    switch ( v6 )
    {
      case 0:
        return 18;
      case 64:
        return 30;
      case 32:
        return 24;
    }
    return 0;
  }
  v8 = *(_DWORD *)(a1 + 908);
  if ( *(_BYTE *)(a1 + 971) == 1 )
  {
    v10 = *(_QWORD *)(a1 + 1224);
    if ( v10 )
      v8 = *(_DWORD *)(v10 + 908);
  }
  v11 = *(_QWORD *)(a1 + 1200);
  if ( (a4 & 1) != 0 )
    v12 = 24;
  else
    v12 = 18;
  if ( v8 >= a2 )
    v7 = a2;
  else
    v7 = v8;
  v13 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(v11 + 132));
  v14 = (unsigned __int64)(unsigned int)(v13 * *(_DWORD *)(v11 + 128)) << 35;
  if ( *(_BYTE *)(a1 + 968) == 1 )
  {
    v15 = 62;
    do
    {
      if ( ((v14 >> v15) & 1) != v14 >> 63 )
        break;
      --v15;
    }
    while ( v15 );
    v16 = v15 - 30;
    v17 = v14 << (62 - (unsigned __int8)v15);
    if ( (unsigned int)(62 - v15) >= 0x20 )
      v16 = 0;
    v18 = v17 / (*(__int64 *)(a1 + 1000) >> v16);
    v19 = 30 - v15;
    if ( (unsigned int)(62 - v15) <= 0x20 )
      v19 = 0;
    v14 = v18 >> v19;
  }
  if ( v7 > v12 )
  {
    v20 = a3 * v7;
    v21 = HIDWORD(v14);
    while ( 1 )
    {
      v22 = v20;
      if ( (a4 & 1) == 0 )
        break;
      if ( v7 == 24 )
      {
        v22 = 8 * a3;
        if ( (*(_BYTE *)(a1 + 964) & 2) != 0 )
          break;
      }
      else
      {
        v22 = 8 * a3;
        if ( v7 != 30 )
          break;
        v22 = 8 * a3;
        if ( (*(_BYTE *)(a1 + 964) & 4) != 0 )
          break;
      }
LABEL_30:
      v7 -= 6;
      v20 -= 6 * a3;
      if ( v7 <= v12 )
        goto LABEL_38;
    }
    if ( v22 <= (unsigned int)v21 )
      goto LABEL_38;
    goto LABEL_30;
  }
LABEL_38:
  if ( v7 < v12 )
  {
    v26 = get_ipc_log_context(v13);
    ipc_log_string(
      v26,
      "[w][%-4d]bpp %d is below minimum supported bpp %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v7,
      v12);
    v13 = printk(&unk_218648, "dp_panel_get_supported_bpp");
    if ( (a4 & 1) == 0 )
      return v7;
  }
  else if ( (a4 & 1) == 0 )
  {
    return v7;
  }
  if ( v7 > 0x24 || ((1LL << v7) & 0x1041000000LL) == 0 )
  {
    v23 = get_ipc_log_context(v13);
    ipc_log_string(
      v23,
      "[w][%-4d]bpp %d is not supported when dsc is enabled\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v7);
    printk(&unk_229B1F, "dp_panel_get_supported_bpp");
  }
  return v7;
}
