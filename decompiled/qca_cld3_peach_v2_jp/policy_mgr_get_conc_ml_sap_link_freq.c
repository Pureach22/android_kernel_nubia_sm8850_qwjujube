__int64 __fastcall policy_mgr_get_conc_ml_sap_link_freq(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  __int64 result; // x0

  if ( (((__int64 (*)(void))policy_mgr_is_mlo_ap)() & 1) == 0 )
    return 0;
  *a3 = 1;
  if ( BYTE4(qword_81C458) == 1
    && (_DWORD)pm_conc_connection_list == 1
    && (_DWORD)qword_81C458 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(pm_conc_connection_list);
  }
  if ( BYTE4(qword_81C47C) == 1
    && (_DWORD)qword_81C464 == 1
    && (_DWORD)qword_81C47C != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_81C464);
  }
  if ( BYTE4(qword_81C4A0) == 1
    && (_DWORD)qword_81C488 == 1
    && (_DWORD)qword_81C4A0 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_81C488);
  }
  if ( BYTE4(qword_81C4C4) == 1
    && (_DWORD)qword_81C4AC == 1
    && (_DWORD)qword_81C4C4 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_81C4AC);
  }
  result = 0;
  if ( BYTE4(qword_81C4E8) == 1 && (_DWORD)qword_81C4D0 == 1 )
  {
    if ( (_DWORD)qword_81C4E8 != a2 && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
      return HIDWORD(qword_81C4D0);
    return 0;
  }
  return result;
}
