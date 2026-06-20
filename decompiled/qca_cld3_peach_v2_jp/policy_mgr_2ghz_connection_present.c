bool __fastcall policy_mgr_2ghz_connection_present(__int64 a1)
{
  _BOOL4 v2; // w20

  qdf_mutex_acquire(a1 + 56);
  v2 = BYTE4(qword_81C458) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
    || BYTE4(qword_81C47C) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464))
    || BYTE4(qword_81C4A0) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488))
    || BYTE4(qword_81C4C4) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC))
    || BYTE4(qword_81C4E8) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0));
  qdf_mutex_release(a1 + 56);
  return v2;
}
