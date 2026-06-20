__int64 __fastcall sde_hw_vdc_disable(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    sde_reg_write(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 48LL) + 48LL) + 4, 0, "VDC_CFG + idx");
    return sde_reg_write(v1, 0, 0, "VDC_CMN_MAIN_CNF");
  }
  return result;
}
