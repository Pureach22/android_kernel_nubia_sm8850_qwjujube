__int64 __fastcall _cam_isp_ctx_link_in_acquired(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x21
  int v4; // w8
  int v5; // w7
  unsigned int v6; // w8
  __int64 v7; // x7
  int v8; // w8
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v12; // x22
  __int64 v13; // [xsp+8h] [xbp-8h]
  __int64 v14; // [xsp+28h] [xbp+18h]

  if ( !a2 )
  {
    v7 = *(unsigned int *)(a1 + 32);
    v8 = *(_DWORD *)(a1 + 64);
    v9 = "setup link info is null: %pK ctx: %u link: 0x%x";
    v10 = 9317;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_link_in_acquired",
      v10,
      v9,
      0,
      v7,
      v8);
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)(a2 + 24) )
  {
    v7 = *(unsigned int *)(a1 + 32);
    v8 = *(_DWORD *)(a1 + 64);
    v9 = "crm cb is null: %pK ctx: %u, link: 0x%x";
    v10 = 9323;
    goto LABEL_18;
  }
  v2 = *(_QWORD *)(a1 + 256);
  v3 = v2 + 45600;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v13 = a2;
    v14 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_link_in_acquired",
      9327,
      "Enter.........ctx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    a2 = v13;
    a1 = v14;
  }
  *(_DWORD *)(a1 + 64) = *(_DWORD *)(a2 + 4);
  *(_QWORD *)(a1 + 216) = *(_QWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 37344) = 3;
  v4 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(v2 + 45688) = 0;
  *(_DWORD *)v3 = v4;
  *(_DWORD *)(v2 + 45692) = 0;
  *(_DWORD *)(v2 + 45760) = *(_DWORD *)(a2 + 12);
  if ( *(_DWORD *)(a2 + 16) != 1 )
  {
    *(_BYTE *)(v2 + 45750) = 1;
    v5 = *(_DWORD *)(a2 + 16) - 1;
    *(_DWORD *)(v2 + 45688) = v5;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v12 = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_link_in_acquired",
        9344,
        "Enabled mode switch handling on ctx: %u max delay cnt: %u",
        *(unsigned int *)(a1 + 32));
      v5 = *(_DWORD *)(v3 + 88);
      a1 = v12;
    }
    *(_DWORD *)(v3 + 92) = v5;
  }
  if ( *(_BYTE *)(v3 + 141) == 1 )
    *(_DWORD *)(a1 + 240) = 3;
  v6 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_link_in_acquired",
      9356,
      "next state %d, ctx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 240),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return 0;
  }
  return v6;
}
