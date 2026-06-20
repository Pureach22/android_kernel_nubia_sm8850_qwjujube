__int64 __fastcall msm_vidc_dma_buf_put(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  __int64 *v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 v7; // x0

  if ( a2 )
  {
    v2 = result + 3992;
    while ( 1 )
    {
      v2 = *(_QWORD *)v2;
      if ( v2 == result + 3992 )
        break;
      if ( *(_QWORD *)(v2 + 16) == a2 )
      {
        v3 = *(_DWORD *)(v2 + 24) - 1;
        *(_DWORD *)(v2 + 24) = v3;
        if ( !v3 )
        {
          v4 = *(__int64 **)(v2 + 8);
          v5 = result;
          if ( *v4 == v2 && (v6 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
          {
            *(_QWORD *)(v6 + 8) = v4;
            *v4 = v6;
          }
          else
          {
            _list_del_entry_valid_or_report(v2);
          }
          v7 = *(_QWORD *)(v2 + 16);
          *(_QWORD *)v2 = 0xDEAD000000000100LL;
          *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
          dma_buf_put(v7);
          return msm_vidc_pool_free(v5, v2);
        }
        return result;
      }
    }
    if ( result && (msm_vidc_debug & 1) != 0 )
      return printk(&unk_89DDD, "err ", result + 340, "msm_vidc_dma_buf_put", a2);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_put");
  }
  return result;
}
