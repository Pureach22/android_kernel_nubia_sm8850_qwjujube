__int64 __fastcall vx_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x8
  unsigned __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x28
  int v8; // w27
  __int64 v9; // x23
  _QWORD *v10; // x20
  _QWORD *v11; // x25
  __int64 v12; // x24
  __int64 v13; // x26
  int v14; // w8
  __int64 v15; // x22
  __int64 v16; // x19
  __int64 *v17; // x20
  __int64 v18; // t1
  __int64 v20; // [xsp+0h] [xbp-90h]
  _BYTE v21[4]; // [xsp+Ch] [xbp-84h] BYREF
  __int64 v22; // [xsp+10h] [xbp-80h] BYREF
  __int64 v23; // [xsp+18h] [xbp-78h]
  __int64 v24; // [xsp+20h] [xbp-70h]
  _QWORD v25[13]; // [xsp+28h] [xbp-68h] BYREF

  v25[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 120) == 1 )
  {
    v21[0] = 0;
    v2 = ktime_get_with_offset(1);
    v3 = *(_QWORD *)(v1 + 104);
    *(_QWORD *)(v1 + 112) = v2;
    v4 = (unsigned __int128)((v2 - v3) * (__int128)0x431BDE82D7B634DBLL) >> 64;
    if ( (__int64)((v4 >> 18) + ((unsigned __int64)v4 >> 63)) > *(unsigned int *)(v1 + 124) )
    {
      if ( (has_system_slept(v21) & 1) != 0 )
        goto LABEL_35;
      if ( v21[0] == 1 )
        *(_DWORD *)(v1 + 132) = 2;
      if ( (has_subsystem_slept() & 1) == 0 )
      {
LABEL_35:
        if ( *(_DWORD *)(v1 + 132) )
        {
          *(_DWORD *)(v1 + 132) = 0;
          sys_pm_vx_send_msg(v1);
        }
      }
      else if ( *(_DWORD *)(v1 + 132) )
      {
        v23 = 0;
        v24 = 0;
        v22 = 0;
        if ( (unsigned int)read_vx_data((unsigned __int64 *)v1, (unsigned __int64)&v22) )
        {
          printk(&unk_7480, "vx_check_drv");
        }
        else
        {
          v5 = *(_QWORD *)(v1 + 16);
          if ( v5 )
          {
            v6 = (unsigned int)v24;
            v7 = 0;
            v8 = 0;
            v9 = (unsigned int)(v24 - 1);
            v10 = (_QWORD *)(v23 + 8);
            v20 = v23;
            do
            {
              v11 = v10;
              v12 = v9;
              v13 = v6;
              if ( (int)v6 >= 1 )
              {
                do
                {
                  if ( !*(_DWORD *)(*v11 + 4 * v7) )
                    break;
                  if ( !v12 )
                  {
                    printk(&unk_77F4, "vx_check_drv");
                    v14 = *(unsigned __int8 *)(v1 + 136);
                    memset(v25, 0, 96);
                    if ( v14 == 1 )
                    {
                      mutex_lock(v1 + 48);
                      scnprintf(v25, 96, "{class: misc_debug, res: do_crash_dump, tmr: %d}", *(_DWORD *)(v1 + 128));
                      if ( (unsigned int)qmp_send(*(_QWORD *)(v1 + 96), v25, 96) )
                        printk(&unk_73E8, "trigger_dump");
                      mutex_unlock(v1 + 48);
                    }
                  }
                  --v13;
                  --v12;
                  v11 += 2;
                }
                while ( v13 );
                v5 = *(_QWORD *)(v1 + 16);
              }
              v7 = ++v8;
            }
            while ( v5 > v8 );
            v15 = v20;
          }
          else
          {
            LODWORD(v6) = v24;
            v15 = v23;
          }
          if ( (int)v6 >= 1 )
          {
            v16 = (unsigned int)v6;
            v17 = (__int64 *)(v15 + 8);
            do
            {
              v18 = *v17;
              v17 += 2;
              kfree(v18);
              --v16;
            }
            while ( v16 );
          }
          kfree(v15);
        }
      }
      else
      {
        *(_DWORD *)(v1 + 132) = 1;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
