__int64 __fastcall _clear_interrupt_iris4(_DWORD *a1)
{
  __int64 result; // x0
  char v3; // w10
  __int64 v4; // x4
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  result = _read_register((__int64)a1, 0xB000Cu, &v5);
  if ( !(_DWORD)result )
  {
    if ( (v5 & 0x4000000C) != 0 )
    {
      v3 = msm_vidc_debug;
      v4 = (unsigned int)(a1[982] + 1);
      a1[980] |= v5;
      a1[982] = v4;
      if ( (v3 & 4) != 0 )
        printk(&unk_800DB, "low ", 0xFFFFFFFFLL, "codec", v4);
    }
    else
    {
      ++a1[981];
    }
    result = _write_register((__int64)a1, 0xA001Cu, 1u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
