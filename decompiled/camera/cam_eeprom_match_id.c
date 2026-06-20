__int64 __fastcall cam_eeprom_match_id(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int16 v4; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  result = cam_spi_query_id(a1 + 3664, 0, 2, &v4, 2);
  if ( !(_DWORD)result )
  {
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_match_id",
        258,
        "read 0x%x 0x%x, check 0x%x 0x%x",
        (unsigned __int8)v4,
        HIBYTE(v4),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 3688) + 45LL),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 3688) + 43LL));
    v3 = *(_QWORD *)(a1 + 3688);
    result = 4294967277LL;
    if ( (unsigned __int8)v4 == *(unsigned __int8 *)(v3 + 45) )
    {
      if ( HIBYTE(v4) == *(unsigned __int8 *)(v3 + 43) )
        result = 0;
      else
        result = 4294967277LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
