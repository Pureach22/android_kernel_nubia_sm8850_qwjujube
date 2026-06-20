__int64 __fastcall wma_send_msg_by_priority(__int64 a1, unsigned __int16 a2, __int64 a3, int a4, char a5)
{
  __int64 result; // x0
  _DWORD v7[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v8; // [xsp+10h] [xbp-30h]
  __int64 v9; // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v10)(); // [xsp+20h] [xbp-20h]
  __int64 v11; // [xsp+28h] [xbp-18h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a3;
  v7[0] = a2;
  v11 = 0;
  v12 = 0;
  v7[1] = a4;
  v9 = 0;
  v10 = wma_discard_fw_event;
  result = scheduler_post_msg_by_priority(53, (unsigned __int16 *)v7, a5);
  if ( a3 && (_DWORD)result )
    result = _qdf_mem_free(a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
