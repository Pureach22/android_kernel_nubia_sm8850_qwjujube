__int64 __fastcall cam_ife_csid_ver1_set_csid_qcfa(const void *a1, _DWORD *a2)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  char v6; // w8

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_set_csid_qcfa",
      3587,
      "Invalid param %pK %pK",
      a1,
      a2);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_set_csid_qcfa",
      3597,
      "CSID[%u] NULL res",
      *(_DWORD *)(*(_QWORD *)a1 + 4LL));
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(v3 + 24);
  if ( !v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_set_csid_qcfa",
      3605,
      "CSID[%u] Invalid res_id %u",
      *(_DWORD *)(*(_QWORD *)a1 + 4LL),
      *(_DWORD *)(v3 + 4));
    return 4294967274LL;
  }
  result = 0;
  v6 = debug_mdl;
  *(_DWORD *)(v4 + 48) = a2[2];
  if ( (v6 & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v6 & 8,
      4,
      "cam_ife_csid_ver1_set_csid_qcfa",
      3613,
      "CSID %u QCFA binning %d",
      *(unsigned int *)(*(_QWORD *)a1 + 4LL));
    return 0;
  }
  return result;
}
