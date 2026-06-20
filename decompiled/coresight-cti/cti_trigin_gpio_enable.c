__int64 __fastcall cti_trigin_gpio_enable(__int64 result)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x19
  unsigned __int64 v4; // x0
  const char *v5; // x1

  if ( !**(_QWORD **)(result + 1208) )
  {
    v1 = result;
    v2 = devm_pinctrl_get(*(_QWORD *)(*(_QWORD *)(result + 8) + 152LL));
    if ( v2 >= 0xFFFFFFFFFFFFF001LL )
      return dev_err(*(_QWORD *)(v1 + 8) + 56LL, "pinctrl get failed\n");
    v3 = v2;
    v4 = pinctrl_lookup_state();
    if ( v4 > 0xFFFFFFFFFFFFF000LL )
    {
      v5 = "pinctrl get state failed\n";
    }
    else
    {
      result = pinctrl_select_state(v3, v4);
      if ( !(_DWORD)result )
      {
        **(_QWORD **)(v1 + 1208) = v3;
        return result;
      }
      v5 = "pinctrl enable state failed\n";
    }
    dev_err(*(_QWORD *)(v1 + 8) + 56LL, v5);
    return devm_pinctrl_put(v3);
  }
  return result;
}
