__int64 __fastcall sde_ds_parse_dt(__int64 a1, __int64 a2)
{
  char v2; // w8
  __int64 v5; // x0
  int *v6; // x19
  unsigned int v7; // w0
  unsigned int v8; // w22
  __int64 v9; // x20
  unsigned int v10; // w0
  __int64 v11; // x21
  int v12; // w11
  int v13; // w8
  int v14; // w9
  int v15; // w10
  int v17; // w11
  int v18; // w9
  int v19; // w8
  int v20; // w11
  unsigned __int64 v21; // x3
  __int64 v22; // x24
  __int64 v23; // x26
  __int64 v24; // x27
  int *v25; // x28
  __int64 v26; // x8
  unsigned __int64 v30; // x10
  int v31; // w9
  int v32; // w10
  __int64 v33; // x25
  unsigned __int64 v34; // x22
  int v35; // w9
  unsigned __int64 v38; // x10
  unsigned __int64 v44; // x10
  unsigned __int64 v47; // x10
  unsigned __int64 StatusReg; // x22
  __int64 v49; // x24
  char v50; // [xsp+Ch] [xbp-34h]
  __int64 v51; // [xsp+10h] [xbp-30h] BYREF
  int v52; // [xsp+18h] [xbp-28h] BYREF
  __int16 v53; // [xsp+1Ch] [xbp-24h] BYREF
  _QWORD v54[2]; // [xsp+20h] [xbp-20h] BYREF
  _QWORD v55[2]; // [xsp+30h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a2 + 708);
  v55[0] = 0;
  v54[0] = 0;
  v54[1] = 0;
  v53 = 0;
  v52 = 0;
  v51 = 0;
  if ( (v2 & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "dest scaler feature not supported\n");
    v5 = 0;
    v9 = 0;
LABEL_9:
    v8 = 0;
    goto LABEL_27;
  }
  v5 = _kvmalloc_node_noprof(3072, 0, 3520, 0xFFFFFFFFLL);
  if ( !v5 )
  {
    v9 = 0;
    v8 = -12;
    goto LABEL_27;
  }
  v6 = (int *)v5;
  v7 = validate_dt_entry(a1, &ds_top_prop, 4, v54, &v51);
  if ( !v7 )
  {
    v7 = read_dt_entry(a1, &ds_top_prop, 4, v54, &v52, v6);
    if ( !v7 )
    {
      v9 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
      if ( !v9 )
        goto LABEL_28;
      v10 = validate_dt_entry(a1, &ds_prop, 2, v55, (char *)&v51 + 4);
      if ( v10 )
      {
        v8 = v10;
        v5 = (__int64)v6;
        goto LABEL_27;
      }
      *(_DWORD *)(a2 + 8840) = HIDWORD(v51);
      v8 = read_dt_entry(a1, &ds_prop, 2, v55, &v53, v9);
      if ( v8 || !HIDWORD(v51) )
      {
        v5 = (__int64)v6;
        goto LABEL_27;
      }
      v11 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
      if ( !v11 )
      {
LABEL_28:
        v8 = -12;
        v5 = (__int64)v6;
        goto LABEL_27;
      }
      while ( 1 )
      {
        *(_DWORD *)(v11 + 16) = 0;
        snprintf((char *)v11, 0x10u, "ds_top_%u", 0);
        v12 = BYTE2(v52);
        v13 = *v6;
        v14 = v6[192];
        *(_DWORD *)(v11 + 60) = 20;
        v15 = v6[384];
        _ZF = v12 == 0;
        v17 = HIBYTE(v52);
        *(_DWORD *)(v11 + 20) = v13;
        *(_DWORD *)(v11 + 24) = v14;
        v18 = v6[576];
        if ( _ZF )
          v19 = 2048;
        else
          v19 = v15;
        _ZF = v17 == 0;
        v20 = HIDWORD(v51);
        if ( _ZF )
          v18 = 2560;
        *(_DWORD *)(v11 + 52) = v19;
        *(_DWORD *)(v11 + 56) = v18;
        if ( !v20 )
          break;
        v21 = 0;
        v22 = -832;
        v23 = 8880;
        v24 = 8848;
        v25 = (int *)v9;
        v50 = HIBYTE(v53);
        v26 = a2;
        while ( v22 )
        {
          v31 = *v25;
          v32 = *(_DWORD *)(v9 + 768);
          v33 = v26 + v22;
          v34 = v21 + 1;
          *(_QWORD *)(v33 + 9736) = v11;
          *(_DWORD *)(v33 + 9696) = v21 + 1;
          *(_DWORD *)(v33 + 9700) = v31;
          *(_DWORD *)(v33 + 9704) = v32;
          snprintf((char *)(v26 + v24), 0x10u, "ds_%u", v21);
          if ( (v50 & 1) == 0 )
            *(_DWORD *)(v33 + 9704) = 256;
          v35 = *(_DWORD *)(a2 + 16);
          v26 = a2;
          v5 = (__int64)v6;
          if ( v35 == 22 )
          {
            _X9 = (unsigned __int64 *)(a2 + v23);
            __asm { PRFM            #0x11, [X9] }
            do
              v47 = __ldxr(_X9);
            while ( __stxr(v47 | 0x400000, _X9) );
          }
          else if ( v35 == 3 )
          {
            _X9 = (unsigned __int64 *)(a2 + v23);
            __asm { PRFM            #0x11, [X9] }
            do
              v44 = __ldxr(_X9);
            while ( __stxr(v44 | 8, _X9) );
          }
          if ( *(_DWORD *)a2 >> 28 >= 9u )
          {
            _X9 = (unsigned __int64 *)(a2 + v23);
            __asm { PRFM            #0x11, [X9] }
            do
              v38 = __ldxr(_X9);
            while ( __stxr(v38 | 2, _X9) );
            _X9 = (unsigned __int64 *)(a2 + v23);
            __asm { PRFM            #0x11, [X9] }
            do
              v30 = __ldxr(_X9);
            while ( __stxr(v30 | 4, _X9) );
          }
          v22 += 64;
          v23 += 64;
          v24 += 64;
          ++v25;
          v21 = v34;
          if ( v34 >= HIDWORD(v51) )
            goto LABEL_9;
        }
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v49 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &sde_ds_parse_dt__alloc_tag_382;
        v11 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v49;
        if ( !v11 )
          goto LABEL_28;
      }
      v5 = (__int64)v6;
      goto LABEL_9;
    }
  }
  v8 = v7;
  v9 = 0;
  v5 = (__int64)v6;
LABEL_27:
  kvfree(v5);
  kvfree(v9);
  _ReadStatusReg(SP_EL0);
  return v8;
}
