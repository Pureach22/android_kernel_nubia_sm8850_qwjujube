__int64 __fastcall dp_mst_connector_mode_valid(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4)
{
  __int64 v8; // x22
  __int64 result; // x0
  __int64 v10; // x24
  _QWORD *v11; // x26
  int v12; // w0
  int v13; // w8
  __int64 v14; // x8
  __int64 v15; // x9
  bool v16; // zf
  int v17; // w9
  int v18; // w8
  __int64 v19; // x10
  __int64 v20; // x11
  _DWORD *v21; // x10
  __int64 v22; // x1
  unsigned int v23; // w24
  int v24; // w23
  unsigned __int16 (__fastcall *v25)(_QWORD); // x8
  unsigned int v26; // w25
  _DWORD *v27; // x8
  int v28; // w26
  _DWORD *v29; // x8
  __int64 v30; // x0
  unsigned __int64 v31; // x20
  __int64 ipc_log_context; // x0
  __int64 v33; // x0
  unsigned __int64 StatusReg; // x19
  _BYTE s[800]; // [xsp+18h] [xbp-328h] BYREF
  __int64 v36; // [xsp+338h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_mst_connector_mode_valid");
    result = 0;
    goto LABEL_44;
  }
  v8 = *(_QWORD *)(a1 + 2768);
  result = 0xFFFFFFFFLL;
  if ( v8 )
  {
    v10 = *(_QWORD *)(a1 + 2776);
    if ( v10 )
    {
      v11 = (_QWORD *)a3[5];
      v12 = drm_mode_vrefresh(a2);
      v13 = *(unsigned __int16 *)(a2 + 4);
      if ( v13 == 640 && *(_WORD *)(a2 + 14) == 480 && *(_DWORD *)a2 == 25175 )
      {
LABEL_35:
        v29 = (_DWORD *)a3[15];
        if ( *(v29 - 1) != -1991269395 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))v29)(a3, v8, a2, a4);
        goto LABEL_44;
      }
      if ( *(_BYTE *)(v8 + 981) != 1
        || *(_DWORD *)(v8 + 984) == v13
        && *(_DWORD *)(v8 + 988) == *(unsigned __int16 *)(a2 + 14)
        && v12 == *(_DWORD *)(v8 + 992)
        && *(_DWORD *)(a2 + 116) == *(_DWORD *)(v8 + 996) )
      {
        v14 = v11[215];
        v15 = *(_QWORD *)(v14 + 16);
        if ( v15 )
          v16 = v15 == a1;
        else
          v16 = 1;
        v17 = v16;
        if ( v16 )
          v18 = 0;
        else
          v18 = *(_DWORD *)(v14 + 32);
        v19 = v11[389];
        v20 = *(_QWORD *)(v19 + 16);
        if ( v20 && v20 != a1 )
        {
          if ( !v17 )
          {
            v33 = get_ipc_log_context();
            StatusReg = _ReadStatusReg(SP_EL0);
            ipc_log_string(v33, "[d][%-4d]all mst streams are active\n", *(_DWORD *)(StatusReg + 1800));
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]all mst streams are active\n", *(_DWORD *)(StatusReg + 1800));
            goto LABEL_43;
          }
          v18 += *(_DWORD *)(v19 + 32);
        }
        v21 = (_DWORD *)a3[34];
        v22 = *(_QWORD *)(a1 + 2768);
        v23 = *(unsigned __int16 *)(v10 + 18);
        v24 = 63 - v18;
        if ( *(v21 - 1) != 271107547 )
          __break(0x822Au);
        ((void (__fastcall *)(_QWORD *, __int64, __int64, _BYTE *))v21)(a3, v22, a2, s);
        v25 = *(unsigned __int16 (__fastcall **)(_QWORD))(v11[516] + 40LL);
        if ( *((_DWORD *)v25 - 1) != -143676487 )
          __break(0x8228u);
        v26 = v25(s);
        v27 = *(_DWORD **)(v11[516] + 48LL);
        if ( *(v27 - 1) != -98629839 )
          __break(0x8228u);
        v28 = ((__int64 (__fastcall *)(_QWORD *, _QWORD))v27)(v11 + 4, v26);
        if ( v26 <= v23 && v28 <= v24 )
          goto LABEL_35;
        v30 = get_ipc_log_context();
        v31 = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v30,
          "[d][%-4d]mode:%s not supported. pbn %d vs %d slots %d vs %d\n",
          *(_DWORD *)(v31 + 1800),
          (const char *)(a2 + 80),
          v26,
          v23,
          v28,
          v24);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]mode:%s not supported. pbn %d vs %d slots %d vs %d\n",
            *(_DWORD *)(v31 + 1800),
            (const char *)(a2 + 80),
            v26,
            v23,
            v28,
            v24);
      }
LABEL_43:
      result = 4294967294LL;
    }
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
