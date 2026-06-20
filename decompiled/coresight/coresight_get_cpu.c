__int64 __fastcall coresight_get_cpu(__int64 a1)
{
  unsigned __int64 v2; // x9
  __int64 result; // x0
  __int64 v4; // x0
  int v5; // w8
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 752);
  result = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_UNKNOWN **)(v2 + 8) == &of_fwnode_ops )
    {
      v4 = *(_QWORD *)(a1 + 744);
      if ( v4 )
      {
        memset(v6, 0, 80);
        v5 = _of_parse_phandle_with_args(v4, "cpu", 0, 0, 0, v6);
        result = 4294967277LL;
        if ( !v5 && v6[0] )
          result = of_cpu_node_to_id(v6[0]);
      }
      else
      {
        result = 4294967277LL;
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
