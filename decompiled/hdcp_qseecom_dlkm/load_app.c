__int64 __fastcall load_app(__int64 a1, int **a2, __int64 (__fastcall **a3)(__int64, __int64, int **, __int64))
{
  __int64 v5; // x0
  int *v6; // x22
  unsigned int client_env_object; // w0
  __int64 v8; // x0
  __int64 (__fastcall *v9)(__int64, _QWORD, int **, __int64); // x9
  unsigned int v10; // w0
  __int64 (__fastcall *v11)(__int64, __int64, int **, __int64); // x21
  _DWORD *v12; // x23
  unsigned int v13; // w0
  __int64 (__fastcall *v14)(__int64, __int64, int **, __int64); // x9
  __int64 (__fastcall *v15)(__int64, __int64, int **, __int64); // x0
  __int64 (__fastcall *v16)(__int64, __int64, int **, __int64); // x8
  unsigned int v17; // w0
  __int64 v18; // x9
  unsigned int v19; // w19
  _DWORD *v20; // x8
  __int64 v21; // x0
  __int64 result; // x0
  __int64 (__fastcall *v23)(__int64, _QWORD, int **, __int64); // [xsp+0h] [xbp-60h] BYREF
  __int64 v24; // [xsp+8h] [xbp-58h]
  __int64 v25; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v26[3]; // [xsp+18h] [xbp-48h] BYREF
  int v27; // [xsp+34h] [xbp-2Ch] BYREF
  int *v28; // [xsp+38h] [xbp-28h] BYREF
  __int64 v29; // [xsp+40h] [xbp-20h]
  _DWORD *v30; // [xsp+48h] [xbp-18h]
  __int64 (__fastcall *v31)(__int64, __int64, int **, __int64); // [xsp+50h] [xbp-10h]
  __int64 v32; // [xsp+58h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  memset(v26, 0, sizeof(v26));
  v23 = nullptr;
  v24 = 0;
  v5 = firmware_request_from_smcinvoke(a1, &v25, v26);
  if ( !v5 )
  {
    printk(&unk_D080);
    result = 4294967274LL;
    goto LABEL_22;
  }
  v6 = (int *)v5;
  client_env_object = get_client_env_object(&v23);
  if ( client_env_object )
  {
    v19 = client_env_object;
    printk(&unk_BFDB);
    v23 = nullptr;
    v24 = 0;
  }
  else
  {
    v9 = v23;
    v8 = v24;
    v27 = 3;
    v30 = nullptr;
    v31 = nullptr;
    v28 = &v27;
    v29 = 4;
    if ( *((_DWORD *)v23 - 1) != 816020464 )
      __break(0x8229u);
    v10 = v9(v8, 0, &v28, 4097);
    if ( !v10 )
    {
      v12 = v30;
      v11 = v31;
      v30 = nullptr;
      v31 = nullptr;
      v28 = v6;
      v29 = v25;
      if ( *(v12 - 1) != 816020464 )
        __break(0x8237u);
      v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD, int **, __int64))v12)(v11, 0, &v28, 4097);
      v14 = v31;
      *a3 = (__int64 (__fastcall *)(__int64, __int64, int **, __int64))v30;
      a3[1] = v14;
      if ( v13 )
      {
        v19 = v13;
        printk(&unk_C557);
        *a3 = nullptr;
        a3[1] = nullptr;
      }
      else
      {
        v16 = *a3;
        v15 = a3[1];
        v28 = nullptr;
        v29 = 0;
        if ( *((_DWORD *)v16 - 1) != 816020464 )
          __break(0x8228u);
        v17 = v16((__int64)v15, 2, &v28, 4096);
        v18 = v29;
        *a2 = v28;
        a2[1] = (int *)v18;
        if ( v17 )
        {
          v19 = v17;
          printk(&unk_C403);
        }
        else
        {
          v19 = 0;
        }
      }
      qtee_shmbridge_free_shm(v26);
      if ( v12 )
      {
        if ( *(v12 - 1) != 816020464 )
          __break(0x8237u);
        ((void (__fastcall *)(__int64 (__fastcall *)(__int64, __int64, int **, __int64), __int64, _QWORD, _QWORD))v12)(
          v11,
          0xFFFF,
          0,
          0);
      }
      v20 = v23;
      if ( !v23 )
        goto LABEL_21;
      goto LABEL_18;
    }
    v19 = v10;
    printk(&unk_C223);
  }
  qtee_shmbridge_free_shm(v26);
  v20 = v23;
  if ( v23 )
  {
LABEL_18:
    v21 = v24;
    if ( *(v20 - 1) != 816020464 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v20)(v21, 0xFFFF, 0, 0);
  }
LABEL_21:
  result = v19;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
