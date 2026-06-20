__int64 __fastcall hdd_set_dynamic_bw_param(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x25
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  if ( (unsigned int)ucfg_get_dynamic_bw_switch_value(a2, v8) )
  {
    result = 16;
    goto LABEL_18;
  }
  if ( !a1 )
  {
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v4 = a1 + 52840, a1 != -52840)
    || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v4 = a1 + 58928, a1 != -58928)
    || (result = 0, (*(_QWORD *)(a1 + 1640) & 4) != 0) && (v4 = a1 + 65016, a1 != -65016) )
  {
    do
    {
      sme_set_smps_cfg(*(unsigned __int8 *)(v4 + 8), 6, v8[0]);
      if ( (unsigned __int8)(73 * ((unsigned int)(v4 - *(_DWORD *)v4 - 52840) >> 3) + 1) > 2u )
        break;
      v5 = (unsigned __int8)(73 * ((unsigned int)(v4 - *(_DWORD *)v4 - 52840) >> 3) + 1);
      v4 = 0;
      v6 = a1 + 52840 + 6088LL * (unsigned int)v5;
      do
      {
        if ( v4 )
          break;
        v7 = *(_QWORD *)(a1 + 1640) >> v5++;
        v4 = (v7 << 63 >> 63) & v6;
        v6 += 6088;
      }
      while ( v5 != 3 );
    }
    while ( v4 );
    goto LABEL_17;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
