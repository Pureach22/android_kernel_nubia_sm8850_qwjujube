__int64 __fastcall gen8_gmu_aop_send_acd_state(__int64 result, char a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w0
  _QWORD v5[4]; // [xsp+0h] [xbp-30h] BYREF
  int v6; // [xsp+20h] [xbp-10h]
  __int64 v7; // [xsp+28h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 1016);
  if ( v2 )
  {
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      v3 = result;
      v6 = 0;
      memset(v5, 0, sizeof(v5));
      v4 = scnprintf(v5, 36, "{class: gpu, res: acd, val: %d}", a2 & 1);
      result = qmp_send(*(_QWORD *)(v3 + 1016), v5, (v4 & 0xFFFFFFFC) + 4);
      if ( (result & 0x80000000) != 0 )
        result = dev_err(*(_QWORD *)(v3 + 3368) + 16LL, "AOP qmp send message failed: %d\n", result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
