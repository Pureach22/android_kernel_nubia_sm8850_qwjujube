__int64 __fastcall dp_catalog_panel_config_msa(__int64 a1, int a2)
{
  unsigned int v2; // w8
  __int64 v4; // x23
  _DWORD *v5; // x9
  __int64 v6; // x20
  int v7; // w24
  __int64 v9; // x0
  __int64 v10; // x1
  int v11; // w0
  _DWORD *v12; // x8
  int v13; // w22
  __int64 v14; // x0
  int v15; // w23
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v18; // x0
  unsigned int v19; // w24
  int v20; // w23
  unsigned int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w12
  unsigned int v25; // w23
  __int64 v26; // x22
  unsigned int v27; // w21
  unsigned int v28; // w24
  unsigned int v29; // w25
  __int64 v30; // x0
  _DWORD **v31; // x19
  _DWORD *v32; // x8
  _DWORD *v33; // x8
  __int64 v35; // x0
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
      return printk(&unk_272496, "dp_catalog_panel_config_msa");
    }
    else
    {
      v4 = *(_QWORD *)(a1 - 512);
      v5 = *(_DWORD **)(a1 - 456);
      v6 = a1 - 576;
      if ( v2 == 1 )
        v7 = 24;
      else
        v7 = 0;
      v9 = a1 - 576;
      v10 = *(_QWORD *)(a1 - 512);
      if ( *(v5 - 1) != -1879227436 )
        __break(0x8229u);
      v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v5)(v9, v10, (unsigned int)(v7 + 436));
      v12 = *(_DWORD **)(a1 - 456);
      v13 = v11;
      if ( *(v12 - 1) != -1879227436 )
        __break(0x8228u);
      v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v12)(a1 - 576, v4, (unsigned int)(v7 + 440));
      v15 = v14;
      v16 = get_ipc_log_context(v14);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = ipc_log_string(v16, "[d][%-4d]pixel_m=0x%x, pixel_n=0x%x\n", *(_DWORD *)(StatusReg + 1800), v13, v15);
      if ( (_drm_debug & 4) != 0 )
        v18 = _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]pixel_m=0x%x, pixel_n=0x%x\n",
                *(_DWORD *)(StatusReg + 1800),
                v13,
                v15);
      v19 = (unsigned __int16)v13 + (unsigned __int16)~(_WORD)v15;
      v20 = 5 * (unsigned __int16)v13;
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
      v26 = *(_QWORD *)(a1 - 552);
      if ( a2 == 810000 )
        v27 = 3 * (v19 << (a2 == 540000));
      else
        v27 = v19 << (a2 == 540000);
      if ( v24 == 1 )
        v28 = 1048;
      else
        v28 = 24;
      if ( v24 == 1 )
        v29 = 1044;
      else
        v29 = 16;
      v30 = get_ipc_log_context(v23);
      ipc_log_string(v30, "[d][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v25, v27);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mvid=0x%x, nvid=0x%x\n", *(_DWORD *)(StatusReg + 1800), v25, v27);
      v31 = (_DWORD **)(a1 - 448);
      v32 = *v31;
      if ( *(*v31 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v32)(v6, v26, v29, v25);
      v33 = *v31;
      if ( *(*v31 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33)(v6, v26, v28, v27);
    }
  }
  else
  {
    v35 = get_ipc_log_context(0);
    ipc_log_string(v35, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_msa");
  }
}
