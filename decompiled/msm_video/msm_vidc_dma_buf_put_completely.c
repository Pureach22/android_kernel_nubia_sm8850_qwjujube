__int64 __fastcall msm_vidc_dma_buf_put_completely(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9
  int v6; // w10
  unsigned int v7; // w10
  unsigned int v8; // w8
  _QWORD *v9; // x8
  __int64 v10; // x19
  __int64 v11; // x9
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 v14; // x9

  if ( a2 )
  {
    v2 = *(_DWORD *)(a2 + 24);
    v3 = v2 - 1;
    if ( v2 < v2 - 1 )
      v3 = *(_DWORD *)(a2 + 24);
    v4 = v3 + 1;
    if ( v4 > 2 )
    {
      v6 = v4 & 1;
      if ( (v4 & 1) == 0 )
        v6 = 2;
      v7 = v4 - v6;
      v5 = v2 - v7;
      do
      {
        v7 -= 2;
        v2 -= 2;
      }
      while ( v7 );
      *(_DWORD *)(a2 + 24) = v2;
    }
    else
    {
      v5 = *(_DWORD *)(a2 + 24);
    }
    v8 = v5 - 1;
    while ( v8 != -1 )
    {
      *(_DWORD *)(a2 + 24) = v8--;
      if ( v8 == -1 )
      {
        v9 = *(_QWORD **)(a2 + 8);
        v10 = result;
        if ( *v9 == a2 && (v11 = *(_QWORD *)a2, *(_QWORD *)(*(_QWORD *)a2 + 8LL) == a2) )
        {
          *(_QWORD *)(v11 + 8) = v9;
          *v9 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(a2);
          a2 = v14;
        }
        v12 = *(_QWORD *)(a2 + 16);
        v13 = a2;
        *(_QWORD *)a2 = 0xDEAD000000000100LL;
        *(_QWORD *)(a2 + 8) = 0xDEAD000000000122LL;
        dma_buf_put(v12);
        return msm_vidc_pool_free(v10, v13);
      }
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_put_completely");
  }
  return result;
}
