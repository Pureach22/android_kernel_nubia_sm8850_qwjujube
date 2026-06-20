__int64 __fastcall csr_translate_to_wni_cfg_dot11_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        int a10)
{
  unsigned int v10; // w4
  bool v11; // zf
  unsigned int v12; // w9

  v10 = a10;
  if ( a10 <= 5 )
  {
    if ( a10 <= 2 )
    {
      switch ( a10 )
      {
        case 0:
          return 1;
        case 1:
          return 2;
        case 2:
          return 3;
      }
LABEL_29:
      qdf_trace_msg(
        0x34u,
        3u,
        "%s: doesn't expect %d as csrDo11Mode",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "csr_translate_to_wni_cfg_dot11_mode");
      return 0;
    }
    if ( a10 == 3 )
      return 4;
    if ( a10 == 4 )
      return 5;
    goto LABEL_23;
  }
  if ( a10 > 8 )
  {
    if ( a10 == 11 )
    {
      if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
        return 11;
    }
    else
    {
      if ( a10 != 10 && a10 != 9 )
        goto LABEL_29;
      if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 )
        return 10;
    }
LABEL_23:
    v11 = (wma_get_fw_wlan_feat_caps(2) & 1) == 0;
    v12 = 8;
LABEL_24:
    if ( v11 )
      return 5;
    else
      return v12;
  }
  if ( a10 != 6 && a10 != 7 )
  {
    v11 = (wma_get_fw_wlan_feat_caps(2) & 1) == 0;
    v12 = 9;
    goto LABEL_24;
  }
  return v10;
}
