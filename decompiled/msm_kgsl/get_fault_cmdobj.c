_QWORD *__fastcall get_fault_cmdobj(__int64 a1, int a2, int a3)
{
  _QWORD *v3; // x20
  _QWORD *v4; // x19
  _QWORD *result; // x0
  __int64 v6; // x21
  _QWORD *v7; // x22
  unsigned int v9; // w8
  unsigned int v10; // w23
  unsigned int v16; // w9
  int v17; // w24
  int v18; // w25
  unsigned __int64 v21; // x9

  v3 = *(_QWORD **)(a1 + 22768);
  v4 = (_QWORD *)(a1 + 22768);
  if ( v3 == (_QWORD *)(a1 + 22768) )
    return nullptr;
  while ( 1 )
  {
    v6 = *(v3 - 1);
    v7 = (_QWORD *)*v3;
    if ( (*(_BYTE *)(v6 + 16) & 1) == 0 || *(_DWORD *)(*(_QWORD *)(v6 + 8) + 4LL) != a2 || *(_DWORD *)(v6 + 20) != a3 )
      goto LABEL_3;
    _X0 = (unsigned int *)(v6 + 32);
    v9 = *(_DWORD *)(v6 + 32);
    if ( v9 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v16 = __ldxr(_X0);
        while ( v16 == v9 && __stxr(v9 + 1, _X0) );
        v10 = v9;
        if ( v16 == v9 )
          break;
        v10 = 0;
        v9 = v16;
      }
      while ( v16 );
    }
    else
    {
      v10 = 0;
    }
    if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
      break;
    if ( v10 )
      goto LABEL_20;
LABEL_3:
    v3 = v7;
    if ( v7 == v4 )
      return nullptr;
  }
  v17 = a2;
  v18 = a3;
  refcount_warn_saturate(_X0, 0);
  a2 = v17;
  a3 = v18;
  if ( !v10 )
    goto LABEL_3;
LABEL_20:
  result = v3 - 1;
  _X8 = (unsigned __int64 *)(v6 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 | 0x10, _X8) );
  return result;
}
