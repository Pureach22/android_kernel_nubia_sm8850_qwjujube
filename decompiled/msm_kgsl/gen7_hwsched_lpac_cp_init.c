__int64 __fastcall gen7_hwsched_lpac_cp_init(_QWORD *a1)
{
  __int64 result; // x0
  unsigned int v3; // w8
  __int64 v4; // x27
  unsigned int v5; // w26
  unsigned int v6; // w20
  unsigned int v7; // w21
  unsigned int v8; // w22
  unsigned int v9; // w23
  unsigned int v10; // w24
  int v11; // w25
  __int64 v12; // x2
  int v13; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v14[6]; // [xsp+10h] [xbp-30h] BYREF

  v14[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_BYTE *)a1 + 20440) == 1 )
  {
    memset(v14, 0, 40);
    v13 = 135;
    gen7_cp_init_cmds((__int64)a1, (__int64)v14);
    result = gen7_hfi_send_cmd_async((__int64)a1, &v13, 0x2Cu);
    if ( !(_DWORD)result )
    {
      v3 = gmu_core_timed_poll_check(a1, 146224, 0, 200, 0x800000);
      result = 0;
      if ( v3 )
      {
        v4 = a1[1780];
        v5 = v3;
        dev_err(*a1, "LPAC CP initialization failed to idle\n");
        v6 = kgsl_regmap_read(a1 + 1650);
        v7 = kgsl_regmap_read(a1 + 1650);
        v8 = kgsl_regmap_read(a1 + 1650);
        v9 = kgsl_regmap_read(a1 + 1650);
        v10 = kgsl_regmap_read(a1 + 1650);
        v11 = kgsl_regmap_read(a1 + 1650);
        if ( (v4 & 0x200) != 0 )
          v12 = 4;
        else
          v12 = 1;
        dev_err(*a1, "LPAC rb=%d pos=%X/%X rbbm_status=%8.8X/%8.8X int_0_status=%8.8X\n", v12, v6, v7, v8, v9, v10);
        dev_err(*a1, " hwfault=%8.8X\n", v11);
        kgsl_device_snapshot(a1, 0, 0, 0);
        result = v5;
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
