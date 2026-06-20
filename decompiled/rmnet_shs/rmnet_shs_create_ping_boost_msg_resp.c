__int64 __fastcall rmnet_shs_create_ping_boost_msg_resp(__int64 result, __int64 a2)
{
  int v2; // w19
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  __int64 v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = result;
    v6 = 0;
    v7 = 0;
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 56) = 0;
    *(_QWORD *)(a2 + 64) = 0;
    *(_QWORD *)(a2 + 72) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    *(_QWORD *)(a2 + 88) = 0;
    *(_QWORD *)(a2 + 96) = 0;
    *(_QWORD *)(a2 + 104) = 0;
    *(_QWORD *)(a2 + 112) = 0;
    result = ktime_get_real_ts64(&v6);
    v4 = v6;
    v5 = v7;
    *(_DWORD *)a2 = v2;
    *(_WORD *)(a2 + 5) = 0;
    *(_BYTE *)(a2 + 7) = 0;
    *(_BYTE *)(a2 + 4) = 1;
    *(_WORD *)(a2 + 98) = 1;
    *(_BYTE *)(a2 + 114) = 1;
    *(_WORD *)(a2 + 112) = 1;
    *(_QWORD *)(a2 + 104) = v5 + 1000000000 * v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
