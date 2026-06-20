__int64 __fastcall policy_mgr_get_ml_sta_and_p2p_cli_go_sap_info(
        _QWORD *a1,
        _BYTE *a2,
        _BYTE *a3,
        __int64 a4,
        __int64 a5,
        _BYTE *a6,
        __int64 a7,
        __int64 a8)
{
  int v16; // w9
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x8
  int v20; // w9
  __int64 v21; // x8
  int v22; // w9
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x8

  *a6 = 0;
  qdf_mutex_acquire((__int64)(a1 + 7));
  policy_mgr_get_ml_sta_info(a1, a2, a3, a4, a5, nullptr, 0, 0);
  if ( BYTE4(qword_8D4F00) == 1
    && (unsigned int)pm_conc_connection_list <= 6
    && ((1 << pm_conc_connection_list) & 0x4E) != 0 )
  {
    v16 = HIDWORD(pm_conc_connection_list);
    *(_BYTE *)(a7 + (unsigned __int8)*a6) = qword_8D4F00;
    v17 = (unsigned __int8)*a6;
    *a6 = v17 + 1;
    *(_DWORD *)(a8 + 4 * v17) = v16;
  }
  if ( BYTE4(qword_8D4F24) == 1 && (unsigned int)qword_8D4F0C <= 6 && ((1 << qword_8D4F0C) & 0x4E) != 0 )
  {
    v18 = HIDWORD(qword_8D4F0C);
    *(_BYTE *)(a7 + (unsigned __int8)*a6) = qword_8D4F24;
    v19 = (unsigned __int8)*a6;
    *a6 = v19 + 1;
    *(_DWORD *)(a8 + 4 * v19) = v18;
  }
  if ( BYTE4(qword_8D4F48) == 1 && (unsigned int)qword_8D4F30 <= 6 && ((1 << qword_8D4F30) & 0x4E) != 0 )
  {
    v20 = HIDWORD(qword_8D4F30);
    *(_BYTE *)(a7 + (unsigned __int8)*a6) = qword_8D4F48;
    v21 = (unsigned __int8)*a6;
    *a6 = v21 + 1;
    *(_DWORD *)(a8 + 4 * v21) = v20;
  }
  if ( BYTE4(qword_8D4F6C) == 1 && (unsigned int)qword_8D4F54 <= 6 && ((1 << qword_8D4F54) & 0x4E) != 0 )
  {
    v22 = HIDWORD(qword_8D4F54);
    *(_BYTE *)(a7 + (unsigned __int8)*a6) = qword_8D4F6C;
    v23 = (unsigned __int8)*a6;
    *a6 = v23 + 1;
    *(_DWORD *)(a8 + 4 * v23) = v22;
  }
  if ( BYTE4(qword_8D4F90) == 1 && (unsigned int)qword_8D4F78 <= 6 && ((1 << qword_8D4F78) & 0x4E) != 0 )
  {
    v24 = HIDWORD(qword_8D4F78);
    *(_BYTE *)(a7 + (unsigned __int8)*a6) = qword_8D4F90;
    v25 = (unsigned __int8)*a6;
    *a6 = v25 + 1;
    *(_DWORD *)(a8 + 4 * v25) = v24;
  }
  return qdf_mutex_release((__int64)(a1 + 7));
}
