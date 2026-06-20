__int64 __fastcall gh_panic_notify_receiver(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _BYTE *v4; // x21
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[18];
  v4 = (_BYTE *)a2[13];
  v6[0] = 1;
  gh_dbl_read_and_clean(v3, v6, 0x100000000LL);
  _pm_stay_awake(a2[19]);
  result = srcu_notifier_call_chain(&gh_panic_notifier, 0, 0);
  *v4 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
