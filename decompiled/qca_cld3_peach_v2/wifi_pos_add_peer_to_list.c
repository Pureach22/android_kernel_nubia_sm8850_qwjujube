__int64 __fastcall wifi_pos_add_peer_to_list(__int64 result, _DWORD *a2, char a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x8
  unsigned __int8 *v17; // x20
  __int64 v34; // x8
  int v35; // w23
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  const char *v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  int v49; // w8
  __int64 v50; // [xsp+18h] [xbp-38h]

  if ( *(_DWORD *)(result + 16) )
    return result;
  v50 = v4;
  result = wifi_pos_get_vdev_priv_obj(result);
  if ( !result )
    return qdf_trace_msg(
             0x25u,
             2u,
             "%s: Wifi pos vdev priv obj is null",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "wifi_pos_add_peer_to_list");
  v15 = result;
  v16 = 6084;
  if ( a2[2] == 1 )
    v16 = 0;
  v17 = (unsigned __int8 *)(result + v16);
  if ( *(_DWORD *)(result + v16) == -1 && *(__int16 *)(result + v16 + 4) == -1 )
  {
    v35 = 0;
  }
  else if ( *((_DWORD *)v17 + 95) == -1 && *((__int16 *)v17 + 192) == -1 )
  {
    v17 += 380;
    v35 = 1;
  }
  else if ( *((_DWORD *)v17 + 190) == -1 && *((__int16 *)v17 + 382) == -1 )
  {
    v17 += 760;
    v35 = 2;
  }
  else if ( *((_DWORD *)v17 + 285) == -1 && *((__int16 *)v17 + 572) == -1 )
  {
    v17 += 1140;
    v35 = 3;
  }
  else if ( *((_DWORD *)v17 + 380) == -1 && *((__int16 *)v17 + 762) == -1 )
  {
    v17 += 1520;
    v35 = 4;
  }
  else if ( *((_DWORD *)v17 + 475) == -1 && *((__int16 *)v17 + 952) == -1 )
  {
    v17 += 1900;
    v35 = 5;
  }
  else if ( *((_DWORD *)v17 + 570) == -1 && *((__int16 *)v17 + 1142) == -1 )
  {
    v17 += 2280;
    v35 = 6;
  }
  else if ( *((_DWORD *)v17 + 665) == -1 && *((__int16 *)v17 + 1332) == -1 )
  {
    v17 += 2660;
    v35 = 7;
  }
  else if ( *((_DWORD *)v17 + 760) == -1 && *((__int16 *)v17 + 1522) == -1 )
  {
    v17 += 3040;
    v35 = 8;
  }
  else if ( *((_DWORD *)v17 + 855) == -1 && *((__int16 *)v17 + 1712) == -1 )
  {
    v17 += 3420;
    v35 = 9;
  }
  else if ( *((_DWORD *)v17 + 950) == -1 && *((__int16 *)v17 + 1902) == -1 )
  {
    v17 += 3800;
    v35 = 10;
  }
  else
  {
    if ( *((_DWORD *)v17 + 1045) == -1 && *((__int16 *)v17 + 2092) == -1 )
    {
      v34 = 4180;
      v35 = 11;
    }
    else if ( *((_DWORD *)v17 + 1140) == -1 && *((__int16 *)v17 + 2282) == -1 )
    {
      v34 = 4560;
      v35 = 12;
    }
    else if ( *((_DWORD *)v17 + 1235) == -1 && *((__int16 *)v17 + 2472) == -1 )
    {
      v34 = 4940;
      v35 = 13;
    }
    else if ( *((_DWORD *)v17 + 1330) == -1 && *((__int16 *)v17 + 2662) == -1 )
    {
      v34 = 5320;
      v35 = 14;
    }
    else
    {
      if ( *((_DWORD *)v17 + 1425) != -1 || *((__int16 *)v17 + 2852) != -1 )
        return result;
      v34 = 5700;
      v35 = 15;
    }
    v17 += v34;
  }
  memcpy(v17, a2, 0x17Cu);
  if ( (a3 & 1) != 0 )
    ++*(_BYTE *)(v15 + 12262);
  v44 = 12164;
  if ( a2[2] == 1 )
    v44 = 6080;
  ++*(_BYTE *)(v15 + v44);
  if ( a2[2] == 1 )
    v45 = "secure";
  else
    v45 = "insecure";
  if ( v17 )
  {
    v46 = *v17;
    v47 = v17[1];
    v48 = v17[2];
    v49 = v17[5];
  }
  else
  {
    v48 = 0;
    v46 = 0;
    v47 = 0;
    v49 = 0;
  }
  return qdf_trace_msg(
           0x25u,
           8u,
           "%s: Added %s peer: %02x:%02x:%02x:**:**:%02x at idx[%d]",
           v36,
           v37,
           v38,
           v39,
           v40,
           v41,
           v42,
           v43,
           "wifi_pos_add_peer_to_list",
           v45,
           v46,
           v47,
           v48,
           v49,
           v35,
           v3,
           v50);
}
