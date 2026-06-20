__int64 __fastcall lpg_brightness_single_set(__int64 a1, int a2)
{
  __int64 v4; // x8
  _QWORD *v5; // x21
  _DWORD v7[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (_QWORD *)(a1 - 8);
  v4 = *(_QWORD *)(a1 - 8);
  v7[0] = 0;
  v8 = 0;
  mutex_lock(v4 + 16);
  v7[1] = a2;
  lpg_brightness_set(v5, a1, v7);
  mutex_unlock(*v5 + 16LL);
  _ReadStatusReg(SP_EL0);
  return 0;
}
