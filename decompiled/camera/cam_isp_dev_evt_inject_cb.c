__int64 __fastcall cam_isp_dev_evt_inject_cb(__int64 a1)
{
  __int64 v1; // x9
  int v2; // w6
  __int64 v3; // x8

  v1 = (unsigned int)dword_3A8B70;
  if ( dword_3A8B70 <= 0 )
  {
    v2 = *(_DWORD *)(a1 + 48);
LABEL_7:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_evt_inject_cb",
      44,
      "No dev hdl found %d",
      v2);
    return 4294967277LL;
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 48);
    v3 = qword_3A8B28;
    while ( *(_DWORD *)(v3 + 60) != v2 )
    {
      --v1;
      v3 += 552;
      if ( !v1 )
        goto LABEL_7;
    }
    cam_context_add_evt_inject(v3, a1 + 16);
    return 0;
  }
}
