__int64 __fastcall cmd_db_read_aux_data(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v6[0] = 0;
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))cmd_db_get_header)(a1, v6, &v5);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    v4 = v6[0];
    if ( a2 )
      *a2 = *(unsigned __int16 *)(v6[0] + 20LL);
    result = cmd_db_header + *(unsigned __int16 *)(v5 + 4) + *(unsigned __int16 *)(v4 + 22) + 144;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
