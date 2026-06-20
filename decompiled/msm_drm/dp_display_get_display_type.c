__int64 __fastcall dp_display_get_display_type(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 *v4; // x19
  __int64 property; // x0
  __int64 result; // x0
  __int64 v7; // x0

  if ( a1 && a2 )
  {
    v2 = *(_QWORD *)(a1 - 1032);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 792);
    }
    else
    {
      v4 = a2;
      property = of_get_property(*(_QWORD *)(*(_QWORD *)(a1 - 1144) + 760LL), "qcom,display-type", 0);
      a2 = v4;
      v3 = property;
    }
    result = 0;
    *a2 = v3;
  }
  else
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    ipc_log_string(v7, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_get_display_type");
    return 4294967274LL;
  }
  return result;
}
