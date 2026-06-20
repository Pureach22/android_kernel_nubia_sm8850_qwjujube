__int64 __fastcall dp_panel_put(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8

  if ( result )
  {
    v1 = (_QWORD *)(result - 8);
    v2 = result;
    sde_edid_deinit(result + 96);
    v3 = *(_QWORD *)(v2 + 944);
    if ( v3 )
      *(_QWORD *)(v3 + 2768) = 0;
    return devm_kfree(*v1);
  }
  return result;
}
