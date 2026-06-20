__int64 __fastcall _cam_isp_ctx_reg_upd_in_epoch_bubble_state(__int64 *a1, __int64 *a2)
{
  __int64 v2; // x21
  _QWORD *v4; // x20
  unsigned __int64 v6; // x1
  char v7; // w22
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x1
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  const char *v14; // x8
  const char *v16; // x0

  v2 = *a1;
  v4 = a1 + 4663;
  if ( a2 && *((_BYTE *)a2 + 16) == 1 )
  {
    v6 = *a2;
    if ( v6 == *v4 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_reg_upd_in_epoch_bubble_state",
          3587,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          v6 / 0x3B9ACA00,
          v6 % 0x3B9ACA00,
          a1[4664] / 0x3B9ACA00uLL,
          a1[4664] % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts(a1, v6, a2[1]);
    }
  }
  if ( a1[1] != 1 )
  {
    if ( !*((_DWORD *)a1 + 11392) )
      *((_DWORD *)a1 + 11391) = 1;
    v11 = __ratelimit(&_cam_isp_ctx_reg_upd_in_epoch_bubble_state__rs, "__cam_isp_ctx_reg_upd_in_epoch_bubble_state");
    v12 = *((unsigned int *)a1 + 5);
    if ( v11 )
      v13 = 3;
    else
      v13 = 2;
    if ( (unsigned int)v12 > 6 )
      v14 = "INVALID";
    else
      v14 = off_451850[v12];
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v13,
      8,
      2,
      "__cam_isp_ctx_reg_upd_in_epoch_bubble_state",
      3615,
      "ctx:%u Unexpected regupdate in activated Substate[%s] for frame_id:%lld",
      (unsigned int)"last_applied_default:%d, unserved_rup:%d",
      (const char *)*(unsigned int *)(*a1 + 32),
      v14);
    v10 = 0;
    *((_DWORD *)a1 + 11392) = 0;
    goto LABEL_24;
  }
  v7 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v16 = _cam_isp_ctx_substate_val_to_type(*((_DWORD *)a1 + 5));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7 & 8,
      4,
      "__cam_isp_ctx_reg_upd_in_epoch_bubble_state",
      3593,
      "Reg update in Substate[%s] for early PCR",
      v16);
  }
  v8 = *(_QWORD *)(v2 + 128);
  if ( v8 != v2 + 128 )
  {
    v9 = *(_QWORD *)(v8 + 24);
    if ( v9 )
    {
      v4[3] = v9;
      v10 = *(_QWORD *)(v8 + 24);
    }
    else
    {
      v10 = 0;
    }
LABEL_24:
    _cam_isp_ctx_send_sof_timestamp(a1, v10, 0);
  }
  return 0;
}
