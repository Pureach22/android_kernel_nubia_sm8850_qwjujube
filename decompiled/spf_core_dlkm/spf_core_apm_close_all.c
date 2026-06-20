void spf_core_apm_close_all()
{
  __int64 v0; // x8
  __int64 *v1; // x21
  __int64 v2; // x19
  unsigned int v3; // w0
  _BOOL4 v4; // w19
  unsigned int v5; // w19
  __int64 v6; // x0
  __int64 v7; // x19
  _QWORD v8[5]; // [xsp+8h] [xbp-48h] BYREF
  int v9; // [xsp+30h] [xbp-20h] BYREF
  __int16 v10; // [xsp+34h] [xbp-1Ch]
  _WORD v11[7]; // [xsp+36h] [xbp-1Ah] BYREF
  int v12; // [xsp+44h] [xbp-Ch]
  __int64 v13; // [xsp+48h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( spf_core_priv )
  {
    memset(v11, 0, sizeof(v11));
    mutex_lock(spf_core_priv + 8);
    v0 = spf_core_priv;
    v1 = *(__int64 **)(spf_core_priv + 56);
    if ( !v1 )
    {
LABEL_30:
      mutex_unlock(v0 + 8);
      goto LABEL_31;
    }
    mutex_lock(v1 + 4);
    v2 = *v1;
    v9 = 6240;
    v10 = 770;
    *(_QWORD *)&v11[1] = 0x100000003LL;
    v12 = 16781331;
    if ( (unsigned int)__ratelimit(&spf_core_apm_close_all__rs, "spf_core_apm_close_all") )
      dev_info(*(_QWORD *)spf_core_priv, "%s: send_command \n", "spf_core_apm_close_all");
    v3 = gpr_send_pkt(v2, &v9);
    if ( (v3 & 0x80000000) != 0 )
    {
      v5 = v3;
      if ( (unsigned int)__ratelimit(&spf_core_apm_close_all__rs_1, "spf_core_apm_close_all") )
        dev_err(*(_QWORD *)spf_core_priv, "%s: send_pkt_failed %d\n", "spf_core_apm_close_all", v5);
      goto LABEL_29;
    }
    if ( (v1[10] & 1) != 0 )
    {
      v4 = 1;
    }
    else
    {
      memset(v8, 0, sizeof(v8));
      init_wait_entry(v8, 0);
      prepare_to_wait_event(v1 + 1, v8, 2);
      if ( (v1[10] & 1) != 0 )
      {
        v4 = 1;
      }
      else
      {
        v6 = 1250;
        do
        {
          v7 = schedule_timeout(v6);
          prepare_to_wait_event(v1 + 1, v8, 2);
          if ( ((_BYTE)v1[10] & (v7 == 0)) != 0 )
            v6 = 1;
          else
            v6 = v7;
        }
        while ( (v1[10] & 1) == 0 && v6 );
        v4 = (int)v6 > 0;
      }
      finish_wait(v1 + 1, v8);
    }
    if ( (unsigned int)__ratelimit(&spf_core_apm_close_all__rs_3, "spf_core_apm_close_all") )
    {
      dev_info(*(_QWORD *)spf_core_priv, "%s: wait event unblocked \n", "spf_core_apm_close_all");
      if ( !v4 )
        goto LABEL_27;
    }
    else if ( !v4 )
    {
      goto LABEL_27;
    }
    if ( *((_BYTE *)v1 + 80) == 1 )
    {
      if ( *((_DWORD *)v1 + 21) && (unsigned int)__ratelimit(&spf_core_apm_close_all__rs_5, "spf_core_apm_close_all") )
        dev_err(
          *(_QWORD *)spf_core_priv,
          "%s, cmd failed status %d",
          "spf_core_apm_close_all",
          *((unsigned int *)v1 + 21));
LABEL_29:
      *((_BYTE *)v1 + 80) = 0;
      mutex_unlock(v1 + 4);
      v0 = spf_core_priv;
      goto LABEL_30;
    }
LABEL_27:
    if ( (unsigned int)__ratelimit(&spf_core_apm_close_all__rs_7, "spf_core_apm_close_all") )
      dev_err(*(_QWORD *)spf_core_priv, "%s: command timedout, ret\n", "spf_core_apm_close_all");
    goto LABEL_29;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
}
