__int64 __fastcall regmap_bus_read(__int64 a1, unsigned __int16 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v7; // x23
  int v9; // w22
  int v10; // w0
  __int64 v11; // x24
  char v12; // w26
  int v13; // w25
  __int16 v14; // w8
  __int64 v15; // x0
  int v16; // w0
  int v17; // w21
  unsigned int v18; // w20
  __int64 result; // x0
  int v20; // w23
  __int16 v22[2]; // [xsp+10h] [xbp-30h] BYREF
  char v23; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v24; // [xsp+18h] [xbp-28h] BYREF
  char *v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  if ( !v5 )
  {
    dev_err(a1, "%s: ctxt is NULL\n", "regmap_bus_read");
LABEL_19:
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( !a2 || (v7 = a4) == 0 )
  {
    dev_err(a1, "%s: reg or val is NULL\n", "regmap_bus_read");
    goto LABEL_19;
  }
  if ( a3 != 2 )
  {
    dev_err(a1, "%s: register size %zd bytes, not supported\n", "regmap_bus_read", a3);
    result = 4294967274LL;
    goto LABEL_16;
  }
  mutex_lock(v5 + 320);
  v9 = *a2;
  v22[0] = v9;
  v10 = wcd_usbss_page_write(v5, v22);
  if ( v10 )
    goto LABEL_15;
  v11 = *(_QWORD *)(v5 + 16);
  if ( !v11 )
  {
    v10 = -19;
LABEL_22:
    v20 = v10;
    dev_err(a1, "%s: Codec read failed (%d), reg: 0x%x, size:%zd\n", "regmap_bus_read", v10, v9, a5);
    v10 = v20;
    goto LABEL_15;
  }
  if ( (int)a5 >= 1 )
  {
    v12 = v22[0];
    v13 = 0;
    v25 = nullptr;
    v26 = 0;
    v24 = 0;
    while ( 1 )
    {
      v14 = *(_WORD *)(v11 + 2);
      v27 = v7;
      v15 = *(_QWORD *)(v11 + 24);
      v23 = v12;
      *(_DWORD *)((char *)&v24 + 2) = 0x10000;
      LOWORD(v24) = v14;
      v25 = &v23;
      LOWORD(v26) = v14;
      *(_DWORD *)((char *)&v26 + 2) = 65537;
      if ( (unsigned int)i2c_transfer(v15, &v24, 2) != 2 )
      {
        v16 = i2c_transfer(*(_QWORD *)(v11 + 24), &v24, 2);
        if ( v16 != 2 )
          break;
      }
      ++v13;
      ++v7;
      ++v12;
      if ( (unsigned int)a5 <= (unsigned __int8)v13 )
        goto LABEL_14;
    }
    v17 = v16;
    printk(&unk_BA8A);
    v10 = v17;
    if ( (v17 & 0x80000000) == 0 )
      goto LABEL_15;
    goto LABEL_22;
  }
LABEL_14:
  v10 = 0;
LABEL_15:
  v18 = v10;
  mutex_unlock(v5 + 320);
  result = v18;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
