__int64 __fastcall lpass_hw_vote_unprepare(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19

  v1 = *(_DWORD *)(result - 56);
  v2 = result;
  if ( v1 == 9 )
  {
    result = audio_prm_set_lpass_hw_core_req(result - 48, 1, 0);
    if ( (result & 0x80000000) != 0 )
      result = printk(&unk_8920, "lpass_hw_vote_unprepare");
    v1 = *(_DWORD *)(v2 - 56);
  }
  if ( v1 == 11 )
  {
    result = audio_prm_set_lpass_hw_core_req(v2 - 48, 2, 0);
    if ( (result & 0x80000000) != 0 )
      return printk(&unk_8D29, "lpass_hw_vote_unprepare");
  }
  return result;
}
