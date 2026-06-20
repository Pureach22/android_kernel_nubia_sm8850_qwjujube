__int64 __fastcall qmp_combo_typec_switch_register(__int64 *a1)
{
  __int64 v2; // x20
  const void *v3; // x0
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19
  _QWORD v7[5]; // [xsp+8h] [xbp-28h] BYREF

  v7[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v7[2] = 0;
  v7[3] = a1;
  v7[0] = *(_QWORD *)(v2 + 752);
  v7[1] = qmp_combo_typec_switch_set;
  v3 = (const void *)typec_switch_register(v2, v7);
  a1[56] = (__int64)v3;
  if ( (unsigned __int64)v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v2, "Unable to register typec switch: %pe\n", v3);
    result = *((unsigned int *)a1 + 112);
  }
  else
  {
    result = _devm_add_action(v2, qmp_combo_typec_unregister, a1, "qmp_combo_typec_unregister");
    if ( (_DWORD)result )
    {
      v5 = a1[56];
      v6 = result;
      typec_switch_unregister(v5);
      result = v6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
