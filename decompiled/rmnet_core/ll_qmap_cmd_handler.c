__int64 __fastcall ll_qmap_cmd_handler(__int64 a1)
{
  __int64 v1; // x22
  int v2; // w8
  unsigned __int64 v3; // x8
  __int64 dev; // x0
  __int64 qos_pt; // x0
  __int64 *v6; // x20
  __int64 v7; // x19
  unsigned __int64 v8; // x23
  unsigned __int8 *v9; // x25
  unsigned __int64 v11; // x8
  __int64 *bearer_map; // x0
  int v13; // w8
  char v14; // w9
  __int64 v15; // x10
  int v16; // w8
  __int64 *v17; // x21
  __int64 *v18; // x21
  unsigned int v19; // w20
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 *v22; // x20
  unsigned __int64 v23; // x23
  unsigned __int8 *v24; // x25
  __int64 *v25; // x21
  __int64 *v26; // x0
  int v27; // w8
  char v28; // w9
  __int64 v29; // x10
  int v30; // w8
  __int64 *v31; // x21

  v1 = *(_QWORD *)(a1 + 224);
  v2 = *(unsigned __int8 *)(v1 + 4);
  if ( v2 == 25 )
  {
    if ( (*(_BYTE *)(v1 + 5) & 3) == 1 )
    {
      v3 = *(unsigned int *)(a1 + 112);
      if ( (unsigned int)v3 >= 0x10 )
      {
        if ( *(_BYTE *)(v1 + 15) )
        {
          if ( 4 * (unsigned __int64)*(unsigned __int8 *)(v1 + 15) + 16 <= v3 )
          {
            dev = rmnet_qmap_get_dev(*(_BYTE *)(v1 + 1));
            if ( dev )
            {
              qos_pt = rmnet_get_qos_pt(dev);
              if ( qos_pt )
              {
                v6 = (__int64 *)qos_pt;
                v7 = qos_pt + 332;
                raw_spin_lock_bh(qos_pt + 332);
                if ( *(_BYTE *)(v1 + 15) )
                {
                  v8 = 0;
                  v9 = (unsigned __int8 *)(v1 + 17);
                  while ( 1 )
                  {
                    bearer_map = qmi_rmnet_get_bearer_map(v6, *(v9 - 1));
                    if ( bearer_map )
                      break;
LABEL_19:
                    ++v8;
                    v9 += 4;
                    if ( v8 >= *(unsigned __int8 *)(v1 + 15) )
                      goto LABEL_34;
                  }
                  v13 = *v9;
                  if ( v13 == 2 )
                  {
                    v14 = 0;
                  }
                  else
                  {
                    if ( v13 != 3 )
                    {
LABEL_27:
                      if ( *((_DWORD *)bearer_map + 34) == 1 && *((_DWORD *)bearer_map + 35) == *(_DWORD *)(v1 + 8) )
                      {
                        v16 = *v9;
                        if ( v16 == 1 )
                        {
                          *((_DWORD *)bearer_map + 34) = 2;
                        }
                        else
                        {
                          *((_BYTE *)bearer_map + 131) = v16;
                          if ( v16 == 4 && *((_BYTE *)bearer_map + 130) )
                          {
                            v17 = bearer_map;
                            *((_DWORD *)bearer_map + 34) = 3;
                            mod_timer(bearer_map + 19, jiffies + 2500LL);
                            --*((_BYTE *)v17 + 130);
                          }
                          else
                          {
                            *((_BYTE *)bearer_map + 148) = 1;
                            v18 = bearer_map;
                            timer_delete(bearer_map + 19);
                            *((_DWORD *)v18 + 34) = 0;
                            *((_BYTE *)v18 + 130) = 0;
                            ll_send_nl_ack(v18);
                            *((_DWORD *)v18 + 36) = 0;
                          }
                        }
                      }
                      goto LABEL_19;
                    }
                    v14 = 1;
                  }
                  v15 = *((unsigned int *)bearer_map + 15);
                  *((_BYTE *)bearer_map + 128) = v14;
                  if ( (unsigned int)v15 <= 0xF )
                    LOBYTE(v6[2 * v15 + 10]) = v13 != 2;
                  goto LABEL_27;
                }
LABEL_34:
                v19 = -1;
                goto LABEL_54;
              }
            }
          }
        }
      }
    }
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(v1 + 5) & 3) != 0 )
    return 0xFFFFFFFFLL;
  if ( v2 != 26 )
    return 2;
  v11 = *(unsigned int *)(a1 + 112);
  if ( (unsigned int)v11 < 0x10 )
    return 3;
  if ( !*(_BYTE *)(v1 + 15) )
    return 1;
  if ( 4 * (unsigned __int64)*(unsigned __int8 *)(v1 + 15) + 16 > v11 )
    return 3;
  v20 = rmnet_qmap_get_dev(*(_BYTE *)(v1 + 1));
  if ( !v20 )
    return 1;
  v21 = rmnet_get_qos_pt(v20);
  if ( !v21 )
    return 1;
  v22 = (__int64 *)v21;
  v7 = v21 + 332;
  raw_spin_lock_bh(v21 + 332);
  if ( *(_BYTE *)(v1 + 15) )
  {
    v23 = 0;
    v24 = (unsigned __int8 *)(v1 + 17);
    while ( 1 )
    {
      v26 = qmi_rmnet_get_bearer_map(v22, *(v24 - 1));
      if ( v26 )
        break;
LABEL_41:
      ++v23;
      v24 += 4;
      if ( v23 >= *(unsigned __int8 *)(v1 + 15) )
        goto LABEL_53;
    }
    v27 = *v24;
    if ( v27 == 2 )
    {
      v28 = 0;
    }
    else
    {
      if ( v27 != 3 )
      {
LABEL_49:
        if ( *((_DWORD *)v26 + 34) == 2 )
        {
          v30 = *v24;
          *((_BYTE *)v26 + 131) = v30;
          if ( v30 == 4 && *((_BYTE *)v26 + 130) )
          {
            *((_DWORD *)v26 + 34) = 3;
            v31 = v26;
            mod_timer(v26 + 19, jiffies + 2500LL);
            --*((_BYTE *)v31 + 130);
          }
          else
          {
            *((_BYTE *)v26 + 148) = 1;
            v25 = v26;
            timer_delete(v26 + 19);
            *((_DWORD *)v25 + 34) = 0;
            *((_BYTE *)v25 + 130) = 0;
            ll_send_nl_ack(v25);
            *((_DWORD *)v25 + 36) = 0;
          }
        }
        goto LABEL_41;
      }
      v28 = 1;
    }
    v29 = *((unsigned int *)v26 + 15);
    *((_BYTE *)v26 + 128) = v28;
    if ( (unsigned int)v29 <= 0xF )
      LOBYTE(v22[2 * v29 + 10]) = v27 != 2;
    goto LABEL_49;
  }
LABEL_53:
  v19 = 1;
LABEL_54:
  raw_spin_unlock_bh(v7);
  return v19;
}
