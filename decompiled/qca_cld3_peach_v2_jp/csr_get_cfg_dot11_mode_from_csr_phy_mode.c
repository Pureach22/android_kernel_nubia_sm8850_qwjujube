__int64 __fastcall csr_get_cfg_dot11_mode_from_csr_phy_mode(unsigned __int8 a1, int a2)
{
  __int64 result; // x0

  result = 0;
  if ( a2 > 127 )
  {
    if ( a2 > 1023 )
    {
      switch ( a2 )
      {
        case 1024:
          return 9;
        case 2048:
          if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
            return 10;
          break;
        case 4096:
          if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
            return 11;
          break;
        default:
          return result;
      }
    }
    else
    {
      if ( a2 == 128 )
        return 2;
      if ( a2 != 256 )
      {
        if ( a2 == 512 )
        {
          if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
            return 8;
          else
            return 4;
        }
        return result;
      }
    }
    if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
      return 5;
    else
      return 4;
  }
  if ( a2 <= 15 )
  {
    if ( a2 == 2 )
      return 1;
    if ( a2 != 4 )
    {
      if ( a2 != 8 )
        return result;
      goto LABEL_25;
    }
    return 2;
  }
  switch ( a2 )
  {
    case 16:
      return 4;
    case 32:
LABEL_25:
      if ( ((a2 == 32) & a1) != 0 )
        return 6;
      else
        return 3;
    case 64:
      if ( (a1 & 1) != 0 )
        return 7;
      else
        return 4;
  }
  return result;
}
