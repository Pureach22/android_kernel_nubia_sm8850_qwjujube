__int64 __fastcall set_acd_1(__int64 result, unsigned __int8 *a2)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w3
  __int64 v5; // x19
  int v6; // w0
  _QWORD v7[4]; // [xsp+0h] [xbp-30h] BYREF
  int v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  v2 = (_QWORD *)(result - 808);
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(result - 808);
  v4 = *a2;
  *(_BYTE *)(result + 20433) = v4;
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = result;
      v8 = 0;
      memset(v7, 0, sizeof(v7));
      v6 = scnprintf(v7, 36, "{class: gpu, res: acd, val: %d}", v4);
      result = qmp_send(*v2, v7, (v6 & 0xFFFFFFFC) + 4);
      if ( (result & 0x80000000) != 0 )
        result = dev_err(*(_QWORD *)(v5 + 1544) + 16LL, "AOP qmp send message failed: %d\n", result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
