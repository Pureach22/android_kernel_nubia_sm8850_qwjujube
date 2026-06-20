__int64 __fastcall rmnet_wwan_set_device(char *string, __int64 a2)
{
  _QWORD *v3; // x20
  size_t v4; // x0
  unsigned __int64 v5; // x2
  __int64 v7; // x0
  __int64 v8; // x1

  if ( rmnet_wwan_device == *string
    && (!byte_CEDD
     || byte_CEDD == string[1]
     && (!byte_CEDE
      || byte_CEDE == string[2]
      && (!byte_CEDF
       || byte_CEDF == string[3]
       && (!byte_CEE0
        || byte_CEE0 == string[4]
        && (!byte_CEE1
         || byte_CEE1 == string[5]
         && (!byte_CEE2
          || byte_CEE2 == string[6]
          && (!byte_CEE3
           || byte_CEE3 == string[7]
           && (!byte_CEE4
            || byte_CEE4 == string[8]
            && (!byte_CEE5
             || byte_CEE5 == string[9]
             && (!byte_CEE6
              || byte_CEE6 == string[10]
              && (!byte_CEE7
               || byte_CEE7 == string[11]
               && (!byte_CEE8
                || byte_CEE8 == string[12]
                && (!byte_CEE9
                 || byte_CEE9 == string[13]
                 && (!byte_CEEA || byte_CEEA == string[14] && (!byte_CEEB || byte_CEEB == string[15]))))))))))))))) )
  {
    v3 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Device is already set");
    if ( v3 )
      *v3 = "Device is already set";
    return 0;
  }
  rmnet_wwan_device = 0;
  v4 = strnlen(string, 0x10u);
  if ( v4 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v4 == 16 )
      v5 = 16;
    else
      v5 = v4 + 1;
    if ( v5 < 0x11 )
    {
      sized_strscpy(&rmnet_wwan_device, string);
      return 0;
    }
  }
  v7 = _fortify_panic(7, 16, v5);
  return rmnet_wlan_unset_device(v7, v8);
}
