__int64 __fastcall cam_vfe_bus_ver3_update_wm_mc_cfg(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 v5; // x14
  __int64 v6; // x12
  __int64 v7; // x13
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x13

  if ( a2 && (v2 = __clz(__rbit32(a2)), v2 <= 2) )
  {
    if ( !*(_DWORD *)(a1 + 32) )
      return 0;
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
    v4 = *(_QWORD *)(v3 + 64) + 80LL * v2;
    v5 = *(_QWORD *)(v3 + 24);
    v7 = *(_QWORD *)(v3 + 32);
    v6 = *(_QWORD *)(v3 + 40);
    *(_DWORD *)(v4 + 32) = *(_DWORD *)(v3 + 48);
    *(_QWORD *)(v4 + 16) = v7;
    *(_QWORD *)(v4 + 24) = v6;
    *(_QWORD *)(v4 + 8) = v5;
    *(_QWORD *)v4 = *(_QWORD *)(v3 + 16);
    if ( *(_DWORD *)(a1 + 32) <= 1u )
      return 0;
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL);
    v9 = *(_QWORD *)(v8 + 64) + 80LL * v2;
    v11 = *(_QWORD *)(v8 + 32);
    v10 = *(_QWORD *)(v8 + 40);
    v12 = *(_QWORD *)(v8 + 24);
    *(_DWORD *)(v9 + 32) = *(_DWORD *)(v8 + 48);
    *(_QWORD *)(v9 + 16) = v11;
    *(_QWORD *)(v9 + 24) = v10;
    *(_QWORD *)(v9 + 8) = v12;
    *(_QWORD *)v9 = *(_QWORD *)(v8 + 16);
    if ( *(_DWORD *)(a1 + 32) > 2u )
    {
      __break(0x5512u);
      return cam_vfe_bus_ver3_release_wm();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_update_wm_mc_cfg",
      2029,
      "Invalid hw context mask: 0x%x",
      a2);
    return 4294967274LL;
  }
}
