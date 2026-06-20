__int64 __fastcall llcc_notif_staling_inc_counter(_DWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  unsigned int v4; // w19
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int64)drv_data < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(unsigned __int8 *)(drv_data + 119) >= 5u )
    {
      result = 4294967274LL;
      if ( a1 )
      {
        if ( (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL )
        {
          v3 = *(_QWORD *)(drv_data + 8);
          v4 = (*a1 << 12) | 0xC;
          v5 = 0;
          result = regmap_update_bits_base(v3, v4, 1, 1, 0, 0, 0);
          if ( !(_DWORD)result )
            result = regmap_read(*(_QWORD *)(drv_data + 8), v4, &v5);
        }
      }
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = (unsigned int)drv_data;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
