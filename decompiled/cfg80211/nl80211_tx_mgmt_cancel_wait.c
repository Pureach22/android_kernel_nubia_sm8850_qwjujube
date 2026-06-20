__int64 __fastcall nl80211_tx_mgmt_cancel_wait(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x20
  _DWORD *v5; // x19
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x2
  _DWORD *v9; // x8
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2[4] + 704LL);
  if ( v3 )
  {
    v4 = a2[6];
    if ( *(_QWORD *)(*(_QWORD *)v4 + 528LL) )
    {
      v5 = (_DWORD *)a2[7];
      result = 4294967201LL;
      v7 = v5[2];
      if ( v7 <= 0xC && (((1 << v7) & 0x71E) != 0 || v7 == 12 && *(char *)(*(_QWORD *)v5 + 119LL) < 0) )
      {
        v10[0] = 0;
        nla_memcpy(v10, v3, 8);
        v8 = v10[0];
        v9 = *(_DWORD **)(*(_QWORD *)v4 + 528LL);
        if ( *(v9 - 1) != 1657842298 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _DWORD *, __int64))v9)(v4 + 992, v5, v8);
      }
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
