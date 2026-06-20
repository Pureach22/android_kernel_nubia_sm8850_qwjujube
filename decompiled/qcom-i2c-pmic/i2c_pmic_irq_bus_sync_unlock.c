__int64 __fastcall i2c_pmic_irq_bus_sync_unlock(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x2
  _QWORD *v3; // x21
  int v4; // w0
  __int64 v5; // x2
  int v6; // w0
  __int64 v7; // x2
  int v8; // w0
  int v9; // w22
  int v10; // w23
  unsigned int v11; // w19
  unsigned int v12; // w0
  unsigned int v13; // w19
  unsigned int v14; // w0

  v1 = *(_QWORD *)(a1 + 48);
  v2 = *(unsigned __int8 *)(v1 + 10);
  v3 = *(_QWORD **)v1;
  if ( (_DWORD)v2 != *(unsigned __int8 *)(v1 + 15) )
  {
    v4 = regmap_write(v3[1], *(unsigned __int16 *)(v1 + 8) | 0x11u, v2);
    if ( v4 < 0 )
    {
      dev_err(
        *v3,
        "Couldn't set periph 0x%04x irqs 0x%02x type rc=%d\n",
        *(unsigned __int16 *)(v1 + 8),
        *(unsigned __int8 *)(v1 + 10),
        v4);
      goto LABEL_10;
    }
    *(_BYTE *)(v1 + 15) = *(_BYTE *)(v1 + 10);
  }
  v5 = *(unsigned __int8 *)(v1 + 11);
  if ( (_DWORD)v5 != *(unsigned __int8 *)(v1 + 16) )
  {
    v6 = regmap_write(v3[1], *(unsigned __int16 *)(v1 + 8) | 0x12u, v5);
    if ( v6 < 0 )
    {
      dev_err(
        *v3,
        "Couldn't set periph 0x%04x irqs 0x%02x polarity high rc=%d\n",
        *(unsigned __int16 *)(v1 + 8),
        *(unsigned __int8 *)(v1 + 11),
        v6);
      goto LABEL_10;
    }
    *(_BYTE *)(v1 + 16) = *(_BYTE *)(v1 + 11);
  }
  v7 = *(unsigned __int8 *)(v1 + 12);
  if ( (_DWORD)v7 != *(unsigned __int8 *)(v1 + 17) )
  {
    v8 = regmap_write(v3[1], *(unsigned __int16 *)(v1 + 8) | 0x13u, v7);
    if ( v8 < 0 )
      dev_err(
        *v3,
        "Couldn't set periph 0x%04x irqs 0x%02x polarity low rc=%d\n",
        *(unsigned __int16 *)(v1 + 8),
        *(unsigned __int8 *)(v1 + 12),
        v8);
    else
      *(_BYTE *)(v1 + 17) = *(_BYTE *)(v1 + 12);
  }
LABEL_10:
  v9 = *(unsigned __int8 *)(v1 + 14);
  v10 = *(unsigned __int8 *)(v1 + 19);
  v11 = v10 & (v9 ^ 0xFF);
  if ( v11 && (v12 = regmap_write(v3[1], *(unsigned __int16 *)(v1 + 8) | 0x16u, v11), (v12 & 0x80000000) != 0) )
  {
    dev_err(*v3, "Couldn't disable periph 0x%04x irqs 0x%02x rc=%d\n", *(unsigned __int16 *)(v1 + 8), v11, v12);
  }
  else
  {
    v13 = v9 & (v10 ^ 0xFF);
    if ( v13 && (v14 = regmap_write(v3[1], *(unsigned __int16 *)(v1 + 8) | 0x15u, v13), (v14 & 0x80000000) != 0) )
      dev_err(*v3, "Couldn't enable periph 0x%04x irqs 0x%02x rc=%d\n", *(unsigned __int16 *)(v1 + 8), v13, v14);
    else
      *(_BYTE *)(v1 + 19) = *(_BYTE *)(v1 + 14);
  }
  return mutex_unlock(v1 + 24);
}
