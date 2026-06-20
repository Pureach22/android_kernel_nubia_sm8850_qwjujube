__int64 __fastcall hal_reo_read_write_ctrl_ix(__int64 a1, char a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  __int64 (*v12)(void); // x8
  __int64 result; // x0
  int v14; // w21

  v12 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 74392) + 1208LL);
  if ( *((_DWORD *)v12 - 1) != -605791253 )
    __break(0x8228u);
  result = v12();
  v14 = result;
  if ( (a2 & 1) != 0 )
  {
    if ( a3 )
    {
      result = hal_read32_mb_0(a1, (unsigned int)(result + 4));
      *a3 = result;
    }
    if ( a4 )
    {
      result = hal_read32_mb_0(a1, (unsigned int)(v14 + 8));
      *a4 = result;
    }
    if ( a5 )
    {
      result = hal_read32_mb_0(a1, (unsigned int)(v14 + 12));
      *a5 = result;
    }
    if ( a6 )
    {
      result = hal_read32_mb_0(a1, (unsigned int)(v14 + 16));
      *a6 = result;
    }
  }
  else
  {
    if ( a3 )
      result = hal_write32_mb_confirm_retry(a1, (unsigned int)(result + 4), (unsigned int)*a3);
    if ( a4 )
      result = hal_write32_mb_confirm_retry(a1, (unsigned int)(v14 + 8), (unsigned int)*a4);
    if ( a5 )
      result = hal_write32_mb_confirm_retry(a1, (unsigned int)(v14 + 12), (unsigned int)*a5);
    if ( a6 )
      return hal_write32_mb_confirm_retry(a1, (unsigned int)(v14 + 16), (unsigned int)*a6);
  }
  return result;
}
