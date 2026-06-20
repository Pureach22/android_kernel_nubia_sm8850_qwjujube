__int64 __fastcall msm_pcie_config_l1ss_disable_all(__int64 result, __int64 a2)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x21
  __int64 v4; // x19

  if ( *(_BYTE *)(result + 1219) == 1 )
  {
    v2 = (_QWORD *)(a2 + 40);
    v3 = *(_QWORD **)(a2 + 40);
    if ( v3 != (_QWORD *)(a2 + 40) )
    {
      v4 = result;
      do
      {
        if ( v3[3] )
          msm_pcie_config_l1ss_disable_all(v4);
        result = msm_pcie_config_l1ss(v4, v3, 0);
        v3 = (_QWORD *)*v3;
      }
      while ( v3 != v2 );
    }
  }
  return result;
}
