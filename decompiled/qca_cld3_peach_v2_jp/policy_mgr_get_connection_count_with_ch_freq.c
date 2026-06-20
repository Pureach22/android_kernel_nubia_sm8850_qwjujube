__int64 __fastcall policy_mgr_get_connection_count_with_ch_freq(int a1)
{
  int v1; // w10
  int v2; // w9
  int v3; // w11
  int v4; // w12
  int v5; // w8
  int v6; // w9

  v1 = BYTE4(qword_81C458);
  v2 = BYTE4(qword_81C47C);
  if ( HIDWORD(pm_conc_connection_list) != a1 )
    v1 = 0;
  v3 = BYTE4(qword_81C4A0);
  if ( HIDWORD(qword_81C464) != a1 )
    v2 = 0;
  v4 = BYTE4(qword_81C4C4);
  if ( HIDWORD(qword_81C488) != a1 )
    v3 = 0;
  if ( HIDWORD(qword_81C4AC) != a1 )
    v4 = 0;
  v5 = BYTE4(qword_81C4E8);
  v6 = v1 + v2 + v3 + v4;
  if ( HIDWORD(qword_81C4D0) != a1 )
    v5 = 0;
  return (unsigned int)(v6 + v5);
}
