__int64 ipa3_setup_low_lat_rt_rules()
{
  __int64 v0; // x19
  unsigned __int64 v1; // x21
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x9
  int v5; // w8
  int ep_mapping; // w0
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w21
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v22; // x21
  long double (*v23)(_QWORD, const char *, ...); // x0

  v0 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
  if ( v0 )
  {
    while ( 1 )
    {
      *(_BYTE *)(v0 + 40) = 2;
      v1 = 192LL * *(unsigned __int8 *)(v0 + 40);
      v2 = _kmalloc_noprof(v1, 3520);
      v3 = v2;
      *(_QWORD *)(v0 + 56) = v2;
      if ( !v2 )
        break;
      *(_BYTE *)v0 = 1;
      *(_DWORD *)(v0 + 44) = 192;
      *(_DWORD *)(v0 + 4) = 0;
      strcpy((char *)(v0 + 8), "ipa_dflt_wan_rt");
      if ( v1 )
      {
        *(_BYTE *)v2 = 0;
        v4 = rmnet_ipa3_ctx;
        *(_DWORD *)(v2 + 16) = 121;
        v5 = *(_DWORD *)(v4 + 520);
        *(_DWORD *)(v2 + 28) = 0x4000;
        *(_DWORD *)(v2 + 20) = v5;
        *(_DWORD *)(v2 + 52) = ipa_get_ep_mapping(121);
        *(_DWORD *)(v3 + 56) = 255;
        if ( v1 >= 0xC1 )
        {
          *(_BYTE *)(v3 + 192) = 0;
          if ( v1 >= 0xD0 )
          {
            *(_DWORD *)(v3 + 208) = 121;
            if ( v1 >= 0xD4 )
            {
              *(_DWORD *)(v3 + 212) = *(_DWORD *)(rmnet_ipa3_ctx + 520);
              if ( v1 >= 0xDC )
              {
                *(_DWORD *)(v3 + 220) = 0x4000;
                ep_mapping = ipa_get_ep_mapping(121);
                if ( v1 >= 0xF4 )
                {
                  *(_DWORD *)(v3 + 244) = ep_mapping;
                  if ( v1 >= 0xF8 )
                  {
                    v7 = *(_DWORD *)(v3 + 220);
                    *(_DWORD *)(v3 + 248) = 255;
                    *(_DWORD *)(v3 + 220) = v7 | 2;
                    if ( v1 >= 0x119 )
                    {
                      *(_BYTE *)(v3 + 281) = 1;
                      if ( (unsigned int)ipa3_add_rt_rule_ext_v2(v0, 0) )
                      {
                        printk(&unk_3E79BD, "ipa3_setup_low_lat_rt_rules");
                        if ( ipa3_get_ipc_logbuf() )
                        {
                          ipc_logbuf = ipa3_get_ipc_logbuf();
                          ipc_log_string(
                            ipc_logbuf,
                            "ipa-wan %s:%d fail to add low lat v4 rule\n",
                            "ipa3_setup_low_lat_rt_rules",
                            631);
                        }
                        if ( ipa3_get_ipc_logbuf_low() )
                        {
                          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
                          ipc_log_string(
                            ipc_logbuf_low,
                            "ipa-wan %s:%d fail to add low lat v4 rule\n",
                            "ipa3_setup_low_lat_rt_rules",
                            631);
                        }
                        goto LABEL_40;
                      }
                      if ( ipa3_get_ipc_logbuf() )
                      {
                        v8 = ipa3_get_ipc_logbuf();
                        ipc_log_string(
                          v8,
                          "ipa-wan %s:%d low lat v4 rt rule hdl[WAN_RT_COMMON]=%x\n",
                          "ipa3_setup_low_lat_rt_rules",
                          636,
                          *(_DWORD *)(v3 + 4));
                      }
                      if ( ipa3_get_ipc_logbuf_low() )
                      {
                        v9 = ipa3_get_ipc_logbuf_low();
                        ipc_log_string(
                          v9,
                          "ipa-wan %s:%d low lat v4 rt rule hdl[WAN_RT_COMMON]=%x\n",
                          "ipa3_setup_low_lat_rt_rules",
                          636,
                          *(_DWORD *)(v3 + 4));
                      }
                      *(_DWORD *)(rmnet_ipa3_ctx + 540) = *(_DWORD *)(v3 + 4);
                      if ( ipa3_get_ipc_logbuf() )
                      {
                        v10 = ipa3_get_ipc_logbuf();
                        ipc_log_string(
                          v10,
                          "ipa-wan %s:%d low lat v4 rt rule hdl[WAN_RT_ICMP]=%x\n",
                          "ipa3_setup_low_lat_rt_rules",
                          640,
                          *(_DWORD *)(v3 + 196));
                      }
                      if ( ipa3_get_ipc_logbuf_low() )
                      {
                        v11 = ipa3_get_ipc_logbuf_low();
                        ipc_log_string(
                          v11,
                          "ipa-wan %s:%d low lat v4 rt rule hdl[WAN_RT_ICMP]=%x\n",
                          "ipa3_setup_low_lat_rt_rules",
                          640,
                          *(_DWORD *)(v3 + 196));
                      }
                      *(_DWORD *)(rmnet_ipa3_ctx + 544) = *(_DWORD *)(v3 + 196);
                      *(_DWORD *)(v0 + 4) = 1;
                      *(_DWORD *)(v3 + 220) = 24576;
                      if ( v1 >= 0x120 )
                      {
                        *(_BYTE *)(v3 + 288) = 1;
                        if ( !(unsigned int)ipa3_add_rt_rule_ext_v2(v0, 0) )
                        {
                          if ( ipa3_get_ipc_logbuf() )
                          {
                            v12 = ipa3_get_ipc_logbuf();
                            ipc_log_string(
                              v12,
                              "ipa-wan %s:%d low lat v6 rt rule hdl[WAN_RT_COMMON]=%x\n",
                              "ipa3_setup_low_lat_rt_rules",
                              657,
                              *(_DWORD *)(v3 + 4));
                          }
                          if ( ipa3_get_ipc_logbuf_low() )
                          {
                            v13 = ipa3_get_ipc_logbuf_low();
                            ipc_log_string(
                              v13,
                              "ipa-wan %s:%d low lat v6 rt rule hdl[WAN_RT_COMMON]=%x\n",
                              "ipa3_setup_low_lat_rt_rules",
                              657,
                              *(_DWORD *)(v3 + 4));
                          }
                          *(_DWORD *)(rmnet_ipa3_ctx + 548) = *(_DWORD *)(v3 + 4);
                          if ( ipa3_get_ipc_logbuf() )
                          {
                            v14 = ipa3_get_ipc_logbuf();
                            ipc_log_string(
                              v14,
                              "ipa-wan %s:%d low lat v6 rt rule hdl[WAN_RT_ICMP]=%x\n",
                              "ipa3_setup_low_lat_rt_rules",
                              661,
                              *(_DWORD *)(v3 + 196));
                          }
                          if ( ipa3_get_ipc_logbuf_low() )
                          {
                            v15 = ipa3_get_ipc_logbuf_low();
                            ipc_log_string(
                              v15,
                              "ipa-wan %s:%d low lat v6 rt rule hdl[WAN_RT_ICMP]=%x\n",
                              "ipa3_setup_low_lat_rt_rules",
                              661,
                              *(_DWORD *)(v3 + 196));
                          }
                          v16 = 0;
                          *(_DWORD *)(rmnet_ipa3_ctx + 552) = *(_DWORD *)(v3 + 196);
                          goto LABEL_31;
                        }
                        printk(&unk_3C2243, "ipa3_setup_low_lat_rt_rules");
                        if ( ipa3_get_ipc_logbuf() )
                        {
                          v19 = ipa3_get_ipc_logbuf();
                          ipc_log_string(
                            v19,
                            "ipa-wan %s:%d fail to add low lat v6 rule\n",
                            "ipa3_setup_low_lat_rt_rules",
                            652);
                        }
                        if ( ipa3_get_ipc_logbuf_low() )
                        {
                          v20 = ipa3_get_ipc_logbuf_low();
                          ipc_log_string(
                            v20,
                            "ipa-wan %s:%d fail to add low lat v6 rule\n",
                            "ipa3_setup_low_lat_rt_rules",
                            652);
                        }
LABEL_40:
                        v16 = -1;
LABEL_31:
                        kfree(*(_QWORD *)(v0 + 56));
                        goto LABEL_44;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v22 = *(_QWORD *)(StatusReg + 80);
      v23 = ipc_log_string;
      *(_QWORD *)(StatusReg + 80) = &ipa3_setup_low_lat_rt_rules__alloc_tag;
      v0 = _kmalloc_cache_noprof(v23, 3520, 64);
      *(_QWORD *)(StatusReg + 80) = v22;
      if ( !v0 )
        return (unsigned int)-12;
    }
    v16 = -12;
LABEL_44:
    kfree(v0);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v16;
}
