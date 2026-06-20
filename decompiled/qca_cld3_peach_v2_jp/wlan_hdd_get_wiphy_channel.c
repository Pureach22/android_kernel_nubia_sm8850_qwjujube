unsigned __int64 __fastcall wlan_hdd_get_wiphy_channel(
        _QWORD *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x20
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x8

  v10 = a1[41];
  if ( v10 )
  {
    v13 = *(unsigned int *)(v10 + 20);
    if ( (_DWORD)v13 )
    {
      v14 = *(_QWORD *)v10;
      v15 = v14 + ((unsigned __int64)(unsigned int)(v13 - 1) << 6);
      while ( *(_DWORD *)(v14 + 4) != a2 )
      {
        --v13;
        v14 += 64LL;
        if ( !v13 )
        {
          v16 = a1[42];
          if ( !v16 )
            goto LABEL_35;
          goto LABEL_7;
        }
      }
      return v14;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Band %d not part of wiphy",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_get_wiphy_channel",
      0);
  }
  v15 = 0;
  v16 = a1[42];
  if ( !v16 )
  {
LABEL_35:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Band %d not part of wiphy",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_get_wiphy_channel",
      1);
    v18 = a1[43];
    if ( !v18 )
      goto LABEL_36;
LABEL_12:
    v19 = *(unsigned int *)(v18 + 20);
    if ( (_DWORD)v19 )
    {
      v14 = *(_QWORD *)v18;
      v15 = v14 + ((unsigned __int64)(unsigned int)(v19 - 1) << 6);
      while ( *(_DWORD *)(v14 + 4) != a2 )
      {
        --v19;
        v14 += 64LL;
        if ( !v19 )
          goto LABEL_16;
      }
      return v14;
    }
LABEL_16:
    v20 = a1[44];
    if ( !v20 )
      goto LABEL_37;
    goto LABEL_17;
  }
LABEL_7:
  v17 = *(unsigned int *)(v16 + 20);
  if ( (_DWORD)v17 )
  {
    v14 = *(_QWORD *)v16;
    v15 = v14 + ((unsigned __int64)(unsigned int)(v17 - 1) << 6);
    while ( *(_DWORD *)(v14 + 4) != a2 )
    {
      --v17;
      v14 += 64LL;
      if ( !v17 )
        goto LABEL_11;
    }
    return v14;
  }
LABEL_11:
  v18 = a1[43];
  if ( v18 )
    goto LABEL_12;
LABEL_36:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Band %d not part of wiphy",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_get_wiphy_channel",
    2);
  v20 = a1[44];
  if ( !v20 )
  {
LABEL_37:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Band %d not part of wiphy",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_get_wiphy_channel",
      3);
    v22 = a1[45];
    if ( !v22 )
    {
LABEL_38:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Band %d not part of wiphy",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_hdd_get_wiphy_channel",
        4);
      v24 = a1[46];
      if ( !v24 )
        goto LABEL_39;
      goto LABEL_27;
    }
    goto LABEL_22;
  }
LABEL_17:
  v21 = *(unsigned int *)(v20 + 20);
  if ( (_DWORD)v21 )
  {
    v14 = *(_QWORD *)v20;
    v15 = v14 + ((unsigned __int64)(unsigned int)(v21 - 1) << 6);
    while ( *(_DWORD *)(v14 + 4) != a2 )
    {
      --v21;
      v14 += 64LL;
      if ( !v21 )
        goto LABEL_21;
    }
    return v14;
  }
LABEL_21:
  v22 = a1[45];
  if ( !v22 )
    goto LABEL_38;
LABEL_22:
  v23 = *(unsigned int *)(v22 + 20);
  if ( (_DWORD)v23 )
  {
    v14 = *(_QWORD *)v22;
    v15 = v14 + ((unsigned __int64)(unsigned int)(v23 - 1) << 6);
    while ( *(_DWORD *)(v14 + 4) != a2 )
    {
      --v23;
      v14 += 64LL;
      if ( !v23 )
        goto LABEL_26;
    }
    return v14;
  }
LABEL_26:
  v24 = a1[46];
  if ( !v24 )
  {
LABEL_39:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Band %d not part of wiphy",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_get_wiphy_channel",
      5);
    return v15;
  }
LABEL_27:
  v25 = *(unsigned int *)(v24 + 20);
  if ( (_DWORD)v25 )
  {
    v15 = *(_QWORD *)v24;
    v14 = *(_QWORD *)v24 + ((unsigned __int64)(unsigned int)(v25 - 1) << 6);
    while ( *(_DWORD *)(v15 + 4) != a2 )
    {
      --v25;
      v15 += 64LL;
      if ( !v25 )
        return v14;
    }
  }
  return v15;
}
