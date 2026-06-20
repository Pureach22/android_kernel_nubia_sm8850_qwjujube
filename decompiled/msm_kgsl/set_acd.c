__int64 __fastcall set_acd(__int64 result, unsigned __int8 *a2)
{
  __int64 *v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w3
  __int64 v5; // x19
  int v6; // w0
  __int64 v7; // x8
  _QWORD v8[2]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v9[4]; // [xsp+10h] [xbp-30h] BYREF
  int v10; // [xsp+30h] [xbp-10h]
  __int64 v11; // [xsp+38h] [xbp-8h]

  v2 = (__int64 *)(result - 384);
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(result - 384);
  v4 = *a2;
  *(_BYTE *)(result + 20433) = v4;
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = result;
      v8[0] = 0;
      memset(v9, 0, sizeof(v9));
      v10 = 0;
      v6 = scnprintf(v9, 36, "{class: gpu, res: acd, val: %d}", v4);
      v7 = *v2;
      v8[1] = v9;
      v8[0] = (v6 & 0xFFFFFFFC) + 4;
      result = mbox_send_message(v7, v8);
      if ( (result & 0x80000000) != 0 )
        result = dev_err(*(_QWORD *)(v5 + 1544) + 16LL, "AOP mbox send message failed: %d\n", result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
