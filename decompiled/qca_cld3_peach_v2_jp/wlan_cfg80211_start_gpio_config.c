__int64 __fastcall wlan_cfg80211_start_gpio_config(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  int v14; // w8
  __int64 v15; // x20
  __int64 v16; // x20
  __int64 v17; // x20
  __int64 v18; // x20
  __int64 v19; // x20
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 v22; // x20
  __int64 v23; // x20
  __int64 v24; // x20
  __int64 v25; // x20
  __int64 v26; // x20
  __int64 v27; // x20
  __int64 v28; // [xsp+28h] [xbp-58h] BYREF
  __int64 v29; // [xsp+30h] [xbp-50h]
  __int64 v30; // [xsp+38h] [xbp-48h]
  __int64 v31; // [xsp+40h] [xbp-40h]
  __int64 v32; // [xsp+48h] [xbp-38h]
  __int64 v33; // [xsp+50h] [xbp-30h]
  __int64 v34; // [xsp+58h] [xbp-28h]
  __int64 v35; // [xsp+60h] [xbp-20h]
  __int64 v36; // [xsp+68h] [xbp-18h]
  __int64 v37; // [xsp+70h] [xbp-10h]
  __int64 v38; // [xsp+78h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  if ( !(unsigned int)_nla_parse(&v28, 9, a3, a4, &wlan_cfg80211_gpio_config_policy, 31, 0) )
  {
    if ( v29 )
    {
      v14 = *(_DWORD *)(v29 + 4);
      if ( v14 == 1 )
      {
        if ( v30 )
        {
          if ( v31 )
          {
            if ( *(_DWORD *)(v31 + 4) < 2u )
            {
              result = ucfg_set_gpio_output(a2, v5, v6, v7, v8, v9, v10, v11, v12);
              goto LABEL_3;
            }
            v17 = jiffies;
            if ( wlan_set_gpio_output___last_ticks_19 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: attr gpio level invalid",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "wlan_set_gpio_output");
              wlan_set_gpio_output___last_ticks_19 = v17;
            }
          }
          else
          {
            v22 = jiffies;
            if ( wlan_set_gpio_output___last_ticks_17 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: attr gpio value failed",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "wlan_set_gpio_output");
              wlan_set_gpio_output___last_ticks_17 = v22;
            }
          }
        }
        else
        {
          v20 = jiffies;
          if ( wlan_set_gpio_output___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: attr gpio number failed",
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              "wlan_set_gpio_output");
            wlan_set_gpio_output___last_ticks = v20;
          }
        }
      }
      else if ( v14 )
      {
        v18 = jiffies;
        if ( wlan_cfg80211_start_gpio_config___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Invalid command",
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            "wlan_cfg80211_start_gpio_config");
          wlan_cfg80211_start_gpio_config___last_ticks = v18;
        }
      }
      else if ( v30 )
      {
        if ( v34 )
        {
          if ( *(_DWORD *)(v34 + 4) < 2u )
          {
            if ( v32 )
            {
              if ( *(_DWORD *)(v32 + 4) < 3u )
              {
                if ( v33 )
                {
                  if ( *(_DWORD *)(v33 + 4) < 6u )
                  {
                    if ( !v36 || *(_DWORD *)(v36 + 4) < 8u )
                    {
                      result = ucfg_set_gpio_config(a2, v5, v6, v7, v8, v9, v10, v11, v12);
                      goto LABEL_3;
                    }
                    v27 = jiffies;
                    if ( wlan_set_gpio_config___last_ticks_15 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x48u,
                        2u,
                        "%s: attr gpio drive invalid",
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11,
                        v12,
                        "wlan_set_gpio_config");
                      wlan_set_gpio_config___last_ticks_15 = v27;
                    }
                  }
                  else
                  {
                    v25 = jiffies;
                    if ( wlan_set_gpio_config___last_ticks_13 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x48u,
                        2u,
                        "%s: attr gpio interrupt mode invalid",
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11,
                        v12,
                        "wlan_set_gpio_config");
                      wlan_set_gpio_config___last_ticks_13 = v25;
                    }
                  }
                }
                else
                {
                  v26 = jiffies;
                  if ( wlan_set_gpio_config___last_ticks_11 - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x48u,
                      2u,
                      "%s: attr gpio interrupt mode failed",
                      v5,
                      v6,
                      v7,
                      v8,
                      v9,
                      v10,
                      v11,
                      v12,
                      "wlan_set_gpio_config");
                    wlan_set_gpio_config___last_ticks_11 = v26;
                  }
                }
              }
              else
              {
                v23 = jiffies;
                if ( wlan_set_gpio_config___last_ticks_9 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    "%s: attr gpio pull type invalid",
                    v5,
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    "wlan_set_gpio_config");
                  wlan_set_gpio_config___last_ticks_9 = v23;
                }
              }
            }
            else
            {
              v24 = jiffies;
              if ( wlan_set_gpio_config___last_ticks_7 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: attr gpio pull failed",
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  v12,
                  "wlan_set_gpio_config");
                wlan_set_gpio_config___last_ticks_7 = v24;
              }
            }
          }
          else
          {
            v15 = jiffies;
            if ( wlan_set_gpio_config___last_ticks_5 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: attr gpio direction invalid",
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                "wlan_set_gpio_config");
              wlan_set_gpio_config___last_ticks_5 = v15;
            }
          }
        }
        else
        {
          v21 = jiffies;
          if ( wlan_set_gpio_config___last_ticks_3 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: attr gpio dir failed",
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              "wlan_set_gpio_config");
            wlan_set_gpio_config___last_ticks_3 = v21;
          }
        }
      }
      else
      {
        v19 = jiffies;
        if ( wlan_set_gpio_config___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: attr gpio number failed",
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            "wlan_set_gpio_config");
          wlan_set_gpio_config___last_ticks = v19;
        }
      }
    }
    else
    {
      v16 = jiffies;
      if ( wlan_cfg80211_start_gpio_config___last_ticks_1 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid command",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "wlan_cfg80211_start_gpio_config");
        wlan_cfg80211_start_gpio_config___last_ticks_1 = v16;
      }
    }
  }
  result = 4294967274LL;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
