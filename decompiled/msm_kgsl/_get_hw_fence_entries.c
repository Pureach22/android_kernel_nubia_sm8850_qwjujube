__int64 __fastcall get_hw_fence_entries(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 14264);
  v3 = 0;
  if ( (*(_BYTE *)(v1 + 34) & 1) != 0 )
  {
    v2 = result;
    result = of_find_node_by_name(0, "qcom,hw-fence");
    if ( result )
    {
      if ( (of_property_read_variable_u32_array(result, "qcom,hw-fence-table-entries", &v3, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "qcom,hw-fence-table-entries property not found\n");
        v3 = 0x2000;
      }
      result = gmu_core_set_vrb_register(*(_QWORD *)(v2 + 8664), 3);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
