__int64 __fastcall osif_dp_rx_check_qdisc_configured(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x21
  unsigned int v8; // w20
  __int64 v9; // x8
  _DWORD *v10; // x8
  __int64 v11; // x19
  _QWORD *i; // x22
  _QWORD *v13; // x8

  if ( *(_QWORD *)(a1 + 1024) )
  {
    v4 = rtnl_trylock(a1);
    if ( (_DWORD)v4 )
    {
      v5 = *(_QWORD *)(a1 + 1024);
      if ( v5 )
      {
        v6 = *(_QWORD *)(v5 + 8);
        if ( v6 )
        {
          v7 = *(_QWORD *)(v6 + 24);
          v4 = strcmp((const char *)(v7 + 16), "ingress");
          if ( !(_DWORD)v4 )
          {
            v8 = 0;
            goto LABEL_24;
          }
          v4 = strcmp((const char *)(v7 + 16), "clsact");
          if ( !(_DWORD)v4 )
          {
            v9 = *(_QWORD *)(v7 + 8);
            if ( v9 )
            {
              v10 = *(_DWORD **)(v9 + 72);
              if ( v10 )
              {
                if ( *(v10 - 1) != 209989006 )
                  __break(0x8228u);
                v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v6, 65522, 0);
                if ( v4 )
                {
                  v11 = v4;
                  mutex_lock(v4 + 16);
                  for ( i = *(_QWORD **)(v11 + 64); i != (_QWORD *)(v11 + 64); i = (_QWORD *)*i )
                  {
                    mutex_lock(i - 7);
                    v13 = i - 1;
                    while ( 1 )
                    {
                      v13 = (_QWORD *)*v13;
                      if ( !v13 )
                        break;
                      if ( *((_DWORD *)v13 + 7) == a2 << 16 )
                      {
                        mutex_unlock(i - 7);
                        v8 = 0;
                        goto LABEL_23;
                      }
                    }
                    mutex_unlock(i - 7);
                  }
                  v8 = 11;
LABEL_23:
                  v4 = mutex_unlock(v11 + 16);
                  goto LABEL_24;
                }
              }
            }
          }
        }
      }
      v8 = 11;
LABEL_24:
      rtnl_unlock(v4);
      return v8;
    }
    return 3;
  }
  else
  {
    return 11;
  }
}
