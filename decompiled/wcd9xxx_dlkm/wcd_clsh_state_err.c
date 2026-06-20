__int64 __fastcall wcd_clsh_state_err(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x19
  const char *v5; // x20
  __int64 result; // x0
  _QWORD v7[17]; // [xsp+8h] [xbp-88h] BYREF

  v7[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  memset(&v7[12], 0, 32);
  if ( (a4 & 1) != 0 )
    v5 = "enable";
  else
    v5 = "disable";
  memset(v7, 0, 96);
  ((void (__fastcall *)(_QWORD, _QWORD *))state_to_str)(a3, v7);
  result = dev_err(
             v4,
             "%s Wrong request for class H state machine requested to %s %s\n",
             "wcd_clsh_state_err",
             v5,
             (const char *)v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
