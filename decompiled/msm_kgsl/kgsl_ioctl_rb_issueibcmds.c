unsigned __int64 __fastcall kgsl_ioctl_rb_issueibcmds(__int64 *a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  unsigned __int64 result; // x0
  __int64 v5; // x21
  __int64 owner; // x0
  char v10; // w8
  __int64 v11; // x9
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  int v15; // w22
  _DWORD *v16; // x8
  unsigned __int64 v17; // x20
  int v23; // w8
  _QWORD v25[4]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v26[2]; // [xsp+20h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a3 + 24);
  if ( (v3 & 0x402) == 0 )
  {
    v5 = *a1;
    if ( (v3 & 4) == 0 || (unsigned int)(*(_DWORD *)(a3 + 16) - 2001) >= 0xFFFFF830 )
    {
      owner = kgsl_context_get_owner(a1, *(_DWORD *)a3);
      if ( owner )
      {
        _X19 = (unsigned int *)owner;
        result = kgsl_drawobj_cmd_create(v5, owner, *(unsigned int *)(a3 + 24), 1);
        if ( result >= 0xFFFFFFFFFFFFF001LL )
        {
          __asm { PRFM            #0x11, [X19] }
          do
            v23 = __ldxr(_X19);
          while ( __stlxr(v23 - 1, _X19) );
          if ( v23 != 1 )
          {
LABEL_30:
            if ( v23 > 0 )
              goto LABEL_3;
            v17 = result;
            refcount_warn_saturate(_X19, 3);
            goto LABEL_24;
          }
          __dmb(9u);
LABEL_23:
          v17 = result;
          kgsl_context_destroy((__int64)_X19);
LABEL_24:
          result = v17;
          goto LABEL_3;
        }
        v10 = *(_BYTE *)(a3 + 24);
        v26[0] = result;
        if ( (v10 & 4) != 0 )
        {
          v15 = kgsl_drawobj_cmd_add_ibdesc_list(v5, result, *(_QWORD *)(a3 + 8));
          if ( !v15 )
            goto LABEL_14;
        }
        else
        {
          v11 = *(unsigned int *)(a3 + 16);
          v25[0] = *(_QWORD *)(a3 + 8);
          v25[1] = 0;
          v25[2] = v11;
          v25[3] = 0;
          v15 = kgsl_drawobj_cmd_add_ibdesc(v5, result, v25);
          if ( !v15 )
          {
LABEL_14:
            v15 = kgsl_reclaim_to_pinned_state(a1[1]);
            if ( !v15 )
            {
              v16 = *(_DWORD **)(*(_QWORD *)(v5 + 8752) + 72LL);
              if ( *(v16 - 1) != -646102743 )
                __break(0x8228u);
              v15 = ((__int64 (__fastcall *)(__int64 *, unsigned int *, _QWORD *, __int64, __int64))v16)(
                      a1,
                      _X19,
                      v26,
                      1,
                      a3 + 20);
            }
          }
        }
        if ( v15 != -71 && v15 )
          kgsl_drawobj_destroy(v26[0], v12, v13, v14);
        result = v15;
        __asm { PRFM            #0x11, [X19] }
        do
          v23 = __ldxr(_X19);
        while ( __stlxr(v23 - 1, _X19) );
        if ( v23 != 1 )
          goto LABEL_30;
        __dmb(9u);
        goto LABEL_23;
      }
    }
  }
  result = -22;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
