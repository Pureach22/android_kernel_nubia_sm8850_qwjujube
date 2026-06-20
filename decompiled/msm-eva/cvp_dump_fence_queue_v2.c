__int64 __fastcall cvp_dump_fence_queue_v2(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  char v4; // w8
  int v5; // w9
  __int64 *v6; // x19
  __int64 *v7; // x28
  unsigned __int64 v9; // x10
  unsigned __int64 i; // x24
  unsigned int v11; // w25
  unsigned int v12; // w26
  __int64 *v13; // x19
  char v14; // w8
  int v15; // w9
  unsigned __int64 v16; // x10
  unsigned __int64 j; // x24
  unsigned int v18; // w25
  unsigned int v19; // w26
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  __int64 v28; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(a1 + 15264);
  v3 = mutex_lock(a1 + 15272);
  v4 = msm_cvp_debug;
  v5 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v3 = printk(&unk_83FED, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    v4 = msm_cvp_debug;
    v5 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 2) == 0 )
      goto LABEL_6;
  }
  else if ( (msm_cvp_debug & 2) == 0 )
  {
    goto LABEL_6;
  }
  if ( !v5 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    v3 = printk(&unk_96AA0, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), "warn");
    v4 = msm_cvp_debug;
    v5 = msm_cvp_debug_out;
  }
LABEL_6:
  v6 = *(__int64 **)(a1 + 15328);
  v28 = a1;
  v7 = (__int64 *)(a1 + 15328);
  if ( v6 != (__int64 *)(a1 + 15328) )
  {
    _X21 = _ReadStatusReg(SP_EL0);
    do
    {
      if ( (v4 & 2) != 0 && !v5 )
      {
        v3 = printk(&unk_8B8FB, *(unsigned int *)(_X21 + 1800), *(unsigned int *)(_X21 + 1804), "warn");
        v4 = msm_cvp_debug;
        v5 = msm_cvp_debug_out;
        v9 = *((unsigned int *)v6 + 9);
        if ( (_DWORD)v9 )
        {
LABEL_12:
          for ( i = 0; i < v9; ++i )
          {
            if ( (v4 & 2) != 0 && !v5 )
            {
              if ( i >= 0x40 )
              {
LABEL_41:
                __break(0x5512u);
                __asm { STZ2G           X21, [X6,#0x4C0]! }
                return _check_tensilica_in_reset_hawi(v3);
              }
              v11 = *(_DWORD *)(_X21 + 1804);
              v12 = *(_DWORD *)(_X21 + 1800);
              synx_get_status(v2, *((unsigned int *)v6 + i + 11));
              v3 = printk(&unk_910AC, v12, v11, "warn");
              v9 = *((unsigned int *)v6 + 9);
              v4 = msm_cvp_debug;
              v5 = msm_cvp_debug_out;
            }
          }
        }
      }
      else
      {
        v9 = *((unsigned int *)v6 + 9);
        if ( (_DWORD)v9 )
          goto LABEL_12;
      }
      v6 = (__int64 *)*v6;
    }
    while ( v6 != v7 );
  }
  if ( (v4 & 2) != 0 && !v5 )
  {
    v23 = _ReadStatusReg(SP_EL0);
    v3 = printk(&unk_8C327, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), "warn");
  }
  v13 = *(__int64 **)(v28 + 15368);
  if ( v13 != (__int64 *)(v28 + 15368) )
  {
    v14 = msm_cvp_debug;
    v15 = msm_cvp_debug_out;
    _X21 = _ReadStatusReg(SP_EL0);
    do
    {
      if ( (v14 & 2) != 0 && !v15 )
      {
        v3 = printk(&unk_8B8FB, *(unsigned int *)(_X21 + 1800), *(unsigned int *)(_X21 + 1804), "warn");
        v14 = msm_cvp_debug;
        v15 = msm_cvp_debug_out;
        v16 = *((unsigned int *)v13 + 9);
        if ( (_DWORD)v16 )
        {
LABEL_29:
          for ( j = 0; j < v16; ++j )
          {
            if ( (v14 & 2) != 0 && !v15 )
            {
              if ( j > 0x3F )
                goto LABEL_41;
              v18 = *(_DWORD *)(_X21 + 1804);
              v19 = *(_DWORD *)(_X21 + 1800);
              synx_get_status(v2, *((unsigned int *)v13 + j + 11));
              v3 = printk(&unk_910AC, v19, v18, "warn");
              v16 = *((unsigned int *)v13 + 9);
              v14 = msm_cvp_debug;
              v15 = msm_cvp_debug_out;
            }
          }
        }
      }
      else
      {
        v16 = *((unsigned int *)v13 + 9);
        if ( (_DWORD)v16 )
          goto LABEL_29;
      }
      v13 = (__int64 *)*v13;
    }
    while ( v13 != (__int64 *)(v28 + 15368) );
  }
  return mutex_unlock(v28 + 15272);
}
