__int64 __fastcall gen7_gmu_aop_send_acd_state(__int64 result, char a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x8
  _QWORD v6[2]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v7[4]; // [xsp+10h] [xbp-30h] BYREF
  int v8; // [xsp+30h] [xbp-10h]
  __int64 v9; // [xsp+38h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 1072);
  if ( v2 )
  {
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      v3 = result;
      v6[0] = 0;
      memset(v7, 0, sizeof(v7));
      v8 = 0;
      v4 = scnprintf(v7, 36, "{class: gpu, res: acd, val: %d}", a2 & 1);
      v5 = *(_QWORD *)(v3 + 1072);
      v6[1] = v7;
      v6[0] = (v4 & 0xFFFFFFFC) + 4;
      result = mbox_send_message(v5, v6);
      if ( (result & 0x80000000) != 0 )
        result = dev_err(*(_QWORD *)(v3 + 3320) + 16LL, "AOP mbox send message failed: %d\n", result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
