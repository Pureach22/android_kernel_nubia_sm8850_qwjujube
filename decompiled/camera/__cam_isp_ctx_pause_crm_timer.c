__int64 __fastcall _cam_isp_ctx_pause_crm_timer(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w9
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x6
  __int64 v6; // x7
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x4
  _DWORD v11[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *(_QWORD *)(result + 216);
    v2 = result;
    if ( v1 )
    {
      v3 = *(_DWORD *)(result + 64);
      v4 = *(__int64 (__fastcall **)(_QWORD))(v1 + 24);
      v11[1] = *(_DWORD *)(result + 60);
      v11[2] = 0;
      v11[0] = v3;
      if ( *((_DWORD *)v4 - 1) != -1398328256 )
        __break(0x8228u);
      result = v4(v11);
      if ( (_DWORD)result )
      {
        v5 = *(unsigned int *)(v2 + 32);
        v6 = *(unsigned int *)(v2 + 64);
        v7 = "Failed to pause sof timer in ctx: %u on link: 0x%x";
        v8 = 8;
        v9 = 1;
        v10 = 982;
LABEL_7:
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                   3,
                   v8,
                   v9,
                   "__cam_isp_ctx_pause_crm_timer",
                   v10,
                   v7,
                   v5,
                   v6);
        goto LABEL_10;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v5 = *(unsigned int *)(v2 + 32);
        v6 = *(unsigned int *)(v2 + 64);
        v7 = "Notify CRM to pause timer for ctx: %u link: 0x%x success";
        v8 = debug_mdl & 8;
        v9 = 4;
        v10 = 987;
        goto LABEL_7;
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
