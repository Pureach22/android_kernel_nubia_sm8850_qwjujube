__int64 __fastcall set_log_level(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(__int64, _QWORD *, __int64, __int64, __int64); // x8
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w19
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = a2;
  v2 = ph;
  v3 = *(__int64 (__fastcall **)(__int64, _QWORD *, __int64, __int64, __int64))ops;
  if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
    __break(0x8228u);
  v4 = v3(v2, v7, 0x435055435043544CLL, 1, 8);
  if ( (v4 & 0x80000000) != 0 )
  {
    v6 = v4;
    printk(&unk_82AC);
    result = v6;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
