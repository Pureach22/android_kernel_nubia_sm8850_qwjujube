__int64 __fastcall dp_connector_get_mode_info(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5, __int64 a6)
{
  __int64 v11; // x24
  __int64 v12; // x25
  _DWORD *v13; // x8
  unsigned int v14; // w0
  unsigned int mixer_count; // w0
  _DWORD *v16; // x8
  __int64 result; // x0
  int v18; // w9
  __int64 ipc_log_context; // x0
  unsigned int v20; // w19
  __int64 v21; // x0
  void *v22; // x0
  __int64 v23; // x0
  _QWORD v24[5]; // [xsp+0h] [xbp-350h] BYREF
  _BYTE s[800]; // [xsp+28h] [xbp-328h] BYREF
  __int64 v26; // [xsp+348h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  memset(v24, 0, sizeof(v24));
  if ( !a2 || !a4 || !a6 || !a5 || !a1 || !*(_DWORD *)(a6 + 24) || !*(_QWORD *)a1 || !*(_QWORD *)(*(_QWORD *)a1 + 56LL) )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24B695, "dp_connector_get_mode_info");
    result = 4294967274LL;
    goto LABEL_21;
  }
  memset(a4, 0, 0x388u);
  v11 = *(_QWORD *)(a1 + 2768);
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  v13 = *(_DWORD **)(a5 + 296);
  if ( *(v13 - 1) != 337982541 )
    __break(0x8228u);
  v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v13)(a5, a6, v24);
  if ( v14 )
  {
    v20 = v14;
    v21 = get_ipc_log_context();
    ipc_log_string(
      v21,
      "[e][%-4d]error getting max dp resources. rc:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v20);
    v22 = &unk_226A05;
LABEL_20:
    printk(v22, "dp_connector_get_mode_info");
    result = v20;
    goto LABEL_21;
  }
  mixer_count = msm_get_mixer_count(v12, a2, v24, a4 + 9);
  if ( mixer_count )
  {
    v20 = mixer_count;
    v23 = get_ipc_log_context();
    ipc_log_string(v23, "[e][%-4d]error getting mixer count. rc:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v20);
    v22 = &unk_23799E;
    goto LABEL_20;
  }
  *(_DWORD *)(a1 + 4668) = 0;
  *((_QWORD *)a4 + 5) = 0x100000000LL;
  *a4 = drm_mode_vrefresh(a2);
  a4[1] = *(unsigned __int16 *)(a2 + 20);
  *((_BYTE *)a4 + 776) = *(_BYTE *)(v11 + 969);
  a4[195] = *(_DWORD *)(v11 + 976);
  v16 = *(_DWORD **)(a5 + 272);
  if ( *(v16 - 1) != 271107547 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, __int64, _BYTE *))v16)(a5, v11, a2, s);
  result = 0;
  if ( s[64] == 1 )
  {
    memcpy(a4 + 14, &s[64], 0x2B0u);
    v18 = a4[15];
    result = 0;
    a4[10] = a4[9];
    a4[12] = v18;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
