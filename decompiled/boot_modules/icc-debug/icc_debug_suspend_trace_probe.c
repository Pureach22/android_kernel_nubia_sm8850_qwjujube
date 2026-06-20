void __fastcall icc_debug_suspend_trace_probe(__int64 a1, const char *a2, int a3, char a4)
{
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  _UNKNOWN **v13; // x22
  _QWORD *v14; // x23
  __int64 *v15; // x23
  __int64 *i; // x24
  __int64 *v17; // t1
  __int64 *j; // x25
  __int64 *v19; // x8
  __int64 v20; // x1

  if ( a3 >= 1 && (a4 & 1) != 0 && !strcmp("machine_suspend", a2) )
  {
    printk(&unk_6706, v4, v5, v6);
    printk(&unk_6627, v7, v8, v9);
    printk(&unk_6725, v10, v11, v12);
    v13 = (_UNKNOWN **)icc_providers;
    if ( icc_providers != (_UNKNOWN *)&icc_providers )
    {
      do
      {
        v14 = v13[2];
        v17 = (__int64 *)v14[2];
        v15 = v14 + 2;
        for ( i = v17; i != v15; i = (__int64 *)*i )
        {
          if ( i[7] )
          {
            printk(&unk_65EB, *(i - 4), *((unsigned int *)i + 14), *((unsigned int *)i + 15));
            for ( j = (__int64 *)i[6]; j; j = (__int64 *)*j )
            {
              while ( 1 )
              {
                v19 = (__int64 *)j[3];
                if ( v19 )
                {
                  if ( *((_BYTE *)j + 32) == 1 && j[5] )
                    break;
                }
                j = (__int64 *)*j;
                if ( !j )
                  goto LABEL_9;
              }
              v20 = v19[14];
              if ( !v20 )
                v20 = *v19;
              printk(&unk_660D, v20, *((unsigned int *)j + 9), *((unsigned int *)j + 10));
            }
          }
LABEL_9:
          ;
        }
        v13 = (_UNKNOWN **)*v13;
      }
      while ( v13 != &icc_providers );
    }
  }
}
