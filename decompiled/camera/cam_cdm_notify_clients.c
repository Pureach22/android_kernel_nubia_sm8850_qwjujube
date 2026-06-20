__int64 __fastcall cam_cdm_notify_clients(__int64 result, int a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w7
  __int64 v5; // x19
  _DWORD *v8; // x8
  unsigned int v9; // w7
  __int64 v10; // x1
  __int64 v11; // x9
  __int64 v12; // x26
  __int64 v13; // x27
  __int64 v14; // x19
  __int64 v15; // x20
  __int64 v16; // x1
  _DWORD *v17; // x8
  __int64 v18; // x0
  __int64 v19; // x4
  int v20; // w7
  _DWORD *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x6
  const char *v27; // x5
  __int64 v28; // x2
  __int64 v29; // x4
  __int64 v30; // x0
  _QWORD v31[6]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v32; // [xsp+38h] [xbp-18h]
  __int64 v33; // [xsp+40h] [xbp-10h]
  __int64 v34; // [xsp+48h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  memset(&v31[1], 0, 40);
  if ( !result )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               1,
               1,
               "cam_cdm_notify_clients",
               223,
               "CDM Notify called with NULL hw info");
    goto LABEL_62;
  }
  v3 = *(_QWORD *)(result + 3680);
  if ( a2 > 3 )
  {
    if ( (unsigned int)(a2 - 4) < 4 )
      goto LABEL_4;
    goto LABEL_57;
  }
  if ( !a2 )
  {
    v20 = *(_DWORD *)(a3 + 8);
    v5 = *(_QWORD *)(v3 + 8LL * (unsigned __int8)v20 + 248);
    if ( v5 && *(_DWORD *)(v5 + 328) == v20 )
    {
      mutex_lock(v5 + 280);
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_cdm_get_client_refcount",
          60,
          "CDM client get refcount=%d",
          *(_DWORD *)(v5 + 276));
      ++*(_DWORD *)(v5 + 276);
      mutex_unlock(v5 + 280);
      mutex_lock(v5 + 280);
      v22 = *(_DWORD **)(v5 + 144);
      if ( v22 )
      {
        v23 = a3;
        if ( (debug_mdl & 1) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            4,
            "cam_cdm_notify_clients",
            243,
            "Calling client=%s cb cookie=%d",
            (const char *)v5,
            *(_DWORD *)(a3 + 24));
          v22 = *(_DWORD **)(v5 + 144);
          v23 = a3;
        }
        v24 = *(unsigned int *)(v23 + 8);
        v25 = *(_QWORD *)(v23 + 16);
        if ( *(v22 - 1) != 606103102 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v22)(v24, v25, 0, v23 + 24);
        if ( (debug_mdl & 1) == 0 || debug_priority )
          goto LABEL_60;
        v26 = *(unsigned int *)(a3 + 24);
        v27 = "Exit client cb cookie=%d";
        v28 = 4;
        v29 = 248;
      }
      else
      {
        v26 = *(unsigned int *)(a3 + 8);
        v27 = "No cb registered for client hdl=%x";
        v28 = 1;
        v29 = 251;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        1,
        v28,
        "cam_cdm_notify_clients",
        v29,
        v27,
        v26);
LABEL_60:
      mutex_unlock(v5 + 280);
      v30 = v5;
      goto LABEL_61;
    }
    v19 = 236;
LABEL_42:
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
               3,
               1,
               1,
               "cam_cdm_notify_clients",
               v19,
               "Invalid client %pK hdl=%x",
               v5);
    goto LABEL_62;
  }
  if ( a2 == 1 )
  {
LABEL_4:
    v4 = *(_DWORD *)(a3 + 8);
    v5 = *(_QWORD *)(v3 + 8LL * (unsigned __int8)v4 + 248);
    if ( v5 && *(_DWORD *)(v5 + 328) == v4 )
    {
      mutex_lock(v5 + 280);
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_cdm_get_client_refcount",
          60,
          "CDM client get refcount=%d",
          *(_DWORD *)(v5 + 276));
      ++*(_DWORD *)(v5 + 276);
      mutex_unlock(v5 + 280);
      mutex_lock(v5 + 280);
      v8 = *(_DWORD **)(v5 + 144);
      v9 = *(_DWORD *)(v5 + 328);
      if ( v8 )
      {
        v10 = *(_QWORD *)(v5 + 136);
        if ( *(v8 - 1) != 606103102 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD, __int64, _QWORD, __int64))v8)(v9, v10, (unsigned int)a2, a3 + 24);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_notify_clients",
          281,
          "No cb registered for client: name %s, hdl=%x",
          (const char *)v5,
          v9);
      }
      goto LABEL_60;
    }
    v19 = 267;
    goto LABEL_42;
  }
  if ( a2 != 2 )
  {
LABEL_57:
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               1,
               1,
               "cam_cdm_notify_clients",
               337,
               "Invalid cdm cb status: %u",
               a2);
    goto LABEL_62;
  }
  v11 = 0;
  LODWORD(v12) = 0;
  v13 = v3 + 248;
  do
  {
    if ( *(_QWORD *)(v13 + 8 * v11) )
      v12 = (unsigned int)v11;
    else
      v12 = (unsigned int)v12;
    ++v11;
  }
  while ( v11 != 256 );
  v14 = 0;
  v31[0] = a3;
  LOBYTE(v33) = 1;
  while ( 1 )
  {
    v15 = *(_QWORD *)(v13 + 8 * v14);
    if ( !v15 )
      goto LABEL_25;
    mutex_lock(v15 + 280);
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_get_client_refcount",
        60,
        "CDM client get refcount=%d",
        *(_DWORD *)(v15 + 276));
    ++*(_DWORD *)(v15 + 276);
    mutex_unlock(v15 + 280);
    if ( *(_QWORD *)(v15 + 144) )
      break;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_notify_clients",
      330,
      "No cb registered for client hdl=%x",
      *(_DWORD *)(v15 + 328));
LABEL_24:
    result = cam_cdm_put_client_refcount(v15);
LABEL_25:
    if ( ++v14 == 256 )
      goto LABEL_62;
  }
  if ( v12 == v14 )
    BYTE1(v32) = 1;
  mutex_lock(v15 + 280);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_notify_clients",
      307,
      "Found client slot %d name %s",
      v14,
      (const char *)v15);
  v16 = *(_QWORD *)(v15 + 136);
  v17 = *(_DWORD **)(v15 + 144);
  v18 = *(unsigned int *)(v15 + 328);
  if ( *(v17 - 1) != 606103102 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD *))v17)(v18, v16, 2, v31);
  if ( (v32 & 1) == 0 )
  {
    if ( (v32 & 0x100) != 0 )
      goto LABEL_64;
    mutex_unlock(v15 + 280);
    goto LABEL_24;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_notify_clients",
    319,
    "Page Fault found on client: [%s][%u]",
    (const char *)v15,
    *(_DWORD *)(v15 + 128));
  *(_BYTE *)(v31[0] + 59LL) = v32;
LABEL_64:
  mutex_unlock(v15 + 280);
  v30 = v15;
LABEL_61:
  result = cam_cdm_put_client_refcount(v30);
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
