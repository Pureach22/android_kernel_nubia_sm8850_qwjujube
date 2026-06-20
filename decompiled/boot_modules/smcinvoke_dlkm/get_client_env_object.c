__int64 __fastcall get_client_env_object(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  unsigned int v4; // w19
  _QWORD v5[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v6; // [xsp+18h] [xbp-18h]
  __int64 v7; // [xsp+20h] [xbp-10h]
  __int64 v8; // [xsp+28h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v7 = 0;
  v5[0] = 0;
  v5[1] = 0;
  result = do_invoke(&qword_1, 5u, (__int64)v5, 0x1100u);
  v3 = v7;
  *a1 = v6;
  a1[1] = v3;
  if ( (_DWORD)result )
  {
    v4 = result;
    printk(&unk_10997, "get_client_env_object", (unsigned int)result);
    result = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
