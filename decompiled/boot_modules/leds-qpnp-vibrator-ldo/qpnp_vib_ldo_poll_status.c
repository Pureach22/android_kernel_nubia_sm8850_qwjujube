__int64 __fastcall qpnp_vib_ldo_poll_status(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  unsigned int v4; // w8
  __int64 v5; // x20
  unsigned int v6; // w20
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v2 = ktime_get();
  LODWORD(result) = regmap_read(*(_QWORD *)(a1 + 448), (unsigned int)*(unsigned __int16 *)(a1 + 600) + 8, &v7);
  if ( !(_DWORD)result )
  {
    v5 = v2 + 1000000;
    while ( 1 )
    {
      if ( (v7 & 0x80) != 0 )
      {
        LODWORD(result) = 0;
        goto LABEL_2;
      }
      if ( ktime_get() > v5 )
        break;
      usleep_range_state(26, 100, 2);
      __yield();
      LODWORD(result) = regmap_read(*(_QWORD *)(a1 + 448), (unsigned int)*(unsigned __int16 *)(a1 + 600) + 8, &v7);
      if ( (_DWORD)result )
        goto LABEL_2;
    }
    LODWORD(result) = regmap_read(*(_QWORD *)(a1 + 448), (unsigned int)*(unsigned __int16 *)(a1 + 600) + 8, &v7);
  }
LABEL_2:
  if ( (unsigned int)result | v7 & 0x80 )
    v4 = 0;
  else
    v4 = -110;
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = v4;
  if ( (result & 0x80000000) != 0 )
  {
    v6 = result;
    printk(&unk_6F74, "qpnp_vib_ldo_poll_status", v7, (unsigned int)result);
    regmap_update_bits_base(*(_QWORD *)(a1 + 448), (unsigned int)*(unsigned __int16 *)(a1 + 600) + 70, 128, 0, 0, 0, 0);
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
