__int64 __fastcall sme_set_usr_cfg_mu_edca(__int64 result, char a2)
{
  *(_BYTE *)(result + 21773) = a2;
  return result;
}
