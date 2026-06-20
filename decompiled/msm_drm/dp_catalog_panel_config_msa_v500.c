__int64 __fastcall dp_catalog_panel_config_msa_v500(__int64 a1, int a2)
{
  unsigned int v3; // w8
  __int64 v5; // x24
  bool v6; // zf
  __int64 v7; // x8
  __int64 v8; // x22
  int v9; // w23
  __int64 (*v10)(void); // x8
  int v11; // w0
  __int64 (*v12)(void); // x9
  int v13; // w21
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w22
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v19; // x0
  unsigned int v20; // w22
  int v21; // w21
  unsigned int v22; // w8
  __int64 v23; // x0
  __int64 v24; // x0
  int v25; // w12
  unsigned int v26; // w21
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

  if ( a1 && a2 )
  {
    v3 = *(_DWORD *)(a1 + 204);
    if ( v3 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_233DB1, "dp_catalog_panel_config_msa_v500");
    }
    else
    {
      v5 = *(_QWORD *)(a1 + 760);
      v6 = v3 == 1;
      v7 = 768;
      if ( v6 )
        v7 = 772;
      v8 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 56LL);
      v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 32) + 1200LL) + v7);
      v10 = *(__int64 (**)(void))v5;
      if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 625732792 )
        __break(0x8228u);
      v11 = v10();
      v12 = *(__int64 (**)(void))v5;
      v13 = v11;
      v14 = *(_QWORD *)(v5 + 32);
      if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 625732792 )
        __break(0x8229u);
      v15 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v12)(v14, v8, (unsigned int)(v9 + 12));
      v16 = v15;
      v17 = get_ipc_log_context(v15);
      StatusReg = _ReadStatusReg(SP_EL0);
      v19 = ipc_log_string(v17, "[d][%-4d]pixel_m=0x%x, pixel_n=0x%x\n", *(_DWORD *)(StatusReg + 1800), v13, v16);
      if ( (_drm_debug & 4) != 0 )
        v19 = _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]pixel_m=0x%x, pixel_n=0x%x\n",
                *(_DWORD *)(StatusReg + 1800),
                v13,
                v16);
      v20 = (unsigned __int16)v13 + (unsigned __int16)~(_WORD)v16;
      v21 = 5 * (unsigned __int16)v13;
      if ( !(v20 >> 15) )
      {
        v22 = 0x8000u / (unsigned __int16)v20;
        v20 *= v22;
        v21 *= v22;
      }
      v23 = get_ipc_log_context(v19);
      v24 = ipc_log_string(v23, "[d][%-4d]rate = %d\n", *(_DWORD *)(StatusReg + 1800), a2);
      if ( (_drm_debug & 4) != 0 )
        v24 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]rate = %d\n", *(_DWORD *)(StatusReg + 1800), a2);
      v25 = *(_DWORD *)(a1 + 204);
      v26 = *(_DWORD *)(a1 + 584) * v21;
      v6 = a2 == 810000;
      v27 = v20 << (a2 == 540000);
      v28 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 16LL);
      if ( v6 )
        v29 = 3 * v27;
      else
        v29 = v27;
      if ( v25 == 1 )
        v30 = 1048;
      else
        v30 = 24;
      if ( v25 == 1 )
        v31 = 1044;
      else
        v31 = 16;
      v32 = get_ipc_log_context(v24);
      ipc_log_string(v32, "[d][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v26, v29);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v26, v29);
      v33 = *(_DWORD **)(v5 + 8);
      v34 = *(_QWORD *)(v5 + 32);
      if ( *(v33 - 1) != 621108289 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33)(v34, v28, v31, v26);
      v35 = *(_DWORD **)(v5 + 8);
      v36 = *(_QWORD *)(v5 + 32);
      if ( *(v35 - 1) != 621108289 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v35)(v36, v28, v30, v29);
    }
  }
  else
  {
    v38 = get_ipc_log_context(a1);
    ipc_log_string(v38, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_279170, "dp_catalog_panel_config_msa_v500");
  }
}
