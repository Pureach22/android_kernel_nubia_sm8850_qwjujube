__int64 __fastcall ipa_mhi_resume_channels(char a1, __int64 a2, int a3)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w3
  unsigned int v12; // w26
  __int64 v13; // x0
  long double v14; // q0
  __int64 v15; // x0
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x10
  __int64 v19; // x4
  __int64 v20; // x2
  unsigned int v21; // w0
  __int64 v22; // x0
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w20
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  _QWORD v34[4]; // [xsp+0h] [xbp-20h] BYREF

  v34[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_resume_channels", 1562);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_resume_channels", 1562);
  }
  if ( a3 < 1 )
  {
LABEL_25:
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(v22, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_resume_channels", 1616);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v24, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_resume_channels", 1616);
      result = 0;
    }
    goto LABEL_29;
  }
  v8 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)a2 != 1 || *(_DWORD *)(a2 + 8) != 3 && *(_BYTE *)(a2 + 12) != 1 )
      goto LABEL_7;
    mutex_lock(&mhi_client_general_mutex);
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v9,
        "ipa_mhi_client %s:%d resuming channel %d, mstate = %d\n",
        "ipa_mhi_resume_channels",
        1572,
        *(unsigned __int8 *)(a2 + 1),
        *(_DWORD *)(ipa_mhi_client_ctx + 1316));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa_mhi_client %s:%d resuming channel %d, mstate = %d\n",
        "ipa_mhi_resume_channels",
        1572,
        *(unsigned __int8 *)(a2 + 1),
        *(_DWORD *)(ipa_mhi_client_ctx + 1316));
    }
    v11 = *(_DWORD *)(ipa_mhi_client_ctx + 1316);
    if ( (unsigned int)(v11 - 1) >= 2 )
      break;
    v12 = 0;
LABEL_19:
    mutex_unlock(&mhi_client_general_mutex);
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_mhi_client %s:%d is DB mode? %d\n", "ipa_mhi_resume_channels", 1600, v12);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      v14 = ipc_log_string(v15, "ipa_mhi_client %s:%d is DB mode? %d\n", "ipa_mhi_resume_channels", 1600, v12);
    }
    v16 = *(_QWORD *)(a2 + 173);
    v17 = *(unsigned int *)(a2 + 4);
    v18 = *(_QWORD *)(a2 + 181);
    v19 = *(unsigned __int8 *)(a2 + 2);
    v20 = *(unsigned __int8 *)(a2 + 164);
    v34[0] = *(_QWORD *)(a2 + 165);
    v34[1] = v16;
    v34[2] = v18;
    v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *, __int64, _QWORD, long double))ipa3_mhi_resume_channels_internal)(
            v17,
            a1 & 1,
            v20,
            v34,
            v19,
            v12,
            v14);
    if ( v21 )
    {
      v27 = v21;
      printk(&unk_3D9E53, "ipa_mhi_resume_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v28,
          "ipa_mhi_client %s:%d failed to resume channel %d error %d\n",
          "ipa_mhi_resume_channels",
          1608,
          v8,
          v27);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v29,
          "ipa_mhi_client %s:%d failed to resume channel %d error %d\n",
          "ipa_mhi_resume_channels",
          1608,
          v8,
          v27);
      }
      result = v27;
      goto LABEL_29;
    }
    *(_BYTE *)(a2 + 12) = 0;
    *(_DWORD *)(a2 + 8) = 2;
LABEL_7:
    ++v8;
    a2 += 200;
    if ( a3 == v8 )
      goto LABEL_25;
  }
  if ( v11 == 3 )
  {
    v12 = 1;
    goto LABEL_19;
  }
  if ( v11 )
  {
    if ( v11 == 4 )
    {
      printk(&unk_3D7259, "ipa_mhi_resume_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v25 = ipa3_get_ipc_logbuf();
        ipc_log_string(v25, "ipa_mhi_client %s:%d No knowledge of M state\n", "ipa_mhi_resume_channels", 1586);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v26 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v26, "ipa_mhi_client %s:%d No knowledge of M state\n", "ipa_mhi_resume_channels", 1586);
      }
    }
    else
    {
      printk(&unk_3C265F, "ipa_mhi_resume_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v32,
          "ipa_mhi_client %s:%d Unknown Mstart %d\n",
          "ipa_mhi_resume_channels",
          1591,
          *(_DWORD *)(ipa_mhi_client_ctx + 1316));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v33,
          "ipa_mhi_client %s:%d Unknown Mstart %d\n",
          "ipa_mhi_resume_channels",
          1591,
          *(_DWORD *)(ipa_mhi_client_ctx + 1316));
      }
    }
  }
  else
  {
    printk(&unk_3BC990, "ipa_mhi_resume_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v30 = ipa3_get_ipc_logbuf();
      ipc_log_string(v30, "ipa_mhi_client %s:%d Resume in M0 - not expected\n", "ipa_mhi_resume_channels", 1582);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v31 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v31, "ipa_mhi_client %s:%d Resume in M0 - not expected\n", "ipa_mhi_resume_channels", 1582);
    }
  }
  mutex_unlock(&mhi_client_general_mutex);
  result = 4294967274LL;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
