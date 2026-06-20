__int64 __fastcall cscfg_csdev_disable_config(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  int v8; // w11
  __int64 v9; // x10
  _QWORD *v10; // x12

  if ( *(int *)(result + 40) >= 1 )
  {
    v1 = result;
    v2 = 0;
    v3 = result + 48;
    do
    {
      v4 = *(_QWORD *)(v3 + 8 * v2);
      raw_spin_lock_irqsave(*(_QWORD *)(v4 + 32));
      if ( *(int *)(v4 + 56) >= 1 )
      {
        v5 = 0;
        v6 = 0;
        do
        {
          v7 = *(_QWORD *)(v4 + 64);
          v8 = *(_DWORD *)(v7 + v5);
          if ( (v8 & 1) != 0 )
          {
            v9 = v7 + v5;
            v10 = *(_QWORD **)(v9 + 16);
            if ( (v8 & 2) != 0 )
              *(_QWORD *)(v9 + 8) = *v10;
            else
              *(_DWORD *)(v9 + 8) = *(_DWORD *)v10;
          }
          ++v6;
          v5 += 24;
        }
        while ( v6 < *(int *)(v4 + 56) );
      }
      result = raw_spin_unlock_irqrestore(*(_QWORD *)(v4 + 32));
      ++v2;
    }
    while ( v2 < *(int *)(v1 + 40) );
  }
  return result;
}
