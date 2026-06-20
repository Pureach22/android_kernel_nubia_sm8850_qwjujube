__int64 __fastcall audio_prm_set_vote_against_sleep(char a1)
{
  if ( dword_6D6C )
    return audio_prm_set_lpass_cpu_lpr_req(a1);
  else
    return audio_prm_set_lpass_hw_core_req(1, a1);
}
