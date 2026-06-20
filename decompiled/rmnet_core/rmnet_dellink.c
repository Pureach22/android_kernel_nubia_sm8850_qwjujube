__int64 __fastcall rmnet_dellink(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int mux; // w0
  __int64 v5; // x8
  unsigned __int8 *v6; // x23
  unsigned int v7; // w22
  __int64 v8; // x8
  _QWORD *v9; // x8
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0

  v1 = *(_QWORD *)(result + 2696);
  if ( v1 && *(__int64 (__fastcall **)())(v1 + 264) == rmnet_rx_handler )
  {
    v2 = *(_QWORD *)(v1 + 272);
    v3 = result;
    mux = rmnet_vnd_get_mux();
    v5 = *(_QWORD *)(v2 + 8LL * (unsigned __int8)mux + 16);
    if ( v5 )
    {
      v6 = (unsigned __int8 *)(v5 - 16);
      if ( v5 != 16 )
      {
        v7 = mux;
        while ( *v6 != (unsigned __int8)mux )
        {
          v8 = *((_QWORD *)v6 + 2);
          if ( v8 )
          {
            v6 = (unsigned __int8 *)(v8 - 16);
            if ( v8 != 16 )
              continue;
          }
          goto LABEL_19;
        }
        v9 = *((_QWORD **)v6 + 3);
        if ( v9 )
        {
          v10 = *((_QWORD *)v6 + 2);
          *v9 = v10;
          if ( v10 )
            *(_QWORD *)(v10 + 8) = v9;
          *((_QWORD *)v6 + 3) = 0;
        }
        synchronize_rcu();
        if ( *(_BYTE *)(v2 + 13) == 2 )
        {
          v11 = *(_QWORD *)(v2 + 2056);
          v12 = *(_QWORD *)(v11 + 272);
          if ( *(_BYTE *)(v2 + 12) )
          {
            rmnet_unregister_real_device(v11, v12);
          }
          else
          {
            *(_QWORD *)(v12 + 2056) = 0;
            *(_BYTE *)(v12 + 13) = 1;
          }
        }
        rmnet_vnd_dellink(v7, v2, v6);
        kfree(v6);
      }
    }
LABEL_19:
    if ( !*(_BYTE *)(v2 + 12) )
      qmi_rmnet_qmi_exit(*(_QWORD *)(v2 + 2472), v2);
    v13 = unregister_netdevice_queue(v3, 0);
    qmi_rmnet_qos_exit_post(v13);
    return rmnet_unregister_real_device(v1, v2);
  }
  return result;
}
