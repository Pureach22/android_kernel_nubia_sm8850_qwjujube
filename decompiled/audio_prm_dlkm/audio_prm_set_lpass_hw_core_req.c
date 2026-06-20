__int64 __fastcall audio_prm_set_lpass_hw_core_req(__int64 a1, int a2, unsigned int a3)
{
  int v4; // w0

  if ( a2 == 1 )
  {
    if ( dword_6D6C )
      return audio_prm_set_lpass_cpu_lpr_req(a3);
    v4 = 1;
  }
  else
  {
    v4 = a2;
  }
  return audio_prm_set_lpass_hw_core_req(v4, a3);
}
