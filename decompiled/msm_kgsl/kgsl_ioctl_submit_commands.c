unsigned __int64 __fastcall kgsl_ioctl_submit_commands(__int64 *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v5; // w9
  int v7; // w10
  unsigned int v9; // w24
  int v11; // w10
  int v12; // w8
  unsigned int v13; // w1
  __int64 v14; // x23
  __int64 owner; // x0
  unsigned int v17; // w25
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x2
  int v22; // w0
  unsigned __int64 v23; // x0
  __int64 v24; // x2
  __int64 v25; // x3
  int v26; // w0
  _DWORD *v27; // x8
  __int64 v28; // x22
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  int v36; // w8
  unsigned __int64 v40; // x9
  _QWORD v41[3]; // [xsp+8h] [xbp-18h] BYREF

  v3 = -22;
  v41[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a3 + 16);
  if ( v4 <= 0x7D0 )
  {
    v5 = *(_DWORD *)(a3 + 32);
    if ( v5 <= 0x20 )
    {
      v7 = *(_DWORD *)(a3 + 4);
      if ( (v7 & 2) != 0 )
      {
        v9 = 2;
      }
      else
      {
        v9 = 4;
        if ( (v7 & 0x400) == 0 )
        {
          if ( v5 )
            _ZF = v4 == 0;
          else
            _ZF = 1;
          if ( _ZF )
            v11 = 4;
          else
            v11 = 5;
          if ( v4 )
            v12 = 1;
          else
            v12 = 2;
          if ( v5 )
            v9 = v11;
          else
            v9 = v12;
        }
      }
      v13 = *(_DWORD *)a3;
      v14 = *a1;
      v41[0] = 0;
      v41[1] = 0;
      owner = kgsl_context_get_owner(a1, v13);
      if ( owner )
      {
        _X19 = (unsigned int *)owner;
        if ( v9 >= 4 )
        {
          v23 = kgsl_drawobj_sync_create(v14, owner);
          v3 = v23;
          if ( v23 >= 0xFFFFFFFFFFFFF001LL )
          {
            v17 = 0;
            if ( v23 == -71 )
              goto LABEL_52;
            goto LABEL_43;
          }
          v24 = *(_QWORD *)(a3 + 24);
          v25 = *(unsigned int *)(a3 + 32);
          v41[0] = v23;
          v26 = kgsl_drawobj_sync_add_syncpoints(v14, v23, v24, v25);
          if ( v26 )
          {
            v3 = v26;
            v17 = 1;
            goto LABEL_31;
          }
          if ( (*(_QWORD *)(v3 + 128) & 1) == 0 )
          {
            _X8 = (unsigned __int64 *)(v3 + 128);
            __asm { PRFM            #0x11, [X8] }
            do
              v40 = __ldxr(_X8);
            while ( __stxr(v40 | 2, _X8) );
          }
          v17 = 1;
        }
        else
        {
          v17 = 0;
        }
        if ( (v9 & 3) == 0 )
        {
LABEL_40:
          v27 = *(_DWORD **)(*(_QWORD *)(v14 + 8752) + 72LL);
          if ( *(v27 - 1) != -646102743 )
            __break(0x8228u);
          v3 = ((int (__fastcall *)(__int64 *, unsigned int *, _QWORD *, _QWORD, __int64))v27)(
                 a1,
                 _X19,
                 v41,
                 v17,
                 a3 + 36);
          if ( v3 == -71 )
            goto LABEL_52;
LABEL_43:
          if ( v3 && v17 )
          {
            v28 = v17 - 1LL;
            if ( (v28 & 0x1FFFFFFFFFFFFFFELL) == 0 )
            {
              kgsl_drawobj_destroy(v41[v28], v18, v19, v20);
              if ( v17 == 1 )
                goto LABEL_52;
              if ( ((v17 - 2LL) & 0x1FFFFFFFFFFFFFFELL) == 0 )
              {
                kgsl_drawobj_destroy(v41[v17 - 2], v29, v30, v31);
                goto LABEL_52;
              }
            }
            __break(1u);
          }
LABEL_52:
          __asm { PRFM            #0x11, [X19] }
          do
            v36 = __ldxr(_X19);
          while ( __stlxr(v36 - 1, _X19) );
          if ( v36 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy((__int64)_X19);
          }
          else if ( v36 <= 0 )
          {
            refcount_warn_saturate(_X19, 3);
          }
          goto LABEL_57;
        }
        v3 = kgsl_drawobj_cmd_create(v14, _X19, *(unsigned int *)(a3 + 4), v9);
        if ( v3 < 0xFFFFFFFFFFFFF001LL )
        {
          v21 = *(_QWORD *)(a3 + 8);
          v41[v17] = v3;
          v22 = kgsl_drawobj_cmd_add_ibdesc_list(v14, v3, v21);
          if ( v22 )
            goto LABEL_24;
          if ( !*(_QWORD *)(v3 + 128) )
            *(_QWORD *)(v3 + 24) &= ~0x10uLL;
          if ( (v9 & 1) != 0 )
          {
            v22 = kgsl_reclaim_to_pinned_state(a1[1]);
            if ( v22 )
            {
LABEL_24:
              v3 = v22;
              ++v17;
              if ( v22 == -71 )
                goto LABEL_52;
              goto LABEL_43;
            }
          }
          ++v17;
          goto LABEL_40;
        }
LABEL_31:
        if ( v3 == -71 )
          goto LABEL_52;
        goto LABEL_43;
      }
    }
  }
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return v3;
}
