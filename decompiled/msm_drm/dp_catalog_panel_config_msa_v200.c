__int64 __fastcall dp_catalog_panel_config_msa_v200(__int64 a1, int a2)
{
  unsigned int v2; // w8
  __int64 v4; // x24
  int v5; // w23
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 (__fastcall *v9)(__int64, __int64, _QWORD); // x9
  int v10; // w0
  __int64 (__fastcall *v11)(__int64, __int64, _QWORD); // x9
  int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w22
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v18; // x0
  unsigned int v19; // w22
  int v20; // w21
  unsigned int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w12
  unsigned int v25; // w21
  bool v26; // zf
  unsigned int v27; // w8
  __int64 v28; // x20
  unsigned int v29; // w19
  unsigned int v30; // w22
  unsigned int v31; // w23
  __int64 v32; // x0
  _DWORD *v33; // x8
  __int64 v34; // x0
  _DWORD *v35; // x8
  __int64 v36; // x0
  __int64 v38; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 204);
    if ( v2 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_config_msa_v200");
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 760);
      if ( v2 == 1 )
        v5 = 24;
      else
        v5 = 0;
      v7 = *(_QWORD *)(v4 - 8);
      v8 = *(_QWORD *)(*(_QWORD *)(v4 - 16) + 56LL);
      v9 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))v4;
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 625732792 )
        __break(0x8229u);
      v10 = v9(v7, v8, (unsigned int)(v5 + 304));
      v11 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))v4;
      v12 = v10;
      v13 = *(_QWORD *)(v4 - 8);
      if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 625732792 )
        __break(0x8229u);
      v14 = v11(v13, v8, (unsigned int)(v5 + 308));
      v15 = v14;
      v16 = get_ipc_log_context(v14);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = ipc_log_string(v16, "[d][%-4d]pixel_m=0x%x, pixel_n=0x%x\n", *(_DWORD *)(StatusReg + 1800), v12, v15);
      if ( (_drm_debug & 4) != 0 )
        v18 = _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]pixel_m=0x%x, pixel_n=0x%x\n",
                *(_DWORD *)(StatusReg + 1800),
                v12,
                v15);
      v19 = (unsigned __int16)v12 + (unsigned __int16)~(_WORD)v15;
      v20 = 5 * (unsigned __int16)v12;
      if ( !(v19 >> 15) )
      {
        v21 = 0x8000u / (unsigned __int16)v19;
        v19 *= v21;
        v20 *= v21;
      }
      v22 = get_ipc_log_context(v18);
      v23 = ipc_log_string(v22, "[d][%-4d]rate = %d\n", *(_DWORD *)(StatusReg + 1800), a2);
      if ( (_drm_debug & 4) != 0 )
        v23 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]rate = %d\n", *(_DWORD *)(StatusReg + 1800), a2);
      v24 = *(_DWORD *)(a1 + 204);
      v25 = *(_DWORD *)(a1 + 584) * v20;
      v26 = a2 == 810000;
      v27 = v19 << (a2 == 540000);
      v28 = *(_QWORD *)(*(_QWORD *)(v4 - 16) + 16LL);
      if ( v26 )
        v29 = 3 * v27;
      else
        v29 = v27;
      if ( v24 == 1 )
        v30 = 1048;
      else
        v30 = 24;
      if ( v24 == 1 )
        v31 = 1044;
      else
        v31 = 16;
      v32 = get_ipc_log_context(v23);
      ipc_log_string(v32, "[d][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v25, v29);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v25, v29);
      v33 = *(_DWORD **)(v4 + 8);
      v34 = *(_QWORD *)(v4 - 8);
      if ( *(v33 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33)(v34, v28, v31, v25);
      v35 = *(_DWORD **)(v4 + 8);
      v36 = *(_QWORD *)(v4 - 8);
      if ( *(v35 - 1) != 621108289 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v35)(v36, v28, v30, v29);
    }
  }
  else
  {
    v38 = get_ipc_log_context(0);
    ipc_log_string(v38, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_msa_v200");
  }
}
