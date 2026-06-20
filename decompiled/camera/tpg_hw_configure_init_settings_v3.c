__int64 __fastcall tpg_hw_configure_init_settings_v3(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  _DWORD *v3; // x19
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned int tpg_clk_level; // w0
  int v8; // w0
  _DWORD *v9; // x8
  int v10; // w0

  v2 = *(_QWORD *)(result + 32);
  if ( v2 && *(_QWORD *)(v2 + 16) )
  {
    v3 = (_DWORD *)result;
    mutex_lock(result + 48);
    if ( (unsigned int)(**((_DWORD **)v3 + 4) - 0x10000000) > 5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_configure_init_settings_v3",
        1006,
        "TPG[%d] Unsupported HW Version",
        *v3);
    }
    else
    {
      tpg_clk_level = get_tpg_clk_level((__int64)v3, v5, v6);
      v8 = tpg_hw_soc_enable(v3, tpg_clk_level);
      if ( v8 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "tpg_hw_configure_init_settings_v3",
          992,
          "TPG[%d] hw soc enable failed %d",
          *v3,
          v8);
      }
      else
      {
        v9 = **(_DWORD ***)(*((_QWORD *)v3 + 4) + 16LL);
        if ( v9 )
        {
          if ( *(v9 - 1) != 731976422 )
            __break(0x8228u);
          v10 = ((__int64 (__fastcall *)(_DWORD *, __int64))v9)(v3, a2);
          if ( v10 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "tpg_hw_configure_init_settings_v3",
              1001,
              "TPG[%d] hw init failed %d",
              *v3,
              v10);
        }
      }
    }
    return mutex_unlock(v3 + 12);
  }
  return result;
}
