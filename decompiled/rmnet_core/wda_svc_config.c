__int64 __fastcall wda_svc_config(__int64 result)
{
  unsigned int *v1; // x19
  __int64 *v2; // x24
  __int64 dlmarker_info; // x0
  int v4; // w20
  __int64 v5; // x21
  _WORD *v6; // x22
  int v7; // w0
  unsigned int v8; // w8
  unsigned int v9; // w10
  int v10; // w8
  int v11; // w23
  __int64 qmi_pt; // x0
  void *v13; // x0
  __int64 v14; // x0
  const char *v15; // x1
  _QWORD v16[10]; // [xsp+0h] [xbp-50h] BYREF

  v1 = (unsigned int *)result;
  v2 = (__int64 *)(result - 16);
  v16[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    result = rtnl_trylock(result);
    if ( (_DWORD)result )
      break;
    if ( v1[90] )
      goto LABEL_33;
  }
  dlmarker_info = rmnet_get_dlmarker_info(*((_QWORD *)v1 - 2));
  v4 = dlmarker_info;
  result = rtnl_unlock(dlmarker_info);
  if ( v1[90] != 1 )
  {
    memset(v16, 0, 72);
    v5 = _kmalloc_cache_noprof(unregister_netdevice_queue, 2336, 16);
    if ( !v5 )
      goto LABEL_32;
    v6 = (_WORD *)_kmalloc_cache_noprof(unregister_netdevice_queue, 2336, 12);
    if ( !v6 )
    {
      kfree(v5);
      goto LABEL_32;
    }
    v7 = qmi_txn_init(v1 + 8, v16, &wda_set_powersave_config_resp_msg_v01_ei, v6);
    if ( v7 < 0 )
    {
      v11 = v7;
      v13 = &unk_2D786;
    }
    else
    {
      v8 = v1[88];
      v9 = v1[89];
      *(_BYTE *)(v5 + 8) = 1;
      *(_DWORD *)v5 = v8;
      *(_DWORD *)(v5 + 4) = v9;
      if ( v4 )
        v10 = 0x7FFFFFFF;
      else
        v10 = 2;
      *(_DWORD *)(v5 + 12) = v10;
      v11 = qmi_send_request(v1 + 8, v1 + 84, v16, 45, 18, &wda_set_powersave_config_req_msg_v01_ei, v5);
      if ( v11 < 0 )
      {
        qmi_txn_cancel(v16);
        v13 = &unk_2CDDC;
      }
      else
      {
        v11 = qmi_txn_wait(v16, 250);
        if ( (v11 & 0x80000000) == 0 )
        {
          if ( *v6 )
          {
            printk(&unk_2CFE0, "wda_set_powersave_config_req");
            v11 = -(unsigned __int16)*v6;
          }
LABEL_16:
          kfree(v6);
          result = kfree(v5);
          if ( (v11 & 0x80000000) == 0 )
          {
            if ( v1[90] != 1 )
            {
              while ( 1 )
              {
                result = rtnl_trylock(result);
                if ( (_DWORD)result )
                  break;
                if ( v1[90] )
                  goto LABEL_33;
              }
              qmi_pt = rmnet_get_qmi_pt(*v2);
              if ( qmi_pt )
              {
                *(_QWORD *)(qmi_pt + 8) = v2;
                *(_QWORD *)(qmi_pt + 16) = 0;
                v14 = trace_wda_client_state_up(v1[87], v1[88], v1[89]);
                rtnl_unlock(v14);
                if ( v4 )
                  v15 = "enabled";
                else
                  v15 = "disabled";
                result = printk(&unk_2CF60, v15);
              }
              else
              {
                result = rtnl_unlock(0);
              }
            }
            goto LABEL_33;
          }
LABEL_32:
          result = printk(&unk_2CD12, "wda_svc_config");
          goto LABEL_33;
        }
        v13 = &unk_2D7B0;
      }
    }
    printk(v13, "wda_set_powersave_config_req");
    goto LABEL_16;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
