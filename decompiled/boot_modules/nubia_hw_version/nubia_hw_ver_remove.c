__int64 __fastcall nubia_hw_ver_remove(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(a1 + 168);
  if ( v1 && *v1 )
    devm_pinctrl_put(*v1);
  return devm_kfree(a1 + 16, v1);
}
