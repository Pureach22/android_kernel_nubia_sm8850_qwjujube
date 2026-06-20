__int64 __fastcall devm_reboot_mode_register(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  unsigned int v6; // w0
  unsigned int v7; // w19

  v4 = _devres_alloc_node(devm_reboot_mode_release, 8, 3264, 0xFFFFFFFFLL, "devm_reboot_mode_release");
  if ( !v4 )
    return 4294967284LL;
  v5 = (_QWORD *)v4;
  v6 = reboot_mode_register(a2);
  if ( v6 )
  {
    v7 = v6;
    devres_free(v5);
    return v7;
  }
  else
  {
    *v5 = a2;
    devres_add(a1, v5);
    return 0;
  }
}
