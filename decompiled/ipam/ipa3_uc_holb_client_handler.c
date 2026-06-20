void ipa3_uc_holb_client_handler()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x22
  __int64 v3; // x23
  __int64 v4; // x24
  unsigned __int16 *v5; // x28
  __int64 v6; // x8
  __int64 v7; // x0

  if ( *(_BYTE *)(ipa3_ctx + 34904) == 1 )
  {
    v0 = mutex_lock(ipa3_ctx + 43096);
    v1 = ipa3_ctx;
    v2 = *(unsigned int *)(ipa3_ctx + 34912);
    *(_BYTE *)(ipa3_ctx + 34659) = 1;
    if ( (int)v2 < 1 )
    {
LABEL_14:
      mutex_unlock(v1 + 43096);
    }
    else
    {
      v3 = 0;
      v4 = 34932;
      while ( v3 != 31 )
      {
        v5 = (unsigned __int16 *)(ipa3_ctx + v4);
        if ( *(_DWORD *)(ipa3_ctx + v4 + 16) == 1 )
        {
          v0 = ipa3_uc_add_holb_monitor(*v5, *((_DWORD *)v5 + 1), *((_DWORD *)v5 + 2), *((_BYTE *)v5 + 12));
          v6 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v7 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v7 )
            {
              ipc_log_string(
                v7,
                "ipa %s:%d HOLB Client with GSI %d moved to ADD state\n",
                "ipa3_uc_holb_client_handler",
                37,
                *v5);
              v6 = ipa3_ctx;
            }
            v0 = *(_QWORD *)(v6 + 34160);
            if ( v0 )
              v0 = ipc_log_string(
                     v0,
                     "ipa %s:%d HOLB Client with GSI %d moved to ADD state\n",
                     "ipa3_uc_holb_client_handler",
                     37,
                     *v5);
          }
          *((_DWORD *)v5 + 4) = 2;
        }
        ++v3;
        v4 += 272;
        if ( v2 == v3 )
        {
          v1 = ipa3_ctx;
          goto LABEL_14;
        }
      }
      __break(0x5512u);
      ipa3_set_holb_client_by_ch(v0);
    }
  }
}
