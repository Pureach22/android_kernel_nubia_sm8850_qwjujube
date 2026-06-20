__int64 __fastcall get_log_level(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _DWORD *v4; // x8
  unsigned int v5; // w0
  __int64 result; // x0
  unsigned int v7; // w19
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ph;
  v8[0] = 1;
  v4 = *(_DWORD **)(ops + 8);
  if ( *(v4 - 1) != 1134762728 )
    __break(0x8228u);
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, _QWORD, __int64))v4)(
         v3,
         v8,
         0x435055435043544CLL,
         1,
         0,
         8);
  if ( (v5 & 0x80000000) != 0 )
  {
    v7 = v5;
    printk(&unk_8714);
    result = v7;
  }
  else
  {
    result = 0;
    *a2 = v8[0];
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
