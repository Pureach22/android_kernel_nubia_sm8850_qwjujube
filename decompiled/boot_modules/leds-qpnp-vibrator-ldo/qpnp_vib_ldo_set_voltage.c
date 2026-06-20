__int64 __fastcall qpnp_vib_ldo_set_voltage(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // x0
  unsigned __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x3
  __int64 v9; // x2
  __int64 v10; // x3
  unsigned int v11; // w19
  unsigned int v12; // w19
  __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 612) == a2 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 448);
    v6 = 2199023256000LL * ((a2 + 7999) / 8000);
    v7 = *(unsigned __int16 *)(a1 + 600);
    v13 = (v6 >> 38) + (v6 >> 63);
    result = regmap_bulk_write(v4, (unsigned int)(v7 + 64), &v13, 2);
    if ( (result & 0x80000000) != 0 )
    {
      v11 = result;
      printk(&unk_722C, "qpnp_vib_ldo_set_voltage", (unsigned int)result, v8);
      result = v11;
    }
    else if ( *(_BYTE *)(a1 + 632) == 1 && (result = qpnp_vib_ldo_poll_status(a1), (result & 0x80000000) != 0) )
    {
      v12 = result;
      printk(&unk_7111, "qpnp_vib_ldo_set_voltage", v9, v10);
      result = v12;
    }
    else
    {
      *(_DWORD *)(a1 + 612) = a2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
