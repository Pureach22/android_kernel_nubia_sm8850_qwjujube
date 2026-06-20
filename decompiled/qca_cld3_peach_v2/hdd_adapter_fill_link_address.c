__int64 __fastcall hdd_adapter_fill_link_address(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  int v11; // w9
  _QWORD *v12; // x10
  __int64 result; // x0
  __int64 v14; // x20
  int v15; // w8
  __int64 v16; // x3
  __int16 v17; // w10
  __int16 v18; // w10
  __int16 v19; // w10
  __int128 v20; // [xsp+0h] [xbp-20h] BYREF
  __int16 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v10 = a1 + 49152;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)(a1 + 40);
  v12 = *(_QWORD **)(a1 + 24);
  v21 = 0;
  v20 = 0u;
  if ( !v11 || v11 == 6 )
  {
    if ( v11 != 6 && (*(_DWORD *)(a1 + 52800) & 1) == 0 )
      goto LABEL_8;
    if ( v11 == 6 )
      v16 = 2;
    else
      v16 = 3;
    result = hdd_derive_link_address_from_mld(*v12, a1 + 1617, &v20, v16);
    if ( !(_DWORD)result && a1 && a1 != -52840 )
    {
      v17 = WORD2(v20);
      *(_DWORD *)(a1 + 52912) = v20;
      *(_WORD *)(a1 + 52916) = v17;
      if ( a1 == -58928 )
        goto LABEL_8;
      v18 = WORD5(v20);
      result = 0;
      *(_DWORD *)(a1 + 59000) = *(_DWORD *)((char *)&v20 + 6);
      *(_WORD *)(a1 + 59004) = v18;
      if ( a1 != -65016 )
      {
        v19 = v21;
        *(_DWORD *)(a1 + 65088) = HIDWORD(v20);
        *(_WORD *)(a1 + 65092) = v19;
      }
    }
  }
  else
  {
    result = 0;
    if ( v11 == 1 )
    {
      v14 = *(_QWORD *)(v10 + 3680);
      if ( (cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9) & 8) == 0 )
      {
        result = 0;
        v15 = *(_DWORD *)(a1 + 1617);
        *(_WORD *)(v14 + 76) = *(_WORD *)(a1 + 1621);
        *(_DWORD *)(v14 + 72) = v15;
        goto LABEL_13;
      }
LABEL_8:
      result = 0;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
