__int64 __fastcall csr_get_cfg_dot11_mode_from_csr_phy_mode(unsigned __int8 a1, int a2)
{
  __int64 result; // x0

  result = 0;
  if ( a2 > 255 )
  {
    if ( a2 <= 2047 )
    {
      if ( a2 != 256 )
      {
        if ( a2 == 512 )
        {
          if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
            return 8;
          else
            return 4;
        }
        else if ( a2 == 1024 )
        {
          return 9;
        }
        return result;
      }
LABEL_39:
      if ( (wma_get_fw_wlan_feat_caps(2) & 1) != 0 )
        return 5;
      else
        return 4;
    }
    if ( a2 >= 0x2000 )
    {
      if ( a2 != 0x2000 )
      {
        if ( a2 != 0x4000 )
          return result;
        if ( (wma_get_fw_wlan_feat_caps(14) & 1) != 0 )
          return 13;
LABEL_29:
        if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
          return 11;
        goto LABEL_39;
      }
      if ( (wma_get_fw_wlan_feat_caps(14) & 1) != 0 )
        return 12;
    }
    else if ( a2 != 2048 )
    {
      if ( a2 != 4096 )
        return result;
      goto LABEL_29;
    }
    if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
      return 10;
    goto LABEL_39;
  }
  if ( a2 <= 15 )
  {
    if ( a2 == 2 )
      return 1;
    if ( a2 != 4 )
    {
      if ( a2 != 8 )
        return result;
LABEL_15:
      if ( ((a2 == 32) & a1) != 0 )
        return 6;
      else
        return 3;
    }
    return 2;
  }
  if ( a2 > 63 )
  {
    if ( a2 == 64 )
    {
      if ( (a1 & 1) != 0 )
        return 7;
      else
        return 4;
    }
    if ( a2 != 128 )
      return result;
    return 2;
  }
  if ( a2 == 16 )
    return 4;
  if ( a2 == 32 )
    goto LABEL_15;
  return result;
}
