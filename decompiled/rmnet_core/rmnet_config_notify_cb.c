__int64 __fastcall rmnet_config_notify_cb(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 result; // x0
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 i; // x22
  __int64 v9; // x8
  _QWORD *v10; // x21
  __int64 v11; // x25
  __int64 *v12; // x26
  __int64 *v13; // x8
  __int64 v14; // x9
  _QWORD *v15; // x8
  _QWORD *v16; // x0
  _QWORD *v17; // x8
  __int64 v18; // x22
  __int64 v19; // x0
  _QWORD *v20; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v21[3]; // [xsp+8h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *a3;
  if ( *a3 )
  {
    if ( a2 == 2 )
    {
      rmnet_vnd_reset_mac_addr();
    }
    else if ( a2 == 6 )
    {
      if ( *(_UNKNOWN **)(result + 2328) == &rmnet_link_ops )
      {
        netdev_rx_handler_unregister(result, 6);
      }
      else
      {
        v20 = nullptr;
        v21[0] = v21;
        v21[1] = v21;
        if ( *(__int64 (__fastcall **)())(result + 264) == rmnet_rx_handler )
        {
          v4 = result;
          if ( !(unsigned int)rtnl_is_locked() && (rmnet_force_unassociate_device___already_done & 1) == 0 )
          {
            rmnet_force_unassociate_device___already_done = 1;
            _warn_printk(
              "RTNL: assertion failed at %s (%d)\n",
              "../vendor/qcom/opensource/datarmnet/core/rmnet_config.c",
              319);
            __break(0x800u);
          }
          v5 = *(_QWORD *)(v4 + 272);
          v6 = qmi_rmnet_qmi_exit(*(_QWORD *)(v5 + 2472), v5);
          if ( *(_BYTE *)(v5 + 13) == 2 )
          {
            v6 = *(_QWORD *)(v5 + 2056);
            v7 = *(_QWORD *)(v6 + 272);
            if ( *(_BYTE *)(v5 + 12) )
            {
              v6 = rmnet_unregister_real_device(v6, v7);
            }
            else
            {
              *(_QWORD *)(v7 + 2056) = 0;
              *(_BYTE *)(v7 + 13) = 1;
            }
          }
          for ( i = 0; i != 255; ++i )
          {
            v9 = *(_QWORD *)(v5 + 16 + 8 * i);
            if ( v9 )
            {
              v10 = (_QWORD *)(v9 - 16);
              if ( v9 != 16 )
              {
                do
                {
                  v12 = v10 + 2;
                  v11 = v10[2];
                  unregister_netdevice_queue(v10[1], v21);
                  v6 = rmnet_vnd_dellink(*(unsigned __int8 *)v10, v5, v10);
                  v13 = (__int64 *)v10[3];
                  if ( v13 )
                  {
                    v14 = *v12;
                    *v13 = *v12;
                    if ( v14 )
                      *(_QWORD *)(v14 + 8) = v13;
                    v10[3] = 0;
                  }
                  v15 = v20;
                  *v12 = (__int64)v20;
                  if ( v15 )
                    v15[1] = v12;
                  v20 = v10 + 2;
                  v10[3] = &v20;
                  if ( !v11 )
                    break;
                  v10 = (_QWORD *)(v11 - 16);
                }
                while ( v11 != 16 );
              }
            }
          }
          synchronize_rcu(v6);
          if ( v20 )
          {
            v16 = v20 - 2;
            if ( v20 != &qword_10 )
            {
              while ( 1 )
              {
                v18 = v16[2];
                v17 = (_QWORD *)v16[3];
                *v17 = v18;
                if ( !v18 )
                  break;
                *(_QWORD *)(v18 + 8) = v17;
                v16[2] = 0xDEAD000000000100LL;
                v16[3] = 0xDEAD000000000122LL;
                kfree(v16);
                v16 = (_QWORD *)(v18 - 16);
                if ( v18 == 16 )
                  goto LABEL_38;
              }
              v16[2] = 0xDEAD000000000100LL;
              v16[3] = 0xDEAD000000000122LL;
              kfree(v16);
            }
          }
LABEL_38:
          v19 = unregister_netdevice_many(v21);
          qmi_rmnet_qos_exit_post(v19);
          rmnet_unregister_real_device(v4, v5);
        }
      }
    }
    else if ( a2 == 5
           && *(_UNKNOWN **)(result + 2328) == &rmnet_link_ops
           && (unsigned int)netdev_rx_handler_register(result, rmnet_rx_priv_handler, 0) )
    {
      result = 32770;
      goto LABEL_40;
    }
    result = 0;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
