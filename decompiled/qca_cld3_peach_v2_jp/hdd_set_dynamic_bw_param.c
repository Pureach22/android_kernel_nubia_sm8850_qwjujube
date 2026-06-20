__int64 __fastcall hdd_set_dynamic_bw_param(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x23
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  if ( (unsigned int)ucfg_get_dynamic_bw_switch_value(a2, v5) )
  {
    result = 16;
    goto LABEL_9;
  }
  if ( !a1 )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  result = 0;
  if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
  {
    v4 = a1 + 52832;
    if ( a1 != -52832 )
    {
      do
      {
        sme_set_smps_cfg(*(unsigned __int8 *)(v4 + 8), 6, v5[0]);
        if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v4 - *(_DWORD *)v4 - 52832) >> 4)) )
          break;
        v4 = a1 + 52832;
      }
      while ( (*(_QWORD *)(a1 + 1640) & 1) != 0 );
      goto LABEL_8;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
