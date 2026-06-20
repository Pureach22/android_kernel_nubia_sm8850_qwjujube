__int64 __fastcall hdd_update_action_oui_for_connect(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  char usr_disable_sta_eht; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  char v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *config; // x0
  const char *v24; // x1
  __int64 v25; // x0
  const char *v26; // x2
  const char *v27; // x2

  result = ucfg_action_oui_enabled(*a1);
  if ( (result & 1) != 0 )
  {
    usr_disable_sta_eht = wlan_mlme_get_usr_disable_sta_eht(*a1);
    if ( (*(_DWORD *)(a2 + 212) & 0x60) == 0x40 )
    {
      if ( (usr_disable_sta_eht & 1) != 0 )
      {
        v14 = usr_disable_sta_eht;
        if ( !(unsigned int)ucfg_action_oui_cleanup(*a1, 9) )
        {
          config = (const char *)ucfg_action_oui_get_config(*a1, 9);
          if ( !*config )
            goto LABEL_16;
          v24 = config;
          v25 = *a1;
LABEL_14:
          if ( (unsigned int)ucfg_action_oui_parse(v25, v24, 9) )
          {
            v27 = "%s: Failed to parse action_oui str for id %d";
            return qdf_trace_msg(
                     0x33u,
                     2u,
                     v27,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     "hdd_update_action_oui_for_connect",
                     9);
          }
LABEL_16:
          if ( !(unsigned int)ucfg_action_oui_send_by_id(*a1, 9) )
            return wlan_mlme_set_usr_disable_sta_eht(*a1, (v14 & 1) == 0);
          v27 = "%s: Failed to send oui id %d";
          return qdf_trace_msg(
                   0x33u,
                   2u,
                   v27,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   "hdd_update_action_oui_for_connect",
                   9);
        }
        goto LABEL_12;
      }
      v26 = "%s: user eht is enabled already";
    }
    else
    {
      if ( (usr_disable_sta_eht & 1) == 0 )
      {
        v14 = usr_disable_sta_eht;
        if ( !(unsigned int)ucfg_action_oui_cleanup(*a1, 9) )
        {
          v25 = *a1;
          v24 = "ffffff 00 01";
          goto LABEL_14;
        }
LABEL_12:
        v27 = "%s: Failed to cleanup oui id %d";
        return qdf_trace_msg(
                 0x33u,
                 2u,
                 v27,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "hdd_update_action_oui_for_connect",
                 9);
      }
      v26 = "%s: user eht is disabled already";
    }
    return qdf_trace_msg(0x33u, 8u, v26, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_update_action_oui_for_connect");
  }
  return result;
}
