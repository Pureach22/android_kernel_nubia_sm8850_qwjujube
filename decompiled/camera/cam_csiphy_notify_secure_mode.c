__int64 __fastcall cam_csiphy_notify_secure_mode(__int64 a1, char a2, int a3)
{
  int client_env_object; // w0
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, _QWORD, int **, __int64); // x9
  unsigned int v9; // w0
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x11
  int v17; // w9
  __int64 v18; // x19
  _DWORD *v19; // x20
  __int64 v20; // x0
  int v21; // w0
  __int64 v22; // x0
  void (__fastcall *v23)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 result; // x0
  unsigned int v25; // w0
  __int64 v26; // x0
  __int64 (__fastcall *v27)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v28; // [xsp+8h] [xbp-68h] BYREF
  __int64 v29; // [xsp+10h] [xbp-60h]
  __int64 v30; // [xsp+18h] [xbp-58h]
  __int64 v31; // [xsp+20h] [xbp-50h]
  __int64 v32; // [xsp+28h] [xbp-48h]
  __int64 (__fastcall *v33)(__int64, _QWORD, int **, __int64); // [xsp+30h] [xbp-40h] BYREF
  __int64 v34; // [xsp+38h] [xbp-38h]
  int v35; // [xsp+44h] [xbp-2Ch] BYREF
  int *v36; // [xsp+48h] [xbp-28h] BYREF
  __int64 v37; // [xsp+50h] [xbp-20h]
  _DWORD *v38; // [xsp+58h] [xbp-18h]
  __int64 v39; // [xsp+60h] [xbp-10h]
  __int64 v40; // [xsp+68h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = nullptr;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v28 = 0;
  if ( a3 >= 3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_notify_secure_mode",
      402,
      "Invalid CSIPHY offset");
    goto LABEL_20;
  }
  client_env_object = get_client_env_object(&v33);
  if ( client_env_object )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_notify_secure_mode",
      411,
      "Failed getting mink env object, rc: %d",
      client_env_object);
    goto LABEL_20;
  }
  v8 = v33;
  v7 = v34;
  v35 = 283;
  v38 = nullptr;
  v39 = 0;
  v36 = &v35;
  v37 = 4;
  if ( *((_DWORD *)v33 - 1) != 816020464 )
    __break(0x8229u);
  v9 = v8(v7, 0, &v36, 4097);
  if ( v9 )
  {
    v10 = v9;
    v11 = "Failed getting mink sc_object, rc: %d";
    v12 = 417;
    goto LABEL_9;
  }
  if ( (unsigned int)a3 < 3 )
  {
    v13 = a1 + 104LL * (unsigned int)a3;
    v14 = *(_DWORD *)(v13 + 676);
    v15 = *(_QWORD *)(v13 + 664);
    v16 = *(_QWORD *)(v13 + 640);
    LODWORD(v13) = *(_DWORD *)(v13 + 672);
    HIDWORD(v29) = v14;
    v17 = a2 & 1;
    v19 = v38;
    v18 = v39;
    HIDWORD(v28) = v17;
    LODWORD(v29) = v13;
    v30 = v15;
    v31 = v16;
    v36 = (int *)&v28;
    v37 = 40;
    v20 = v39;
    if ( *(v38 - 1) != 816020464 )
      __break(0x8234u);
    v21 = ((__int64 (__fastcall *)(__int64, _QWORD, int **, __int64))v19)(v20, 0, &v36, 1);
    if ( v21 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_notify_secure_mode",
        432,
        "Mink secure call failed, rc: %d",
        v21);
      if ( *(v19 - 1) != 816020464 )
        __break(0x8234u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v19)(v18, 0xFFFF, 0, 0);
      goto LABEL_17;
    }
    if ( *(v19 - 1) != 816020464 )
      __break(0x8234u);
    v25 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v19)(v18, 0xFFFF, 0, 0);
    if ( !v25 )
    {
      v27 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33;
      v26 = v34;
      if ( *((_DWORD *)v33 - 1) != 816020464 )
        __break(0x8228u);
      result = v27(v26, 0xFFFF, 0, 0);
      if ( !(_DWORD)result )
        goto LABEL_21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_notify_secure_mode",
        446,
        "Failed releasing mink env object, rc: %d",
        result);
LABEL_20:
      result = 4294967274LL;
LABEL_21:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v10 = v25;
    v11 = "Failed releasing secure camera object, rc: %d";
    v12 = 439;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_notify_secure_mode",
      v12,
      v11,
      v10);
LABEL_17:
    v23 = (void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33;
    v22 = v34;
    if ( *((_DWORD *)v33 - 1) != 816020464 )
      __break(0x8228u);
    v23(v22, 0xFFFF, 0, 0);
    goto LABEL_20;
  }
  __break(0x5512u);
  return cam_update_camnoc_qos_settings();
}
