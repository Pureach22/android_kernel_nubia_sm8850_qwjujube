bool __fastcall policy_mgr_2ghz_connection_present(__int64 a1)
{
  _BOOL4 v2; // w20

  qdf_mutex_acquire(a1 + 56);
  v2 = BYTE4(qword_8D4F00) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
    || BYTE4(qword_8D4F24) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C))
    || BYTE4(qword_8D4F48) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30))
    || BYTE4(qword_8D4F6C) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54))
    || BYTE4(qword_8D4F90) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78));
  qdf_mutex_release(a1 + 56);
  return v2;
}
