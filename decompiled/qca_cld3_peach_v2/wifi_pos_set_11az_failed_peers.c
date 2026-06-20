__int64 __fastcall wifi_pos_set_11az_failed_peers(__int64 a1, unsigned __int8 *a2)
{
  __int64 vdev_priv_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  bool v20; // zf
  bool v21; // zf
  bool v22; // zf
  bool v23; // zf
  bool v24; // zf
  bool v25; // zf
  bool v26; // zf
  bool v27; // zf
  __int64 v28; // x9
  const char *v45; // x2
  unsigned int v46; // w1
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  const char *v52; // x2
  int v53; // w10
  int v54; // w12
  char v55; // w13
  int v56; // [xsp+0h] [xbp-10h]

  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a1);
  if ( !vdev_priv_obj )
  {
    v45 = "%s: Wifi pos vdev priv obj is null";
    v46 = 2;
    return qdf_trace_msg(0x25u, v46, v45, v4, v5, v6, v7, v8, v9, v10, v11, "wifi_pos_set_11az_failed_peers");
  }
  if ( !*(_BYTE *)(vdev_priv_obj + 12261) )
    goto LABEL_67;
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12165)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12169) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12171)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12175) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12177)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12181) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12183)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12187) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12189)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12193) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12195)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12199) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12201)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12205) )
  {
    goto LABEL_132;
  }
  if ( *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12207)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12211) )
  {
    goto LABEL_132;
  }
  v20 = *(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12213)
     && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12217);
  if ( v20
    || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12219)
      ? (v21 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12223))
      : (v21 = 0),
        v21
     || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12225)
       ? (v22 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12229))
       : (v22 = 0),
         v22
      || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12231)
        ? (v23 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12235))
        : (v23 = 0),
          v23
       || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12237)
         ? (v24 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12241))
         : (v24 = 0),
           v24
        || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12243)
          ? (v25 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12247))
          : (v25 = 0),
            v25
         || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12249)
           ? (v26 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12253))
           : (v26 = 0),
             v26
          || (*(_DWORD *)a2 == *(_DWORD *)(vdev_priv_obj + 12255)
            ? (v27 = *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(vdev_priv_obj + 12259))
            : (v27 = 0),
              v27))))))) )
  {
LABEL_132:
    if ( a2 )
    {
      v47 = *a2;
      v48 = a2[1];
      v49 = a2[2];
      v50 = a2[5];
    }
    else
    {
      v49 = 0;
      v47 = 0;
      v48 = 0;
      v50 = 0;
    }
    v52 = "%s: Peer: %02x:%02x:%02x:**:**:%02x already exists in failed list";
  }
  else
  {
LABEL_67:
    v28 = vdev_priv_obj + 12165;
    if ( *(_DWORD *)(vdev_priv_obj + 12165) == -1 && *(__int16 *)(vdev_priv_obj + 12169) == -1 )
    {
      v53 = 0;
    }
    else
    {
      v28 = vdev_priv_obj + 12171;
      if ( *(_DWORD *)(vdev_priv_obj + 12171) == -1 && *(__int16 *)(vdev_priv_obj + 12175) == -1 )
      {
        v53 = 1;
      }
      else
      {
        v28 = vdev_priv_obj + 12177;
        if ( *(_DWORD *)(vdev_priv_obj + 12177) == -1 && *(__int16 *)(vdev_priv_obj + 12181) == -1 )
        {
          v53 = 2;
        }
        else
        {
          v28 = vdev_priv_obj + 12183;
          if ( *(_DWORD *)(vdev_priv_obj + 12183) == -1 && *(__int16 *)(vdev_priv_obj + 12187) == -1 )
          {
            v53 = 3;
          }
          else
          {
            v28 = vdev_priv_obj + 12189;
            if ( *(_DWORD *)(vdev_priv_obj + 12189) == -1 && *(__int16 *)(vdev_priv_obj + 12193) == -1 )
            {
              v53 = 4;
            }
            else
            {
              v28 = vdev_priv_obj + 12195;
              if ( *(_DWORD *)(vdev_priv_obj + 12195) == -1 && *(__int16 *)(vdev_priv_obj + 12199) == -1 )
              {
                v53 = 5;
              }
              else
              {
                v28 = vdev_priv_obj + 12201;
                if ( *(_DWORD *)(vdev_priv_obj + 12201) == -1 && *(__int16 *)(vdev_priv_obj + 12205) == -1 )
                {
                  v53 = 6;
                }
                else
                {
                  v28 = vdev_priv_obj + 12207;
                  if ( *(_DWORD *)(vdev_priv_obj + 12207) == -1 && *(__int16 *)(vdev_priv_obj + 12211) == -1 )
                  {
                    v53 = 7;
                  }
                  else
                  {
                    v28 = vdev_priv_obj + 12213;
                    if ( *(_DWORD *)(vdev_priv_obj + 12213) == -1 && *(__int16 *)(vdev_priv_obj + 12217) == -1 )
                    {
                      v53 = 8;
                    }
                    else
                    {
                      v28 = vdev_priv_obj + 12219;
                      if ( *(_DWORD *)(vdev_priv_obj + 12219) == -1 && *(__int16 *)(vdev_priv_obj + 12223) == -1 )
                      {
                        v53 = 9;
                      }
                      else
                      {
                        v28 = vdev_priv_obj + 12225;
                        if ( *(_DWORD *)(vdev_priv_obj + 12225) == -1 && *(__int16 *)(vdev_priv_obj + 12229) == -1 )
                        {
                          v53 = 10;
                        }
                        else
                        {
                          v28 = vdev_priv_obj + 12231;
                          if ( *(_DWORD *)(vdev_priv_obj + 12231) == -1 && *(__int16 *)(vdev_priv_obj + 12235) == -1 )
                          {
                            v53 = 11;
                          }
                          else
                          {
                            v28 = vdev_priv_obj + 12237;
                            if ( *(_DWORD *)(vdev_priv_obj + 12237) == -1 && *(__int16 *)(vdev_priv_obj + 12241) == -1 )
                            {
                              v53 = 12;
                            }
                            else
                            {
                              v28 = vdev_priv_obj + 12243;
                              if ( *(_DWORD *)(vdev_priv_obj + 12243) == -1 && *(__int16 *)(vdev_priv_obj + 12247) == -1 )
                              {
                                v53 = 13;
                              }
                              else
                              {
                                v28 = vdev_priv_obj + 12249;
                                if ( *(_DWORD *)(vdev_priv_obj + 12249) == -1
                                  && *(__int16 *)(vdev_priv_obj + 12253) == -1 )
                                {
                                  v53 = 14;
                                }
                                else
                                {
                                  v28 = vdev_priv_obj + 12255;
                                  if ( *(_DWORD *)(vdev_priv_obj + 12255) != -1
                                    || *(__int16 *)(vdev_priv_obj + 12259) != -1 )
                                  {
                                    v45 = "%s: Not able to set failed peer";
                                    v46 = 8;
                                    return qdf_trace_msg(
                                             0x25u,
                                             v46,
                                             v45,
                                             v4,
                                             v5,
                                             v6,
                                             v7,
                                             v8,
                                             v9,
                                             v10,
                                             v11,
                                             "wifi_pos_set_11az_failed_peers");
                                  }
                                  v53 = 15;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v54 = *(_DWORD *)a2;
    v55 = *(_BYTE *)(vdev_priv_obj + 12261);
    *(_WORD *)(v28 + 4) = *((_WORD *)a2 + 2);
    *(_DWORD *)v28 = v54;
    *(_BYTE *)(vdev_priv_obj + 12261) = v55 + 1;
    if ( a2 )
    {
      v47 = *a2;
      v48 = a2[1];
      v49 = a2[2];
      v50 = a2[5];
    }
    else
    {
      v49 = 0;
      v47 = 0;
      v48 = 0;
      v50 = 0;
    }
    v52 = "%s: Added failed peer: %02x:%02x:%02x:**:**:%02x at idx[%d]";
    v56 = v53;
  }
  return qdf_trace_msg(
           0x25u,
           8u,
           v52,
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "wifi_pos_set_11az_failed_peers",
           v47,
           v48,
           v49,
           v50,
           v56);
}
