__int64 __fastcall dp_ipa_pcie_link_down(__int64 a1)
{
  hif_allow_l1(**(_QWORD **)(a1 + 1128));
  return hif_enable_rtpm();
}
