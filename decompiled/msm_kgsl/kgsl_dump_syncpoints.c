__int64 __fastcall kgsl_dump_syncpoints(__int64 result, __int64 a2)
{
  _QWORD *v3; // x20
  unsigned __int64 v4; // x21
  __int64 v5; // x26
  int v6; // w8
  __int64 v7; // x26
  int v8; // w3
  int v9; // w27
  __int64 v10; // x8
  __int64 v11; // x26
  __int64 v12; // x27
  __int64 v13; // x28

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a2 + 64) )
  {
    v3 = (_QWORD *)result;
    v4 = 0;
    do
    {
      if ( v4 <= 0x1F && ((*(_QWORD *)(a2 + 72) >> v4) & 1) != 0 )
      {
        v5 = *(_QWORD *)(a2 + 56) + 120 * v4;
        v6 = *(_DWORD *)(v5 + 4);
        switch ( v6 )
        {
          case 1:
            v11 = *(_QWORD *)(v5 + 48);
            if ( v11 && *(int *)(v11 + 8) >= 1 )
            {
              v12 = 0;
              v13 = 0;
              do
              {
                result = dev_err(*v3, "[%d]  fence: %s\n", v4, (const char *)(*(_QWORD *)v11 + v12));
                ++v13;
                v12 += 74;
              }
              while ( v13 < *(int *)(v11 + 8) );
            }
            break;
          case 2:
            v7 = *(_QWORD *)(v5 + 48);
            if ( v7 )
            {
              v8 = *(_DWORD *)(v7 + 8);
              if ( v8 )
              {
                v9 = 1;
                v10 = v7;
                do
                {
                  result = dev_err(*v3, "[%d]  timeline: %d seqno %lld\n", v4, v8, *(_QWORD *)v10);
                  v10 = v7 + 16LL * v9++;
                  v8 = *(_DWORD *)(v10 + 8);
                }
                while ( v8 );
              }
            }
            break;
          case 0:
            kgsl_readtimestamp(*(_QWORD *)(v5 + 40));
            result = dev_err(
                       *v3,
                       "  [timestamp] context %u timestamp %u (retired %u)\n",
                       *(_DWORD *)(*(_QWORD *)(v5 + 16) + 4LL),
                       *(_DWORD *)(v5 + 24),
                       0);
            break;
        }
      }
      ++v4;
    }
    while ( v4 < *(unsigned int *)(a2 + 64) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
