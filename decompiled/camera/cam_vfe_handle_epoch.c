__int64 __fastcall cam_vfe_handle_epoch(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x20
  __int64 v6; // x21

  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v5 = a2;
    v6 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_handle_epoch",
      2334,
      "VFE:%u Received EPOCH",
      *(_DWORD *)(a1[2] + 4LL));
    a3 = v6;
    a2 = v5;
  }
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(a2 + 36);
  a1[2844] = *(_QWORD *)(a2 + 40);
  a1[2845] = *(_QWORD *)(a2 + 48);
  return 0;
}
