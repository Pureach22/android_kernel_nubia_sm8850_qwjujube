__int64 __fastcall hal_get_tsf_time_peach(_QWORD *a1, int a2, int a3, _QWORD *a4, unsigned __int64 *a5)
{
  __int64 result; // x0
  unsigned int v11; // w22
  unsigned int v12; // w23
  unsigned __int64 StatusReg; // x24
  __int64 v14; // x25
  unsigned __int64 v15; // x27
  __int64 v16; // x25
  __int64 v17; // x26
  __int64 v18; // x22
  unsigned int v19; // w0
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8

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
    v16 = (unsigned int)hal_read32_mb_1(a1, 11862268);
    v17 = (unsigned int)hal_read32_mb_1(a1, 11862272);
    v18 = (unsigned int)hal_read32_mb_1(a1, v11);
    v19 = hal_read32_mb_1(a1, v12);
    if ( 10 * v15 >= v15 )
      v20 = 10 * v15 / 0xC0;
    else
      v20 = 10 * (v15 / 0xC0);
    *a4 = v18 + v16 + (v17 << 32) + ((unsigned __int64)v19 << 32) + v20;
    if ( 10 * StatusReg >= StatusReg )
      v21 = 10 * StatusReg / 0xC0;
    else
      v21 = 10 * (StatusReg / 0xC0);
    *a5 = v21;
    return hif_force_wake_release(*a1);
  }
  return result;
}
