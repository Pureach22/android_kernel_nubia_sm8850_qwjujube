__int64 __fastcall _cam_req_mgr_inject_delay(__int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x8
  __int64 v5; // x20
  unsigned int v6; // w24
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x6
  __int64 v10; // x1
  __int64 v11; // x4
  const char *v12; // x5
  int v13; // w9
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = a2;
  if ( a1 )
  {
    v3 = a2;
    if ( a2 > 0x30uLL )
LABEL_20:
      __break(0x5512u);
    v5 = a1;
    v6 = 0;
    while ( 1 )
    {
      v7 = v5 + 48 * v3;
      if ( a3 == 2 )
      {
        v13 = *(_DWORD *)(v7 + 60);
        if ( !v13 )
          goto LABEL_13;
        v6 = -11;
        *(_DWORD *)(v7 + 60) = v13 - 1;
        if ( (debug_mdl & 0x10) == 0 || debug_priority )
          goto LABEL_13;
        v9 = *(unsigned int *)(v5 + 4);
        v10 = debug_mdl & 0x10;
        v11 = 204;
        v12 = "Delay injected by pd %d device at EOF, inject_delay_at_eof:%d";
      }
      else
      {
        if ( a3 != 1 )
          goto LABEL_13;
        v8 = *(_DWORD *)(v7 + 56);
        if ( !v8 )
          goto LABEL_13;
        v6 = -11;
        *(_DWORD *)(v7 + 56) = v8 - 1;
        if ( (debug_mdl & 0x10) == 0 || debug_priority )
          goto LABEL_13;
        v9 = *(unsigned int *)(v5 + 4);
        v10 = debug_mdl & 0x10;
        v11 = 197;
        v12 = "Delay injected by pd %d device at SOF, inject_delay_at_sof:%d";
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v10,
        4,
        "__cam_req_mgr_inject_delay",
        v11,
        v12,
        v9);
LABEL_13:
      cam_common_dec_idx(&v15, *(unsigned int *)(v5 + 32));
      v5 = *(_QWORD *)(v5 + 24);
      if ( !v5 )
        goto LABEL_19;
      v3 = v15;
      if ( v15 >= 0x31 )
        goto LABEL_20;
    }
  }
  v6 = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v6;
}
