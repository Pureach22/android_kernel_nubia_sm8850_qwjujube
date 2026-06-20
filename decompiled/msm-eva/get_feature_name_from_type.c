const char *__fastcall get_feature_name_from_type(int a1)
{
  if ( a1 <= 4095 )
  {
    if ( a1 > 63 )
    {
      if ( a1 <= 255 )
      {
        if ( a1 == 64 )
          return (const char *)&unk_8535D;
        if ( a1 == 128 )
          return "Pyramid HCD";
      }
      else
      {
        switch ( a1 )
        {
          case 256:
            return "BLOB";
          case 512:
            return "DESCRIPTOR";
          case 1024:
            return "MATCH";
        }
      }
    }
    else if ( a1 <= 3 )
    {
      if ( a1 == 1 )
        return (const char *)&unk_8FB68;
      if ( a1 == 2 )
        return "SCALER";
    }
    else
    {
      switch ( a1 )
      {
        case 4:
          return (const char *)&unk_849D4;
        case 8:
          return "DFS";
        case 16:
          return "WARP NCC";
      }
    }
  }
  else if ( a1 < 0x20000 )
  {
    if ( a1 < 0x4000 )
    {
      if ( a1 == 4096 )
        return "LME";
      if ( a1 == 0x2000 )
        return (const char *)&unk_90FC7;
    }
    else
    {
      switch ( a1 )
      {
        case 0x4000:
          return (const char *)&unk_954B7;
        case 0x8000:
          return (const char *)&unk_83350;
        case 0x10000:
          return "CSC";
      }
    }
  }
  else if ( a1 >= 0x100000 )
  {
    switch ( a1 )
    {
      case 0x100000:
        return "Spatial Stats";
      case 0x200000:
        return (const char *)&unk_867A4;
      case 0x800000:
        return "WARP";
    }
  }
  else
  {
    switch ( a1 )
    {
      case 0x20000:
        return (const char *)&unk_949BB;
      case 0x40000:
        return "ITOF";
      case 0x80000:
        return "RGE";
    }
  }
  return (const char *)&unk_83F66;
}
