__int64 __fastcall cam_cpas_util_vote_default_ahb_axi(__int64 a1, int a2)
{
  __int64 v2; // x19
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned int v7; // w22
  unsigned int v8; // w8
  unsigned __int64 v9; // x23
  int updated; // w0

  v2 = *(_QWORD *)(a1 + 3680);
  v5 = cam_cpas_util_vote_bus_client_level(v2 + 2856, 2 * (unsigned int)(a2 == 1));
  if ( (_DWORD)v5 )
  {
    v7 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_default_ahb_axi",
      574,
      "Failed in AHB vote, enable=%d, rc=%d",
      a2,
      v5);
    return v7;
  }
  v8 = *(_DWORD *)(v2 + 2780);
  if ( !v8 )
    return 0;
  v9 = (unsigned __int64)(a2 != 0) << 10;
  if ( (*(_BYTE *)(v2 + 3184) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 3392) = v9;
    *(_QWORD *)(v2 + 3400) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 3104,
           0,
           v2 + 3384,
           v2 + 3448);
    v7 = v5;
    if ( (_DWORD)v5 )
      goto LABEL_26;
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 < 2 )
    return 0;
  if ( (*(_BYTE *)(v2 + 3592) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 3800) = v9;
    *(_QWORD *)(v2 + 3808) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 3512,
           0,
           v2 + 3792,
           v2 + 3856);
    v7 = v5;
    if ( (_DWORD)v5 )
      goto LABEL_26;
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 < 3 )
    return 0;
  if ( (*(_BYTE *)(v2 + 4000) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 4208) = v9;
    *(_QWORD *)(v2 + 4216) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 3920,
           0,
           v2 + 4200,
           v2 + 4264);
    v7 = v5;
    if ( (_DWORD)v5 )
      goto LABEL_26;
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 < 4 )
    return 0;
  if ( (*(_BYTE *)(v2 + 4408) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 4616) = v9;
    *(_QWORD *)(v2 + 4624) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 4328,
           0,
           v2 + 4608,
           v2 + 4672);
    v7 = v5;
    if ( (_DWORD)v5 )
      goto LABEL_26;
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 < 5 )
    return 0;
  if ( (*(_BYTE *)(v2 + 4816) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 5024) = v9;
    *(_QWORD *)(v2 + 5032) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 4736,
           0,
           v2 + 5016,
           v2 + 5080);
    v7 = v5;
    if ( (_DWORD)v5 )
      goto LABEL_26;
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 < 6 )
    return 0;
  if ( (*(_BYTE *)(v2 + 5224) & 1) == 0 )
  {
    *(_QWORD *)(v2 + 5432) = v9;
    *(_QWORD *)(v2 + 5440) = v9;
    v5 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
           *(_QWORD *)(a1 + 3392),
           v2,
           v2 + 5144,
           0,
           v2 + 5424,
           v2 + 5488);
    v7 = v5;
    if ( (_DWORD)v5 )
    {
LABEL_26:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_vote_default_ahb_axi",
        598,
        "Failed in mnoc vote, enable=%d, rc=%d",
        a2,
        v7);
      if ( (*(_BYTE *)(v2 + 2856) & 1) != 0 )
      {
        if ( *(_DWORD *)(v2 + 2912) )
        {
          updated = cam_soc_bus_client_update_request(*(_QWORD *)(v2 + 3088), 0);
          if ( updated )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_util_vote_bus_client_level",
              243,
              "Client: %s update request failed rc: %d",
              *(const char **)(v2 + 2920),
              updated);
          else
            *(_DWORD *)(v2 + 2912) = 0;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_vote_bus_client_level",
          223,
          "bus client not valid");
      }
      return v7;
    }
    v8 = *(_DWORD *)(v2 + 2780);
  }
  if ( v8 <= 6 )
    return 0;
  __break(0x5512u);
  return cam_cpas_util_vote_bus_client_level(v5, v6);
}
