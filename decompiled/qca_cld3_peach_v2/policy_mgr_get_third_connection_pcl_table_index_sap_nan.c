__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_sap_nan(__int64 a1)
{
  char v2; // w0
  unsigned int v3; // w8
  unsigned int v4; // w9

  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
  {
    if ( dword_8D4EF8 )
      return 118;
    else
      return 117;
  }
  else
  {
    v2 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C));
    if ( dword_8D4EF8 )
      v3 = 122;
    else
      v3 = 121;
    if ( dword_8D4EF8 )
      v4 = 120;
    else
      v4 = 119;
    if ( (v2 & 1) != 0 )
      return v4;
    else
      return v3;
  }
}
