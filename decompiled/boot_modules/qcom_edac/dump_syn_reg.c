__int64 __fastcall dump_syn_reg(__int64 a1, int a2, unsigned int a3)
{
  char **v3; // x8
  _QWORD *v5; // x28
  int v7; // w20
  unsigned int *v8; // x9
  unsigned int *v9; // x10
  unsigned int *v10; // x11
  int v11; // w12
  int v12; // w13
  char v13; // w23
  char v14; // w8
  unsigned int v15; // w24
  unsigned int v16; // w26
  int v17; // w25
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 result; // x0
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x0
  const char *v24; // x4
  const char *v25; // x4
  char v26; // [xsp+0h] [xbp-30h]
  int v27; // [xsp+4h] [xbp-2Ch]
  int v28; // [xsp+8h] [xbp-28h]
  unsigned int v29; // [xsp+Ch] [xbp-24h]
  int v31; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+20h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)a2 > 3 )
    __break(1u);
  v3 = &(&edac_reg_data)[3 * (unsigned int)a2];
  v5 = *(_QWORD **)(*(_QWORD *)(a1 + 192) + 144LL);
  v7 = *((_DWORD *)v3 + 2);
  v8 = (unsigned int *)v5[4];
  if ( a2 > 1 )
  {
    v9 = v8 + 2;
    v10 = v8 + 1;
    if ( a2 != 2 )
      v9 = v8 + 3;
  }
  else
  {
    if ( a2 )
      v9 = v8 + 19;
    else
      v9 = v8 + 18;
    v10 = v8 + 17;
    v8 += 16;
  }
  v12 = *((_DWORD *)v3 + 3);
  v11 = *((_DWORD *)v3 + 4);
  v13 = *((_BYTE *)v3 + 20);
  v14 = *((_BYTE *)v3 + 21);
  v32[0] = 0;
  v31 = 0;
  v15 = *v10;
  v26 = v14;
  v27 = v11;
  v28 = v12;
  v29 = *v8;
  if ( v7 )
  {
    v16 = *v9;
    v17 = 0;
    while ( !(unsigned int)regmap_read(*(_QWORD *)(*v5 + 8LL * a3), v16, &v31) )
    {
      printk(&unk_6922);
      ++v17;
      v16 += 4;
      if ( v7 == v17 )
        goto LABEL_14;
    }
  }
  else
  {
LABEL_14:
    if ( !(unsigned int)regmap_read(*(_QWORD *)(*v5 + 8LL * a3), v15, (char *)v32 + 4) )
    {
      HIDWORD(v32[0]) = (HIDWORD(v32[0]) & v28) >> v13;
      printk(&unk_68F8);
      if ( !(unsigned int)regmap_read(*(_QWORD *)(*v5 + 8LL * a3), v29, v32) )
      {
        LODWORD(v32[0]) = (v32[0] & v27) >> v26;
        printk(&unk_6A3A);
      }
    }
  }
  v18 = v5[1];
  v19 = v5[4];
  if ( (unsigned int)a2 > 1 )
  {
    result = regmap_write(v18, *(unsigned int *)(v19 + 24), 3);
    if ( (_DWORD)result )
      goto LABEL_31;
    v21 = v5[1];
    v22 = *(unsigned int *)(v5[4] + 16LL);
  }
  else
  {
    result = regmap_write(v18, *(unsigned int *)(v19 + 56), 3);
    if ( (_DWORD)result )
      goto LABEL_31;
    v21 = v5[1];
    v22 = *(unsigned int *)(v5[4] + 48LL);
  }
  result = regmap_write(v21, v22, 3);
  if ( !(_DWORD)result )
  {
    if ( a2 > 1 )
    {
      v23 = a1;
      if ( a2 == 2 )
      {
        v24 = "LLCC Tag RAM correctable Error";
        goto LABEL_26;
      }
      v25 = "LLCC Tag RAM uncorrectable Error";
    }
    else
    {
      v23 = a1;
      if ( !a2 )
      {
        v24 = "LLCC Data RAM correctable Error";
LABEL_26:
        edac_device_handle_ce_count(v23, 1, 0, a3, v24);
LABEL_30:
        result = 0;
        goto LABEL_31;
      }
      v25 = "LLCC Data RAM uncorrectable Error";
    }
    edac_device_handle_ue_count(v23, 1, 0, a3, v25);
    goto LABEL_30;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
