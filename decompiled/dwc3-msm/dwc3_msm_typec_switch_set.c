__int64 __fastcall dwc3_msm_typec_switch_set(__int64 result, int a2)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x19

  if ( a2 >= 1 )
  {
    v2 = (_QWORD *)result;
    v3 = fwnode_typec_switch_get(*(_QWORD *)(*(_QWORD *)result + 752LL));
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      return dev_err(*v2, "failed to acquire orientation-switch\n");
    }
    else
    {
      v4 = v3;
      typec_switch_set();
      return typec_switch_put(v4);
    }
  }
  return result;
}
