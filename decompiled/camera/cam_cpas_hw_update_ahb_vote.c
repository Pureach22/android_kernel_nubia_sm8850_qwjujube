__int64 __fastcall cam_cpas_hw_update_ahb_vote(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 v3; // x9
  __int64 v5; // x22
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x7
  unsigned int v9; // w19
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // [xsp+28h] [xbp-18h] BYREF
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_ahb_vote",
      2722,
      "Invalid input arg");
    result = 4294967274LL;
    goto LABEL_18;
  }
  v3 = a3[1];
  v5 = *(_QWORD *)(a1 + 3680);
  v12 = *a3;
  v13 = v3;
  if ( !(_DWORD)v3 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      v11 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_hw_update_ahb_vote",
        2730,
        "0 ahb vote from client %d",
        a2);
      a1 = v11;
    }
    LODWORD(v12) = 0;
    LODWORD(v13) = 2;
    if ( a2 <= 0x2A )
      goto LABEL_4;
LABEL_15:
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( a2 > 0x2A )
    goto LABEL_15;
LABEL_4:
  v6 = a1;
  mutex_lock(a1);
  v7 = v5 + 48LL * a2;
  mutex_lock(v7 + 664);
  v8 = *(_QWORD *)(v5 + 320 + 8LL * a2);
  if ( *(_BYTE *)(v8 + 168) == 1 && (*(_BYTE *)(v8 + 169) & 1) != 0 )
  {
    if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000004,
        4,
        "cam_cpas_hw_update_ahb_vote",
        2755,
        "client=[%d][%s][%d] : type[%d], level[%d], freq[%ld], applied[%d]",
        a2,
        (const char *)v8,
        *(_DWORD *)(v8 + 128),
        v12,
        v13,
        v13,
        *(_DWORD *)(v8 + 172));
      v8 = *(_QWORD *)(v5 + 320 + 8LL * a2);
    }
    v9 = cam_cpas_util_apply_client_ahb_vote(v6, v8, &v12, nullptr);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_ahb_vote",
      2745,
      "client=[%d][%s][%d] has not started",
      a2);
    v9 = -1;
  }
  mutex_unlock(v7 + 664);
  mutex_unlock(v6);
  result = v9;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
