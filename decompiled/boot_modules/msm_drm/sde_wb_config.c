__int64 __fastcall sde_wb_config(__int64 a1, int *a2, __int64 a3)
{
  int v6; // w27
  __int64 v7; // x21
  __int64 v8; // x23
  __int64 v9; // x0
  void *v10; // x20
  _UNKNOWN **v11; // x25
  _DWORD *v12; // x8
  __int64 v13; // x8
  unsigned __int64 v14; // x22
  __int64 v15; // x0
  char *v16; // x20
  int v17; // w8
  __int64 v18; // x23
  unsigned int v19; // w0
  void *v20; // x0
  unsigned int v21; // w22
  int v22; // w8
  void *v23; // x0
  __int64 result; // x0
  void *v25; // x0
  unsigned __int64 v26; // x8
  _QWORD v27[16]; // [xsp+60h] [xbp-80h] BYREF

  v27[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    v6 = *a2;
    v7 = (unsigned int)a2[2];
    v8 = *((_QWORD *)a2 + 2);
    v9 = drm_mode_object_find(a1, a3, (unsigned int)a2[1], 3233857728LL);
    if ( !v9 || (v10 = (void *)(v9 - 64), v9 == 64) )
    {
      v25 = &unk_2669B1;
    }
    else
    {
      mutex_lock(&sde_wb_list_lock);
      v11 = &sde_wb_list;
      do
      {
        v11 = (_UNKNOWN **)*v11;
        if ( v11 == &sde_wb_list )
        {
          mutex_unlock(&sde_wb_list_lock);
          goto LABEL_41;
        }
      }
      while ( v11[8] != v10 );
      mutex_unlock(&sde_wb_list_lock);
      if ( v11 != (_UNKNOWN **)&dword_20 )
      {
        mutex_lock(v11 + 2);
        v12 = v11[8];
        if ( v12 && v12[39] == 15 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "\n");
            v13 = _drm_debug & 4;
            if ( (v6 & 1) == 0 )
              goto LABEL_29;
LABEL_15:
            if ( v13 )
              _drm_dev_dbg(0, 0, 0, "connect\n");
            if ( (_DWORD)v7 && v8 )
            {
              v14 = 68 * v7;
              v15 = _kmalloc_noprof(68 * v7, 3520);
              v16 = (char *)v15;
              if ( v15 )
              {
                if ( (unsigned int)v7 >= 0x1E1E1E2 )
                {
                  __break(0x800u);
                }
                else
                {
                  _check_object_size(v15, 68 * v7, 0);
                  if ( !inline_copy_from_user_6((int)v16, v8, 68 * v7) )
                  {
                    v17 = 0;
                    while ( 1 )
                    {
                      v18 = v17;
                      memset(v27, 0, 120);
                      v19 = drm_mode_convert_umode(*(v11 - 4), v27, &v16[68 * v17]);
                      if ( v19 )
                        break;
                      v17 = v18 + 1;
                      if ( (_DWORD)v7 == (_DWORD)v18 + 1 )
                      {
                        v20 = v11[12];
                        if ( v20 )
                        {
                          *((_DWORD *)v11 + 22) = 0;
                          kfree(v20);
                        }
                        v21 = 0;
                        *((_DWORD *)v11 + 22) = v7;
                        v22 = 1;
                        v11[12] = v16;
                        goto LABEL_34;
                      }
                    }
                    v26 = 68 * v18;
                    if ( v14 <= 68 * v18 + 24
                      || v14 <= v26
                      || v14 <= v26 + 4
                      || v14 < v26 + 6
                      || v14 <= v26 + 8
                      || v14 < v26 + 10
                      || v14 < v26 + 14
                      || v14 <= v26 + 16
                      || v14 < v26 + 18
                      || v14 <= v26 + 20
                      || v14 <= v26 + 32
                      || v14 <= v26 + 28
                      || v14 <= v26 + 32
                      || v14 <= v26 + 28 )
                    {
                      __break(1u);
                    }
                    v21 = v19;
                    printk(&unk_2633DD, "sde_wb_connector_set_modes");
                    kfree(v16);
                    goto LABEL_35;
                  }
                }
                printk(&unk_24A536, "sde_wb_connector_set_modes");
                kfree(v16);
                v21 = -14;
              }
              else
              {
                printk(&unk_223EAA, "sde_wb_connector_set_modes");
                v21 = -12;
              }
            }
            else
            {
              printk(&unk_23974B, "sde_wb_connector_set_modes");
              v21 = -22;
            }
          }
          else
          {
            v13 = 0;
            if ( (v6 & 1) != 0 )
              goto LABEL_15;
LABEL_29:
            if ( v13 )
              _drm_dev_dbg(0, 0, 0, "disconnect\n");
            v23 = v11[12];
            if ( v23 )
            {
              *((_DWORD *)v11 + 22) = 0;
              kfree(v23);
              v11[12] = nullptr;
            }
            v21 = 0;
            v22 = 2;
LABEL_34:
            *((_DWORD *)v11 + 20) = v22;
          }
        }
        else
        {
          printk(&unk_223EAA, "sde_wb_connector_set_modes");
          v21 = -22;
        }
LABEL_35:
        mutex_unlock(v11 + 2);
        drm_helper_hpd_irq_event(a1);
        result = v21;
        goto LABEL_36;
      }
LABEL_41:
      v25 = &unk_24A503;
    }
    printk(v25, "sde_wb_config");
    result = 4294967294LL;
  }
  else
  {
    printk(&unk_223EAA, "sde_wb_config");
    result = 4294967274LL;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
