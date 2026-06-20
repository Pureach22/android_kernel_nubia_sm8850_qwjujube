__int64 __fastcall fastrpc_init_attach(__int64 a1, int a2)
{
  int v3; // w8
  char v4; // w9
  __int64 v6; // x0
  int v7; // w8
  int v8; // w8
  const char *v9; // x8
  __int64 result; // x0
  __int64 v11; // x1
  __int64 v12; // x9
  __int64 v13; // x8
  int v14; // [xsp+0h] [xbp-A0h] BYREF
  unsigned int v15; // [xsp+4h] [xbp-9Ch] BYREF
  _QWORD v16[15]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v17[2]; // [xsp+80h] [xbp-20h] BYREF
  __int64 v18; // [xsp+90h] [xbp-10h]
  __int64 v19; // [xsp+98h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 244);
  v4 = *(_BYTE *)(a1 + 304);
  v18 = 0;
  v14 = v3;
  if ( (v4 & 1) == 0 )
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "untrusted app trying to attach to privileged DSP PD\n");
    result = 4294967283LL;
    goto LABEL_25;
  }
  v6 = fastrpc_session_alloc(a1, 0, *(_DWORD *)(a1 + 268));
  if ( !v6 )
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "No session available\n");
    result = 4294967280LL;
    goto LABEL_25;
  }
  v7 = *(_DWORD *)(a1 + 268);
  *(_QWORD *)(a1 + 136) = v6;
  if ( v7 )
  {
    if ( a2 != 3 )
    {
LABEL_17:
      memset(&v16[2], 0, 104);
      v17[0] = &v14;
      v17[1] = 4;
      LODWORD(v18) = -1;
      v16[0] = 0x1000000000001LL;
      v16[1] = v17;
      result = fastrpc_internal_invoke(a1, 1u, (int *)v16);
      if ( !(_DWORD)result )
      {
        if ( a1 )
          fastrpc_create_session_debugfs(a1);
        result = 0;
      }
      goto LABEL_25;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 268) = a2;
    if ( a2 != 3 )
      goto LABEL_17;
  }
  v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 60LL);
  if ( v8 == 2 )
  {
    v9 = "sensors_pdr_adsp";
  }
  else
  {
    if ( v8 != 3 )
      goto LABEL_12;
    v9 = "sensors_pdr_slpi";
  }
  *(_QWORD *)(a1 + 312) = v9;
LABEL_12:
  v15 = 0;
  if ( !a1 )
  {
    result = 4294967287LL;
    goto LABEL_25;
  }
  result = fastrpc_get_static_pd_session(a1, &v15);
  if ( (_DWORD)result )
  {
LABEL_25:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v15 < 4 )
  {
    v12 = *(_QWORD *)(a1 + 128) + 51376LL;
    if ( *(_DWORD *)(v12 + 56LL * v15 + 40) )
    {
      v13 = v12 + 56LL * v15;
      *(_QWORD *)(a1 + 184) = v13;
      *(_QWORD *)(v13 + 32) = *(_QWORD *)(v13 + 24);
      goto LABEL_17;
    }
    result = 4294967189LL;
    goto LABEL_25;
  }
  __break(0x5512u);
  return fastrpc_internal_control(result, v11);
}
