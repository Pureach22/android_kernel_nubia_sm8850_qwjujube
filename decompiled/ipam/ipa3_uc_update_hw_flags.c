__int64 __fastcall ipa3_uc_update_hw_flags(int a1)
{
  return ipa3_uc_send_cmd_64b_param(a1, 0, 1, 0, 0, 250);
}
