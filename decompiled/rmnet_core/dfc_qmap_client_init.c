__int64 __fastcall dfc_qmap_client_init(__int64 a1, unsigned int a2, __int64 *a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x21
  unsigned __int64 v10; // x0
  __int64 v11; // x9
  int v12; // w11
  __int64 v13; // x9
  unsigned int *v14; // x20
  __int64 v15; // x1

  result = 4294967274LL;
  if ( a1 && a4 && !qmap_dfc_data )
  {
    v8 = a1;
    v10 = _kmalloc_cache_noprof(memset, 3520, 440);
    if ( v10 )
    {
      v11 = *a3;
      v12 = *((_DWORD *)a3 + 2);
      *(_QWORD *)v10 = v8;
      *(_DWORD *)(v10 + 428) = a2;
      *(_QWORD *)(v10 + 364) = v11;
      *(_DWORD *)(v10 + 372) = v12;
      if ( a2 >= 2 )
      {
        __break(0x5512u);
        return ((__int64 (*)(void))trace_dfc_client_state_up)();
      }
      else
      {
        v13 = a4 + 8LL * a2;
        v14 = (unsigned int *)v10;
        *(_QWORD *)(v13 + 24) = v10;
        atomic_store(v10, (unsigned __int64 *)&qmap_dfc_data);
        rmnet_qmap_init(v8);
        trace_dfc_client_state_up(v14[107], v14[91], v14[92], v14[93]);
        printk(&unk_2C871, v15);
        if ( *(_DWORD *)(a4 + 76) )
        {
          dfc_config_acked = 1;
        }
        else
        {
          dfc_config_acked = 0;
          dfc_qmap_send_config((__int64)v14);
        }
        return 0;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
