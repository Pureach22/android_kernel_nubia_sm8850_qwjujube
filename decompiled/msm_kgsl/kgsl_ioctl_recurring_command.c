unsigned __int64 __fastcall kgsl_ioctl_recurring_command(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x21
  unsigned int *owner; // x0
  unsigned int v7; // w8
  __int64 v9; // x2
  unsigned __int64 result; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned __int64 v14; // x20
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64 *, unsigned int *, unsigned __int64); // x8
  __int64 (__fastcall *v17)(__int64, unsigned int *); // x8
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x20
  int v21; // w8
  int v27; // w8

  if ( (*((_BYTE *)a3 + 2) & 0x30) == 0 )
    return -22;
  v3 = *a1;
  owner = (unsigned int *)kgsl_context_get_owner(a1, a3[10]);
  if ( !owner )
    return -22;
  v7 = a3[5];
  _X19 = owner;
  if ( !v7 || (v9 = *a3, (v9 & 0x402) != 0) || v7 > 0x7D0 || a3[9] >= 0x7D1 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v27 = __ldxr(owner);
    while ( __stlxr(v27 - 1, owner) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)owner);
    }
    else if ( v27 <= 0 )
    {
      refcount_warn_saturate(owner, 3);
    }
    return -22;
  }
  result = kgsl_drawobj_cmd_create(v3, owner, v9, 1);
  v14 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    v14 = 0;
    if ( result == -71 )
      goto LABEL_28;
    goto LABEL_22;
  }
  *(_QWORD *)(result + 24) &= ~0x10uLL;
  LODWORD(result) = kgsl_drawobj_cmd_add_cmdlist(v3, result, *((_QWORD *)a3 + 1), a3[4], a3[5]);
  if ( (_DWORD)result )
    goto LABEL_21;
  LODWORD(result) = kgsl_drawobj_cmd_add_memlist(v3, v14, *((_QWORD *)a3 + 3), a3[8], a3[9]);
  if ( (_DWORD)result )
    goto LABEL_21;
  v15 = *(_QWORD *)(v3 + 8752);
  if ( (*(_BYTE *)(v14 + 26) & 0x20) == 0 )
  {
    v16 = *(__int64 (__fastcall **)(__int64 *, unsigned int *, unsigned __int64))(v15 + 272);
    if ( *((_DWORD *)v16 - 1) != 1292319187 )
      __break(0x8228u);
    LODWORD(result) = v16(a1, _X19, v14);
    goto LABEL_21;
  }
  v17 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v15 + 280);
  if ( *((_DWORD *)v17 - 1) != -1840578834 )
    __break(0x8228u);
  LODWORD(result) = v17(v3, _X19);
  if ( (_DWORD)result )
  {
LABEL_21:
    result = (int)result;
    if ( (int)result == -71 )
      goto LABEL_28;
LABEL_22:
    if ( !result )
      goto LABEL_28;
    goto LABEL_23;
  }
  result = 0;
LABEL_23:
  v18 = result;
  kgsl_drawobj_destroy(v14, v11, v12, v13);
  result = v18;
LABEL_28:
  __asm { PRFM            #0x11, [X19] }
  do
    v21 = __ldxr(_X19);
  while ( __stlxr(v21 - 1, _X19) );
  if ( v21 == 1 )
  {
    __dmb(9u);
    v19 = result;
    kgsl_context_destroy((__int64)_X19);
    return v19;
  }
  if ( v21 <= 0 )
  {
    v19 = result;
    refcount_warn_saturate(_X19, 3);
    return v19;
  }
  return result;
}
