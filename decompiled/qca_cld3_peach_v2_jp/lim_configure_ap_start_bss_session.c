void __fastcall lim_configure_ap_start_bss_session(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  char v7; // w8
  __int64 v8; // x0
  __int64 v9; // x2
  _WORD v10[2]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = a2 + 7020;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a2 + 88) = 1;
  v7 = *(_BYTE *)(a3 + 49);
  *(_BYTE *)(a2 + 7021) = 1;
  v11[0] = 0;
  *(_BYTE *)(a2 + 1620) = v7;
  *(_DWORD *)(a2 + 1624) = *(_DWORD *)(a3 + 52);
  *(_BYTE *)(a2 + 251) = *(_DWORD *)(a3 + 44);
  v8 = *(_QWORD *)(a1 + 21552);
  v10[0] = -16385;
  wlan_mlme_is_sap_uapsd_enabled(v8, v11);
  *(_BYTE *)(a2 + 1936) = v11[0];
  *(_BYTE *)(a2 + 428) = wlan_mlme_is_ap_prot_enabled(*(_QWORD *)(a1 + 21552)) & 1;
  wlan_mlme_get_ap_protection_mode(*(_QWORD *)(a1 + 21552), v10);
  qdf_mem_copy((void *)(a2 + 432), v10, 2u);
  wlan_mlme_get_vendor_vht_for_24ghz(*(_QWORD *)(a1 + 21552), (_BYTE *)(a2 + 8628));
  if ( *(_DWORD *)(a2 + 7036) == 3 )
  {
    *(_BYTE *)(v3 + 1605) = 1;
  }
  else
  {
    *(_BYTE *)(v3 + 1605) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1056LL);
    if ( !*(_BYTE *)(a3 + 376) )
    {
      *(_DWORD *)(a2 + 1984) = 1;
      goto LABEL_5;
    }
  }
  *(_DWORD *)(a2 + 1984) = 0;
LABEL_5:
  v9 = *(unsigned int *)(a2 + 7232);
  *(_BYTE *)v3 = *(_BYTE *)(a3 + 48);
  *(_BYTE *)(v3 + 2) = *(_BYTE *)(a3 + 376);
  lim_get_short_slot_from_phy_mode(a1, a2, v9, a2 + 250);
  *(_WORD *)(v3 + 1636) = *(_WORD *)(a3 + 410);
  _ReadStatusReg(SP_EL0);
}
