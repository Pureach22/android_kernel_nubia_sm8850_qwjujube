__int64 __fastcall remote_etm_disable(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x0
  unsigned int v7; // w21
  unsigned int v8; // w8
  unsigned int v9; // w21
  __int64 v10; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  mutex_lock(v2 + 16);
  if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
  {
    v3 = **(_QWORD **)(v2 + 8);
    v4 = *(unsigned int *)(v3 + 4);
    if ( (int)v4 >= 1 )
    {
      v5 = *(_QWORD *)(v3 + 8);
      while ( 1 )
      {
        v6 = *(_QWORD *)(*(_QWORD *)v5 + 16LL);
        if ( v6 )
        {
          if ( *(_DWORD *)(v6 + 8) == 4 )
            break;
        }
        --v4;
        v5 += 8;
        if ( !v4 )
          goto LABEL_8;
      }
      coresight_qmi_remote_etm_disable();
    }
LABEL_8:
    if ( *(_DWORD *)(v2 + 80) )
    {
      v7 = 0;
      do
      {
        coresight_csr_set_etr_atid(a1, *(unsigned __int8 *)(*(_QWORD *)(v2 + 72) + (int)v7), 0, 0);
        v8 = *(_DWORD *)(v2 + 80);
        ++v7;
      }
      while ( v7 < v8 );
      if ( v8 )
      {
        v9 = 0;
        do
        {
          v10 = *(unsigned __int8 *)(*(_QWORD *)(v2 + 72) + (int)v9);
          if ( *(_BYTE *)(v2 + 84) == 1 )
            coresight_trace_id_free_reserved_id(v10);
          else
            coresight_trace_id_put_system_id(v10);
          ++v9;
        }
        while ( v9 < *(_DWORD *)(v2 + 80) );
      }
    }
    *(_QWORD *)(a1 + 968) = 0;
  }
  return mutex_unlock(v2 + 16);
}
