__int64 __fastcall cam_ife_mgr_bw_control(__int64 result, int a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x25
  __int64 v5; // x6
  __int64 v6; // x2
  __int64 v7; // x4
  const char *v8; // x5
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 (__fastcall *v11)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v12; // x0
  __int64 v13; // x6
  __int64 v14; // x2
  __int64 v15; // x4
  const char *v16; // x5
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 (__fastcall *v19)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v20; // x0
  _QWORD *v21; // x25
  __int64 v22; // x6
  __int64 v23; // x2
  __int64 v24; // x4
  const char *v25; // x5
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 (__fastcall *v28)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v29; // x0
  __int64 v30; // x6
  __int64 v31; // x2
  __int64 v32; // x4
  const char *v33; // x5
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 (__fastcall *v36)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v37; // x0
  __int64 v38; // [xsp+8h] [xbp-18h] BYREF
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v3 = result;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_mgr_bw_control",
               8410,
               "Enter...ctx id:%u",
               *(_DWORD *)(result + 56));
  v4 = *(_QWORD **)(v3 + 224);
  if ( v4 != (_QWORD *)(v3 + 224) )
  {
    while ( 1 )
    {
      v9 = v4[4];
      if ( !v9 )
        goto LABEL_18;
      v10 = *(_QWORD *)(v9 + 16);
      if ( !v10 )
        break;
      v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v10 + 88);
      if ( !v11 )
        break;
      v12 = *(_QWORD *)(v10 + 112);
      v38 = v4[4];
      LODWORD(v39) = a2;
      if ( *((_DWORD *)v11 - 1) != -1055839300 )
        __break(0x8228u);
      result = v11(v12, 12, &v38, 16);
      if ( (_DWORD)result )
      {
        v13 = *(unsigned int *)(v3 + 56);
        v14 = 1;
        v15 = 8430;
        v16 = "BW Update failed, ctx id:%u";
LABEL_17:
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   8,
                   v14,
                   "cam_ife_mgr_bw_control",
                   v15,
                   v16,
                   v13);
      }
LABEL_18:
      v17 = v4[5];
      if ( v17 )
      {
        v18 = *(_QWORD *)(v17 + 16);
        if ( v18 && (v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v18 + 88)) != nullptr )
        {
          v20 = *(_QWORD *)(v18 + 112);
          v38 = v4[5];
          LODWORD(v39) = a2;
          if ( *((_DWORD *)v19 - 1) != -1055839300 )
            __break(0x8228u);
          result = v19(v20, 12, &v38, 16);
          if ( !(_DWORD)result )
            goto LABEL_8;
          v5 = *(unsigned int *)(v3 + 56);
          v6 = 1;
          v7 = 8430;
          v8 = "BW Update failed, ctx id:%u";
        }
        else
        {
          v5 = *(unsigned int *)(v3 + 56);
          v6 = 2;
          v7 = 8432;
          v8 = "NULL hw_intf!, ctx id:%u";
        }
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   8,
                   v6,
                   "cam_ife_mgr_bw_control",
                   v7,
                   v8,
                   v5);
      }
LABEL_8:
      v4 = (_QWORD *)*v4;
      if ( v4 == (_QWORD *)(v3 + 224) )
        goto LABEL_25;
    }
    v13 = *(unsigned int *)(v3 + 56);
    v14 = 2;
    v15 = 8432;
    v16 = "NULL hw_intf!, ctx id:%u";
    goto LABEL_17;
  }
LABEL_25:
  v21 = *(_QWORD **)(v3 + 240);
  if ( v21 != (_QWORD *)(v3 + 240) )
  {
    while ( 1 )
    {
      v26 = v21[4];
      if ( !v26 )
        goto LABEL_39;
      v27 = *(_QWORD *)(v26 + 16);
      if ( !v27 )
        break;
      v28 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v27 + 88);
      if ( !v28 )
        break;
      v29 = *(_QWORD *)(v27 + 112);
      v38 = v21[4];
      LODWORD(v39) = a2;
      if ( *((_DWORD *)v28 - 1) != -1055839300 )
        __break(0x8228u);
      result = v28(v29, 12, &v38, 16);
      if ( (_DWORD)result )
      {
        v30 = *(unsigned int *)(v3 + 56);
        v31 = 1;
        v32 = 8454;
        v33 = "BW Update failed, ctx id:%u";
LABEL_38:
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   8,
                   v31,
                   "cam_ife_mgr_bw_control",
                   v32,
                   v33,
                   v30);
      }
LABEL_39:
      v34 = v21[5];
      if ( v34 )
      {
        v35 = *(_QWORD *)(v34 + 16);
        if ( v35 && (v36 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v35 + 88)) != nullptr )
        {
          v37 = *(_QWORD *)(v35 + 112);
          v38 = v21[5];
          LODWORD(v39) = a2;
          if ( *((_DWORD *)v36 - 1) != -1055839300 )
            __break(0x8228u);
          result = v36(v37, 12, &v38, 16);
          if ( !(_DWORD)result )
            goto LABEL_29;
          v22 = *(unsigned int *)(v3 + 56);
          v23 = 1;
          v24 = 8454;
          v25 = "BW Update failed, ctx id:%u";
        }
        else
        {
          v22 = *(unsigned int *)(v3 + 56);
          v23 = 2;
          v24 = 8456;
          v25 = "NULL hw_intf! ctx id:%u";
        }
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   8,
                   v23,
                   "cam_ife_mgr_bw_control",
                   v24,
                   v25,
                   v22);
      }
LABEL_29:
      v21 = (_QWORD *)*v21;
      if ( v21 == (_QWORD *)(v3 + 240) )
        goto LABEL_46;
    }
    v30 = *(unsigned int *)(v3 + 56);
    v31 = 2;
    v32 = 8456;
    v33 = "NULL hw_intf! ctx id:%u";
    goto LABEL_38;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
