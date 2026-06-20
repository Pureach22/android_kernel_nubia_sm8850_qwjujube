__int64 __fastcall icnss_genl_send_msg(__int64 a1, unsigned __int8 a2, const char *a3, unsigned int a4)
{
  char *v4; // x25
  int v7; // w24
  unsigned int v8; // w23
  unsigned int v9; // w9
  unsigned int v10; // w27
  int v11; // w21
  char v12; // w8
  unsigned int v13; // w26
  char v14; // w22
  __int64 v15; // x0
  size_t v16; // x0
  unsigned __int64 v17; // x2
  size_t v18; // x0
  __int64 v19; // x0
  _DWORD *v20; // x28
  char *v21; // x21
  __int64 v22; // x0
  __int64 v23; // x25
  unsigned int v24; // w0
  __int64 v25; // x3
  __int64 v26; // x0
  unsigned int v28; // [xsp+4h] [xbp-3Ch]
  int v29; // [xsp+8h] [xbp-38h]
  unsigned int v32; // [xsp+1Ch] [xbp-24h] BYREF
  char string[8]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v34; // [xsp+28h] [xbp-18h]
  char v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v4 = "eq %d\n";
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_string(icnss_ipc_log_context, "cnss_genl: type: %u, total_size: %x\n", a2, a4);
  if ( a4 )
  {
    v7 = 0;
    v8 = 0;
    v9 = a4;
    while ( 2 )
    {
      if ( v9 >= 0x3C00 )
        v10 = 15360;
      else
        v10 = v9;
      if ( v9 <= 0x3C00 )
        v7 = 1;
      v28 = v9;
      v29 = v7;
      v11 = (((_WORD)v10 + 7) & 0x7FFC) + 63;
      v12 = 1;
      while ( 1 )
      {
        v14 = v12;
        v15 = *((_QWORD *)v4 + 54);
        v35 = 0;
        *(_QWORD *)string = 0;
        v34 = 0;
        ipc_log_string(
          v15,
          "cnss_genl: type: %u, file_name %s, total_size: %x, seg_id %u, end %u, data_len %u\n",
          a2,
          a3,
          a4,
          v8,
          (unsigned __int8)v7,
          v10);
        if ( a3 )
        {
          v16 = strnlen(a3, 0x11u);
          if ( v16 == -1 )
            goto LABEL_47;
          if ( v16 == 17 )
            v17 = 17;
          else
            v17 = v16 + 1;
          if ( v17 >= 0x12 )
            goto LABEL_46;
          sized_strscpy(string, a3);
        }
        else
        {
          strcpy(string, "default");
        }
        v18 = strnlen(string, 0x11u);
        if ( v18 >= 0x12 )
          goto LABEL_45;
        if ( v18 == 17 )
        {
LABEL_44:
          v18 = _fortify_panic(4, 17, v18 + 1);
LABEL_45:
          _fortify_panic(2, 17, v18 + 1);
LABEL_46:
          v16 = _fortify_panic(7, 17, v17);
LABEL_47:
          _fortify_panic(2, -1, v16 + 1);
        }
        v19 = _alloc_skb((((v11 + (((_BYTE)v18 + 8) & 0x3C)) & 0x1FFFC) + 19) & 0x3FFFC, 3264, 0, 0xFFFFFFFFLL);
        if ( v19 )
          break;
        v13 = -12;
LABEL_11:
        msleep(100);
        v12 = 0;
        if ( (v14 & 1) == 0 )
        {
          printk("%scnss_genl: fail to send genl data, ret %d\n", byte_130B32, v13);
          ipc_log_string(
            *((_QWORD *)v4 + 54),
            "%scnss_genl: fail to send genl data, ret %d\n",
            (const char *)&unk_12DBF3,
            v13);
          goto LABEL_42;
        }
      }
      v20 = (_DWORD *)v19;
      v21 = v4;
      v22 = genlmsg_put(v19, 0, 0, &icnss_genl_family, 0, 1);
      if ( v22 )
      {
        v23 = v22;
        LOBYTE(v32) = a2;
        v24 = nla_put(v20, 1, 1, &v32);
        if ( (v24 & 0x80000000) == 0 )
        {
          v18 = strnlen(string, 0x11u);
          if ( v18 >= 0x12 )
            goto LABEL_45;
          if ( v18 == 17 )
            goto LABEL_44;
          v24 = nla_put(v20, 2, (unsigned int)(v18 + 1), string);
          if ( (v24 & 0x80000000) == 0 )
          {
            v32 = a4;
            v24 = nla_put(v20, 3, 4, &v32);
            if ( (v24 & 0x80000000) == 0 )
            {
              v32 = v8;
              v24 = nla_put(v20, 4, 4, &v32);
              if ( (v24 & 0x80000000) == 0 )
              {
                LOBYTE(v32) = v7;
                v24 = nla_put(v20, 5, 1, &v32);
                if ( (v24 & 0x80000000) == 0 )
                {
                  v32 = v10;
                  v24 = nla_put(v20, 6, 4, &v32);
                  if ( (v24 & 0x80000000) == 0 )
                  {
                    v24 = nla_put(v20, 7, v10, a1);
                    if ( (v24 & 0x80000000) == 0 )
                    {
                      *(_DWORD *)(v23 - 20) = v20[54] + v20[52] - (v23 - 20);
                      if ( byte_EA8 )
                      {
                        v25 = (unsigned int)dword_F1C;
                        v26 = thermal_cooling_device_unregister;
                        v20[14] = dword_F1C;
                        v13 = netlink_broadcast_filtered(v26, v20, 0, v25, 3264, 0, 0);
                        v4 = v21;
                        if ( (v13 & 0x80000000) == 0 )
                        {
                          ++v8;
                          v9 = v28 - v10;
                          a1 += v10;
                          if ( v28 == v10 )
                            goto LABEL_41;
                          continue;
                        }
                      }
                      else
                      {
                        __break(0x800u);
                        v13 = -22;
                        v4 = v21;
                      }
                      printk("%scnss_genl: Fail to send genl msg: %d\n", byte_130B32, v13);
                      ipc_log_string(
                        *((_QWORD *)v4 + 54),
                        "%scnss_genl: Fail to send genl msg: %d\n",
                        (const char *)&unk_12DBF3,
                        v13);
                      goto LABEL_38;
                    }
                  }
                }
              }
            }
          }
        }
        v13 = v24;
      }
      else
      {
        v13 = -12;
      }
      break;
    }
    printk("%scnss_genl: Fail to generate genl msg: %d\n", byte_130B32, v13);
    v4 = v21;
    ipc_log_string(
      *((_QWORD *)v21 + 54),
      "%scnss_genl: Fail to generate genl msg: %d\n",
      (const char *)&unk_12DBF3,
      v13);
    sk_skb_reason_drop(0, v20, 2);
    v7 = v29;
LABEL_38:
    v11 = (((_WORD)v10 + 7) & 0x7FFC) + 63;
    goto LABEL_11;
  }
LABEL_41:
  v13 = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v13;
}
