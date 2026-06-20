const char *__fastcall dp_link_get_test_name(int a1)
{
  if ( a1 <= 7 )
  {
    if ( a1 == 1 )
      return "DP_TEST_LINK_TRAINING";
    if ( a1 != 2 )
    {
      if ( a1 == 4 )
        return "DP_TEST_LINK_EDID_READ";
      return "unknown";
    }
    return "DP_TEST_LINK_VIDEO_PATTERN";
  }
  else if ( a1 > 127 )
  {
    if ( a1 != 128 )
    {
      if ( a1 == 512 )
        return "DS_PORT_STATUS_CHANGED";
      return "unknown";
    }
    return "DP_LINK_STATUS_UPDATED";
  }
  else
  {
    if ( a1 != 8 )
    {
      if ( a1 == 32 )
        return "DP_TEST_LINK_AUDIO_PATTERN";
      return "unknown";
    }
    return "DP_TEST_LINK_PHY_TEST_PATTERN";
  }
}
