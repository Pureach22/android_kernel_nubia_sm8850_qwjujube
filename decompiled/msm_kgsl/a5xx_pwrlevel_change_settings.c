__int64 __fastcall a5xx_pwrlevel_change_settings(__int64 result, __int64 a2, int a3, char a4)
{
  _QWORD *v4; // x19
  int v5; // w8
  int v6; // w21
  int v7; // w8
  int v8; // w21

  v4 = (_QWORD *)result;
  if ( **(_DWORD **)(result + 14264) == 540 || *(_BYTE *)(result + 20432) == 1 )
  {
    if ( (a4 & 1) != 0 )
    {
      kgsl_regmap_write(result + 13200, a3 | 0x80000000);
      v5 = -100;
      do
      {
        v6 = v5;
        result = kgsl_regmap_read(v4 + 1650);
        if ( (result & 0x80000000) == 0 )
          break;
        v5 = v6 + 1;
      }
      while ( v6 );
      if ( (result & 0x80000000) != 0 )
        return dev_err(*v4, "GPMU post powerlevel did not stabilize\n");
    }
    else
    {
      kgsl_regmap_write(result + 13200, a3 | 0x80000010);
      v7 = -100;
      do
      {
        v8 = v7;
        result = kgsl_regmap_read(v4 + 1650);
        if ( (result & 0x80000000) == 0 )
          break;
        v7 = v8 + 1;
      }
      while ( v8 );
      if ( (result & 0x80000000) != 0 )
        return dev_err(*v4, "GPMU pre powerlevel did not stabilize\n");
    }
  }
  return result;
}
