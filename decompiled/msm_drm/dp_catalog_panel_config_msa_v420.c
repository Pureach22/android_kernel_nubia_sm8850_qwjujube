__int64 __fastcall dp_catalog_panel_config_msa_v420(__int64 a1, int a2, unsigned int a3)
{
  _QWORD *v6; // x26
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 v9; // x12
  int v10; // w11
  unsigned __int64 v11; // x12
  __int64 v12; // x14
  bool v13; // cf
  __int64 v14; // x10
  unsigned __int64 v15; // x8
  __int64 v16; // x11
  unsigned int v17; // w11
  unsigned int v18; // w10
  __int64 v19; // x8
  unsigned __int64 v20; // x23
  unsigned int v21; // w22
  int v22; // w9
  __int64 v23; // x21
  unsigned int v24; // w24
  unsigned int v25; // w25
  __int64 v26; // x0
  unsigned __int64 StatusReg; // x27
  _DWORD *v28; // x8
  __int64 v29; // x0
  _DWORD *v30; // x8
  __int64 v31; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  __int64 v34; // x0
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36[0] = 0;
  if ( !a1 || !a2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "dp_catalog_panel_config_msa_v420");
    goto LABEL_39;
  }
  if ( *(_DWORD *)(a1 + 204) >= 2u )
  {
    v34 = get_ipc_log_context(a1);
    ipc_log_string(
      v34,
      "[e][%-4d]invalid stream id:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 204));
    result = printk(&unk_26EFE9, "dp_catalog_panel_config_msa_v420");
    goto LABEL_39;
  }
  v6 = *(_QWORD **)(a1 + 760);
  v7 = rational_best_approximation((unsigned int)(10 * a2), a3, 0xFFFF, 0xFFFF, &v35, v36);
  if ( (((unsigned int)v35 >> 15) & 1) == 0 )
  {
    v8 = 0x8000u / (unsigned __int16)v35;
    v9 = 0x8000u % (unsigned __int16)v35;
    v10 = -32;
    do
    {
      v11 = 2 * v9;
      if ( v11 < (unsigned __int16)v35 )
        v12 = 0;
      else
        v12 = (unsigned __int16)v35;
      v13 = __CFADD__(v10++, 1);
      v8 = (v11 >= (unsigned __int16)v35) | (unsigned __int64)(2 * v8);
      v9 = v11 - v12;
    }
    while ( !v13 );
    v14 = 62;
    if ( (unsigned __int16)v35 <= (unsigned __int64)(2 * v9) )
      ++v8;
    v15 = (unsigned __int64)(40960 * (unsigned int)LOWORD(v36[0])) << 20;
    do
    {
      if ( (((unsigned __int64)v8 >> v14) & 1) != (unsigned __int64)v8 >> 63 )
        break;
      --v14;
    }
    while ( v14 );
    v16 = 62;
    do
    {
      if ( ((v15 >> v16) & 1) != 0 )
        break;
      --v16;
    }
    while ( v16 );
    v17 = v16 + v14;
    v18 = v17 - 61;
    if ( v17 <= 0x3D )
    {
      v19 = v15 * v8;
      LOBYTE(v18) = 0;
    }
    else
    {
      v19 = (v8 >> ((v18 >> 1) + (v18 & 1))) * (v15 >> (v18 >> 1));
      if ( v18 >= 0x21 )
      {
        v19 <<= (unsigned __int8)v17 - 93;
LABEL_25:
        v20 = HIDWORD(v19);
        v21 = 0x8000;
        goto LABEL_26;
      }
      if ( v17 == 93 )
        goto LABEL_25;
    }
    v19 >>= 32 - (unsigned __int8)v18;
    goto LABEL_25;
  }
  LODWORD(v20) = 10 * LOWORD(v36[0]);
  v21 = (unsigned __int16)v35;
LABEL_26:
  v22 = *(_DWORD *)(a1 + 204);
  v23 = *(_QWORD *)(v6[3] + 16LL);
  if ( v22 == 1 )
    v24 = 1048;
  else
    v24 = 24;
  if ( v22 == 1 )
    v25 = 1044;
  else
    v25 = 16;
  v26 = get_ipc_log_context(v7);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v26,
    "[d][%-4d]pclk=%u, lclk=%u, mvid=0x%x, nvid=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    a3,
    a2,
    v20,
    v21);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]pclk=%u, lclk=%u, mvid=0x%x, nvid=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      a3,
      a2,
      v20,
      v21);
  v28 = (_DWORD *)v6[1];
  v29 = v6[4];
  if ( *(v28 - 1) != 621108289 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v28)(v29, v23, v25, (unsigned int)v20);
  v30 = (_DWORD *)v6[1];
  v31 = v6[4];
  if ( *(v30 - 1) != 621108289 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v30)(v31, v23, v24, v21);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
