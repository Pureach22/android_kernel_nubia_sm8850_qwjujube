bool __fastcall spf_core_is_apm_ready(unsigned int a1)
{
  __int64 v2; // x8
  __int64 *v3; // x27
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x25
  __int64 v7; // x0
  __int64 v8; // x25
  int v9; // w25
  int v10; // w8
  _BOOL4 v11; // w25
  _QWORD v13[5]; // [xsp+8h] [xbp-48h] BYREF
  int v14; // [xsp+30h] [xbp-20h] BYREF
  __int16 v15; // [xsp+34h] [xbp-1Ch]
  __int16 v16; // [xsp+36h] [xbp-1Ah]
  __int64 v17; // [xsp+38h] [xbp-18h]
  int v18; // [xsp+40h] [xbp-10h]
  int v19; // [xsp+44h] [xbp-Ch]
  __int64 v20; // [xsp+48h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !spf_core_priv )
  {
    v11 = 0;
    goto LABEL_30;
  }
  mutex_lock(spf_core_priv + 8);
  v2 = spf_core_priv;
  v3 = *(__int64 **)(spf_core_priv + 56);
  if ( !v3 )
  {
    v11 = 0;
    goto LABEL_29;
  }
  v4 = jiffies;
  v5 = _msecs_to_jiffies(a1);
  mutex_lock(v3 + 4);
  do
  {
    v6 = *v3;
    v18 = 0;
    v16 = 0;
    v14 = 6240;
    v17 = 0x100000003LL;
    v15 = 770;
    v19 = 16781345;
    if ( (unsigned int)__ratelimit(&_spf_core_is_apm_ready__rs, "__spf_core_is_apm_ready") )
      dev_err(*(_QWORD *)spf_core_priv, "%s: send_command ret\n", "__spf_core_is_apm_ready");
    if ( (gpr_send_pkt(v6, &v14) & 0x80000000) == 0 )
    {
      if ( (v3[10] & 1) != 0 )
        goto LABEL_22;
      memset(v13, 0, sizeof(v13));
      init_wait_entry(v13, 0);
      prepare_to_wait_event(v3 + 1, v13, 2);
      if ( (v3[10] & 1) != 0 )
      {
        finish_wait(v3 + 1, v13);
      }
      else
      {
        v7 = 250;
        do
        {
          v8 = schedule_timeout(v7);
          prepare_to_wait_event(v3 + 1, v13, 2);
          if ( ((_BYTE)v3[10] & (v8 == 0)) != 0 )
            v7 = 1;
          else
            v7 = v8;
        }
        while ( (v3[10] & 1) == 0 && v7 );
        v9 = v7;
        finish_wait(v3 + 1, v13);
        if ( v9 < 1 )
        {
LABEL_4:
          if ( (unsigned int)__ratelimit(&_spf_core_is_apm_ready__rs_10, "__spf_core_is_apm_ready") )
            dev_err(*(_QWORD *)spf_core_priv, "%s: command timedout, ret\n", "__spf_core_is_apm_ready");
          goto LABEL_6;
        }
      }
      if ( (v3[10] & 1) != 0 )
      {
LABEL_22:
        v10 = *((_DWORD *)v3 + 21);
        *((_BYTE *)v3 + 80) = 0;
        v11 = v10 != 0;
        if ( v10 || !a1 )
          goto LABEL_27;
        goto LABEL_7;
      }
      goto LABEL_4;
    }
LABEL_6:
    *((_BYTE *)v3 + 80) = 0;
    if ( !a1 )
      break;
LABEL_7:
    usleep_range_state(50000, 50050, 2);
  }
  while ( jiffies - (v5 + v4) < 0 );
  v11 = 0;
LABEL_27:
  mutex_unlock(v3 + 4);
  v2 = spf_core_priv;
LABEL_29:
  mutex_unlock(v2 + 8);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v11;
}
