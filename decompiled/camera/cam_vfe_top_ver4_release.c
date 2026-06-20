__int64 __fastcall cam_vfe_top_ver4_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x8
  __int64 v5; // [xsp+8h] [xbp-8h]
  __int64 v6; // [xsp+28h] [xbp+18h]

  if ( a1 && a2 )
  {
    v2 = *(_QWORD *)(a2 + 24);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v6 = a2;
      v5 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_top_ver4_release",
        1423,
        "VFE:%u Resource in state %d",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL),
        *(_DWORD *)(a2 + 8));
      a1 = v5;
      a2 = v6;
    }
    if ( *(_DWORD *)(a2 + 8) > 1u )
    {
      v4 = *(_QWORD *)(v2 + 72);
      *(_QWORD *)(v4 + 10912) = 0;
      *(_QWORD *)(v4 + 10904) = 0;
      *(_DWORD *)(v2 + 22816) = 0;
      *(_DWORD *)(a2 + 8) = 1;
      return 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_release",
        1426,
        "VFE:%u Error, Resource in Invalid res_state :%d",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL));
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_release",
      1414,
      "Error, Invalid input arguments");
    return 4294967274LL;
  }
}
