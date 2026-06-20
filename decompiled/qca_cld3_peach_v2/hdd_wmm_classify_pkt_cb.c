__int64 __fastcall hdd_wmm_classify_pkt_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  char v4; // w9
  _BYTE v5[4]; // [xsp+0h] [xbp-10h] BYREF
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5[0] = 0;
  result = hdd_wmm_classify_critical_pkt(a2, &v6, v5);
  if ( v5[0] == 1 )
  {
    v4 = *(_BYTE *)(a2 + 68);
    *(_DWORD *)(a2 + 144) = v6;
    *(_BYTE *)(a2 + 68) = v4 | 0x80;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
