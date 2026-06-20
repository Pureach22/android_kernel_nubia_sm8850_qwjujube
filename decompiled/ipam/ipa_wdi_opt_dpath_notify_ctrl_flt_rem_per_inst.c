__int64 __fastcall ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst(unsigned int a1, int a2, unsigned __int16 a3)
{
  __int64 v3; // x9
  _DWORD *v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x9
  char *v7; // x8
  __int16 v8; // w8
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 < 2 )
  {
    v13[0] = 0;
    v3 = 136LL * a1;
    if ( *(_DWORD *)((char *)&opt_dpath_info + v3 + 116) == a2 )
    {
      v4 = (_DWORD *)((char *)&opt_dpath_info + v3 + 112);
      v5 = v3 + 112;
      if ( v5 > 0x10C )
        goto LABEL_22;
    }
    else
    {
      v6 = 136LL * a1;
      v7 = (char *)&opt_dpath_info + v6;
      if ( *(_DWORD *)((char *)&opt_dpath_info + v6 + 124) == a2 )
      {
        v4 = v7 + 120;
        v5 = v6 + 120;
        if ( v5 > 0x10C )
LABEL_22:
          __break(1u);
      }
      else
      {
        if ( *((_DWORD *)v7 + 33) != a2 )
        {
LABEL_13:
          v8 = 0;
          if ( (unsigned int)a3 - 203 >= 3 )
            v8 = a3 != 0;
          LOWORD(v13[0]) = v8;
          WORD1(v13[0]) = a3;
          result = ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind((unsigned __int16 *)v13);
          goto LABEL_16;
        }
        v4 = v7 + 128;
        v5 = v6 + 128;
        if ( v5 > 0x10C )
          goto LABEL_22;
      }
    }
    HIDWORD(v13[0]) = *v4;
    if ( v5 - 265 < 4 )
      goto LABEL_22;
    v4[1] = 0;
    *v4 = 0;
    goto LABEL_13;
  }
  printk(&unk_3F6766, "ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa_wdi %s:%d Invalid Handle %d\n",
      "ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst",
      1769,
      a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_wdi %s:%d Invalid Handle %d\n",
      "ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst",
      1769,
      a1);
  }
  result = 4294967282LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
