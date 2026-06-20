__int64 __fastcall populate_dot11_assoc_res_p2p_ie(__int64 a1, __int64 a2, __int64 a3)
{
  if ( wlan_get_vendor_ie_ptr_from_oui(&unk_969516, 4u, (unsigned __int8 *)(a3 + 1006), *(_WORD *)(a3 + 1004)) )
  {
    *(_BYTE *)(a2 + 2) = 0;
    *(_WORD *)a2 = 257;
    *(_BYTE *)(a2 + 4) = 0;
  }
  return 0;
}
