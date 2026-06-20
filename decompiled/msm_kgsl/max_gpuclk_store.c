__int64 __fastcall max_gpuclk_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x12
  unsigned int v10; // w11
  unsigned int v11; // w15
  int v12; // w15
  unsigned int v13; // w9
  int updated; // w0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v15 = 0;
  LODWORD(result) = kstrtouint(a3, 0, &v15);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    v7 = *(unsigned int *)(v5 + 10068);
    v8 = v5 + 9144;
    v9 = v7 - 1;
    v10 = *(_DWORD *)(v5 + 10068);
    do
    {
      if ( (--v10 & 0x80000000) != 0 )
      {
        result = -34;
        goto LABEL_19;
      }
      if ( v10 >= 0x20 )
        goto LABEL_20;
      v11 = v9-- & 0x1F;
      v12 = *(_DWORD *)(v8 + 28LL * v11) - v15;
      if ( v12 < 0 )
        v12 = -v12;
    }
    while ( v12 > 4999999 );
    if ( (unsigned int)v7 <= v10 )
      v13 = v7 - 1;
    else
      v13 = v10;
    if ( *(_QWORD *)(v5 + 10544) )
    {
      if ( v13 >= 0x20 )
LABEL_20:
        __break(0x5512u);
      updated = dev_pm_qos_update_request(v5 + 10472, *(unsigned int *)(v8 + 28LL * v13) / 0x3E8uLL);
      if ( updated >= 0 )
        result = a4;
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
