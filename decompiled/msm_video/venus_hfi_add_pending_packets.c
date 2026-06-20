__int64 __fastcall venus_hfi_add_pending_packets(__int64 a1)
{
  unsigned int *v1; // x22
  __int64 v3; // x4
  _QWORD *v4; // x24
  _QWORD *v5; // x23
  unsigned __int64 v6; // x27
  _QWORD *v7; // x20
  _DWORD *v8; // x21
  int v9; // w28
  __int64 v10; // x4
  int v11; // w9
  __int64 v12; // x8
  _QWORD *v13; // x8
  __int64 v14; // x9
  __int64 result; // x0

  v1 = *(unsigned int **)(a1 + 368);
  v3 = *v1;
  if ( (unsigned int)v3 > 0x1F )
  {
    v4 = *(_QWORD **)(a1 + 4072);
    v5 = (_QWORD *)(a1 + 4072);
    if ( v4 == (_QWORD *)(a1 + 4072) )
    {
      return 0;
    }
    else
    {
      do
      {
        v6 = v4[2];
        v7 = v4;
        v4 = (_QWORD *)*v4;
        v8 = (_DWORD *)(v6 + 32);
        v9 = *(_DWORD *)(v6 + 28) + 1;
        while ( --v9 >= 1 )
        {
          memcpy((char *)v1 + *v1, v8, (unsigned int)*v8);
          v11 = *v1;
          ++v1[7];
          v12 = (unsigned int)(v11 + *v8);
          *v1 = v12;
          v8 = (_DWORD *)((char *)v8 + (unsigned int)*v8);
          if ( (unsigned __int64)v8 < v6 || (unsigned __int64)v8 > v6 + v12 )
          {
            if ( a1 && (msm_vidc_debug & 1) != 0 )
              printk(&unk_94F53, "err ", a1 + 340, "venus_hfi_add_pending_packets", v10);
            return 4294967274LL;
          }
        }
        v13 = (_QWORD *)v7[1];
        if ( (_QWORD *)*v13 == v7 && (v14 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
        {
          *(_QWORD *)(v14 + 8) = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        *v7 = 0xDEAD000000000100LL;
        v7[1] = 0xDEAD000000000122LL;
        msm_vidc_pool_free(a1, (__int64)v7);
        result = 0;
      }
      while ( v4 != v5 );
    }
  }
  else
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8DE8C, "err ", a1 + 340, "venus_hfi_add_pending_packets", v3);
    }
    return 4294967274LL;
  }
  return result;
}
