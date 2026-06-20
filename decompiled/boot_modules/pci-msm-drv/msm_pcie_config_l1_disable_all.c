__int64 __fastcall msm_pcie_config_l1_disable_all(__int64 result, __int64 a2)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x21
  __int64 v4; // x19
  __int64 v5; // x1

  if ( *(_BYTE *)(result + 1218) == 1 )
  {
    v2 = (_QWORD *)(a2 + 40);
    v3 = *(_QWORD **)(a2 + 40);
    if ( v3 != (_QWORD *)(a2 + 40) )
    {
      v4 = result;
      do
      {
        v5 = v3[3];
        if ( v5 )
          msm_pcie_config_l1_disable_all(v4, v5);
        result = msm_pcie_config_l1(v4, v3, 0);
        v3 = (_QWORD *)*v3;
      }
      while ( v3 != v2 );
    }
  }
  return result;
}
