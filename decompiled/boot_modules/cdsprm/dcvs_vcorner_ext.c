const char *__fastcall dcvs_vcorner_ext(int a1)
{
  char v2; // w8
  char v3; // w8

  if ( a1 > 448 )
  {
    if ( a1 <= 576 )
    {
      if ( (unsigned int)(a1 - 449) < 0x40 )
        return (const char *)&unk_BD2D;
      else
        return "NOM_L1";
    }
    if ( (unsigned int)(a1 - 577) < 0x40 )
      return "TUR";
    v2 = a1 + 127;
    if ( (unsigned int)(a1 - 641) <= 0x3F )
    {
      if ( (unsigned int)(1LL << v2) )
        return "TUR_L1";
      if ( ((1LL << v2) & 0xFFFF00000000LL) != 0 )
        return "TUR_L2";
      return "TUR_L3";
    }
    goto LABEL_26;
  }
  if ( a1 <= 320 )
  {
    v3 = a1 - 1;
    if ( (unsigned int)(a1 - 257) > 0x3F )
    {
      if ( !a1 )
        return "DISABLE";
LABEL_26:
      if ( (unsigned int)(a1 - 705) <= 0xFD3E )
        return "MAX";
      if ( (unsigned int)(a1 - 1) >= 0x100 )
        return "INVALID";
      return "MIN";
    }
    if ( ((1LL << v3) & 0xFFFFFFFFFFFFFLL) != 0 )
    {
      return "LOW_SVS_D2";
    }
    else if ( ((1LL << v3) & 0xFF00000000000000LL) != 0 )
    {
      return "LOW_SVS";
    }
    else
    {
      return "LOW_SVS_D1";
    }
  }
  else if ( (unsigned int)(a1 - 321) < 0x40 )
  {
    return "SVS";
  }
  else
  {
    return "SVS_L1";
  }
}
