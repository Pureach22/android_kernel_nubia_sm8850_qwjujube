__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index_nan_ndi(__int64 a1)
{
  char v2; // w0
  unsigned int v3; // w8
  unsigned int v4; // w9

  if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_81C464) )
  {
    if ( dword_81C450 )
      return 143;
    else
      return 142;
  }
  else
  {
    v2 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464));
    if ( dword_81C450 )
      v3 = 147;
    else
      v3 = 146;
    if ( dword_81C450 )
      v4 = 145;
    else
      v4 = 144;
    if ( (v2 & 1) != 0 )
      return v4;
    else
      return v3;
  }
}
