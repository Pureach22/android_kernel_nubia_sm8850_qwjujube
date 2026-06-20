__int64 __fastcall qmp_shim_send_data(__int64 a1, const void **a2)
{
  __int64 v2; // x19
  unsigned int v3; // w8
  __int64 v4; // x9
  int v5; // w8
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x11

  v2 = *(_QWORD *)(a1 + 240);
  if ( !v2 )
    return (unsigned int)-22;
  v3 = -22;
  if ( a2 )
  {
    v4 = *(_QWORD *)(v2 + 496);
    if ( v4 )
    {
      if ( (*(_BYTE *)(v4 + 153) & 1) != 0 || (*(_BYTE *)(v4 + 154) & 1) != 0 )
        return (unsigned int)-6;
      v5 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 > 0x1000u )
        return (unsigned int)-22;
      v7 = *(unsigned int *)(v2 + 40);
      if ( (int)v7 >= 1 )
      {
        v8 = 0;
        v9 = *(_QWORD *)(v2 + 32) - 248LL;
        while ( 1 )
        {
          v9 += 248;
          if ( v9 == a1 )
            break;
          if ( v7 == ++v8 )
            goto LABEL_16;
        }
        *(_DWORD *)(v2 + 180) = v8;
        v5 = *(_DWORD *)a2;
      }
LABEL_16:
      *(_DWORD *)(v2 + 208) = v5;
      memcpy(*(void **)(v2 + 216), a2[1], *(unsigned int *)a2);
      queue_work_on(32, system_wq, v2 + 224);
      return 0;
    }
  }
  return v3;
}
