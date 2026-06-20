unsigned __int64 __fastcall kgsl_ioctl_gpu_command(__int64 *a1, __int64 a2, unsigned int *a3)
{
  unsigned __int64 v3; // x20
  unsigned int v4; // w8
  unsigned int v6; // w9
  unsigned int v8; // w24
  int v10; // w10
  int v11; // w8
  unsigned int v12; // w1
  __int64 v13; // x23
  __int64 owner; // x0
  unsigned int v16; // w25
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x2
  int v23; // w0
  unsigned __int64 v24; // x0
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x2
  int v28; // w0
  __int64 v29; // x22
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  _DWORD *v33; // x8
  int v38; // w8
  unsigned __int64 v42; // x9
  _QWORD v43[3]; // [xsp+8h] [xbp-18h] BYREF

  v3 = -22;
  v43[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a3[5];
  if ( v4 <= 0x7D0 && a3[9] <= 0x7D0 )
  {
    v6 = a3[13];
    if ( v6 <= 0x20 )
    {
      if ( (*a3 & 2) != 0 )
      {
        v8 = 2;
      }
      else
      {
        v8 = 4;
        if ( (*a3 & 0x400) == 0 )
        {
          if ( v6 )
            _ZF = v4 == 0;
          else
            _ZF = 1;
          if ( _ZF )
            v10 = 4;
          else
            v10 = 5;
          if ( v4 )
            v11 = 1;
          else
            v11 = 2;
          if ( v6 )
            v8 = v10;
          else
            v8 = v11;
        }
      }
      v12 = a3[14];
      v13 = *a1;
      v43[0] = 0;
      v43[1] = 0;
      owner = kgsl_context_get_owner(a1, v12);
      if ( owner )
      {
        _X19 = (unsigned int *)owner;
        if ( v8 >= 4 )
        {
          v24 = kgsl_drawobj_sync_create(v13, owner);
          v3 = v24;
          if ( v24 >= 0xFFFFFFFFFFFFF001LL )
          {
            v16 = 0;
            if ( v24 == -71 )
              goto LABEL_53;
            goto LABEL_34;
          }
          v25 = a3[12];
          v26 = a3[13];
          v27 = *((_QWORD *)a3 + 5);
          v43[0] = v24;
          v28 = kgsl_drawobj_sync_add_synclist(v13, v24, v27, v25, v26);
          if ( v28 )
          {
            v3 = v28;
            v16 = 1;
            goto LABEL_33;
          }
          if ( (*(_QWORD *)(v3 + 128) & 1) == 0 )
          {
            _X8 = (unsigned __int64 *)(v3 + 128);
            __asm { PRFM            #0x11, [X8] }
            do
              v42 = __ldxr(_X8);
            while ( __stxr(v42 | 2, _X8) );
          }
          v16 = 1;
        }
        else
        {
          v16 = 0;
        }
        if ( (v8 & 3) == 0 )
        {
LABEL_47:
          v33 = *(_DWORD **)(*(_QWORD *)(v13 + 8752) + 72LL);
          if ( *(v33 - 1) != -646102743 )
            __break(0x8228u);
          v3 = ((int (__fastcall *)(__int64 *, unsigned int *, _QWORD *, _QWORD, unsigned int *))v33)(
                 a1,
                 _X19,
                 v43,
                 v16,
                 a3 + 15);
          if ( v3 == -71 )
            goto LABEL_53;
LABEL_34:
          if ( v3 && v16 )
          {
            v29 = v16 - 1LL;
            if ( (v29 & 0x1FFFFFFFFFFFFFFELL) != 0 )
              goto LABEL_52;
            kgsl_drawobj_destroy(v43[v29], v17, v18, v19);
            if ( v16 == 1 )
              goto LABEL_53;
            if ( ((v16 - 2LL) & 0x1FFFFFFFFFFFFFFELL) != 0 )
LABEL_52:
              __break(1u);
            else
              kgsl_drawobj_destroy(v43[v16 - 2], v30, v31, v32);
          }
LABEL_53:
          __asm { PRFM            #0x11, [X19] }
          do
            v38 = __ldxr(_X19);
          while ( __stlxr(v38 - 1, _X19) );
          if ( v38 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy((__int64)_X19);
          }
          else if ( v38 <= 0 )
          {
            refcount_warn_saturate(_X19, 3);
          }
          goto LABEL_58;
        }
        v3 = kgsl_drawobj_cmd_create(v13, _X19, *a3, v8);
        if ( v3 < 0xFFFFFFFFFFFFF001LL )
        {
          v20 = a3[4];
          v21 = a3[5];
          v22 = *((_QWORD *)a3 + 1);
          v43[v16] = v3;
          v23 = kgsl_drawobj_cmd_add_cmdlist(v13, v3, v22, v20, v21);
          if ( v23 )
            goto LABEL_26;
          v23 = kgsl_drawobj_cmd_add_memlist(v13, v3, *((_QWORD *)a3 + 3), a3[8], a3[9]);
          if ( v23 )
            goto LABEL_26;
          if ( !*(_QWORD *)(v3 + 128) )
            *(_QWORD *)(v3 + 24) &= ~0x10uLL;
          if ( (v8 & 1) != 0 )
          {
            v23 = kgsl_reclaim_to_pinned_state(a1[1]);
            if ( v23 )
            {
LABEL_26:
              v3 = v23;
              ++v16;
              if ( v23 == -71 )
                goto LABEL_53;
              goto LABEL_34;
            }
          }
          ++v16;
          goto LABEL_47;
        }
LABEL_33:
        if ( v3 == -71 )
          goto LABEL_53;
        goto LABEL_34;
      }
    }
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v3;
}
