__int64 __fastcall rmnet_aps_notifier_cb(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x20
  __int64 v5; // x1
  _DWORD *v6; // x24
  int v7; // w20
  _UNKNOWN **v8; // x25
  int v9; // w8
  __int64 v10; // x1
  _DWORD *v11; // x25
  int v12; // w22
  _UNKNOWN **v13; // x26
  int v14; // w8
  __int64 v15; // x0
  __int64 v17; // [xsp+Ch] [xbp-14h] BYREF
  int v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  if ( *a3 && !strncmp((const char *)(v3 + 296), "rmnet_data", 0xAu) )
  {
    if ( a2 == 6 )
    {
      mutex_lock(&rmnet_aps_mutex);
      v11 = aps_flow_list;
      if ( aps_flow_list != (_UNKNOWN *)&aps_flow_list )
      {
        v12 = *(_DWORD *)(v3 + 224);
        do
        {
          v13 = *(_UNKNOWN ***)v11;
          if ( v11[7] == v12 )
          {
            if ( HIDWORD(aps_client_genl_info) )
            {
              v14 = v11[5];
              v17 = 0x200000005LL;
              v18 = v14;
              if ( (unsigned int)rmnet_aps_send_msg((__int64)&aps_client_genl_info, 1u, 2u, 0xCu, (__int64)&v17, 0x820u) )
                HIDWORD(aps_client_genl_info) = 0;
            }
            rmnet_aps_remove_flow((_QWORD *)v11 - 4, v10);
          }
          v11 = v13;
        }
        while ( v13 != &aps_flow_list );
      }
      v15 = *(_QWORD *)(v3 + 3184);
      if ( v15 )
      {
        if ( *(_QWORD *)(v15 + 16) != v15 + 16 )
          __break(0x800u);
        *(_QWORD *)(v3 + 3184) = 0;
        kvfree_call_rcu(v15, v15);
      }
      goto LABEL_25;
    }
    if ( a2 == 2 )
    {
      *(_BYTE *)(v3 + 3176) = 0;
      mutex_lock(&rmnet_aps_mutex);
      v6 = aps_flow_list;
      if ( aps_flow_list != (_UNKNOWN *)&aps_flow_list )
      {
        v7 = *(_DWORD *)(v3 + 224);
        do
        {
          v8 = *(_UNKNOWN ***)v6;
          if ( v6[7] == v7 )
          {
            if ( HIDWORD(aps_client_genl_info) )
            {
              v9 = v6[5];
              v17 = 0x200000005LL;
              v18 = v9;
              if ( (unsigned int)rmnet_aps_send_msg((__int64)&aps_client_genl_info, 1u, 2u, 0xCu, (__int64)&v17, 0x820u) )
                HIDWORD(aps_client_genl_info) = 0;
            }
            rmnet_aps_remove_flow((_QWORD *)v6 - 4, v5);
          }
          v6 = v8;
        }
        while ( v8 != &aps_flow_list );
      }
LABEL_25:
      mutex_unlock(&rmnet_aps_mutex);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
