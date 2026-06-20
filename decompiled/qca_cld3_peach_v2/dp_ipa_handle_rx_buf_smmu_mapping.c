__int64 __fastcall dp_ipa_handle_rx_buf_smmu_mapping(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        unsigned int a6,
        int a7)
{
  int v15; // w8
  int v16; // w10
  int v17; // w9
  unsigned int v18; // w8
  unsigned int v19; // w9

  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0
    || *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) != 1
    || (wlan_ipa_is_shared_smmu_enabled() & 1) != 0 )
  {
    return 0;
  }
  if ( !*(_DWORD *)(a1 + 18200) || !*(_DWORD *)(a1 + 18032) )
  {
    if ( (a4 & 1) != 0 || (*(_BYTE *)(a2 + 49) & 1) == 0 )
      return 0;
    if ( a1 )
      ++*(_DWORD *)(a1 + 14076);
  }
  v15 = *(_DWORD *)(a2 + 48);
  if ( ((v15 & 0x100) == 0) == (a4 & 1) )
  {
    v16 = v15 & 0x3FFFFFF;
    if ( (a4 & 1) != 0 )
      v17 = 256;
    else
      v17 = 0;
    v18 = v15 & 0xFFFFFEFF;
    v19 = v16 & 0xFFFFFEFF | v17 | (a7 << 26);
    if ( (a4 & 1) != 0 )
      v18 = v19;
    *(_DWORD *)(a2 + 48) = v18;
    return _dp_ipa_handle_buf_smmu_mapping(a1, a2, a3, a4 & 1, a5, a6);
  }
  else
  {
    if ( (a4 & 1) != 0 )
    {
      if ( a1 )
      {
        ++*(_DWORD *)(a1 + 14068);
        return 4;
      }
    }
    else if ( a1 )
    {
      ++*(_DWORD *)(a1 + 14072);
      return 4;
    }
    return 4;
  }
}
