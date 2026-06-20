__int64 __fastcall populate_dot11f_tdls_ext_capability(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v15; // x22
  unsigned __int64 v16; // x8
  char tdls_chan_switch_prohibited; // w0
  __int64 result; // x0

  v11 = *(_QWORD *)(a3 + 2);
  v12 = a1 + 0x2000;
  v15 = 0x8000000000LL;
  *(_QWORD *)(a3 + 2) = v11 & 0xFFFFFFFFDFFFFFFFLL;
  v16 = v11 & 0xFFFFFFFFCFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a1 + 11367) & 1) << 28);
  *(_QWORD *)(a3 + 2) = v16;
  if ( *(_BYTE *)(a1 + 11369) == 1 )
  {
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a2 + 16),
                                    a4,
                                    a5,
                                    a6,
                                    a7,
                                    a8,
                                    a9,
                                    a10,
                                    a11);
    v16 = *(_QWORD *)(a3 + 2);
    if ( (tdls_chan_switch_prohibited & 1) == 0 )
      v15 = 0x40000000;
  }
  *(_QWORD *)(a3 + 2) = v16 & 0xFFFFFF1FBFFFFFFFLL | v15 | 0x2000000000LL;
  if ( (wlan_cfg80211_tdls_is_fw_wideband_capable(*(_QWORD *)(a2 + 16)) & 1) != 0
    && (*(_BYTE *)(v12 + 3177) || !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284))) )
  {
    *(_QWORD *)(a3 + 2) |= 0x2000000000000000uLL;
  }
  *(_BYTE *)a3 = 1;
  result = lim_compute_ext_cap_ie_length((_BYTE *)a3);
  *(_BYTE *)(a3 + 1) = result;
  return result;
}
