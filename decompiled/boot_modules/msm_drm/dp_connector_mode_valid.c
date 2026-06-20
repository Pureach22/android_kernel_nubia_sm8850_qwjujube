__int64 __fastcall dp_connector_mode_valid(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x24
  int v9; // w0
  _DWORD *v10; // x8
  int v11; // w20
  int v12; // w0
  int v13; // w8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v16; // x0
  __int64 v17; // x0
  int v18; // w19
  __int64 v19; // x0
  _DWORD *v20; // x8
  __int64 v21; // x1
  unsigned int v22; // w21
  __int64 v23; // x0
  unsigned __int64 StatusReg; // x23
  unsigned int v25; // w22
  const char *v26; // x21
  _QWORD v27[6]; // [xsp+10h] [xbp-30h] BYREF

  v27[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v27, 0, 40);
  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_24B695;
LABEL_20:
    printk(v16, "dp_connector_mode_valid");
    result = 0xFFFFFFFFLL;
    goto LABEL_17;
  }
  v6 = *(_QWORD *)(a1 + 2768);
  if ( !v6 )
  {
    v17 = get_ipc_log_context();
    ipc_log_string(v17, "[e][%-4d]invalid dp panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_2238C5;
    goto LABEL_20;
  }
  v9 = drm_mode_vrefresh(a2);
  v10 = *(_DWORD **)(a3 + 296);
  v11 = v9;
  if ( *(v10 - 1) != 337982541 )
    __break(0x8228u);
  v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v10)(a3, a4, v27);
  if ( v12 )
  {
    v18 = v12;
    v19 = get_ipc_log_context();
    ipc_log_string(
      v19,
      "[e][%-4d]error getting max dp resources. rc:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v18);
    printk(&unk_226A05, "dp_connector_mode_valid");
    result = 0xFFFFFFFFLL;
    goto LABEL_17;
  }
  v13 = *(unsigned __int16 *)(a2 + 4);
  if ( (v13 != 640 || *(_WORD *)(a2 + 14) != 480 || *(_DWORD *)a2 != 25175) && *(_BYTE *)(v6 + 981) == 1 )
  {
    if ( *(_DWORD *)(v6 + 984) != v13
      || *(_DWORD *)(v6 + 988) != *(unsigned __int16 *)(a2 + 14)
      || v11 != *(_DWORD *)(v6 + 992)
      || *(_DWORD *)(a2 + 116) != *(_DWORD *)(v6 + 996) )
    {
      result = 4294967294LL;
      goto LABEL_17;
    }
    *(_BYTE *)(a2 + 62) |= 8u;
  }
  v20 = *(_DWORD **)(a3 + 120);
  v21 = *(_QWORD *)(a1 + 2768);
  if ( *(v20 - 1) != -1991269395 )
    __break(0x8228u);
  v22 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v20)(a3, v21, a2, v27);
  v23 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v25 = v22;
  if ( v22 )
    v26 = "invalid";
  else
    v26 = "valid";
  ipc_log_string(
    v23,
    "[i][%-4d]: override = %d, %dx%d %d %d, %s\n",
    *(_DWORD *)(StatusReg + 1800),
    *(unsigned __int8 *)(v6 + 981),
    *(unsigned __int16 *)(a2 + 4),
    *(unsigned __int16 *)(a2 + 14),
    v11,
    *(_DWORD *)(a2 + 116),
    v26);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_215308, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_215345, "dp_connector_mode_valid");
  result = v25;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
