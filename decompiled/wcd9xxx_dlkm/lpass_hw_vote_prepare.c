__int64 __fastcall lpass_hw_vote_prepare(__int64 a1)
{
  int v1; // w8
  unsigned int v3; // w0
  unsigned int v4; // w0
  unsigned int v6; // w19
  void *v7; // x0

  v1 = *(_DWORD *)(a1 - 56);
  if ( v1 == 9 )
  {
    v3 = audio_prm_set_lpass_hw_core_req(a1 - 48, 1, 1);
    if ( (v3 & 0x80000000) != 0 )
    {
      v6 = v3;
      if ( !(unsigned int)__ratelimit(&lpass_hw_vote_prepare_rtl, "lpass_hw_vote_prepare") )
        return v6;
      v7 = &unk_8920;
LABEL_13:
      printk(v7, "lpass_hw_vote_prepare");
      return v6;
    }
    v1 = *(_DWORD *)(a1 - 56);
  }
  if ( v1 != 11 )
    return 0;
  v4 = audio_prm_set_lpass_hw_core_req(a1 - 48, 2, 1);
  if ( (v4 & 0x80000000) == 0 )
    return 0;
  v6 = v4;
  if ( (unsigned int)__ratelimit(&lpass_hw_vote_prepare_rtl, "lpass_hw_vote_prepare") )
  {
    v7 = &unk_8943;
    goto LABEL_13;
  }
  return v6;
}
