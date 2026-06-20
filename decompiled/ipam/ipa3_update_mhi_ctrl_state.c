__int64 __fastcall ipa3_update_mhi_ctrl_state(char a1, char a2)
{
  __int64 v4; // x8
  char v5; // w10

  mutex_lock(ipa3_ctx + 29472);
  v4 = ipa3_ctx;
  if ( (a2 & 1) != 0 )
    v5 = *(_BYTE *)(ipa3_ctx + 51296) | a1;
  else
    v5 = *(_BYTE *)(ipa3_ctx + 51296) & ~a1;
  *(_BYTE *)(ipa3_ctx + 51296) = v5;
  mutex_unlock(v4 + 29472);
  return ipa_send_mhi_endp_ind_to_modem();
}
