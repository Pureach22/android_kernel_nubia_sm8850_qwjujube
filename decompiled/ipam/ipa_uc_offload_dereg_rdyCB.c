void __fastcall ipa_uc_offload_dereg_rdyCB(int a1)
{
  if ( (a1 & 0xFFFFFFFE) == 2 )
    ipa3_ntn_uc_dereg_rdyCB();
}
