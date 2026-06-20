__int64 __fastcall llcc_update_act_ctrl(int a1, int a2, int a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w20
  __int64 v6; // x0
  unsigned int v10; // w20
  __int64 v11; // x21
  __int64 v12; // x22
  __int64 v13; // x22
  unsigned int v14; // w0
  int v15; // w8
  __int64 v16; // x22
  __int64 v17; // x22
  unsigned int v18; // w0
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = drv_data;
  if ( (unsigned __int64)drv_data >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_4;
  v4 = a1 << 12;
  v6 = *(_QWORD *)(drv_data + 8);
  v19 = 0;
  v3 = regmap_write(v6, v4, a2 | 1u);
  if ( v3 )
    goto LABEL_4;
  v3 = regmap_write(*(_QWORD *)(drv_data + 8), v4, a2 & 0xFFFFFFFE);
  if ( v3 )
    goto LABEL_4;
  v10 = (a1 << 12) | 4;
  if ( *(unsigned __int16 *)(drv_data + 118) >= 0x401u )
  {
    v11 = *(_QWORD *)(drv_data + 16);
    if ( !v11 )
      v11 = *(_QWORD *)(drv_data + 8);
    v12 = ktime_get();
    v3 = regmap_read(v11, v10, &v19);
    if ( v3 )
      goto LABEL_4;
    v13 = v12 + 100000;
    while ( 1 )
    {
      if ( (v19 & 0x10) != 0 )
      {
        v14 = 0;
        v15 = 1;
        goto LABEL_16;
      }
      if ( ktime_get() > v13 )
        break;
      __yield();
      v3 = regmap_read(v11, v10, &v19);
      if ( v3 )
        goto LABEL_4;
    }
    v14 = regmap_read(v11, v10, &v19);
    v15 = ((unsigned __int8)v19 >> 4) & 1;
LABEL_16:
    if ( v14 || (v15 & 1) == 0 )
    {
      if ( v14 )
        v15 = 1;
      if ( v15 )
        v3 = 0;
      else
        v3 = -110;
      if ( v14 )
        v3 = v14;
      goto LABEL_4;
    }
  }
  v16 = ktime_get();
  v3 = regmap_read(*(_QWORD *)(drv_data + 8), v10, &v19);
  if ( !v3 )
  {
    v17 = v16 + 100000;
    while ( 1 )
    {
      if ( (v19 & a3) == 0 )
        goto LABEL_30;
      if ( ktime_get() > v17 )
        break;
      __yield();
      v3 = regmap_read(*(_QWORD *)(drv_data + 8), v10, &v19);
      if ( v3 )
        goto LABEL_4;
    }
    v18 = regmap_read(*(_QWORD *)(drv_data + 8), v10, &v19);
    if ( (v19 & a3) != 0 )
      v3 = -110;
    else
      v3 = 0;
    if ( v18 )
      v3 = v18;
    if ( !(v18 | v19 & a3) )
    {
LABEL_30:
      if ( *(_DWORD *)(drv_data + 116) <= 0x400FFFFu )
        v3 = 0;
      else
        v3 = regmap_write(*(_QWORD *)(drv_data + 8), (a1 << 12) | 8u, 1);
    }
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v3;
}
