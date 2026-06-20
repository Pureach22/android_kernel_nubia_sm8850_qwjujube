__int64 __fastcall mem_buf_vmperm_try_reclaim(__int64 a1, char a2)
{
  unsigned int v4; // w20
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x2
  int v9; // w9
  void (*v11)(void); // x8
  int v18; // w9

  mutex_lock(a1 + 88);
  if ( (a2 & 1) == 0 || (*(_BYTE *)(a1 + 16) & 0x10) != 0 )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(a1 + 136);
    if ( v5 )
    {
      v6 = *(_QWORD *)(a1 + 144);
      if ( *((_DWORD *)v5 - 1) != -1066802076 )
        __break(0x8228u);
      v4 = v5(v6);
      *(_QWORD *)(a1 + 136) = 0;
      if ( v4 && (unsigned int)__ratelimit(&mem_buf_vmperm_try_reclaim__rs, "mem_buf_vmperm_try_reclaim") )
        printk(&unk_13830, *(_QWORD *)(a1 + 136), *(unsigned int *)(a1 + 80));
    }
    else
    {
      v4 = 0;
    }
    v7 = *(_DWORD *)(a1 + 16);
    if ( (v7 & 2) != 0 )
    {
      v4 = _mem_buf_vmperm_reclaim(a1);
    }
    else if ( (v7 & 4) != 0 )
    {
      v4 = mem_buf_unmap_mem_s2(*(unsigned int *)(a1 + 80));
      if ( !v4 )
      {
        if ( (unsigned int)gh_rm_mem_notify(*(unsigned int *)(a1 + 80), 2, 8, 0) )
          printk(&unk_131AC, "mem_buf_vmperm_relinquish", v8);
        xa_erase(&vmperm_xa, *(unsigned int *)(a1 + 80));
        v9 = *(_DWORD *)(a1 + 16);
        *(_DWORD *)(a1 + 80) = -1;
        v11 = *(void (**)(void))(a1 + 152);
        _X0 = *(unsigned int **)(a1 + 160);
        *(_DWORD *)(a1 + 16) = v9 & 0xFFFFFFFB;
        __asm { PRFM            #0x11, [X0] }
        do
          v18 = __ldxr(_X0);
        while ( __stlxr(v18 - 1, _X0) );
        if ( v18 == 1 )
        {
          __dmb(9u);
          if ( *((_DWORD *)v11 - 1) != -2006492174 )
            __break(0x8228u);
          v11();
        }
        else if ( v18 <= 0 )
        {
          refcount_warn_saturate();
        }
        goto LABEL_3;
      }
LABEL_22:
      *(_DWORD *)(a1 + 16) |= 0x10u;
      goto LABEL_23;
    }
    if ( !v4 )
      goto LABEL_23;
    goto LABEL_22;
  }
LABEL_3:
  v4 = 0;
LABEL_23:
  mutex_unlock(a1 + 88);
  return v4;
}
