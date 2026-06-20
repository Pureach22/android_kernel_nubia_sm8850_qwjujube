__int64 __fastcall rndis_ipa_next_state(int a1, int a2)
{
  unsigned int v2; // w19
  int v3; // w8
  const char *v4; // x6
  int v5; // w8
  int v6; // w21
  __int64 v7; // x0
  const char *v8; // x4
  const char *v9; // x5

  if ( a1 <= 1 )
  {
    if ( !a1 )
      goto LABEL_17;
    if ( a1 == 1 )
    {
      v3 = a2 - 1;
      if ( (unsigned int)(a2 - 1) < 5 )
      {
        v4 = off_1F65D0[v3];
        v2 = dword_401848[v3];
        goto LABEL_24;
      }
      goto LABEL_17;
    }
    goto LABEL_18;
  }
  if ( a1 == 2 )
  {
    if ( a2 == 4 )
    {
      v2 = 1;
      goto LABEL_23;
    }
    if ( a2 == 2 )
    {
      v2 = 4;
      goto LABEL_23;
    }
LABEL_17:
    v2 = 5;
    v4 = "Forbidden";
    goto LABEL_24;
  }
  if ( a1 == 3 )
  {
    v5 = a2 - 1;
    if ( (unsigned int)(a2 - 1) < 5 )
    {
      v4 = off_1F65F8[v5];
      v2 = dword_40185C[v5];
      goto LABEL_24;
    }
    goto LABEL_17;
  }
  if ( a1 != 4 )
  {
LABEL_18:
    v6 = a1;
    if ( (unsigned int)__ratelimit(&rndis_ipa_next_state__rs, "rndis_ipa_next_state") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3FA4D9, "rndis_ipa_next_state");
      v7 = ipa_rndis_logbuf;
      if ( ipa_rndis_logbuf )
        goto LABEL_20;
    }
    else
    {
      v7 = ipa_rndis_logbuf;
      if ( ipa_rndis_logbuf )
      {
LABEL_20:
        ipc_log_string(v7, "RNDIS_IPA %s:%d State is not supported\n", "rndis_ipa_next_state", 2292);
        v2 = 5;
        v4 = "Forbidden";
        a1 = v6;
        goto LABEL_24;
      }
    }
    return 5;
  }
  if ( a2 == 3 )
  {
    v2 = 2;
    goto LABEL_23;
  }
  if ( a2 != 4 )
    goto LABEL_17;
  v2 = 3;
LABEL_23:
  v4 = "Allowed";
LABEL_24:
  if ( ipa_rndis_logbuf )
  {
    if ( (unsigned int)a1 > 4 )
    {
      v8 = "Not supported";
      if ( v2 > 4 )
        goto LABEL_27;
    }
    else
    {
      v8 = off_1F6620[a1];
      if ( v2 > 4 )
      {
LABEL_27:
        v9 = "Not supported";
LABEL_30:
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d state transition ( %s -> %s )- %s\n",
          "rndis_ipa_next_state",
          2301,
          v8,
          v9,
          v4);
        return v2;
      }
    }
    v9 = off_1F6620[v2];
    goto LABEL_30;
  }
  return v2;
}
