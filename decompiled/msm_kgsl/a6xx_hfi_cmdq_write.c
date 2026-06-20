__int64 __fastcall a6xx_hfi_cmdq_write(__int64 a1, int *a2, unsigned int a3)
{
  __int64 result; // x0

  result = a6xx_hfi_queue_write(a1, 0, a2, a3);
  __dsb(0xEu);
  if ( !(_DWORD)result )
  {
    gmu_core_regwrite(a1, 129428, 1);
    return 0;
  }
  return result;
}
