__int64 *__fastcall hif_ce_stop(__int64 a1)
{
  __int64 v1; // x25
  __int64 *result; // x0
  __int64 v4; // d0
  __int64 v5; // d6
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // x9
  int v19; // w8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x20
  __int64 v22; // x21

  result = (__int64 *)hif_disable_isr();
  v6 = *(_DWORD *)(a1 + 656);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 480);
    if ( v7 )
    {
      result = (__int64 *)cancel_work_sync(v7 + 24);
      v6 = *(_DWORD *)(a1 + 656);
    }
    if ( v6 >= 2 )
    {
      v8 = *(_QWORD *)(a1 + 488);
      if ( v8 )
      {
        result = (__int64 *)cancel_work_sync(v8 + 24);
        v6 = *(_DWORD *)(a1 + 656);
      }
      if ( v6 >= 3 )
      {
        v9 = *(_QWORD *)(a1 + 496);
        if ( v9 )
        {
          result = (__int64 *)cancel_work_sync(v9 + 24);
          v6 = *(_DWORD *)(a1 + 656);
        }
        if ( v6 >= 4 )
        {
          v10 = *(_QWORD *)(a1 + 504);
          if ( v10 )
          {
            result = (__int64 *)cancel_work_sync(v10 + 24);
            v6 = *(_DWORD *)(a1 + 656);
          }
          if ( v6 >= 5 )
          {
            v11 = *(_QWORD *)(a1 + 512);
            if ( v11 )
            {
              result = (__int64 *)cancel_work_sync(v11 + 24);
              v6 = *(_DWORD *)(a1 + 656);
            }
            if ( v6 >= 6 )
            {
              v12 = *(_QWORD *)(a1 + 520);
              if ( v12 )
              {
                result = (__int64 *)cancel_work_sync(v12 + 24);
                v6 = *(_DWORD *)(a1 + 656);
              }
              if ( v6 >= 7 )
              {
                v13 = *(_QWORD *)(a1 + 528);
                if ( v13 )
                {
                  result = (__int64 *)cancel_work_sync(v13 + 24);
                  v6 = *(_DWORD *)(a1 + 656);
                }
                if ( v6 >= 8 )
                {
                  v14 = *(_QWORD *)(a1 + 536);
                  if ( v14 )
                  {
                    result = (__int64 *)cancel_work_sync(v14 + 24);
                    v6 = *(_DWORD *)(a1 + 656);
                  }
                  if ( v6 >= 9 )
                  {
                    v15 = *(_QWORD *)(a1 + 544);
                    if ( v15 )
                    {
                      result = (__int64 *)cancel_work_sync(v15 + 24);
                      v6 = *(_DWORD *)(a1 + 656);
                    }
                    if ( v6 >= 0xA )
                    {
                      v16 = *(_QWORD *)(a1 + 552);
                      if ( v16 )
                      {
                        result = (__int64 *)cancel_work_sync(v16 + 24);
                        v6 = *(_DWORD *)(a1 + 656);
                      }
                      if ( v6 >= 0xB )
                      {
                        v17 = *(_QWORD *)(a1 + 560);
                        if ( v17 )
                        {
                          result = (__int64 *)cancel_work_sync(v17 + 24);
                          v6 = *(_DWORD *)(a1 + 656);
                        }
                        if ( v6 >= 0xC )
                        {
                          v18 = *(_QWORD *)(a1 + 568);
                          if ( v18 )
                          {
                            result = (__int64 *)cancel_work_sync(v18 + 24);
                            v6 = *(_DWORD *)(a1 + 656);
                          }
                          if ( v6 > 0xC )
                          {
LABEL_49:
                            __break(0x5512u);
                            *(_QWORD *)(v1 + 392) = v5;
                            *(_QWORD *)(v1 + 400) = v4;
                            return (__int64 *)hif_preare_shadow_register_cfg_v3(result);
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
  *(_DWORD *)(a1 + 680) = 0;
  v19 = *(unsigned __int8 *)(a1 + 736);
  *(_BYTE *)(a1 + 584) = 0;
  if ( v19 == 1 )
  {
    athdiag_procfs_remove();
    *(_BYTE *)(a1 + 736) = 0;
  }
  result = (__int64 *)hif_buffer_cleanup(a1);
  v20 = *(unsigned int *)(a1 + 656);
  if ( (_DWORD)v20 )
  {
    v21 = 0;
    v22 = a1 + 27416;
    while ( v21 != 13 )
    {
      result = *(__int64 **)v22;
      if ( *(_QWORD *)v22 )
      {
        result = (__int64 *)ce_fini(result);
        *(_QWORD *)v22 = 0;
        *(_QWORD *)(v22 + 32) = 0;
        v20 = *(unsigned int *)(a1 + 656);
      }
      ++v21;
      v22 += 136;
      if ( v21 >= v20 )
        goto LABEL_46;
    }
    goto LABEL_49;
  }
LABEL_46:
  if ( *(_BYTE *)(a1 + 27368) == 1 )
  {
    timer_delete((timer_t)(a1 + 27312));
    result = (__int64 *)timer_delete_sync(a1 + 27312);
    *(_BYTE *)(a1 + 27368) = 0;
  }
  *(_BYTE *)(a1 + 26440) = 0;
  return result;
}
