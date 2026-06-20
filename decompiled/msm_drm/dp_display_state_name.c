const char *__fastcall dp_display_state_name(__int16 a1)
{
  unsigned int v2; // w21
  size_t v3; // x0
  __int64 v5; // x0
  __int64 v6; // x1

  memset(dp_display_state_name_buf, 0, sizeof(dp_display_state_name_buf));
  if ( (a1 & 1) == 0 )
  {
    if ( (a1 & 2) == 0 )
    {
      if ( (a1 & 4) == 0 )
      {
        if ( (a1 & 8) == 0 )
        {
          if ( (a1 & 0x10) == 0 )
          {
            if ( (a1 & 0x20) == 0 )
            {
              if ( (a1 & 0x40) == 0 )
              {
                if ( (a1 & 0x80) == 0 )
                {
                  if ( (a1 & 0x100) == 0 )
                  {
                    if ( (a1 & 0x200) == 0 )
                    {
                      if ( (a1 & 0x400) == 0 )
                      {
                        if ( (a1 & 0x800) == 0 )
                          goto LABEL_51;
                        v2 = 0;
                        goto LABEL_50;
                      }
                      v2 = 0;
                      goto LABEL_47;
                    }
                    v2 = 0;
                    goto LABEL_44;
                  }
                  v2 = 0;
                  goto LABEL_41;
                }
                v2 = 0;
                goto LABEL_38;
              }
              v2 = 0;
              goto LABEL_35;
            }
            v2 = 0;
            goto LABEL_32;
          }
          v2 = 0;
          goto LABEL_29;
        }
        v2 = 0;
        goto LABEL_26;
      }
      v2 = 0;
      goto LABEL_23;
    }
    v2 = 0;
    goto LABEL_18;
  }
  v3 = scnprintf(dp_display_state_name_buf, 1024, "|%s|", "CONFIGURED");
  v2 = v3;
  if ( (a1 & 2) != 0 )
  {
    if ( (unsigned int)v3 > 0x400 )
      goto LABEL_65;
LABEL_18:
    v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "INITIALIZED");
    v2 += v3;
  }
  if ( (a1 & 4) == 0 )
    goto LABEL_24;
  if ( v2 > 0x400 )
    goto LABEL_65;
LABEL_23:
  v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "READY");
  v2 += v3;
LABEL_24:
  if ( (a1 & 8) != 0 )
  {
    if ( v2 > 0x400 )
      goto LABEL_65;
LABEL_26:
    v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "CONNECTED");
    v2 += v3;
  }
  if ( (a1 & 0x10) == 0 )
    goto LABEL_30;
  if ( v2 > 0x400 )
    goto LABEL_65;
LABEL_29:
  v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "CONNECT_NOTIFIED");
  v2 += v3;
LABEL_30:
  if ( (a1 & 0x20) != 0 )
  {
    if ( v2 > 0x400 )
      goto LABEL_65;
LABEL_32:
    v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "DISCONNECT_NOTIFIED");
    v2 += v3;
  }
  if ( (a1 & 0x40) == 0 )
    goto LABEL_36;
  if ( v2 > 0x400 )
    goto LABEL_65;
LABEL_35:
  v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "ENABLED");
  v2 += v3;
LABEL_36:
  if ( (a1 & 0x80) != 0 )
  {
    if ( v2 > 0x400 )
      goto LABEL_65;
LABEL_38:
    v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "SUSPENDED");
    v2 += v3;
  }
  if ( (a1 & 0x100) == 0 )
    goto LABEL_42;
  if ( v2 > 0x400 )
    goto LABEL_65;
LABEL_41:
  v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "ABORTED");
  v2 += v3;
LABEL_42:
  if ( (a1 & 0x200) != 0 )
  {
    if ( v2 > 0x400 )
      goto LABEL_65;
LABEL_44:
    v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "HDCP_ABORTED");
    v2 += v3;
  }
  if ( (a1 & 0x400) == 0 )
    goto LABEL_48;
  if ( v2 > 0x400 )
    goto LABEL_65;
LABEL_47:
  v3 = scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "SRC_PWRDN");
  v2 += v3;
LABEL_48:
  if ( (a1 & 0x800) == 0 )
    goto LABEL_51;
  if ( v2 > 0x400 )
  {
LABEL_65:
    __break(0x5512u);
    goto LABEL_66;
  }
LABEL_50:
  scnprintf(&dp_display_state_name_buf[v2], 1024LL - v2, "|%s|", "TUI_ACTIVE");
LABEL_51:
  v3 = strnlen(dp_display_state_name_buf, 0x400u);
  if ( v3 >= 0x401 )
  {
LABEL_66:
    _fortify_panic(2, 1024, v3 + 1);
    goto LABEL_67;
  }
  if ( v3 == 1024 )
  {
LABEL_67:
    v5 = _fortify_panic(4, 1024, 1025);
    return (const char *)dp_audio_enable(v5, v6);
  }
  if ( v3 )
    return dp_display_state_name_buf;
  else
    return "DISCONNECTED";
}
