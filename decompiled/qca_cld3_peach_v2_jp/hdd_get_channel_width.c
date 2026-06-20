__int64 __fastcall hdd_get_channel_width(__int64 a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 ext_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 *v23; // x8
  const char *v24; // x2
  unsigned int v25; // w0
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_channel_width");
  if ( vdev_by_user )
  {
    v12 = *(_QWORD *)(vdev_by_user + 32);
    if ( v12 )
    {
      v13 = vdev_by_user;
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(vdev_by_user, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( ext_hdl )
      {
        v23 = (unsigned __int8 *)(ext_hdl + 24252);
        if ( !*(_BYTE *)(ext_hdl + 24256) )
          v23 = (unsigned __int8 *)(v12 + 24);
        v35[0] = hdd_phy_chwidth_to_nl80211_chwidth(*v23);
        if ( !(unsigned int)nla_put(a2, 63, 1, v35) )
        {
          _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_get_channel_width");
          result = 0;
          goto LABEL_13;
        }
        v24 = "%s: nla_put chn width failure";
        v25 = 51;
      }
      else
      {
        v24 = "%s: vdev legacy private object is NULL";
        v25 = 31;
      }
      qdf_trace_msg(v25, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_get_channel_width");
      result = 4294967274LL;
    }
    else
    {
      _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "hdd_get_channel_width");
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: get bss_chan failed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_get_channel_width");
      result = 16;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
