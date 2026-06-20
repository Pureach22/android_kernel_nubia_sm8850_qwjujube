__int64 __fastcall kgsl_ioctl_gpu_aux_command(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x22
  unsigned int v5; // w1
  __int64 owner; // x0
  __int64 v8; // x28
  int v10; // w8
  unsigned __int64 v11; // x20
  unsigned __int64 *v12; // x21
  __int64 v13; // x25
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x26
  size_t v17; // x27
  __int64 result; // x0
  unsigned __int64 timestamp_syncobj; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x2
  int v26; // w8
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  void (__fastcall *v33)(__int64, unsigned int *, __int64, unsigned int *); // x8
  __int64 v34; // x2
  __int64 v35; // x3
  __int64 v36; // x3
  _DWORD *v37; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v39; // x26
  int v46; // w8
  unsigned int v47; // [xsp+8h] [xbp-28h]
  unsigned int v48; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v49[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v50; // [xsp+20h] [xbp-10h]
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a3 + 20) != 1
    || (v3 = a3, (*(_QWORD *)a3 & 3LL) == 0)
    || (v4 = *a1, (*(_QWORD *)a3 & 0x400) != 0) && *(_DWORD *)(a3 + 36) > 0x20u
    || (v5 = *(_DWORD *)(a3 + 40), v49[1] = 0, v50 = 0, v49[0] = 0, (owner = kgsl_context_get_owner(a1, v5)) == 0) )
  {
    result = -22;
    goto LABEL_20;
  }
  v8 = *(_QWORD *)v3;
  _X19 = (unsigned int *)owner;
  if ( (*(_QWORD *)v3 & 0x400LL) != 0 )
    v10 = 3;
  else
    v10 = 2;
  v11 = (unsigned int)(8 * v10);
  v12 = (unsigned __int64 *)_kvmalloc_node_noprof(v11, 0, 77248, 0xFFFFFFFFLL);
  if ( !v12 )
  {
LABEL_65:
    __asm { PRFM            #0x11, [X19] }
    do
      v46 = __ldxr(_X19);
    while ( __stlxr(v46 - 1, _X19) );
    if ( v46 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X19);
    }
    else if ( v46 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    result = -12;
    goto LABEL_20;
  }
  while ( 1 )
  {
    v13 = v3 + 44;
    if ( (*(_BYTE *)(v3 + 1) & 4) != 0 )
    {
      timestamp_syncobj = kgsl_drawobj_sync_create(v4, _X19);
      if ( timestamp_syncobj >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_67;
      v23 = *(unsigned int *)(v3 + 32);
      v24 = *(unsigned int *)(v3 + 36);
      v25 = *(_QWORD *)(v3 + 24);
      *v12 = timestamp_syncobj;
      LODWORD(timestamp_syncobj) = kgsl_drawobj_sync_add_synclist(v4, timestamp_syncobj, v25, v23, v24);
      if ( (_DWORD)timestamp_syncobj )
        goto LABEL_23;
      v47 = 1;
    }
    else
    {
      v47 = 0;
    }
    v14 = *(unsigned int *)(v3 + 16);
    v15 = 24;
    v16 = *(_QWORD *)(v3 + 8);
    if ( v14 >= 0x18 )
      v17 = 24;
    else
      v17 = *(unsigned int *)(v3 + 16);
    if ( v14 > 0x18 )
      v15 = *(unsigned int *)(v3 + 16);
    if ( (unsigned int)v14 > 0x17 )
    {
      if ( (_DWORD)v14 != 24 && (int)check_zeroed_user(v16 + v17, v15 - v17) < 1 )
      {
LABEL_27:
        timestamp_syncobj = -14;
        goto LABEL_67;
      }
    }
    else
    {
      memset((char *)v49 + v17, 0, v15 - v17);
    }
    _check_object_size(v49, v17, 0);
    if ( inline_copy_from_user_0((int)v49, v16, v17) )
      goto LABEL_27;
    if ( (_DWORD)v50 == 2 )
    {
      timestamp_syncobj = kgsl_drawobj_timeline_create(v4, _X19);
      if ( timestamp_syncobj >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_67;
      v35 = *(unsigned int *)(v3 + 16);
      v3 = v47;
      v12[v47] = timestamp_syncobj;
      LODWORD(timestamp_syncobj) = kgsl_drawobj_add_timeline(a1, timestamp_syncobj, v16, v35);
      if ( !(_DWORD)timestamp_syncobj )
      {
        timestamp_syncobj = kgsl_drawobj_cmd_create(v4, _X19, 2, 2);
        if ( timestamp_syncobj >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_67;
        v26 = v47 + 1;
        if ( v11 - 8LL * (v47 + 1) < 8 )
          goto LABEL_64;
        v12[v26] = timestamp_syncobj;
LABEL_60:
        v37 = *(_DWORD **)(*(_QWORD *)(v4 + 8752) + 72LL);
        if ( *(v37 - 1) != -646102743 )
          __break(0x8228u);
        LODWORD(timestamp_syncobj) = ((__int64 (__fastcall *)(__int64 *, unsigned int *, unsigned __int64 *, _QWORD, __int64))v37)(
                                       a1,
                                       _X19,
                                       v12,
                                       (unsigned int)v3 | 2,
                                       v13);
      }
LABEL_23:
      timestamp_syncobj = (int)timestamp_syncobj;
      goto LABEL_67;
    }
    if ( (_DWORD)v50 != 1 )
    {
      timestamp_syncobj = -22;
      goto LABEL_67;
    }
    v48 = 0;
    if ( v4 )
    {
      v33 = *(void (__fastcall **)(__int64, unsigned int *, __int64, unsigned int *))(*(_QWORD *)(v4 + 8752) + 64LL);
      if ( *((_DWORD *)v33 - 1) != -362688460 )
        __break(0x8228u);
      v33(v4, _X19, 3, &v48);
      v34 = v48;
    }
    else
    {
      v34 = 0;
    }
    timestamp_syncobj = kgsl_drawobj_create_timestamp_syncobj(v4, _X19, v34);
    if ( timestamp_syncobj < 0xFFFFFFFFFFFFF001LL )
    {
      v12[v47] = timestamp_syncobj;
      timestamp_syncobj = kgsl_drawobj_bind_create(v4, _X19);
      if ( timestamp_syncobj < 0xFFFFFFFFFFFFF001LL )
      {
        v26 = v47 + 1;
        if ( v11 - 8LL * (v47 + 1) < 8 )
          goto LABEL_64;
        v36 = *(unsigned int *)(v3 + 16);
        v12[v26] = timestamp_syncobj;
        LODWORD(timestamp_syncobj) = kgsl_drawobj_add_bind(a1, timestamp_syncobj, v16, v36);
        if ( !(_DWORD)timestamp_syncobj )
        {
          v3 = v47;
          goto LABEL_60;
        }
        goto LABEL_23;
      }
    }
LABEL_67:
    __asm { PRFM            #0x11, [X19] }
    do
      v26 = __ldxr(_X19);
    while ( __stlxr(v26 - 1, _X19) );
    v4 = timestamp_syncobj;
    if ( v26 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X19);
    }
    else
    {
      if ( v26 > 0 )
        goto LABEL_33;
      refcount_warn_saturate(_X19, 3);
    }
    timestamp_syncobj = v4;
LABEL_33:
    if ( timestamp_syncobj == -71 || !timestamp_syncobj )
      goto LABEL_40;
    if ( v11 >= 8 )
    {
      kgsl_drawobj_destroy(*v12, v20, v21, v22);
      v26 = v11 & 0x7FFFFFF8;
      if ( (v11 & 0x7FFFFFF8) != 8 )
      {
        kgsl_drawobj_destroy(v12[1], v27, v28, v29);
        if ( (v8 & 0x400) == 0 )
          goto LABEL_40;
        v26 = v11 & 0x7FFFFFF8;
        if ( (v11 & 0x7FFFFFF8) != 0x10 )
          break;
      }
    }
LABEL_64:
    __break(1u);
    v11 = (unsigned int)(8 * v26);
    StatusReg = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &kgsl_ioctl_gpu_aux_command__alloc_tag;
    v12 = (unsigned __int64 *)_kvmalloc_node_noprof(v11, 0, 77248, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v39;
    if ( !v12 )
      goto LABEL_65;
  }
  kgsl_drawobj_destroy(v12[2], v30, v31, v32);
LABEL_40:
  kvfree(v12);
  result = v4;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
