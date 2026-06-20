__int64 __fastcall mhi_prepare_channel(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x8
  unsigned __int64 v6; // x4
  unsigned int inited; // w22
  unsigned int updated; // w0
  __int64 result; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  int v14; // w23
  int v15; // w8
  __int64 v16; // x21
  __int64 v17; // x22
  unsigned int v18; // w0
  unsigned int v19; // w21
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  void (__fastcall *v23)(__int64, __int64, __int64); // x8
  __int64 v24; // x2
  __int64 v25; // x21
  const char *v26; // x3
  __int64 v27; // x8
  const char *v28; // x3
  _QWORD v29[3]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int *)(a1 + 344);
  v6 = *(unsigned int *)(a2 + 256);
  if ( ((v6 >> v5) & 1) != 0 )
  {
    mutex_lock(a2 + 288);
    if ( (*(_BYTE *)(a2 + 394) & 1) == 0 )
    {
      inited = mhi_init_chan_ctxt(a1, a2);
      if ( inited )
      {
LABEL_7:
        mutex_unlock(a2 + 288);
        result = inited;
        goto LABEL_40;
      }
    }
    updated = mhi_update_channel_state(a1, a2, 2);
    if ( updated )
    {
      inited = updated;
      if ( (*(_BYTE *)(a2 + 394) & 1) == 0 )
        mhi_deinit_chan_ctxt(a1, a2);
      goto LABEL_7;
    }
    if ( *(_DWORD *)(a2 + 216) == 2 )
    {
      *(_BYTE *)(a2 + 395) = a3 & 1;
      if ( (a3 & 1) == 0 )
        goto LABEL_27;
    }
    else if ( (*(_BYTE *)(a2 + 395) & 1) == 0 )
    {
LABEL_27:
      mutex_unlock(a2 + 288);
      result = 0;
      goto LABEL_40;
    }
    v12 = *(_QWORD *)(a2 + 144);
    v11 = *(_QWORD *)(a2 + 152);
    if ( v11 >= v12 )
    {
      v15 = (v12 - *(_QWORD *)(a2 + 136)) / *(_QWORD *)(a2 + 160)
          + (*(_QWORD *)(a2 + 136) + *(_QWORD *)(a2 + 168) - v11) / *(_QWORD *)(a2 + 160);
      v14 = v15 - 1;
      if ( v15 == 1 )
      {
LABEL_22:
        raw_read_lock_bh(a1 + 320);
        if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
        {
          raw_read_lock_irq(a2 + 368);
          v20 = *(_QWORD *)(a2 + 152);
          v21 = *(_QWORD *)(a2 + 136);
          v22 = *(_QWORD *)(a2 + 112);
          __dmb(2u);
          **(_QWORD **)(a2 + 120) = v20 - v21 + v22;
          v23 = *(void (__fastcall **)(__int64, __int64, __int64))(a2 + 248);
          v24 = *(_QWORD *)(a2 + 192);
          if ( *((_DWORD *)v23 - 1) != -396405511 )
            __break(0x8228u);
          v23(a1, a2 + 224, v24);
          raw_read_unlock_irq(a2 + 368);
        }
        raw_read_unlock_bh(a1 + 320);
        goto LABEL_27;
      }
    }
    else
    {
      v13 = (v12 - v11) / *(_QWORD *)(a2 + 160);
      v14 = v13 - 1;
      if ( (_DWORD)v13 == 1 )
        goto LABEL_22;
    }
    v16 = *(_QWORD *)(a1 + 600);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v32 = 0;
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v29[1] = 0;
      v29[2] = 0;
      v17 = _kmalloc_noprof(v16, 3264);
      if ( !v17 )
      {
        v19 = -12;
        goto LABEL_36;
      }
      v29[0] = v17;
      v30 = v17;
      v32 = v16;
      v18 = mhi_gen_tre(a1, a2, (__int64)v29, 2u);
      if ( v18 )
        break;
      if ( !--v14 )
        goto LABEL_22;
    }
    v19 = v18;
    kfree(v17);
LABEL_36:
    mutex_unlock(a2 + 288);
    mhi_unprepare_channel(a1, a2);
    result = v19;
  }
  else
  {
    v25 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( (unsigned int)v5 <= 9 )
      v26 = mhi_ee_str[v5];
    else
      v26 = "INVALID_EE";
    dev_err(
      *(_QWORD *)(a2 + 272) + 40LL,
      "[E][%s] Current EE: %s Required EE Mask: 0x%x\n",
      "mhi_prepare_channel",
      v26,
      v6);
    if ( v25 && *(_DWORD *)(v25 + 24) <= 2u )
    {
      v27 = *(unsigned int *)(a1 + 344);
      if ( (unsigned int)v27 <= 9 )
        v28 = mhi_ee_str[v27];
      else
        v28 = "INVALID_EE";
      ipc_log_string(
        *(_QWORD *)(v25 + 32),
        "[E][%s] Current EE: %s Required EE Mask: 0x%x\n",
        "mhi_prepare_channel",
        v28,
        *(_DWORD *)(a2 + 256));
    }
    result = 4294967189LL;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
