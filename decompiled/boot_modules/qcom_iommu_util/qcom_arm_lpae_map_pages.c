__int64 __fastcall qcom_arm_lpae_map_pages(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6,
        int a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 v9; // x19
  int v10; // w9
  __int64 v11; // x10
  __int64 result; // x0
  __int64 v19; // x11
  __int64 v20; // x12
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x26
  unsigned int v27; // w19
  unsigned int v28; // [xsp+2Ch] [xbp-14h]
  _QWORD v29[2]; // [xsp+30h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 && a5 && (*(_QWORD *)(a1 - 96) & a4) == a4 )
  {
    if ( a2 >> *(_DWORD *)(a1 - 88) != (__int64)(*(_QWORD *)(a1 - 104) << 58) >> 63 || a3 >> *(_DWORD *)(a1 - 84) )
    {
      __break(0x800u);
      result = 4294967262LL;
    }
    else if ( (a6 & 3) != 0 )
    {
      v8 = a1 - 128;
      v9 = *(_QWORD *)(a1 + 88);
      v10 = *(_DWORD *)(a1 - 128);
      if ( v10 && v10 != -2 )
      {
        v11 = (unsigned __int8)(a6 & 3) << 6;
      }
      else
      {
        v11 = 2048;
        if ( (a6 & 3) == 1 )
          v11 = 2176;
        if ( (a6 & 0x20) == 0 )
          v11 |= 0x40uLL;
      }
      v28 = *(_DWORD *)(a1 + 76);
      if ( (v10 | 2) == 3 )
      {
        if ( (a6 & 0x10) != 0 )
        {
          v19 = 4;
        }
        else
        {
          v19 = 60;
          if ( (a6 & 4) == 0 )
            v19 = 20;
        }
      }
      else if ( (a6 & 0x10) != 0 )
      {
        v19 = 8;
      }
      else
      {
        v19 = a6 & 4;
      }
      v20 = 768;
      if ( (a6 & 4) == 0 )
        v20 = 512;
      v22 = 32 * (*(_QWORD *)(a1 - 104) & 1LL);
      v23 = a1 + 120;
      v24 = v11 | v20 | v19;
      if ( (a6 & 8) != 0 )
        v24 |= 0x60000000000000uLL;
      v25 = v24 | v22;
      if ( v10 == 5 )
        v26 = v25;
      else
        v26 = v25 | 0x400;
      v29[0] = raw_spin_lock_irqsave(v23);
      v27 = _arm_lpae_map(v8, a2, a3, a4, a5, v26, v28, v9, 0, 0, a7, v29, a8);
      raw_spin_unlock_irqrestore(a1 + 120, v29[0]);
      __dsb(0xEu);
      result = v27;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
