__int64 __fastcall msm_vote_against_sleep_ctl_put(__int64 a1, __int64 a2)
{
  __int64 v3; // x9
  int v4; // w8
  unsigned int v5; // w19
  unsigned int v6; // w0

  mutex_lock(&vote_against_sleep_lock);
  v3 = *(_QWORD *)(a2 + 72);
  v4 = vote_against_sleep_cnt;
  vote_against_sleep_enable = v3 != 0;
  if ( !v3 )
  {
    if ( vote_against_sleep_cnt == 1 )
    {
      v6 = audio_prm_set_vote_against_sleep(0);
      v4 = vote_against_sleep_cnt;
      v5 = v6;
      if ( !vote_against_sleep_cnt )
        goto LABEL_13;
    }
    else
    {
      v5 = 0;
      if ( !vote_against_sleep_cnt )
        goto LABEL_13;
    }
    vote_against_sleep_cnt = v4 - 1;
    goto LABEL_13;
  }
  ++vote_against_sleep_cnt;
  if ( v4 )
  {
    v5 = 0;
  }
  else
  {
    v5 = audio_prm_set_vote_against_sleep(1);
    if ( (v5 & 0x80000000) != 0 )
    {
      if ( vote_against_sleep_cnt )
        --vote_against_sleep_cnt;
      printk(&unk_126D6, "msm_vote_against_sleep_ctl_put", v5);
    }
  }
LABEL_13:
  mutex_unlock(&vote_against_sleep_lock);
  return v5;
}
