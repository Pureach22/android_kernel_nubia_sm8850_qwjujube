__int64 __fastcall policy_mgr_get_conc_ml_sap_link_freq(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  __int64 result; // x0

  if ( (((__int64 (*)(void))policy_mgr_is_mlo_ap)() & 1) == 0 )
    return 0;
  *a3 = 1;
  if ( BYTE4(qword_8D4F00) == 1
    && (_DWORD)pm_conc_connection_list == 1
    && (_DWORD)qword_8D4F00 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(pm_conc_connection_list);
  }
  if ( BYTE4(qword_8D4F24) == 1
    && (_DWORD)qword_8D4F0C == 1
    && (_DWORD)qword_8D4F24 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_8D4F0C);
  }
  if ( BYTE4(qword_8D4F48) == 1
    && (_DWORD)qword_8D4F30 == 1
    && (_DWORD)qword_8D4F48 != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_8D4F30);
  }
  if ( BYTE4(qword_8D4F6C) == 1
    && (_DWORD)qword_8D4F54 == 1
    && (_DWORD)qword_8D4F6C != a2
    && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
  {
    return HIDWORD(qword_8D4F54);
  }
  result = 0;
  if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F78 == 1 )
  {
    if ( (_DWORD)qword_8D4F90 != a2 && (policy_mgr_is_mlo_ap(a1) & 1) != 0 )
      return HIDWORD(qword_8D4F78);
    return 0;
  }
  return result;
}
