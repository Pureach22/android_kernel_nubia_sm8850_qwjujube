__int64 __fastcall wcd9378_sys_usage_auto_udpate(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x22
  unsigned __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned int v12; // w20
  unsigned __int64 v15; // x10
  unsigned __int64 v22; // x10

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  mutex_lock(v6 + 232);
  _X9 = a2 >> 6;
  v8 = v6 + 16;
  v9 = 1LL << a2;
  if ( (a3 & 1) != 0 )
  {
    while ( 1 )
    {
      _X9 = v8 + 8 * _X9;
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v15 = __ldxr((unsigned __int64 *)_X9);
        v8 = v15 | v9;
      }
      while ( __stxr(v8, (unsigned __int64 *)_X9) );
      v9 = *(unsigned int *)(v6 + 8);
      if ( (unsigned int)v9 < 0xD )
        break;
      __break(0x5512u);
    }
    v10 = sys_usage[v9];
    v11 = *(_QWORD *)(v6 + 16);
    if ( (v11 & ~v10) != 0 )
    {
      if ( (v11 & 0xFFFFFFFFFFFFF36ALL) != 0 )
      {
        if ( (v11 & 0xFFFFFFFFFFFFED58LL) != 0 )
        {
          if ( (v11 & 0xFFFFFFFFFFFFF366LL) != 0 )
          {
            if ( (v11 & 0xFFFFFFFFFFFFE554LL) != 0 )
            {
              if ( (v11 & 0xFFFFFFFFFFFFF76BLL) != 0 )
              {
                if ( (v11 & 0xFFFFFFFFFFFFEE59LL) != 0 )
                {
                  if ( (v11 & 0xFFFFFFFFFFFFF767LL) != 0 )
                  {
                    if ( (v11 & 0xFFFFFFFFFFFFEE54LL) != 0 )
                    {
                      if ( (v11 & 0xFFFFFFFFFFFFED95LL) != 0 )
                      {
                        if ( (v11 & 0xFFFFFFFFFFFFEE94LL) != 0 )
                        {
                          if ( (v11 & 0xFFFFFFFFFFFFE358LL) != 0 )
                          {
                            if ( (v11 & 0xFFFFFFFFFFFFEE6ALL) != 0 )
                            {
                              if ( (v11 & 0xFFFFFFFFFFFFED69LL) != 0 )
                              {
                                dev_err(
                                  *(_QWORD *)(a1 + 24),
                                  "%s: cannot find sys_usage\n",
                                  "wcd9378_sys_usage_auto_udpate");
                                return mutex_unlock(v6 + 232);
                              }
                              v12 = 12;
                            }
                            else
                            {
                              v12 = 11;
                            }
                          }
                          else
                          {
                            v12 = 10;
                          }
                        }
                        else
                        {
                          v12 = 9;
                        }
                      }
                      else
                      {
                        v12 = 8;
                      }
                    }
                    else
                    {
                      v12 = 7;
                    }
                  }
                  else
                  {
                    v12 = 6;
                  }
                }
                else
                {
                  v12 = 5;
                }
              }
              else
              {
                v12 = 4;
              }
            }
            else
            {
              v12 = 3;
            }
          }
          else
          {
            v12 = 2;
          }
        }
        else
        {
          v12 = 1;
        }
      }
      else
      {
        v12 = 0;
      }
      snd_soc_component_update_bits(a1, 1075315969, 15, v12);
      *(_DWORD *)(v6 + 8) = v12;
    }
  }
  else
  {
    _X9 = (unsigned __int64 *)(v8 + 8 * _X9);
    __asm { PRFM            #0x11, [X9] }
    do
      v22 = __ldxr(_X9);
    while ( __stxr(v22 & ~v9, _X9) );
  }
  return mutex_unlock(v6 + 232);
}
