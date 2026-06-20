__int64 __fastcall hal_get_tsf_time_peach(_QWORD *a1, int a2, int a3, _QWORD *a4, unsigned __int64 *a5)
{
  __int64 result; // x0
  unsigned int v11; // w22
  unsigned int v12; // w23
  unsigned __int64 StatusReg; // x24
  __int64 v14; // x25
  unsigned __int64 v15; // x27
  double v16; // d0
  unsigned int v17; // w0
  __int64 v18; // x25
  double v19; // d0
  unsigned int v20; // w0
  __int64 v21; // x26
  double v22; // d0
  unsigned int v23; // w0
  __int64 v24; // x22
  unsigned int v25; // w0
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8

  result = hif_force_wake_request(*a1);
  if ( !(_DWORD)result )
  {
    if ( a3 == 1 )
    {
      if ( a2 )
      {
        v11 = 11862268;
        v12 = 11862268;
        if ( a2 == 1 )
        {
          v11 = 11862300;
          v12 = 11862304;
        }
      }
      else
      {
        v11 = 11862292;
        v12 = 11862296;
      }
    }
    else
    {
      v11 = 11862268;
      v12 = 11862268;
      if ( !a3 )
      {
        if ( a2 )
        {
          if ( a2 == 1 )
          {
            v11 = 11862284;
            v12 = 11862288;
          }
        }
        else
        {
          v11 = 11862276;
          v12 = 11862280;
        }
      }
    }
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v14 = (unsigned int)readl_8(a1[2] + 2600LL);
    v15 = v14 | (readl_8(a1[2] + 2604LL) << 32);
    v16 = hal_read32_mb_1(a1, (const char *)0xB500FC);
    v18 = v17;
    v19 = hal_read32_mb_1(a1, (const char *)0xB50100, v16);
    v21 = v20;
    v22 = hal_read32_mb_1(a1, (const char *)v11, v19);
    v24 = v23;
    hal_read32_mb_1(a1, (const char *)v12, v22);
    if ( 10 * v15 >= v15 )
      v26 = 10 * v15 / 0xC0;
    else
      v26 = 10 * (v15 / 0xC0);
    *a4 = v24 + v18 + (v21 << 32) + ((unsigned __int64)v25 << 32) + v26;
    if ( 10 * StatusReg >= StatusReg )
      v27 = 10 * StatusReg / 0xC0;
    else
      v27 = 10 * (StatusReg / 0xC0);
    *a5 = v27;
    return hif_force_wake_release(*a1);
  }
  return result;
}
