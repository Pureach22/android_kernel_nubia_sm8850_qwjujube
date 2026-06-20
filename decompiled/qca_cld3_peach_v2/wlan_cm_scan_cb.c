__int64 __fastcall wlan_cm_scan_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  result = util_is_scan_completed(a2, v7);
  if ( (result & 1) != 0 )
  {
    result = cm_sm_deliver_event(a1, 2, 4, a2 + 20);
    if ( (_DWORD)result )
    {
      result = cm_get_cm_id_by_scan_id(a3, *(unsigned int *)(a2 + 20));
      if ( (_DWORD)result != -1 )
        result = cm_connect_handle_event_post_fail(a3, result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
