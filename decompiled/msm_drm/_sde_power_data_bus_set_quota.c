__int64 __fastcall sde_power_data_bus_set_quota(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x24
  unsigned __int64 v4; // x21
  __int64 v7; // x28
  unsigned __int64 v8; // x25
  unsigned __int64 v9; // x26
  __int64 v10; // x0
  unsigned int v11; // w0
  unsigned int v12; // w23
  __int64 v14; // x0

  v3 = *(unsigned int *)(a1 + 32);
  if ( (unsigned int)(v3 - 3) <= 0xFFFFFFFD )
  {
    printk(&unk_24D73E, "_sde_power_data_bus_set_quota");
    return (unsigned int)-22;
  }
  else
  {
    v4 = a2 / v3;
    _ReadStatusReg(SP_EL0);
    v7 = 0;
    v8 = a2 / v3 / 0x3E8;
    v9 = a3 / 0x3E8;
    while ( 1 )
    {
      v10 = *(_QWORD *)(a1 + 8 * v7);
      if ( v10 )
      {
        v11 = icc_set_bw(v10, (unsigned int)v8, (unsigned int)v9);
        if ( v11 )
          break;
      }
      if ( v3 == ++v7 )
      {
        *(_QWORD *)(a1 + 16) = v4;
        *(_QWORD *)(a1 + 24) = a3;
        return 0;
      }
    }
    v12 = v11;
    do
    {
      v14 = *(_QWORD *)(a1 + 8 * v7);
      if ( v14 )
        icc_set_bw(v14, *(_QWORD *)(a1 + 16) / 0x3E8uLL, *(_QWORD *)(a1 + 24) / 0x3E8uLL);
    }
    while ( v7-- > 0 );
    printk(&unk_2251CD, "_sde_power_data_bus_set_quota");
  }
  return v12;
}
