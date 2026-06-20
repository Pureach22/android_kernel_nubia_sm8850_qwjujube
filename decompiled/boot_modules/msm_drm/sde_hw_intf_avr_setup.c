__int64 __fastcall sde_hw_intf_avr_setup(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w10
  unsigned int v5; // w8

  if ( a1 && a2 && a3 )
  {
    v3 = a3[1];
    v4 = a2[6] + a2[9] + a2[1] + a2[7];
    if ( *a3 == v3 )
      v5 = 0;
    else
      v5 = v4 % v3 * (*a3 - v3) / v3 + v4 / v3 * (*a3 - v3);
    sde_reg_write(a1, 636, (v5 + v4) * (a2[4] + a2[8] + *a2 + a2[5]), "INTF_AVR_VTOTAL");
    return 0;
  }
  else
  {
    printk(&unk_266511, "sde_hw_intf_avr_setup");
    return 4294967274LL;
  }
}
