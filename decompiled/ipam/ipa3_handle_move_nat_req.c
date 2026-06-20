__int64 __fastcall ipa3_handle_move_nat_req(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  const char *v10; // x4
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  const char *v13; // x4
  _WORD *v14; // x1
  int v15; // w9
  __int64 v16; // x0
  int v17; // w22
  int v18; // w23
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x7
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 result; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // w22
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  _QWORD v42[2]; // [xsp+0h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v42[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
    if ( *a4 )
      v10 = "TO_SRAM";
    else
      v10 = "TO_DDR";
    ipc_logbuf = ipc_log_string(
                   v9,
                   "ipa-wan %s:%d Received IPA_MOVE_NAT_REQ_MSG_V01(%s)\n",
                   "ipa3_handle_move_nat_req",
                   449,
                   v10);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v12 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    if ( *a4 )
      v13 = "TO_SRAM";
    else
      v13 = "TO_DDR";
    ipc_log_string(v12, "ipa-wan %s:%d Received IPA_MOVE_NAT_REQ_MSG_V01(%s)\n", "ipa3_handle_move_nat_req", 449, v13);
  }
  HIDWORD(v42[0]) = 0;
  v14 = (_WORD *)_kmalloc_cache_noprof(sg_next, 3520, 4);
  if ( v14 )
  {
    v15 = *a4;
    LODWORD(v42[0]) = 262195;
    *(_DWORD *)v14 = v15;
    nat_move_qmi_disabled = 0;
    __dsb(0xEu);
    v16 = ipa_send_msg((unsigned __int8 *)v42, v14, ipa3_qmi_msg_free_cb);
    v17 = 0;
    v18 = 0;
    if ( (_DWORD)v16 )
    {
      v33 = v16;
      v34 = printk(&unk_3B0076, "ipa3_handle_move_nat_req");
      v35 = ipa3_get_ipc_logbuf(v34);
      if ( v35 )
      {
        v36 = ipa3_get_ipc_logbuf(v35);
        v35 = ipc_log_string(
                v36,
                "ipa-wan %s:%d ipa_send_msg failed: %d, notify Q6\n",
                "ipa3_handle_move_nat_req",
                479,
                v33);
      }
      v16 = ipa3_get_ipc_logbuf_low(v35);
      if ( v16 )
      {
        v37 = ipa3_get_ipc_logbuf_low(v16);
        v16 = ipc_log_string(
                v37,
                "ipa-wan %s:%d ipa_send_msg failed: %d, notify Q6\n",
                "ipa3_handle_move_nat_req",
                479,
                v33);
      }
      v17 = 0;
      v18 = 1;
      WORD2(v42[0]) = 1;
    }
  }
  else
  {
    v38 = printk(&unk_3AA258, "ipa3_handle_move_nat_req");
    v39 = ipa3_get_ipc_logbuf(v38);
    if ( v39 )
    {
      v40 = ipa3_get_ipc_logbuf(v39);
      v39 = ipc_log_string(v40, "ipa-wan %s:%d allocation failed\n", "ipa3_handle_move_nat_req", 457);
    }
    v16 = ipa3_get_ipc_logbuf_low(v39);
    if ( v16 )
    {
      v41 = ipa3_get_ipc_logbuf_low(v16);
      v16 = ipc_log_string(v41, "ipa-wan %s:%d allocation failed\n", "ipa3_handle_move_nat_req", 457);
    }
    v18 = 1;
    v17 = 2;
    HIDWORD(v42[0]) = 131073;
  }
  v19 = ipa3_get_ipc_logbuf(v16);
  if ( v19 )
  {
    v20 = ipa3_get_ipc_logbuf(v19);
    v19 = ipc_log_string(
            v20,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_move_nat_req",
            484,
            v18,
            v17);
  }
  v21 = ipa3_get_ipc_logbuf_low(v19);
  if ( v21 )
  {
    v23 = ipa3_get_ipc_logbuf_low(v21);
    ipc_log_string(v23, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "ipa3_handle_move_nat_req", 484, v18, v17);
  }
  v24 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
          a1,
          a2,
          a3,
          70,
          7,
          &ipa_move_nat_resp_msg_v01_ei,
          (char *)v42 + 4,
          v22,
          v42[0]);
  if ( (v24 & 0x80000000) != 0 )
  {
    v29 = printk(&unk_3D01B3, "ipa3_handle_move_nat_req");
    v30 = ipa3_get_ipc_logbuf(v29);
    if ( v30 )
    {
      v31 = ipa3_get_ipc_logbuf(v30);
      v30 = ipc_log_string(v31, "ipa-wan %s:%d QMI_IPA_MOVE_NAT_RESP_V01 failed\n", "ipa3_handle_move_nat_req", 493);
    }
    result = ipa3_get_ipc_logbuf_low(v30);
    if ( result )
    {
      v32 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v32, "ipa-wan %s:%d QMI_IPA_MOVE_NAT_RESP_V01 failed\n", "ipa3_handle_move_nat_req", 493);
    }
  }
  else
  {
    v25 = ipa3_get_ipc_logbuf(v24);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(
              v26,
              "ipa-wan %s:%d Finished sending QMI_IPA_MOVE_NAT_RESP_V01, res %d\n",
              "ipa3_handle_move_nat_req",
              497,
              WORD2(v42[0]));
    }
    result = ipa3_get_ipc_logbuf_low(v25);
    if ( result )
    {
      v28 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v28,
                 "ipa-wan %s:%d Finished sending QMI_IPA_MOVE_NAT_RESP_V01, res %d\n",
                 "ipa3_handle_move_nat_req",
                 497,
                 WORD2(v42[0]));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
