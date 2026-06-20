__int64 __fastcall aw22xxx_para_store(__int64 a1, __int64 a2, const char *a3, _DWORD *a4)
{
  __int64 v6; // x1
  _DWORD *v7; // x20
  const char *v8; // x0
  int v10; // w9
  __int64 v11; // x11
  __int64 v12; // x13
  __int64 v13; // x11
  unsigned __int64 StatusReg; // x21
  __int64 v15; // x19
  size_t (*v16)(const char *); // x0
  _DWORD *v17; // [xsp+100h] [xbp-10h]

  printk(&unk_12EEC, "aw22xxx_para_store");
  v7 = (_DWORD *)_kmalloc_cache_noprof(strlen, 3264, 100);
  if ( v7 )
  {
    while ( 1 )
    {
      v8 = a3;
      a3 = (const char *)(v7 + 18);
      v17 = a4;
      a4 = v7 + 6;
      if ( sscanf(
             v8,
             "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",
             v7,
             v7 + 1,
             v7 + 2,
             v7 + 3,
             v7 + 4,
             v7 + 5,
             v7 + 6,
             v7 + 7,
             v7 + 8,
             v7 + 9,
             v7 + 10,
             v7 + 11,
             v7 + 12,
             v7 + 13,
             v7 + 14,
             v7 + 15,
             v7 + 16,
             v7 + 17,
             v7 + 18,
             v7 + 19,
             v7 + 20,
             v7 + 21,
             v7 + 22,
             v7 + 23,
             v7 + 24) != 25 )
        break;
      printk(&unk_13217, "aw22xxx_para_store");
      v10 = write_idx;
      if ( (unsigned int)write_idx > 0x3E7 )
      {
        printk(&unk_13674, "aw22xxx_para_store");
        break;
      }
      v11 = 25LL * (unsigned int)write_idx;
      user_para_data[v11] = *v7;
      if ( 25 * v10 != 24999 )
      {
        user_para_data[25 * v10 + 1] = v7[1];
        if ( (_DWORD)v11 != 24998 )
        {
          user_para_data[(unsigned int)v11 + 2] = v7[2];
          if ( (_DWORD)v11 != 24997 )
          {
            user_para_data[(unsigned int)v11 + 3] = v7[3];
            if ( (_DWORD)v11 != 24996 )
            {
              user_para_data[(unsigned int)v11 + 4] = v7[4];
              if ( (_DWORD)v11 != 24995 )
              {
                user_para_data[(unsigned int)v11 + 5] = v7[5];
                if ( (_DWORD)v11 != 24994 )
                {
                  user_para_data[(unsigned int)v11 + 6] = v7[6];
                  if ( (_DWORD)v11 != 24993 )
                  {
                    user_para_data[(unsigned int)v11 + 7] = v7[7];
                    if ( (_DWORD)v11 != 24992 )
                    {
                      user_para_data[(unsigned int)v11 + 8] = v7[8];
                      if ( (_DWORD)v11 != 24991 )
                      {
                        user_para_data[(unsigned int)v11 + 9] = v7[9];
                        if ( (_DWORD)v11 != 24990 )
                        {
                          user_para_data[(unsigned int)v11 + 10] = v7[10];
                          if ( (_DWORD)v11 != 24989 )
                          {
                            user_para_data[(unsigned int)v11 + 11] = v7[11];
                            if ( (_DWORD)v11 != 24988 )
                            {
                              user_para_data[(unsigned int)v11 + 12] = v7[12];
                              if ( (_DWORD)v11 != 24987 )
                              {
                                user_para_data[(unsigned int)v11 + 13] = v7[13];
                                if ( (_DWORD)v11 != 24986 )
                                {
                                  user_para_data[(unsigned int)v11 + 14] = v7[14];
                                  if ( (_DWORD)v11 != 24985 )
                                  {
                                    user_para_data[(unsigned int)v11 + 15] = v7[15];
                                    if ( (_DWORD)v11 != 24984 )
                                    {
                                      user_para_data[(unsigned int)v11 + 16] = v7[16];
                                      if ( (_DWORD)v11 != 24983 )
                                      {
                                        user_para_data[(unsigned int)v11 + 17] = v7[17];
                                        if ( (_DWORD)v11 != 24982 )
                                        {
                                          user_para_data[(unsigned int)v11 + 18] = *(_DWORD *)a3;
                                          if ( (_DWORD)v11 != 24981 )
                                          {
                                            user_para_data[(unsigned int)v11 + 19] = v7[19];
                                            if ( (_DWORD)v11 != 24980 )
                                            {
                                              user_para_data[(unsigned int)v11 + 20] = v7[20];
                                              if ( (_DWORD)v11 != 24979 )
                                              {
                                                user_para_data[(unsigned int)v11 + 21] = v7[21];
                                                if ( (_DWORD)v11 != 24978 )
                                                {
                                                  v12 = (unsigned int)v11 + 23LL;
                                                  user_para_data[(unsigned int)v11 + 22] = v7[22];
                                                  if ( (_DWORD)v11 != 24977 )
                                                  {
                                                    v13 = (unsigned int)v11 + 24LL;
                                                    user_para_data[v12] = v7[23];
                                                    if ( (_DWORD)v13 != 25000 )
                                                    {
                                                      user_para_data[v13] = v7[24];
                                                      write_idx = v10 + 1;
                                                      printk(&unk_138F3, "aw22xxx_para_store");
                                                      break;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
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
      v15 = *(_QWORD *)(StatusReg + 80);
      v16 = strlen;
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v7 = (_DWORD *)_kmalloc_cache_noprof(v16, 3264, 100);
      *(_QWORD *)(StatusReg + 80) = v15;
      if ( !v7 )
        goto LABEL_33;
    }
    kfree(v7);
    return (__int64)v17;
  }
  else
  {
LABEL_33:
    printk(&unk_13200, v6);
    return -14;
  }
}
