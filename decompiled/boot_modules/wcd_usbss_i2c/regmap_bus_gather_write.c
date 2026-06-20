__int64 __fastcall regmap_bus_gather_write(__int64 a1, unsigned __int16 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  int v10; // w24
  unsigned int v11; // w21
  unsigned __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  if ( v5 && a2 && a4 && a3 == 2 )
  {
    mutex_lock(v5 + 320);
    v10 = *a2;
    v13 = *a2;
    v11 = wcd_usbss_page_write(v5, &v13);
    if ( !v11 )
    {
      v11 = wcd_usbss_i2c_write_device(v5, v13, a4, (unsigned int)a5);
      if ( (v11 & 0x80000000) != 0 )
        dev_err(a1, "%s: Codec write failed (%d), reg:0x%x, size:%zd\n", "regmap_bus_gather_write", v11, v10, a5);
    }
    mutex_unlock(v5 + 320);
  }
  else
  {
    ((void (*)(void))dev_err)();
    v11 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
