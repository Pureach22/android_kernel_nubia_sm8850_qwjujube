__int64 __fastcall cm_send_disconnect_resp(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD v5[6]; // [xsp+0h] [xbp-30h] BYREF

  v5[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 40);
  qdf_mem_set(v5, 0x28u, 0);
  result = cm_fill_disconnect_resp_from_cm_id(a1, a2, v5);
  if ( !(_DWORD)result )
    result = cm_disconnect_complete(a1, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
