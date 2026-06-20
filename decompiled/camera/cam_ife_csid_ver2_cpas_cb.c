__int64 __fastcall cam_ife_csid_ver2_cpas_cb(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0

  result = 0;
  if ( a2 && a3 )
  {
    if ( *a3 )
    {
      return 0;
    }
    else
    {
      result = 1;
      if ( (a3[3] & 0x700) == 0x100 )
      {
        *(_BYTE *)(a2 + 2161) = 1;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver2_cpas_cb",
            108,
            "CPAS address decode error rxved for CSID[%u]",
            *(_DWORD *)(*(_QWORD *)(a2 + 31120) + 4LL));
          return 1;
        }
      }
    }
  }
  return result;
}
