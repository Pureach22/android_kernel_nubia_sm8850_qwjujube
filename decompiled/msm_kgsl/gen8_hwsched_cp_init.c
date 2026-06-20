__int64 __fastcall gen8_hwsched_cp_init(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w21
  __int64 v7; // x20
  unsigned int v8; // w21
  _DWORD v9[13]; // [xsp+Ch] [xbp-34h] BYREF

  *(_QWORD *)&v9[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v3 = to_gen8_gmu(a1);
  memset(&v9[1], 0, 40);
  v9[0] = 131;
  gen8_cp_init_cmds(a1, (__int64)&v9[1]);
  result = gen8_hfi_send_cmd_async(a1, v9, 0x2Cu);
  if ( (_DWORD)result )
    goto LABEL_4;
  v5 = gmu_core_timed_poll_check(a1, 146188, 0, 200, 0x800000);
  if ( v5 )
  {
    v6 = v5;
    gen8_spin_idle_debug((_QWORD *)a1, "CP initialization failed to idle\n");
    result = v6;
LABEL_4:
    *(_DWORD *)(v3 + 1280) = v9[0];
    goto LABEL_5;
  }
  *(_DWORD *)(v3 + 1280) = v9[0];
  result = adreno_zap_shader_load(a1, *(_QWORD *)(v2 + 120));
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(a1 + 20868) )
    {
      v7 = to_gen8_gmu(a1);
      v9[2] = 0;
      *(_QWORD *)v9 = 0x70E6000100000083LL;
      result = gen8_hfi_send_cmd_async(a1, v9, 0xCu);
      if ( !(_DWORD)result )
      {
        result = gmu_core_timed_poll_check(a1, 146188, 0, 200, 0x800000);
        if ( (_DWORD)result )
        {
          v8 = result;
          gen8_spin_idle_debug((_QWORD *)a1, "Switch to unsecure failed to idle\n");
          result = v8;
        }
      }
      *(_DWORD *)(v7 + 1284) = v9[0];
    }
    else
    {
      kgsl_regmap_write(a1 + 13200, 0);
      result = 0;
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
