__int64 __fastcall get_task_struct(__int64 a1)
{
  __int64 v1; // x8
  __int64 v4; // x19
  __int64 v5; // x1
  unsigned int v11; // w9

  v1 = a1;
  _X0 = (unsigned int *)(a1 + 64);
  __asm { PRFM            #0x11, [X0] }
  do
    v11 = __ldxr(_X0);
  while ( __stxr(v11 + 1, _X0) );
  if ( !v11 )
  {
    v4 = v1;
    v5 = 2;
    goto LABEL_8;
  }
  if ( (((v11 + 1) | v11) & 0x80000000) != 0 )
  {
    v4 = v1;
    v5 = 1;
LABEL_8:
    refcount_warn_saturate(_X0, v5);
    return v4;
  }
  return v1;
}
