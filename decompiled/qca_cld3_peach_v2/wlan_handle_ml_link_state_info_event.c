__int64 __fastcall wlan_handle_ml_link_state_info_event(__int64 a1, __int64 a2)
{
  __int64 v2; // x3
  void (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(unsigned __int8 *)(a2 + 34);
    v7 = 0;
    v8[0] = 0;
    if ( !(unsigned int)mlo_get_link_state_context(a1, v8, &v7, v2) )
    {
      v4 = (void (__fastcall *)(__int64, __int64))v8[0];
      if ( v8[0] )
      {
        v5 = v7;
        if ( *(_DWORD *)(v8[0] - 4LL) != 1860441987 )
          __break(0x8228u);
        v4(a2, v5);
      }
    }
    result = 0;
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
