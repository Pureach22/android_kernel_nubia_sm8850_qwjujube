bool __fastcall policy_mgr_is_third_conn_sta_p2p_p2p_valid(__int64 a1, unsigned int a2)
{
  int v4; // w21
  int v5; // w22
  bool v6; // zf
  char v7; // w10
  bool v9; // w12
  bool v10; // w10
  bool v11; // w11

  v4 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  v5 = policy_mgr_mode_specific_connection_count(a1, 3, nullptr);
  if ( v5 + v4 + (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr) != 2 || !a2 && v4 == 1 )
    return 1;
  if ( !(_DWORD)pm_conc_connection_list && (_DWORD)qword_81C464 == 3
    || ((_DWORD)qword_81C464 ? (v6 = (_DWORD)qword_81C464 == 3) : (v6 = 1),
        !v6 ? (v7 = 0) : (v7 = 1),
        (_DWORD)pm_conc_connection_list == 3 && (v7 & 1) != 0
     || !(_DWORD)pm_conc_connection_list && (_DWORD)qword_81C464 == 2
     || ((_DWORD)qword_81C464 == 2 ? (v9 = 1) : (v9 = (_DWORD)qword_81C464 == 0),
         (_DWORD)qword_81C464 == 2 ? (v10 = (_DWORD)pm_conc_connection_list == 3) : (v10 = 0),
         (_DWORD)pm_conc_connection_list == 2 ? (v11 = v9) : (v11 = 0),
         v11 || v10)) )
  {
    if ( v4 > 1 )
      return 1;
  }
  else if ( (_DWORD)pm_conc_connection_list != 2 || (_DWORD)qword_81C464 != 3 || v4 >= 2 )
  {
    return 1;
  }
  return a2 > 3 || a2 == 1 || (wlan_mlme_get_p2p_p2p_conc_support(a1) & 1) != 0;
}
