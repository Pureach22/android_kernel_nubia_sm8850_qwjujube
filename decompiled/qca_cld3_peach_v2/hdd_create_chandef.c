__int64 __fastcall hdd_create_chandef(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v3; // w21
  __int64 channel_khz; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w8
  unsigned int v16; // w9
  __int64 v17; // x2
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v23; // w8
  int v24; // w8

  v3 = *(unsigned __int16 *)a2;
  channel_khz = ieee80211_get_channel_khz(*(_QWORD *)(a1 + 112), 1000 * v3);
  if ( !channel_khz )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid input frequency %d for channel conversion",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_create_chandef",
      v3);
    return 16;
  }
  if ( (unsigned int)(a2[7] - 5) > 0x23 )
  {
    v17 = 0;
  }
  else
  {
    v15 = a2[4];
    if ( v15 && (v16 = *(unsigned __int16 *)a2, v15 != v16) )
    {
      if ( v15 <= v16 )
        v17 = 2;
      else
        v17 = 3;
    }
    else
    {
      v17 = 1;
    }
  }
  cfg80211_chandef_create(a3, channel_khz, v17);
  v19 = a2[6];
  switch ( v19 )
  {
    case 4:
      a3[2] = 4;
      v21 = a2[5];
      if ( v21 )
        a3[4] = v21;
      break;
    case 3:
      a3[2] = 5;
      v20 = a2[5];
      if ( v20 )
        a3[3] = v20;
      break;
    case 2:
      a3[2] = 3;
      break;
    default:
      goto LABEL_20;
  }
  v19 = a2[6];
LABEL_20:
  if ( v19 == 7 )
  {
    a3[2] = 13;
    v22 = a2[5];
    if ( v22 )
      a3[3] = v22;
  }
  v23 = a2[6];
  if ( v23 != 4 && v23 != 2 )
    return 0;
  v24 = a2[4];
  if ( !v24 )
    return 0;
  a3[3] = v24;
  return 0;
}
