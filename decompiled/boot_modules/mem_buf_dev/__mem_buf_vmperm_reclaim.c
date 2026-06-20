__int64 __fastcall _mem_buf_vmperm_reclaim(__int64 a1)
{
  __int64 v2; // x0
  int *v3; // x1
  unsigned int v4; // w2
  unsigned int v5; // w3
  unsigned int v6; // w8
  __int64 v7; // x1
  __int64 v8; // x1
  void (__fastcall *v10)(unsigned int *, __int64); // x8
  int v16; // w9
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 64);
  v3 = *(int **)(a1 + 32);
  v4 = *(_DWORD *)(a1 + 48);
  v5 = *(_DWORD *)(a1 + 80);
  src = current_vmid;
  v6 = mem_buf_unassign_mem(v2, v3, v4, v5);
  if ( !v6 )
  {
    mem_buf_vmperm_update_state(a1, &src);
    v7 = *(unsigned int *)(a1 + 80);
    *(_DWORD *)(a1 + 16) &= ~2u;
    xa_erase(&vmperm_xa, v7);
    v10 = *(void (__fastcall **)(unsigned int *, __int64))(a1 + 152);
    _X0 = *(unsigned int **)(a1 + 160);
    *(_DWORD *)(a1 + 80) = -1;
    __asm { PRFM            #0x11, [X0] }
    do
      v16 = __ldxr(_X0);
    while ( __stlxr(v16 - 1, _X0) );
    if ( v16 == 1 )
    {
      __dmb(9u);
      if ( *((_DWORD *)v10 - 1) != -2006492174 )
        __break(0x8228u);
      v10(_X0, v8);
    }
    else
    {
      v6 = 0;
      if ( v16 > 0 )
        goto LABEL_10;
      refcount_warn_saturate(_X0, 3);
    }
    v6 = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v6;
}
