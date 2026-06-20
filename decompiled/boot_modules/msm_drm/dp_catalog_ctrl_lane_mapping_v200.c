__int64 __fastcall dp_catalog_ctrl_lane_mapping_v200(__int64 a1, char a2, unsigned __int8 *a3)
{
  __int64 v3; // x9
  __int64 v5; // x1
  int v6; // w10
  _BYTE *v7; // x8
  _BYTE *v8; // x8
  _BYTE *v9; // x11
  _BYTE *v10; // x12
  _BYTE *v11; // x8
  __int64 ipc_log_context; // x0
  int v14; // w8
  _BYTE *v15; // x11
  _BYTE *v16; // x11
  int v17; // w11
  _BYTE *v18; // x12
  _BYTE *v19; // x12
  _BYTE *v20; // x8
  _BYTE *v21; // x8
  __int64 v22; // x0
  char v23; // w12
  _DWORD *v24; // x8
  _BYTE v25[4]; // [xsp+8h] [xbp-8h] BYREF
  _BYTE v26[4]; // [xsp+Ch] [xbp-4h] BYREF
  _BYTE v27[4]; // [xsp+28h] [xbp+18h] BYREF
  _BYTE v28[4]; // [xsp+2Ch] [xbp+1Ch] BYREF

  v28[0] = 0;
  v27[0] = 0;
  v26[0] = 0;
  v25[0] = 0;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_lane_mapping_v200");
  }
  v3 = *(_QWORD *)(a1 + 1104);
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 16) + 16LL);
  v6 = *a3;
  if ( (a2 & 1) != 0 )
  {
    if ( v6 == 1 )
    {
      if ( a3[1] == 2 )
      {
        v11 = v27;
      }
      else if ( a3[2] == 2 )
      {
        v11 = v26;
      }
      else
      {
        if ( a3[3] != 2 )
          goto LABEL_21;
        v11 = v25;
      }
      v28[0] = 2;
      *v11 = 1;
    }
    else
    {
      if ( *a3 )
        goto LABEL_21;
      if ( a3[1] == 3 )
      {
        v7 = v27;
      }
      else if ( a3[2] == 3 )
      {
        v7 = v26;
      }
      else
      {
        if ( a3[3] != 3 )
          goto LABEL_21;
        v7 = v25;
      }
      *v7 = 0;
      v28[0] = 3;
    }
LABEL_21:
    v14 = a3[1];
    if ( a3[1] )
    {
      if ( v14 != 1 )
        goto LABEL_37;
      if ( v6 == 2 )
      {
        v15 = v28;
      }
      else if ( a3[2] == 2 )
      {
        v15 = v26;
      }
      else
      {
        if ( a3[3] != 2 )
          goto LABEL_37;
        v15 = v25;
      }
      v27[0] = 2;
      *v15 = 1;
    }
    else
    {
      if ( v6 == 3 )
      {
        v16 = v28;
      }
      else if ( a3[2] == 3 )
      {
        v16 = v26;
      }
      else
      {
        if ( a3[3] != 3 )
          goto LABEL_37;
        v16 = v25;
      }
      *v16 = 0;
      v27[0] = 3;
    }
LABEL_37:
    v17 = a3[2];
    if ( a3[2] )
    {
      if ( v17 != 1 )
        goto LABEL_53;
      if ( v6 == 2 )
      {
        v18 = v28;
      }
      else if ( v14 == 2 )
      {
        v18 = v27;
      }
      else
      {
        if ( a3[3] != 2 )
          goto LABEL_53;
        v18 = v25;
      }
      v26[0] = 2;
      *v18 = 1;
    }
    else
    {
      if ( v6 == 3 )
      {
        v19 = v28;
      }
      else if ( v14 == 3 )
      {
        v19 = v27;
      }
      else
      {
        if ( a3[3] != 3 )
          goto LABEL_53;
        v19 = v25;
      }
      *v19 = 0;
      v26[0] = 3;
    }
LABEL_53:
    if ( !a3[3] )
    {
      if ( v6 == 3 )
      {
        v21 = v28;
      }
      else if ( v14 == 3 )
      {
        v21 = v27;
      }
      else
      {
        if ( v17 != 3 )
          goto LABEL_69;
        v21 = v26;
      }
      *v21 = 0;
      v25[0] = 3;
      goto LABEL_69;
    }
    if ( a3[3] == 1 )
    {
      if ( v6 == 2 )
      {
        v20 = v28;
LABEL_65:
        v25[0] = 2;
        *v20 = 1;
        goto LABEL_69;
      }
      if ( v14 == 2 )
      {
        v20 = v27;
        goto LABEL_65;
      }
      if ( v17 == 2 )
      {
        v20 = v26;
        goto LABEL_65;
      }
    }
LABEL_69:
    LOBYTE(v6) = v28[0];
    v10 = v25;
    v9 = v26;
    v8 = v27;
    goto LABEL_70;
  }
  v8 = a3 + 1;
  v9 = a3 + 2;
  v10 = a3 + 3;
LABEL_70:
  v22 = *(_QWORD *)(v3 - 8);
  v23 = (*v10 << 6) | (16 * (*v9 & 3)) | (4 * (*v8 & 3));
  v24 = *(_DWORD **)(v3 + 8);
  if ( *(v24 - 1) != 621108289 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v24)(v22, v5, 56, v23 & 0xFC | v6 & 3u);
}
