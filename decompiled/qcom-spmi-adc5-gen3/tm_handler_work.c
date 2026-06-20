__int64 __fastcall tm_handler_work(__int64 result)
{
  int v1; // w8
  __int64 v2; // x20
  int v3; // w23
  __int64 v4; // x19
  int v5; // w21
  unsigned int v6; // w22
  unsigned int v7; // w0
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x28
  int v12; // w22
  unsigned int v13; // w26
  unsigned int v14; // w0
  unsigned int v15; // w0
  __int64 v16; // x9
  unsigned int v17; // w0
  __int64 v18; // x9
  unsigned int v19; // w0
  unsigned int v20; // w0
  _BOOL4 v21; // w26
  _BOOL4 v22; // w24
  unsigned int v23; // w20
  __int64 v24; // x2
  void *v25; // x0
  int v26; // [xsp+Ch] [xbp-24h] BYREF
  _BYTE v27[4]; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int8 v28[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v29[3]; // [xsp+18h] [xbp-18h] BYREF

  v29[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result - 136);
  *(_WORD *)v28 = 0;
  v29[0] = 0;
  v29[1] = 0;
  if ( !v1 )
    goto LABEL_33;
  v2 = result;
  v3 = 0;
  v4 = result - 80;
  v5 = -1;
  v27[0] = 0;
  while ( 1 )
  {
    v10 = *(_QWORD *)(v2 - 128);
    v26 = 0;
    v11 = v10 + 200LL * v3;
    if ( (*(_DWORD *)(v11 + 72) | 2) == 3 )
      break;
LABEL_5:
    if ( (unsigned int)++v3 >= *(_DWORD *)(v2 - 136) )
      goto LABEL_33;
  }
  v12 = *(_DWORD *)(v11 + 76);
  mutex_lock(v4);
  v13 = *(_DWORD *)(v11 + 28);
  if ( v13 == v5 )
    goto LABEL_13;
  v14 = regmap_bulk_read(
          *(_QWORD *)(v2 - 176),
          (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v2 - 152) + 24LL * v13) + 72,
          v28,
          2);
  if ( (v14 & 0x80000000) != 0 )
  {
    v23 = v14;
    printk(&unk_9458, 72, 2);
    v25 = &unk_997D;
    goto LABEL_32;
  }
  v15 = regmap_bulk_write(
          *(_QWORD *)(v2 - 176),
          (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v2 - 152) + 24LL * v13) + 76,
          v28,
          2);
  if ( (v15 & 0x80000000) != 0 )
  {
    v23 = v15;
    printk(&unk_95F2, 76, 2);
    v25 = &unk_94B0;
    goto LABEL_32;
  }
  v16 = *(_QWORD *)(v2 - 152);
  v27[0] = 0;
  v17 = regmap_bulk_write(*(_QWORD *)(v2 - 176), (unsigned int)*(unsigned __int16 *)(v16 + 24LL * v13) + 80, v27, 1);
  if ( (v17 & 0x80000000) != 0 )
  {
    v23 = v17;
    printk(&unk_95F2, 80, 1);
    v25 = &unk_9323;
    goto LABEL_32;
  }
  v18 = *(_QWORD *)(v2 - 152);
  v27[0] = 1;
  v19 = regmap_bulk_write(*(_QWORD *)(v2 - 176), (unsigned int)*(unsigned __int16 *)(v18 + 24LL * v13) + 229, v27, 1);
  if ( (v19 & 0x80000000) != 0 )
  {
    v23 = v19;
    printk(&unk_95F2, 229, 1);
    v25 = &unk_98A7;
    goto LABEL_32;
  }
  v20 = regmap_bulk_read(
          *(_QWORD *)(v2 - 176),
          (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v2 - 152) + 24LL * v13) + 92,
          v29,
          16);
  v5 = v13;
  if ( (v20 & 0x80000000) == 0 )
  {
LABEL_13:
    v21 = ((1LL << v12) & v28[0]) != 0 && *(_DWORD *)(v11 + 96) != 0;
    v22 = ((1LL << v12) & v28[1]) != 0 && *(_DWORD *)(v11 + 100) != 0;
    result = mutex_unlock(v4);
    if ( v21 || v22 )
    {
      if ( (unsigned int)(2 * v12) > 0xF )
        __break(0x5512u);
      if ( *(_DWORD *)(v11 + 72) == 3 )
      {
        if ( v22 )
        {
          mutex_lock(v4);
          *(_DWORD *)(v11 + 100) = 0;
          *(_BYTE *)(v11 + 105) = 1;
          mutex_unlock(v4);
          result = queue_work_on(32, *(_QWORD *)(v11 + 136), v11 + 144);
        }
        if ( v21 )
        {
          mutex_lock(v4);
          *(_DWORD *)(v11 + 96) = 0;
          *(_BYTE *)(v11 + 104) = 1;
          mutex_unlock(v4);
          result = queue_work_on(32, *(_QWORD *)(v11 + 136), v11 + 144);
        }
      }
      else
      {
        v6 = *((unsigned __int8 *)v29 + (unsigned int)(2 * v12))
           | (*((unsigned __int8 *)v29 + (unsigned int)(2 * v12) + 1) << 8);
        v7 = qcom_adc5_hw_scale(
               *(unsigned int *)(v11 + 40),
               *(unsigned int *)(v11 + 16),
               *(_QWORD *)(v11 + 64),
               v6,
               &v26);
        if ( (v7 & 0x80000000) != 0 )
        {
          result = printk(&unk_99EB, v7, v6);
        }
        else
        {
          v8 = v26;
          v9 = *(_QWORD *)(v11 + 88);
          *(_BYTE *)(v11 + 132) = 1;
          *(_DWORD *)(v11 + 128) = v8;
          result = thermal_zone_device_update(v9, 2);
        }
      }
    }
    goto LABEL_5;
  }
  v23 = v20;
  printk(&unk_9458, 92, 16);
  v25 = &unk_9AAE;
LABEL_32:
  printk(v25, v23, v24);
  result = mutex_unlock(v4);
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
