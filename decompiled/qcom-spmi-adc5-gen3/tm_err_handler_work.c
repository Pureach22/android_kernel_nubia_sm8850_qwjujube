__int64 __fastcall tm_err_handler_work(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w23
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned __int64 v6; // x24
  unsigned int v7; // w8
  int v8; // w10
  int v9; // w25
  __int64 v10; // x9

  if ( *(_DWORD *)(result - 172) )
  {
    v1 = result;
    v2 = 0;
    v3 = result - 112;
    do
    {
      v4 = raw_spin_lock_irqsave(v1 + 40);
      v5 = *(_QWORD *)(v1 + 32);
      v6 = *(unsigned __int8 *)(v5 + (int)v2);
      if ( *(_BYTE *)(v5 + (int)v2) )
      {
        *(_BYTE *)(v5 + (int)v2) = 0;
        result = raw_spin_unlock_irqrestore(v1 + 40, v4);
        v7 = *(_DWORD *)(v1 - 168);
        if ( v7 )
        {
          v8 = 0;
          do
          {
            v9 = v8;
            v10 = *(_QWORD *)(v1 - 160) + 200LL * v8;
            if ( *(_DWORD *)(v10 + 72) && v2 == *(_DWORD *)(v10 + 28) && ((v6 >> *(_DWORD *)(v10 + 76)) & 1) != 0 )
            {
              ipc_log_string(
                *(_QWORD *)(v1 - 192),
                "Reconfiguring %s channel after conversion fault\n",
                *(const char **)(v10 + 48));
              mutex_lock(v3);
              adc_tm5_gen3_configure(*(_QWORD *)(v1 - 160) + 200LL * v9);
              result = mutex_unlock(v3);
              v7 = *(_DWORD *)(v1 - 168);
            }
            v8 = v9 + 1;
          }
          while ( v9 + 1 < v7 );
        }
      }
      else
      {
        result = raw_spin_unlock_irqrestore(v1 + 40, v4);
      }
      ++v2;
    }
    while ( v2 < *(_DWORD *)(v1 - 172) );
  }
  return result;
}
