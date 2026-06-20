__int64 __fastcall qcom_glink_create_ept(__int64 a1, __int64 a2, __int64 a3, const char *a4)
{
  __int64 v8; // x20
  __int64 v9; // x25
  __int64 next; // x0
  __int64 v11; // x19
  unsigned __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v16; // x8
  int v17; // w6
  __int64 v18; // x8
  __int64 v19; // x8
  int v20; // w3
  __int64 v21; // x8
  __int64 v22; // x21
  __int64 v23; // x8
  __int64 v24; // x8
  int v25; // w9
  int v31; // w8
  int v33; // w8
  int v35; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 968) + 112LL);
  v9 = raw_spin_lock_irqsave(v8 + 156);
  v35 = 0;
  next = idr_get_next(v8 + 184, &v35);
  if ( !next )
  {
LABEL_5:
    raw_spin_unlock_irqrestore(v8 + 156, v9);
    v12 = qcom_glink_alloc_channel(v8, (__int64)a4);
    if ( v12 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_44:
      v11 = 0;
      goto LABEL_45;
    }
    v13 = *(_QWORD *)(v12 + 112);
    v11 = v12;
    if ( v13 )
      ipc_log_string(
        *(_QWORD *)(v13 + 256),
        "%s[%d:%d] %s: \n",
        *(const char **)(v12 + 128),
        *(_DWORD *)(v12 + 136),
        *(_DWORD *)(v12 + 140),
        "qcom_glink_create_local");
    if ( (unsigned int)qcom_glink_send_open_req(v8, v11) )
    {
      v14 = *(_QWORD *)(v11 + 112);
      if ( !v14 )
        goto LABEL_11;
    }
    else
    {
      if ( (unsigned int)wait_for_completion_timeout(v11 + 280, 1250)
        && (unsigned int)wait_for_completion_timeout(v11 + 312, 1250) )
      {
        goto LABEL_26;
      }
      v21 = *(_QWORD *)(v11 + 112);
      if ( v21 )
        ipc_log_string(
          *(_QWORD *)(v21 + 256),
          "%s[%d:%d] %s: err_timeout\n",
          *(const char **)(v11 + 128),
          *(_DWORD *)(v11 + 136),
          *(_DWORD *)(v11 + 140),
          "qcom_glink_create_local");
      v22 = raw_spin_lock_irqsave(v8 + 156);
      idr_remove(v8 + 160, *(unsigned int *)(v11 + 136));
      raw_spin_unlock_irqrestore(v8 + 156, v22);
      v14 = *(_QWORD *)(v11 + 112);
      if ( !v14 )
      {
LABEL_11:
        _X19 = (unsigned int *)(v11 + 120);
        __asm { PRFM            #0x11, [X19] }
        do
          v31 = __ldxr(_X19);
        while ( __stlxr(v31 - 1, _X19) );
        if ( v31 == 1 )
        {
          __dmb(9u);
          qcom_glink_channel_release((__int64)_X19);
        }
        else if ( v31 <= 0 )
        {
          refcount_warn_saturate(_X19, 3);
        }
        __asm { PRFM            #0x11, [X19] }
        do
          v33 = __ldxr(_X19);
        while ( __stlxr(v33 - 1, _X19) );
        if ( v33 == 1 )
        {
          __dmb(9u);
          qcom_glink_channel_release((__int64)_X19);
        }
        else if ( v33 <= 0 )
        {
          refcount_warn_saturate(_X19, 3);
        }
        goto LABEL_44;
      }
    }
    ipc_log_string(
      *(_QWORD *)(v14 + 256),
      "%s[%d:%d] %s: release_channel\n",
      *(const char **)(v11 + 128),
      *(_DWORD *)(v11 + 136),
      *(_DWORD *)(v11 + 140),
      "qcom_glink_create_local");
    goto LABEL_11;
  }
  v11 = next;
  while ( strcmp(*(const char **)(v11 + 128), a4) )
  {
    ++v35;
    v11 = idr_get_next(v8 + 184, &v35);
    if ( !v11 )
      goto LABEL_5;
  }
  raw_spin_unlock_irqrestore(v8 + 156, v9);
  v16 = *(_QWORD *)(v11 + 112);
  if ( v16 )
    ipc_log_string(
      *(_QWORD *)(v16 + 256),
      "%s[%d:%d] %s: \n",
      *(const char **)(v11 + 128),
      *(_DWORD *)(v11 + 136),
      *(_DWORD *)(v11 + 140),
      "qcom_glink_create_remote");
  v17 = qcom_glink_send_open_req(v8, v11);
  if ( v17 )
  {
    v18 = *(_QWORD *)(v11 + 112);
    if ( v18 )
      goto LABEL_17;
    goto LABEL_31;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v11 + 280, 1250) )
  {
    v17 = -110;
    v18 = *(_QWORD *)(v11 + 112);
    if ( v18 )
    {
LABEL_17:
      ipc_log_string(
        *(_QWORD *)(v18 + 256),
        "%s[%d:%d] %s: close_link %d\n",
        *(const char **)(v11 + 128),
        *(_DWORD *)(v11 + 136),
        *(_DWORD *)(v11 + 140),
        "qcom_glink_create_remote",
        v17);
      v19 = *(_QWORD *)(v11 + 112);
      v20 = *(_DWORD *)(v11 + 136);
      v36[0] = 3;
      WORD1(v36[0]) = v20;
      if ( v19 )
        ipc_log_string(
          *(_QWORD *)(v19 + 256),
          "%s[%d:%d] %s: \n",
          *(const char **)(v11 + 128),
          v20,
          *(_DWORD *)(v11 + 140),
          "qcom_glink_send_close_req");
      goto LABEL_32;
    }
LABEL_31:
    v25 = *(_DWORD *)(v11 + 136);
    v36[0] = 3;
    WORD1(v36[0]) = v25;
LABEL_32:
    qcom_glink_tx(v8, (__int64)v36, 8, 0, 0, 1);
    goto LABEL_44;
  }
LABEL_26:
  v23 = *(_QWORD *)(v11 + 112);
  if ( v23 )
  {
    ipc_log_string(
      *(_QWORD *)(v23 + 256),
      "%s[%d:%d] %s: Initializing ept\n",
      *(const char **)(v11 + 128),
      *(_DWORD *)(v11 + 136),
      *(_DWORD *)(v11 + 140),
      "qcom_glink_create_ept");
    v24 = *(_QWORD *)(v11 + 112);
    *(_QWORD *)v11 = a1;
    *(_QWORD *)(v11 + 16) = a2;
    *(_QWORD *)(v11 + 88) = a3;
    *(_QWORD *)(v11 + 96) = glink_endpoint_ops;
    if ( v24 )
      ipc_log_string(
        *(_QWORD *)(v24 + 256),
        "%s[%d:%d] %s: Initialized ept\n",
        *(const char **)(v11 + 128),
        *(_DWORD *)(v11 + 136),
        *(_DWORD *)(v11 + 140),
        "qcom_glink_create_ept");
  }
  else
  {
    *(_QWORD *)v11 = a1;
    *(_QWORD *)(v11 + 16) = a2;
    *(_QWORD *)(v11 + 88) = a3;
    *(_QWORD *)(v11 + 96) = glink_endpoint_ops;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return v11;
}
