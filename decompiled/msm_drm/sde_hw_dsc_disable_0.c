__int64 __fastcall sde_hw_dsc_disable_0(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20

  if ( result )
  {
    v1 = result;
    sde_reg_write(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 56LL) + 48LL) + 4, 0, "DSC_CFG + idx");
    v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + 56LL) + 20LL);
    sde_reg_write(v1, v2, 0, "ENC_DF_CTRL + idx");
    return sde_reg_write(v1, v2 + 48, 0, "DSC_MAIN_CONF + idx");
  }
  return result;
}
