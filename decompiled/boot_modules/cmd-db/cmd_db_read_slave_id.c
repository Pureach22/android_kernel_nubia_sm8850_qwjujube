__int64 __fastcall cmd_db_read_slave_id(__int64 a1)
{
  __int64 result; // x0
  _QWORD v2[2]; // [xsp+0h] [xbp-10h] BYREF

  v2[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  if ( (((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD))cmd_db_get_header)(a1, v2, 0) & 0x80000000) != 0 )
    result = 0;
  else
    result = *(_WORD *)((_BYTE *)&dword_10 + v2[0] + 2) & 7;
  _ReadStatusReg(SP_EL0);
  return result;
}
