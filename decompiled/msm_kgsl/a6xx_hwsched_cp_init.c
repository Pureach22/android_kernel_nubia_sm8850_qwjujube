__int64 __fastcall a6xx_hwsched_cp_init(__int64 a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  const char *v4; // x1
  unsigned int v5; // w20
  _QWORD v6[7]; // [xsp+8h] [xbp-38h] BYREF

  v6[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 28LL));
  memset((char *)v6 + 4, 0, 44);
  LODWORD(v6[0]) = 131;
  a6xx_cp_init_cmds(a1, (__int64)v6 + 4);
  result = a6xx_hfi_send_cmd_async(a1, (int *)v6, 0x30u);
  if ( !(_DWORD)result )
  {
    LODWORD(result) = gmu_core_timed_poll_check(a1, 146188, 0, 200, 0x800000);
    if ( (_DWORD)result )
    {
      v4 = "CP initialization failed to idle\n";
LABEL_4:
      v5 = result;
      a6xx_spin_idle_debug((_QWORD *)a1, v4);
      result = v5;
      goto LABEL_6;
    }
    result = adreno_zap_shader_load(a1, *(_QWORD *)(v2 + 120));
    if ( !(_DWORD)result )
    {
      if ( !*(_DWORD *)(a1 + 20868) )
      {
        kgsl_regmap_write(a1 + 13200, 0);
        result = 0;
        goto LABEL_6;
      }
      LODWORD(v6[1]) = 0;
      v6[0] = 0x70E6000100000083LL;
      result = a6xx_hfi_send_cmd_async(a1, (int *)v6, 0xCu);
      if ( !(_DWORD)result )
      {
        result = gmu_core_timed_poll_check(a1, 146188, 0, 200, 0x800000);
        if ( (_DWORD)result )
        {
          v4 = "Switch to unsecure failed to idle\n";
          goto LABEL_4;
        }
      }
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
