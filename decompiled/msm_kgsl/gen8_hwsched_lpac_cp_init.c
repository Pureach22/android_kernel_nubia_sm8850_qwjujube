__int64 __fastcall gen8_hwsched_lpac_cp_init(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  int v4; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v5[6]; // [xsp+10h] [xbp-30h] BYREF

  v5[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 20440) == 1 )
  {
    memset(v5, 0, 40);
    v4 = 135;
    gen8_cp_init_cmds(a1, (__int64)v5);
    result = gen8_hfi_send_cmd_async(a1, &v4, 0x2Cu);
    if ( !(_DWORD)result )
    {
      result = gmu_core_timed_poll_check(a1, 146224, 0, 200, 0x800000);
      if ( (_DWORD)result )
      {
        v3 = result;
        gen8_spin_idle_debug_lpac(a1);
        result = v3;
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
