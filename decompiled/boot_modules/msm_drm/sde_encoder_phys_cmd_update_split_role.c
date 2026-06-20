__int64 __fastcall sde_encoder_phys_cmd_update_split_role(__int64 result, int a2)
{
  __int64 v2; // x8
  __int64 v4; // x8
  bool v5; // w21
  int v6; // w20
  int v7; // w4
  __int64 v8; // x22
  bool v9; // w8
  __int64 v10; // x19

  if ( result )
  {
    v2 = *(_QWORD *)(result + 8);
    v5 = v2 && (v4 = *(_QWORD *)(v2 + 2512)) != 0 && *(_DWORD *)(v4 + 1376) == 10;
    v6 = *(_DWORD *)(result + 664);
    *(_DWORD *)(result + 664) = a2;
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)result )
        v7 = *(_DWORD *)(*(_QWORD *)result + 24LL);
      else
        v7 = -1;
      v8 = result;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d old role %d new role %d\n", v7, *(_DWORD *)(result + 672) - 1, v6, a2);
      result = v8;
    }
    if ( a2 )
      v9 = 0;
    else
      v9 = v5;
    if ( v9 || a2 != 4 && v6 != a2 )
    {
      v10 = result;
      sde_encoder_helper_split_config((__int64 **)result, *(_DWORD *)(result + 672));
      sde_encoder_phys_cmd_pingpong_config(v10);
      return sde_encoder_phys_cmd_update_flush_mask(v10);
    }
  }
  return result;
}
