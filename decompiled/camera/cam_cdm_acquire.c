__int64 __fastcall cam_cdm_acquire(__int64 a1)
{
  __int64 result; // x0
  int v3; // w20
  __int64 v4; // x0
  __int64 v5; // x20
  char *v6; // x22
  unsigned __int64 v7; // x21
  __int64 v8; // x25
  __int64 v9; // x23
  char v10; // w27
  int v11; // w28
  unsigned __int64 v12; // x8
  const char *v13; // x24
  unsigned __int64 v14; // x9
  __int64 v15; // x21
  char v16; // w10
  int v17; // w8
  _DWORD *v18; // x8
  __int64 v19; // x0
  unsigned int v20; // w20
  char s2[8]; // [xsp+10h] [xbp-130h] BYREF
  __int64 v22; // [xsp+18h] [xbp-128h]
  __int64 v23; // [xsp+20h] [xbp-120h]
  __int64 v24; // [xsp+28h] [xbp-118h]
  __int64 v25; // [xsp+30h] [xbp-110h]
  __int64 v26; // [xsp+38h] [xbp-108h]
  __int64 v27; // [xsp+40h] [xbp-100h]
  __int64 v28; // [xsp+48h] [xbp-F8h]
  __int64 v29; // [xsp+50h] [xbp-F0h]
  __int64 v30; // [xsp+58h] [xbp-E8h]
  __int64 v31; // [xsp+60h] [xbp-E0h]
  __int64 v32; // [xsp+68h] [xbp-D8h]
  __int64 v33; // [xsp+70h] [xbp-D0h]
  __int64 v34; // [xsp+78h] [xbp-C8h]
  __int64 v35; // [xsp+80h] [xbp-C0h]
  __int64 v36; // [xsp+88h] [xbp-B8h]
  __int64 v37; // [xsp+90h] [xbp-B0h]
  __int64 v38; // [xsp+98h] [xbp-A8h]
  __int64 v39; // [xsp+A0h] [xbp-A0h]
  __int64 v40; // [xsp+A8h] [xbp-98h]
  char s[8]; // [xsp+B0h] [xbp-90h] BYREF
  __int64 v42; // [xsp+B8h] [xbp-88h]
  __int64 v43; // [xsp+C0h] [xbp-80h]
  __int64 v44; // [xsp+C8h] [xbp-78h]
  __int64 v45; // [xsp+D0h] [xbp-70h]
  __int64 v46; // [xsp+D8h] [xbp-68h]
  __int64 v47; // [xsp+E0h] [xbp-60h]
  __int64 v48; // [xsp+E8h] [xbp-58h]
  __int64 v49; // [xsp+F0h] [xbp-50h]
  __int64 v50; // [xsp+F8h] [xbp-48h]
  __int64 v51; // [xsp+100h] [xbp-40h]
  __int64 v52; // [xsp+108h] [xbp-38h]
  __int64 v53; // [xsp+110h] [xbp-30h]
  __int64 v54; // [xsp+118h] [xbp-28h]
  __int64 v55; // [xsp+120h] [xbp-20h]
  __int64 v56; // [xsp+128h] [xbp-18h]
  __int64 v57; // [xsp+130h] [xbp-10h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_DWORD *)(a1 + 152) )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( (unsigned int)get_cdm_mgr_refcount() )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      181,
      "CDM intf mgr get refcount failed");
    result = 0xFFFFFFFFLL;
    goto LABEL_6;
  }
  if ( *(_DWORD *)(a1 + 132) >= 2u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      187,
      "only CAM_CDM_VIRTUAL/CAM_CDM_HW_ANY is supported");
    goto LABEL_45;
  }
  v3 = *(_DWORD *)(a1 + 128);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  *(_QWORD *)s = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  *(_QWORD *)s2 = 0;
  v22 = 0;
  snprintf(s, 0x80u, "%s", (const char *)a1);
  snprintf(s2, 0xA0u, "%s%d", (const char *)a1, v3);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "get_cdm_index_by_id",
      91,
      "Looking for HW id of =%s or %s and index=%d cdm_count %d",
      (const char *)a1,
      s2,
      v3,
      dword_394234);
  v4 = mutex_lock(&cam_cdm_mgr_lock);
  if ( !dword_394234 )
  {
LABEL_43:
    mutex_unlock(&cam_cdm_mgr_lock);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      194,
      "Failed to identify associated hw id");
LABEL_45:
    v20 = -1;
LABEL_46:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      222,
      "CDM acquire failed for id=%d name=%s, idx=%d",
      *(_DWORD *)(a1 + 132),
      (const char *)a1,
      *(_DWORD *)(a1 + 128));
    put_cdm_mgr_refcount();
    result = v20;
    goto LABEL_6;
  }
  v5 = 0;
  while ( 1 )
  {
    if ( v5 == 16 )
      goto LABEL_47;
    v6 = &cdm_mgr[72 * v5];
    v4 = mutex_lock(v6 + 16);
    v7 = 72 * v5 - 1096;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      if ( v7 < 0xFFFFFFFFFFFFFB68LL )
      {
LABEL_32:
        __break(1u);
        goto LABEL_33;
      }
      v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             1,
             4,
             "get_cdm_index_by_id",
             96,
             "dt_num_supported_clients=%d",
             *(_DWORD *)(*((_QWORD *)v6 + 10) + 20LL));
    }
    else if ( v7 < 0xFFFFFFFFFFFFFB68LL )
    {
      goto LABEL_32;
    }
    v8 = *((_QWORD *)v6 + 10);
    if ( *(_DWORD *)(v8 + 20) )
      break;
LABEL_14:
    v4 = mutex_unlock(v6 + 16);
    if ( ++v5 >= (unsigned __int64)(unsigned int)dword_394234 )
      goto LABEL_43;
  }
  v9 = 4;
  v10 = debug_mdl;
  v11 = debug_priority;
  while ( 1 )
  {
    v12 = v9 - 4;
    if ( (v10 & 1) != 0 && !v11 )
    {
      if ( v12 > 0xFF )
        goto LABEL_47;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "get_cdm_index_by_id",
        102,
        "client name:%s dev Index: %d",
        *(const char **)(v8 + 8 * v9),
        v5);
      v8 = *((_QWORD *)v6 + 10);
      v10 = debug_mdl;
      v11 = debug_priority;
    }
    else if ( v12 > 0xFF )
    {
      goto LABEL_47;
    }
    v13 = *(const char **)(v8 + 8 * v9);
    if ( !strcmp(v13, s) )
      break;
    v4 = strcmp(v13, s2);
    if ( !(_DWORD)v4 )
      break;
    v14 = v9 - 3;
    ++v9;
    if ( v14 >= *(unsigned int *)(v8 + 20) )
      goto LABEL_14;
  }
LABEL_33:
  mutex_unlock(v6 + 16);
  v4 = mutex_unlock(&cam_cdm_mgr_lock);
  if ( (unsigned int)v5 >= 0x10 )
  {
LABEL_47:
    __break(0x5512u);
    return cam_cdm_publish_ops(v4);
  }
  v15 = *(_QWORD *)&cdm_mgr[72 * (v5 & 0xF) + 72];
  if ( !v15 || !*(_QWORD *)(v15 + 88) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      215,
      "idx %d doesn't have acquire ops",
      v5);
    goto LABEL_45;
  }
  v16 = debug_mdl;
  v17 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v15 + 112) + 3680LL) + 132LL);
  *(_DWORD *)(a1 + 132) = v17;
  *(_DWORD *)(a1 + 260) = *(_DWORD *)(v15 + 4);
  if ( (v16 & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_acquire",
      205,
      "Device = %s, hw_index = %d, CDM id = %d",
      (const char *)a1,
      v5,
      v17);
  v18 = *(_DWORD **)(v15 + 88);
  v19 = *(_QWORD *)(v15 + 112);
  if ( *(v18 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v18)(v19, 0, a1, 264);
  if ( (result & 0x80000000) != 0 )
  {
    v20 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_acquire",
      210,
      "CDM hw acquire failed");
    goto LABEL_46;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
