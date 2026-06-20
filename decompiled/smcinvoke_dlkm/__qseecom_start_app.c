__int64 __fastcall _qseecom_start_app(__int64 *a1, const char *a2, unsigned int a3)
{
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x19
  unsigned int client_env_object; // w0
  __int64 v12; // x0
  _DWORD *v13; // x9
  unsigned int v14; // w0
  __int64 v15; // x9
  size_t v16; // x0
  size_t v17; // x0
  __int64 v18; // x0
  __int64 (__fastcall *v19)(__int64, __int64, const char **, __int64); // x8
  int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x9
  __int64 v23; // x2
  __int64 v24; // x8
  size_t v25; // x2
  __int64 v26; // x2
  char *v27; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  char *v30; // x23
  size_t v31; // x0
  __int64 v32; // x0
  __int64 (__fastcall *v33)(__int64, __int64, const char **, __int64); // x9
  unsigned int v34; // w0
  __int64 v35; // x10
  unsigned int v36; // w21
  __int64 v37; // x0
  _DWORD *v38; // x9
  __int64 v39; // x0
  _DWORD *v40; // x9
  __int64 v41; // x0
  _DWORD *v42; // x9
  __int64 v43; // x0
  int v44; // [xsp+4h] [xbp-16Ch] BYREF
  _QWORD v45[3]; // [xsp+8h] [xbp-168h] BYREF
  size_t v46; // [xsp+20h] [xbp-150h] BYREF
  const char **v47; // [xsp+28h] [xbp-148h] BYREF
  __int64 v48; // [xsp+30h] [xbp-140h]
  __int64 v49; // [xsp+38h] [xbp-138h]
  __int64 v50; // [xsp+40h] [xbp-130h]
  __int64 v51; // [xsp+48h] [xbp-128h]
  __int64 v52; // [xsp+50h] [xbp-120h]
  __int64 v53; // [xsp+58h] [xbp-118h]
  __int64 v54; // [xsp+60h] [xbp-110h]
  __int64 v55; // [xsp+68h] [xbp-108h]
  __int64 v56; // [xsp+70h] [xbp-100h]
  __int64 v57; // [xsp+78h] [xbp-F8h]
  __int64 v58; // [xsp+80h] [xbp-F0h]
  __int64 v59; // [xsp+88h] [xbp-E8h]
  __int64 v60; // [xsp+90h] [xbp-E0h]
  __int64 v61; // [xsp+98h] [xbp-D8h]
  __int64 v62; // [xsp+A0h] [xbp-D0h]
  __int64 v63; // [xsp+A8h] [xbp-C8h]
  __int64 v64; // [xsp+B0h] [xbp-C0h]
  __int64 v65; // [xsp+B8h] [xbp-B8h]
  __int64 v66; // [xsp+C0h] [xbp-B0h]
  __int64 v67; // [xsp+C8h] [xbp-A8h]
  __int64 v68; // [xsp+D0h] [xbp-A0h]
  __int64 v69; // [xsp+D8h] [xbp-98h]
  __int64 v70; // [xsp+E0h] [xbp-90h]
  __int64 v71; // [xsp+E8h] [xbp-88h]
  __int64 v72; // [xsp+F0h] [xbp-80h]
  __int64 v73; // [xsp+F8h] [xbp-78h]
  __int64 v74; // [xsp+100h] [xbp-70h]
  __int64 v75; // [xsp+108h] [xbp-68h]
  __int64 v76; // [xsp+110h] [xbp-60h]
  __int64 v77; // [xsp+118h] [xbp-58h]
  __int64 v78; // [xsp+120h] [xbp-50h]
  const char *v79; // [xsp+128h] [xbp-48h] BYREF
  size_t v80; // [xsp+130h] [xbp-40h]
  const char *v81; // [xsp+138h] [xbp-38h]
  __int64 v82; // [xsp+140h] [xbp-30h]
  const char ***v83; // [xsp+148h] [xbp-28h]
  __int64 v84; // [xsp+150h] [xbp-20h]
  __int64 v85; // [xsp+158h] [xbp-18h]
  __int64 v86; // [xsp+160h] [xbp-10h]
  __int64 v87; // [xsp+168h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_10740, "__qseecom_start_app", a2);
  if ( !a1 || !a2 )
  {
    printk(&unk_FF3F, v6, v7);
LABEL_38:
    result = 4294967274LL;
    goto LABEL_5;
  }
  v8 = _kmalloc_cache_noprof(_trace_trigger_soft_disabled, 3520, 104);
  if ( !v8 )
  {
    result = 4294967284LL;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = v8;
  client_env_object = get_client_env_object(v8 + 56);
  if ( client_env_object )
  {
    printk(&unk_1008A, a2, client_env_object);
LABEL_37:
    kfree(v10);
    goto LABEL_38;
  }
  v13 = *(_DWORD **)(v10 + 56);
  v12 = *(_QWORD *)(v10 + 64);
  LODWORD(v79) = 122;
  v49 = 0;
  v50 = 0;
  v47 = &v79;
  v48 = 4;
  if ( *(v13 - 1) != 816020464 )
    __break(0x8229u);
  v14 = ((__int64 (__fastcall *)(__int64, _QWORD, const char ***, __int64))v13)(v12, 0, &v47, 4097);
  v15 = v50;
  *(_QWORD *)(v10 + 72) = v49;
  *(_QWORD *)(v10 + 80) = v15;
  if ( v14 )
  {
    printk(&unk_10A37, a2, v14);
LABEL_34:
    v40 = *(_DWORD **)(v10 + 56);
    v39 = *(_QWORD *)(v10 + 64);
    if ( *(v40 - 1) != 816020464 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v40)(v39, 0xFFFF, 0, 0);
    goto LABEL_37;
  }
  v46 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = nullptr;
  v48 = 0;
  memset(v45, 0, sizeof(v45));
  v44 = 0;
  v16 = strnlen(a2, 0x100u);
  if ( v16 == 256 )
  {
    v25 = strnlen(a2, 0x100u);
    if ( v25 != -1 )
    {
      printk(&unk_10135, a2, v25);
      v26 = 4294967274LL;
      goto LABEL_30;
    }
  }
  else if ( v16 != -1 )
  {
    v17 = strlen(a2);
    v79 = a2;
    v80 = v17;
    v81 = (const char *)&v44;
    v82 = 4;
    v19 = *(__int64 (__fastcall **)(__int64, __int64, const char **, __int64))(v10 + 72);
    v18 = *(_QWORD *)(v10 + 80);
    v83 = nullptr;
    v84 = 0;
    if ( *((_DWORD *)v19 - 1) != 816020464 )
      __break(0x8228u);
    v20 = v19(v18, 2, &v79, 4113);
    v22 = v84;
    *(_QWORD *)(v10 + 88) = v83;
    *(_QWORD *)(v10 + 96) = v22;
    if ( !v20 )
    {
      printk(&unk_107BF, a2, v21);
LABEL_17:
      result = qtee_shmbridge_allocate_shm(a3, v10 + 24);
      if ( !(_DWORD)result )
      {
        v24 = *(_QWORD *)(v10 + 32);
        *(_DWORD *)(v10 + 16) = a3;
        *a1 = v10;
        *(_QWORD *)(v10 + 8) = v24;
        goto LABEL_5;
      }
      printk(&unk_FF6B, (unsigned int)result, v23);
      v42 = *(_DWORD **)(v10 + 88);
      v41 = *(_QWORD *)(v10 + 96);
      if ( *(v42 - 1) != 816020464 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v42)(v41, 0xFFFF, 0, 0);
      goto LABEL_31;
    }
    v27 = firmware_request_from_smcinvoke(a2, &v46, (__int64)v45);
    if ( v27 )
    {
      v30 = v27;
      v31 = strlen(a2);
      v81 = a2;
      v82 = v31;
      v83 = &v47;
      v84 = 256;
      v33 = *(__int64 (__fastcall **)(__int64, __int64, const char **, __int64))(v10 + 72);
      v32 = *(_QWORD *)(v10 + 80);
      v79 = v30;
      v80 = v46;
      v85 = 0;
      v86 = 0;
      if ( *((_DWORD *)v33 - 1) != 816020464 )
        __break(0x8229u);
      v34 = v33(v32, 1, &v79, 4114);
      v35 = v86;
      *(_QWORD *)(v10 + 88) = v85;
      *(_QWORD *)(v10 + 96) = v35;
      if ( !v34 )
      {
        *(_BYTE *)(v10 + 48) = v30[4];
        printk(&unk_10553, "load_app", 98);
        qtee_shmbridge_free_shm(v45);
        goto LABEL_17;
      }
      v36 = v34;
      printk(&unk_108F9, a2, v34);
      qtee_shmbridge_free_shm(v45);
      v26 = v36;
    }
    else
    {
      printk(&unk_10167, v28, v29);
      v26 = 4294967274LL;
    }
LABEL_30:
    printk(&unk_10010, a2, v26);
LABEL_31:
    v38 = *(_DWORD **)(v10 + 72);
    v37 = *(_QWORD *)(v10 + 80);
    if ( *(v38 - 1) != 816020464 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v38)(v37, 0xFFFF, 0, 0);
    goto LABEL_34;
  }
  v43 = _fortify_panic(2, -1, 0);
  return _qseecom_shutdown_app(v43);
}
