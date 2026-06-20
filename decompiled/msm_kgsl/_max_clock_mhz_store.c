__int64 __fastcall max_clock_mhz_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x12
  __int64 v8; // x8
  unsigned int v9; // w11
  unsigned int v10; // w15
  int v11; // w15
  unsigned int v12; // w9
  int updated; // w0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  LODWORD(result) = kstrtouint(a2, 0, &v14);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    v6 = *(unsigned int *)(a1 + 10068);
    v7 = v6 - 1;
    v8 = a1 + 9144;
    v9 = *(_DWORD *)(a1 + 10068);
    do
    {
      if ( (--v9 & 0x80000000) != 0 )
      {
        result = -34;
        goto LABEL_19;
      }
      if ( v9 >= 0x20 )
        goto LABEL_20;
      v10 = v7-- & 0x1F;
      v11 = *(_DWORD *)(v8 + 28LL * v10) - 1000000 * v14;
      if ( v11 < 0 )
        v11 = -v11;
    }
    while ( v11 > 4999999 );
    if ( (unsigned int)v6 <= v9 )
      v12 = v6 - 1;
    else
      v12 = v9;
    if ( *(_QWORD *)(a1 + 10544) )
    {
      if ( v12 >= 0x20 )
LABEL_20:
        __break(0x5512u);
      updated = dev_pm_qos_update_request(a1 + 10472, *(unsigned int *)(v8 + 28LL * v12) / 0x3E8uLL);
      if ( updated >= 0 )
        result = a3;
      else
        result = updated & (updated >> 31);
    }
    else
    {
      result = -22;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
