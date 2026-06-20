__int64 __fastcall sde_hw_intf_avr_ctrl(__int64 result, __int64 a2)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x2
  __int64 v5; // x20
  unsigned int v6; // w19

  if ( result && a2 )
  {
    v2 = *(_DWORD *)(a2 + 8);
    if ( v2 )
    {
      v3 = *(_DWORD *)(a2 + 12);
      if ( v2 == 2 )
        v2 = 257;
      else
        v2 = 0;
      v4 = 1;
      if ( v3 )
        v2 |= v3 << 16;
    }
    else
    {
      v4 = 0;
    }
    v5 = result;
    if ( *(_BYTE *)(a2 + 16) )
      v2 |= 0x200u;
    if ( *(_BYTE *)(a2 + 17) )
      v6 = v2 | 0x400;
    else
      v6 = v2;
    sde_reg_write(result, 624, v4, "INTF_AVR_CONTROL");
    return sde_reg_write(v5, 628, v6, "INTF_AVR_MODE");
  }
  return result;
}
