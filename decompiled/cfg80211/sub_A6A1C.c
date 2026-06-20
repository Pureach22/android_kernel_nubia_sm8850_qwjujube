// positive sp value has been detected, the output may be wrong!
__int64 sub_A6A1C()
{
  size_t v0; // x0
  unsigned __int64 v1; // x2
  __int64 v2; // x8
  int v3; // w9
  __int64 result; // x0
  __int64 v5; // x19
  int *v6; // x20
  __int64 v7; // x21
  __int64 v8; // x22
  const char *v9; // x24
  __int64 v10; // [xsp-78h] [xbp-78h] BYREF

  v0 = strnlen(v9, 0x20u);
  if ( v0 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_15;
  }
  if ( v0 == 32 )
    v1 = 32;
  else
    v1 = v0 + 1;
  if ( v1 >= 0x21 )
  {
LABEL_15:
    _fortify_panic(7, 32);
    JUMPOUT(0x9EBC4);
  }
  sized_strscpy(v7 + 8, v9);
  v2 = *(_QWORD *)(v8 + 304);
  *(_QWORD *)(v7 + 40) = *(_QWORD *)(v8 + 296);
  *(_QWORD *)(v7 + 48) = v2;
  *(_DWORD *)(v7 + 56) = *(_DWORD *)(v8 + 224);
  if ( v6 )
  {
    v3 = *v6;
    *(_WORD *)(v7 + 64) = *((_WORD *)v6 + 2);
    *(_DWORD *)(v7 + 60) = v3;
    if ( !v5 )
      goto LABEL_12;
  }
  else
  {
    *(_WORD *)(v7 + 64) = 0;
    *(_DWORD *)(v7 + 60) = 0;
    if ( !v5 )
    {
LABEL_12:
      *(_QWORD *)(v7 + 90) = 0;
      *(_QWORD *)(v7 + 84) = 0;
      *(_QWORD *)(v7 + 76) = 0;
      *(_QWORD *)(v7 + 68) = 0;
      goto LABEL_13;
    }
  }
  if ( !*(_QWORD *)v5 )
    goto LABEL_12;
  *(_DWORD *)(v7 + 68) = **(_DWORD **)v5;
  *(_DWORD *)(v7 + 72) = *(_DWORD *)(*(_QWORD *)v5 + 4LL);
  *(_DWORD *)(v7 + 76) = *(unsigned __int16 *)(*(_QWORD *)v5 + 8LL);
  *(_DWORD *)(v7 + 80) = *(_DWORD *)(v5 + 8);
  *(_DWORD *)(v7 + 84) = *(_DWORD *)(v5 + 12);
  *(_DWORD *)(v7 + 88) = *(unsigned __int16 *)(v5 + 28);
  *(_DWORD *)(v7 + 92) = *(_DWORD *)(v5 + 16);
  *(_WORD *)(v7 + 96) = *(_WORD *)(v5 + 30);
LABEL_13:
  result = trace_event_buffer_commit(&v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
