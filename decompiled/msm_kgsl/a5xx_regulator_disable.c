__int64 __fastcall a5xx_regulator_disable(__int64 result)
{
  int v1; // w8
  _QWORD *v2; // x19
  int v3; // w8
  int v4; // w21
  __int64 v5; // x0
  int v6; // w8
  int v7; // w21
  unsigned __int64 v14; // x8

  v1 = **(_DWORD **)(result + 14264);
  if ( v1 != 508 && v1 != 512 )
  {
    v2 = (_QWORD *)result;
    _X9 = (unsigned __int64 *)(result + 14240);
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr(_X9);
    while ( __stlxr(v14 & 0xFFFFFFFFFFFFFEFFLL, _X9) );
    __dmb(0xBu);
    if ( (v14 & 0x100) != 0 )
    {
      if ( (*(_BYTE *)(result + 20436) & 1) != 0 )
      {
        if ( (*(_QWORD *)(result + 14240) & 0x800) != 0 )
        {
          if ( (kgsl_regmap_read(result + 13200) & 0x100000) != 0 )
            dev_warn(*v2, "SPTP GDSC is not disabled\n");
          if ( (kgsl_regmap_read(v2 + 1650) & 0x100000) != 0 )
            dev_warn(*v2, "RBCCU GDSC is not disabled\n");
          result = kgsl_regmap_read(v2 + 1650);
          if ( (result & 0x4000) != 0 )
            result = dev_warn(*v2, "GMEM is forced on\n");
        }
      }
      else
      {
        kgsl_regmap_write(result + 13200, 7831553);
        _const_udelay(12885);
        v3 = -100;
        do
        {
          v4 = v3;
          _const_udelay(4295);
          v5 = kgsl_regmap_read(v2 + 1650);
          if ( (v5 & 0x100000) == 0 )
            break;
          v3 = v4 + 1;
        }
        while ( v4 );
        if ( (v5 & 0x100000) != 0 )
          dev_warn(*v2, "SPTP GDSC disable failed\n");
        kgsl_regmap_write(v2 + 1650, 7831553);
        v6 = -100;
        do
        {
          v7 = v6;
          _const_udelay(4295);
          result = kgsl_regmap_read(v2 + 1650);
          if ( (result & 0x100000) == 0 )
            break;
          v6 = v7 + 1;
        }
        while ( v7 );
        if ( (result & 0x100000) != 0 )
          result = dev_warn(*v2, "RBCCU GDSC disable failed\n");
      }
      if ( *(_DWORD *)v2[1783] == 530 )
      {
        kgsl_regmap_write(v2 + 1650, 3932160);
        return kgsl_regmap_write(v2 + 1650, 0);
      }
    }
  }
  return result;
}
