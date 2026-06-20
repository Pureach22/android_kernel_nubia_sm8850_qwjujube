__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_sta_nan(__int64 a1)
{
  char v2; // w0
  unsigned int v3; // w8
  unsigned int v4; // w9

  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
  {
    if ( dword_8D4EF8 )
      return 137;
    else
      return 136;
  }
  else
  {
    v2 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C));
    if ( dword_8D4EF8 )
      v3 = 141;
    else
      v3 = 140;
    if ( dword_8D4EF8 )
      v4 = 139;
    else
      v4 = 138;
    if ( (v2 & 1) != 0 )
      return v4;
    else
      return v3;
  }
}
