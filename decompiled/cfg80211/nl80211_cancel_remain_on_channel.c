__int64 __fastcall nl80211_cancel_remain_on_channel(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x2
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2[4] + 704LL);
  if ( v3 )
  {
    v4 = a2[6];
    if ( *(_QWORD *)(*(_QWORD *)v4 + 512LL) )
    {
      v5 = a2[7];
      v9[0] = 0;
      nla_memcpy(v9, v3, 8);
      v6 = v9[0];
      v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v4 + 512LL);
      if ( *((_DWORD *)v7 - 1) != 1657842298 )
        __break(0x8228u);
      result = v7(v4 + 992, v5, v6);
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
