__int64 __fastcall hdd_set_channel_width(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 v15; // x0
  _WORD *v16; // x26
  unsigned __int16 v17; // w9
  unsigned int v18; // w8
  unsigned __int16 *v19; // x26
  unsigned int v20; // t1
  unsigned int v21; // w21
  unsigned int v22; // w25
  int v23; // w28
  __int64 v24; // x8
  unsigned int updated; // w20
  const char *v26; // x2
  __int64 v28; // x8
  const char *v29; // x2
  unsigned int v30; // w1
  __int64 v31; // x4
  const char *v32; // x2
  __int64 v33; // x21
  char v34[4]; // [xsp+4h] [xbp-43Ch] BYREF
  _QWORD s[135]; // [xsp+8h] [xbp-438h] BYREF

  s[133] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x428u);
  v34[0] = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_set_channel_width");
  if ( vdev_by_user )
  {
    v13 = *(_QWORD *)(vdev_by_user + 152);
    v14 = vdev_by_user;
    if ( v13 )
    {
      v15 = *(_QWORD *)(v13 + 80);
      if ( v15 )
      {
        ucfg_mlme_get_update_chan_width_allowed(v15, v34);
        if ( (v34[0] & 1) != 0 )
        {
          v16 = *(_WORD **)(a2 + 800);
          if ( v16 )
          {
            v17 = *v16 - 4;
            if ( v17 >= 4u )
            {
              v20 = (unsigned __int16)v16[2];
              v19 = v16 + 2;
              v18 = v20;
              v21 = 0;
              v22 = 255;
              if ( v20 >= 4 && v18 <= v17 )
              {
                v23 = v17;
                while ( (__int16)v19[1] < 0 )
                {
                  if ( (unsigned int)_nla_parse(
                                       s,
                                       132,
                                       v19 + 2,
                                       (unsigned __int16)(v18 - 4),
                                       &wlan_hdd_wifi_config_policy,
                                       31,
                                       0) )
                    goto LABEL_40;
                  if ( !s[63] )
                  {
                    v32 = "%s: [MLO] invalid ch width";
                    goto LABEL_35;
                  }
                  v21 = ((__int64 (__fastcall *)(_QWORD))hdd_nl80211_chwidth_to_chwidth)(*(unsigned __int8 *)(s[63] + 4LL));
                  if ( v21 >= 6 )
                  {
                    v29 = "%s: [MLO] invalid channel width:%u";
                    goto LABEL_31;
                  }
                  if ( !s[99] )
                  {
                    v32 = "%s: [MLO] invalid link id";
                    goto LABEL_35;
                  }
                  v22 = *(unsigned __int8 *)(s[99] + 4LL);
                  if ( v22 >= 0x10 )
                  {
                    v29 = "%s: [MLO] invalid link_id:%u";
                    v30 = 8;
                    v31 = *(unsigned __int8 *)(s[99] + 4LL);
                    goto LABEL_32;
                  }
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: [MLO] chwidth: %u, link_id: %u",
                    v5,
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    "hdd_set_channel_width",
                    v21,
                    *(unsigned __int8 *)(s[99] + 4LL));
                  v24 = (*v19 + 3) & 0x1FFFC;
                  v23 -= v24;
                  if ( v23 > 3 )
                  {
                    v19 = (unsigned __int16 *)((char *)v19 + v24);
                    v18 = *v19;
                    if ( v18 >= 4 && v23 >= v18 )
                      continue;
                  }
                  goto LABEL_38;
                }
                do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_40:
                v33 = jiffies;
                if ( hdd_set_channel_width___last_ticks - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: [MLO] nla_parse failed",
                    v5,
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    "hdd_set_channel_width");
                  hdd_set_channel_width___last_ticks = v33;
                }
                goto LABEL_25;
              }
LABEL_38:
              updated = hdd_update_channel_width(a1, v21, v21 != 0, v22, 1);
              goto LABEL_26;
            }
            v21 = 0;
LABEL_37:
            v22 = 255;
            goto LABEL_38;
          }
          v28 = *(_QWORD *)(a2 + 504);
          if ( !v28 )
          {
            v32 = "%s: [non-MLO] CHANNEL_WIDTH ATTR is NULL";
LABEL_35:
            qdf_trace_msg(0x33u, 2u, v32, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_set_channel_width");
            updated = 0;
            goto LABEL_26;
          }
          v21 = ((__int64 (__fastcall *)(_QWORD))hdd_nl80211_chwidth_to_chwidth)(*(unsigned __int8 *)(v28 + 4));
          if ( v21 < 6 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: [non-MLO] vdev_id: %d channel width: %u",
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              "hdd_set_channel_width",
              *(unsigned __int8 *)(a1 + 8),
              v21);
            goto LABEL_37;
          }
          v29 = "%s: [non-MLO] Invalid channel width %u";
LABEL_31:
          v30 = 2;
          v31 = v21;
LABEL_32:
          qdf_trace_msg(0x33u, v30, v29, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_set_channel_width", v31);
LABEL_25:
          updated = -22;
LABEL_26:
          _hdd_objmgr_put_vdev_by_user(v14, 6, "hdd_set_channel_width");
          goto LABEL_27;
        }
        v26 = "%s: update_channel_width is disabled via INI";
      }
      else
      {
        v26 = "%s: psoc is null";
      }
    }
    else
    {
      v26 = "%s: pdev is NULL";
    }
    qdf_trace_msg(0x33u, 8u, v26, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_set_channel_width");
    goto LABEL_25;
  }
  qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "hdd_set_channel_width");
  updated = -22;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return updated;
}
