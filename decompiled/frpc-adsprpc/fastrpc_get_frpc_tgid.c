__int64 __fastcall fastrpc_get_frpc_tgid(int a1, int a2, _DWORD *a3)
{
  __int64 v6; // x8
  __int64 *v7; // x22
  __int64 v8; // x19
  __int64 **v9; // x24
  _DWORD *v10; // x23
  unsigned int v12; // w21
  __int64 v13; // x1
  unsigned int v19; // w8
  __int64 v20; // x0
  int v21; // w8
  __int64 *v22; // x9
  __int64 v23; // x22
  int v24; // w10
  int v25; // w8

  mutex_lock(&unk_26CD8);
  v6 = 0;
  while ( 1 )
  {
    v7 = *(__int64 **)&g_frpc[2 * v6 + 26];
    if ( v7 )
      break;
LABEL_2:
    if ( ++v6 == 256 )
    {
      mutex_unlock(&unk_26CD8);
      return (unsigned int)-32;
    }
  }
  while ( *((_DWORD *)v7 + 4) != a1 )
  {
    v7 = (__int64 *)*v7;
    if ( !v7 )
      goto LABEL_2;
  }
  mutex_unlock(&unk_26CD8);
  v8 = v7[22];
  if ( !v8 )
    return (unsigned int)-32;
  v9 = (__int64 **)(v8 + 51648);
  v10 = (_DWORD *)(v8 + 64136);
  _X0 = (unsigned int *)(v8 + 51664);
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr(_X0);
  while ( __stxr(v19 + 1, _X0) );
  if ( v19 )
  {
    if ( (((v19 + 1) | v19) & 0x80000000) == 0 )
    {
      if ( !*v10 )
        goto LABEL_19;
      goto LABEL_11;
    }
    v13 = 1;
  }
  else
  {
    v13 = 2;
  }
  refcount_warn_saturate(_X0, v13);
  if ( !*v10 )
  {
LABEL_19:
    v20 = raw_spin_lock_irqsave(v8 + 51600);
    v21 = *(_DWORD *)(v8 + 64180);
    v22 = *v9;
    v23 = v20;
    _ZF = *v9 == (__int64 *)v9;
    *(_DWORD *)(v8 + 64180) = v21 + 1;
    if ( _ZF )
    {
LABEL_26:
      v12 = -3;
      *(_DWORD *)(v8 + 64180) = v21;
      if ( v21 )
      {
LABEL_28:
        raw_spin_unlock_irqrestore(v8 + 51600, v23);
        goto LABEL_29;
      }
    }
    else
    {
      v24 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
      while ( *((_DWORD *)v22 + 62) != v24 || *((_DWORD *)v22 + 71) != a2 )
      {
        v22 = (__int64 *)*v22;
        if ( v22 == (__int64 *)v9 )
          goto LABEL_26;
      }
      v12 = 0;
      *a3 = *((_DWORD *)v22 + 61);
      v25 = *(_DWORD *)(v8 + 64180) - 1;
      *(_DWORD *)(v8 + 64180) = v25;
      if ( v25 )
        goto LABEL_28;
    }
    _wake_up(v8 + 64216, 1, 1, 0);
    goto LABEL_28;
  }
LABEL_11:
  v12 = -32;
LABEL_29:
  fastrpc_channel_ctx_put(v8);
  return v12;
}
