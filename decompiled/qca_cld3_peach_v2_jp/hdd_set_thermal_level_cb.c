__int64 __fastcall hdd_set_thermal_level_cb(__int64 a1, char a2)
{
  __int64 v3; // x0
  char v4; // w8

  v3 = *(_QWORD *)(a1 + 8);
  if ( a2 )
    v4 = 1;
  else
    v4 = *(_BYTE *)(a1 + 1352);
  return ucfg_ipa_send_mcc_scc_msg(v3, v4 & 1);
}
