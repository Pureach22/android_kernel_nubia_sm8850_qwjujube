__int64 *__fastcall adreno_fault_skipcmd_detached(__int64 *result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  const char *v5; // x2
  __int64 v6; // x9
  int v7; // w3
  __int64 v8; // x19
  __int64 v9; // x9
  unsigned __int64 v16; // x10

  if ( (*(_QWORD *)(a2 + 32) & 0x200000) != 0 && (!a2 || (*(_QWORD *)(a2 + 32) & 2) != 0) )
  {
    v3 = *(_QWORD *)(a3 + 8);
    v4 = *result;
    if ( v3 )
    {
      v9 = *(_QWORD *)(v3 + 24);
      if ( v9 )
        v5 = (const char *)(v9 + 16);
      else
        v5 = "unknown";
      v6 = *(_QWORD *)(v9 + 8);
      if ( v6 )
        goto LABEL_7;
    }
    else
    {
      v5 = "unknown";
      v6 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
      {
LABEL_7:
        v7 = *(_DWORD *)(v6 + 112);
        v8 = a2;
        goto LABEL_13;
      }
    }
    v8 = a2;
    v7 = 0;
LABEL_13:
    result = (__int64 *)dev_err(v4, "%s[%d]: gpu detached context %d\n", v5, v7, *(_DWORD *)(v3 + 4));
    _X8 = (unsigned __int64 *)(v8 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 & 0xFFFFFFFFFFDFFFFFLL, _X8) );
  }
  return result;
}
