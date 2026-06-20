__int64 __fastcall dp_ipa_iounmap_doorbell_vaddr(__int64 a1)
{
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 && (*(_BYTE *)(a1 + 18440) & 1) == 0 )
    iounmap(*(_QWORD *)(a1 + 18424));
  return 0;
}
