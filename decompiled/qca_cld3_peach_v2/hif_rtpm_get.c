__int64 __fastcall hif_rtpm_get(unsigned __int8 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x19
  int v5; // w9
  __int64 v6; // x1
  unsigned int v7; // w0
  unsigned int v8; // w21
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned int v17; // w11
  __int64 v18; // x21
  int v19; // w0
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x9
  unsigned int v24; // w19
  unsigned int v27; // w9
  unsigned int v30; // w9
  unsigned int v33; // w9

  v2 = gp_hif_rtpm_ctx;
  if ( !gp_hif_rtpm_ctx
    || (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 && (*(_WORD *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 488LL) & 7) != 0 )
  {
    return 0;
  }
  if ( a2 > 0xB )
    return 4294967292LL;
  v4 = *(_QWORD *)(gp_hif_rtpm_ctx + 8LL * a2 + 56);
  if ( !v4 )
    return 4294967292LL;
  v5 = a1;
  result = 7;
  if ( v5 > 1 )
  {
    if ( v5 == 3 )
    {
      _X8 = (unsigned int *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 480LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 + 1, _X8) );
      goto LABEL_43;
    }
    if ( v5 != 2 )
      return result;
    v6 = 4;
    goto LABEL_15;
  }
  if ( v5 )
  {
    v6 = 5;
LABEL_15:
    v7 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), v6);
    if ( (v7 & 0x80000000) != 0 && v7 != -115 )
    {
      v8 = v7;
      qdf_trace_msg(61, 2, "%s: pm_state: %d ret: %d", "hif_rtpm_get", *(_DWORD *)(gp_hif_rtpm_ctx + 188), v7);
      v9 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
      v10 = *(_DWORD *)(v9 + 480);
      do
      {
        if ( !v10 )
          break;
        _X13 = (unsigned int *)(v9 + 480);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v17 = __ldxr(_X13);
          if ( v17 != v10 )
            break;
          if ( !__stlxr(v10 - 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v17 == v10;
        v10 = v17;
      }
      while ( !_ZF );
      goto LABEL_39;
    }
    goto LABEL_43;
  }
  v18 = a2;
  if ( *(int *)(gp_hif_rtpm_ctx + 188) > 2 )
  {
    if ( a2 != 4 )
    {
      if ( a2 == 11 )
      {
        __break(0x5512u);
        goto LABEL_43;
      }
      qdf_trace_msg(61, 5, "%s: request RTPM resume by %d- %s", "hif_rtpm_get", a2, hif_rtpm_id_to_string_strings[a2]);
      v2 = gp_hif_rtpm_ctx;
    }
    _pm_runtime_resume(*(_QWORD *)(v2 + 8), 1);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v23 = gp_hif_rtpm_ctx;
    *(_QWORD *)(gp_hif_rtpm_ctx + 272) = StatusReg;
    *(_QWORD *)(v23 + 280) = v18;
    return 16;
  }
  v19 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 5);
  if ( v19 <= 0 )
  {
    if ( v19 && v19 != -115 )
    {
      v24 = v19;
      qdf_trace_msg(61, 2, "%s: pm_state: %d ret: %d", "hif_rtpm_get", *(_DWORD *)(gp_hif_rtpm_ctx + 188), v19);
      pm_runtime_put_noidle(*(_QWORD *)(gp_hif_rtpm_ctx + 8));
      return v24;
    }
    qdf_spin_lock_bh_0(gp_hif_rtpm_ctx + 16);
    v20 = gp_hif_rtpm_ctx;
    if ( *(int *)(gp_hif_rtpm_ctx + 188) < 3 )
    {
      v8 = 0;
    }
    else
    {
      pm_runtime_put_noidle(*(_QWORD *)(gp_hif_rtpm_ctx + 8));
      __isb(0xFu);
      v21 = _ReadStatusReg(CNTVCT_EL0);
      v20 = gp_hif_rtpm_ctx;
      *(_QWORD *)(gp_hif_rtpm_ctx + 272) = v21;
      *(_QWORD *)(v20 + 280) = v18;
      v8 = 16;
    }
    qdf_spin_unlock_bh(v20 + 16);
LABEL_39:
    result = v8;
    if ( v8 )
      return result;
  }
LABEL_43:
  _X8 = (unsigned int *)(v4 + 8);
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr(_X8);
  while ( __stxr(v27 + 1, _X8) );
  _X8 = (unsigned int *)(v4 + 12);
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 + 1, _X8) );
  __isb(0xFu);
  *(_QWORD *)(v4 + 24) = _ReadStatusReg(CNTVCT_EL0);
  return 0;
}
